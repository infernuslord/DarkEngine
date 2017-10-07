#ifndef __RNGCONG_H
#define __RNGCONG_H

#include "rng.h"

class RNGCongruential : public RNG
{
public:
    RNGCongruential();
    ~RNGCongruential();

    RNG *CreateRNGCongruential();

private:

};


#endif //__RNGCONG_H