// $Header: r:/prj/cam/src/RCS/linksave.h 1.1 1997/01/24 02:08:38 mahk Exp $

#ifndef LINKSAVE_H
#define LINKSAVE_H
#include <comtools.h>

////////////////////////////////////////////////////////////
// SAVE/LOAD for links
//

EXTERN void SaveAllLinks(IUnknown* file); 
EXTERN void LoadAllLinks(IUnknown* file); 

#endif // LINKSAVE_H
