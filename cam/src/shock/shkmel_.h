// $Header: r:/t2repos/thief2/src/shock/shkmel_.h,v 1.3 2000/01/31 09:57:58 adurant Exp $
#pragma once

#ifndef __SHKMEL__H
#define __SHKMEL__H

// this must be in same order as skills in static array
enum ePlayerMeleeSkill
{
   kPSS_Ready,
   kPSS_WindupMediumLeft,
   kPSS_AtWoundMediumLeft,
   kPSS_SwingMediumLeft,
   kPSS_WindupLong,
   kPSS_AtWoundLong,
   kPSS_SwingLong,
   kPSS_Begin,
   kPSS_End,
   kPSS_NumSkills
};

EXTERN sPlayerSkillFullDesc g_meleeSkillDesc[];

#endif
