#pragma once
#ifndef __DPCCROSS_H
#define __DPCCROSS_H

#ifndef RECT_H
#include <rect.h>
#endif // !RECT_H

EXTERN void DPCCrosshairDraw(unsigned long inDeltaTicks);
EXTERN void DPCCrosshairInit(int which);
EXTERN void DPCCrosshairTerm(void);
EXTERN bool DPCCrosshairCheckTransp(Point pt);

#endif  // !__DPCCROSS_H