// $Header: r:/t2repos/thief2/src/deepc/game/dpcmiss.h,v 1.1 2000/01/26 19:07:11 porges Exp $
#pragma once  
#ifndef __DRKMISS_H
#define __DRKMISS_H
#include <comtools.h>

////////////////////////////////////////////////////////////
// DARK MISSION STUFF
//

struct sMissionData
{
   int num; // mission num 
   char path[9];  // path name 
}; 

typedef struct sMissionData sMissionData; 

EXTERN const sMissionData* GetMissionData(); 

// Pre-load mission data
F_DECLARE_INTERFACE(ITagFile); 
EXTERN void LoadMissionData(ITagFile* file); 
EXTERN void SaveMissionData(ITagFile* file); 

//
// Init/Term
//

EXTERN void MissionDataInit(); 
EXTERN void MissionDataTerm(); 

//
// Open a mission file 
//
EXTERN ITagFile* OpenMissionFile(int missnum); 

#endif // __DRKMISS_H




