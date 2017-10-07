/*
 * $Source: x:/prj/tech/libsrc/random/RCS/random.h $
 * $Revision: 1.4 $
 * $Author: JAEMZ $
 * $Date: 1998/07/10 18:06:21 $
 */
#ifndef __RANDOM_H
#define __RANDOM_H
#pragma once

#define rn1(n) (arandom() % (n))
#define RANDOM_MAX 0x7FFFFFFF
#define drand48() (arandom() / (RANDOM_MAX + 1.0))

// Call this first, or you're doomed to get crap.
EXTERN void RandInit(long seed);

// Returns the RandomInit seed or the last sarandom seed that was set.
EXTERN unsigned long RandGetSeed(void);

// Only call this if you want, RandomInit does it anyway
EXTERN void RandSeed(long seed);

// Call this for a good one
EXTERN long Rand(void);

// Call this for a good float between in the range [0 and 1)
EXTERN float RandFloat(void);

// Returns a normalized random variable,
// stdev 1, mean 0
// Not fast, takes log, sqrt, cos, and 2 uniform random variables.
EXTERN float RandNorm();


// These are called Q for Quick, but really they shouldn't be
// all that much faster than the above, it's a mul and add vs 
// 2 adds, 2 branches, and an xor.  So the difference should be very
// slight.  Here they are anyway.

// Only call this if you want, RandomInit does it anyway
EXTERN void RandSeedQ(long seed);

// Call this for a quickee
EXTERN long RandQ(void);

// Fast, bad float between [0 and 1)
EXTERN float RandFloatQ(void);



#endif
