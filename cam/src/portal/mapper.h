#pragma once
#ifndef _MAPPER_H
#define _MAPPER_H

typedef struct point {
   fix x,y;
   int code;
   fix i;
} my_goof;

// portal clipping info
typedef struct {
   int l,t,r,b;
   int tl,tr,bl,br;
} ClipData;

#endif
