//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>



//----- (008E5E20) --------------------------------------------------------
void __thiscall cFoundStream::cFoundStream(cFoundStream *this, IStore *pStore, const char *pName)
{
	size_t v3; // eax@5
	cFoundStream *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	this->m_pStore = 0;
	this->m_pName = 0;
	if (pStore)
	{
		this->m_pStore = pStore;
		pStore->baseclass_0.vfptr->AddRef((IUnknown *)pStore);
	}
	if (!pName)
		_CriticalMsg("Creating a FoundStream without a name!", "x:\\prj\\tech\\libsrc\\namedres\\search.cpp", 0x28u);
	v3 = strlen(pName);
	thisa->m_pName = (char *)MallocSpew(v3 + 1, "x:\\prj\\tech\\libsrc\\namedres\\search.cpp", 41);
	strcpy(thisa->m_pName, pName);
}

//----- (008E5EB4) --------------------------------------------------------
void __thiscall cFoundStream::_cFoundStream(cFoundStream *this)
{
	cFoundStream *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (this->m_pStore)
	{
		this->m_pStore->baseclass_0.vfptr->Release((IUnknown *)this->m_pStore);
		thisa->m_pStore = 0;
	}
	FreeSpew(thisa->m_pName, "x:\\prj\\tech\\libsrc\\namedres\\search.cpp", 50);
	thisa->m_pName = 0;
}

//----- (008E5F00) --------------------------------------------------------
void __thiscall cFoundStreamsByName::cFoundStreamsByName(cFoundStreamsByName *this)
{
	cFoundStreamsByName *v1; // ST04_4@1

	v1 = this;
	cStrIHashSet<cFoundStream__>::cStrIHashSet<cFoundStream__>(&this->baseclass_0, 0x65u);
	v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cFoundStreamsByName::_vftable_;
}
// 9A8444: using guessed type int (__stdcall *cFoundStreamsByName___vftable_)(int __flags);

//----- (008E5F21) --------------------------------------------------------
void __thiscall cFoundStreamsByName::_cFoundStreamsByName(cFoundStreamsByName *this)
{
	cStrIHashSet<cFoundStream *> *v1; // ST00_4@1

	v1 = (cStrIHashSet<cFoundStream *> *)this;
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cFoundStreamsByName::_vftable_;
	cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>::DestroyAll(&this->baseclass_0.baseclass_0);
	cStrIHashSet<cFoundStream__>::_cStrIHashSet<cFoundStream__>(v1);
}
// 9A8444: using guessed type int (__stdcall *cFoundStreamsByName___vftable_)(int __flags);

//----- (008E5F45) --------------------------------------------------------
tHashSetKey__ *__thiscall cFoundStreamsByName::GetKey(cFoundStreamsByName *this, tHashSetNode__ *node)
{
	return (tHashSetKey__ *)node[1].unused;
}

//----- (008E5F58) --------------------------------------------------------
int __stdcall cSearchPath::QueryInterface(cSearchPath *this, _GUID *id, void **ppI)
{
	int result; // eax@5

	if (id != &IID_ISearchPath
		&& id != &IID_IUnknown
		&& memcmp(id, &IID_ISearchPath, 0x10u)
		&& memcmp(id, &IID_IUnknown, 0x10u))
	{
		*ppI = 0;
		result = -2147467262;
	}
	else
	{
		*ppI = this;
		this->baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)this);
		result = 0;
	}
	return result;
}

//----- (008E5FC5) --------------------------------------------------------
unsigned int __stdcall cSearchPath::AddRef(cSearchPath *this)
{
	return cSearchPath::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008E5FD7) --------------------------------------------------------
