#pragma once
#ifndef __DPCDIFF_H
#define __DPCDIFF_H

enum eDPCifficulty
{
   kDPCDiffPlaytest,
   kDPCFirstDiff,
   kDPCDiffEasy = kDPCFirstDiff, 
   kDPCDiffNormal,
   kDPCDiffHard,
   kDPCDiffImpossible,
   kDPCLimDiff, 
   kNumDPCDiffs = kDPCLimDiff - kDPCFirstDiff,
   kDPCDiffMultiplay = kDPCLimDiff,
}; 

#endif // __DPCDIFF_H
