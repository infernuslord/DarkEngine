///////////////////////////////////////////////////////////////////////////////
// $Header: r:/t2repos/thief2/src/sim/doorrep.h,v 1.2 2000/01/29 13:41:02 adurant Exp $
//
// Door report generation header
//
#pragma once

#ifndef __DOORREP_H
#define __DOORREP_H

#ifdef REPORT

EXTERN void InitDoorReports();
EXTERN void TermDoorReports();

#else

#define InitDoorReports()
#define TermDoorReports()

#endif

#endif
