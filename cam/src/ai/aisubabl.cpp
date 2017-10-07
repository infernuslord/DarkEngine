///////////////////////////////////////////////////////////////////////////////
// $Header: r:/t2repos/thief2/src/ai/aisubabl.cpp,v 1.3 2000/02/19 12:45:44 toml Exp $
//
//
//

#include <aisubabl.h>
#include <aigoal.h>
#include <memall.h>
#include <dbmem.h>   // must be last header! 

///////////////////////////////////////////////////////////////////////////////

BOOL AISubabilityIsOwnerLosingControl(const IAIAbility * pAbility, const cAIGoal * pPrevious, const cAIGoal * pGoal)
{
   return ((!pGoal || pGoal->pOwner != (IAIAbility *)pAbility) && (pPrevious && pPrevious->pOwner == (IAIAbility *)pAbility));
}

///////////////////////////////////////////////////////////////////////////////
