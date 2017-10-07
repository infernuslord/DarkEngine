///////////////////////////////////////////////////////////////////////////////
// $Header: r:/t2repos/thief2/src/ai/aisched.h,v 1.2 2000/01/29 12:45:50 adurant Exp $
//
//
//
#pragma once

#ifndef __AISCHED_H
#define __AISCHED_H

struct sAIScheduleSettings
{
   BOOL fActive;
   long budget;
};

extern sAIScheduleSettings g_AIScheduleSettings;

#endif /* !__AISCHED_H */
