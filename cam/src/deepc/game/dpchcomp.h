#pragma once
#ifndef __DPCHCOMP_H
#define __DPCHCOMP_H

#ifndef _OBJTYPE_H
#include <objtype.h>
#endif // ! _OBJTYPE_H

extern "C"
{
#include <event.h>
}

EXTERN void DPCComputerInit(int which);
EXTERN void DPCComputerTerm(void);
EXTERN void DPCComputerDraw(unsigned long inDeltaTicks);
EXTERN void DPCComputerStateChange(int which);

#endif  // __DPCHCOMP_H