// $Header: x:/prj/tech/libsrc/gadget/RCS/lgadover.h 1.1 1996/05/21 13:38:38 xemu Exp $

#ifndef __LGADOVER_H
#define __LGADOVER_H

typedef enum {OverlayUpdate,OverlayDelete,OverlayNoChange} OverlayStatus;

typedef OverlayStatus (*OverlayUpdateFunc)(void *arg);

#endif