unsigned int __stdcall cSearchPath::Release(cSearchPath *this)
{
	unsigned int result; // eax@2

	if (cSearchPath::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cSearchPath::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cSearchPath::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (008E6004) --------------------------------------------------------
void __thiscall cSearchPath::cSearchPath(cSearchPath *this, IStoreManager *pStoreMan)
{
	cDynArray<sSearchPathElement> *v2; // eax@2
	cDynArray<sSearchPathElement> *v3; // [sp+0h] [bp-Ch]@2
	cSearchPath *thisa; // [sp+4h] [bp-8h]@1
	void *v5; // [sp+8h] [bp-4h]@1

	thisa = this;
	ISearchPath::ISearchPath(&this->baseclass_0);
	cSearchPath::cRefCount::cRefCount(&thisa->__m_ulRefs);
	thisa->m_bPathParsed = 0;
	thisa->m_aPathStrings = 0;
	thisa->m_pContext = 0;
	thisa->m_pVariants = 0;
	thisa->m_pPathStorages = 0;
	thisa->m_pLastNode = 0;
	thisa->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cSearchPath::_vftable_;
	v5 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\search.cpp", 107);
	if (v5)
	{
		cDynArray<sSearchPathElement>::cDynArray<sSearchPathElement>((cDynArray<sSearchPathElement> *)v5);
		v3 = v2;
	}
	else
	{
		v3 = 0;
	}
	thisa->m_aPathStrings = v3;
	thisa->m_pStoreMan = pStoreMan;
	thisa->m_pStoreMan->baseclass_0.vfptr->AddRef((IUnknown *)thisa->m_pStoreMan);
}
// 9A8464: using guessed type int (__stdcall *cSearchPath___vftable_)(int this, int id, int ppI);

//----- (008E60BD) --------------------------------------------------------
void __thiscall cSearchPath::_cSearchPath(cSearchPath *this)
{
	cSearchPath *thisa; // [sp+4h] [bp-Ch]@1
	cDynArray<sSearchPathElement> *v2; // [sp+Ch] [bp-4h]@3

	thisa = this;
	this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cSearchPath::_vftable_;
	cSearchPath::Clear(this);
	if (thisa->m_pStoreMan)
	{
		thisa->m_pStoreMan->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pStoreMan);
		thisa->m_pStoreMan = 0;
	}
	v2 = thisa->m_aPathStrings;
	if (v2)
		cDynArray<sSearchPathElement>::_scalar_deleting_destructor_(v2, 1u);
	thisa->m_aPathStrings = 0;
}
// 9A8464: using guessed type int (__stdcall *cSearchPath___vftable_)(int this, int id, int ppI);

//----- (008E6136) --------------------------------------------------------
void __thiscall cSearchPath::ClearStorages(cSearchPath *this)
{
	void *v1; // ST0C_4@3
	cSearchPath *thisa; // [sp+0h] [bp-10h]@1
	void *pStoreNode; // [sp+Ch] [bp-4h]@1

	thisa = this;
	for (pStoreNode = this->m_pPathStorages; pStoreNode; pStoreNode = v1)
	{
		(*(void(__stdcall **)(_DWORD))(**(_DWORD **)pStoreNode + 8))(*(_DWORD *)pStoreNode);
		v1 = (void *)*((_DWORD *)pStoreNode + 1);
		operator delete(pStoreNode);
	}
	thisa->m_pLastNode = 0;
	thisa->m_pPathStorages = 0;
	thisa->m_bPathParsed = 0;
}

//----- (008E61A2) --------------------------------------------------------
void __stdcall cSearchPath::Clear(cSearchPath *this)
{
	void **v1; // eax@7
	cDynArray<sSearchPathElement> *v2; // eax@11
	cDynArray<sSearchPathElement> *v3; // [sp+0h] [bp-18h]@11
	void *v4; // [sp+8h] [bp-10h]@10
	cDynArray<sSearchPathElement> *v5; // [sp+10h] [bp-8h]@8
	int i; // [sp+14h] [bp-4h]@5

	if (this->m_pContext)
		this->m_pContext->baseclass_0.vfptr->Release((IUnknown *)this->m_pContext);
	this->m_pContext = 0;
	if (this->m_pVariants)
		this->m_pVariants->baseclass_0.vfptr->Release((IUnknown *)this->m_pVariants);
	this->m_pVariants = 0;
	for (i = cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::Size(&this->m_aPathStrings->baseclass_0.baseclass_0)
		- 1; i >= 0; --i)
	{
		v1 = (void **)cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::operator__(
			&this->m_aPathStrings->baseclass_0.baseclass_0,
			i);
		FreeSpew(*v1, "x:\\prj\\tech\\libsrc\\namedres\\search.cpp", 185);
	}
	v5 = this->m_aPathStrings;
	if (v5)
		cDynArray<sSearchPathElement>::_scalar_deleting_destructor_(v5, 1u);
	v4 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\search.cpp", 188);
	if (v4)
	{
		cDynArray<sSearchPathElement>::cDynArray<sSearchPathElement>((cDynArray<sSearchPathElement> *)v4);
		v3 = v2;
	}
	else
	{
		v3 = 0;
	}
	this->m_aPathStrings = v3;
	cSearchPath::ClearStorages(this);
}

//----- (008E62AD) --------------------------------------------------------
ISearchPath *__stdcall cSearchPath::Copy(cSearchPath *this)
{
	ISearchPath *v1; // eax@2
	char *v2; // ST08_4@14
	char *v3; // ST04_4@15
	char *v4; // ST04_4@16
	int v6; // [sp+0h] [bp-18h]@10
	ISearchPath *v7; // [sp+4h] [bp-14h]@2
	void *v8; // [sp+8h] [bp-10h]@1
	int i; // [sp+10h] [bp-8h]@8
	unsigned int numPaths; // [sp+14h] [bp-4h]@1

	numPaths = cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::Size(&this->m_aPathStrings->baseclass_0.baseclass_0);
	v8 = j__new(0x21u, "x:\\prj\\tech\\libsrc\\namedres\\search.cpp", 202);
	if (v8)
	{
		cSearchPath::cSearchPath((cSearchPath *)v8, this->m_pStoreMan);
		v7 = v1;
	}
	else
	{
		v7 = 0;
	}
	if (this->m_pContext)
		((void(__stdcall *)(_DWORD, _DWORD))v7->baseclass_0.vfptr[3].QueryInterface)(v7, this->m_pContext);
	if (this->m_pVariants)
		((void(__stdcall *)(_DWORD, _DWORD))v7->baseclass_0.vfptr[3].AddRef)(v7, this->m_pVariants);
	for (i = 0; i < (signed int)numPaths; ++i)
	{
		v6 = cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::operator__(
			&this->m_aPathStrings->baseclass_0.baseclass_0,
			i)->fRecurse;
		if (v6)
		{
			if (v6 == 1)
			{
				v3 = cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::operator__(
					&this->m_aPathStrings->baseclass_0.baseclass_0,
					i)->pPath;
				v7->baseclass_0.vfptr[2].QueryInterface((IUnknown *)v7, (_GUID *)v3, 0);
			}
			else
			{
				if (v6 == 2)
				{
					v4 = cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::operator__(
						&this->m_aPathStrings->baseclass_0.baseclass_0,
						i)->pPath;
					v7->baseclass_0.vfptr[2].QueryInterface((IUnknown *)v7, (_GUID *)v4, (void **)1);
				}
			}
		}
		else
		{
			v2 = cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::operator__(
				&this->m_aPathStrings->baseclass_0.baseclass_0,
				i)->pPath;
			((void(__stdcall *)(_DWORD, _DWORD))v7->baseclass_0.vfptr[1].Release)(v7, v2);
		}
	}
	return v7;
}

//----- (008E63EE) --------------------------------------------------------
void __thiscall cSearchPath::DoAddStore(cSearchPath *this, const char *pStoreName, int fRecurse)
{
	cSearchPath *thisa; // [sp+0h] [bp-Ch]@1
	sSearchPathElement NewEntry; // [sp+4h] [bp-8h]@2

	thisa = this;
	if (pStoreName)
	{
		GetNormalizedPath(pStoreName, &NewEntry.pPath);
		NewEntry.fRecurse = fRecurse;
		cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::Append(
			&thisa->m_aPathStrings->baseclass_0.baseclass_0,
			&NewEntry);
		thisa->m_bPathParsed = 0;
	}
}

//----- (008E6431) --------------------------------------------------------
void __thiscall cSearchPath::DoAddPath(cSearchPath *this, const char *pPath, int fRecurse)
{
	cSearchPath *thisa; // [sp+0h] [bp-20Ch]@1
	char buff[512]; // [sp+4h] [bp-208h]@8
	char *pdelim; // [sp+204h] [bp-8h]@6
	const char *p; // [sp+208h] [bp-4h]@4

	thisa = this;
	if (pPath && strlen(pPath))
	{
		for (p = pPath; *p; p = pdelim + 1)
		{
			pdelim = strpbrk(p, ";+");
			if (!pdelim)
			{
				cSearchPath::DoAddStore(thisa, p, fRecurse);
				return;
			}
			strncpy(buff, p, pdelim - p);
			buff[pdelim - p] = 0;
			cSearchPath::DoAddStore(thisa, buff, fRecurse);
		}
	}
}

//----- (008E64EC) --------------------------------------------------------
void __stdcall cSearchPath::AddPath(cSearchPath *this, const char *pPath)
{
	cSearchPath::DoAddPath(this, pPath, 0);
}

//----- (008E6501) --------------------------------------------------------
void __stdcall cSearchPath::AddPathTrees(cSearchPath *this, const char *pPath, int bRecurse)
{
	cSearchPath::DoAddPath(this, pPath, (bRecurse != 0) + 1);
}

//----- (008E651F) --------------------------------------------------------
void __stdcall cSearchPath::Ready(cSearchPath *this)
{
	if (!this->m_bPathParsed)
		cSearchPath::SetupStorages(this);
}

//----- (008E653A) --------------------------------------------------------
void __stdcall cSearchPath::Refresh(cSearchPath *this)
{
	;
}

//----- (008E6541) --------------------------------------------------------
void __stdcall cSearchPath::SetContext(cSearchPath *this, ISearchPath *pContext)
{
	if (this->m_pContext)
		this->m_pContext->baseclass_0.vfptr->Release((IUnknown *)this->m_pContext);
	if (pContext)
	{
		this->m_pContext = pContext;
		this->m_pContext->baseclass_0.vfptr->AddRef((IUnknown *)this->m_pContext);
	}
	else
	{
		this->m_pContext = 0;
	}
	this->m_bPathParsed = 0;
}

//----- (008E6597) --------------------------------------------------------
void __stdcall cSearchPath::SetVariants(cSearchPath *this, ISearchPath *pVariants)
{
	if (this->m_pVariants)
		this->m_pVariants->baseclass_0.vfptr->Release((IUnknown *)this->m_pVariants);
	if (pVariants)
	{
		this->m_pVariants = pVariants;
		this->m_pVariants->baseclass_0.vfptr->AddRef((IUnknown *)this->m_pVariants);
	}
	else
	{
		this->m_pVariants = 0;
	}
	this->m_bPathParsed = 0;
}

//----- (008E65ED) --------------------------------------------------------
int __cdecl StorageSetupCallback(IStore *__formal, const char *pSubstoreName, void *pClientData)
{
	cSearchPath *v3; // ST08_4@1
	char FullPath[512]; // [sp+4h] [bp-204h]@1
	void *pData; // [sp+204h] [bp-4h]@1

	pData = pClientData;
	v3 = *(cSearchPath **)pClientData;
	strcpy(FullPath, *((const char **)pClientData + 1));
	strcat(FullPath, pSubstoreName);
	cSearchPath::SetupSingleStore(v3, FullPath, 0);
	return 1;
}

//----- (008E664D) --------------------------------------------------------
void __thiscall cSearchPath::SetupSingleStore(cSearchPath *this, const char *pStorePath, int fRecurse)
{
	cSearchPath *thisa; // [sp+0h] [bp-14h]@1
	SubpathEnumerateData pData; // [sp+4h] [bp-10h]@7
	void *pNode; // [sp+Ch] [bp-8h]@3
	void *pStore; // [sp+10h] [bp-4h]@1

	thisa = this;
	pStore = (void *)((int(__stdcall *)(IStoreManager *, const char *, _DWORD))this->m_pStoreMan->baseclass_0.vfptr[1].AddRef)(
		this->m_pStoreMan,
		pStorePath,
		0);
	if (pStore && (*(int(__stdcall **)(void *))(*(_DWORD *)pStore + 40))(pStore))
	{
		pNode = MallocSpew(8u, "x:\\prj\\tech\\libsrc\\namedres\\search.cpp", 421);
		*(_DWORD *)pNode = pStore;
		*((_DWORD *)pNode + 1) = 0;
		if (thisa->m_pPathStorages)
			thisa->m_pLastNode->pNext = (PathStorageNode *)pNode;
		else
			thisa->m_pPathStorages = (PathStorageNode *)pNode;
		thisa->m_pLastNode = (PathStorageNode *)pNode;
		if (fRecurse)
		{
			pData.pThisPath = thisa;
			pData.pRootPath = pStorePath;
			(*(void(__stdcall **)(void *, int(__cdecl *)(IStore *, const char *, void *), _DWORD, _DWORD, SubpathEnumerateData *))(*(_DWORD *)pStore + 20))(
				pStore,
				StorageSetupCallback,
				0,
				fRecurse == 2,
				&pData);
		}
	}
}

//----- (008E671A) --------------------------------------------------------
void __cdecl DispatchSetupStorage(ISearchPath *__formal, const char *pStore, int fRecurse, void *pClientData)
{
	cSearchPath::SetupSingleStore((cSearchPath *)pClientData, pStore, fRecurse);
}

//----- (008E6738) --------------------------------------------------------
void __thiscall cSearchPath::SetupStorages(cSearchPath *this)
{
	cSearchPath *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cSearchPath::ClearStorages(this);
	if (thisa->m_aPathStrings)
	{
		if (cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::Size(&thisa->m_aPathStrings->baseclass_0.baseclass_0))
		{
			((void(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))thisa->baseclass_0.baseclass_0.vfptr[5].QueryInterface)(
				thisa,
				DispatchSetupStorage,
				1,
				thisa);
			thisa->m_bPathParsed = 1;
		}
	}
}

//----- (008E6783) --------------------------------------------------------
void __cdecl FindInStorage(ISearchPath *__formal, const char *pVariant, int a3, void *pClientData)
{
	int pStore; // [sp+4h] [bp-4h]@3

	if (!*((_DWORD *)pClientData + 3))
	{
		if (pVariant)
		{
			pStore = (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)pClientData + 28))(
				*(_DWORD *)pClientData,
				pVariant,
				0);
			if (!pStore)
				return;
		}
		else
		{
			pStore = *(_DWORD *)pClientData;
			(*(void(__stdcall **)(_DWORD))(**(_DWORD **)pClientData + 4))(*(_DWORD *)pClientData);
		}
		if (*((_DWORD *)pClientData + 2) & 2)
		{
			*((_DWORD *)pClientData + 3) = (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)pStore + 28))(
				pStore,
				*((_DWORD *)pClientData + 1),
				0);
			if (*((_DWORD *)pClientData + 3))
			{
				if (!(*(int(__stdcall **)(_DWORD))(**((_DWORD **)pClientData + 3) + 40))(*((_DWORD *)pClientData + 3)))
				{
					(*(void(__stdcall **)(_DWORD))(**((_DWORD **)pClientData + 3) + 8))(*((_DWORD *)pClientData + 3));
					*((_DWORD *)pClientData + 3) = 0;
				}
			}
		}
		else
		{
			if ((*(int(__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)pStore + 44))(pStore, *((_DWORD *)pClientData + 1)))
			{
				*((_DWORD *)pClientData + 3) = pStore;
				(*(void(__stdcall **)(_DWORD))(**((_DWORD **)pClientData + 3) + 4))(*((_DWORD *)pClientData + 3));
			}
		}
		(*(void(__stdcall **)(_DWORD))(*(_DWORD *)pStore + 8))(pStore);
	}
}

