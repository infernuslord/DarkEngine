#pragma once

///////////////////////
// Animation tools for joints in a gun

#ifndef __GUNANIM_H
#define __GUNANIM_H

#include <matrixc.h>
#include <simtime.h>

// parameter animation - go to target 1 at rate 1, then target 2 at rate 2

typedef int eGunParamAnimFlags;
enum eGunParamAnimFlags_ {kGunAnimTarget2 = 0x0001};

typedef struct sGunParamAnim
{
   int m_flags;   // is target 2 valid?
   float m_target1;
   float m_rate1;
   float m_target2;
   float m_rate2;
} sGunParamAnim;

typedef struct sGunJointAnim
{
   int m_num;  // joint to animate
   sGunParamAnim m_params; 
} sGunJointAnim;

// Gun animation data
// currently just a joint animation
typedef struct sGunAnim
{
   sGunJointAnim m_jointAnim;
} sGunAnim;

// state of an individual animation component state

typedef int eGunAnimStateFlags;
enum eGunAnimStateFlags_ {kGunAnimReversed = 0x0001};

typedef struct sGunAnimState
{
   eGunAnimStateFlags m_flags;
   tSimTime m_reverseTime; // when we reversed this animation
} sGunAnimState;

// state of the whole animation

typedef int eGunAnimsStateFlags;
enum eGunAnimsStateFlags_ {kGunAnimating = 0x0001};

typedef struct sGunAnimsState
{
   eGunAnimsStateFlags m_flags;
   tSimTime m_startTime;            // when we started the animations
   sGunAnimState m_jointAnimState; // state of individual anims
} sGunAnimsState;

#endif //!__GUNANIM_H
