// $Header: r:/t2repos/thief2/src/sound/schmsg.h,v 1.2 2000/01/29 13:41:54 adurant Exp $
#pragma once

#ifndef __SCHMSG_H
#define __SCHMSG_H

#include <schtype.h>

// Propagate a message originating from a given location and object (can be OBJ_NULL)
void SchemaMsgPropagate(sSchemaMsg *pMsg);

#endif
