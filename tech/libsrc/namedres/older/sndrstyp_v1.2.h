//////////////////////////////////////////////////////////////////////////
//
// $Header: x:/prj/tech/libsrc/res2/RCS/sndrstyp.h 1.2 1998/06/29 12:18:32 JUSTIN Exp $
//
// Sound Resource Type. Trivial at this point, but we're keeping it separate
// for encapsulation later.
//


#ifndef _SNDRSTYP_H
#pragma once
#define _SNDRSTYP_H

#include <resapilg.h>

class cSoundResourceType : public IResType
{
 public:
   DECLARE_UNAGGREGATABLE();

   STDMETHOD_(const char *, GetName) ();
   STDMETHOD_(void, EnumerateExts) (tResEnumExtsCallback,
                                    void *pClientData);
   STDMETHOD_(BOOL, IsLegalExt) (const char *pExt);
   STDMETHOD_(IRes *, CreateRes) (IStore *pStore,
                                  const char *pName,
                                  const char *pExt,
                                  IResMemOverride **ppResMem);
};
#endif

//////////////////////////////////////////////////////////////////////////
