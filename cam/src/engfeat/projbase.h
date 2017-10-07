#pragma once

#ifndef __PROJBASE_H
#define __PROJBASE_H

#include <mxang.h>

// info structure attached to a projectile archetype object
typedef struct sProjectile
{
   int m_spray;             // number of projectiles/trigger pull (instantaneous)
   mxs_ang m_spread;        // random angular error per shot
} sProjectile;

#endif //!__PROJBASE_H
