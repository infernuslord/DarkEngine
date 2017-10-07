//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>



//----- (008E1B90) --------------------------------------------------------
cResourceTypeData *__thiscall cResMan::GetResourceTypeData(cResMan *this, IRes *pRes)
{
	cResourceTypeData *result; // eax@2
	void *pResControl; // [sp+4h] [bp-8h]@1
	cResourceTypeData *ResData; // [sp+8h] [bp-4h]@3

	if (pRes->baseclass_0.baseclass_0.vfptr->QueryInterface((IUnknown *)pRes, &IID_IResControl, &pResControl) >= 0)
	{
		ResData = (cResourceTypeData *)(*(int(__stdcall **)(void *))(*(_DWORD *)pResControl + 52))(pResControl);
		(*(void(__stdcall **)(void *))(*(_DWORD *)pResControl + 8))(pResControl);
		if (ResData == (cResourceTypeData *)-1)
		{
			DbgReportWarning("Resource without any Manager Data!\n");
			result = 0;
		}
		else
		{
			result = ResData;
		}
	}
	else
	{
		_CriticalMsg("Resource without an IResControl!", "x:\\prj\\tech\\libsrc\\namedres\\resmanx.cpp", 0x2Eu);
		result = 0;
	}
	return result;
}

//----- (008E1C01) --------------------------------------------------------
void __thiscall cResMan::InstallResourceType(cResMan *this, const char *pExt, IResType *pType)
{
	cResTypeData *v3; // eax@7
	cResTypeData *v4; // [sp+0h] [bp-10h]@7
	cResMan *thisa; // [sp+4h] [bp-Ch]@1
	void *v6; // [sp+8h] [bp-8h]@6
	cResTypeData *pData; // [sp+Ch] [bp-4h]@4

	thisa = this;
	if (pType && pExt)
	{
		pData = cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::Search(
			&this->m_ResTypeHash.baseclass_0.baseclass_0,
			pExt);
		if (pData)
		{
			++pData->m_nNumFactories;
			pData->m_pFactories = (IResType **)ReallocSpew(
				pData->m_pFactories,
				4 * pData->m_nNumFactories,
				"x:\\prj\\tech\\libsrc\\namedres\\resmanx.cpp",
				77);
			pData->m_pFactories[pData->m_nNumFactories - 1] = pType;
			pType->baseclass_0.vfptr->AddRef((IUnknown *)pType);
		}
		else
		{
			v6 = j__new(0x1Cu, "x:\\prj\\tech\\libsrc\\namedres\\resmanx.cpp", 84);
			if (v6)
			{
				cResTypeData::cResTypeData((cResTypeData *)v6, pExt, pType);
				v4 = v3;
			}
			else
			{
				v4 = 0;
			}
			cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::Insert(
				&thisa->m_ResTypeHash.baseclass_0.baseclass_0,
				v4);
		}
	}
}

//----- (008E1CD7) --------------------------------------------------------
void __thiscall cResMan::RemoveResourceType(cResMan *this, const char *pExt, IResType *pType)
{
	cResMan *thisa; // [sp+0h] [bp-Ch]@1
	int i; // [sp+4h] [bp-8h]@5
	cResTypeData *pData; // [sp+8h] [bp-4h]@4

	thisa = this;
	if (pType)
	{
		if (pExt)
		{
			pData = cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::Search(
				&this->m_ResTypeHash.baseclass_0.baseclass_0,
				pExt);
			if (pData)
			{
				for (i = 0; i < pData->m_nNumFactories && pData->m_pFactories[i] != pType; ++i)
					;
				if (i != pData->m_nNumFactories)
				{
					if (pData->m_nNumFactories == 1)
					{
						cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::Remove(
							&thisa->m_ResTypeHash.baseclass_0.baseclass_0,
							pData);
					}
					else
					{
						pData->m_pFactories[pData->m_nNumFactories - 1]->baseclass_0.vfptr->Release((IUnknown *)pData->m_pFactories[pData->m_nNumFactories - 1]);
						if (i < pData->m_nNumFactories - 1)
							memmove(&pData->m_pFactories[i], &pData->m_pFactories[i + 1], 4 * (pData->m_nNumFactories - (i + 1)));
						--pData->m_nNumFactories;
					}
				}
			}
		}
	}
}

