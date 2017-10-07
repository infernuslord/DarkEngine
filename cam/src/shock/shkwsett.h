// $Header: r:/t2repos/thief2/src/shock/shkwsett.h,v 1.3 2000/01/31 09:59:37 adurant Exp $
#pragma once

#ifndef __SHKWSETT_H
#define __SHKWSETT_H

extern "C"
{
#include <event.h>
}
#include <objtype.h>

EXTERN void ShockSettingInit(int which);
EXTERN void ShockSettingTerm(void);
EXTERN void ShockSettingDraw(void);
EXTERN bool ShockSettingHandleMouse(Point pt);
EXTERN void ShockSettingStateChange(int which);

#endif