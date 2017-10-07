#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include "rngcong.h"


RNGCongruential::RNGCongruential()
{
}

RNGCongruential::~RNGCongruential()
{
}

RNG CreateRNGCongruential()
{
    RNG *v0;
    RNG *v2;
    RNGCongruential *this;

    this = (RNGCongruential *)operator new(8u);
    if(this)
    {
        RNGCongruential::RNGCongruential(this);
        v2 = v0;
    }
    else
    {
        v2 = 0;
    }
    return v2;
}
