// $Header: x:/prj/tech/libsrc/gadget/RCS/gadgint.h 1.2 1996/08/15 00:04:59 mahk Exp $

#ifndef __GADGINT_H
#define __GADGINT_H

EXTERN LGadBox *LGadCreateBoxInternal(LGadBox *vbox, Region* root, short x, short y, short w, short h,
   LGadMouseCallback vmc, LGadKeyCallback vkc, DrawCallback drawcall, char paltype);

EXTERN int LGadDrawBoxInternal(LGadBox* box, void* data, Rect* drawrect);
#endif // __GADGINT_H

