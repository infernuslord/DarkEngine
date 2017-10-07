#pragma once
#ifndef __CONTPROP_H
#define __CONTPROP_H

//////////////////////////////
#define PROP_CONTAIN_INHERIT_NAME "ContainInherit"

EXTERN void InitContainInheritProp(void);
EXTERN void TermContainInheritProp(void);
EXTERN BOOL ShouldContainInherit(ObjID obj);

#endif
