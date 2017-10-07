// $Header: r:/t2repos/thief2/src/shock/shkgun.cpp,v 1.51 1999/11/29 15:22:27 porges Exp $

#include <gunapi.h>
#include <gunbase.h>
#include <shkgunmd.h>
#include <shkganpr.h>

#include <appagg.h>
#include <sdesc.h>
#include <sdesbase.h>

#include <autolink.h>
#include <bintrait.h>
#include <linkman.h>
#include <linkbase.h>
#include <linkint.h>
#include <lnkbyobj.h>
#include <lnkquery.h>
#include <relation.h>
#include <objdef.h>
#include <osetlnkq.h>
#include <traitman.h>
#include <traitbas.h>
#include <combprop.h>
#include <iobjsys.h>
#include <prjctile.h>
#include <playrobj.h>
#include <psnd.h>
#include <matrixc.h>
#include <rendprop.h>

#include <esnd.h>
#include <ctagset.h>

#include <gunflash.h>
#include <gunprop.h>
#include <shkinv.h>
#include <projprop.h>
#include <gunproj.h>
#include <shkpgapi.h>
#include <shkammov.h>
#include <shkutils.h>

#include <projlink.h>

#include <command.h>
#include <scrptapi.h>

// must be last header
#include <dbmem.h>

IRelation * g_pClipLinks;

//projectile links extracted.  AMSD

//////////////////////////////////////////////

BOOL IsGun(ObjID objID)
{
   sGunState *pGun;

   return GunStateGet(objID, &pGun);
}

////////////////////////////////////////////////////////
// Get the order (int) of the current projectile in the gun
// Returns -1 if no projectile current
//
ObjID GetProjectileOrder(ObjID gunID)
{
   cAutoLinkQuery query(g_pProjectileLinks, gunID, LINKOBJ_WILDCARD);  

   if (!query->Done())
   {
      AutoAppIPtr(TraitManager);
      cAutoLinkQuery parentQuery(g_pProjectileLinks, pTraitManager->GetArchetype(gunID), query.GetDest());
      // there should always be a matching link from the abstract gun obj to a projectile...
      Assert_(!query->Done());
      return ((sProjectileData*)parentQuery->Data())->m_order;
   }
   return -1;
}

////////////////////////////////////////////////////////
// Get the projectile for the specified order, OBJ_NULL if none
//
ObjID GetProjectileByOrder(ObjID gunID, int order)
{
   cAutoLinkQuery query(g_pProjectileLinks, gunID, LINKOBJ_WILDCARD);  

   while (!query->Done())
   {
      ObjID obj = query.GetDest();
      int qorder = ((sProjectileData*)query->Data())->m_order;
      if (qorder == order)
         return obj;
      query->Next();
   }
   return OBJ_NULL;
}

////////////////////////////////////////////////////////
// Find the projectile for the gun/setting with the same order index
// as given. Returns OBJ_NULL if no corresponding projectile/order.
//
ObjID FindProjectileByOrder(ObjID gunID, int order)
{
   AutoAppIPtr(TraitManager);
   cProjectileQuery query(gunID);  
   ObjID projID;

   projID = query.GetFirst();
   while ((projID != OBJ_NULL) && (query.GetOrder()<order))
      projID = query.GetNext();
   return projID;
}

////////////////////////////////////////////////////////
// Set projectile for new setting trying to match current order.
// If no current order, use first projectile.
// If no projectile/setting which matches current order then
// use projectile with greatest order less than current 
//
void AdjustProjectileForSetting(ObjID gunID)
{
   int order = GetProjectileOrder(gunID);
   ObjID projID;

   // If nothing, then just set to default for this setting 
   if (order == -1)
      projID = OBJ_NULL;
   else
      projID = FindProjectileByOrder(gunID, order);
   if (projID != OBJ_NULL)   
      SetProjectile(gunID, projID);
   else
      SetProjectile(gunID, GetNextProjectile(gunID, OBJ_NULL));
}

//////////////////////////////////////////////////////////////
// Get clip from link
//
ObjID GetClip(ObjID projID)
{
   ObjID clip = OBJ_NULL;
   AutoAppIPtr(LinkManager);
   ILinkQuery *pQuery = pLinkManager->Query(projID, LINKOBJ_WILDCARD, g_pClipLinks->GetID());

   if (!pQuery->Done())
   {
      sLink link;
      pQuery->Link(&link);
      clip = link.dest;
   }
   SafeRelease(pQuery);
   return clip;
}

