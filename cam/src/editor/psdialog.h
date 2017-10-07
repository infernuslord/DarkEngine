#pragma once

#include <aipsdscr.h>
#include <isdescty.h>
#include <isdescst.h>
#include <isdesced.h>
#include <sdesbase.h>

IStructEditor* NewPseudoScriptDialog (char* title, int maxSteps, sStructDesc* headerStruct, void* data, sAIPsdScrAct* steps);

