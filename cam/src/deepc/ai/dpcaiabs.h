//

#ifndef __DPCAIABS_H
#define __DPCAIABS_H

#include <dpcaisbs.h>

#pragma once
#pragma pack(4)

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIDPCBehaviorSet
//

class cAIActorBehaviorSet : public cAIDPCBehaviorSet
{
 public:
    //
    // Find out the behavior set name
    //
    STDMETHOD_(const char *, GetName)();

 protected:
    virtual void CreateGenericAbilities(cAIComponentPtrs   * pComponents);
    virtual void CreateNonCombatAbilities(cAIComponentPtrs * pComponents);
    virtual void CreateCombatAbilities(cAIComponentPtrs    * pComponents);
};

#pragma pack()
#endif /* !__DPCAIABS_H */