////////////////////////////////////////////////////////////////
// Get projectile from clip link, OBJ_NULL if more than one link
//
ObjID GetProjectileFromClip(ObjID clipID, ObjID gunID)
{
   AutoAppIPtr(TraitManager);
   cAutoLinkQuery projQuery(g_pClipLinks, LINKOBJ_WILDCARD, pTraitManager->GetArchetype(clipID));
   ObjID gunArchID = pTraitManager->GetArchetype(gunID);
   ObjID projID;
   ILinkQuery *pGunQuery;
   int setting = GunGetSetting(gunID);
   BOOL found = FALSE;

   while (!projQuery->Done() && !found)
   {
      projID = projQuery.GetSource();
      pGunQuery = g_pProjectileLinks->Query(LINKOBJ_WILDCARD, projID);
      while (!pGunQuery->Done() && !found)
      {
         sLink link;
         pGunQuery->Link(&link);
         if ((link.source == gunArchID) && MatchesSetting((sProjectileData*)pGunQuery->Data(), setting))
            found = TRUE;
         pGunQuery->Next();
      }
      SafeRelease(pGunQuery);
      projQuery->Next();
   }
   if (found)
      return projID;
   return OBJ_NULL;
}


////////////////////////////////////////////////////////////////
// Can we load ammo that has this projectile ID?

BOOL GunCanLoad(ObjID gunID, ObjID clipID)
{
   return (GetProjectileFromClip(clipID, gunID) != OBJ_NULL);
}

////////////////////////////////////////////////////////////////

ObjID GunUnload(ObjID gunID, uint flags)
{
   ObjID gunProjID = GetProjectile(gunID);
   ObjID clipID = GetClip(gunProjID);
   ObjID unloadID = OBJ_NULL;
   int currentAmmoCount;

   if (clipID != OBJ_NULL)
   {
      currentAmmoCount = GunStateGetAmmo(gunID);
      if (currentAmmoCount == 0)
         return(OBJ_NULL);

      // create unloaded ammo object
      AutoAppIPtr(ObjectSystem);
      unloadID = pObjectSystem->BeginCreate(clipID, kObjectConcrete);
      ObjSetHasRefs(unloadID,FALSE);
      gStackCountProp->Set(unloadID, currentAmmoCount);
      ShockInvLoadCursor(OBJ_NULL);
      if (flags & LF_AUTOPLACE)
         ShockInvAddObj(PlayerObject(),unloadID);
      else if (flags == LF_NONE)
         ShockInvLoadCursor(unloadID);
      pObjectSystem->EndCreate(unloadID);
   }
   else
      Warning(("GunUnload: Projectile object %d has no associated clip\n", gunProjID));
   GunStateSetAmmo(gunID, 0);
   return(unloadID);
}

////////////////////////////////////////////////////////////////

