///////////////////////////////////////////////////////////////////////////////
// $Header: r:/t2repos/thief2/src/shock/shkpick.h,v 1.2 2000/01/31 09:58:28 adurant Exp $
//
#pragma once

#ifndef __SHKPICK_H
#define __SHKPICK_H

#include <objtype.h>

EXTERN void ShockPickWeighObject(ObjID obj, float pickDistSquared, ObjID* pPickObj, float* pBestPickWeight);

#endif // __SHKPICK_H