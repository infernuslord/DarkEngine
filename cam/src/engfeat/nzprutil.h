#pragma once

#ifndef __NZPRUTIL_H
#define __NZPRUTIL_H

///////////////////////////////////////////////////////////////////////////////
//
// Handy way to specifify nozeroing without having a seperate class for 
// every property
//

#ifdef __DATAOPS__H

template <class TYPE> 
class cNoZeroDataOps : public cClassDataOps<TYPE>
{
public:
   cNoZeroDataOps()
    : cClassDataOps<TYPE>(cClassDataOps<TYPE>::kNoFlags)
   {
   }
}; 

#else

class cNoZeroDataOps;

#endif // __DATAOPS_H

#endif // __NZPRUTIL_H