void GunLoad(ObjID gunID, ObjID clipID, uint flags)
{
   int clip;
   int currentAmmoCount;
   int oldammo;
   int ammoCount;
   AutoAppIPtr(TraitManager);
   ObjID clipProjID;
   ObjID gunProjID;
   ObjID unload_obj = OBJ_NULL;
   sBaseGunDesc *pBaseGunDesc;

   if (!BaseGunDescGet(gunID, &pBaseGunDesc))
      return;
   clip = pBaseGunDesc->m_clip;
   oldammo = currentAmmoCount = GunStateGetAmmo(gunID);
   clipProjID = GetProjectileFromClip(clipID, gunID);
   if (clipProjID == OBJ_NULL)
   {
      // @TODO: play can't load sound here
      return;
   }
   if (!gStackCountProp->Get(clipID, &ammoCount))
      ammoCount = 0;
   gunProjID = GetProjectile(gunID);
   if ((clipProjID != OBJ_NULL) && (clipProjID != gunProjID))
   {
      // unload current ammo
      if ((gunProjID != OBJ_NULL) && (currentAmmoCount>0))
      {
         unload_obj = GunUnload(gunID, flags);
         currentAmmoCount = 0;
      }
      // set new archetype & count
      SetProjectile(gunID, clipProjID);
   }
   if (currentAmmoCount+ammoCount>clip)
   {
      // fill up gun, reduce count of ammo object
      GunStateSetAmmo(gunID, clip);
      gStackCountProp->Set(clipID, ammoCount-(clip-currentAmmoCount));
      // okay, if there is still ammo in what we were loading, AND
      // we have a new object in our hand from switching ammo types
      // re-add the clip to our invnetory
      if (clipProjID != gunProjID) 
      {
         ShockInvAddObj(PlayerObject(),clipID);      
      }
   }
   else
   {
      // can't fill gun, destroy ammo object
      GunStateSetAmmo(gunID, currentAmmoCount+ammoCount);
      AutoAppIPtr(ObjectSystem);
      pObjectSystem->Destroy(clipID);

      // if we are not autoplacing/juggling, clear the cursor object as well
      if ((flags == LF_NONE) && ((clipProjID == gunProjID) || (oldammo == 0)))
         ClearCursor();
   }

   // sound
   AutoAppIPtr(PlayerGun);
   if (gunID == pPlayerGun->Get())
   {
      // defer load sound
      pPlayerGun->Load();
   }
   else
      GunLoadSound(gunID);

   ShockAmmoRefreshButtons();

   if ((flags & LF_JUGGLE) && (unload_obj != OBJ_NULL))
   {
      ShockInvAddObj(PlayerObject(),unload_obj);         
   }
}

////////////////////////////////////////////////////////////////

void GunLoadSound(ObjID gunID)
{
   // play reload sound
   cTagSet eventTags("Event Reload");
   int schemaHandle = ESndPlay(&eventTags, gunID, OBJ_NULL); 
}

////////////////////////////////////////////////////////////////

int GunGetAmmoCount(ObjID gunID)
{
   return GunStateGetAmmo(gunID);
}

////////////////////////////////////////////////////////////////

float GunGetCondition(ObjID gunID)
{
//guncondition code changed, copying the GunGetCondition from 
//deepc\weapon\dpcgun.cpp AMSD
   sGunState *pState;

   if (g_pGunStateProperty->Get(gunID, &pState))
     {
       return pState->m_condition;
     }
   return 1;
}

////////////////////////////////////////////////////////////////

#define MAX_GUNCOND_STRING 10
#define GUNCOND_INTERVAL   10
void GunGetConditionString(ObjID gunID, char *buf, int buflen)
{
   float cond = GunGetCondition(gunID);
   int val;

   val = ((int)cond)/GUNCOND_INTERVAL;
   if (val < 0)
      val = 0;
   if (val > MAX_GUNCOND_STRING - 1)
      val = MAX_GUNCOND_STRING -1;

   ShockStringFetch(buf, buflen, "GunCondVal", "weapon", val + 1);
}

////////////////////////////////////////////////////////////////

void GunSetCondition(ObjID gunID, float condition)
{
   sGunState *pGunState;

   if (g_pGunStateProperty->Get(gunID, &pGunState))
     {
       pGunState->m_condition = condition;
       g_pGunStateProperty->Set(gunID, pGunState);
     }
   else
      Warning(("GunSetCondition: Gun %d has no gun state\n"));
}

////////////////////////////////////////////////////////////////

int GunGetSetting(ObjID objID)
{
   sGunState *pGunState;

   if (g_pGunStateProperty->Get(objID, &pGunState))
      return pGunState->m_setting;
   return 0;
}

////////////////////////////////////////////////////////////////

void GunSetSetting(ObjID gunID, int setting)
{
   sGunState *pGunState;

   if (g_pGunStateProperty->Get(gunID, &pGunState))
   {
      pGunState->m_setting = setting;
      g_pGunStateProperty->Set(gunID, pGunState);
      AdjustProjectileForSetting(gunID);
   }
   else
      Warning(("GunModify: Gun %d has no gun state\n"));
}

////////////////////////////////////////////////////////////////

int GunGetModification(ObjID objID)
{
   sGunState *pGunState;

   if (g_pGunStateProperty->Get(objID, &pGunState))
      return pGunState->m_modification;
   return 0;
}

////////////////////////////////////////////////////////////////

