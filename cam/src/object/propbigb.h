// $Header: r:/t2repos/thief2/src/object/propbigb.h,v 1.2 2000/01/29 13:24:18 adurant Exp $
#pragma once

#ifndef PROPBIGB_H
#define PROPBIGB_H

////////////////////////////////////////////////////////////
// BASE TYPES FOR BIG ARRAY PROPERTY IMPLEMENTATION 
////////////////////////////////////////////////////////////


//
// Descriptor structure
//

typedef void* tPropArrayElem;


struct sPropArrayDesc
{
   tPropArrayElem* vector; // the actual vector
   ObjID min_idx;  // min_idx <= idx < max_idx
   ObjID max_idx; 
   int elemsize; // size of an element 
}; 


#endif // PROPBIGB_H
