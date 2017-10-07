//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>







//----- (008EDC20) --------------------------------------------------------
void __thiscall cDirectoryStorage::cDirectoryStorage(cDirectoryStorage *this, const char *pRawName)
{
	size_t v2; // eax@2
	cStorageHashByName *v3; // eax@4
	cStreamHashByName *v4; // eax@7
	cStreamHashByName *v5; // [sp+0h] [bp-18h]@7
	cStorageHashByName *v6; // [sp+4h] [bp-14h]@4
	cDirectoryStorage *thisa; // [sp+8h] [bp-10h]@1
	void *v8; // [sp+Ch] [bp-Ch]@6
	void *v9; // [sp+10h] [bp-8h]@3
	const char *pName; // [sp+14h] [bp-4h]@2

	thisa = this;
	cStorageBase::cStorageBase(&this->baseclass_0);
	thisa->m_pFilePath = 0;
	thisa->m_pName = 0;
	thisa->m_pParent = 0;
	thisa->m_pSubstorageTable = 0;
	thisa->m_pStreamTable = 0;
	thisa->m_Exists = 2;
	thisa->m_pStoreManager = 0;
	thisa->m_fFlags = 0;
	thisa->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cDirectoryStorage::_vftable_;
	thisa->baseclass_0.baseclass_4.baseclass_0.vfptr = (IUnknownVtbl *)&cDirectoryStorage::_vftable_;
	if (pRawName)
	{
		GetNormalizedPath(pRawName, (char **)&pName);
		v2 = strlen(pName);
		thisa->m_pName = (char *)MallocSpew(v2 + 1, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 33);
		strcpy(thisa->m_pName, pName);
		FreeSpew((void *)pName, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 35);
	}
	v9 = j__new(0x14u, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 38);
	if (v9)
	{
		cStorageHashByName::cStorageHashByName((cStorageHashByName *)v9);
		v6 = v3;
	}
	else
	{
		v6 = 0;
	}
	thisa->m_pSubstorageTable = v6;
	v8 = j__new(0x14u, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 39);
	if (v8)
	{
		cStreamHashByName::cStreamHashByName((cStreamHashByName *)v8);
		v5 = v4;
	}
	else
	{
		v5 = 0;
	}
	thisa->m_pStreamTable = v5;
}
// 9A8B2C: using guessed type int (__stdcall *cDirectoryStorage___vftable_)(int this, int, int);
// 9A8B50: using guessed type int (__stdcall *cDirectoryStorage___vftable_)(int this, int id, int ppReturn);

//----- (008EDD6C) --------------------------------------------------------
void __thiscall cDirectoryStorage::_cDirectoryStorage(cDirectoryStorage *this)
{
	cDirectoryStorage *thisa; // [sp+10h] [bp-34h]@1
	cStreamHashByName *v2; // [sp+18h] [bp-2Ch]@19
	cStorageHashByName *v3; // [sp+28h] [bp-1Ch]@10
	cFilePath *v4; // [sp+30h] [bp-14h]@4
	tHashSetHandle h; // [sp+34h] [bp-10h]@14
	cNamedStream *pEntry; // [sp+40h] [bp-4h]@14

	thisa = this;
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cDirectoryStorage::_vftable_;
	this->baseclass_0.baseclass_4.baseclass_0.vfptr = (IUnknownVtbl *)&cDirectoryStorage::_vftable_;
	if (this->m_pName)
	{
		FreeSpew(this->m_pName, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 46);
		thisa->m_pName = 0;
	}
	if (thisa->m_pFilePath)
	{
		v4 = thisa->m_pFilePath;
		if (v4)
			cFilePath::_scalar_deleting_destructor_(v4, 1u);
		thisa->m_pFilePath = 0;
	}
	if (thisa->m_pParent)
	{
		thisa->m_pParent->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pParent);
		thisa->m_pParent = 0;
	}
	if (thisa->m_pSubstorageTable)
	{
		v3 = thisa->m_pSubstorageTable;
		if (v3)
			v3->baseclass_0.baseclass_0.baseclass_0.vfptr->__vecDelDtor((cHashSetBase *)v3, 1u);
		thisa->m_pSubstorageTable = 0;
	}
	if (thisa->m_pStreamTable)
	{
		for (pEntry = cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::GetFirst(
			&thisa->m_pStreamTable->baseclass_0.baseclass_0,
			&h);
		pEntry;
		pEntry = cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::GetNext(
			&thisa->m_pStreamTable->baseclass_0.baseclass_0,
			&h))
		{
			cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::Remove(
				&thisa->m_pStreamTable->baseclass_0.baseclass_0,
				pEntry);
			if (pEntry)
				cNamedStream::_scalar_deleting_destructor_(pEntry, 1u);
		}
		v2 = thisa->m_pStreamTable;
		if (v2)
			v2->baseclass_0.baseclass_0.baseclass_0.vfptr->__vecDelDtor((cHashSetBase *)v2, 1u);
		thisa->m_pStreamTable = 0;
	}
	if (thisa->m_pStoreManager)
	{
		thisa->m_pStoreManager->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pStoreManager);
		thisa->m_pStoreManager = 0;
	}
	cStorageBase::_cStorageBase(&thisa->baseclass_0);
}
// 9A8B2C: using guessed type int (__stdcall *cDirectoryStorage___vftable_)(int this, int, int);
// 9A8B50: using guessed type int (__stdcall *cDirectoryStorage___vftable_)(int this, int id, int ppReturn);

