//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>



//----- (008DBA80) --------------------------------------------------------
void __thiscall cResMan::cResMan(cResMan *this, IUnknown *pOuter)
{
	IUnknown *v2; // [sp+0h] [bp-78h]@12
	IUnknown *v3; // [sp+4h] [bp-74h]@9
	IUnknown *v4; // [sp+8h] [bp-70h]@6
	IUnknown *v5; // [sp+Ch] [bp-6Ch]@3
	cResMan *thisa; // [sp+10h] [bp-68h]@1
	sAggAddInfo aAggAddInfo[4]; // [sp+18h] [bp-60h]@2

	thisa = this;
	cCTDelegating<IResMan>::cCTDelegating<IResMan>(&this->baseclass_0);
	cCTDelegating<IResStats>::cCTDelegating<IResStats>(&thisa->baseclass_8);
	cCTDelegating<IResMem>::cCTDelegating<IResMem>(&thisa->baseclass_10);
	cCTDelegating<IResManHelper>::cCTDelegating<IResManHelper>(&thisa->baseclass_18);
	cCTAggregateMemberControl<0>::cCTAggregateMemberControl<0>(&thisa->baseclass_20);
	thisa->m_pStoreMan = 0;
	thisa->m_pDefSearchPath = 0;
	cInstalledResTypeHash::cInstalledResTypeHash(&thisa->m_ResTypeHash);
	cInstalledResTypeByName::cInstalledResTypeByName(&thisa->m_ResTypeByNameHash);
	cHashByResName::cHashByResName(&thisa->m_ResTable);
	thisa->m_pSharedCache = 0;
	thisa->m_pCache = 0;
	thisa->m_bPagingEnabled = 1;
	thisa->m_ppResFactories = 0;
	thisa->m_nResFactories = 0;
	thisa->m_FreshStamp = 1;
	thisa->m_pResStats = 0;
	thisa->m_fDidInit = 0;
	cDefResMem::cDefResMem(&thisa->m_DefResMem);
	thisa->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cResMan::_vftable_;
	thisa->baseclass_8.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cResMan::_vftable_;
	thisa->baseclass_10.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cResMan::_vftable_;
	thisa->baseclass_18.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cResMan::_vftable_;
	thisa->baseclass_20.baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cResMan::_vftable_;
	cCTDelegating<IResMan>::InitDelegation(&thisa->baseclass_0, pOuter);
	cCTDelegating<IResStats>::InitDelegation(&thisa->baseclass_8, pOuter);
	cCTDelegating<IResMem>::InitDelegation(&thisa->baseclass_10, pOuter);
	cCTDelegating<IResManHelper>::InitDelegation(&thisa->baseclass_18, pOuter);
	if (pOuter)
	{
		aAggAddInfo[0].pID = &IID_IResMan;
		aAggAddInfo[0].pszName = "IID_IResMan";
		aAggAddInfo[0].pAggregated = (IUnknown *)thisa;
		if (thisa)
			v5 = (IUnknown *)&thisa->baseclass_20;
		else
			v5 = 0;
		aAggAddInfo[0].pControl = v5;
		aAggAddInfo[0].controlPriority = 4096;
		aAggAddInfo[0].pControlConstraints = 0;
		aAggAddInfo[1].pID = &IID_IResStats;
		aAggAddInfo[1].pszName = "IID_IResStats";
		if (thisa)
			v4 = (IUnknown *)&thisa->baseclass_8;
		else
			v4 = 0;
		aAggAddInfo[1].pAggregated = v4;
		aAggAddInfo[1].pControl = 0;
		aAggAddInfo[1].controlPriority = 0;
		aAggAddInfo[1].pControlConstraints = 0;
		aAggAddInfo[2].pID = &IID_IResMem;
		aAggAddInfo[2].pszName = "IID_IResMem";
		if (thisa)
			v3 = (IUnknown *)&thisa->baseclass_10;
		else
			v3 = 0;
		aAggAddInfo[2].pAggregated = v3;
		aAggAddInfo[2].pControl = 0;
		aAggAddInfo[2].controlPriority = 0;
		aAggAddInfo[2].pControlConstraints = 0;
		aAggAddInfo[3].pID = &IID_IResManHelper;
		aAggAddInfo[3].pszName = "IID_IResManHelper";
		if (thisa)
			v2 = (IUnknown *)&thisa->baseclass_18;
		else
			v2 = 0;
		aAggAddInfo[3].pAggregated = v2;
		aAggAddInfo[3].pControl = 0;
		aAggAddInfo[3].controlPriority = 0;
		aAggAddInfo[3].pControlConstraints = 0;
		_AddToAggregate(pOuter, aAggAddInfo, 4u);
	}
	cCTAggregateMemberControl<0>::AggregateMemberControlRelease(&thisa->baseclass_20);
}
// 9A7C78: using guessed type int (__stdcall *cResMan___vftable_)(int, int, int);
// 9A7CA0: using guessed type int (__stdcall *cResMan___vftable_)(int this, int id, int ppI);
// 9A7CE8: using guessed type int (__stdcall *cResMan___vftable_)(int this, int id, int ppI);
// 9A7D00: using guessed type int (__stdcall *cResMan___vftable_)(int this, int id, int ppI);
// 9A7D1C: using guessed type int (__stdcall *cResMan___vftable_)(int this, int id, int ppI);

//----- (008DBDD0) --------------------------------------------------------
void __thiscall cResMan::_cResMan(cResMan *this)
{
	cCTDelegating<IResStats> *v1; // [sp+0h] [bp-14h]@11
	cCTDelegating<IResMem> *v2; // [sp+4h] [bp-10h]@8
	cCTDelegating<IResManHelper> *v3; // [sp+8h] [bp-Ch]@5
	cCTAggregateMemberControl<0> *v4; // [sp+Ch] [bp-8h]@2
	cResMan *thisa; // [sp+10h] [bp-4h]@1

	thisa = this;
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cResMan::_vftable_;
	this->baseclass_8.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cResMan::_vftable_;
	this->baseclass_10.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cResMan::_vftable_;
	this->baseclass_18.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cResMan::_vftable_;
	this->baseclass_20.baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cResMan::_vftable_;
	cHashByResName::_cHashByResName(&this->m_ResTable);
	cInstalledResTypeByName::_cInstalledResTypeByName(&thisa->m_ResTypeByNameHash);
	cInstalledResTypeHash::_cInstalledResTypeHash(&thisa->m_ResTypeHash);
	if (thisa)
		v4 = &thisa->baseclass_20;
	else
		v4 = 0;
	cCTAggregateMemberControl<0>::_cCTAggregateMemberControl<0>(v4);
	if (thisa)
		v3 = &thisa->baseclass_18;
	else
		v3 = 0;
	cCTDelegating<IResManHelper>::_cCTDelegating<IResManHelper>(v3);
	if (thisa)
		v2 = &thisa->baseclass_10;
	else
		v2 = 0;
	cCTDelegating<IResMem>::_cCTDelegating<IResMem>(v2);
	if (thisa)
		v1 = &thisa->baseclass_8;
	else
		v1 = 0;
	cCTDelegating<IResStats>::_cCTDelegating<IResStats>(v1);
	cCTDelegating<IResMan>::_cCTDelegating<IResMan>(&thisa->baseclass_0);
}
// 9A7C78: using guessed type int (__stdcall *cResMan___vftable_)(int, int, int);
// 9A7CA0: using guessed type int (__stdcall *cResMan___vftable_)(int this, int id, int ppI);
// 9A7CE8: using guessed type int (__stdcall *cResMan___vftable_)(int this, int id, int ppI);
// 9A7D00: using guessed type int (__stdcall *cResMan___vftable_)(int this, int id, int ppI);
// 9A7D1C: using guessed type int (__stdcall *cResMan___vftable_)(int this, int id, int ppI);

//----- (008DBEB7) --------------------------------------------------------
int __stdcall ResCacheCallback(sCacheMsg *pMsg)
{
	int result; // eax@3

	if (pMsg->message < 0 || pMsg->message > 1)
	{
		result = 1;
	}
	else
	{
		cResMan::FreeData((cResMan *)pMsg->pClientContext, (cResourceTypeData *)pMsg->itemId, 1);
		result = 0;
	}
	return result;
}

