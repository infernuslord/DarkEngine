#pragma once
#ifndef __DPCOPTMN_H
#define __DPCOPTMN_H

//////////////////////////////////////////////////////////////
// OPTIONS PANEL MODE FOR DEEP COVER
//

EXTERN void SwitchToDPCOptionsMode(BOOL push); 
EXTERN const struct sLoopInstantiator* DescribeDPCOptionsMode(void); 


EXTERN void DPCOptionsMenuInit();
EXTERN void DPCOptionsMenuTerm();


#endif // __DPCOPTMN_H
