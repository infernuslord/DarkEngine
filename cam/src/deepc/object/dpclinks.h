#pragma once
#ifndef __DPCLINKS_H
#define __DPCLINKS_H

#ifndef __COMTOOLS_H
#include <comtools.h>
#endif // !__COMTOOLS_H

F_DECLARE_INTERFACE(IRelation);

EXTERN IRelation * g_pReplicatorLinks;
EXTERN IRelation * g_pMutateLinks;

EXTERN void DPCLinksInit(void);
EXTERN void DPCLinksTerm(void);
#endif // __DPCLINKS_H