//----- (008DBEFC) --------------------------------------------------------
int __stdcall cResMan::Init(cResMan *this)
{
	int result; // eax@2
	IUnknown *v2; // eax@8
	IStoreFactory *v3; // ST1C_4@10
	unsigned int v4; // eax@11
	unsigned int v5; // [sp+0h] [bp-30h]@11
	IUnknown *v6; // [sp+4h] [bp-2Ch]@8
	void *v7; // [sp+8h] [bp-28h]@10
	void *v8; // [sp+Ch] [bp-24h]@7
	sCacheClientDesc CacheDesc; // [sp+14h] [bp-1Ch]@5
	IResType *pDefResType; // [sp+2Ch] [bp-4h]@7

	if (this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.m_ResizeThreshold)
	{
		result = 1;
	}
	else
	{
		this->m_ResTypeByNameHash.baseclass_0.baseclass_0.baseclass_0.m_nPts = (unsigned int)_AppGetAggregated(&IID_ISharedCache);
		if (!this->m_ResTypeByNameHash.baseclass_0.baseclass_0.baseclass_0.m_nPts)
			_CriticalMsg("cResMan: no shared cache is available!", "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x79u);
		CacheDesc.pID = &IID_IResMan;
		CacheDesc.pContext = (char *)this - 32;
		CacheDesc.pfnCallback = ResCacheCallback;
		CacheDesc.nMaxBytes = -1;
		CacheDesc.nMaxItems = -1;
		CacheDesc.flags = 0;
		(*(void(__stdcall **)(unsigned int, sCacheClientDesc *, unsigned int *))(*(_DWORD *)this->m_ResTypeByNameHash.baseclass_0.baseclass_0.baseclass_0.m_nPts
			+ 16))(
			this->m_ResTypeByNameHash.baseclass_0.baseclass_0.baseclass_0.m_nPts,
			&CacheDesc,
			&this->m_ResTypeByNameHash.baseclass_0.baseclass_0.baseclass_0.m_nItems);
		if (!this->m_ResTypeByNameHash.baseclass_0.baseclass_0.baseclass_0.m_nItems)
			_CriticalMsg("cResMan: couldn't get a resource cache!", "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x84u);
		pDefResType = MakeBinaryResourceType();
		(*(void(__stdcall **)(char *, IResType *))(*((_DWORD *)this - 8) + 52))((char *)this - 32, pDefResType);
		pDefResType->baseclass_0.vfptr->Release((IUnknown *)pDefResType);
		v8 = j__new(0x1Cu, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 139);
		if (v8)
		{
			cStorageManager::cStorageManager((cStorageManager *)v8);
			v6 = v2;
		}
		else
		{
			v6 = 0;
		}
		this->baseclass_8.__m_pOuterUnknown = v6;
		v3 = MakeZipStorageFactory();
		(*(void(__stdcall **)(char *, IStoreFactory *))(*((_DWORD *)this - 8) + 56))((char *)this - 32, v3);
		v3->baseclass_0.vfptr->Release((IUnknown *)v3);
		v7 = j__new(0x54u, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 147);
		if (v7)
		{
			cResStats::cResStats((cResStats *)v7);
			v5 = v4;
		}
		else
		{
			v5 = 0;
		}
		this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.m_nItems = v5;
		this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.m_ResizeThreshold = 1;
		cResManARQ::Init((cResManARQ *)&this->baseclass_8, (cResMan *)((char *)this - 32));
		result = 0;
	}
	return result;
}



//----- (008DC09D) --------------------------------------------------------
void __thiscall cResMan::CleanResources(cResMan *this)
{
	cResMan *thisa; // [sp+0h] [bp-2Ch]@1
	cResourceName *pNameData; // [sp+4h] [bp-28h]@1
	tHashSetHandle TypeHandle; // [sp+8h] [bp-24h]@6
	unsigned int refs; // [sp+14h] [bp-18h]@9
	cResourceData *pData; // [sp+18h] [bp-14h]@4
	tHashSetHandle NameHandle; // [sp+1Ch] [bp-10h]@1
	cResourceTypeData *pTypeData; // [sp+28h] [bp-4h]@6

	thisa = this;
	for (pNameData = cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::GetFirst(
		&this->m_ResTable.baseclass_0.baseclass_0,
		&NameHandle);
	pNameData;
	pNameData = cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::GetNext(
		&thisa->m_ResTable.baseclass_0.baseclass_0,
		&NameHandle))
	{
		if (!(pNameData->m_fFlags & 1))
		{
			for (pData = pNameData->m_pFirstStream; pData; pData = pData->m_pNext)
			{
				for (pTypeData = cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::GetFirst(
					&pData->m_ResourceTypeHash.baseclass_0.baseclass_0,
					&TypeHandle);
				pTypeData;
				pTypeData = cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::GetNext(
					&pData->m_ResourceTypeHash.baseclass_0.baseclass_0,
					&TypeHandle))
				{
					if (pTypeData->m_pRes)
					{
						refs = pTypeData->m_pRes->baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)pTypeData->m_pRes) - 1;
						pTypeData->m_pRes->baseclass_0.baseclass_0.vfptr->Release((IUnknown *)pTypeData->m_pRes);
					}
					else
					{
						refs = -1;
					}
					cResourceTypeData::GetName(pTypeData);
					DbgReportWarning("Leftover resource %s found at cleanup with lock count of %d, %d references.\n");
				}
			}
		}
	}
}

//----- (008DC19E) --------------------------------------------------------
int __stdcall cResMan::End(cResMan *this)
{
	int result; // eax@2
	cResStats *v2; // [sp+8h] [bp-8h]@8
	signed int i; // [sp+Ch] [bp-4h]@12

	if (this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.m_ResizeThreshold)
	{
		(*(void(__stdcall **)(_DWORD))(*(_DWORD *)this->m_ResTypeByNameHash.baseclass_0.baseclass_0.baseclass_0.m_nPts + 36))(this->m_ResTypeByNameHash.baseclass_0.baseclass_0.baseclass_0.m_nPts);
		if (this->m_ResTypeByNameHash.baseclass_0.baseclass_0.baseclass_0.m_nItems)
			(*(void(__stdcall **)(_DWORD))(*(_DWORD *)this->m_ResTypeByNameHash.baseclass_0.baseclass_0.baseclass_0.m_nItems
			+ 8))(this->m_ResTypeByNameHash.baseclass_0.baseclass_0.baseclass_0.m_nItems);
		this->m_ResTypeByNameHash.baseclass_0.baseclass_0.baseclass_0.m_nItems = 0;
		if (this->m_ResTypeByNameHash.baseclass_0.baseclass_0.baseclass_0.m_nPts)
			(*(void(__stdcall **)(_DWORD))(*(_DWORD *)this->m_ResTypeByNameHash.baseclass_0.baseclass_0.baseclass_0.m_nPts + 8))(this->m_ResTypeByNameHash.baseclass_0.baseclass_0.baseclass_0.m_nPts);
		this->m_ResTypeByNameHash.baseclass_0.baseclass_0.baseclass_0.m_nPts = 0;
		cResManARQ::Term((cResManARQ *)&this->baseclass_8);
		cResMan::CleanResources((cResMan *)((char *)this - 32));
		if (this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.m_nItems)
		{
			v2 = (cResStats *)this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.m_nItems;
			if (v2)
				cResStats::_scalar_deleting_destructor_(v2, 1u);
			this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.m_nItems = 0;
		}
		(*(void(__thiscall **)(_DWORD))(this->m_ResTypeHash.baseclass_0.baseclass_0.baseclass_0.m_nPts + 4))(&this->m_ResTypeHash.baseclass_0.baseclass_0.baseclass_0.m_nPts);
		((void(__thiscall *)(_DWORD))this->baseclass_18.__m_pOuterUnknown[1].vfptr)(&this->baseclass_18.__m_pOuterUnknown);
		((void(__thiscall *)(_DWORD))this->m_pDefSearchPath[1].baseclass_0.vfptr)(&this->m_pDefSearchPath);
		if (this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.vfptr)
		{
			for (i = 0; i < (signed int)this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.m_Table; ++i)
				(*(void(__stdcall **)(_DWORD))(**((_DWORD **)&this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.vfptr->__vecDelDtor
				+ i)
				+ 8))(*((_DWORD *)&this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.vfptr->__vecDelDtor
				+ i));
			FreeSpew(
				this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.vfptr,
				"x:\\prj\\tech\\libsrc\\namedres\\resman.cpp",
				243);
		}
		this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.vfptr = 0;
		this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.m_Table = 0;
		if (this->baseclass_10.baseclass_0.baseclass_0.vfptr)
			(*((void(__stdcall **)(_DWORD))this->baseclass_10.baseclass_0.baseclass_0.vfptr->QueryInterface + 2))(this->baseclass_10.baseclass_0.baseclass_0.vfptr);
		this->baseclass_10.baseclass_0.baseclass_0.vfptr = 0;
		this->baseclass_8.__m_pOuterUnknown->vfptr[3].AddRef(this->baseclass_8.__m_pOuterUnknown);
		if (this->baseclass_8.__m_pOuterUnknown)
			this->baseclass_8.__m_pOuterUnknown->vfptr->Release(this->baseclass_8.__m_pOuterUnknown);
		this->baseclass_8.__m_pOuterUnknown = 0;
		this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.m_ResizeThreshold = 0;
		result = 0;
	}
	else
	{
		result = -2147467259;
	}
	return result;
}

//----- (008DC375) --------------------------------------------------------
ISearchPath *__stdcall cResMan::NewSearchPath(cResMan *this, const char *pNewPath)
{
	return (ISearchPath *)((int(__stdcall *)(_DWORD, _DWORD))this->m_pStoreMan->baseclass_0.vfptr[3].QueryInterface)(
		this->m_pStoreMan,
		pNewPath);
}

//----- (008DC392) --------------------------------------------------------
void __stdcall cResMan::SetDefaultPath(cResMan *this, ISearchPath *pPath)
{
	int v2; // ecx@0
	int lock; // [sp+0h] [bp-4h]@1

	lock = v2;
	cAutoResThreadLock::cAutoResThreadLock((cAutoResThreadLock *)&lock);
	if (this->m_pDefSearchPath)
		this->m_pDefSearchPath->baseclass_0.vfptr->Release((IUnknown *)this->m_pDefSearchPath);
	this->m_pDefSearchPath = pPath;
	if (pPath)
		pPath->baseclass_0.vfptr->AddRef((IUnknown *)pPath);
	cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&lock);
}

