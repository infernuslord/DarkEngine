// $Header: r:/t2repos/thief2/src/engfeat/tweqrep.h,v 1.1 1998/08/16 22:53:34 dc Exp $
// expose the tweq properties

#pragma once

#ifndef __TWEQREP_H
#define __TWEQREP_H

#ifdef REPORT
EXTERN void TweqReportInit(void);
EXTERN void TweqReportTerm(void);
#else
#define TweqReportInit()
#define TweqReportTerm()
#endif

#endif
