// Deep Cover AI Utilities
//

#include <dpcaiutl.h>

#include <autolink.h>
#include <doorphys.h>
#include <linkman.h>
#include <lockprop.h>
#include <propman.h>
#include <relation.h>

// Must be last header
#include <dbmem.h>

IRelation* _g_pSwitchLinkRelation = NULL;
IRelation* _g_pTripwireRelation = NULL;

BOOL AIInDoorTripwire(ObjID AIID)
{
   if (_g_pTripwireRelation == NULL)
   {
      AutoAppIPtr(LinkManager);
      _g_pTripwireRelation = pLinkManager->GetRelationNamed("Tripwire");
      Assert_(_g_pTripwireRelation);
   }
   {
      cAutoLinkQuery query(_g_pTripwireRelation, LINKOBJ_WILDCARD, AIID);
      // assume tripwire link -> we are in tripwire
      if (!query->Done())
         return TRUE;
   }
   return FALSE;
}

///////////////////////////////////////////////////////
//
// Am I a door or any objects switched linked from me? (recursive)
//

BOOL DoorSearch(ObjID objID, int depth)
{
   if (IsDoor(objID))
      return TRUE;
   if (depth>1)
   {
      cAutoLinkQuery query(_g_pSwitchLinkRelation, objID, LINKOBJ_WILDCARD);
      
      while (!query->Done())
      {
         if (DoorSearch(query.GetDest(), depth-1))
            return TRUE;
         query->Next();
      }
   }
   return FALSE;
}

///////////////////////////////////////////////////////
//
// Am I a door trigger?
//

BOOL IsDoorTrigger(ObjID triggerID)
{
   if (_g_pSwitchLinkRelation == NULL)
   {
      AutoAppIPtr(LinkManager);
      _g_pSwitchLinkRelation = pLinkManager->GetRelationNamed("SwitchLink");
      Assert_(_g_pSwitchLinkRelation);
   }
   {
      cAutoLinkQuery query(_g_pSwitchLinkRelation, triggerID, LINKOBJ_WILDCARD);
      while (!query->Done())
      {
         if (DoorSearch(query.GetDest(), 2))
            return TRUE;
         query->Next();
      }
   }
   return FALSE;
}