//----- (008DC3E2) --------------------------------------------------------
void __stdcall cResMan::SetGlobalContext(cResMan *this, ISearchPath *pPath)
{
	((void(__stdcall *)(_DWORD, _DWORD))this->m_pStoreMan->baseclass_0.vfptr[2].AddRef)(this->m_pStoreMan, pPath);
}

//----- (008DC3FF) --------------------------------------------------------
void __stdcall cResMan::SetDefaultVariants(cResMan *this, ISearchPath *pPath)
{
	((void(__stdcall *)(_DWORD, _DWORD))this->m_pStoreMan->baseclass_0.vfptr[2].Release)(this->m_pStoreMan, pPath);
}

//----- (008DC41C) --------------------------------------------------------
void __cdecl ResTypeEnumerator(const char *pExt, IResType *pType, void *pClientData)
{
	cResMan::InstallResourceType((cResMan *)pClientData, pExt, pType);
}

//----- (008DC43A) --------------------------------------------------------
void __cdecl ResTypeRemover(const char *pExt, IResType *pType, void *pClientData)
{
	cResMan::RemoveResourceType((cResMan *)pClientData, pExt, pType);
}

//----- (008DC458) --------------------------------------------------------
int __stdcall cResMan::RegisterResType(cResMan *this, IResType *pType)
{
	int result; // eax@2
	const char *v3; // eax@6
	cNamedResType *v4; // eax@10
	cNamedResType *v5; // [sp+0h] [bp-24h]@10
	void *v6; // [sp+Ch] [bp-18h]@9
	cNamedResType *pTypeEntry; // [sp+1Ch] [bp-8h]@6
	cAutoResThreadLock lock; // [sp+20h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&lock);
	if (pType)
	{
		((void(__stdcall *)(IResType *, void(__cdecl *)(const char *, IResType *, void *), cResMan *))pType->baseclass_0.vfptr[1].AddRef)(
			pType,
			ResTypeEnumerator,
			this);
		if (this->m_ppResFactories)
		{
			++this->m_nResFactories;
			this->m_ppResFactories = (IResType **)ReallocSpew(
				this->m_ppResFactories,
				4 * this->m_nResFactories,
				"x:\\prj\\tech\\libsrc\\namedres\\resman.cpp",
				346);
			this->m_ppResFactories[this->m_nResFactories - 1] = pType;
		}
		else
		{
			this->m_ppResFactories = (IResType **)MallocSpew(4u, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 337);
			*this->m_ppResFactories = pType;
			this->m_nResFactories = 1;
		}
		pType->baseclass_0.vfptr->AddRef((IUnknown *)pType);
		v3 = (const char *)((int(__stdcall *)(IResType *))pType->baseclass_0.vfptr[1].QueryInterface)(pType);
		pTypeEntry = cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::Search(
			&this->m_ResTypeByNameHash.baseclass_0.baseclass_0,
			v3);
		if (pTypeEntry)
		{
			cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::Remove(
				&this->m_ResTypeByNameHash.baseclass_0.baseclass_0,
				pTypeEntry);
			if (pTypeEntry)
				cNamedResType::_scalar_deleting_destructor_(pTypeEntry, 1u);
		}
		v6 = j__new(4u, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 356);
		if (v6)
		{
			cNamedResType::cNamedResType((cNamedResType *)v6, pType);
			v5 = v4;
		}
		else
		{
			v5 = 0;
		}
		cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::Insert(
			&this->m_ResTypeByNameHash.baseclass_0.baseclass_0,
			v5);
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
		result = 1;
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
		result = 0;
	}
	return result;
}

//----- (008DC604) --------------------------------------------------------
int __stdcall cResMan::RegisterStoreFactory(cResMan *this, IStoreFactory *pStoreFactory)
{
	int result; // eax@3
	cAutoResThreadLock lock; // [sp+8h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&lock);
	if (pStoreFactory && this->m_pStoreMan)
	{
		((void(__stdcall *)(IStoreManager *, IStoreFactory *))this->m_pStoreMan->baseclass_0.vfptr[1].QueryInterface)(
			this->m_pStoreMan,
			pStoreFactory);
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
		result = 1;
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
		result = 0;
	}
	return result;
}

//----- (008DC663) --------------------------------------------------------
void __stdcall cResMan::UnregisterResType(cResMan *this, IResType *pType)
{
	const char *v2; // eax@13
	int i; // [sp+Ch] [bp-Ch]@4
	cNamedResType *pTypeEntry; // [sp+10h] [bp-8h]@13
	cAutoResThreadLock lock; // [sp+14h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&lock);
	if (pType)
	{
		((void(__stdcall *)(IResType *, void(__cdecl *)(const char *, IResType *, void *), cResMan *))pType->baseclass_0.vfptr[1].AddRef)(
			pType,
			ResTypeRemover,
			this);
		if (this->m_ppResFactories)
		{
			for (i = 0; i < this->m_nResFactories && this->m_ppResFactories[i] != pType; ++i)
				;
			if (i < this->m_nResFactories)
			{
				this->m_ppResFactories[i]->baseclass_0.vfptr->Release((IUnknown *)this->m_ppResFactories[i]);
				if (i < this->m_nResFactories - 1)
					memmove(&this->m_ppResFactories[i], &this->m_ppResFactories[i + 1], 4 * (this->m_nResFactories - (i + 1)));
				--this->m_nResFactories;
				if (!this->m_nResFactories)
				{
					FreeSpew(this->m_ppResFactories, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 411);
					this->m_ppResFactories = 0;
				}
			}
		}
		v2 = (const char *)((int(__stdcall *)(IResType *))pType->baseclass_0.vfptr[1].QueryInterface)(pType);
		pTypeEntry = cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::Search(
			&this->m_ResTypeByNameHash.baseclass_0.baseclass_0,
			v2);
		if (pTypeEntry && pTypeEntry->m_pType == pType)
		{
			cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::Remove(
				&this->m_ResTypeByNameHash.baseclass_0.baseclass_0,
				pTypeEntry);
			if (pTypeEntry)
				cNamedResType::_scalar_deleting_destructor_(pTypeEntry, 1u);
		}
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
	}
}

//----- (008DC820) --------------------------------------------------------
IStore *__stdcall cResMan::GetStore(cResMan *this, const char *pPathName)
{
	IStore *result; // eax@2
	IStore *v3; // ST0C_4@3
	cAutoResThreadLock lock; // [sp+8h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&lock);
	if (pPathName)
	{
		v3 = (IStore *)((int(__stdcall *)(IStoreManager *, const char *, _DWORD))this->m_pStoreMan->baseclass_0.vfptr[1].AddRef)(
			this->m_pStoreMan,
			pPathName,
			0);
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
		result = v3;
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
		result = 0;
	}
	return result;
}

//----- (008DC874) --------------------------------------------------------
void __stdcall cResMan::MarkForRefresh(cResMan *this, IRes *pRes)
{
	cResourceTypeData *pData; // [sp+0h] [bp-8h]@3
	cAutoResThreadLock lock; // [sp+4h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&lock);
	if (pRes)
	{
		pData = cResMan::GetResourceTypeData(this, pRes);
		if (pData)
			pData->m_Freshed = 0;
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
	}
}

//----- (008DC8BF) --------------------------------------------------------
void __stdcall cResMan::GlobalRefresh(cResMan *this)
{
	++this->m_FreshStamp;
}

//----- (008DC8DB) --------------------------------------------------------
void __cdecl TryNameWithExt(const char *pExt, IResType *__formal, void *pClientData)
{
	if (!*((_DWORD *)pClientData + 12))
	{
		strcpy((char *)pClientData + 12, *(const char **)pClientData);
		strcat((char *)pClientData + 12, pExt);
		*((_DWORD *)pClientData + 12) = (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(**((_DWORD **)pClientData + 2)
			+ 44))(
			*((_DWORD *)pClientData + 2),
			(char *)pClientData + 12,
			0,
			(char *)pClientData + 44,
			*((_DWORD *)pClientData + 1));
	}
}

