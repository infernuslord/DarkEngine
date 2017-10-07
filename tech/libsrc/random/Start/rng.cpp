#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include "rng.h"


//From IDA
#define SLOBYTE(x)   (*((char*)&(x)))
#define LODWORD(x)  (*((DWORD*)&(x)))  // low dword



float RNG::GetFloat()
{
    double v1;
    float result;

    v1 = COERCE_FLOAT((unsigned int)loc_7FFFFF & ((int(*)(void))this->vfptr->GetLong)() | 0x3F800000) - 1.0;
    LODWORD(result) = LODWORD(v1);
    return result;
}

float RNG::GetNorm()
{
    RNG *v1;
    double v2;
    double v3;
    int v4;
    double v5;
    double v6;
    int v7;
    double v8;
    double v9;
    double v10;
    int v11;
    double v12;
    float result;



    v1 = this;
    v2 = RNG::GetFloat();
    v3 = v2;
    log(v4, SLOBYTE(v3));
    v5 = v2 * -2.0;
    v6 = v5;
    sqrt(v7, SLOBYTE(v6));
    v8 = v5;
    v9 = RNG::GetFloat() * 6.283185307179586;
    v10 = v9;
    cos(v11, SLOBYTE(v10));
    v12 = v9 * v8;
    LODWORD(result) = LODWORD(v12);
    return result;

}

long RNG::GetRange(long max)
{
    return ((int(__cdecl *)(DWORD))this->vfptr->GetLong)(this) % max;
}

void* RNG::vector_deleting_destructor(unsigned int flags)
{
    void *thisa;

    thisa = this;
    RNG::~RNG();
    if(flags & 1)
        operator delete(thisa);
    return thisa;
}
