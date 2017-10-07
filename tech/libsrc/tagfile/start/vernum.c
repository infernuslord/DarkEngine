#include <Windows.h>
#include <lg.h>
#include <comtools.h>

#include "vernum.h"

extern char vbuf[32];

//----- (008FDFF0) --------------------------------------------------------
const char* VersionNum2String(const VersionNum *v)
{
	sprintf(vbuf, "%d.%02d", v->major, v->minor);
	return vbuf;
}

//----- (008FE019) --------------------------------------------------------
int VersionNumsCompare(const VersionNum *v1, const VersionNum *v2)
{
	int result; // eax@2

	if ( v1->major == v2->major )
	{
		if ( v1->minor == v2->minor )
			result = 0;
		else
			result = v1->minor - v2->minor;
	}
	else
	{
		result = v1->major - v2->major;
	}
	return result;
}



/*

//----- (008FDFF0) --------------------------------------------------------
const char *__cdecl VersionNum2String(VersionNum *v)
{
	sprintf(vbuf, "%d.%02d", v->major, v->minor);
	return vbuf;
}

//----- (008FE019) --------------------------------------------------------
int __cdecl VersionNumsCompare(VersionNum *v1, VersionNum *v2)
{
	int result; // eax@2

	if (v1->major == v2->major)
	{
		if (v1->minor == v2->minor)
			result = 0;
		else
			result = v1->minor - v2->minor;
	}
	else
	{
		result = v1->major - v2->major;
	}
	return result;
}


*/