//----- (008E1DE1) --------------------------------------------------------
int __thiscall cResMan::VerifyStorage(cResMan *this, IStore *pStorage)
{
	return pStorage && pStorage->baseclass_0.vfptr[3].AddRef((IUnknown *)pStorage);
}

//----- (008E1E0D) --------------------------------------------------------
void __thiscall cResMan::MungePaths(cResMan *this, const char *pPathName, const char *pExpRelPath, char **ppRelPath, char **ppName, char *pOldSlash, int *pbCombinedPaths)
{
	signed int needSlash; // [sp+4h] [bp-1Ch]@0
	size_t nExpLen; // [sp+8h] [bp-18h]@20
	int nImpLen; // [sp+10h] [bp-10h]@0
	size_t nNameSize; // [sp+14h] [bp-Ch]@7
	int i; // [sp+18h] [bp-8h]@7
	const char *pImpRelPath; // [sp+1Ch] [bp-4h]@1

	pImpRelPath = 0;
	*pbCombinedPaths = 0;
	if (!pPathName || !ppRelPath || !ppName || !pOldSlash || !pbCombinedPaths)
		_CriticalMsg("SplitPath called with missing arguments!", "x:\\prj\\tech\\libsrc\\namedres\\resmanx.cpp", 0xADu);
	*ppRelPath = 0;
	*ppName = 0;
	*pOldSlash = 0;
	nNameSize = strlen(pPathName);
	for (i = nNameSize - 1; i >= 0 && pPathName[i] != 92 && pPathName[i] != 47; --i)
		;
	if ((signed int)(nNameSize - i) <= 32 && (signed int)nNameSize <= 512)
	{
		if (i >= 0)
		{
			*pOldSlash = pPathName[i];
			pPathName[i] = 0;
			pImpRelPath = pPathName;
			*ppName = (char *)&pPathName[i + 1];
			nImpLen = i;
		}
		else
		{
			*ppName = (char *)pPathName;
		}
		if (pExpRelPath)
		{
			if (pImpRelPath)
			{
				*pbCombinedPaths = 1;
				nExpLen = strlen(pExpRelPath);
				if (pExpRelPath[nExpLen - 1] != 47 && pExpRelPath[nExpLen - 1] != 92)
				{
					needSlash = 1;
					++nExpLen;
				}
				*ppRelPath = (char *)MallocSpew(nExpLen + nImpLen + 1, "x:\\prj\\tech\\libsrc\\namedres\\resmanx.cpp", 230);
				strcpy(*ppRelPath, pExpRelPath);
				if (needSlash)
					strcat(*ppRelPath, "\\");
				strcat(*ppRelPath, pImpRelPath);
			}
			else
			{
				*ppRelPath = (char *)pExpRelPath;
			}
		}
		else
		{
			if (pImpRelPath)
				*ppRelPath = (char *)pImpRelPath;
		}
	}
	else
	{
		DbgReportWarning("SplitPath: name too long: %s\n");
	}
}

//----- (008E2000) --------------------------------------------------------
void __thiscall cResMan::RestorePath(cResMan *this, char *pPath, char *pName, char OldSlash, int bCombinedPaths)
{
	if (OldSlash)
		*(pName - 1) = OldSlash;
	if (bCombinedPaths)
		FreeSpew(pPath, "x:\\prj\\tech\\libsrc\\namedres\\resmanx.cpp", 255);
}

