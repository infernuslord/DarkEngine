///////////////////////////////////////////////////////////////////////////////
// $Header: r:/t2repos/thief2/src/shock/shkaiprb.h,v 1.5 2000/01/29 13:40:18 adurant Exp $
//
#pragma once

#ifndef __SHKAIPRB_H
#define __SHKAIPRB_H

#include <shkaisbs.h>

///////////////////////////////////////////////////////////////////////////////
//
// Protocol behavior set
//

class cAIProtocolBehaviorSet : public cAIShockBehaviorSet
{ 
public: 
   STDMETHOD_(const char *, GetName)()
   {
      return "Protocol";
   }
   
protected:
   virtual void CreateCombatAbilities(cAIComponentPtrs * pComponents);
   virtual void CreateGenericAbilities(cAIComponentPtrs * pComponents);
};

///////////////////////////////////////////////////////////////////////////////

#endif /* !__SHKAIPRB_H */
