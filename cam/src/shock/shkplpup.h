// $Header: r:/t2repos/thief2/src/shock/shkplpup.h,v 1.2 2000/01/31 09:58:38 adurant Exp $
#pragma once

#ifndef __SHKPLPUP_H
#define __SHKPLPUP_H

#include <objtype.h>

ObjID PlayerPuppetCreate(const char *pModelName);
void PlayerPuppetDestroy(void);

#endif