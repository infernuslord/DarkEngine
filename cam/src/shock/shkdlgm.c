// $Header: r:/t2repos/thief2/src/shock/shkdlgm.c,v 1.3 2000/02/19 13:20:14 toml Exp $

#include <loopapi.h>
#include <shkdlgm.h>
#include <scrnloop.h>
#include <shkdlg.h>
#include <uiloop.h>
#include <scrnman.h>
#include <editor.h>
#include <sndloop.h>
#include <schloop.h>
#include <memall.h>
#include <dbmem.h>   // must be last header! 

static tLoopClientID* DialogLoopModeClients[] =
{
   &LOOPID_Dialog,
   &LOOPID_ScrnMan,
   &LOOPID_Sound,
   &LOOPID_Schema,
   &LOOPID_UI,
};

sLoopModeDesc DialogLoopMode =
{
   { &LOOPID_DialogMode, "Dialog mode"}, 
   DialogLoopModeClients,
   sizeof(DialogLoopModeClients)/sizeof(DialogLoopModeClients[0]),
};




static ScrnManContext _scrnmode = 
{ 
   SCR_640x480, 
   0,
   MODE_FULLSCREEN,
}; 

static uiLoopContext _uidata = 
{
   REF_IMG_EditCursor,
};

static sLoopModeInitParm _InitContext[] =
{
   { &LOOPID_ScrnMan, (tLoopClientData)&_scrnmode}, 
   { &LOOPID_UI, (tLoopClientData)&_uidata}, 

   { NULL, } // terminator
};

static sLoopInstantiator _instantiator = 
{
   &LOOPID_DialogMode,
   0,
   _InitContext,
};

sLoopInstantiator* GetDialogLoopInst()
{
   return &_instantiator;
}
