//////////////////////////////////////////////////////////////////////////
//
// $Header: x:/prj/tech/libsrc/res2/RCS/palrstyp.h 1.1 1998/06/29 12:04:35 JUSTIN Exp $
//
// Palette Resource Type.
//


#ifndef _PALRSTYP_H
#pragma once
#define _PALRSTYP_H

#include <resapilg.h>

//
// Use this method to get the palette type; register that with the Resource
// Manager to use that type from here on out.
//
EXTERN IResType *MakePaletteResourceType();

#endif

//////////////////////////////////////////////////////////////////////////
