#pragma once
#ifndef __DPCHUD_H
#define __DPCHUD_H

#ifndef _OBJTYPE_H
#include <objtype.h>
#endif // _OBJTYPE_H

EXTERN void DPCHUDDraw(unsigned long inDeltaTicks);
EXTERN void DPCHUDInit(int which);
EXTERN void DPCHUDTerm(void);
EXTERN void DPCHUDDrawRect(Rect r, ObjID o);

EXTERN void DPCHUDClear();

#endif