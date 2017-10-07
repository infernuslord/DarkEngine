// $Header: r:/t2repos/thief2/src/framewrk/dlgmode.h,v 1.2 2000/01/29 13:20:43 adurant Exp $
#pragma once
#ifndef __DLGMODE_H
#define __DLGMODE_H

DEFINE_LG_GUID(LOOPID_DialogMode, 0x58);

EXTERN struct sLoopModeDesc DialogLoopMode;

EXTERN struct sLoopInstantiator* GetDialogLoopInst();

#endif // __DLGMODE_H
