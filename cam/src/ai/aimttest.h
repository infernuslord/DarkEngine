///////////////////////////////////////////////////////////////////////////////
// $Header: r:/t2repos/thief2/src/ai/aimttest.h,v 1.1 1999/01/15 19:00:18 KATE Exp $
//
//
//

#ifndef __AIMTTEST_H
#define __AIMTTEST_H

#include <aibasabl.h>

#pragma once
#pragma pack(4)

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIMotionTagTestPlayer
//

class cAIMotionTagsTester : public cAIAbility
{
public:

   STDMETHOD_(const char *, GetName)();

   // Scheduling calls
   STDMETHOD_(void, ConnectAbility)(unsigned ** ppSignals);

   // Set/Get whether this is the ability currently running the AI
   STDMETHOD_(void, SetControl)(BOOL);
   STDMETHOD_(BOOL, InControl)();

   STDMETHOD_(void, Init)();

   // Notifications
   STDMETHOD_(void, OnActionProgress)(IAIAction * pAction);
   
   // Update the status of the current goal
   STDMETHOD_(eAIResult, UpdateGoal)(cAIGoal *);

   // Ability flow
   STDMETHOD (SuggestMode)   (sAIModeSuggestion *);
   STDMETHOD (SuggestGoal)   (cAIGoal * pPrevious, cAIGoal ** ppNew);
   STDMETHOD (SuggestActions)(cAIGoal * pGoal, const cAIActions & previous, cAIActions * pNew);

private:
   int m_current;
};

///////////////////////////////////////////////////////////////////////////////

#pragma pack()

#endif /* !__AIMTTEST_H */
