#pragma once
#ifndef __DPCALARM_H
#define __DPCALARM_H

extern "C" 
{
#include <event.h>
}

EXTERN void DPCAlarmDraw(unsigned long inDeltaTicks);
EXTERN void DPCAlarmInit(int which);
EXTERN void DPCAlarmTerm(void);
EXTERN void DPCHackIconDraw(unsigned long inDeltaTicks);
EXTERN void DPCHackIconInit(int which);
EXTERN void DPCHackIconTerm(void);

EXTERN void DPCAlarmAdd(int time);
EXTERN void DPCAlarmRemove(void);
EXTERN void DPCAlarmDisableAll(void);
#endif  // !__DPCALARM_H