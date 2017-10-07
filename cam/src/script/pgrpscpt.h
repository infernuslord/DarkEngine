////////////////////////////////////////////////////////////////////////////////
// $Header: r:/t2repos/thief2/src/script/pgrpscpt.h,v 1.3 1998/09/21 23:17:14 CCAROLLO Exp $
//

#ifndef __PGRPSCPT_H
#define __PGRPSCPT_H

#pragma once

#include <scrptsrv.h>

////////////////////////////////////////
//
// Services
//
DECLARE_SCRIPT_SERVICE(PGroup, 0x1f8)
{
   STDMETHOD(SetActive)(ObjID PGroupObjID, BOOL active) PURE;
};

#endif
