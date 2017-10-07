// $Header: r:/t2repos/thief2/src/editor/proped.h,v 1.2 1997/12/05 19:23:37 mahk Exp $
#pragma once  
#ifndef __PROPED_H
#define __PROPED_H

#include <edtrait.h>
#include <edtraist.h>

#include <isdescty.h>

F_DECLARE_INTERFACE(IProperty); 

//
// Default Property EditTrait Implementation
//

//
// Base Property editor.  It is suggested that all property editors, custom or otherwise,
// derive from this. 
//

class cBasePropEditTrait : public cCTUnaggregated<IEditTrait,&IID_IEditTrait,kCTU_Default>
{
public:
   cBasePropEditTrait(IProperty* prop); 

   virtual ~cBasePropEditTrait(); 

   STDMETHOD_(const sEditTraitDesc*,Describe)();
   STDMETHOD_(const sEditTraitCaps*,Capabilities)();
   STDMETHOD_(BOOL,IntrinsicTo)(ObjID obj);
   STDMETHOD(Add)(ObjID obj); 
   STDMETHOD(Remove)(ObjID obj); 

protected:
   IProperty* Prop;
   sEditTraitDesc Desc;
   sEditTraitCaps Caps; 

}; 

//
// Sdesc-based property editor
//


class cSdescPropEditTrait : public cBasePropEditTrait
{
public:
   cSdescPropEditTrait(IProperty* property); 
   ~cSdescPropEditTrait(); 

   STDMETHOD_(const sEditTraitCaps*,Capabilities)();
   STDMETHOD(Edit)(ObjID obj); 
   STDMETHOD(Parse)(ObjID obj, const char* val) ; 
   STDMETHOD(Unparse)(ObjID obj, char* buf, int buflen);  

protected:
   const struct sStructDesc* Sdesc; 

}; 



#endif // __PROPED_H