//----- (008EDF2E) --------------------------------------------------------
const char *__stdcall cDirectoryStorage::GetName(cDirectoryStorage *this)
{
	return this->m_pName;
}

//----- (008EDF3B) --------------------------------------------------------
const char *__stdcall cDirectoryStorage::GetFullPathName(cDirectoryStorage *this)
{
	const char *result; // eax@2

	if (this->m_pFilePath)
		result = cFilePath::GetPathName(this->m_pFilePath);
	else
		result = 0;
	return result;
}

//----- (008EDF5A) --------------------------------------------------------
void __thiscall cDirectoryStorage::EnumerateLevelHelper(cDirectoryStorage *this, cFilePath *pPath, int(__cdecl *Callback)(IStore *, const char *, void *), int bAbsolute, int bRecurse, void *pClientData)
{
	cDirectoryStorage *thisa; // [sp+0h] [bp-2Ch]@1
	sFindContext FC; // [sp+4h] [bp-28h]@1
	cAnsiStr RelativePath; // [sp+Ch] [bp-20h]@1
	cFilePath FoundPath; // [sp+18h] [bp-14h]@1
	int bContinue; // [sp+24h] [bp-8h]@1
	const char *pName; // [sp+28h] [bp-4h]@4

	thisa = this;
	sFindContext::sFindContext(&FC);
	cFilePath::cFilePath(&FoundPath);
	cAnsiStr::cAnsiStr(&RelativePath);
	for (bContinue = cFilePath::FindFirst(pPath, &FoundPath, &FC);
		bContinue;
		bContinue = cFilePath::FindNext(pPath, &FoundPath, &FC))
	{
		if (bAbsolute)
		{
			cFilePath::MakeFullPath(&FoundPath);
			pName = cFilePath::GetPathName(&FoundPath);
		}
		else
		{
			if (cFilePath::ComputeAnchoredPath(thisa->m_pFilePath, &FoundPath, &RelativePath))
			{
				pName = cAnsiStr::operator char_const__(&RelativePath);
			}
			else
			{
				cFilePath::MakeFullPath(&FoundPath);
				pName = cFilePath::GetPathName(&FoundPath);
			}
		}
		if (Callback(&thisa->baseclass_0.baseclass_0, pName, pClientData))
		{
			if (bRecurse)
				cDirectoryStorage::EnumerateLevelHelper(thisa, &FoundPath, Callback, bAbsolute, bRecurse, pClientData);
		}
	}
	cFilePath::FindDone(pPath, &FC);
	cAnsiStr::_cAnsiStr(&RelativePath);
	cFilePath::_cFilePath(&FoundPath);
}

//----- (008EE05C) --------------------------------------------------------
void __stdcall cDirectoryStorage::EnumerateLevel(cDirectoryStorage *this, int(__cdecl *Callback)(IStore *, const char *, void *), int bAbsolute, int bRecurse, void *pClientData)
{
	if (this->m_pFilePath)
		cDirectoryStorage::EnumerateLevelHelper(this, this->m_pFilePath, Callback, bAbsolute, bRecurse, pClientData);
}

//----- (008EE08D) --------------------------------------------------------
void __thiscall cDirectoryStorage::EnumerateStreamPath(cDirectoryStorage *this, cFilePath *pPath, int(__cdecl *Callback)(IStore *, const char *, void *), int bAbsolute, void *pClientData)
{
	cDirectoryStorage *thisa; // [sp+0h] [bp-28h]@1
	sFindContext FC; // [sp+4h] [bp-24h]@1
	cAnsiStr Name; // [sp+Ch] [bp-1Ch]@1
	cFileSpec FoundFile; // [sp+18h] [bp-10h]@1
	int bContinue; // [sp+20h] [bp-8h]@1
	const char *pName; // [sp+24h] [bp-4h]@8

	thisa = this;
	sFindContext::sFindContext(&FC);
	cFileSpec::cFileSpec(&FoundFile);
	cAnsiStr::cAnsiStr(&Name);
	for (bContinue = cFilePath::FindFirst(pPath, &FoundFile, &FC);
		bContinue;
		bContinue = cFilePath::FindNext(pPath, &FoundFile, &FC))
	{
		if (bAbsolute)
		{
			cFileSpec::MakeFullPath(&FoundFile);
			cFileSpec::GetNameString(&FoundFile, &Name, 0);
		}
		else
		{
			if (cFileSpec::MakeAnchoredPath(&FoundFile, thisa->m_pFilePath))
				cFileSpec::GetNameString(&FoundFile, &Name, kAnchorRelativeNameStyle);
			else
				cFileSpec::GetNameString(&FoundFile, &Name, 0);
		}
		pName = cAnsiStr::operator char_const__(&Name);
		Callback(&thisa->baseclass_0.baseclass_0, pName, pClientData);
	}
	cFilePath::FindDone(pPath, &FC);
	cAnsiStr::_cAnsiStr(&Name);
	cFileSpec::_cFileSpec(&FoundFile);
}

