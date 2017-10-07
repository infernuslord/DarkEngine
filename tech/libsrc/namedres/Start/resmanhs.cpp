//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>





//----- (008E0D10) --------------------------------------------------------
void __thiscall cResourceTypeData::cResourceTypeData(cResourceTypeData *this, IResType *pType, cResourceData *pResData, IRes *pRes)
{
	cResourceTypeData *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	this->m_pData = 0;
	this->m_nSize = 0;
	this->m_pResMem = 0;
	this->m_nUserLockCount = 0;
	this->m_nInternalLockCount = 0;
	this->m_pRes = 0;
	this->m_pType = 0;
	this->m_pResourceData = pResData;
	this->m_pProxiedRes = 0;
	this->m_Freshed = 0;
	if (!pResData)
		_CriticalMsg(
		"cResourceTypeData created without a pResData!",
		"x:\\prj\\tech\\libsrc\\namedres\\resmanhs.cpp",
		0x2Fu);
	if (pType)
	{
		thisa->m_pType = pType;
		thisa->m_pType->baseclass_0.vfptr->AddRef((IUnknown *)thisa->m_pType);
	}
	if (pRes)
		thisa->m_pRes = pRes;
}

//----- (008E0DD1) --------------------------------------------------------
void __thiscall cResourceTypeData::_cResourceTypeData(cResourceTypeData *this)
{
	const char *v1; // eax@2
	cResourceTypeData *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (this->m_pData)
	{
		cResourceTypeData::GetName(this);
		v1 = _LogFmt("Not freeing Data for resource %s\n");
		_CriticalMsg(v1, "x:\\prj\\tech\\libsrc\\namedres\\resmanhs.cpp", 0x44u);
	}
	if (thisa->m_pResMem)
	{
		thisa->m_pResMem->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pResMem);
		thisa->m_pResMem = 0;
	}
	if (thisa->m_pType)
		thisa->m_pType->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pType);
	if (thisa->m_pRes)
		thisa->m_pRes = 0;
}

//----- (008E0E62) --------------------------------------------------------
void __thiscall cHashByResourceType::cHashByResourceType(cHashByResourceType *this)
{
	cHashByResourceType *v1; // ST04_4@1

	v1 = this;
	cStrIHashSet<cResourceTypeData__>::cStrIHashSet<cResourceTypeData__>(&this->baseclass_0, 0x65u);
	v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashByResourceType::_vftable_;
}
// 9A819C: using guessed type int (__stdcall *cHashByResourceType___vftable_)(int __flags);

//----- (008E0E83) --------------------------------------------------------
void __thiscall cHashByResourceType::_cHashByResourceType(cHashByResourceType *this)
{
	cStrIHashSet<cResourceTypeData *> *v1; // ST00_4@1

	v1 = (cStrIHashSet<cResourceTypeData *> *)this;
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashByResourceType::_vftable_;
	cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::DestroyAll(&this->baseclass_0.baseclass_0);
	cStrIHashSet<cResourceTypeData__>::_cStrIHashSet<cResourceTypeData__>(v1);
}
// 9A819C: using guessed type int (__stdcall *cHashByResourceType___vftable_)(int __flags);

//----- (008E0EA7) --------------------------------------------------------
tHashSetKey__ *__thiscall cHashByResourceType::GetKey(cHashByResourceType *this, tHashSetNode__ *node)
{
	tHashSetKey__ *result; // eax@2

	if (node[6].unused)
		result = (tHashSetKey__ *)(*(int(__stdcall **)(_DWORD))(*(_DWORD *)node[6].unused + 12))(node[6].unused);
	else
		result = 0;
	return result;
}

