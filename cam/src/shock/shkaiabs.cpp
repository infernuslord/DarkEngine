///////////////////////////////////////////////////////////////////////////////
// $Header: r:/t2repos/thief2/src/shock/shkaiabs.cpp,v 1.3 1999/04/30 08:31:28 JON Exp $
//
//
//

#include <shkaiabs.h>

#include <lg.h>

#include <comtools.h>
#include <appagg.h>

#include <aibassns.h>
#include <aibassns.h>
#include <aicnvabl.h>
#include <aidbgcmp.h>
#include <aideath.h>
#include <aiidle.h>
#include <ailisten.h>
#include <aimove.h>
#include <ainet.h>
#include <aipatrol.h>
#include <aipthfnd.h>
#include <aiscrabl.h>
#include <aisound.h>
#include <aistdmrg.h>
#include <aiwatch.h>

#include <shkaidmr.h>
#include <shkaipth.h>

// Must be last header
#include <dbmem.h>

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIActorBehaviorSet
//

STDMETHODIMP_(const char *) cAIActorBehaviorSet::GetName()
{
   return "ShockActor";
}

///////////////////////////////////////

void cAIActorBehaviorSet::CreateGenericAbilities(cAIComponentPtrs * pComponents)
{
   pComponents->Append(new cAIDeath);
   pComponents->Append(new cAIBasicScript);
}

////////////////////////////////////

void cAIActorBehaviorSet::CreateNonCombatAbilities(cAIComponentPtrs * pComponents)
{
   pComponents->Append(new cAIPatrol);
   pComponents->Append(new cAIIdle);
   pComponents->Append(new cAISignalResponse);
   pComponents->Append(new cAIWatch);
   pComponents->Append(new cAIConverse);
}

///////////////////////////////////////

void cAIActorBehaviorSet::CreateCombatAbilities(cAIComponentPtrs * pComponents)
{
}