//----- (008EE171) --------------------------------------------------------
void __thiscall cDirectoryStorage::EnumerateStreamHelper(cDirectoryStorage *this, cFilePath *pPath, int(__cdecl *Callback)(IStore *, const char *, void *), int bAbsolute, int bRecurse, void *pClientData)
{
	cDirectoryStorage *thisa; // [sp+0h] [bp-28h]@1
	sFindContext FC; // [sp+4h] [bp-24h]@1
	cAnsiStr RelativePath; // [sp+Ch] [bp-1Ch]@1
	cFilePath FoundPath; // [sp+18h] [bp-10h]@1
	int bContinue; // [sp+24h] [bp-4h]@2

	thisa = this;
	sFindContext::sFindContext(&FC);
	cFilePath::cFilePath(&FoundPath);
	cAnsiStr::cAnsiStr(&RelativePath);
	cDirectoryStorage::EnumerateStreamPath(thisa, pPath, Callback, bAbsolute, pClientData);
	if (bRecurse)
	{
		for (bContinue = cFilePath::FindFirst(pPath, &FoundPath, &FC);
			bContinue;
			bContinue = cFilePath::FindNext(pPath, &FoundPath, &FC))
			cDirectoryStorage::EnumerateStreamHelper(thisa, &FoundPath, Callback, bAbsolute, bRecurse, pClientData);
		cFilePath::FindDone(pPath, &FC);
	}
	cAnsiStr::_cAnsiStr(&RelativePath);
	cFilePath::_cFilePath(&FoundPath);
}

//----- (008EE21C) --------------------------------------------------------
void __stdcall cDirectoryStorage::EnumerateStreams(cDirectoryStorage *this, int(__cdecl *Callback)(IStore *, const char *, void *), int bAbsolute, int bRecurse, void *pClientData)
{
	if (this->m_pFilePath)
		cDirectoryStorage::EnumerateStreamHelper(this, this->m_pFilePath, Callback, bAbsolute, bRecurse, pClientData);
}

