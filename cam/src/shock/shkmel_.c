////////////////////////////////////////////
// $Header: r:/t2repos/thief2/src/shock/shkmel_.c,v 1.3 1999/06/06 19:15:39 JON Exp $

#include <plyablty.h>
#include <plyablt_.h>
#include <mschbase.h>
#include <shkcret.h>
#include <shkmel_.h>

// Must be last header
#include <dbmem.h>

// needs to be in c file for Watcom compile

//////////////
// THE MELEE ABILITY


// @NOTE: the arm position and rotation offsets here get overridden by the global
// position and rotation offsets passed in to the cPlayerMeleeAbility constructor.
// If you want these to win out, then pass in NULL for pos and rot offsets to the 
// constructor.  Probably what we really want is a property for global pos and rot offset 
// hanging off Melee and bow archetypes where the listener updates the
// associated player ability pos and rot offsets.  KJ 4/98

sPlayerSkillFullDesc g_meleeSkillDesc[] = {
// Melee Ready
   {          
      kShMC_PlayerArm, // controller id
      kTrans_Immediate,
      { kPSS_Ready, kPSS_SwingMediumLeft, kPSS_Ready, kPSS_End }, // connecting skills
      {                0 // maneuver skill data
      }, 
      "PlyrMelee 0",
      NULL,                   // schema name
      0,         // time to max
      0,         // mouse speed
      0,         // mouse zone
      0,         // slewSpeedScale
      0,         // rotateSpeedScale
      TRUE,      // IsIdleMotion
   },
// Melee Windup Medium Left
   {
      kShMC_PlayerArm, // controller id
      kTrans_Immediate,
      { kPSS_AtWoundMediumLeft, kPSS_SwingMediumLeft, kPSS_SwingMediumLeft, kPSS_End }, // connecting skills
      {   0 // maneuver skill data
      },              
      "PlyrMelee 1, PlyrMeleeSwing 1, Direction 1",
      NULL,                   // schema name
      0, // time to max
   },
// Melee At Wound Medium Left
   {
      kShMC_PlayerArm, // controller id
      kTrans_Immediate,
      { kPSS_Ready, kPSS_SwingMediumLeft, kPSS_SwingMediumLeft, kPSS_End }, // connecting skills
      {   0 // maneuver skill data
      },              
      NULL,
      NULL,                   // schema name
      0, // time to max
   },
// Melee Swing Medium Left
   {
      kShMC_PlayerArm, // controller id
      kTrans_AtEnd,
      { kPSS_Ready, kPSS_SwingMediumLeft, kPSS_Ready, kPSS_End }, // connecting skills
      {   0 // maneuver skill data
      },              
      "PlyrMelee 2, PlyrMeleeSwing 1, Direction 1",
      "Melee_swing_M",                   // schema name
      0, // time to max
   },
// Melee Windup Long
   {
      kShMC_PlayerArm, // controller id
      kTrans_Immediate,
      { kPSS_AtWoundLong, kPSS_SwingMediumLeft, kPSS_SwingMediumLeft, kPSS_End }, // connecting skills
      {   0 // maneuver skill data
      },              
      "PlyrMelee 1, PlyrMeleeSwing 2",
      NULL,                   // schema name
      0, // time to max
   },
// Melee At Wound Long
   {
      kShMC_PlayerArm, // controller id
      kTrans_Immediate,
      { kPSS_Ready, kPSS_SwingLong, kPSS_SwingLong, kPSS_End }, // connecting skills
      {   0 // maneuver skill data
      },              
      NULL,
      NULL,                   // schema name
      0, // time to max
   },
// Melee Swing Long
   {
      kShMC_PlayerArm, // controller id
      kTrans_AtEnd,
      { kPSS_Ready, kPSS_SwingMediumLeft, kPSS_Ready, kPSS_End }, // connecting skills
      {   0 // maneuver skill data
      },              
      "PlyrMelee 2, PlyrMeleeSwing 2",
      NULL,                   // schema name
      0, // time to max
   },
// Melee Begin
   {
      kShMC_PlayerArm, // controller id
      kTrans_Immediate,
      { kPSS_Ready, kPSS_SwingMediumLeft, kPSS_Ready, kPSS_End }, // connecting skills
      {                0 // maneuver skill data
      }, 
      "PlyrMelee 4",
      NULL,                   // schema name
   },
// Melee End
   {
      kShMC_PlayerArm, // controller id
      kTrans_Immediate,
      { kSkillInvalid, kSkillInvalid, kSkillInvalid, kSkillInvalid}, // connecting skills
      {                0 // maneuver skill data
      }, 
      "PlyrMelee 5",
      NULL,                   // schema name
   },
};