//----- (008E6884) --------------------------------------------------------
IStore *__stdcall cSearchPath::Find(cSearchPath *this, const char *pName, unsigned int fFlags, IStore **ppCanonStore, const char *pRawRelPath)
{
	IStore *result; // eax@3
	FindInfo Info; // [sp+0h] [bp-20h]@16
	void *pRelPath; // [sp+10h] [bp-10h]@7
	IStore *found; // [sp+14h] [bp-Ch]@1
	PathStorageNode *pNode; // [sp+18h] [bp-8h]@1
	IStore *pStore; // [sp+1Ch] [bp-4h]@1

	pStore = 0;
	found = 0;
	pNode = 0;
	if (pName && *pName)
	{
		if (!this->m_bPathParsed)
			cSearchPath::SetupStorages(this);
		if (pRawRelPath)
			GetNormalizedPath(pRawRelPath, (char **)&pRelPath);
		else
			pRelPath = 0;
		for (pNode = this->m_pPathStorages; !found && pNode; pNode = pNode->pNext)
		{
			if (pRelPath)
			{
				pStore = (IStore *)((int(__stdcall *)(IStore *, void *, _DWORD))pNode->pStore->baseclass_0.vfptr[2].AddRef)(
					pNode->pStore,
					pRelPath,
					0);
			}
			else
			{
				pStore = pNode->pStore;
				pStore->baseclass_0.vfptr->AddRef((IUnknown *)pStore);
			}
			if (pStore)
			{
				Info.pName = pName;
				Info.pStore = pStore;
				Info.fFlags = fFlags;
				Info.pFound = 0;
				if (this->m_pVariants)
					((void(__stdcall *)(ISearchPath *, void(__cdecl *)(ISearchPath *, const char *, int, void *), _DWORD, FindInfo *))this->m_pVariants->baseclass_0.vfptr[5].QueryInterface)(
					this->m_pVariants,
					FindInStorage,
					0,
					&Info);
				else
					FindInStorage(0, 0, 0, &Info);
				found = Info.pFound;
				if (Info.pFound)
				{
					if (ppCanonStore)
					{
						*ppCanonStore = pStore;
						pStore->baseclass_0.vfptr->AddRef((IUnknown *)pStore);
					}
				}
				pStore->baseclass_0.vfptr->Release((IUnknown *)pStore);
			}
		}
		if (pRelPath)
			FreeSpew(pRelPath, "x:\\prj\\tech\\libsrc\\namedres\\search.cpp", 625);
		result = found;
	}
	else
	{
		DbgReportWarning("Find: empty name!\n");
		result = 0;
	}
	return result;
}

