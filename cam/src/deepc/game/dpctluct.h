#pragma once
#ifndef __DPCTLUCT_H
#define __DPCTLUCT_H

EXTERN void DPCTlucTextDraw(unsigned long inDeltaTicks);
EXTERN void DPCTlucTextInit(int which);
EXTERN void DPCTlucTextTerm(void);

EXTERN void DPCTlucTextAdd(char *name, char *table, int offset);

#endif  // !__DPCTLUCT_H