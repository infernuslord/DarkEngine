// $Header: r:/t2repos/thief2/src/motion/skillset.cpp,v 1.5 1998/10/05 17:27:57 mahk Exp $
//
// XXX THIS IS TEMPORARY AND SLOW
// real implentation will involve properties and links and designer input and stuff

#include <skillset.h>

// Must be last header 
#include <dbmem.h>


static tSkillID g_DummySkills[]= \
{ 
   "Teleport",
   "SinglePlay",
   "Glide",
   "StandNormal",
   "StandSearching",
   "StandCombat",
   "SwordSwing",
   "Walk",
   "WalkSearching",
   "Run",
   "CombatAdvance",
   "CombatBackup",
   "CombatSSLeft",
   "CombatSSRight",
};

BOOL SkillSetGetForObj(const ObjID objID, int *nSkills, tSkillID **ppSkills)
{
   *ppSkills=g_DummySkills;
   *nSkills=sizeof(g_DummySkills)/sizeof(tSkillID);
   return TRUE;
}

