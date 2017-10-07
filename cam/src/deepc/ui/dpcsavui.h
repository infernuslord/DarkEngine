#pragma once  
#ifndef __DPCSAVUI_H
#define __DRKSAVUI_H

////////////////////////////////////////////////////////////
// DEEP COVER SAVE/LOAD UI
//

//
// Init/Term
//

EXTERN void DPCSaveUIInit(void);
EXTERN void DPCSaveUITerm(void); 

//
// Load panel
//
EXTERN void SwitchToDPCLoadGameMode(BOOL push); 
EXTERN void SwitchToDPCSaveGameMode(BOOL push); 


#endif // __DPCSAVUI_H
