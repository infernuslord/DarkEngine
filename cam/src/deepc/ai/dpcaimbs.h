//
//

#ifndef __DPCAIMBS_H
#define __DPCAIMBS_H

#include <dpcaisbs.h>

#pragma once
#pragma pack(4)

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIMeleeBehaviorSet
//

class cAIMeleeBehaviorSet : public cAIDPCBehaviorSet
{
public:
   //
   // Find out the behavior set name
   //
   STDMETHOD_(const char *, GetName)();

protected:
   virtual void CreateCombatAbilities(cAIComponentPtrs * pComponents);
};

#pragma pack()
#endif /* !__DPCAIMBS_H */