//----- (008E0ED3) --------------------------------------------------------
void __thiscall cResourceData::cResourceData(cResourceData *this, IStore *pStore, cResourceName *pNameData)
{
	cResourceData *v3; // ST04_4@1

	v3 = this;
	this->m_pStore = pStore;
	this->m_pNameData = pNameData;
	cHashByResourceType::cHashByResourceType(&this->m_ResourceTypeHash);
	v3->m_pNext = 0;
	if (pStore)
		pStore->baseclass_0.vfptr->AddRef((IUnknown *)pStore);
}

//----- (008E0F1B) --------------------------------------------------------
void __thiscall cResourceData::_cResourceData(cResourceData *this)
{
	cResourceData *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	this->m_ResourceTypeHash.baseclass_0.baseclass_0.baseclass_0.vfptr->DestroyAll((cHashSetBase *)&this->m_ResourceTypeHash);
	if (thisa->m_pStore)
		thisa->m_pStore->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pStore);
	thisa->m_pStore = 0;
	cHashByResourceType::_cHashByResourceType(&thisa->m_ResourceTypeHash);
}

//----- (008E0F61) --------------------------------------------------------
void __thiscall cResourceName::cResourceName(cResourceName *this, const char *pResName)
{
	size_t v2; // ST10_4@2
	void **thisa; // [sp+0h] [bp-8h]@1

	thisa = (void **)this;
	this->m_pFirstStream = 0;
	this->m_ppFullNames = 0;
	this->m_fFlags = 0;
	if (pResName)
	{
		v2 = strlen(pResName);
		*thisa = MallocSpew(v2 + 1, "x:\\prj\\tech\\libsrc\\namedres\\resmanhs.cpp", 133);
		memmove(*thisa, pResName, v2 + 1);
		strlwr((char *)*thisa);
	}
	else
	{
		this->m_pName = 0;
	}
}

//----- (008E0FF6) --------------------------------------------------------
void __thiscall cResourceName::_cResourceName(cResourceName *this)
{
	void **v1; // eax@4
	cResourceName *thisa; // [sp+8h] [bp-20h]@1
	cDynArray<char *> *v3; // [sp+18h] [bp-10h]@5
	cResourceData *pNext; // [sp+1Ch] [bp-Ch]@10
	cResourceData *pData; // [sp+20h] [bp-8h]@8
	int i; // [sp+24h] [bp-4h]@2

	thisa = this;
	if (this->m_fFlags & 1)
	{
		for (i = 0; i < cDABase<char___4_cDARawSrvFns<char__>>::Size(&thisa->m_ppFullNames->baseclass_0.baseclass_0); ++i)
		{
			v1 = (void **)cDABase<char___4_cDARawSrvFns<char__>>::operator__(
				&thisa->m_ppFullNames->baseclass_0.baseclass_0,
				i);
			FreeSpew(*v1, "x:\\prj\\tech\\libsrc\\namedres\\resmanhs.cpp", 150);
		}
		v3 = thisa->m_ppFullNames;
		if (v3)
			cDynArray<char__>::_scalar_deleting_destructor_(v3, 1u);
	}
	else
	{
		for (pData = this->m_pFirstStream; pData; pData = pNext)
		{
			pNext = pData->m_pNext;
			if (pData)
				cResourceData::_scalar_deleting_destructor_(pData, 1u);
		}
	}
	thisa->m_pFirstStream = 0;
	if (thisa->m_pName)
	{
		FreeSpew(thisa->m_pName, "x:\\prj\\tech\\libsrc\\namedres\\resmanhs.cpp", 166);
		thisa->m_pName = 0;
	}
}

//----- (008E1100) --------------------------------------------------------
void __thiscall cHashByResName::cHashByResName(cHashByResName *this)
{
	cHashByResName *v1; // ST04_4@1

	v1 = this;
	cStrIHashSet<cResourceName__>::cStrIHashSet<cResourceName__>(&this->baseclass_0, 0x65u);
	v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashByResName::_vftable_;
}
// 9A81BC: using guessed type int (__stdcall *cHashByResName___vftable_)(int __flags);

