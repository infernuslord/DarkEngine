#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include "rng.h"

RNG* CreateRNGFibonacci()
{
    RNG *v0;
    RNG *v2;
    void *this;

    this = operator new(0xE8u);
    if(this)
    {
        RNGFibonacci::RNGFibonacci((RNGFibonacci *)this);
        v2 = v0;
    }
    else
    {
        v2 = 0;
    }
    return v2;
}

void* RNGFibonacci::GetState(long* sz)
{
    RNGFibonacci *v2;
    void *v3;
    void *v4;

    v2 = this;
    *sz = 228;
    v3 = operator new(0xE4u);
    v4 = v3;
    *(DWORD *)v3 = 21796;
    *((DWORD *)v3 + 1) = (signed int)((char *)v2->pI - (signed int)v2->data) >> 2;
    memcpy((char *)v3 + 8, v2->data, 0xDCu);
    return v4;
}

void RNGFibonacci::SetState(void* buf)
{
    RNGFibonacci *thisa;

    thisa = this;
    if(*(DWORD *)buf != 21796 || *((DWORD *)buf + 1) >= 55)
        _CriticalMsg("Invalid state for RNGFibonacci::SetState", "x:\\prj\\tech\\libsrc\\random\\rngfib.cpp", 0x28u);
    thisa->pI = &thisa->data[*((DWORD *)buf + 1)];
    thisa->pJ = thisa->pI + 31;
    if((signed int)((char *)thisa->pJ - (signed int)thisa->data) >> 2 > 55)
        thisa->pJ -= 55;
    memcpy(thisa->data, (char *)buf + 8, 0xDCu);
}

void RNGFibonacci::Seed(long seed)
{
    RNGFibonacci *thisa;
    signed int i;
    signed int ia;
    RNG *cong;

    thisa = this;
    cong = CreateRNGCongruential();
    cong->vfptr->Seed(cong, seed);
    thisa->data[0] = 2147483647;
    for(i = 1; i < 55; ++i)
        thisa->data[i] = cong->vfptr->GetLong(cong);
    for(ia = 0; ia < 1000; ++ia)
        thisa->baseclass_0.vfptr->GetLong((RNG *)thisa);
    if(cong)
        cong->vfptr->__vecDelDtor(cong, 1u);
}

long RNGFibonacci::GetLong()
{
    ++this->pI;

    if(this->pI >= (unsigned int *)&this[1])
        this->pI = this->data;

    ++this->pJ;

    if(this->pJ >= (unsigned int *)&this[1])
        this->pJ = this->data;

    *this->pI ^= *this->pJ;

    return *this->pI;
}

void* RNGFibonacci::scalar_deleting_destructor(unsigned int flags)
{
    void *thisa;

    thisa = this;
    RNGFibonacci::~RNGFibonacci();
    if(flags & 1)
        operator delete(thisa);
    return thisa;
}