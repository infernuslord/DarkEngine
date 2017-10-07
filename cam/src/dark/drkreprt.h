// $Header: r:/t2repos/thief2/src/dark/drkreprt.h,v 1.3 1998/09/25 12:55:16 TOML Exp $
// dark specfic report functions

#pragma once

#ifndef __DRKREPRT_H
#define __DRKREPRT_H

/////////////////////////
// hey look

#ifdef REPORT
EXTERN void DarkReportInit(void);
EXTERN void DarkReportTerm(void);
#else
#define DarkReportInit()
#define DarkReportTerm()
#endif

#endif  // __DRKREPRT_H
