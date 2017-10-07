// Deep Cover AI Combat - ranged backup
//

#include <dpcaicrb.h>
#include <dpcaiutl.h>

// Must be last header
#include <dbmem.h>

////////////////////////////////////////

int cAIDPCRangedBackup::SuggestApplicability(void)
{
   if (AIInDoorTripwire(GetID()))
      return kAIRC_AppNone;
   return cAIRangedBackup::SuggestApplicability();
}

