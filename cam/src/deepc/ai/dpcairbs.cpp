//
//

#include <dpcairbs.h>

#include <lg.h>

#include <comtools.h>
#include <appagg.h>

#include <aiutils.h>
#include <aidbgcmp.h>
#include <aifreeze.h>
#include <aisound.h>

#include <dpcaimuc.h>

// Must be last header
#include <dbmem.h>

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIDPCRangedMeleeBehaviorSet
//

STDMETHODIMP_(const char *) cAIDPCRangedMeleeBehaviorSet::GetName()
{
   return "RangedMelee";
}

///////////////////////////////////////

void cAIDPCRangedMeleeBehaviorSet::CreateCombatAbilities(cAIComponentPtrs * pComponents)
{
   pComponents->Append(new cAIDPCMultiCombat);
}

