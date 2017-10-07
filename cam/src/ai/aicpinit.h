///////////////////////////////////////////////////////////////////////////////
// $Header: r:/t2repos/thief2/src/ai/aicpinit.h,v 1.4 2000/03/25 22:10:00 adurant Exp $
//
//
//
#pragma once

#ifndef __AICPINIT_H
#define __AICPINIT_H

#include <comtools.h>

F_DECLARE_INTERFACE(IAIManager);

BOOL AIInitStandardComponents(IAIManager * pManager);
BOOL AITermStandardComponents();
BOOL AIDBResetStandardComponents();

#endif /* !__AICPINIT_H */
