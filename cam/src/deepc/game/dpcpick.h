#pragma once
#ifndef __DPCPICK_H
#define __DPCPICK_H

#ifndef _OBJTYPE_H
#include <objtype.h>
#endif // !_OBJTYPE_H

EXTERN void DPCPickWeighObject(ObjID obj, float pickDistSquared, ObjID* pPickObj, float* pBestPickWeight);

#endif // __DPCPICK_H