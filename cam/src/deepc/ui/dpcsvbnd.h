#pragma once
#ifndef __DPCSVBND_H
#define __DPCSVBND_H

EXTERN void SwitchToDPCLoadBndMode(BOOL push);
EXTERN void SwitchToDPCSaveBndMode(BOOL push); 

EXTERN void DPCInitBindSaveLoad(void); 
EXTERN void DPCTermBindSaveLoad(void); 


#endif // __DPCSVBND_H
