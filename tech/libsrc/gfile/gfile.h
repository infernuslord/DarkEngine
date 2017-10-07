//		GFILE.H		Generic graphics file access
//		Rex E. Bradford (REX)
/*
* $Header: x:/prj/tech/libsrc/gfile/RCS/gfile.h 1.8 1999/09/14 11:46:07 JAEMZ Exp $
* $Log: gfile.h $
 * Revision 1.8  1999/09/14  11:46:07  JAEMZ
 * Updated for the 90s
 * 
 * Revision 1.7  1999/09/14  11:37:59  JAEMZ
 * Added const
 * 
 * Revision 1.6  1998/07/01  18:27:10  PATMAC
 * Add extern "C"
 * 
 * Revision 1.5  1994/12/07  14:00:24  mahk
 * Added GfileFindParm
 * 
 * Revision 1.4  1993/10/19  15:10:42  xemu
 * added GfileWrite
 * 
 * Revision 1.3  1993/10/07  09:44:39  rex
 * Added BMP type
 * 
 * Revision 1.2  1993/09/27  19:21:25  rex
 * Added GFILE_CEL type
 * 
 * Revision 1.1  1993/09/27  16:38:49  rex
 * Initial revision
 * 
 * Revision 1.1  1993/09/27  15:58:02  rex
 * Initial revision
 * 
*/

#ifndef GFILE_H
#define GFILE_H
#pragma once

#include <stdio.h>
#include <rect.h>
#include <dev2d.h>
#include <lgdatapath.h>

typedef enum {
	GFILE_PCX,      // .pcx file (org. PC Paintbrush)
	GFILE_GIF,      // .gif file (org. Compuserve?)
	GFILE_CEL,	// .cel, .flc, or .fli (Autodesk Animator/Studio)
	GFILE_IFF,	// .iff (NOT SUPPORTED YET!)
	GFILE_BMP,	// .bmp file (Windows 3.x)
} GfileType;

typedef struct {        
	short index;	// index at which to start writing
	short numcols;	// number of colors to write
	uchar rgb[3 * 256];	// 0-256 rgb entries
} PallInfo;

typedef struct {
	GfileType type;	// GFILE_XXX
	grs_bitmap bm;	// bitmap
	uchar *ppall;	// ptr to pall, or NULL
} GfileInfo;

//	Function prototypes

EXTERN bool GfileRead(GfileInfo *pgfi, const char *filename, Datapath *pdp);
EXTERN bool GfileWrite(GfileInfo *pgfi, const char *filename, Datapath *pdp);
EXTERN void GfileFree(GfileInfo *pgfi);
EXTERN void GfileGetPall(GfileInfo *pgfi, PallInfo *ppall);

EXTERN void GfileGetImage(grs_bitmap *pbm, Rect *parea, uchar *pbits);
EXTERN bool GfileFindImage(grs_bitmap *pbm, Point currLoc, Rect *parea, uchar bordCol);
EXTERN int GfileFindAnchorRect(grs_bitmap *pbm, Rect *parea, uchar bordCol, Rect *panrect);
EXTERN int GfileFindParm(grs_bitmap *pbm, Rect *parea, uchar bordCol, int* parm);

#endif