//----- (008E1121) --------------------------------------------------------
void __thiscall cHashByResName::_cHashByResName(cHashByResName *this)
{
	cStrIHashSet<cResourceName *> *v1; // ST00_4@1

	v1 = (cStrIHashSet<cResourceName *> *)this;
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashByResName::_vftable_;
	cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::DestroyAll(&this->baseclass_0.baseclass_0);
	cStrIHashSet<cResourceName__>::_cStrIHashSet<cResourceName__>(v1);
}
// 9A81BC: using guessed type int (__stdcall *cHashByResName___vftable_)(int __flags);

//----- (008E1145) --------------------------------------------------------
tHashSetKey__ *__thiscall cHashByResName::GetKey(cHashByResName *this, tHashSetNode__ *node)
{
	tHashSetKey__ *result; // eax@2

	if (node->unused)
		result = (tHashSetKey__ *)node->unused;
	else
		result = 0;
	return result;
}

//----- (008E1163) --------------------------------------------------------
cResourceData *__thiscall cHashByResName::FindResData(cHashByResName *this, const char *pName, IStore *pStore, int bCreate)
{
	cResourceData *result; // eax@3
	char **v5; // eax@11
	void *v6; // eax@24
	void *v7; // eax@32
	void *v8; // eax@35
	const char *v9; // eax@37
	const char *v10; // eax@38
	const char *v11; // eax@40
	int v12; // eax@40
	int v13; // eax@42
	cDynArray<char *> *v14; // eax@43
	size_t v15; // eax@46
	cDynArray<char *> *v16; // [sp+0h] [bp-54h]@43
	int v17; // [sp+4h] [bp-50h]@40
	void *v18; // [sp+8h] [bp-4Ch]@35
	void *v19; // [sp+Ch] [bp-48h]@32
	void *v20; // [sp+10h] [bp-44h]@24
	cHashByResName *thisa; // [sp+14h] [bp-40h]@1
	void *v22; // [sp+18h] [bp-3Ch]@42
	void *v23; // [sp+1Ch] [bp-38h]@39
	void *v24; // [sp+20h] [bp-34h]@34
	void *v25; // [sp+24h] [bp-30h]@31
	void *v26; // [sp+28h] [bp-2Ch]@23
	void *pNameCopy; // [sp+2Ch] [bp-28h]@46
	cFileSpec FileSpec; // [sp+30h] [bp-24h]@37
	cAnsiStr Root; // [sp+38h] [bp-1Ch]@37
	int i; // [sp+44h] [bp-10h]@9
	cResourceData *pPrev; // [sp+48h] [bp-Ch]@15
	cResourceName *pNameData; // [sp+4Ch] [bp-8h]@7
	cResourceData *pData; // [sp+50h] [bp-4h]@7

	thisa = this;
	if (!bCreate || pStore)
	{
		if (pName && *pName)
		{
			pData = 0;
			pNameData = cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::Search(
				&this->baseclass_0.baseclass_0,
				pName);
			if (pNameData)
			{
				if (pNameData->m_fFlags & 1)
				{
					for (i = 0;
						i < cDABase<char___4_cDARawSrvFns<char__>>::Size(&pNameData->m_ppFullNames->baseclass_0.baseclass_0);
						++i)
					{
						v5 = cDABase<char___4_cDARawSrvFns<char__>>::operator__(
							&pNameData->m_ppFullNames->baseclass_0.baseclass_0,
							i);
						pData = cHashByResName::FindResData(thisa, *v5, pStore, 0);
						if (pData)
							return pData;
					}
					result = 0;
				}
				else
				{
					pData = pNameData->m_pFirstStream;
					pPrev = pData;
					if (pStore || !pData)
					{
						while (pData)
						{
							if (pData->m_pStore == pStore)
								return pData;
							pPrev = pData;
							pData = pData->m_pNext;
						}
						if (bCreate)
						{
							v26 = j__new(0x20u, "x:\\prj\\tech\\libsrc\\namedres\\resmanhs.cpp", 243);
							if (v26)
							{
								cResourceData::cResourceData((cResourceData *)v26, pStore, pNameData);
								v20 = v6;
							}
							else
							{
								v20 = 0;
							}
							pData = (cResourceData *)v20;
							if (pPrev)
								pPrev->m_pNext = pData;
							else
								pNameData->m_pFirstStream = pData;
						}
						result = pData;
					}
					else
					{
						result = pData;
					}
				}
			}
			else
			{
				if (bCreate)
				{
					v25 = j__new(0x10u, "x:\\prj\\tech\\libsrc\\namedres\\resmanhs.cpp", 257);
					if (v25)
					{
						cResourceName::cResourceName((cResourceName *)v25, pName);
						v19 = v7;
					}
					else
					{
						v19 = 0;
					}
					pNameData = (cResourceName *)v19;
					v24 = j__new(0x20u, "x:\\prj\\tech\\libsrc\\namedres\\resmanhs.cpp", 258);
					if (v24)
					{
						cResourceData::cResourceData((cResourceData *)v24, pStore, pNameData);
						v18 = v8;
					}
					else
					{
						v18 = 0;
					}
					pData = (cResourceData *)v18;
					pNameData->m_pFirstStream = (cResourceData *)v18;
					cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::Insert(
						&thisa->baseclass_0.baseclass_0,
						pNameData);
					cFileSpec::cFileSpec(&FileSpec, pName);
					cAnsiStr::cAnsiStr(&Root);
					cFileSpec::GetFileRoot(&FileSpec, &Root);
					v9 = cAnsiStr::operator char_const__(&Root);
					if (_strcmpi(pName, v9))
					{
						v10 = cAnsiStr::operator char_const__(&Root);
						pNameData = cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::Search(
							&thisa->baseclass_0.baseclass_0,
							v10);
						if (!pNameData)
						{
							v23 = j__new(0x10u, "x:\\prj\\tech\\libsrc\\namedres\\resmanhs.cpp", 272);
							if (v23)
							{
								v11 = cAnsiStr::operator char_const__(&Root);
								cResourceName::cResourceName((cResourceName *)v23, v11);
								v17 = v12;
							}
							else
							{
								v17 = 0;
							}
							pNameData = (cResourceName *)v17;
							v13 = *(_DWORD *)(v17 + 12);
							LOBYTE(v13) = v13 | 1;
							*(_DWORD *)(v17 + 12) = v13;
							v22 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\resmanhs.cpp", 274);
							if (v22)
							{
								cDynArray<char__>::cDynArray<char__>((cDynArray<char *> *)v22);
								v16 = v14;
							}
							else
							{
								v16 = 0;
							}
							pNameData->m_ppFullNames = v16;
							cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::Insert(
								&thisa->baseclass_0.baseclass_0,
								pNameData);
						}
						v15 = strlen(pName);
						pNameCopy = MallocSpew(v15 + 1, "x:\\prj\\tech\\libsrc\\namedres\\resmanhs.cpp", 277);
						strcpy((char *)pNameCopy, pName);
						cDABase<char___4_cDARawSrvFns<char__>>::Append(
							&pNameData->m_ppFullNames->baseclass_0.baseclass_0,
							(char *const *)&pNameCopy);
					}
					else
					{
						DbgReportWarning("FindResData: Created real entry without extension!\n");
					}
					cAnsiStr::_cAnsiStr(&Root);
					cFileSpec::_cFileSpec(&FileSpec);
				}
				result = pData;
			}
		}
		else
		{
			DbgReportWarning("FindResData: Empty name!");
			result = 0;
		}
	}
	else
	{
		_CriticalMsg("FindResData: Can't create without pStore!", "x:\\prj\\tech\\libsrc\\namedres\\resmanhs.cpp", 0xC2u);
		result = 0;
	}
	return result;
}

