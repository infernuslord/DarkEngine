//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>


//----- (008E4B70) --------------------------------------------------------
void __thiscall cFactoryEntry::cFactoryEntry(cFactoryEntry *this, IStoreFactory *pFactory, const char *pExt)
{
	size_t v3; // eax@5
	cFactoryEntry *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	this->m_pExt = 0;
	if (!pExt)
		_CriticalMsg(
		"Creating storage factory entry with no extension!",
		"x:\\prj\\tech\\libsrc\\namedres\\storeman.cpp",
		0x1Eu);
	if (!pFactory)
		_CriticalMsg("Missing storage factory!", "x:\\prj\\tech\\libsrc\\namedres\\storeman.cpp", 0x1Fu);
	thisa->m_pFactory = pFactory;
	thisa->m_pFactory->baseclass_0.vfptr->AddRef((IUnknown *)thisa->m_pFactory);
	v3 = strlen(pExt);
	thisa->m_pExt = (char *)MallocSpew(v3 + 1, "x:\\prj\\tech\\libsrc\\namedres\\storeman.cpp", 36);
	strcpy(thisa->m_pExt, pExt);
}

//----- (008E4C18) --------------------------------------------------------
void __thiscall cFactoryEntry::_cFactoryEntry(cFactoryEntry *this)
{
	cFactoryEntry *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (this->m_pFactory)
	{
		this->m_pFactory->baseclass_0.vfptr->Release((IUnknown *)this->m_pFactory);
		thisa->m_pFactory = 0;
	}
	if (thisa->m_pExt)
	{
		FreeSpew(thisa->m_pExt, "x:\\prj\\tech\\libsrc\\namedres\\storeman.cpp", 48);
		thisa->m_pExt = 0;
	}
}

//----- (008E4C6D) --------------------------------------------------------
void __thiscall cFactoryHashByExt::cFactoryHashByExt(cFactoryHashByExt *this)
{
	cFactoryHashByExt *v1; // ST04_4@1

	v1 = this;
	cStrHashSet<cFactoryEntry__>::cStrHashSet<cFactoryEntry__>(&this->baseclass_0, 0x65u);
	v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cFactoryHashByExt::_vftable_;
}
// 9A8358: using guessed type int (__stdcall *cFactoryHashByExt___vftable_)(int __flags);

//----- (008E4C8E) --------------------------------------------------------
void __thiscall cFactoryHashByExt::_cFactoryHashByExt(cFactoryHashByExt *this)
{
	cStrHashSet<cFactoryEntry *> *v1; // ST00_4@1

	v1 = (cStrHashSet<cFactoryEntry *> *)this;
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cFactoryHashByExt::_vftable_;
	cHashSet<cFactoryEntry___char_const___cHashFunctions>::DestroyAll(&this->baseclass_0.baseclass_0);
	cStrHashSet<cFactoryEntry__>::_cStrHashSet<cFactoryEntry__>(v1);
}
// 9A8358: using guessed type int (__stdcall *cFactoryHashByExt___vftable_)(int __flags);

//----- (008E4CB2) --------------------------------------------------------
tHashSetKey__ *__thiscall cFactoryHashByExt::GetKey(cFactoryHashByExt *this, tHashSetNode__ *node)
{
	return (tHashSetKey__ *)node[1].unused;
}

