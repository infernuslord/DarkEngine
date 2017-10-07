// $Header: r:/t2repos/thief2/src/editor/isdesced.h,v 1.4 1997/11/07 18:37:12 mahk Exp $
#pragma once  
#ifndef __ISDESCED_H
#define __ISDESCED_H

#include <comtools.h>
#include <sdestype.h>
#include <isdescty.h>

////////////////////////////////////////////////////////////
// Struct Desc Editor API
//
// Mostly COM for interoperability
//

F_DECLARE_INTERFACE(IStructEditor);

enum eSdescModality_
{
   kStructEdModal,
   kStructEdModeless, 
};

typedef ulong eSdescModality;


#undef INTERFACE
#define INTERFACE IStructEditor
DECLARE_INTERFACE_(IStructEditor,IUnknown)
{
   DECLARE_UNKNOWN_PURE();

   //
   // Start the editor.  Call this one.
   // If Modal, returns TRUE iff the ok button was pushed. 
   // If Modeless, returns FALSE immediately
   //
   STDMETHOD_(BOOL,Go)(THIS_ eSdescModality modal) PURE;

#define IStructEditor_Go(p, a) COMCall1(p, Go, a) 

   //
   // Set the callback to be called when buttons get pushed
   //
   STDMETHOD(SetCallback)(THIS_ StructEditCB cb, StructEditCBData data) PURE;

#define IStructEditor_SetCallback(p, a, b) COMCall2(p, SetCallback, a, b)

   //
   // Accessors
   //
   STDMETHOD_(const sStructEditorDesc*,Describe)(THIS) PURE;
   STDMETHOD_(const sStructDesc*,DescribeStruct)(THIS) PURE;
   STDMETHOD_(void*,Struct)(THIS) PURE;

};
 
#define IStructEditor_Describe(p)         COMCall0(p, Describe)
#define IStructEditor_DescribeStruct(p)   COMCall0(p, DescribeStruct)
#define IStructEditor_Struct(p)           COMCall0(p, Struct)

#undef INTERFACE

EXTERN IStructEditor* CreateStructEditor(const sStructEditorDesc* eddesc, const sStructDesc* sdesc, void* editme); 

#endif // __ISDESCED_H
 
