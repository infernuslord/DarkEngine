///////////////////////////////////////////////////////////////////////////////
// $Header: r:/t2repos/thief2/src/shock/shkaimuc.cpp,v 1.4 1999/05/23 17:04:56 JON Exp $
//
//
//

#include <shkaimuc.h>

#include <aitrginf.h>

#include <mprintf.h>

#include <dbmem.h>

const eAITimerPeriod kAIShockFrustrationTime = kAIT_10Sec;

extern sHtoHModeSelections g_defaultShockModeSelections;

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIShockMultiCombat
//

cAIShockMultiCombat::cAIShockMultiCombat():
   m_HtoHSubcombat(&g_defaultShockModeSelections),
   m_HtoHFrustrationTimer(kAIShockFrustrationTime),
   m_rangedFrustrationTimer(kAIShockFrustrationTime)
{
   m_HtoHSubcombat.InitSubability(this);
   m_rangedSubcombat.InitSubability(this);
   m_rangedSubcombat.SetPhyscastCallback(tPhyscastObjTest(ShockRangedPhyscastCallback));
   SetSubcombat(&m_rangedSubcombat);
   m_HtoHFrustrationTimer.Force();
   m_rangedFrustrationTimer.Force();
}
   
///////////////////////////////////////

cAIShockMultiCombat::~cAIShockMultiCombat()
{
   SafeRelease(m_pActiveSubcombat);
}

///////////////////////////////////////

STDMETHODIMP_(void) cAIShockMultiCombat::GetSubComponents(cAIComponentPtrs * pResult)
{
   m_HtoHSubcombat.AddRef();
   pResult->Append(&m_HtoHSubcombat);
   m_rangedSubcombat.AddRef();
   pResult->Append(&m_rangedSubcombat);
}

///////////////////////////////////////////////////////////////////////////////

cAISubcombat* cAIShockMultiCombat::SelectSubcombat(cAIGoal * pGoal, const cAIActions & previous)
{
   const sAITargetInfo* pTargetInfo = GetTargetInfo();

   if (!m_HtoHFrustrationTimer.Expired())
   {
      if (m_rangedFrustrationTimer.Expired())
         return &m_rangedSubcombat;
   }
   else if (!m_rangedFrustrationTimer.Expired() && m_HtoHFrustrationTimer.Expired())
      return &m_HtoHSubcombat;

   // @TODO: make more sensible, propertize
   if (pTargetInfo->distSq<100)
      return &m_HtoHSubcombat;
   else
      return &m_rangedSubcombat;
}

///////////////////////////////////////////////////////////////////////////////

void cAIShockMultiCombat::SignalFrustration()
{
   if (m_pActiveSubcombat == &m_HtoHSubcombat)
      m_HtoHFrustrationTimer.Reset();
   else
      m_rangedFrustrationTimer.Reset();
}

///////////////////////////////////////////////////////////////////////////////

sHtoHModeSelections g_defaultShockModeSelections =
{
   //////////////////////////
   //
   // Responses
   //
   {
      // OpponentAttack
      {
         0,                                      // no flags
         {
            {kSwingQuick, 3},
            {kSwingNormal, 1},
            {kBlock, 9},
            {kBackoff, 6},
            {kUndecided, 7},  // dont respond at all
         }
      },

      // LowHitpoints
      {
         0,                                      // no flags
         {
            {kSwingQuick, 1},
            {kBlock, 6},
            {kBackoff, 3},
            {kDodge, 6},
            {kUndecided, 7},  // dont respond at all
         }
      },

      // Opening
      {
         0,                                      // no flags
         {
            {kSwingQuick, 2},
            {kSwingNormal, 4},
            {kSwingMassive, 6},
            {kSwingSpecial, 1},
            {kUndecided, 8},  // dont respond at all
         }
      },

      // TooCloseToOpponent
      {
         0,                                      // no flags
         {
            {kJumpback, 1}
         }
      },

      // RemainingTooCloseToOpponent
      {
         0,                                      // no flags
         {
            {kSwingQuick, 3},
            {kCircleCCW, 1},
            {kCircleCW, 1},
            {kDodge, 1},
         }
      },

      // FailedBackup
      {
         0,                                      // no flags
         {
            {kSwingQuick, 2},
            {kSwingNormal, 3},
            {kCircleCCW, 1},
            {kCircleCW, 1},
            {kBlock, 1},
            {kAdvance, 1},
         }
      },

      // Cornered
      {
         0,                                      // no flags
         {
            {kSwingNormal, 2},
            {kSwingMassive, 2},
            {kAdvance, 3},
            {kBlock, 2},
            {kIdle, 1},
         }
      },
   },

   //////////////////////////
   //
   // Attacks
   //
   {
      // NormalWhileIdle
      {
         0,                                      // no flags
         {
            {kSwingQuick,     2},
            {kSwingNormal,    4},
            {kSwingMassive,   6},
            {kSwingSpecial,   1},
            {kBlock,          1},
            {kCircleCW,       1},
            {kCircleCCW,      1},
         }
      },

      // NormalWhileActive
      {
         0,                                      // no flags
         {
            {kSwingQuick,     2},
            {kSwingNormal,    2},
            {kSwingMassive,   2},
            {kCircleCW,       2},
            {kCircleCCW,      2},
         }
      },

      // OpponentAttacking
      {
         0,                                      // no flags
         {
            {kSwingQuick,     1},
            {kSwingNormal,    1},
            {kBlock,          8},
            {kDodge,          8},
            {kCircleCW,       2},
            {kCircleCCW,      2},
         }
      },

      // OpponentBlocking
      {
         0,                                      // no flags
         {
            {kSwingMassive,   2},
            {kDodge,          2},
            {kIdle,           2},
            {kCircleCW,       2},
            {kCircleCCW,      2},
         }
      },

      // OpponentUnarmed
      {
         0,                                      // no flags
         {
            {kSwingQuick,     2},
            {kSwingNormal,    4},
            {kSwingMassive,   8},
            {kSwingSpecial,   2},
         }
      }
   }
};