//----- (008EE24D) --------------------------------------------------------
IStore *__stdcall cDirectoryStorage::GetSubstorage(cDirectoryStorage *this, const char *pSubPath, int bCreate)
{
	IStore *result; // eax@3
	int v4; // eax@24
	void *v5; // eax@27
	void *v6; // eax@34
	int v7; // eax@39
	void *v8; // eax@42
	void *v9; // eax@46
	IStore *v10; // ST4C_4@52
	void *v11; // [sp+0h] [bp-B0h]@46
	void *v12; // [sp+4h] [bp-ACh]@42
	int v13; // [sp+8h] [bp-A8h]@39
	void *v14; // [sp+Ch] [bp-A4h]@34
	void *v15; // [sp+10h] [bp-A0h]@27
	int v16; // [sp+14h] [bp-9Ch]@24
	void *v17; // [sp+1Ch] [bp-94h]@45
	void *v18; // [sp+20h] [bp-90h]@41
	void *v19; // [sp+24h] [bp-8Ch]@38
	void *v20; // [sp+2Ch] [bp-84h]@33
	void *v21; // [sp+30h] [bp-80h]@26
	void *v22; // [sp+34h] [bp-7Ch]@23
	char NameBuffer[32]; // [sp+44h] [bp-6Ch]@30
	void *pNewStore; // [sp+64h] [bp-4Ch]@26
	cFilePath SubstoragePath; // [sp+68h] [bp-48h]@15
	cFilePath AnchoredSubpath; // [sp+74h] [bp-3Ch]@14
	char isDriveLetter; // [sp+80h] [bp-30h]@1
	cNamedStorage *pSubEntry; // [sp+84h] [bp-2Ch]@4
	IStore *pSubstorage; // [sp+88h] [bp-28h]@5
	char topPathLevel[32]; // [sp+8Ch] [bp-24h]@4
	const char *pathRest; // [sp+ACh] [bp-4h]@4

	isDriveLetter = 0;
	if (!pSubPath || !strlen(pSubPath))
		return 0;
	GetPathTop(pSubPath, topPathLevel, &pathRest);
	pSubEntry = cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Search(
		&this->m_pSubstorageTable->baseclass_0.baseclass_0,
		topPathLevel);
	if (pSubEntry)
	{
		pSubstorage = pSubEntry->m_pStore;
		if (!pSubstorage)
			return 0;
		pSubstorage->baseclass_0.vfptr->AddRef((IUnknown *)pSubstorage);
		goto LABEL_50;
	}
	if (!strcmp(topPathLevel, "..\\") && this->m_pParent)
	{
		pSubstorage = this->m_pParent;
		pSubstorage->baseclass_0.vfptr->AddRef((IUnknown *)pSubstorage);
		goto LABEL_50;
	}
	if (!strcmp(topPathLevel, ".\\") && this->m_pParent)
	{
		pSubstorage = (IStore *)this;
		this->baseclass_0.baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)this);
		goto LABEL_50;
	}
	cFilePath::cFilePath(&AnchoredSubpath);
	if (this->m_pFilePath)
	{
		cFilePath::cFilePath(&SubstoragePath, topPathLevel);
		cFilePath::operator_(&AnchoredSubpath, this->m_pFilePath);
		if (!cFilePath::AddRelativePath(&AnchoredSubpath, &SubstoragePath))
		{
			cFilePath::_cFilePath(&SubstoragePath);
			cFilePath::_cFilePath(&AnchoredSubpath);
			return 0;
		}
		cFilePath::_cFilePath(&SubstoragePath);
	}
	else
	{
		if (topPathLevel[1] == 58)
			isDriveLetter = 1;
		else
			cFilePath::FromText(&AnchoredSubpath, topPathLevel);
	}
	if (isDriveLetter || cFilePath::PathExists(&AnchoredSubpath))
	{
		v22 = j__new(0x2Cu, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 377);
		if (v22)
		{
			cDirectoryStorage::cDirectoryStorage((cDirectoryStorage *)v22, topPathLevel);
			v16 = v4;
		}
		else
		{
			v16 = 0;
		}
		pNewStore = (void *)v16;
		(*(void(__stdcall **)(int, cDirectoryStorage *))(*(_DWORD *)(v16 + 4) + 20))(v16 + 4, this);
		(*(void(__stdcall **)(char *, IStoreManager *))(*((_DWORD *)pNewStore + 1) + 12))(
			(char *)pNewStore + 4,
			this->m_pStoreManager);
		pSubstorage = (IStore *)v16;
		v21 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 381);
		if (v21)
		{
			cNamedStorage::cNamedStorage((cNamedStorage *)v21, pSubstorage);
			v15 = v5;
		}
		else
		{
			v15 = 0;
		}
		pSubEntry = (cNamedStorage *)v15;
		cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Insert(
			&this->m_pSubstorageTable->baseclass_0.baseclass_0,
			(cNamedStorage *)v15);
		goto LABEL_49;
	}
	if (((int(__stdcall *)(IStoreManager *, cDirectoryStorage *, _DWORD, _DWORD))this->m_pStoreManager->baseclass_0.vfptr[1].Release)(
		this->m_pStoreManager,
		this,
		topPathLevel,
		NameBuffer))
	{
		pSubstorage = (IStore *)this->m_pStoreManager->baseclass_0.vfptr[2].QueryInterface(
			(IUnknown *)this->m_pStoreManager,
			(_GUID *)this,
			(void **)NameBuffer);
		if (pSubstorage)
		{
			((void(__stdcall *)(IStoreHierarchy *, IStore *, _DWORD))this->baseclass_0.baseclass_4.baseclass_0.vfptr[1].AddRef)(
				&this->baseclass_0.baseclass_4,
				pSubstorage,
				topPathLevel);
		LABEL_49:
			cFilePath::_cFilePath(&AnchoredSubpath);
		LABEL_50:
			if (strlen(pathRest))
			{
				v10 = (IStore *)((int(__stdcall *)(IStore *, const char *, int))pSubstorage->baseclass_0.vfptr[2].AddRef)(
					pSubstorage,
					pathRest,
					bCreate);
				pSubstorage->baseclass_0.vfptr->Release((IUnknown *)pSubstorage);
				result = v10;
			}
			else
			{
				result = pSubstorage;
			}
			return result;
		}
		v20 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 399);
		if (v20)
		{
			cNamedStorage::cNamedStorage((cNamedStorage *)v20, topPathLevel);
			v14 = v6;
		}
		else
		{
			v14 = 0;
		}
		pSubEntry = (cNamedStorage *)v14;
		cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Insert(
			&this->m_pSubstorageTable->baseclass_0.baseclass_0,
			(cNamedStorage *)v14);
		cFilePath::_cFilePath(&AnchoredSubpath);
		result = 0;
	}
	else
	{
		if (bCreate)
		{
			v19 = j__new(0x2Cu, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 408);
			if (v19)
			{
				cDirectoryStorage::cDirectoryStorage((cDirectoryStorage *)v19, topPathLevel);
				v13 = v7;
			}
			else
			{
				v13 = 0;
			}
			(*(void(__stdcall **)(int, cDirectoryStorage *))(*(_DWORD *)(v13 + 4) + 20))(v13 + 4, this);
			pSubstorage = (IStore *)v13;
			v18 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 411);
			if (v18)
			{
				cNamedStorage::cNamedStorage((cNamedStorage *)v18, pSubstorage);
				v12 = v8;
			}
			else
			{
				v12 = 0;
			}
			pSubEntry = (cNamedStorage *)v12;
			cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Insert(
				&this->m_pSubstorageTable->baseclass_0.baseclass_0,
				(cNamedStorage *)v12);
			goto LABEL_49;
		}
		v17 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 415);
		if (v17)
		{
			cNamedStorage::cNamedStorage((cNamedStorage *)v17, topPathLevel);
			v11 = v9;
		}
		else
		{
			v11 = 0;
		}
		pSubEntry = (cNamedStorage *)v11;
		cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Insert(
			&this->m_pSubstorageTable->baseclass_0.baseclass_0,
			(cNamedStorage *)v11);
		cFilePath::_cFilePath(&AnchoredSubpath);
		result = 0;
	}
	return result;
}