//----- (008E203A) --------------------------------------------------------
cResourceTypeData *__thiscall cResMan::FindResourceTypeData(cResMan *this, IStore *pStore, const char *pResName, IResType *pType)
{
	const char *v4; // eax@2
	cResourceTypeData *result; // eax@2
	cResourceData *pData; // [sp+Ch] [bp-4h]@1

	pData = cHashByResName::FindResData(&this->m_ResTable, pResName, pStore, 0);
	if (pData)
	{
		v4 = (const char *)((int(__stdcall *)(_DWORD))pType->baseclass_0.vfptr[1].QueryInterface)(pType);
		result = cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::Search(
			&pData->m_ResourceTypeHash.baseclass_0.baseclass_0,
			v4);
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008E208F) --------------------------------------------------------
IRes *__thiscall cResMan::GetResource(cResMan *this, const char *pName, const char *pTypeName, IStore *pStore)
{
	IRes *result; // eax@6
	cResMan *thisa; // [sp+0h] [bp-Ch]@1
	cResourceData *pData; // [sp+4h] [bp-8h]@5
	cResourceTypeData *pTypeData; // [sp+8h] [bp-4h]@7

	thisa = this;
	if (!pStore)
		_CriticalMsg("Trying to GetResource without a storage!", "x:\\prj\\tech\\libsrc\\namedres\\resmanx.cpp", 0x126u);
	if (!pTypeName)
		_CriticalMsg("Trying to GetResource without a type!", "x:\\prj\\tech\\libsrc\\namedres\\resmanx.cpp", 0x127u);
	pData = cHashByResName::FindResData(&thisa->m_ResTable, pName, pStore, 0);
	if (pData)
	{
		pTypeData = cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::Search(
			&pData->m_ResourceTypeHash.baseclass_0.baseclass_0,
			pTypeName);
		if (pTypeData)
		{
			pTypeData->m_pRes->baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)pTypeData->m_pRes);
			result = pTypeData->m_pRes;
		}
		else
		{
			result = 0;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008E2138) --------------------------------------------------------
IRes *__thiscall cResMan::CreateResource(cResMan *this, IStore *pStorage, const char *pName, const char *pExt, const char *pTypeName, const unsigned int __formal)
{
	IRes *result; // eax@5
	void *v7; // eax@14
	void *v8; // [sp+0h] [bp-2Ch]@14
	cResMan *thisa; // [sp+4h] [bp-28h]@1
	void *v10; // [sp+8h] [bp-24h]@13
	void *pResControl; // [sp+Ch] [bp-20h]@16
	void *pResMem; // [sp+10h] [bp-1Ch]@1
	void *pResTypeData; // [sp+14h] [bp-18h]@1
	IRes *pResource; // [sp+18h] [bp-14h]@1
	char NullExt; // [sp+1Ch] [bp-10h]@1
	void *pType; // [sp+20h] [bp-Ch]@1
	cResourceData *pData; // [sp+24h] [bp-8h]@1
	void *pTypeData; // [sp+28h] [bp-4h]@1

	thisa = this;
	pResTypeData = 0;
	pResource = 0;
	pData = 0;
	pTypeData = 0;
	NullExt = 0;
	pResMem = 0;
	pType = 0;
	if (!pTypeName)
		_CriticalMsg("CreateResource called without a type!", "x:\\prj\\tech\\libsrc\\namedres\\resmanx.cpp", 0x153u);
	if (pStorage && pName)
	{
		if (!pExt)
			pExt = &NullExt;
		pType = cResMan::GetResType(thisa, pTypeName);
		if (pType)
		{
			pResource = (IRes *)(*(int(__stdcall **)(void *, IStore *, const char *, const char *, void **))(*(_DWORD *)pType + 24))(
				pType,
				pStorage,
				pName,
				pExt,
				&pResMem);
			if (pResource)
			{
				pData = cHashByResName::FindResData(&thisa->m_ResTable, pName, pStorage, 1);
				if (!pData)
					_CriticalMsg(
					"Couldn't create entry in global resource table!",
					"x:\\prj\\tech\\libsrc\\namedres\\resmanx.cpp",
					0x16Au);
				v10 = j__new(0x28u, "x:\\prj\\tech\\libsrc\\namedres\\resmanx.cpp", 363);
				if (v10)
				{
					cResourceTypeData::cResourceTypeData((cResourceTypeData *)v10, (IResType *)pType, pData, pResource);
					v8 = v7;
				}
				else
				{
					v8 = 0;
				}
				pTypeData = v8;
				cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::Insert(
					&pData->m_ResourceTypeHash.baseclass_0.baseclass_0,
					(cResourceTypeData *)v8);
				*((_DWORD *)pTypeData + 2) = pResMem;
				*((_DWORD *)pTypeData + 9) = thisa->m_FreshStamp;
				if (pResource->baseclass_0.baseclass_0.vfptr->QueryInterface(
					(IUnknown *)pResource,
					&IID_IResControl,
					&pResControl) >= 0)
				{
					(*(void(__stdcall **)(void *, void *))(*(_DWORD *)pResControl + 48))(pResControl, pTypeData);
					(*(void(__stdcall **)(void *))(*(_DWORD *)pResControl + 8))(pResControl);
				}
			}
			result = pResource;
		}
		else
		{
			_CriticalMsg(
				"Caller asked to create unknown type of resource!",
				"x:\\prj\\tech\\libsrc\\namedres\\resmanx.cpp",
				0x15Eu);
			result = 0;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008E22EA) --------------------------------------------------------
void __thiscall cResMan::FreeData(cResMan *this, cResourceTypeData *pData, int bTestUser)
{
	const char *v3; // eax@8
	const char *v4; // eax@10
	cResMan *thisa; // [sp+0h] [bp-18h]@1
	void *pathName; // [sp+4h] [bp-14h]@21
	IResMemOverride *pResMem; // [sp+8h] [bp-10h]@17
	void *pResControl; // [sp+Ch] [bp-Ch]@19
	cResourceTypeData *pTestData; // [sp+10h] [bp-8h]@4
	cAutoResThreadLock lock; // [sp+14h] [bp-4h]@1

	thisa = this;
	cAutoResThreadLock::cAutoResThreadLock(&lock);
	if (pData)
	{
		if (pData->m_pProxiedRes)
			pTestData = pData->m_pProxiedRes;
		else
			pTestData = pData;
		if (bTestUser && pTestData->m_nUserLockCount)
		{
			cResourceTypeData::GetName(pTestData);
			v3 = _LogFmt("ResMan FreeData callback ignored. UserLock count = %d for %s\n");
			_CriticalMsg(v3, "x:\\prj\\tech\\libsrc\\namedres\\resmanx.cpp", 0x193u);
		}
		if (pTestData->m_nInternalLockCount != 1)
		{
			cResourceTypeData::GetName(pTestData);
			v4 = _LogFmt("ResMan FreeData callback ignored. Internal Lock count = %d for %s\n");
			_CriticalMsg(v4, "x:\\prj\\tech\\libsrc\\namedres\\resmanx.cpp", 0x199u);
		}
		if (bTestUser && pTestData->m_nUserLockCount || pTestData->m_nInternalLockCount != 1)
		{
			_CriticalMsg("Not Freeing locked data", "x:\\prj\\tech\\libsrc\\namedres\\resmanx.cpp", 0x19Eu);
			cAutoResThreadLock::_cAutoResThreadLock(&lock);
		}
		else
		{
			pData->m_nInternalLockCount = 0;
			if (pData->m_pProxiedRes)
			{
				pData->m_pProxiedRes = 0;
			}
			else
			{
				if (pData->m_pResMem)
					pResMem = pData->m_pResMem;
				else
					pResMem = (IResMemOverride *)&thisa->m_DefResMem;
				if ((**(int(__stdcall ***)(IRes *, GUID *, void **))pData->m_pRes)(
					pData->m_pRes,
					&IID_IResControl,
					&pResControl) >= 0)
				{
					if (g_fResPrintDrops)
					{
						((void(__stdcall *)(IRes *, void **))pData->m_pRes->baseclass_0.baseclass_0.vfptr[3].QueryInterface)(
							pData->m_pRes,
							&pathName);
						mprintf("cResMan::FreeData(): Freeing %s\n");
						if (pathName)
							FreeSpew(pathName, "x:\\prj\\tech\\libsrc\\namedres\\resmanx.cpp", 439);
					}
					if (!(*(int(__stdcall **)(void *, void *, unsigned int, IResMemOverride *))(*(_DWORD *)pResControl + 32))(
						pResControl,
						pData->m_pData,
						pData->m_nSize,
						pResMem))
						DbgReportWarning("cResMan::FreeData -- couldn't free resource!\n");
					cResStats::LogStatRes(thisa->m_pResStats, pData->m_pRes, kResStat_MemFreed);
					(*(void(__stdcall **)(void *))(*(_DWORD *)pResControl + 8))(pResControl);
				}
			}
			pData->m_pData = 0;
			pData->m_pRes->baseclass_0.baseclass_0.vfptr->Release((IUnknown *)pData->m_pRes);
			cAutoResThreadLock::_cAutoResThreadLock(&lock);
		}
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
	}
}
// EAC7C4: using guessed type int g_fResPrintDrops;

//----- (008E250E) --------------------------------------------------------
IResType *__thiscall cResMan::GetResType(cResMan *this, const char *pTypeName)
{
	IResType *result; // eax@2
	IResType **pTypeEntry; // [sp+4h] [bp-4h]@1

	pTypeEntry = (IResType **)cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::Search(
		&this->m_ResTypeByNameHash.baseclass_0.baseclass_0,
		pTypeName);
	if (pTypeEntry)
	{
		result = *pTypeEntry;
	}
	else
	{
		DbgReportWarning("GetResType called with unknown type %s!\n");
		result = 0;
	}
	return result;
}


