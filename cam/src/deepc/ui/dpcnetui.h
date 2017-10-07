#pragma once
#ifndef __DPCNETUI_H
#define __DPCNETUI_H

#ifndef __LOOPTYPE_H
#include <looptype.h>
#endif // !__LOOPTYPE_H

EXTERN void SwitchToDPCMultiplayUIMode(BOOL push);

EXTERN void DPCMultiplayUIInit(); 
EXTERN void DPCMultiplayUITerm(); 

#endif // __DPCNETUI_H
