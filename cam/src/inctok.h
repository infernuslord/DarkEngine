#pragma once
typedef union {
   char *strval;
   int  ival;
} INCSTYPE;
#define INCLUDE	257
#define DEFINE	258
#define INT	259
#define STRING	260
#define IDENT	261
extern INCSTYPE inclval;
