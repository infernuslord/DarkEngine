// $Header: r:/t2repos/thief2/src/motion/motdmng_.h,v 1.3 2000/01/29 13:22:15 adurant Exp $
#pragma once

#ifndef __MOTDMNG__H
#define __MOTDMNG__H

#include <resapilg.h>

typedef struct 
{
   int numEntries;
   ulong offset[1];
} MotDataCTable;

typedef IRes *MotDataHandle;

EXTERN MotDataHandle *motDataHandles;

#define MotDmngeIsLocked(mot_num) (motDataHandles[mot_num]!=NULL)
#define MotDmngeHandle(mot_num) (motDataHandles[mot_num])


#endif