void GunSetModification(ObjID gunID, int mod)
{
   sGunState *pGunState;

   if (g_pGunStateProperty->Get(gunID, &pGunState))
   {
      AutoAppIPtr(ScriptMan);
      if ((pGunState->m_modification == 0) && (mod == 1))
      {
         sScrMsg msg(gunID, "Modify1"); 
         pScriptMan->SendMessage(&msg); 
         pGunState->m_modification = mod;
      }
      else if ((pGunState->m_modification == 1) && (mod == 2))
      {
         sScrMsg msg(gunID, "Modify2"); 
         pScriptMan->SendMessage(&msg); 
         pGunState->m_modification = mod;
      }
      else
         Warning(("Bad modification number or sequence on gun %d\n", gunID));
      g_pGunStateProperty->Set(gunID, pGunState);
   }
   else
      Warning(("GunModify: Gun %d has no gun state\n"));
}

/////////////////////////////////////////////

#ifndef SHIP

void SetGun(ObjID objID)
{
   AutoAppIPtr(PlayerGun);
   pPlayerGun->Set(objID);
}

void LoadGun(ObjID clipID)
{
   AutoAppIPtr(PlayerGun);
   GunLoad(pPlayerGun->Get(), clipID, LF_AUTOPLACE);
}

void GunSetting(int setting)
{
   ObjID gunID;
   AutoAppIPtr(PlayerGun);

   if ((gunID = pPlayerGun->Get()) != OBJ_NULL)
      GunSetSetting(gunID, setting);
}

void GunModify(int mod)
{
   ObjID gunID;
   AutoAppIPtr(PlayerGun);

   if ((gunID = pPlayerGun->Get()) != OBJ_NULL)
      GunSetModification(gunID, mod);
}

void GunGetNextProjectile()
{
   static ObjID projID = OBJ_NULL;
   AutoAppIPtr(PlayerGun);

   //mprintf("Proj = %d\n", projID = GetNextProjectile(pPlayerGun->Get(), projID));
}

static Command gunCommands[] =
{
   { "set_gun", FUNC_INT, SetGun, "Set an obj to be the current gun"},
   { "load_gun", FUNC_INT, LoadGun, "Load the current gun with ammo obj"},
   { "gun_setting", FUNC_INT, GunSetting, "Change the setting of the current gun"},
   { "modify_gun", FUNC_INT, GunModify, "Modify the current gun to level"},
   { "next_proj", FUNC_INT, GunGetNextProjectile, "Get the next valid projectile for gun"},
};

#endif

/////////////////////////////////////////////////
void GunInit(void)
{
   sCustomRelationDesc desc;
   sRelationDesc clipRelationDesc  = { "Clip", 0, 0, 0 };
   sRelationDataDesc noDataDesc = { "None", 0 };

   memset(&desc,0,sizeof(desc));

   cOrderedLinksByIntData *table = new cOrderedLinksByIntData;
   desc.DBs[kRelationSourceKnown] = new cFromObjQueryDatabase(table);

   g_pClipLinks = CreateStandardRelation(&clipRelationDesc, &noDataDesc, kQCaseSetSourceKnown);

   BaseGunDescPropertyInit();
   AIGunDescPropertyInit();
   PlayerGunDescPropertyInit();
   GunStatePropertyInit();
   GunAnimPropertyInit();
   AIGunNamePropInit();
   ProjectilePropertyInit();
   WeaponTypePropertyInit();
   GunReliabilityPropertyInit();
   GunKickPropertyInit();
   GunFlashInit();
   ProjectileLinksInit();

#ifndef SHIP
   // commands
   COMMANDS(gunCommands,HK_ALL);
#endif
}

/////////////////////////////////////////////

void GunShutdown(void)
{
   ProjectileLinksTerm();
   SafeRelease(g_baseGunDescProperty);
   SafeRelease(g_aiGunDescProperty);
   SafeRelease(g_playerGunDescProperty);
   SafeRelease(g_pGunStateProperty);
   SafeRelease(g_pProjectileProperty);
   SafeRelease(g_pWeaponTypeProperty);
   SafeRelease(g_pGunReliabilityProperty);
   SafeRelease(g_pGunKickProperty);
   GunAnimPropertyTerm();
   GunFlashTerm();
}

