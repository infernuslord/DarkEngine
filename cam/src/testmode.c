// $Header: r:/t2repos/thief2/src/testmode.c,v 1.2 2000/02/19 12:14:23 toml Exp $

#include <loopapi.h>
#include <testmode.h>
#include <scrnloop.h>
#include <testloop.h>
#include <memall.h>
#include <dbmem.h>   // must be last header! 

static tLoopClientID* TestLoopModeClients[] =
{
   &LOOPID_Test,
   &LOOPID_ScrnMan,
};

sLoopModeDesc TestLoopMode =
{
   { &LOOPID_DebugMode, "debug mode"}, 
   TestLoopModeClients,
   sizeof(TestLoopModeClients)/sizeof(TestLoopModeClients[0]),
};