//----- (008EE711) --------------------------------------------------------
IStore *__stdcall cDirectoryStorage::GetParent(cDirectoryStorage *this)
{
	if (this->m_pParent)
		this->m_pParent->baseclass_0.vfptr->AddRef((IUnknown *)this->m_pParent);
	return this->m_pParent;
}

//----- (008EE739) --------------------------------------------------------
void __stdcall cDirectoryStorage::Refresh(cDirectoryStorage *this, int bRecurse)
{
	cNamedStorage *pSubstorage; // [sp+18h] [bp-14h]@6
	tHashSetHandle hs; // [sp+1Ch] [bp-10h]@1
	cNamedStream *pStream; // [sp+28h] [bp-4h]@1

	for (pStream = cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::GetFirst(
		&this->m_pStreamTable->baseclass_0.baseclass_0,
		&hs);
	pStream;
	pStream = cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::GetNext(
		&this->m_pStreamTable->baseclass_0.baseclass_0,
		&hs))
	{
		cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::Remove(
			&this->m_pStreamTable->baseclass_0.baseclass_0,
			pStream);
		if (pStream)
			cNamedStream::_scalar_deleting_destructor_(pStream, 1u);
	}
	for (pSubstorage = cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::GetFirst(
		&this->m_pSubstorageTable->baseclass_0.baseclass_0,
		&hs);
	pSubstorage;
	pSubstorage = cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::GetNext(
		&this->m_pSubstorageTable->baseclass_0.baseclass_0,
		&hs))
	{
		if (bRecurse && pSubstorage->m_pStore)
			((void(__stdcall *)(IStore *, int))pSubstorage->m_pStore->baseclass_0.vfptr[3].QueryInterface)(
			pSubstorage->m_pStore,
			bRecurse);
		cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Remove(
			&this->m_pSubstorageTable->baseclass_0.baseclass_0,
			pSubstorage);
		if (pSubstorage)
			cNamedStorage::_scalar_deleting_destructor_(pSubstorage, 1u);
	}
	this->m_Exists = 2;
}

//----- (008EE837) --------------------------------------------------------
int __stdcall cDirectoryStorage::Exists(cDirectoryStorage *this)
{
	if (this->m_Exists == 2)
	{
		if (!this->m_pFilePath)
			return 1;
		if (this->m_pParent->baseclass_0.vfptr[3].AddRef((IUnknown *)this->m_pParent))
		{
			if (cFilePath::PathExists(this->m_pFilePath))
				this->m_Exists = 0;
			else
				this->m_Exists = this->m_pName[1] != 58;
		}
		else
		{
			this->m_Exists = 1;
		}
	}
	return this->m_Exists == 0;
}

