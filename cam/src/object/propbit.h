// $Header: r:/t2repos/thief2/src/object/propbit.h,v 1.2 2000/01/29 13:24:19 adurant Exp $
#pragma once

#ifndef __PROPBIT_H
#define __PROPBIT_H

#include <propimp.h>
#include <packflag.h>
#include <osysbase.h>

typedef struct sPropArrayDesc sPropArrayDesc;

////////////////////////////////////////////////////////////
// 
// cObjBitVec
//
// Bit vector for handling negative obj IDs 
//
////////////////////////////////////////////////////////////

class cObjBitVec : private cPackedBoolSet
{
   typedef cPackedBoolSet cParent;
   ObjID min_obj;
   ObjID max_obj;

public:
   cObjBitVec(ObjID lo, ObjID hi)
      : cParent(hi-lo),
        min_obj(lo),
        max_obj(hi)
   {
   }


   BOOL IsSet(ObjID obj) const { return cParent::IsSet(obj - min_obj);};
   void Set(ObjID obj) { cParent::Set(obj - min_obj);};
   void Clear(ObjID obj) { cParent::Clear(obj - min_obj);};

   // val must be ONE or ZERO!
   void AssignBit(ObjID obj, int bit) { cParent::AssignBit(obj - min_obj,bit);};
   // more traditional bool
   void Assign(ObjID obj, BOOL bit) { cParent::Assign(obj - min_obj,bit);};

   void SetAll(void) { cParent::SetAll();};
   void ClearAll(void) { cParent::ClearAll(); }; 
   
   
}; 


////////////////////////////////////////////////////////////
//
// cPImpBitVec
//
// A bit array impl, intended for boolean properties.
//
////////////////////////////////////////////////////////////

class cPImpBitVec : public cPropertyImpl
{
   void NullOut();

   BOOL InBounds(ObjID obj) const { return obj >= min_idx && obj < max_idx; }; 
   
public:
   // Constructor
   cPImpBitVec (int elemsize, ObjID min = MIN_OBJS, ObjID max = MAX_OBJS);
   ~cPImpBitVec();

   //
   // cPropertyImpl methods.  See propimp.h for details
   //
   BOOL Get (ObjID obj, PropertyID propid, void **pptr) const;
   BOOL Set (ObjID obj, PropertyID propid, void *ptr);
   BOOL Delete(ObjID obj, PropertyID propid);
   void* Create(ObjID obj, PropertyID propid); 
   void Reset(PropertyID id); 
   void IterStart(PropertyID id, sPropertyObjIter* iter) const;
   BOOL IterNext(PropertyID id, sPropertyObjIter* iter, ObjID* next, void** value) const;
   void IterStop(PropertyID id, sPropertyObjIter* iter) const;
   BOOL Relevant (ObjID obj, PropertyID propid) const;
   
   //
   // Internal stuff
   //
   
protected:
   cObjBitVec     Relevance; // whether we are relevent
   cObjBitVec         Value;  // Bit array of relevance flags
   ObjID min_idx;
   ObjID max_idx;

};



#endif // __PROPBIT_H