//----- (008E4CC5) --------------------------------------------------------
int __stdcall cStorageManager::QueryInterface(cStorageManager *this, _GUID *id, void **ppI)
{
	int result; // eax@5

	if (id != &IID_IStoreManager
		&& id != &IID_IUnknown
		&& memcmp(id, &IID_IStoreManager, 0x10u)
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

//----- (008E4D32) --------------------------------------------------------
unsigned int __stdcall cStorageManager::AddRef(cStorageManager *this)
{
	return cStorageManager::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008E4D44) --------------------------------------------------------
unsigned int __stdcall cStorageManager::Release(cStorageManager *this)
{
	unsigned int result; // eax@2

	if (cStorageManager::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cStorageManager::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cStorageManager::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (008E4D71) --------------------------------------------------------
void __thiscall cStorageManager::cStorageManager(cStorageManager *this)
{
	IStore *v1; // eax@2
	cFactoryHashByExt *v2; // eax@7
	IStoreFactory *v3; // eax@10
	IStoreFactory *v4; // [sp+0h] [bp-20h]@10
	cFactoryHashByExt *v5; // [sp+4h] [bp-1Ch]@7
	IStore *v6; // [sp+8h] [bp-18h]@2
	cStorageManager *thisa; // [sp+Ch] [bp-14h]@1
	void *v8; // [sp+10h] [bp-10h]@9
	void *v9; // [sp+14h] [bp-Ch]@6
	void *v10; // [sp+18h] [bp-8h]@1
	void *pStoreHier; // [sp+1Ch] [bp-4h]@4

	thisa = this;
	IStoreManager::IStoreManager(&this->baseclass_0);
	cStorageManager::cRefCount::cRefCount(&thisa->__m_ulRefs);
	thisa->m_pRootStore = 0;
	thisa->m_pDefStoreFactory = 0;
	thisa->m_pGlobalContext = 0;
	thisa->m_pDefVariants = 0;
	thisa->m_pFactoryTable = 0;
	thisa->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cStorageManager::_vftable_;
	v10 = j__new(0x2Cu, "x:\\prj\\tech\\libsrc\\namedres\\storeman.cpp", 81);
	if (v10)
	{
		cDirectoryStorage::cDirectoryStorage((cDirectoryStorage *)v10, 0);
		v6 = v1;
	}
	else
	{
		v6 = 0;
	}
	thisa->m_pRootStore = v6;
	if ((**(int(__stdcall ***)(IStore *, GUID *, void **))thisa->m_pRootStore)(
		thisa->m_pRootStore,
		&IID_IStoreHierarchy,
		&pStoreHier) < 0)
		_CriticalMsg("Root storage has no IStoreHierarchy!", "x:\\prj\\tech\\libsrc\\namedres\\storeman.cpp", 0x56u);
	(*(void(__stdcall **)(void *, cStorageManager *))(*(_DWORD *)pStoreHier + 12))(pStoreHier, thisa);
	(*(void(__stdcall **)(void *))(*(_DWORD *)pStoreHier + 8))(pStoreHier);
	v9 = j__new(0x14u, "x:\\prj\\tech\\libsrc\\namedres\\storeman.cpp", 91);
	if (v9)
	{
		cFactoryHashByExt::cFactoryHashByExt((cFactoryHashByExt *)v9);
		v5 = v2;
	}
	else
	{
		v5 = 0;
	}
	thisa->m_pFactoryTable = v5;
	v8 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\storeman.cpp", 93);
	if (v8)
	{
		cDefaultStorageFactory::cDefaultStorageFactory((cDefaultStorageFactory *)v8);
		v4 = v3;
	}
	else
	{
		v4 = 0;
	}
	thisa->m_pDefStoreFactory = v4;
	cStorageManager::RegisterFactory(thisa, thisa->m_pDefStoreFactory);
}
// 9A8378: using guessed type int (__stdcall *cStorageManager___vftable_)(int this, int id, int ppI);

//----- (008E4ED1) --------------------------------------------------------
void __thiscall cStorageManager::_cStorageManager(cStorageManager *this)
{
	cStorageManager *thisa; // [sp+4h] [bp-Ch]@1
	cFactoryHashByExt *v2; // [sp+Ch] [bp-4h]@4

	thisa = this;
	this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cStorageManager::_vftable_;
	if (this->m_pRootStore)
	{
		DbgReportWarning("Storage Manager being deleted without being closed!\n");
		cStorageManager::Close(thisa);
	}
	if (thisa->m_pFactoryTable)
	{
		v2 = thisa->m_pFactoryTable;
		if (v2)
			v2->baseclass_0.baseclass_0.baseclass_0.vfptr->__vecDelDtor((cHashSetBase *)v2, 1u);
		thisa->m_pFactoryTable = 0;
	}
	if (thisa->m_pDefStoreFactory)
	{
		thisa->m_pDefStoreFactory->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pDefStoreFactory);
		thisa->m_pDefStoreFactory = 0;
	}
}
// 9A8378: using guessed type int (__stdcall *cStorageManager___vftable_)(int this, int id, int ppI);

//----- (008E4F6B) --------------------------------------------------------
void __thiscall cStorageManager::InstallStorageType(cStorageManager *this, const char *pExt, IStoreFactory *pFactory)
{
	cFactoryEntry *v3; // eax@5
	cFactoryEntry *v4; // [sp+0h] [bp-1Ch]@5
	cStorageManager *thisa; // [sp+8h] [bp-14h]@1
	void *v6; // [sp+Ch] [bp-10h]@4
	cFactoryEntry *pEntry; // [sp+18h] [bp-4h]@1

	thisa = this;
	pEntry = cHashSet<cFactoryEntry___char_const___cHashFunctions>::Search(
		&this->m_pFactoryTable->baseclass_0.baseclass_0,
		pExt);
	if (pEntry)
	{
		cHashSet<cFactoryEntry___char_const___cHashFunctions>::Remove(
			&thisa->m_pFactoryTable->baseclass_0.baseclass_0,
			pEntry);
		if (pEntry)
			cFactoryEntry::_scalar_deleting_destructor_(pEntry, 1u);
	}
	v6 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\storeman.cpp", 132);
	if (v6)
	{
		cFactoryEntry::cFactoryEntry((cFactoryEntry *)v6, pFactory, pExt);
		v4 = v3;
	}
	else
	{
		v4 = 0;
	}
	cHashSet<cFactoryEntry___char_const___cHashFunctions>::Insert(&thisa->m_pFactoryTable->baseclass_0.baseclass_0, v4);
}

//----- (008E5017) --------------------------------------------------------
void __cdecl StorageTypeEnumerator(const char *pExt, IStoreFactory *pFactory, void *pClientData)
{
	cStorageManager::InstallStorageType((cStorageManager *)pClientData, pExt, pFactory);
}

//----- (008E5035) --------------------------------------------------------
void __stdcall cStorageManager::RegisterFactory(cStorageManager *this, IStoreFactory *pFactory)
{
	pFactory->baseclass_0.vfptr[1].QueryInterface((IUnknown *)pFactory, (_GUID *)StorageTypeEnumerator, (void **)this);
}

//----- (008E5051) --------------------------------------------------------
IStore *__stdcall cStorageManager::GetStore(cStorageManager *this, const char *pPathName, int bCreate)
{
	if (!this->m_pRootStore)
		_CriticalMsg("Storage Manager doesn't have a root store!", "x:\\prj\\tech\\libsrc\\namedres\\storeman.cpp", 0xA0u);
	return (IStore *)((int(__stdcall *)(_DWORD, _DWORD, _DWORD))this->m_pRootStore->baseclass_0.vfptr[2].AddRef)(
		this->m_pRootStore,
		pPathName,
		bCreate);
}

//----- (008E5097) --------------------------------------------------------
IStore *__stdcall cStorageManager::CreateSubstore(cStorageManager *this, IStore *pParent, const char *pName)
{
	const char *v3; // eax@1
	const char *v4; // eax@2
	const char *v5; // eax@3
	IStore *v6; // ST10_4@8
	void *pHier; // [sp+4h] [bp-20h]@5
	cFactoryEntry *pFactoryEntry; // [sp+8h] [bp-1Ch]@1
	cAnsiStr Ext; // [sp+Ch] [bp-18h]@1
	int pStorage; // [sp+18h] [bp-Ch]@2
	cFileSpec fileSpec; // [sp+1Ch] [bp-8h]@1

	cAnsiStr::cAnsiStr(&Ext);
	cFileSpec::cFileSpec(&fileSpec, pName);
	cFileSpec::GetFileExtension(&fileSpec, &Ext);
	v3 = cAnsiStr::operator char_const__(&Ext);
	pFactoryEntry = cHashSet<cFactoryEntry___char_const___cHashFunctions>::Search(
		&this->m_pFactoryTable->baseclass_0.baseclass_0,
		v3);
	if (pFactoryEntry)
	{
		v5 = cAnsiStr::operator char_const__(&Ext);
		pStorage = ((int(__stdcall *)(IStoreFactory *, IStore *, const char *, const char *))pFactoryEntry->m_pFactory->baseclass_0.vfptr[1].AddRef)(
			pFactoryEntry->m_pFactory,
			pParent,
			pName,
			v5);
	}
	else
	{
		v4 = cAnsiStr::operator char_const__(&Ext);
		pStorage = ((int(__stdcall *)(IStoreFactory *, IStore *, const char *, const char *))this->m_pDefStoreFactory->baseclass_0.vfptr[1].AddRef)(
			this->m_pDefStoreFactory,
			pParent,
			pName,
			v4);
	}
	if (pStorage)
	{
		if ((**(int(__stdcall ***)(int, GUID *, void **))pStorage)(pStorage, &IID_IStoreHierarchy, &pHier) < 0)
		{
			DbgReportWarning("Storage without an IStoreHierarchy!");
		}
		else
		{
			(*(void(__stdcall **)(void *, cStorageManager *))(*(_DWORD *)pHier + 12))(pHier, this);
			(*(void(__stdcall **)(void *))(*(_DWORD *)pHier + 8))(pHier);
		}
	}
	v6 = (IStore *)pStorage;
	cFileSpec::_cFileSpec(&fileSpec);
	cAnsiStr::_cAnsiStr(&Ext);
	return v6;
}

//----- (008E518E) --------------------------------------------------------
void __cdecl SetContextRoot(ISearchPath *__formal, const char *pRoot, int a3, void *pClientData)
{
	void *pStoreHier; // [sp+0h] [bp-Ch]@2
	void *pStoreMan; // [sp+4h] [bp-8h]@1
	void *pStore; // [sp+8h] [bp-4h]@1

	pStoreMan = pClientData;
	pStore = (void *)(*(int(__stdcall **)(void *, const char *, _DWORD))(*(_DWORD *)pClientData + 16))(
		pClientData,
		pRoot,
		0);
	if (pStore)
	{
		if ((**(int(__stdcall ***)(void *, GUID *, void **))pStore)(pStore, &IID_IStoreHierarchy, &pStoreHier) >= 0)
		{
			(*(void(__stdcall **)(void *, signed int))(*(_DWORD *)pStoreHier + 28))(pStoreHier, 1);
			(*(void(__stdcall **)(void *))(*(_DWORD *)pStoreHier + 8))(pStoreHier);
		}
		(*(void(__stdcall **)(void *))(*(_DWORD *)pStore + 8))(pStore);
	}
}

//----- (008E51F7) --------------------------------------------------------
void __stdcall cStorageManager::SetGlobalContext(cStorageManager *this, ISearchPath *pPath)
{
	if (this->m_pGlobalContext)
		this->m_pGlobalContext->baseclass_0.vfptr->Release((IUnknown *)this->m_pGlobalContext);
	this->m_pGlobalContext = pPath;
	if (pPath)
	{
		pPath->baseclass_0.vfptr->AddRef((IUnknown *)pPath);
		((void(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))pPath->baseclass_0.vfptr[5].QueryInterface)(
			pPath,
			SetContextRoot,
			1,
			this);
	}
}

//----- (008E524B) --------------------------------------------------------
void __stdcall cStorageManager::SetDefaultVariants(cStorageManager *this, ISearchPath *pPath)
{
	if (this->m_pDefVariants)
		this->m_pDefVariants->baseclass_0.vfptr->Release((IUnknown *)this->m_pDefVariants);
	this->m_pDefVariants = pPath;
	if (pPath)
		pPath->baseclass_0.vfptr->AddRef((IUnknown *)pPath);
}

//----- (008E5288) --------------------------------------------------------
ISearchPath *__stdcall cStorageManager::NewSearchPath(cStorageManager *this, const char *pNewPath)
{
	ISearchPath *v2; // eax@2
	ISearchPath *v4; // [sp+0h] [bp-Ch]@2
	void *v5; // [sp+4h] [bp-8h]@1

	v5 = j__new(0x21u, "x:\\prj\\tech\\libsrc\\namedres\\storeman.cpp", 278);
	if (v5)
	{
		cSearchPath::cSearchPath((cSearchPath *)v5, &this->baseclass_0);
		v4 = v2;
	}
	else
	{
		v4 = 0;
	}
	if (this->m_pGlobalContext)
		((void(__stdcall *)(_DWORD, _DWORD))v4->baseclass_0.vfptr[3].QueryInterface)(v4, this->m_pGlobalContext);
	if (this->m_pDefVariants)
		((void(__stdcall *)(_DWORD, _DWORD))v4->baseclass_0.vfptr[3].AddRef)(v4, this->m_pDefVariants);
	if (pNewPath)
		((void(__stdcall *)(_DWORD, _DWORD))v4->baseclass_0.vfptr[1].Release)(v4, pNewPath);
	return v4;
}

//----- (008E5320) --------------------------------------------------------
void __stdcall cStorageManager::Close(cStorageManager *this)
{
	void *v1; // ecx@0
	IUnknownVtbl *v2; // eax@6
	IUnknownVtbl *v3; // edx@8
	IUnknownVtbl *v4; // ecx@10
	IUnknown *pStoreHier; // [sp+0h] [bp-4h]@1

	pStoreHier = (IUnknown *)v1;
	if (!this->m_pRootStore)
		_CriticalMsg(
		"Trying to Close without a valid Root Storage!",
		"x:\\prj\\tech\\libsrc\\namedres\\storeman.cpp",
		0x12Au);
	if ((**(int(__stdcall ***)(_DWORD, _DWORD, _DWORD, _DWORD))this->m_pRootStore)(
		this->m_pRootStore,
		&IID_IStoreHierarchy,
		&pStoreHier,
		pStoreHier) < 0)
		_CriticalMsg("Root storage has no IStoreHierarchy!", "x:\\prj\\tech\\libsrc\\namedres\\storeman.cpp", 0x12Fu);
	pStoreHier->vfptr[2].Release(pStoreHier);
	pStoreHier->vfptr->Release(pStoreHier);
	if (this->m_pRootStore)
	{
		v2 = this->m_pRootStore->baseclass_0.vfptr;
		pStoreHier = (IUnknown *)this->m_pRootStore;
		v2->Release(pStoreHier);
	}
	this->m_pRootStore = 0;
	if (this->m_pGlobalContext)
	{
		v3 = this->m_pGlobalContext->baseclass_0.vfptr;
		pStoreHier = (IUnknown *)this->m_pGlobalContext;
		v3->Release(pStoreHier);
	}
	this->m_pGlobalContext = 0;
	if (this->m_pDefVariants)
	{
		v4 = this->m_pDefVariants->baseclass_0.vfptr;
		pStoreHier = (IUnknown *)this->m_pDefVariants;
		v4->Release(pStoreHier);
	}
	this->m_pDefVariants = 0;
}

//----- (008E5408) --------------------------------------------------------
int __stdcall cStorageManager::HeteroStoreExists(cStorageManager *this, IStore *pParentStore, const char *pSubStoreName, char *pNameBuffer)
{
	tHashSetHandle hsh; // [sp+0h] [bp-14h]@1
	size_t nLen; // [sp+Ch] [bp-8h]@1
	cFactoryEntry *pEntry; // [sp+10h] [bp-4h]@1

	nLen = strlen(pSubStoreName);
	for (pEntry = cHashSet<cFactoryEntry___char_const___cHashFunctions>::GetFirst(
		&this->m_pFactoryTable->baseclass_0.baseclass_0,
		&hsh);
	pEntry;
	pEntry = cHashSet<cFactoryEntry___char_const___cHashFunctions>::GetNext(
		&this->m_pFactoryTable->baseclass_0.baseclass_0,
		&hsh))
	{
		strcpy(pNameBuffer, pSubStoreName);
		if (pNameBuffer[nLen - 1] == 92)
			pNameBuffer[nLen - 1] = 0;
		strcat(pNameBuffer, pEntry->m_pExt);
		if (((int(__stdcall *)(IStore *, char *))pParentStore->baseclass_0.vfptr[3].Release)(pParentStore, pNameBuffer))
			return 1;
	}
	return 0;
}

//----- (008E54B0) --------------------------------------------------------
void *__thiscall cFactoryHashByExt::_vector_deleting_destructor_(cFactoryHashByExt *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cFactoryHashByExt::_cFactoryHashByExt(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E54E0) --------------------------------------------------------
unsigned int __thiscall cStorageManager::cRefCount::AddRef(cStorageManager::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008E5500) --------------------------------------------------------
unsigned int __thiscall cStorageManager::cRefCount::Release(cStorageManager::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008E5520) --------------------------------------------------------
unsigned int __thiscall cStorageManager::cRefCount::operator unsigned_long(cStorageManager::cRefCount *this)
{
	return this->ul;
}

//----- (008E5530) --------------------------------------------------------
void __thiscall cStorageManager::OnFinalRelease(cStorageManager *this)
{
	if (this)
		((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[3].Release)(this, 1);
}

//----- (008E5570) --------------------------------------------------------
void __thiscall cStorageManager::cRefCount::cRefCount(cStorageManager::cRefCount *this)
{
	this->ul = 1;
}

//----- (008E5590) --------------------------------------------------------
void *__thiscall cStorageManager::_scalar_deleting_destructor_(cStorageManager *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStorageManager::_cStorageManager(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E55C0) --------------------------------------------------------
void __thiscall IStoreManager::IStoreManager(IStoreManager *this)
{
	IStoreManager *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)IStoreManager::_vftable_;
}
// 9A83A8: using guessed type int (*IStoreManager___vftable_[11])();

//----- (008E55E0) --------------------------------------------------------
void __thiscall cDefaultStorageFactory::cDefaultStorageFactory(cDefaultStorageFactory *this)
{
	cDefaultStorageFactory *v1; // ST00_4@1

	v1 = this;
	IStoreFactory::IStoreFactory(&this->baseclass_0);
	cDefaultStorageFactory::cRefCount::cRefCount(&v1->__m_ulRefs);
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cDefaultStorageFactory::_vftable_;
}
// 9A83D4: using guessed type int (__stdcall *cDefaultStorageFactory___vftable_)(int this, int id, int ppI);

//----- (008E5610) --------------------------------------------------------
void __thiscall cDefaultStorageFactory::cRefCount::cRefCount(cDefaultStorageFactory::cRefCount *this)
{
	this->ul = 1;
}
