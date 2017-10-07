//
//not sure if this file exists...

#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include "random.h"


void RandInit(long seed)
{
    //gRNGCongruential = CreateRNGCongruential();
    //gRNGCongruential->vfptr->Seed(gRNGCongruential, seed);
    //gRNGFibonacci = CreateRNGFibonacci();
    //gRNGFibonacci->vfptr->Seed(gRNGFibonacci, seed);
}

void RandShutdown(void)
{
    /*
    void *result; // eax@1

    result = gRNGCongruential;
    if(gRNGCongruential)
        result = gRNGCongruential->vfptr->__vecDelDtor(gRNGCongruential, 1u);
    if(gRNGFibonacci)
        result = gRNGFibonacci->vfptr->__vecDelDtor(gRNGFibonacci, 1u);
    return result;
    */
}

void RandSeed(long seed)
{
    //gRNGFibonacci->vfptr->Seed(gRNGFibonacci, seed);
}

void RandSeedQ(long seed)
{
    //gRNGCongruential->vfptr->Seed(gRNGCongruential, seed);

}
