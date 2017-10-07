#pragma once
#ifndef __DPCHAZRD_H
#define __DPCHAZRD_H

extern "C" 
{
#include <event.h>
}

EXTERN void DPCRadDraw(unsigned long inDeltaTicks);
EXTERN void DPCRadInit(int which);
EXTERN void DPCRadTerm(void);
#endif  // !__DPCHAZRD_H