//----- (008E14E7) --------------------------------------------------------
void __thiscall cResTypeData::cResTypeData(cResTypeData *this, const char *pName, IResType *pType)
{
	cResTypeData *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (pName && pType)
	{
		strncpy(this->m_Name, pName, 0x14u);
		thisa->m_Name[19] = 0;
		strlwr(thisa->m_Name);
		pType->baseclass_0.vfptr->AddRef((IUnknown *)pType);
		thisa->m_pFactories = (IResType **)MallocSpew(4u, "x:\\prj\\tech\\libsrc\\namedres\\resmanhs.cpp", 301);
		*thisa->m_pFactories = pType;
		thisa->m_nNumFactories = 1;
	}
	else
	{
		this->m_Name[0] = 0;
		this->m_pFactories = 0;
		this->m_nNumFactories = 0;
	}
}

//----- (008E1583) --------------------------------------------------------
void __thiscall cResTypeData::_cResTypeData(cResTypeData *this)
{
	cResTypeData *thisa; // [sp+0h] [bp-8h]@1
	int i; // [sp+4h] [bp-4h]@2

	thisa = this;
	if (this->m_nNumFactories)
	{
		for (i = 0; i < thisa->m_nNumFactories; ++i)
			thisa->m_pFactories[i]->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pFactories[i]);
		FreeSpew(thisa->m_pFactories, "x:\\prj\\tech\\libsrc\\namedres\\resmanhs.cpp", 319);
		thisa->m_pFactories = 0;
		thisa->m_nNumFactories = 0;
	}
}

