//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>



//----- (008E5B60) --------------------------------------------------------
void __cdecl GetPathTop(const char *pFullPath, char *pTopLevel, const char **ppPathRest)
{
	size_t i; // [sp+0h] [bp-8h]@5
	const char c; // [sp+4h] [bp-4h]@5

	if (pFullPath && pTopLevel && ppPathRest)
	{
		i = 0;
		for (c = *pFullPath; c && c != 92 && c != 47; c = pFullPath[i])
			++i;
		memmove(pTopLevel, pFullPath, i);
		pTopLevel[i] = 92;
		pTopLevel[i + 1] = 0;
		if (c)
			*ppPathRest = &pFullPath[i + 1];
		else
			*ppPathRest = &pFullPath[i];
	}
}

//----- (008E5C10) --------------------------------------------------------
char __cdecl PathAndName(const char *pPathName, char *pPath, char *pName)
{
	char result; // al@4
	int i; // [sp+0h] [bp-8h]@7
	size_t nSize; // [sp+4h] [bp-4h]@5

	if (pPathName && pPath && pName)
	{
		nSize = strlen(pPathName);
		*pPath = 0;
		*pName = 0;
		if ((signed int)nSize <= 544)
		{
			for (i = nSize - 1; i >= 0 && pPathName[i] != 92 && pPathName[i] != 47; --i)
				;
			if ((signed int)(nSize - i) <= 32)
			{
				memmove(pName, &pPathName[i + 1], nSize - i + 1);
				if (i < 0)
				{
					result = 0;
				}
				else
				{
					memmove(pPath, pPathName, i + 1);
					pPath[i + 1] = 0;
					result = 1;
				}
			}
			else
			{
				DbgReportWarning("PathAndName: name too long: %s\n");
				*pPath = 0;
				*pName = 0;
				result = 0;
			}
		}
		else
		{
			DbgReportWarning("PathAndName: path looks incredibly bogus: %s\n");
			*pPath = 0;
			*pName = 0;
			result = 0;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008E5D2E) --------------------------------------------------------
void __cdecl GetNormalizedPath(const char *pOldPath, char **ppNewPath)
{
	size_t nameLen; // [sp+0h] [bp-14h]@3
	signed int needSlash; // [sp+4h] [bp-10h]@3
	char *pNew; // [sp+8h] [bp-Ch]@6
	const char lastChar; // [sp+Ch] [bp-8h]@3
	const char *pOld; // [sp+10h] [bp-4h]@6

	if (pOldPath)
	{
		nameLen = strlen(pOldPath);
		lastChar = pOldPath[nameLen - 1];
		needSlash = 0;
		if (lastChar != 92 && lastChar != 47)
		{
			++nameLen;
			needSlash = 1;
		}
		*ppNewPath = (char *)MallocSpew(nameLen + 1, "x:\\prj\\tech\\libsrc\\namedres\\pathutil.cpp", 131);
		pOld = pOldPath;
		pNew = *ppNewPath;
		while (*pOld)
		{
			if (*pOld == 47)
				*pNew = 92;
			else
				*pNew = *pOld;
			++pOld;
			++pNew;
		}
		if (needSlash)
			*pNew++ = 92;
		*pNew = 0;
	}
	else
	{
		*ppNewPath = 0;
	}
}
