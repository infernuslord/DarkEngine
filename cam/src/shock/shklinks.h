// $Header: r:/t2repos/thief2/src/shock/shklinks.h,v 1.3 2000/01/31 09:57:49 adurant Exp $
#pragma once

#ifndef __SHKLINKS_H
#define __SHKLINKS_H

#include <comtools.h>

F_DECLARE_INTERFACE(IRelation);

EXTERN IRelation * g_pReplicatorLinks;
EXTERN IRelation * g_pMutateLinks;

EXTERN void ShockLinksInit(void);
EXTERN void ShockLinksTerm(void);
#endif 