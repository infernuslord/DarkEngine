// $Header: x:/prj/tech/libsrc/ui/RCS/tngqbox.h 1.14 1998/06/18 13:31:28 JAEMZ Exp $

#ifndef __TNGQBOX_H
#define __TNGQBOX_H
#pragma once

// Includes
#include <lg.h>  // every file should have this
#include <tng.h>

// Typedefs
typedef struct _QuickboxSlot {
   char *label;                // Text Label
   ulong options;              // Options mask
   int   vartype;              // Type of the slot
   void *var;                  // Pointer to actual variable
   void *p1, *p2;              // parameters
   struct _QuickboxSlot *next; // next slot in the box
   TNG *aux_tng;               // An auxilliary gadget, if relevant
   Point aux_size;
   TNG *tng;
} QuickboxSlot;

typedef struct {
   TNG *tng_data;
   Point size, slot_size, spacing, border;
   Ref left_id, right_id;
   int aux_size, internal_margin;
   ushort options;
   QuickboxSlot *slots;
   QuickboxSlot *current_slot;
} TNG_quickbox;

// SlotTypes
#define QB_INT_SLOT        0   // var is an int *
#define QB_SHORT_SLOT      1   // var is a short *
#define QB_BYTE_SLOT       2   // var is a ubyte *
#define QB_TEXT_SLOT       3   // var is a char *
#define QB_BOOL_SLOT       4   // var is a bool, and should be displayed as TRUE/FALSE
#define QB_PUSHBUTTON_SLOT 5   // var is a GadgetCallback to be called when the button using the label as text is pressed
                               // requires parameters to be set.  P1 is the user_data for the callback.  If P2 is null,
                               // then the label will be the text of the button.  If P2 is not null, it is taken as a
                               // pointer to a resource to display in the button, and the label will appear off to the
                               // right, like for other slot types
#define QB_FIX_SLOT        6   // fixpoint number
#define QB_UINT_SLOT        7   // var is an uint *

// Overall Options
// Align up all the data fields nicely
#define QB_ALIGNMENT    0x01

// Have the quickbox set the slot width to the minimum setting
// large enough to encompass the data for  every slot.
#define QB_AUTOSIZE     0x02

// Has the quickbox grab keyboard focus upon creation,
// releasing it upon exit.
#define QB_GRABFOCUS    0x04

// Add a "close" button at the bottom of the quickbox which
// will close it down.  If you want your own code to get run
// when quickbox closed, don't use this option!
#define QB_ADDCLOSE     0x08
  
// ********************
// *** SLOT OPTIONS ***
// ********************

// no options for this slot, plain vanilla
#define QB_NO_OPTION    0x0000

// the var can be toggled up and down with clickable arrows. 
// SUPPORTED TYPES:  INT_SLOT, SHORT_SLOT, BYTE_SLOT, BOOL_SLOT
#define QB_ARROWS       0x0001UL   

// the var has an associated slider which can be used to set it's value.  Requires parameters 
// which are the max and min values of the variable.  If variables not provided, default to 0 and 100
// for minimum and maximum.
// SUPPORTED TYPES:  INT_SLOT, SHORT_SLOT, BYTE_SLOT
#define QB_SLIDER       0x0002UL

// the var is for output purposes only and should not be allowed to be changed.
// SUPPORTED TYPES:  ALL
#define QB_RD_ONLY      0x0004UL                               

// limit the upper and lower limit of the start to p1 min and p2 max.
// SUPPORTED TYPES:  INT_SLOT, SHORT_SLOT, BYTE_SLOT
#define QB_BOUNDED      0x0008UL

// like QB_BOUNDED, but when max exceeded, cycles around to min
#define QB_CYCLE        0x0010UL

// These all constrain the slot to that type of number
// SUPPORTED TYPES:  INT_SLOT, SHORT_SLOT, BYTE_SLOT, only if standard display options chosen
#define QB_HEX          0x0020UL
#define QB_OCTAL        0x0040UL
#define QB_BINARY       0x0080UL

// Display the value of the slot as one a set of string values
// SUPPORTED TYPES:  INT_SLOT, SHORT_SLOT, BYTE_SLOT
// automatically inherits QB_CYCLE from 0 to the number of provided values
#define QB_STRINGSET    0x0100UL

// *****************
// ** KEY DEFINES **
// *****************

#define QB_RETURN_KEY          0xd
#define QB_UP_KEY              0x48
#define QB_DOWN_KEY            0x50
#define QB_LEFT_KEY            0x4b
#define QB_RIGHT_KEY           0x4d

#define TNG_QB_SELECTION_SPACING 0
#define TNG_QB_DEFAULT_SLIDER_SIZE  60

// Prototypes

// Initializes the TNG 
EXTERN errtype tng_quickbox_init(void *ui_data, TNG *ptng, TNGStyle *sty, ushort options, Point slot_size, Point spacing, Point border,
   Ref left_id, Ref right_id);

// Add a line to a quickbox.  slot_type describes the type of slot, var is a pointer to the variable to be
// displaying, and slot_options describes any additional modifiers to the qbox.  Note that some bizarre-o 
// combinations of options and types might not be implemented.
EXTERN errtype tng_quickbox_add(char *label, int slot_type, void *var, ulong slot_options);

// Just like gad_qbox_add but allows two parameters to be set for the slot.  Certain slot options require
// this form of accessing.
EXTERN errtype tng_quickbox_add_parm(char *label, int slot_type, void *var, ulong slot_options, void *parm1, void *parm2);

// Deallocate all memory used by the TNG 
EXTERN errtype tng_quickbox_destroy(TNG *ptng);

// This represents that the quickbox is done being created and is ready for display, input, etc.
EXTERN errtype tng_quickbox_end();

// Draw the specified parts (may be all) of the TNG at screen coordinates loc
// assumes all appropriate setup has already been done!
EXTERN errtype tng_quickbox_2d_draw(TNG *ptng, ushort partmask, Point loc);

// Fill in ppt with the size of the TNG 
EXTERN errtype tng_quickbox_size(TNG *ptng, Point *ppt);

// Returns the current "value" of the TNG
EXTERN int tng_quickbox_getvalue(TNG *ptng);

// React appropriately for receiving the specified cooked key
EXTERN bool tng_quickbox_keycooked(TNG *ptng, ushort key);

// React appropriately for receiving the specified mouse button event
EXTERN bool tng_quickbox_mousebutt(TNG *ptng, uchar type, Point loc);

// Handle incoming signals
EXTERN bool tng_quickbox_signal(TNG *ptng, ushort signal);

// Rename a slot
EXTERN errtype tng_quickbox_rename_slot(TNG *qb, int slot_num, char *new_name);

// Macros
#define TNG_QB(ptng) ((TNG_quickbox *)(ptng->type_data))
#define QB_CURRENT(ptng) TNG_QB(ptng)->current_slot
#define QB_SLOTS(ptng) TNG_QB(ptng)->slots

#endif // __TNGQBOX_H

