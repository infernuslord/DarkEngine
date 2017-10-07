#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include "rng.h"


RNG* CreateRNGCongruential()
{
    RNG *v0;
    RNG *v2;
    void *this;

    this = operator new(8u);
    if(this)
    {
        RNGCongruential::RNGCongruential((RNGCongruential *)this);
        v2 = v0;
    }
    else
    {
        v2 = 0;
    }
    return v2;
}

void* RNGCongruential::GetState(long* sz)
{
    RNGCongruential *v2;
    void *result;

    v2 = this;
    *sz = 8;
    result = operator new(8u);
    *(DWORD *)result = 23479589;
    *((DWORD *)result + 1) = v2->seed;
    return result;
}

void RNGCongruential::SetState(void* buf)
{
    RNGCongruential *thisa;

    thisa = this;
    if(*(DWORD *)buf != 23479589)
        _CriticalMsg("Invalid state for RNGCongruential::SetState", "x:\\prj\\tech\\libsrc\\random\\rngcong.cpp", 0x21u);
    thisa->seed = *((DWORD *)buf + 1);
}

void RNGCongruential::Seed(long sd)
{
    this->seed = sd;
}

long RNGCongruential::GetLong()
{
    this->seed = 1664525 * this->seed + 12345;
    return this->seed >> 1;
}

void* RNGCongruential::scalar_deleting_destructor(unsigned int flags)
{
    void *thisa;

    thisa = this;
    RNGCongruential::~RNGCongruential();
    if(flags & 1)
        operator delete(thisa);
    return thisa;
}