//----- (008E15FF) --------------------------------------------------------
void __thiscall cInstalledResTypeHash::cInstalledResTypeHash(cInstalledResTypeHash *this)
{
	cInstalledResTypeHash *v1; // ST04_4@1

	v1 = this;
	cStrIHashSet<cResTypeData__>::cStrIHashSet<cResTypeData__>(&this->baseclass_0, 0x65u);
	v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cInstalledResTypeHash::_vftable_;
}
// 9A81DC: using guessed type int (__stdcall *cInstalledResTypeHash___vftable_)(int __flags);

//----- (008E1620) --------------------------------------------------------
void __thiscall cInstalledResTypeHash::_cInstalledResTypeHash(cInstalledResTypeHash *this)
{
	cStrIHashSet<cResTypeData *> *v1; // ST00_4@1

	v1 = (cStrIHashSet<cResTypeData *> *)this;
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cInstalledResTypeHash::_vftable_;
	cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::DestroyAll(&this->baseclass_0.baseclass_0);
	cStrIHashSet<cResTypeData__>::_cStrIHashSet<cResTypeData__>(v1);
}
// 9A81DC: using guessed type int (__stdcall *cInstalledResTypeHash___vftable_)(int __flags);

//----- (008E1644) --------------------------------------------------------
tHashSetKey__ *__thiscall cInstalledResTypeHash::GetKey(cInstalledResTypeHash *this, tHashSetNode__ *node)
{
	return (tHashSetKey__ *)&node[2];
}

//----- (008E1657) --------------------------------------------------------
void __thiscall cNamedResType::cNamedResType(cNamedResType *this, IResType *pType)
{
	cNamedResType *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (!pType)
		_CriticalMsg("Creating a cNamedResType with a NULL type!", "x:\\prj\\tech\\libsrc\\namedres\\resmanhs.cpp", 0x156u);
	thisa->m_pType = pType;
	thisa->m_pType->baseclass_0.vfptr->AddRef((IUnknown *)thisa->m_pType);
}

//----- (008E16A1) --------------------------------------------------------
void __thiscall cNamedResType::_cNamedResType(cNamedResType *this)
{
	cNamedResType *v1; // ST04_4@1

	v1 = this;
	this->m_pType->baseclass_0.vfptr->Release((IUnknown *)this->m_pType);
	v1->m_pType = 0;
}


