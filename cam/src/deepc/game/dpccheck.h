#pragma once
#ifndef __DPCCHECK_H
#define __DPCCHECK_H

#ifndef __WRTYPE_H
#include <wrtype.h>
#endif // !__WRTYPE_H

BOOL DPCCheckSphereLocation(const Location& testLoc, float radius);

#endif  // __DPCCHECK_H
