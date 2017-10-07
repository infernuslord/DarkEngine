#pragma once
#ifndef __DPCBOOKO_H
#define __DPCBOOKO_H

extern "C"
{
#include <event.h>
}

EXTERN void DPCBookInit(int which);
EXTERN void DPCBookTerm(void);
EXTERN void DPCBookDraw(unsigned long inDeltaTicks);
EXTERN bool DPCBookHandleMouse(Point pos);
EXTERN void DPCBookStateChange(int which);

EXTERN void DPCBookDisplay(int level, int which);
#endif  // __DPCBOOKO_H