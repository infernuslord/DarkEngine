// $Header: r:/t2repos/thief2/src/object/propbig.h,v 1.5 2000/01/29 13:24:16 adurant Exp $
#pragma once

#ifndef PROPBIG_H
#define PROPBIG_H

#include <propimp.h>
#include <propbigb.h>
#include <osysbase.h>

typedef struct sPropArrayDesc sPropArrayDesc;

////////////////////////////////////////////////////////////
//
// cPImpArraySmall
//
// A single big array mapping objid's to values of small size (<= 4)
//
// Intended for simple properties.  Implements a single property only
//
////////////////////////////////////////////////////////////

class cPImpArraySmall : public cPropertyImpl, private sPropArrayDesc
{
   void NullOut();

   BOOL InBounds(ObjID obj) const { return obj >= min_idx && obj < max_idx; }; 
   
public:
   // Constructor
   cPImpArraySmall (const sPropArrayDesc*, BOOL sponsor_array = TRUE);
   cPImpArraySmall (int elemsize, ObjID min = MIN_OBJS, ObjID max = MAX_OBJS);
   ~cPImpArraySmall();

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
   ulong*         bitvec_;  // Bit array of relevance flags
   bool           delete_;  // should we delete vector

   int BitIdx(ObjID obj) const { return (obj - min_idx) / 32; }; 
   ulong BitMask(ObjID obj) const { return (ulong)(1 << ((obj - min_idx) % 32)); }; 
   int BitVecSize() const { return (max_idx - min_idx + 31)/32;}; 
   int VecSize() const { return (max_idx - min_idx); } ; 
   BOOL HaveObj(ObjID obj) const { return (bitvec_[BitIdx(obj)] & BitMask(obj)) != 0; };
};


////////////////////////////////////////////////////////////
//
// cPImpArrayLarge
//
// A single big array mapping objid's to values of any size
//
// Intended for complex properties.  Implements a single property only
//
////////////////////////////////////////////////////////////

class cPImpArrayLarge : public cPropertyImpl, private sPropArrayDesc
{
   void NullOut();

   BOOL InBounds(ObjID obj) const { return obj >= min_idx && obj < max_idx; }; 
   
public:
   // Constructor
   cPImpArrayLarge (const sPropArrayDesc*, BOOL sponsor = TRUE);
   cPImpArrayLarge (int elemsize, ObjID min = MIN_OBJS, ObjID max = MAX_OBJS);
   ~cPImpArrayLarge();

   //
   // cPropertyImpl methods.  See propimp.h for details
   //
   BOOL Get (ObjID obj, PropertyID propid, void **pptr) const;
   BOOL Set (ObjID obj, PropertyID propid, void *ptr);
   BOOL Delete(ObjID obj, PropertyID propid);
   void* Create(ObjID obj, PropertyID propid); 
   void Reset(PropertyID id); 
   void IterStart(PropertyID id, sPropertyObjIter* iter) const;
   virtual BOOL IterNext(PropertyID id, sPropertyObjIter* iter, ObjID* next, void** value) const;
   void IterStop(PropertyID id, sPropertyObjIter* iter) const;
   BOOL Relevant (ObjID obj, PropertyID propid) const;
   
protected:
   bool           delete_;  // should we delete vector

   int VecSize() const { return (max_idx - min_idx); } ; 
   BOOL HaveObj(ObjID obj) const { return vector[obj] != NULL;};
};

////////////////////////////////////////////////////////////
// Create a generic array property impl
//

cPropertyImpl* CreateArrayImpl(int size);


#endif // PROPBIG_H
