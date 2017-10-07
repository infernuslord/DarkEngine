///////////////////////////////////////////////////////////////////////////////
// $Source: r:/t2repos/thief2/src/framewrk/hchkthrd.h,v $
// $Author: adurant $
// $Date: 2000/01/29 13:21:01 $
// $Revision: 1.2 $
//
#pragma once

#ifndef __HCHKTHRD_H
#define __HCHKTHRD_H

#ifdef _WIN32

EXTERN void LGAPI HeapCheckActivate(int toggleKey);
EXTERN void LGAPI HeapCheckEnd();

#endif

#endif /* !__HCHKTHRD_H */
