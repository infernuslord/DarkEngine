// Deep Cover damage models
#pragma once

#ifndef __DPCDMG_H
#define __DPCDMG_H

#ifndef __DMGMODEL_H
#include <dmgmodel.h>
#endif // !__DMGMODEL_H

EXTERN void DPCDamageInit(void);
EXTERN void DPCDamageShutDown(void);

EXTERN eDamageResult LGAPI DPCDamageListener(const sDamageMsg* pMsg, tDamageCallbackData data);

#endif  // __DPCDMG_H