//----- (008DC94B) --------------------------------------------------------
IRes *__thiscall cResMan::DoBind(cResMan *this, const char *pName, const char *pTypeName, ISearchPath *pPath, const char *pRelPath, const unsigned int fBindFlags)
{
	IRes *result; // eax@3
	const char *v7; // eax@16
	IRes *v8; // ST1C_4@23
	cResMan *thisa; // [sp+0h] [bp-8Ch]@1
	sFoundTypedStream Results; // [sp+14h] [bp-78h]@13
	char pFullname[32]; // [sp+48h] [bp-44h]@14
	int pRes; // [sp+68h] [bp-24h]@21
	IResType *pType; // [sp+6Ch] [bp-20h]@7
	cFileSpec fileSpec; // [sp+70h] [bp-1Ch]@12
	IStore *pCanonStore; // [sp+78h] [bp-14h]@14
	IStore *pStore; // [sp+7Ch] [bp-10h]@13
	cAnsiStr ResExt; // [sp+80h] [bp-Ch]@12

	thisa = this;
	if (!pName || !*pName)
	{
		DbgReportWarning("Can't Bind Resource with empty name!\n");
		return 0;
	}
	if (!pTypeName || !*pTypeName)
	{
		DbgReportWarning("Can't Bind Resource without a type!\n");
		return 0;
	}
	pType = cResMan::GetResType(this, pTypeName);
	if (!pType)
	{
		DbgReportWarning("Bind: unknown type specified!\n");
		return 0;
	}
	if (!pPath)
	{
		pPath = thisa->m_pDefSearchPath;
		if (!pPath)
		{
			DbgReportWarning("Bind: no path specified.\n");
			return 0;
		}
	}
	cAnsiStr::cAnsiStr(&ResExt);
	cFileSpec::cFileSpec(&fileSpec, pName);
	cFileSpec::GetFileExtension(&fileSpec, &ResExt);
	if (cAnsiStr::IsEmpty(&ResExt))
	{
		Results.pName = pName;
		Results.pPath = pPath;
		Results.pRelPath = pRelPath;
		Results.pFoundCanonStore = 0;
		Results.pStore = 0;
		((void(__stdcall *)(IResType *, void(__cdecl *)(const char *, IResType *, void *), sFoundTypedStream *))pType->baseclass_0.vfptr[1].AddRef)(
			pType,
			TryNameWithExt,
			&Results);
		pStore = Results.pStore;
		if (Results.pStore)
		{
			strcpy(pFullname, Results.pFoundName);
			pCanonStore = Results.pFoundCanonStore;
		}
	}
	else
	{
		v7 = cAnsiStr::operator char_const__(&ResExt);
		if (!((int(__stdcall *)(IResType *, const char *))pType->baseclass_0.vfptr[1].Release)(pType, v7))
		{
			cAnsiStr::operator char_const__(&ResExt);
			DbgReportWarning("Illegal extension %s given to bind type %s.\n");
			cFileSpec::_cFileSpec(&fileSpec);
			cAnsiStr::_cAnsiStr(&ResExt);
			return 0;
		}
		pStore = (IStore *)((int(__stdcall *)(ISearchPath *, const char *, _DWORD, IStore **, const char *))pPath->baseclass_0.vfptr[3].Release)(
			pPath,
			pName,
			0,
			&pCanonStore,
			pRelPath);
		strcpy(pFullname, pName);
	}
	if (pStore)
	{
		pRes = ((int(__stdcall *)(cResMan *, _DWORD, const char *, IStore *, IStore *, const unsigned int))thisa->baseclass_0.baseclass_0.baseclass_0.vfptr[3].QueryInterface)(
			thisa,
			pFullname,
			pTypeName,
			pStore,
			pCanonStore,
			fBindFlags);
		if (pCanonStore)
			pCanonStore->baseclass_0.vfptr->Release((IUnknown *)pCanonStore);
		pCanonStore = 0;
		pStore->baseclass_0.vfptr->Release((IUnknown *)pStore);
		v8 = (IRes *)pRes;
		cFileSpec::_cFileSpec(&fileSpec);
		cAnsiStr::_cAnsiStr(&ResExt);
		result = v8;
	}
	else
	{
		cFileSpec::_cFileSpec(&fileSpec);
		cAnsiStr::_cAnsiStr(&ResExt);
		result = 0;
	}
	return result;
}

//----- (008DCBA2) --------------------------------------------------------
IRes *__stdcall cResMan::Bind(cResMan *this, const char *pRelativePathname, const char *pTypeName, ISearchPath *pPath, const char *pExpRelPath, const unsigned int fBindFlags)
{
	const char *pRelPath; // [sp+0h] [bp-414h]@1
	char OldSlash; // [sp+4h] [bp-410h]@1
	IRes *pRes; // [sp+8h] [bp-40Ch]@1
	char temp[1024]; // [sp+Ch] [bp-408h]@1
	int bCombined; // [sp+40Ch] [bp-8h]@1
	const char *pName; // [sp+410h] [bp-4h]@1

	strncpy(temp, pRelativePathname, 0x3FFu);
	temp[1023] = 0;
	cResMan::MungePaths(this, temp, pExpRelPath, (char **)&pRelPath, (char **)&pName, &OldSlash, &bCombined);
	pRes = cResMan::DoBind(this, pName, pTypeName, pPath, pRelPath, fBindFlags);
	cResMan::RestorePath(this, (char *)pRelPath, (char *)pName, OldSlash, bCombined);
	return pRes;
}

//----- (008DCC3F) --------------------------------------------------------
void __stdcall cResMan::BindAll(cResMan *this, const char *pPattern, const char *pTypeName, ISearchPath *pPath, void(__cdecl *callback)(IRes *, IStore *, void *), void *pClientData, const char *pRelPath, const unsigned int fBindFlags)
{
	const char *v8; // eax@13
	cFileSpec fileSpec; // [sp+0h] [bp-48h]@13
	cAnsiStr ResExt; // [sp+8h] [bp-40h]@13
	IRes *pRes; // [sp+14h] [bp-34h]@16
	char pResName[32]; // [sp+18h] [bp-30h]@11
	void *pCookie; // [sp+38h] [bp-10h]@10
	IResType *pType; // [sp+3Ch] [bp-Ch]@8
	void *pCanonStore; // [sp+40h] [bp-8h]@11
	IStore *pStore; // [sp+44h] [bp-4h]@11

	if (callback)
	{
		if (!pPath)
		{
			pPath = this->m_pDefSearchPath;
			if (!pPath)
			{
				DbgReportWarning("BindAll called without a search path!\n");
				return;
			}
		}
		if (!pTypeName || !*pTypeName)
		{
			DbgReportWarning("Can't Bind Resource without a type!\n");
			return;
		}
		pType = 0;
		if (!pTypeName || (pType = cResMan::GetResType(this, pTypeName)) != 0)
		{
			pCookie = (void *)((int(__stdcall *)(ISearchPath *, const char *, _DWORD, const char *))pPath->baseclass_0.vfptr[4].QueryInterface)(
				pPath,
				pPattern,
				0,
				pRelPath);
			if (pCookie)
			{
				while (1)
				{
					while (1)
					{
						if (!((int(__stdcall *)(ISearchPath *, void *, IStore **, _DWORD, void **))pPath->baseclass_0.vfptr[4].AddRef)(
							pPath,
							pCookie,
							&pStore,
							pResName,
							&pCanonStore))
						{
							((void(__stdcall *)(ISearchPath *, void *))pPath->baseclass_0.vfptr[4].Release)(pPath, pCookie);
							return;
						}
						if (pType)
							break;
					LABEL_16:
						pRes = cResMan::GetResource(this, pResName, pTypeName, pStore);
						if (!pRes)
							pRes = (IRes *)((int(__stdcall *)(cResMan *, _DWORD, const char *, IStore *, void *, const unsigned int))this->baseclass_0.baseclass_0.baseclass_0.vfptr[3].QueryInterface)(
							this,
							pResName,
							pTypeName,
							pStore,
							pCanonStore,
							fBindFlags);
						if (pRes)
						{
							callback(pRes, pStore, pClientData);
							pRes->baseclass_0.baseclass_0.vfptr->Release((IUnknown *)pRes);
						}
						(*(void(__stdcall **)(void *))(*(_DWORD *)pCanonStore + 8))(pCanonStore);
						pStore->baseclass_0.vfptr->Release((IUnknown *)pStore);
					}
					cAnsiStr::cAnsiStr(&ResExt);
					cFileSpec::cFileSpec(&fileSpec, pResName);
					cFileSpec::GetFileExtension(&fileSpec, &ResExt);
					v8 = cAnsiStr::operator char_const__(&ResExt);
					if (((int(__stdcall *)(IResType *, const char *))pType->baseclass_0.vfptr[1].Release)(pType, v8))
					{
						cFileSpec::_cFileSpec(&fileSpec);
						cAnsiStr::_cAnsiStr(&ResExt);
						goto LABEL_16;
					}
					(*(void(__stdcall **)(void *))(*(_DWORD *)pCanonStore + 8))(pCanonStore);
					pStore->baseclass_0.vfptr->Release((IUnknown *)pStore);
					cFileSpec::_cFileSpec(&fileSpec);
					cAnsiStr::_cAnsiStr(&ResExt);
				}
			}
		}
	}
}

