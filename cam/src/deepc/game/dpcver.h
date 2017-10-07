#pragma once
#ifndef __DPCVER_H
#define __DPCVER_H

#ifndef __RESAPI_H
#include <resapilg.h>
#endif // !__RESAPI_H

EXTERN void  DPCVersionInit(int which);
EXTERN void  DPCVersionTerm(void);
EXTERN IRes *DPCVersionBitmap(void);

#endif  // ! __DPCVER_H