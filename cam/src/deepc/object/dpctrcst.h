#pragma once

#ifndef __DPCTRCST_H
#define __DPCTRCST_H

typedef enum eTrait {
   kTraitEmpty,      // 00

   // 01
   kTraitMetabolism, 
   kTraitPharmo,
   kTraitPackRat,
   kTraitSpeedy,
   kTraitSharpshooter,

   // 06
   kTraitAble,
   kTraitCybernetic,
   kTraitTank,
   kTraitLethal,     
   kTraitSecurity,

   // 11
   kTraitSmasher,
   kTraitBorg,
   kTraitReplicator,
   kTraitPsionic,
   kTraitTinker,

   // 16
   kTraitAutomap,

   kTraitMax,
};

#define NUM_TRAIT_SLOTS 4

#endif  // __DPCTRCST_H