//----- (008EE8C5) --------------------------------------------------------
int __stdcall cDirectoryStorage::StreamExists(cDirectoryStorage *this, const char *pName)
{
	int result; // eax@3
	void *v3; // eax@10
	void *v4; // [sp+0h] [bp-20h]@10
	void *v5; // [sp+4h] [bp-1Ch]@9
	char v6; // [sp+8h] [bp-18h]@8
	cFileSpec FileSpec; // [sp+10h] [bp-10h]@7
	cNamedStream *pEntry; // [sp+18h] [bp-8h]@4
	int bExists; // [sp+1Ch] [bp-4h]@7

	if (this->m_pFilePath && pName)
	{
		pEntry = cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::Search(
			&this->m_pStreamTable->baseclass_0.baseclass_0,
			pName);
		if (pEntry)
		{
			result = pEntry->m_bExists;
		}
		else
		{
			if (this->m_pFilePath)
			{
				cFileSpec::cFileSpec(&FileSpec, this->m_pFilePath, pName);
				bExists = cFileSpec::FileExists(&FileSpec);
				cFileSpec::_cFileSpec(&FileSpec);
			}
			else
			{
				cFileSpec::cFileSpec((cFileSpec *)&v6, pName);
				bExists = cFileSpec::FileExists((cFileSpec *)&v6);
				cFileSpec::_cFileSpec((cFileSpec *)&v6);
			}
			v5 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 552);
			if (v5)
			{
				cNamedStream::cNamedStream((cNamedStream *)v5, pName, bExists);
				v4 = v3;
			}
			else
			{
				v4 = 0;
			}
			pEntry = (cNamedStream *)v4;
			cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::Insert(
				&this->m_pStreamTable->baseclass_0.baseclass_0,
				(cNamedStream *)v4);
			result = bExists;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008EE9AB) --------------------------------------------------------
IStoreStream *__stdcall cDirectoryStorage::OpenStream(cDirectoryStorage *this, const char *pName, unsigned int __formal)
{
	IStoreStream *result; // eax@2
	IStoreStream *v4; // eax@6
	IStoreStream *v5; // [sp+0h] [bp-Ch]@6
	void *v6; // [sp+4h] [bp-8h]@5

	if (pName)
	{
		if (((int(__stdcall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.vfptr[3].Release)(this, pName))
		{
			v6 = j__new(0x1Cu, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 573);
			if (v6)
			{
				cFileStream::cFileStream((cFileStream *)v6, &this->baseclass_0.baseclass_0);
				v5 = v4;
			}
			else
			{
				v5 = 0;
			}
			((void(__stdcall *)(_DWORD, _DWORD))v5->baseclass_0.vfptr[1].QueryInterface)(v5, pName);
			if (v5->baseclass_0.vfptr[1].AddRef((IUnknown *)v5))
			{
				result = v5;
			}
			else
			{
				v5->baseclass_0.vfptr->Release((IUnknown *)v5);
				result = 0;
			}
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

//----- (008EEA4A) --------------------------------------------------------
void *__stdcall cDirectoryStorage::BeginContents(cDirectoryStorage *this, const char *pPattern, unsigned int fFlags)
{
	int v3; // eax@2
	size_t v4; // eax@5
	int v6; // [sp+0h] [bp-Ch]@2
	void *v7; // [sp+4h] [bp-8h]@1

	v7 = j__new(0x14u, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 598);
	if (v7)
	{
		sDirState::sDirState((sDirState *)v7);
		v6 = v3;
	}
	else
	{
		v6 = 0;
	}
	*(_DWORD *)v6 = 1;
	*(_DWORD *)(v6 + 4) = fFlags;
	if (pPattern)
	{
		v4 = strlen(pPattern);
		*(_DWORD *)(v6 + 8) = MallocSpew(v4 + 1, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 602);
		strcpy(*(char **)(v6 + 8), pPattern);
	}
	else
	{
		*(_DWORD *)(v6 + 8) = 0;
	}
	return (void *)v6;
}

//----- (008EEAEF) --------------------------------------------------------
int __stdcall cDirectoryStorage::Next(cDirectoryStorage *this, void *pCookie, char *foundName)
{
	int v3; // ST0C_4@14
	cFilePath FoundPath; // [sp+4h] [bp-20h]@1
	cFileSpec FoundFile; // [sp+10h] [bp-14h]@1
	int bContinue; // [sp+18h] [bp-Ch]@3
	const char *pName; // [sp+1Ch] [bp-8h]@11
	void *pState; // [sp+20h] [bp-4h]@1

	pState = pCookie;
	cFilePath::cFilePath(&FoundPath);
	cFileSpec::cFileSpec(&FoundFile);
	if (*(_DWORD *)pState)
	{
		if (*((_DWORD *)pState + 1) & 2)
			bContinue = cFilePath::FindFirst(this->m_pFilePath, &FoundPath, (sFindContext *)((char *)pState + 12));
		else
			bContinue = cFilePath::FindFirst(
			this->m_pFilePath,
			&FoundFile,
			(sFindContext *)((char *)pState + 12),
			*((const char **)pState + 2));
		*(_DWORD *)pState = 0;
	}
	else
	{
		if (*((_DWORD *)pState + 1) & 2)
			bContinue = cFilePath::FindNext(this->m_pFilePath, &FoundPath, (sFindContext *)((char *)pState + 12));
		else
			bContinue = cFilePath::FindNext(this->m_pFilePath, &FoundFile, (sFindContext *)((char *)pState + 12));
	}
	if (bContinue)
	{
		if (*((_DWORD *)pState + 1) & 2)
			pName = cFilePath::GetPathName(&FoundPath);
		else
			pName = cFileSpec::GetFileName(&FoundFile);
		strcpy(foundName, pName);
	}
	v3 = bContinue;
	cFileSpec::_cFileSpec(&FoundFile);
	cFilePath::_cFilePath(&FoundPath);
	return v3;
}

//----- (008EEC01) --------------------------------------------------------
void __stdcall cDirectoryStorage::EndContents(cDirectoryStorage *this, void *pCookie)
{
	if (*((_DWORD *)pCookie + 2))
		FreeSpew(*((void **)pCookie + 2), "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 661);
	operator delete(pCookie);
}

//----- (008EEC47) --------------------------------------------------------
void __stdcall cDirectoryStorage::GetCanonPath(cDirectoryStorage *this, char **ppCanonPath)
{
	size_t v2; // esi@4
	size_t v3; // eax@4
	const char *pCanonPath; // [sp+4h] [bp-8h]@4
	const char *pName; // [sp+8h] [bp-4h]@4

	if (this->m_pParent && !(this->m_fFlags & 1))
	{
		((void(__stdcall *)(_DWORD, _DWORD))this->m_pParent->baseclass_0.vfptr[5].AddRef)(this->m_pParent, &pCanonPath);
		pName = (const char *)((int(__stdcall *)(_DWORD))this->baseclass_0.baseclass_0.baseclass_0.vfptr[1].QueryInterface)(this);
		v2 = strlen(pCanonPath);
		v3 = strlen(pName);
		*ppCanonPath = (char *)ReallocSpew(
			(void *)pCanonPath,
			v2 + v3 + 1,
			"x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp",
			686);
		strcat(*ppCanonPath, pName);
	}
	else
	{
		*ppCanonPath = (char *)MallocSpew(1u, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 678);
		**ppCanonPath = 0;
	}
}

//----- (008EECFF) --------------------------------------------------------
void __stdcall cDirectoryStorage::RegisterSubstorage(cDirectoryStorage *this, IStore *pSubstore, const char *pName)
{
	void *v3; // eax@6
	void *v4; // [sp+0h] [bp-20h]@6
	void *v5; // [sp+8h] [bp-18h]@5
	void *pSubstoreHier; // [sp+14h] [bp-Ch]@8
	cNamedStorage *pOldSubstore; // [sp+18h] [bp-8h]@1
	void *pStoreEntry; // [sp+1Ch] [bp-4h]@8

	pOldSubstore = cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Search(
		(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *)this->m_pParent,
		pName);
	if (pOldSubstore)
	{
		if (pSubstore == pOldSubstore->m_pStore)
			return;
		cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Remove(
			(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *)this->m_pParent,
			pOldSubstore);
		if (pOldSubstore)
			cNamedStorage::_scalar_deleting_destructor_(pOldSubstore, 1u);
	}
	v5 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 711);
	if (v5)
	{
		cNamedStorage::cNamedStorage((cNamedStorage *)v5, pSubstore);
		v4 = v3;
	}
	else
	{
		v4 = 0;
	}
	pStoreEntry = v4;
	cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Insert(
		(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *)this->m_pParent,
		(cNamedStorage *)v4);
	if (pSubstore->baseclass_0.vfptr->QueryInterface((IUnknown *)pSubstore, &IID_IStoreHierarchy, &pSubstoreHier) >= 0)
	{
		(*(void(__stdcall **)(void *, char *))(*(_DWORD *)pSubstoreHier + 20))(pSubstoreHier, (char *)this - 4);
		(*(void(__stdcall **)(void *))(*(_DWORD *)pSubstoreHier + 8))(pSubstoreHier);
	}
}

//----- (008EEDEA) --------------------------------------------------------
void __stdcall cDirectoryStorage::SetParent(cDirectoryStorage *this, IStore *pNewParent)
{
	unsigned int v2; // eax@7
	unsigned int v3; // eax@11
	unsigned int v4; // [sp+0h] [bp-20h]@11
	unsigned int v5; // [sp+4h] [bp-1Ch]@7
	void *v6; // [sp+8h] [bp-18h]@10
	void *v7; // [sp+Ch] [bp-14h]@6
	const char *pParentName; // [sp+10h] [bp-10h]@5
	cFilePath LocalPath; // [sp+14h] [bp-Ch]@5

	if (this->m_pName)
		(*(void(__stdcall **)(char *))(*(_DWORD *)this->m_pName + 8))(this->m_pName);
	this->m_pName = (char *)pNewParent;
	if (this->m_pName)
	{
		(*(void(__stdcall **)(char *))(*(_DWORD *)this->m_pName + 4))(this->m_pName);
		if (this->m_pFilePath)
		{
			pParentName = (const char *)(*(int(__stdcall **)(char *))(*(_DWORD *)this->m_pName + 16))(this->m_pName);
			cFilePath::cFilePath(&LocalPath, (const char *)&this->m_pFilePath->m_path.m_pchData);
			if (pParentName)
			{
				v7 = j__new(0xCu, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 741);
				if (v7)
				{
					cFilePath::cFilePath((cFilePath *)v7, pParentName);
					v5 = v2;
				}
				else
				{
					v5 = 0;
				}
				this->baseclass_0.m_ulRefs = v5;
				cFilePath::AddRelativePath((cFilePath *)this->baseclass_0.m_ulRefs, &LocalPath);
			}
			else
			{
				v6 = j__new(0xCu, "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 746);
				if (v6)
				{
					cFilePath::cFilePath((cFilePath *)v6, &LocalPath);
					v4 = v3;
				}
				else
				{
					v4 = 0;
				}
				this->baseclass_0.m_ulRefs = v4;
			}
			cFilePath::MakeFullPath((cFilePath *)this->baseclass_0.m_ulRefs);
			cFilePath::_cFilePath(&LocalPath);
		}
	}
}

//----- (008EEF10) --------------------------------------------------------
void __stdcall cDirectoryStorage::SetStoreManager(cDirectoryStorage *this, IStoreManager *pMan)
{
	if (this->m_Exists)
		(*(void(__stdcall **)(_DWORD))(*(_DWORD *)this->m_Exists + 8))(this->m_Exists);
	this->m_Exists = (eExistenceState)pMan;
	if (this->m_Exists)
		(*(void(__stdcall **)(_DWORD))(*(_DWORD *)this->m_Exists + 4))(this->m_Exists);
}

//----- (008EEF56) --------------------------------------------------------
void __stdcall cDirectoryStorage::SetDataStream(cDirectoryStorage *this, IStoreStream *__formal)
{
	_CriticalMsg("cDirectoryStorage::SetDataStream called!", "x:\\prj\\tech\\libsrc\\namedres\\storedir.cpp", 0x308u);
}

//----- (008EEF71) --------------------------------------------------------
void __stdcall cDirectoryStorage::DeclareContextRoot(cDirectoryStorage *this, int bIsRoot)
{
	if (bIsRoot)
		this->m_pStoreManager = (IStoreManager *)((unsigned int)this->m_pStoreManager | 1);
	else
		this->m_pStoreManager = (IStoreManager *)((unsigned int)this->m_pStoreManager & 0xFFFFFFFE);
}

//----- (008EEF9E) --------------------------------------------------------
void __stdcall cDirectoryStorage::Close(cDirectoryStorage *this)
{
	tHashSetHandle h; // [sp+Ch] [bp-14h]@2
	cNamedStorage *pEntry; // [sp+18h] [bp-8h]@2
	void *pHier; // [sp+1Ch] [bp-4h]@5

	if (this->m_pParent)
	{
		for (pEntry = cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::GetFirst(
			(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *)this->m_pParent,
			&h);
		pEntry;
		pEntry = cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::GetNext(
			(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *)this->m_pParent,
			&h))
		{
			cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Remove(
				(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *)this->m_pParent,
				pEntry);
			if (pEntry->m_pStore
				&& pEntry->m_pStore->baseclass_0.vfptr->QueryInterface(
				(IUnknown *)pEntry->m_pStore,
				&IID_IStoreHierarchy,
				&pHier) >= 0)
			{
				(*(void(__stdcall **)(void *))(*(_DWORD *)pHier + 32))(pHier);
				(*(void(__stdcall **)(void *))(*(_DWORD *)pHier + 8))(pHier);
			}
			if (pEntry)
				cNamedStorage::_scalar_deleting_destructor_(pEntry, 1u);
		}
	}
}

//----- (008EF060) --------------------------------------------------------
void *__thiscall cDirectoryStorage::_vector_deleting_destructor_(cDirectoryStorage *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cDirectoryStorage::_cDirectoryStorage(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008EF090) --------------------------------------------------------
void __thiscall sFindContext::sFindContext(sFindContext *this)
{
	sFindContext *v1; // ST00_4@1

	v1 = this;
	sFileFind::sFileFind(&this->PlatformFindContext);
	v1->Finding = 0;
}

//----- (008EF0B0) --------------------------------------------------------
void __thiscall sFileFind::sFileFind(sFileFind *this)
{
	this->hContext = 0;
}

//----- (008EF0D0) --------------------------------------------------------
void __thiscall sDirState::sDirState(sDirState *this)
{
	sFindContext::sFindContext(&this->FC);
}