//----- (008DCE1B) --------------------------------------------------------
IRes *__stdcall cResMan::BindSpecific(cResMan *this, const char *pName, const char *pTypeName, IStore *pStore, IStore *pCanonStore, const unsigned int fBindFlags)
{
	const char *v7; // eax@12
	IRes *v8; // ST14_4@17
	void *pResControl; // [sp+10h] [bp-20h]@13
	cFileSpec fileSpec; // [sp+14h] [bp-1Ch]@12
	cAnsiStr ResExt; // [sp+1Ch] [bp-14h]@12
	IRes *pResource; // [sp+28h] [bp-8h]@7
	cAutoResThreadLock lock; // [sp+2Ch] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&lock);
	if (!pTypeName || !*pTypeName || !pName || !*pName || !pStore)
		_CriticalMsg("Missing arguments for BindSpecific!", "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x2DFu);
	pResource = 0;
	if (cResMan::VerifyStorage(this, pStore))
	{
		pResource = cResMan::GetResource(this, pName, pTypeName, pStore);
		if (pResource)
		{
			cAutoResThreadLock::_cAutoResThreadLock(&lock);
			return pResource;
		}
		if (!((int(__stdcall *)(IStore *, const char *))pStore->baseclass_0.vfptr[3].Release)(pStore, pName))
		{
			cAutoResThreadLock::_cAutoResThreadLock(&lock);
			return 0;
		}
		cAnsiStr::cAnsiStr(&ResExt);
		cFileSpec::cFileSpec(&fileSpec, pName);
		cFileSpec::GetFileExtension(&fileSpec, &ResExt);
		v7 = cAnsiStr::operator char_const__(&ResExt);
		pResource = cResMan::CreateResource(this, pStore, pName, v7, pTypeName, fBindFlags);
		if (pResource)
		{
			if (pResource->baseclass_0.baseclass_0.vfptr->QueryInterface(
				(IUnknown *)pResource,
				&IID_IResControl,
				&pResControl) < 0)
			{
				_CriticalMsg("BindSpecific: resource lacks IResControl!", "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x302u);
				pResource->baseclass_0.baseclass_0.vfptr->Release((IUnknown *)pResource);
				cFileSpec::_cFileSpec(&fileSpec);
				cAnsiStr::_cAnsiStr(&ResExt);
				cAutoResThreadLock::_cAutoResThreadLock(&lock);
				return 0;
			}
			(*(void(__stdcall **)(void *, _DWORD))(*(_DWORD *)pResControl + 20))(pResControl, (fBindFlags & 1) == 0);
			(*(void(__stdcall **)(void *, IStore *))(*(_DWORD *)pResControl + 24))(pResControl, pCanonStore);
			(*(void(__stdcall **)(void *))(*(_DWORD *)pResControl + 8))(pResControl);
		}
		cResStats::LogStatRes(this->m_pResStats, pResource, kResStat_ResourceBindings);
		cFileSpec::_cFileSpec(&fileSpec);
		cAnsiStr::_cAnsiStr(&ResExt);
	}
	v8 = pResource;
	cAutoResThreadLock::_cAutoResThreadLock(&lock);
	return v8;
}

//----- (008DCFFD) --------------------------------------------------------
IRes *__stdcall cResMan::Retype(cResMan *this, IRes *pOldRes, const char *pTypeName, const unsigned int fBindFlags)
{
	IRes *result; // eax@3
	IRes *v5; // ST18_4@8
	void *pStreamName; // [sp+4h] [bp-Ch]@6
	void *pCanonStore; // [sp+8h] [bp-8h]@8
	void *pStore; // [sp+Ch] [bp-4h]@4

	if (pOldRes && pTypeName)
	{
		pStore = (void *)((int(__stdcall *)(IRes *))pOldRes->baseclass_0.baseclass_0.vfptr[4].QueryInterface)(pOldRes);
		if (!pStore)
			_CriticalMsg("Resource without a storage!", "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x31Au);
		((void(__stdcall *)(IRes *, _DWORD, void **))pOldRes->baseclass_0.baseclass_0.vfptr[4].AddRef)(
			pOldRes,
			0,
			&pStreamName);
		if (pStreamName)
		{
			pCanonStore = 0;
			pCanonStore = (void *)pOldRes->baseclass_0.baseclass_0.vfptr[3].AddRef((IUnknown *)pOldRes);
			v5 = (IRes *)((int(__stdcall *)(cResMan *, void *, const char *, void *, void *, const unsigned int))this->baseclass_0.baseclass_0.baseclass_0.vfptr[3].QueryInterface)(
				this,
				pStreamName,
				pTypeName,
				pStore,
				pCanonStore,
				fBindFlags);
			(*(void(__stdcall **)(void *))(*(_DWORD *)pCanonStore + 8))(pCanonStore);
			FreeSpew(pStreamName, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 814);
			(*(void(__stdcall **)(void *))(*(_DWORD *)pStore + 8))(pStore);
			result = v5;
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

//----- (008DD0D3) --------------------------------------------------------
IRes *__thiscall cResMan::WalkNameChain(cResMan *this, cResourceData *pData, const char *__formal, const char *pTypeName, const char *pCanonPath)
{
	void *pResCanonPath; // [sp+4h] [bp-8h]@6
	cResourceTypeData *pTypeData; // [sp+8h] [bp-4h]@4

	if (!pTypeName)
		_CriticalMsg("No type given to WalkNameChain!", "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x342u);
	while (pData)
	{
		pTypeData = cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::Search(
			&pData->m_ResourceTypeHash.baseclass_0.baseclass_0,
			pTypeName);
		if (pTypeData)
		{
			if (!pCanonPath)
			{
				pTypeData->m_pRes->baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)pTypeData->m_pRes);
				return pTypeData->m_pRes;
			}
			((void(__stdcall *)(IRes *, void **))pTypeData->m_pRes->baseclass_0.baseclass_0.vfptr[2].Release)(
				pTypeData->m_pRes,
				&pResCanonPath);
			if (!_strcmpi(pCanonPath, (const char *)pResCanonPath))
			{
				pTypeData->m_pRes->baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)pTypeData->m_pRes);
				FreeSpew(pResCanonPath, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 847);
				return pTypeData->m_pRes;
			}
			FreeSpew(pResCanonPath, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 850);
		}
		pData = pData->m_pNext;
	}
	return 0;
}

//----- (008DD1CC) --------------------------------------------------------
IRes *__thiscall cResMan::DoLookup(cResMan *this, const char *pName, const char *pTypeName, const char *pRawCanonPath)
{
	IRes *result; // eax@3
	char **v5; // eax@14
	char *v6; // ST0C_4@20
	cResMan *thisa; // [sp+0h] [bp-18h]@1
	cResourceData *pData; // [sp+4h] [bp-14h]@14
	int i; // [sp+8h] [bp-10h]@12
	cResourceName *pNameData; // [sp+Ch] [bp-Ch]@7
	IRes *pRes; // [sp+10h] [bp-8h]@15
	IRes *pResa; // [sp+10h] [bp-8h]@25
	const char *pCanonPath; // [sp+14h] [bp-4h]@9

	thisa = this;
	if (pTypeName && *pTypeName)
	{
		if (pName && *pName)
		{
			pNameData = cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::Search(
				&this->m_ResTable.baseclass_0.baseclass_0,
				pName);
			if (pNameData)
			{
				pCanonPath = 0;
				if (pRawCanonPath)
					GetNormalizedPath(pRawCanonPath, (char **)&pCanonPath);
				if (pNameData->m_fFlags & 1)
				{
					for (i = 0;
						i < cDABase<char___4_cDARawSrvFns<char__>>::Size(&pNameData->m_ppFullNames->baseclass_0.baseclass_0);
						++i)
					{
						v5 = cDABase<char___4_cDARawSrvFns<char__>>::operator__(
							&pNameData->m_ppFullNames->baseclass_0.baseclass_0,
							i);
						pData = cHashByResName::FindResData(&thisa->m_ResTable, *v5, 0, 0);
						if (pData)
						{
							pRes = cResMan::WalkNameChain(thisa, pData, pName, pTypeName, pCanonPath);
							if (pRes)
							{
								if (pCanonPath)
									FreeSpew((void *)pCanonPath, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 924);
								return pRes;
							}
						}
						else
						{
							v6 = *cDABase<char___4_cDARawSrvFns<char__>>::operator__(
								&pNameData->m_ppFullNames->baseclass_0.baseclass_0,
								i);
							DbgReportWarning("Lookup: odd -- no entry found for %s.\n");
						}
					}
					if (pCanonPath)
						FreeSpew((void *)pCanonPath, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 936);
					result = 0;
				}
				else
				{
					pResa = cResMan::WalkNameChain(thisa, pNameData->m_pFirstStream, pName, pTypeName, pCanonPath);
					if (pCanonPath)
						FreeSpew((void *)pCanonPath, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 948);
					result = pResa;
				}
			}
			else
			{
				result = 0;
			}
		}
		else
		{
			DbgReportWarning("Lookup called with empty name.\n");
			result = 0;
		}
	}
	else
	{
		DbgReportWarning("Can't Lookup Resource without a type!\n");
		result = 0;
	}
	return result;
}

//----- (008DD38F) --------------------------------------------------------
IRes *__stdcall cResMan::Lookup(cResMan *this, const char *pRelativePathname, const char *pTypeName, const char *pCanonPath)
{
	const char *pRelPath; // [sp+0h] [bp-414h]@1
	char OldSlash; // [sp+4h] [bp-410h]@1
	int bComb; // [sp+8h] [bp-40Ch]@1
	IRes *pRes; // [sp+Ch] [bp-408h]@1
	char temp[1024]; // [sp+10h] [bp-404h]@1
	const char *pName; // [sp+410h] [bp-4h]@1

	strncpy(temp, pRelativePathname, 0x3FFu);
	temp[1023] = 0;
	cResMan::MungePaths(this, temp, pCanonPath, (char **)&pRelPath, (char **)&pName, &OldSlash, &bComb);
	pRes = cResMan::DoLookup(this, pName, pTypeName, pRelPath);
	cResMan::RestorePath(this, (char *)pRelPath, (char *)pName, OldSlash, bComb);
	return pRes;
}

//----- (008DD42A) --------------------------------------------------------
void __stdcall cResMan::UnregisterResource(cResMan *this, IRes *pResource, unsigned int ManData)
{
	cAutoResThreadLock lock; // [sp+10h] [bp-8h]@1
	cResourceTypeData *pTypeData; // [sp+14h] [bp-4h]@5

	cAutoResThreadLock::cAutoResThreadLock(&lock);
	if (pResource && ManData && ManData != -1)
	{
		pTypeData = (cResourceTypeData *)ManData;
		cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::Remove(
			(cHashSet<cResourceTypeData *, char const *, cCaselessStringHashFuncs> *)(*(_DWORD *)(ManData + 28) + 8),
			(cResourceTypeData *)ManData);
		if (pTypeData)
			cResourceTypeData::_scalar_deleting_destructor_(pTypeData, 1u);
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
	}
	else
	{
		DbgReportWarning("UnregisterResource called for a bogus resource!\n");
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
	}
}

//----- (008DD4B5) --------------------------------------------------------
void __thiscall cResMan::CacheAdd(cResMan *this, cResourceTypeData *pData)
{
	if (this->m_bPagingEnabled)
		((void(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->m_pCache->baseclass_0.vfptr[1].AddRef)(
		this->m_pCache,
		pData,
		pData->m_pRes,
		pData->m_nSize);
}

//----- (008DD4F2) --------------------------------------------------------
int __thiscall cResMan::CacheRemove(cResMan *this, cResourceTypeData *pData)
{
	int result; // eax@2
	void *pDummy; // [sp+4h] [bp-4h]@3

	if (this->m_bPagingEnabled)
	{
		if (this->m_pCache->baseclass_0.vfptr[2].QueryInterface((IUnknown *)this->m_pCache, (_GUID *)pData, &pDummy))
		{
			cResourceTypeData::GetName(pData);
			DbgReportWarning("Tried to remove an item expected but not in the cache (%s)\n");
			result = 0;
		}
		else
		{
			result = 1;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008DD54E) --------------------------------------------------------
void *__thiscall cResMan::DoLockResource(cResMan *this, IRes *pResource, cResourceTypeData *pData)
{
	const char *v3; // eax@6
	const char *v5; // eax@8
	const char *v6; // eax@36
	const char *v7; // eax@40
	cResMan *thisa; // [sp+0h] [bp-30h]@1
	int bSuccess; // [sp+4h] [bp-2Ch]@39
	IResMemOverride *pResMem; // [sp+8h] [bp-28h]@20
	int bDidAllocate; // [sp+Ch] [bp-24h]@24
	void *pNewData; // [sp+10h] [bp-20h]@19
	unsigned int nNewSize; // [sp+14h] [bp-1Ch]@19
	cResourceTypeData *pFoundData; // [sp+18h] [bp-18h]@13
	int i; // [sp+1Ch] [bp-14h]@10
	const char **ppProxiedTypes; // [sp+20h] [bp-10h]@5
	void *pResControl; // [sp+24h] [bp-Ch]@5
	int nNumTypes; // [sp+28h] [bp-8h]@5
	int bProxied; // [sp+2Ch] [bp-4h]@5

	thisa = this;
	cResManARQ::ClearPreload(&this->m_ResManARQ, pData);
	++pData->m_nUserLockCount;
	if (pData->m_nUserLockCount == 1)
	{
		if (pData->m_Freshed < thisa->m_FreshStamp)
		{
			cResourceTypeData::GetName(pData);
			DbgReportWarning("Refresh requested for %s; NYI...\n");
			pData->m_Freshed = thisa->m_FreshStamp;
		}
		if (pData->m_nInternalLockCount)
		{
			bSuccess = cResMan::CacheRemove(thisa, pData);
			if (!bSuccess)
			{
				cResourceTypeData::GetName(pData);
				v7 = _LogFmt("Res tried to take %s back from cache, it wasnt there?");
				_CriticalMsg(v7, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x56Bu);
			}
			pData->m_nInternalLockCount = 0;
			if (bSuccess)
			{
				cResStats::LogStatRes(thisa->m_pResStats, pResource, kResStat_NewLoadLRU);
			}
			else
			{
				cResStats::LogStatRes(thisa->m_pResStats, pResource, kResStat_LoadFailed);
				cResStats::LogStatRes(thisa->m_pResStats, pResource, kResStat_LockFailed);
			}
		}
		else
		{
			ppProxiedTypes = 0;
			nNumTypes = 0;
			bProxied = 0;
			if (pResource->baseclass_0.baseclass_0.vfptr->QueryInterface(
				(IUnknown *)pResource,
				&IID_IResControl,
				&pResControl) < 0)
			{
				pResource->baseclass_0.baseclass_0.vfptr[2].AddRef((IUnknown *)pResource);
				v3 = _LogFmt("No IResControl for resource %s!");
				_CriticalMsg(v3, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x4F7u);
				return 0;
			}
			if (pData->m_pData)
			{
				pResource->baseclass_0.baseclass_0.vfptr[2].AddRef((IUnknown *)pResource);
				v5 = _LogFmt("Unexpectedly overwriting data for %s");
				_CriticalMsg(v5, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x4FDu);
			}
			ppProxiedTypes = (const char **)(*(int(__stdcall **)(void *, int *))(*(_DWORD *)pResControl + 40))(
				pResControl,
				&nNumTypes);
			if (nNumTypes)
			{
				i = 0;
				while (!bProxied && i < nNumTypes)
				{
					pFoundData = cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::Search(
						&pData->m_pResourceData->m_ResourceTypeHash.baseclass_0.baseclass_0,
						ppProxiedTypes[i]);
					if (pFoundData && pFoundData->m_pData)
						bProxied = 1;
					else
						++i;
				}
				if (bProxied)
				{
					pNewData = 0;
					nNewSize = 0;
					if (pData->m_pResMem)
						pResMem = pData->m_pResMem;
					else
						pResMem = (IResMemOverride *)&thisa->m_DefResMem;
					if (g_fResPrintAccesses)
					{
						cResourceTypeData::GetName(pData);
						mprintf("cResMan::DoLockResource(): Loading resource %s (proxied)\n");
					}
					pNewData = (void *)(*(int(__stdcall **)(void *, void *, unsigned int, const char *, int *, unsigned int *, IResMemOverride *))(*(_DWORD *)pResControl + 44))(
						pResControl,
						pFoundData->m_pData,
						pFoundData->m_nSize,
						ppProxiedTypes[i],
						&bDidAllocate,
						&nNewSize,
						pResMem);
					if (pNewData)
					{
						pData->m_pData = pNewData;
						pData->m_nSize = nNewSize;
						if (!bDidAllocate)
						{
							pData->m_pProxiedRes = pFoundData;
							cResMan::DoLockResource(thisa, pResource, pFoundData);
						}
						cResStats::LogStatRes(thisa->m_pResStats, pResource, kResStat_ProxiedLoad);
					}
					else
					{
						DbgReportWarning("Proxy load failed. Attempting fresh load.\n");
						bProxied = 0;
					}
				}
			}
			if (!bProxied)
			{
				if (g_fResPrintAccesses)
				{
					cResourceTypeData::GetName(pData);
					mprintf("cResMan::DoLockResource(): Loading resource %s\n");
				}
				if (pData->m_pResMem)
					pData->m_pData = (void *)(*(int(__stdcall **)(void *, unsigned int *, _DWORD, IResMemOverride *))(*(_DWORD *)pResControl + 28))(
					pResControl,
					&pData->m_nSize,
					0,
					pData->m_pResMem);
				else
					pData->m_pData = (void *)(*(int(__stdcall **)(void *, unsigned int *, _DWORD, cDefResMem *))(*(_DWORD *)pResControl + 28))(
					pResControl,
					&pData->m_nSize,
					0,
					&thisa->m_DefResMem);
				if (!pData->m_pData)
				{
					cResourceTypeData::GetName(pData);
					v6 = _LogFmt("Failed to load resource data %s");
					_CriticalMsg(v6, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x558u);
				}
				cResStats::LogStatRes(thisa->m_pResStats, pResource, kResStat_NewLoad);
				cResStats::LogStatRes(thisa->m_pResStats, pResource, kResStat_MemAlloced);
				pResource->baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)pResource);
			}
			(*(void(__stdcall **)(void *))(*(_DWORD *)pResControl + 8))(pResControl);
		}
	}
	else
	{
		cResStats::LogStatRes(thisa->m_pResStats, pResource, kResStat_AlreadyLoaded);
	}
	return pData->m_pData;
}
// EAC7C0: using guessed type int g_fResPrintAccesses;

//----- (008DD959) --------------------------------------------------------
void *__stdcall cResMan::LockResource(cResMan *this, IRes *pResource)
{
	void *result; // eax@2
	void *v3; // ST0C_4@7
	cResourceTypeData *pData; // [sp+Ch] [bp-8h]@3
	cAutoResThreadLock lock; // [sp+10h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&lock);
	cResStats::LogStatRes((cResStats *)this->m_pSharedCache, pResource, 0);
	if (pResource)
	{
		pData = cResMan::GetResourceTypeData((cResMan *)((char *)this - 24), pResource);
		if (pData)
		{
			if (!cResMan::DoLockResource((cResMan *)((char *)this - 24), pResource, pData))
				_CriticalMsg(
				"Resource Lock failed -- unable to lock data.",
				"x:\\prj\\tech\\libsrc\\namedres\\resman.cpp",
				0x591u);
			v3 = pData->m_pData;
			cAutoResThreadLock::_cAutoResThreadLock(&lock);
			result = v3;
		}
		else
		{
			_CriticalMsg("Resource Lock failed. No private data", "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x58Cu);
			cAutoResThreadLock::_cAutoResThreadLock(&lock);
			result = 0;
		}
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
		result = 0;
	}
	return result;
}

//----- (008DDA16) --------------------------------------------------------
void *__stdcall cResMan::ExtractResource(cResMan *this, IRes *pRes, void *pBuf)
{
	void *result; // eax@3
	const char *v4; // eax@7
	int pStream; // [sp+10h] [bp-10h]@6
	void *pResControl; // [sp+14h] [bp-Ch]@4
	cAutoResThreadLock lock; // [sp+18h] [bp-8h]@1
	int nSize; // [sp+1Ch] [bp-4h]@10

	cAutoResThreadLock::cAutoResThreadLock(&lock);
	if (pRes && pBuf)
	{
		if (pRes->baseclass_0.baseclass_0.vfptr->QueryInterface((IUnknown *)pRes, &IID_IResControl, &pResControl) >= 0)
		{
			pStream = (*(int(__stdcall **)(void *))(*(_DWORD *)pResControl + 36))(pResControl);
			if (!pStream)
			{
				pRes->baseclass_0.baseclass_0.vfptr[2].AddRef((IUnknown *)pRes);
				v4 = _LogFmt("Unable to open stream: %s");
				_CriticalMsg(v4, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x5AFu);
			}
			(*(void(__stdcall **)(void *))(*(_DWORD *)pResControl + 8))(pResControl);
			if (pStream)
			{
				nSize = (*(int(__stdcall **)(int))(*(_DWORD *)pStream + 40))(pStream);
				(*(void(__stdcall **)(int, int, void *))(*(_DWORD *)pStream + 44))(pStream, nSize, pBuf);
				(*(void(__stdcall **)(int))(*(_DWORD *)pStream + 20))(pStream);
				(*(void(__stdcall **)(int))(*(_DWORD *)pStream + 8))(pStream);
				cAutoResThreadLock::_cAutoResThreadLock(&lock);
				result = pBuf;
			}
			else
			{
				cAutoResThreadLock::_cAutoResThreadLock(&lock);
				result = 0;
			}
		}
		else
		{
			_CriticalMsg("Resource without an IResControl!", "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x5A9u);
			cAutoResThreadLock::_cAutoResThreadLock(&lock);
			result = 0;
		}
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
		result = 0;
	}
	return result;
}

//----- (008DDB49) --------------------------------------------------------
void *__stdcall cResMan::FindResource(cResMan *this, IRes *pResource, int *pSize)
{
	void *result; // eax@8
	void *v4; // ST0C_4@17
	cResourceTypeData *pData; // [sp+Ch] [bp-8h]@3
	cAutoResThreadLock lock; // [sp+10h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&lock);
	if (pSize)
		*pSize = 0;
	pData = cResMan::GetResourceTypeData((cResMan *)((char *)this - 24), pResource);
	if (!pData)
		_CriticalMsg("FindResource -- no private resource data!", "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x5CAu);
	if ((pData->m_nUserLockCount || pData->m_nInternalLockCount)
		&& pData->m_Freshed >= (signed int)this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.m_ResizeThreshold)
	{
		if (pSize)
			*pSize = pData->m_nSize;
		if (!pData->m_nUserLockCount && pData->m_nInternalLockCount)
		{
			if (pData->m_pResMem)
				((void(__stdcall *)(IResMemOverride *, void *))pData->m_pResMem->baseclass_0.vfptr[1].Release)(
				pData->m_pResMem,
				pData->m_pData);
			else
				f_msize(pData->m_pData);
			(*(void(__stdcall **)(cHashSetBaseVtbl *, cResourceTypeData *))((void(__stdcall **)(_DWORD, _DWORD))this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.vfptr->__vecDelDtor
				+ 7))(
				this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.vfptr,
				pData);
		}
		v4 = pData->m_pData;
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
		result = v4;
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
		result = 0;
	}
	return result;
}
// B1950C: using guessed type int (__cdecl *f_msize)(_DWORD);

//----- (008DDC5B) --------------------------------------------------------
void __thiscall cResMan::DoUnlockResource(cResMan *this, cResourceTypeData *pData)
{
	const char *v2; // eax@2
	const char *v3; // eax@8
	cResMan *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (!pData->m_nUserLockCount)
	{
		cResourceTypeData::GetName(pData);
		v2 = _LogFmt("Lock count 0 during Unlock of %s");
		_CriticalMsg(v2, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x5EBu);
	}
	if (pData->m_nUserLockCount)
	{
		--pData->m_nUserLockCount;
		if (!pData->m_nUserLockCount)
		{
			if (pData->m_pProxiedRes)
			{
				cResMan::DoUnlockResource(thisa, pData->m_pProxiedRes);
				pData->m_pData = 0;
				pData->m_nSize = 0;
				pData->m_pProxiedRes = 0;
			}
			else
			{
				if (pData->m_nInternalLockCount)
				{
					cResourceTypeData::GetName(pData);
					v3 = _LogFmt("Internal Lock Count non-zero during Unlock of %s");
					_CriticalMsg(v3, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x604u);
				}
				if (!pData->m_nInternalLockCount)
				{
					pData->m_nInternalLockCount = 1;
					cResMan::CacheAdd(thisa, pData);
				}
			}
		}
	}
}

//----- (008DDD58) --------------------------------------------------------
void __stdcall cResMan::UnlockResource(cResMan *this, IRes *pResource)
{
	cResourceTypeData *pData; // [sp+0h] [bp-8h]@1
	cAutoResThreadLock lock; // [sp+4h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&lock);
	pData = cResMan::GetResourceTypeData((cResMan *)((char *)this - 24), pResource);
	if (pData)
	{
		cResMan::DoUnlockResource((cResMan *)((char *)this - 24), pData);
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
	}
	else
	{
		_CriticalMsg("Unable to unlock resource", "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x61Bu);
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
	}
}

//----- (008DDDB9) --------------------------------------------------------
unsigned int __stdcall cResMan::GetResourceLockCount(cResMan *this, IRes *pResource)
{
	unsigned int result; // eax@2
	unsigned int v3; // ST0C_4@3
	cResourceTypeData *pData; // [sp+8h] [bp-8h]@1
	cAutoResThreadLock lock; // [sp+Ch] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&lock);
	pData = cResMan::GetResourceTypeData((cResMan *)((char *)this - 24), pResource);
	if (pData)
	{
		v3 = pData->m_nUserLockCount;
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
		result = v3;
	}
	else
	{
		_CriticalMsg("Unable to get lock count", "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x62Eu);
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
		result = 0;
	}
	return result;
}

//----- (008DDE21) --------------------------------------------------------
int __thiscall cResMan::DropResourceData(cResMan *this, cResourceTypeData *pData)
{
	int result; // eax@2
	cResMan *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (pData->m_nUserLockCount)
	{
		result = 0;
	}
	else
	{
		if (pData->m_nInternalLockCount)
		{
			cResMan::CacheRemove(this, pData);
			cResMan::FreeData(thisa, pData, 0);
		}
		result = 1;
	}
	return result;
}

//----- (008DDE63) --------------------------------------------------------
int __stdcall cResMan::DropResource(cResMan *this, IRes *pResource)
{
	cResourceTypeData *v2; // ST08_4@1
	int v3; // ST04_4@1
	cAutoResThreadLock lock; // [sp+8h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&lock);
	v2 = cResMan::GetResourceTypeData((cResMan *)((char *)this - 24), pResource);
	v3 = cResMan::DropResourceData((cResMan *)((char *)this - 24), v2);
	cAutoResThreadLock::_cAutoResThreadLock(&lock);
	return v3;
}

//----- (008DDEA6) --------------------------------------------------------
int __stdcall cResMan::GetResourceSize(cResMan *this, IRes *pRes)
{
	int result; // eax@2
	int v3; // ST20_4@4
	const char *v4; // eax@10
	int v5; // ST14_4@13
	int pStream; // [sp+18h] [bp-14h]@9
	void *pResControl; // [sp+1Ch] [bp-10h]@7
	int nSize; // [sp+20h] [bp-Ch]@13
	cResourceTypeData *pData; // [sp+24h] [bp-8h]@3
	cAutoResThreadLock lock; // [sp+28h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&lock);
	if (pRes)
	{
		pData = cResMan::GetResourceTypeData((cResMan *)((char *)this - 24), pRes);
		if (pData->m_nSize)
		{
			v3 = pData->m_nSize;
			cAutoResThreadLock::_cAutoResThreadLock(&lock);
			result = v3;
		}
		else
		{
			if (pData->m_nUserLockCount || pData->m_nInternalLockCount)
			{
				cAutoResThreadLock::_cAutoResThreadLock(&lock);
				result = 0;
			}
			else
			{
				if (pRes->baseclass_0.baseclass_0.vfptr->QueryInterface((IUnknown *)pRes, &IID_IResControl, &pResControl) >= 0)
				{
					pStream = (*(int(__stdcall **)(void *))(*(_DWORD *)pResControl + 36))(pResControl);
					if (!pStream)
					{
						pRes->baseclass_0.baseclass_0.vfptr[2].AddRef((IUnknown *)pRes);
						v4 = _LogFmt("Unable to open stream: %s");
						_CriticalMsg(v4, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x67Eu);
					}
					(*(void(__stdcall **)(void *))(*(_DWORD *)pResControl + 8))(pResControl);
					if (pStream)
					{
						nSize = (*(int(__stdcall **)(int))(*(_DWORD *)pStream + 40))(pStream);
						(*(void(__stdcall **)(int))(*(_DWORD *)pStream + 20))(pStream);
						(*(void(__stdcall **)(int))(*(_DWORD *)pStream + 8))(pStream);
						v5 = nSize;
						cAutoResThreadLock::_cAutoResThreadLock(&lock);
						result = v5;
					}
					else
					{
						cAutoResThreadLock::_cAutoResThreadLock(&lock);
						result = 0;
					}
				}
				else
				{
					_CriticalMsg("Resource without an IResControl!", "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 0x678u);
					cAutoResThreadLock::_cAutoResThreadLock(&lock);
					result = 0;
				}
			}
		}
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&lock);
		result = 0;
	}
	return result;
}

//----- (008DE021) --------------------------------------------------------
int __stdcall cResMan::AsyncLock(cResMan *this, IRes *pResource, int nPriority)
{
	return cResManARQ::Lock((cResManARQ *)&this->baseclass_10, pResource, nPriority);
}

//----- (008DE03B) --------------------------------------------------------
int __stdcall cResMan::AsyncExtract(cResMan *this, IRes *pResource, int nPriority, void *pBuf, int bufSize)
{
	return cResManARQ::Extract((cResManARQ *)&this->baseclass_10, pResource, nPriority, pBuf, bufSize);
}

//----- (008DE05D) --------------------------------------------------------
int __stdcall cResMan::AsyncPreload(cResMan *this, IRes *pResource)
{
	return cResManARQ::Preload((cResManARQ *)&this->baseclass_10, pResource);
}

//----- (008DE073) --------------------------------------------------------
int __stdcall cResMan::IsAsyncFulfilled(cResMan *this, IRes *pResource)
{
	return cResManARQ::IsFulfilled((cResManARQ *)&this->baseclass_10, pResource);
}

//----- (008DE089) --------------------------------------------------------
int __stdcall cResMan::AsyncKill(cResMan *this, IRes *pResource)
{
	return cResManARQ::Kill((cResManARQ *)&this->baseclass_10, pResource);
}

//----- (008DE09F) --------------------------------------------------------
int __stdcall cResMan::GetAsyncResult(cResMan *this, IRes *pResource, void **ppResult)
{
	return cResManARQ::GetResult((cResManARQ *)&this->baseclass_10, pResource, ppResult);
}

//----- (008DE0B9) --------------------------------------------------------
void __stdcall cResMan::EnablePaging(cResMan *this, int bEnable)
{
	this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.m_nItems = bEnable;
}

//----- (008DE0C9) --------------------------------------------------------
void __stdcall cResMan::Compact(cResMan *this)
{
	((void(__stdcall *)(_DWORD, _DWORD))(*this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.m_Table)[4].node)(
		this->m_ResTable.baseclass_0.baseclass_0.baseclass_0.m_Table,
		&IID_IResMan);
}

//----- (008DE0E7) --------------------------------------------------------
void __stdcall cResMan::SetMode(cResMan *this, eResStatMode mode, int bTurnOn)
{
	cResStats::SetMode((cResStats *)this->m_nResFactories, mode, bTurnOn);
}

//----- (008DE104) --------------------------------------------------------
void __stdcall cResMan::Dump(cResMan *this, const char *pFile)
{
	cResStats::Dump((cResStats *)this->m_nResFactories, pFile);
}

//----- (008DE11D) --------------------------------------------------------
void __stdcall cResMan::DumpSnapshot(cResMan *this, const char *pFile)
{
	_iobuf *fp; // [sp+0h] [bp-4h]@1

	fp = 0;
	if (pFile)
		fp = fopen(pFile, "a+");
	cResMan::DoDumpSnapshot((cResMan *)((char *)this - 8), fp);
	if (fp)
		fclose(fp);
}

//----- (008DE169) --------------------------------------------------------
void __thiscall cResMan::DoDumpSnapshot(cResMan *this, _iobuf *fp)
{
	int v2; // ST1C_4@15
	int v3; // ST18_4@15
	int v4; // ST14_4@15
	unsigned int v5; // ST10_4@15
	int v6; // eax@15
	cResMan *thisa; // [sp+0h] [bp-58h]@1
	char padded_name[33]; // [sp+4h] [bp-54h]@11
	char i; // [sp+28h] [bp-30h]@11
	const char *pCanonPathName; // [sp+2Ch] [bp-2Ch]@11
	int refcnt; // [sp+30h] [bp-28h]@14
	cResourceTypeData *pResEntry; // [sp+34h] [bp-24h]@9
	tHashSetHandle h; // [sp+38h] [bp-20h]@9
	cResourceData *pResData; // [sp+44h] [bp-14h]@7
	cResourceName *pNameEntry; // [sp+48h] [bp-10h]@4
	tHashSetHandle nameHandle; // [sp+4Ch] [bp-Ch]@4

	thisa = this;
	if (fp)
	{
		fprintf(fp, "Current Resources in Use:\n");
		fprintf(fp, "Canonical Path                 Type\tSize\tExtLock\tIntLock\tRefCnt\n");
	}
	else
	{
		mprintf("Current Resources in Use:\n");
		mprintf("Canonical Path                 Type\tSize\tExtLock\tIntLock\tRefCnt\n");
	}
	for (pNameEntry = cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::GetFirst(
		&thisa->m_ResTable.baseclass_0.baseclass_0,
		&nameHandle);
	pNameEntry;
	pNameEntry = cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::GetNext(
		&thisa->m_ResTable.baseclass_0.baseclass_0,
		&nameHandle))
	{
		if (!(pNameEntry->m_fFlags & 1))
		{
			for (pResData = pNameEntry->m_pFirstStream; pResData; pResData = pResData->m_pNext)
			{
				for (pResEntry = cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::GetFirst(
					&pResData->m_ResourceTypeHash.baseclass_0.baseclass_0,
					&h);
				pResEntry;
				pResEntry = cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::GetNext(
					&pResData->m_ResourceTypeHash.baseclass_0.baseclass_0,
					&h))
				{
					((void(__stdcall *)(IRes *, const char **))pResEntry->m_pRes->baseclass_0.baseclass_0.vfptr[3].QueryInterface)(
						pResEntry->m_pRes,
						&pCanonPathName);
					strncpy(padded_name, pCanonPathName, 0x1Du);
					padded_name[29] = 0;
					for (i = strlen(padded_name); i < 30; ++i)
						padded_name[i] = 32;
					padded_name[i] = 0;
					refcnt = pResEntry->m_pRes->baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)pResEntry->m_pRes) - 1;
					pResEntry->m_pRes->baseclass_0.baseclass_0.vfptr->Release((IUnknown *)pResEntry->m_pRes);
					if (fp)
					{
						v2 = refcnt;
						v3 = pResEntry->m_nInternalLockCount;
						v4 = pResEntry->m_nUserLockCount;
						v5 = pResEntry->m_nSize;
						v6 = ((int(__stdcall *)(IResType *))pResEntry->m_pType->baseclass_0.vfptr[1].QueryInterface)(pResEntry->m_pType);
						fprintf(fp, "%s%s\t%ld\t%d\t%d\t%d\n", padded_name, v6, v5, v4, v3, v2);
					}
					else
					{
						((void(__stdcall *)(IResType *))pResEntry->m_pType->baseclass_0.vfptr[1].QueryInterface)(pResEntry->m_pType);
						mprintf("%s%s\t%ld\t%d\t%d\t%d\n");
					}
					FreeSpew((void *)pCanonPathName, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 1855);
				}
			}
		}
	}
}

//----- (008DE383) --------------------------------------------------------
int __stdcall _Res2Create(_GUID *__formal, IResMan **ppResMan, IUnknown *pOuter)
{
	IResMan *v3; // eax@2
	IResMan *v5; // [sp+0h] [bp-Ch]@2
	void *this; // [sp+4h] [bp-8h]@1

	this = j__new(0xA0u, "x:\\prj\\tech\\libsrc\\namedres\\resman.cpp", 1878);
	if (this)
	{
		cResMan::cResMan((cResMan *)this, pOuter);
		v5 = v3;
	}
	else
	{
		v5 = 0;
	}
	if (ppResMan)
		*ppResMan = v5;
	return v5 != 0 ? 0 : -2147467259;
}

//----- (008DE3F0) --------------------------------------------------------
void *__thiscall cResMan::_scalar_deleting_destructor_(cResMan *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cResMan::_cResMan(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}


//----- (008DF6B0) --------------------------------------------------------
void *__thiscall cResMan::_vector_deleting_destructor_(cResMan *this, unsigned int a2)
{
	return cResMan::_scalar_deleting_destructor_((cResMan *)((char *)this - 8), a2);
}

//----- (008DF6C0) --------------------------------------------------------
void *__thiscall cResMan::_vector_deleting_destructor_(cResMan *this, unsigned int a2)
{
	return cResMan::_scalar_deleting_destructor_((cResMan *)((char *)this - 16), a2);
}

//----- (008DF6D0) --------------------------------------------------------
void *__thiscall cResMan::_vector_deleting_destructor_(cResMan *this, unsigned int a2)
{
	return cResMan::_scalar_deleting_destructor_((cResMan *)((char *)this - 24), a2);
}

//----- (008DF6E0) --------------------------------------------------------
void *__thiscall cResMan::_vector_deleting_destructor_(cResMan *this, unsigned int a2)
{
	return cResMan::_scalar_deleting_destructor_((cResMan *)((char *)this - 32), a2);
}


