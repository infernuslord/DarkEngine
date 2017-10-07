///////////////////////////////////////////////////////////////////////////////
// $Header: r:/t2repos/thief2/src/shock/shkaipth.cpp,v 1.5 1999/06/03 19:29:54 JON Exp $
//

#include <shkaipth.h>

#include <appagg.h>

#include <aiprops.h>

#include <autolink.h>
#include <doorphys.h>
#include <linkman.h>
#include <lockprop.h>
#include <propman.h>
#include <questapi.h>
#include <relation.h>

#include <shkfrob.h>
#include <shkprop.h>

#include <dbmem.h>

#define AIUsesDoors(obj)   AIGetProperty(g_pAIUsesDoorsProperty, (obj), TRUE)

static IBoolProperty* g_pAIUsesDoorsProperty = NULL;
static IRelation* g_pSwitchLinkRelation = NULL;

///////////////////////////////////////

void ShockAITermPathfinder(void)
{
   SafeRelease(g_pAIUsesDoorsProperty);
}

///////////////////////////////////////

STDMETHODIMP_(const char *) cShockAIPathfinder::GetName()
{
   return "Shock pathfinding component";
}

////////////////////////////////////////
//
// A hack, for sure
//

inline BOOL ShockAIIsTripwire(ObjID objID)
{
   return gPropTripFlags->IsRelevant(objID);
}

////////////////////////////////////////
//
// Is this object a quest filter that should currently be "locking" this door?
// This is really a hack, but we assume that anything with the QB Name property on 
// it is a QuestFilter.
//

BOOL cShockAIPathfinder::QuestBlock(ObjID objID) const
{
   const char* pQBName;
   int QBVal;
   int val;

   // Start by checking for quest props on obj
   if (!gPropQBName->Get(objID, &pQBName))
      return FALSE;
   gPropQBVal->Get(objID, &QBVal);
   AutoAppIPtr(QuestData);
   val = pQuestData->Get(pQBName);
   if (val<=QBVal)
      return TRUE;
   return FALSE;
}


///////////////////////////////////////
// 
// Recursive search back along switch links to specified depth.
// This function returns the result in the openable parameter.
// It is defensive in the sense that it will return FALSE if any lock
// or unset quest bit is encountered in the search. It will only return
// true if it encounters a tripwire and no locks or unset quest bits.
// The actual function return value is used to specify whether to continue
// searching or not.
// The initial value of the openable parameter is assumed to be FALSE.
//

BOOL cShockAIPathfinder::DoorOpenable(ObjID objID, int depth, BOOL& openable)
{
   cAutoLinkQuery query(g_pSwitchLinkRelation, LINKOBJ_WILDCARD, objID);

   if (depth<=0)
      return TRUE;

   while (!query->Done())
   {
      ObjID sourceID = query.GetSource();
      int keypadCode;

      // Check for impassable. 
      // Assume that anything with a keypad code property on it is a keypad
      if (ObjSelfLocked(sourceID) || QuestBlock(sourceID) || g_pPropKeypadCode->Get(sourceID, &keypadCode))
      {
         openable = FALSE;
         return FALSE;
      }
      if (ShockAIIsTripwire(sourceID))
         openable = TRUE;
      if ((depth>1) && !DoorOpenable(sourceID, depth-1, openable))
         return FALSE;
      query->Next();
   }
   return TRUE;
}

///////////////////////////////////////

STDMETHODIMP_(BOOL) cShockAIPathfinder::CanPassDoor(ObjID door)
{
   BOOL openable;

   // This is kind of stupid, but avoids ordering issues with init functions (& the AI)
   if (g_pAIUsesDoorsProperty == NULL)
   {
      AutoAppIPtr(PropertyManager);
      g_pAIUsesDoorsProperty = (IBoolProperty*)pPropertyManager->GetPropertyNamed("AI_UsesDoors");
      Assert_(g_pAIUsesDoorsProperty);
   }
   if (g_pSwitchLinkRelation == NULL)
   {
      AutoAppIPtr(LinkManager);
      g_pSwitchLinkRelation = pLinkManager->GetRelationNamed("SwitchLink");
      Assert_(g_pSwitchLinkRelation);
   }

   if (!AIUsesDoors(GetID()))
      return FALSE;

   if (!IsDoor(door) || GetDoorStatus(door) == kDoorOpen || GetDoorStatus(door) == kDoorOpening)
      return TRUE;

   // just do 2 deep search for now
   openable = FALSE;
   DoorOpenable(door, 2, openable);
   return openable;
}

