#pragma once
#ifndef __DPCIFTUL_H
#define __DPCIFTUL_H

EXTERN void DPCMFDNavButtonsInit();
EXTERN void DPCMFDNavButtonsTerm();
EXTERN void DPCMFDNavButtonsBuild(Rect *r);
EXTERN void DPCMFDNavButtonsDestroy();
EXTERN void DPCMFDNavButtonsDraw();

EXTERN void SetLeftMFDRect(int  which, Rect full_rect);
EXTERN void SetRightMFDRect(int which, Rect full_rect);

#endif  // __DPCIFTUL_H
