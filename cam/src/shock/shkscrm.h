// $Header: r:/t2repos/thief2/src/shock/shkscrm.h,v 1.2 1998/10/14 16:53:58 XEMU Exp $
#pragma once  
#ifndef __SHKSCRM_H
#define __SHKSCRM_H

#include <scrptmsg.h>

///////////////////////////////////////////////////////////////////////////////
//
// SHOCK SCRIPT MESSAGES
//

// Yes or No Dialog
#define kYorNMsgVer 1

struct sYorNMsg : public sScrMsg
{
   bool yes;

   sYorNMsg()
   {
   }

   // real constructor
   sYorNMsg(ObjID obj_to, bool decision)
   {
      // setup base scrMsg fields
      to = obj_to;
      free((void *)message);
      message = strdup("YorNDone");

      // then our fields
      yes = decision;
   }
         
   DECLARE_SCRMSG_PERSISTENT();

};

#ifdef SCRIPT
#define OnYorNDone()         SCRIPT_MESSAGE_HANDLER_SIGNATURE_(YorNDone, sYorNMsg)
#define DefaultOnYorNDone()  SCRIPT_CALL_BASE(YorNDone)
#endif

// Keypad messages
#define kKeypadMsgVer 1

struct sKeypadMsg : public sScrMsg
{
   int code;

   sKeypadMsg()
   {
   }

   // real constructor
   sKeypadMsg(ObjID obj_to, int codeval)
   {
      // setup base scrMsg fields
      to = obj_to;
      free((void *)message);
      message = strdup("KeypadDone");

      // then our fields
      code = codeval;
   }
         
   DECLARE_SCRMSG_PERSISTENT();

};

#ifdef SCRIPT
#define OnKeypadDone()         SCRIPT_MESSAGE_HANDLER_SIGNATURE_(KeypadDone, sKeypadMsg)
#define DefaultOnKeypadDone()  SCRIPT_CALL_BASE(KeypadDone)
#endif



#endif // __SHKSCRM_H