//----- (008E6A0C) --------------------------------------------------------
void *__stdcall cSearchPath::BeginContents(cSearchPath *this, const char *pPattern, unsigned int fFlags, const char *pRelPath)
{
	void *result; // eax@4
	size_t v5; // eax@6
	size_t v6; // eax@9
	int v7; // eax@12
	int v8; // [sp+0h] [bp-Ch]@12
	void *v9; // [sp+4h] [bp-8h]@11
	void *pCookie; // [sp+8h] [bp-4h]@5

	if (!this->m_bPathParsed)
		cSearchPath::SetupStorages(this);
	if (this->m_pPathStorages)
	{
		pCookie = MallocSpew(0x18u, "x:\\prj\\tech\\libsrc\\namedres\\search.cpp", 654);
		*(_DWORD *)pCookie = this->m_pPathStorages;
		if (pRelPath)
		{
			v5 = strlen(pRelPath);
			*((_DWORD *)pCookie + 4) = MallocSpew(v5 + 1, "x:\\prj\\tech\\libsrc\\namedres\\search.cpp", 657);
			strcpy(*((char **)pCookie + 4), pRelPath);
		}
		else
		{
			*((_DWORD *)pCookie + 4) = 0;
		}
		*((_DWORD *)pCookie + 1) = 0;
		if (pPattern)
		{
			v6 = strlen(pPattern);
			*((_DWORD *)pCookie + 2) = MallocSpew(v6 + 1, "x:\\prj\\tech\\libsrc\\namedres\\search.cpp", 664);
			strcpy(*((char **)pCookie + 2), pPattern);
		}
		else
		{
			*((_DWORD *)pCookie + 2) = 0;
		}
		*((_DWORD *)pCookie + 3) = fFlags;
		v9 = j__new(0x14u, "x:\\prj\\tech\\libsrc\\namedres\\search.cpp", 670);
		if (v9)
		{
			cStreamHashByName::cStreamHashByName((cStreamHashByName *)v9);
			v8 = v7;
		}
		else
		{
			v8 = 0;
		}
		*((_DWORD *)pCookie + 5) = v8;
		result = pCookie;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008E6B48) --------------------------------------------------------
int __stdcall cSearchPath::Next(cSearchPath *this, void *pUntypedCookie, IStore **ppStore, char *pName, IStore **ppCanonStore)
{
	cNamedStream *v6; // eax@16
	cNamedStream *v7; // [sp+0h] [bp-18h]@16
	void *v8; // [sp+4h] [bp-14h]@15
	IStore *pStore; // [sp+14h] [bp-4h]@4

	while (1)
	{
		while (1)
		{
		LABEL_1:
			if (!*(_DWORD *)pUntypedCookie)
				return 0;
			if (!*((_DWORD *)pUntypedCookie + 4))
				break;
			pStore = (IStore *)(*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(***(_DWORD ***)pUntypedCookie + 28))(
				**(_DWORD **)pUntypedCookie,
				*((_DWORD *)pUntypedCookie + 4),
				0);
			if (pStore)
				goto LABEL_8;
			*(_DWORD *)pUntypedCookie = *(_DWORD *)(*(_DWORD *)pUntypedCookie + 4);
		}
		pStore = (IStore *)**(_DWORD **)pUntypedCookie;
		pStore->baseclass_0.vfptr->AddRef((IUnknown *)**(_DWORD **)pUntypedCookie);
	LABEL_8:
		if (*((_DWORD *)pUntypedCookie + 1))
			break;
		*((_DWORD *)pUntypedCookie + 1) = ((int(__stdcall *)(_DWORD, _DWORD, _DWORD))pStore->baseclass_0.vfptr[4].AddRef)(
			pStore,
			*((_DWORD *)pUntypedCookie + 2),
			*((_DWORD *)pUntypedCookie + 3));
		if (*((_DWORD *)pUntypedCookie + 1))
			break;
		pStore->baseclass_0.vfptr->Release((IUnknown *)pStore);
		*(_DWORD *)pUntypedCookie = *(_DWORD *)(*(_DWORD *)pUntypedCookie + 4);
	}
	do
	{
		if (!((int(__stdcall *)(_DWORD, _DWORD, _DWORD))pStore->baseclass_0.vfptr[4].Release)(
			pStore,
			*((_DWORD *)pUntypedCookie + 1),
			pName))
		{
			((void(__stdcall *)(_DWORD, _DWORD))pStore->baseclass_0.vfptr[5].QueryInterface)(
				pStore,
				*((_DWORD *)pUntypedCookie + 1));
			pStore->baseclass_0.vfptr->Release((IUnknown *)pStore);
			*((_DWORD *)pUntypedCookie + 1) = 0;
			*(_DWORD *)pUntypedCookie = *(_DWORD *)(*(_DWORD *)pUntypedCookie + 4);
			goto LABEL_1;
		}
	} while (cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::Search(
		*((cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> **)pUntypedCookie + 5),
		pName));
	*ppStore = pStore;
	if (ppCanonStore)
	{
		*ppCanonStore = pStore;
		pStore->baseclass_0.vfptr->AddRef((IUnknown *)pStore);
	}
	v8 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\search.cpp", 741);
	if (v8)
	{
		cNamedStream::cNamedStream((cNamedStream *)v8, pName, 1);
		v7 = v6;
	}
	else
	{
		v7 = 0;
	}
	cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::Insert(
		*((cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> **)pUntypedCookie + 5),
		v7);
	return 1;
}

//----- (008E6D13) --------------------------------------------------------
void __stdcall cSearchPath::EndContents(cSearchPath *this, void *pUntypedCookie)
{
	int v2; // [sp+8h] [bp-8h]@7

	if (pUntypedCookie)
	{
		if (*((_DWORD *)pUntypedCookie + 2))
			FreeSpew(*((void **)pUntypedCookie + 2), "x:\\prj\\tech\\libsrc\\namedres\\search.cpp", 765);
		if (*((_DWORD *)pUntypedCookie + 4))
			FreeSpew(*((void **)pUntypedCookie + 4), "x:\\prj\\tech\\libsrc\\namedres\\search.cpp", 768);
		if (*((_DWORD *)pUntypedCookie + 5))
		{
			v2 = *((_DWORD *)pUntypedCookie + 5);
			if (v2)
				(**(void(__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
		}
		FreeSpew(pUntypedCookie, "x:\\prj\\tech\\libsrc\\namedres\\search.cpp", 773);
	}
}

//----- (008E6DBF) --------------------------------------------------------
void __thiscall cSearchPath::DoIterate(cSearchPath *this, const char *pContext, void(__cdecl *callback)(ISearchPath *, const char *, int, void *), void *pClientData)
{
	const char **v4; // eax@3
	sSearchPathElement *v5; // eax@3
	cSearchPath *thisa; // [sp+0h] [bp-20Ch]@1
	char fullpath[512]; // [sp+4h] [bp-208h]@3
	int i; // [sp+204h] [bp-8h]@1
	unsigned int numPaths; // [sp+208h] [bp-4h]@1

	thisa = this;
	numPaths = cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::Size(&this->m_aPathStrings->baseclass_0.baseclass_0);
	for (i = 0; i < (signed int)numPaths; ++i)
	{
		strcpy(fullpath, pContext);
		v4 = (const char **)cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::operator__(
			&thisa->m_aPathStrings->baseclass_0.baseclass_0,
			i);
		strcat(fullpath, *v4);
		v5 = cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::operator__(
			&thisa->m_aPathStrings->baseclass_0.baseclass_0,
			i);
		callback(&thisa->baseclass_0, fullpath, v5->fRecurse, pClientData);
	}
}

//----- (008E6E66) --------------------------------------------------------
void __cdecl doDispatchIterate(ISearchPath *__formal, const char *pContextStore, int a3, void *pClientData)
{
	cSearchPath::DoIterate(
		*(cSearchPath **)pClientData,
		pContextStore,
		*((void(__cdecl **)(ISearchPath *, const char *, int, void *))pClientData + 1),
		*((void **)pClientData + 2));
}

//----- (008E6E90) --------------------------------------------------------
void __stdcall cSearchPath::Iterate(cSearchPath *this, void(__cdecl *callback)(ISearchPath *, const char *, int, void *), int bUseContext, void *pClientData)
{
	PathIterateData Envelope; // [sp+0h] [bp-Ch]@4

	if (bUseContext && this->m_pContext)
	{
		Envelope.pPath = this;
		Envelope.RealCallback = callback;
		Envelope.pRealClientData = pClientData;
		((void(__stdcall *)(ISearchPath *, void(__cdecl *)(ISearchPath *, const char *, int, void *), signed int, PathIterateData *))this->m_pContext->baseclass_0.vfptr[5].QueryInterface)(
			this->m_pContext,
			doDispatchIterate,
			1,
			&Envelope);
	}
	else
	{
		cSearchPath::DoIterate(this, pContext, callback, pClientData);
	}
}

//----- (008E6F00) --------------------------------------------------------
void *__thiscall cFoundStreamsByName::_vector_deleting_destructor_(cFoundStreamsByName *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cFoundStreamsByName::_cFoundStreamsByName(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E6F30) --------------------------------------------------------
unsigned int __thiscall cSearchPath::cRefCount::AddRef(cSearchPath::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008E6F50) --------------------------------------------------------
unsigned int __thiscall cSearchPath::cRefCount::Release(cSearchPath::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008E6F70) --------------------------------------------------------
unsigned int __thiscall cSearchPath::cRefCount::operator unsigned_long(cSearchPath::cRefCount *this)
{
	return this->ul;
}

//----- (008E6F80) --------------------------------------------------------
void __thiscall cSearchPath::OnFinalRelease(cSearchPath *this)
{
	if (this)
		((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[5].AddRef)(this, 1);
}

//----- (008E6FC0) --------------------------------------------------------
void __thiscall cSearchPath::cRefCount::cRefCount(cSearchPath::cRefCount *this)
{
	this->ul = 1;
}

//----- (008E6FE0) --------------------------------------------------------
void *__thiscall cSearchPath::_scalar_deleting_destructor_(cSearchPath *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cSearchPath::_cSearchPath(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E7010) --------------------------------------------------------
void __thiscall ISearchPath::ISearchPath(ISearchPath *this)
{
	ISearchPath *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)ISearchPath::_vftable_;
}
// 9A84A8: using guessed type int (*ISearchPath___vftable_[16])();

//----- (008E7030) --------------------------------------------------------
void *__thiscall cDynArray<sSearchPathElement>::_scalar_deleting_destructor_(cDynArray<sSearchPathElement> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cDynArray<sSearchPathElement>::_cDynArray<sSearchPathElement>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E7060) --------------------------------------------------------
void __thiscall cDynArray<sSearchPathElement>::_cDynArray<sSearchPathElement>(cDynArray<sSearchPathElement> *this)
{
	cDynArray_<sSearchPathElement_4>::_cDynArray_<sSearchPathElement_4>(&this->baseclass_0);
}

//----- (008E7080) --------------------------------------------------------
void __thiscall cDynArray_<sSearchPathElement_4>::_cDynArray_<sSearchPathElement_4>(cDynArray_<sSearchPathElement, 4> *this)
{
	cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::_cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>(&this->baseclass_0);
}

//----- (008E70A0) --------------------------------------------------------
void __thiscall cDynArray<sSearchPathElement>::cDynArray<sSearchPathElement>(cDynArray<sSearchPathElement> *this)
{
	cDynArray_<sSearchPathElement_4>::cDynArray_<sSearchPathElement_4>(&this->baseclass_0);
}

//----- (008E70C0) --------------------------------------------------------
void __thiscall cDynArray_<sSearchPathElement_4>::cDynArray_<sSearchPathElement_4>(cDynArray_<sSearchPathElement, 4> *this)
{
	cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>(&this->baseclass_0);
}


