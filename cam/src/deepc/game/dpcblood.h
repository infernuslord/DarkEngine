#pragma once
#ifndef __DPCBLOOD_H
#define __DPCBLOOD_H

#ifndef __DMGMODEL_H
#include <dmgmodel.h>
#endif // !__DMGMODEL_H

extern void DPCBloodInit(void);
extern void DPCBloodTerm(void);
extern void DPCReleaseBlood(const sDamageMsg* msg);

#endif // __DPCBLOOD_H
