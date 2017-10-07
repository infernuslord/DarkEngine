//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>






//----- (008EC1F0) --------------------------------------------------------
void __thiscall cNamedZipStream::cNamedZipStream(cNamedZipStream *this, const char *pName, unsigned int nCompressedSize, unsigned int nUncompressedSize, unsigned int nHeaderOffset, unsigned __int16 nCompressionMethod)
{
	cNamedZipStream *v6; // ST08_4@1

	v6 = this;
	cNamedStream::cNamedStream(&this->baseclass_0, pName, 1);
	v6->m_nCompressedSize = nCompressedSize;
	v6->m_nUncompressedSize = nUncompressedSize;
	v6->m_nHeaderOffset = nHeaderOffset;
	v6->m_nCompressionMethod = nCompressionMethod;
}

//----- (008EC234) --------------------------------------------------------
void __thiscall cZipSubstorage::cZipSubstorage(cZipSubstorage *this, IStore *pParent, const char *pRawName)
{
	size_t v3; // eax@2
	cStorageHashByName *v4; // eax@4
	cStreamHashByName *v5; // eax@7
	cStreamHashByName *v6; // [sp+0h] [bp-18h]@7
	cStorageHashByName *v7; // [sp+4h] [bp-14h]@4
	cZipSubstorage *thisa; // [sp+8h] [bp-10h]@1
	void *v9; // [sp+Ch] [bp-Ch]@6
	void *v10; // [sp+10h] [bp-8h]@3
	const char *pName; // [sp+14h] [bp-4h]@2

	thisa = this;
	cStorageBase::cStorageBase(&this->baseclass_0);
	thisa->m_pFilePath = 0;
	thisa->m_pName = 0;
	thisa->m_pParent = 0;
	thisa->m_pSubstorageTable = 0;
	thisa->m_pStreamTable = 0;
	thisa->m_pStoreManager = 0;
	thisa->m_fFlags = 0;
	thisa->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cZipSubstorage::_vftable_;
	thisa->baseclass_0.baseclass_4.baseclass_0.vfptr = (IUnknownVtbl *)&cZipSubstorage::_vftable_;
	if (pRawName)
	{
		GetNormalizedPath(pRawName, (char **)&pName);
		v3 = strlen(pName);
		thisa->m_pName = (char *)MallocSpew(v3 + 1, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 58);
		strcpy(thisa->m_pName, pName);
		FreeSpew((void *)pName, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 60);
	}
	v10 = j__new(0x14u, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 63);
	if (v10)
	{
		cStorageHashByName::cStorageHashByName((cStorageHashByName *)v10);
		v7 = v4;
	}
	else
	{
		v7 = 0;
	}
	thisa->m_pSubstorageTable = v7;
	v9 = j__new(0x14u, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 64);
	if (v9)
	{
		cStreamHashByName::cStreamHashByName((cStreamHashByName *)v9);
		v6 = v5;
	}
	else
	{
		v6 = 0;
	}
	thisa->m_pStreamTable = v6;
	cZipSubstorage::SetParent((cZipSubstorage *)((char *)thisa + 4), pParent);
}
// 9A8A54: using guessed type int (__stdcall *cZipSubstorage___vftable_)(int this, int, int);
// 9A8A78: using guessed type int (__stdcall *cZipSubstorage___vftable_)(int this, int id, int ppReturn);

//----- (008EC386) --------------------------------------------------------
void __thiscall cZipSubstorage::_cZipSubstorage(cZipSubstorage *this)
{
	cZipSubstorage *thisa; // [sp+10h] [bp-34h]@1
	cStreamHashByName *v2; // [sp+18h] [bp-2Ch]@19
	cStorageHashByName *v3; // [sp+28h] [bp-1Ch]@10
	cFilePath *v4; // [sp+30h] [bp-14h]@4
	tHashSetHandle h; // [sp+34h] [bp-10h]@14
	cNamedStream *pEntry; // [sp+40h] [bp-4h]@14

	thisa = this;
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cZipSubstorage::_vftable_;
	this->baseclass_0.baseclass_4.baseclass_0.vfptr = (IUnknownVtbl *)&cZipSubstorage::_vftable_;
	if (this->m_pName)
	{
		FreeSpew(this->m_pName, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 72);
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
// 9A8A54: using guessed type int (__stdcall *cZipSubstorage___vftable_)(int this, int, int);
// 9A8A78: using guessed type int (__stdcall *cZipSubstorage___vftable_)(int this, int id, int ppReturn);

//----- (008EC548) --------------------------------------------------------
const char *__stdcall cZipSubstorage::GetName(cZipSubstorage *this)
{
	return this->m_pName;
}

//----- (008EC555) --------------------------------------------------------
const char *__stdcall cZipSubstorage::GetFullPathName(cZipSubstorage *this)
{
	const char *result; // eax@2

	if (this->m_pFilePath)
		result = cFilePath::GetPathName(this->m_pFilePath);
	else
		result = 0;
	return result;
}

//----- (008EC574) --------------------------------------------------------
int __thiscall cZipSubstorage::EnumerateLevelHelper(cZipSubstorage *this, const char *pSubpath, IStore *pSubstore, int(__cdecl *Callback)(IStore *, const char *, void *), int bAbsolute, void *pClientData)
{
	const char *v6; // eax@1
	int v7; // ST10_4@4
	cZipSubstorage *thisa; // [sp+0h] [bp-30h]@1
	cFilePath MyPath; // [sp+8h] [bp-28h]@2
	cFilePath SubPath; // [sp+14h] [bp-1Ch]@1
	const char *pName; // [sp+20h] [bp-10h]@2
	cFilePath TopPath; // [sp+24h] [bp-Ch]@1

	thisa = this;
	v6 = (const char *)((int(__stdcall *)(IStore *))pSubstore->baseclass_0.vfptr[1].QueryInterface)(pSubstore);
	cFilePath::cFilePath(&TopPath, v6);
	cFilePath::cFilePath(&SubPath, pSubpath);
	cFilePath::AddRelativePath(&TopPath, &SubPath);
	if (bAbsolute)
	{
		cFilePath::cFilePath(&MyPath, thisa->m_pFilePath);
		cFilePath::AddRelativePath(&MyPath, &TopPath);
		cFilePath::MakeFullPath(&MyPath);
		pName = cFilePath::GetPathName(&MyPath);
		cFilePath::_cFilePath(&MyPath);
	}
	else
	{
		pName = cFilePath::GetPathName(&TopPath);
	}
	v7 = Callback(&thisa->baseclass_0.baseclass_0, pName, pClientData);
	cFilePath::_cFilePath(&SubPath);
	cFilePath::_cFilePath(&TopPath);
	return v7;
}

//----- (008EC621) --------------------------------------------------------
int __cdecl EnumerateLevelCallback(IStore *pSubstore, const char *pSubpath, void *pClientData)
{
	return cZipSubstorage::EnumerateLevelHelper(
		*((cZipSubstorage **)pClientData + 2),
		pSubpath,
		pSubstore,
		*((int(__cdecl **)(IStore *, const char *, void *))pClientData + 1),
		*((_DWORD *)pClientData + 3),
		*(void **)pClientData);
}

//----- (008EC65E) --------------------------------------------------------
void __stdcall cZipSubstorage::EnumerateLevel(cZipSubstorage *this, int(__cdecl *Callback)(IStore *, const char *, void *), int bAbsolute, int bRecurse, void *pClientData)
{
	sEnumLevelEnvelope Envelope; // [sp+0h] [bp-3Ch]@8
	cFilePath SubPath; // [sp+10h] [bp-2Ch]@4
	cFilePath FullPath; // [sp+1Ch] [bp-20h]@4
	tHashSetHandle hsh; // [sp+28h] [bp-14h]@1
	cNamedStorage *pEntry; // [sp+34h] [bp-8h]@1
	const char *pName; // [sp+38h] [bp-4h]@4

	for (pEntry = cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::GetFirst(
		&this->m_pSubstorageTable->baseclass_0.baseclass_0,
		&hsh);
	pEntry;
	pEntry = cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::GetNext(
		&this->m_pSubstorageTable->baseclass_0.baseclass_0,
		&hsh))
	{
		if (bAbsolute)
		{
			cFilePath::cFilePath(&FullPath, this->m_pFilePath);
			cFilePath::cFilePath(&SubPath, pEntry->m_pName);
			cFilePath::AddRelativePath(&FullPath, &SubPath);
			cFilePath::MakeFullPath(&FullPath);
			pName = cFilePath::GetPathName(&FullPath);
			cFilePath::_cFilePath(&SubPath);
			cFilePath::_cFilePath(&FullPath);
		}
		else
		{
			pName = pEntry->m_pName;
		}
		if (Callback(&this->baseclass_0.baseclass_0, pName, pClientData))
		{
			if (bRecurse)
			{
				Envelope.pRealClientData = pClientData;
				Envelope.Callback = Callback;
				Envelope.pStore = this;
				Envelope.bAbsolute = bAbsolute;
				((void(__stdcall *)(IStore *, int(__cdecl *)(IStore *, const char *, void *), _DWORD, signed int, sEnumLevelEnvelope *))pEntry->m_pStore->baseclass_0.vfptr[1].Release)(
					pEntry->m_pStore,
					EnumerateLevelCallback,
					0,
					1,
					&Envelope);
			}
		}
	}
}

//----- (008EC74E) --------------------------------------------------------
int __thiscall cZipSubstorage::EnumerateStreamsHelper(cZipSubstorage *this, const char *pSubpath, IStore *pSubstore, int(__cdecl *Callback)(IStore *, const char *, void *), int bAbsolute, void *pClientData)
{
	const char *v6; // eax@1
	int v7; // ST10_4@4
	cZipSubstorage *thisa; // [sp+0h] [bp-2Ch]@1
	cFileSpec FileSpec; // [sp+8h] [bp-24h]@1
	cAnsiStr Name; // [sp+10h] [bp-1Ch]@1
	const char *pName; // [sp+1Ch] [bp-10h]@4
	cFilePath TopPath; // [sp+20h] [bp-Ch]@1

	thisa = this;
	cAnsiStr::cAnsiStr(&Name);
	v6 = (const char *)((int(__stdcall *)(IStore *))pSubstore->baseclass_0.vfptr[1].QueryInterface)(pSubstore);
	cFilePath::cFilePath(&TopPath, v6);
	cFileSpec::cFileSpec(&FileSpec, &TopPath, pSubpath);
	if (bAbsolute)
		cFileSpec::GetNameString(&FileSpec, &Name, thisa->m_pFilePath);
	else
		cFileSpec::GetNameString(&FileSpec, &Name, kAnchorRelativeNameStyle);
	pName = cAnsiStr::operator char_const__(&Name);
	v7 = Callback(&thisa->baseclass_0.baseclass_0, pName, pClientData);
	cFileSpec::_cFileSpec(&FileSpec);
	cFilePath::_cFilePath(&TopPath);
	cAnsiStr::_cAnsiStr(&Name);
	return v7;
}

//----- (008EC7EE) --------------------------------------------------------
int __cdecl EnumerateStreamsCallback(IStore *pSubstore, const char *pSubpath, void *pClientData)
{
	return cZipSubstorage::EnumerateStreamsHelper(
		*((cZipSubstorage **)pClientData + 2),
		pSubpath,
		pSubstore,
		*((int(__cdecl **)(IStore *, const char *, void *))pClientData + 1),
		*((_DWORD *)pClientData + 3),
		*(void **)pClientData);
}

//----- (008EC82B) --------------------------------------------------------
void __stdcall cZipSubstorage::EnumerateStreams(cZipSubstorage *this, int(__cdecl *Callback)(IStore *, const char *, void *), int bAbsolute, int bRecurse, void *pClientData)
{
	sEnumStreamsEnvelope Envelope; // [sp+0h] [bp-3Ch]@12
	cFileSpec FileSpec; // [sp+10h] [bp-2Ch]@4
	tHashSetHandle hsh; // [sp+18h] [bp-24h]@1
	cAnsiStr Name; // [sp+24h] [bp-18h]@1
	const char **pStreamEntry; // [sp+30h] [bp-Ch]@1
	cNamedStorage *pStoreEntry; // [sp+34h] [bp-8h]@10
	const char *pName; // [sp+38h] [bp-4h]@6

	cAnsiStr::cAnsiStr(&Name);
	for (pStreamEntry = (const char **)cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::GetFirst(
		&this->m_pStreamTable->baseclass_0.baseclass_0,
		&hsh);
	pStreamEntry;
	pStreamEntry = (const char **)cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::GetNext(
		&this->m_pStreamTable->baseclass_0.baseclass_0,
		&hsh))
	{
		if (bAbsolute)
		{
			cFileSpec::cFileSpec(&FileSpec, *pStreamEntry);
			if (!cFileSpec::GetFullPath(&FileSpec, &Name, this->m_pFilePath))
				_CriticalMsg(
				"cZipSubstorage::EnumerateStreams -- no fullpath",
				"x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp",
				0x144u);
			pName = cAnsiStr::operator char_const__(&Name);
			cFileSpec::_cFileSpec(&FileSpec);
		}
		else
		{
			pName = *pStreamEntry;
		}
		Callback(&this->baseclass_0.baseclass_0, pName, pClientData);
	}
	if (bRecurse)
	{
		for (pStoreEntry = cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::GetFirst(
			&this->m_pSubstorageTable->baseclass_0.baseclass_0,
			&hsh);
		pStoreEntry;
		pStoreEntry = cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::GetNext(
			&this->m_pSubstorageTable->baseclass_0.baseclass_0,
			&hsh))
		{
			Envelope.pRealClientData = pClientData;
			Envelope.Callback = Callback;
			Envelope.pStore = this;
			Envelope.bAbsolute = bAbsolute;
			((void(__stdcall *)(IStore *, int(__cdecl *)(IStore *, const char *, void *), _DWORD, signed int, sEnumStreamsEnvelope *))pStoreEntry->m_pStore->baseclass_0.vfptr[2].QueryInterface)(
				pStoreEntry->m_pStore,
				EnumerateStreamsCallback,
				0,
				1,
				&Envelope);
		}
	}
	cAnsiStr::_cAnsiStr(&Name);
}

//----- (008EC94F) --------------------------------------------------------
IStore *__stdcall cZipSubstorage::GetSubstorage(cZipSubstorage *this, const char *pSubPath, int bCreate)
{
	IStore *result; // eax@3
	void *v4; // eax@17
	IStore *v5; // ST18_4@24
	void *v6; // [sp+0h] [bp-58h]@17
	void *v7; // [sp+4h] [bp-54h]@16
	char NameBuffer[32]; // [sp+Ch] [bp-4Ch]@14
	cNamedStorage *pSubEntry; // [sp+2Ch] [bp-2Ch]@4
	IStore *pSubstorage; // [sp+30h] [bp-28h]@5
	char topPathLevel[32]; // [sp+34h] [bp-24h]@4
	const char *pathRest; // [sp+54h] [bp-4h]@4

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
			_CriticalMsg("NULL substorage in Zip file?!?", "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 0x189u);
		pSubstorage->baseclass_0.vfptr->AddRef((IUnknown *)pSubstorage);
	}
	else
	{
		if (strcmp(topPathLevel, "..\\"))
		{
			if (strcmp(topPathLevel, ".\\"))
			{
				if (!((int(__stdcall *)(IStoreManager *, cZipSubstorage *, _DWORD, _DWORD))this->m_pStoreManager->baseclass_0.vfptr[1].Release)(
					this->m_pStoreManager,
					this,
					topPathLevel,
					NameBuffer))
					return 0;
				pSubstorage = (IStore *)this->m_pStoreManager->baseclass_0.vfptr[2].QueryInterface(
					(IUnknown *)this->m_pStoreManager,
					(_GUID *)this,
					(void **)NameBuffer);
				if (!pSubstorage)
					return 0;
				v7 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 421);
				if (v7)
				{
					cNamedStorage::cNamedStorage((cNamedStorage *)v7, pSubstorage);
					v6 = v4;
				}
				else
				{
					v6 = 0;
				}
				pSubEntry = (cNamedStorage *)v6;
				cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Insert(
					&this->m_pSubstorageTable->baseclass_0.baseclass_0,
					(cNamedStorage *)v6);
			}
			else
			{
				pSubstorage = (IStore *)this;
				this->baseclass_0.baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)this);
			}
		}
		else
		{
			if (!this->m_pParent)
				return 0;
			pSubstorage = this->m_pParent;
			pSubstorage->baseclass_0.vfptr->AddRef((IUnknown *)pSubstorage);
		}
	}
	if (strlen(pathRest))
	{
		v5 = (IStore *)((int(__stdcall *)(IStore *, const char *, int))pSubstorage->baseclass_0.vfptr[2].AddRef)(
			pSubstorage,
			pathRest,
			bCreate);
		pSubstorage->baseclass_0.vfptr->Release((IUnknown *)pSubstorage);
		result = v5;
	}
	else
	{
		result = pSubstorage;
	}
	return result;
}

//----- (008ECB22) --------------------------------------------------------
void __thiscall cZipSubstorage::SetTopZip(cZipSubstorage *this, cZipStorage *pStorage)
{
	cZipSubstorage *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (!pStorage)
		_CriticalMsg(
		"cZipSubstorage::SetTopZip -- empty pStorage!",
		"x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp",
		0x1C9u);
	thisa->m_pZipStorage = pStorage;
}

//----- (008ECB5A) --------------------------------------------------------
cZipSubstorage *__thiscall cZipSubstorage::MakeSubstorage(cZipSubstorage *this, const char *pSubPath)
{
	cZipSubstorage *v2; // eax@8
	cNamedStorage *v3; // eax@11
	cZipSubstorage *result; // eax@15
	cNamedStorage *v5; // [sp+0h] [bp-40h]@11
	cZipSubstorage *v6; // [sp+4h] [bp-3Ch]@8
	cZipSubstorage *thisa; // [sp+8h] [bp-38h]@1
	void *v8; // [sp+Ch] [bp-34h]@10
	void *v9; // [sp+10h] [bp-30h]@7
	cNamedStorage *pSubEntry; // [sp+14h] [bp-2Ch]@5
	void *pSubstorage; // [sp+18h] [bp-28h]@6
	char topPathLevel[32]; // [sp+1Ch] [bp-24h]@5
	const char *pathRest; // [sp+3Ch] [bp-4h]@5

	thisa = this;
	if (!pSubPath)
		_CriticalMsg("cZipStorage::MakeSubstorage -- null subpath", "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 0x1DAu);
	if (!strlen(pSubPath))
		_CriticalMsg(
		"cZipStorage::MakeSubstorage -- empty subpath",
		"x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp",
		0x1DCu);
	GetPathTop(pSubPath, topPathLevel, &pathRest);
	pSubEntry = cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Search(
		&thisa->m_pSubstorageTable->baseclass_0.baseclass_0,
		topPathLevel);
	if (pSubEntry)
	{
		pSubstorage = pSubEntry->m_pStore;
	}
	else
	{
		v9 = j__new(0x2Cu, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 490);
		if (v9)
		{
			cZipSubstorage::cZipSubstorage((cZipSubstorage *)v9, &thisa->baseclass_0.baseclass_0, topPathLevel);
			v6 = v2;
		}
		else
		{
			v6 = 0;
		}
		pSubstorage = v6;
		cZipSubstorage::SetTopZip(v6, thisa->m_pZipStorage);
		(*(void(__stdcall **)(char *, IStoreManager *))(*((_DWORD *)pSubstorage + 1) + 12))(
			(char *)pSubstorage + 4,
			thisa->m_pStoreManager);
		v8 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 493);
		if (v8)
		{
			cNamedStorage::cNamedStorage((cNamedStorage *)v8, &v6->baseclass_0.baseclass_0);
			v5 = v3;
		}
		else
		{
			v5 = 0;
		}
		v6->baseclass_0.baseclass_0.baseclass_0.vfptr->Release((IUnknown *)v6);
		cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Insert(
			&thisa->m_pSubstorageTable->baseclass_0.baseclass_0,
			v5);
	}
	if (strlen(pathRest))
	{
		result = cZipSubstorage::MakeSubstorage((cZipSubstorage *)pSubstorage, pathRest);
	}
	else
	{
		(*(void(__stdcall **)(void *))(*(_DWORD *)pSubstorage + 4))(pSubstorage);
		result = (cZipSubstorage *)pSubstorage;
	}
	return result;
}

//----- (008ECCD8) --------------------------------------------------------
IStore *__stdcall cZipSubstorage::GetParent(cZipSubstorage *this)
{
	if (!this->m_pParent)
		_CriticalMsg("ZipSubstorage with no parent!", "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 0x207u);
	this->m_pParent->baseclass_0.vfptr->AddRef((IUnknown *)this->m_pParent);
	return this->m_pParent;
}

//----- (008ECD1C) --------------------------------------------------------
void __stdcall cZipSubstorage::Refresh(cZipSubstorage *this, int __formal)
{
	;
}

//----- (008ECD23) --------------------------------------------------------
int __stdcall cZipSubstorage::Exists(cZipSubstorage *this)
{
	return 1;
}

//----- (008ECD2F) --------------------------------------------------------
int __stdcall cZipSubstorage::StreamExists(cZipSubstorage *this, const char *pName)
{
	int result; // eax@4

	if (!pName)
		_CriticalMsg("cZipSubstorage::StreamExists -- null name!", "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 0x228u);
	if (cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::Search(
		&this->m_pStreamTable->baseclass_0.baseclass_0,
		pName))
		result = 1;
	else
		result = 0;
	return result;
}

//----- (008ECD74) --------------------------------------------------------
void __thiscall cZipSubstorage::AddStream(cZipSubstorage *this, const char *pName, sDirFileRecord *pDirRecord)
{
	cNamedStream *v3; // eax@6
	cNamedStream *v4; // [sp+0h] [bp-10h]@6
	cZipSubstorage *thisa; // [sp+4h] [bp-Ch]@1
	void *v6; // [sp+8h] [bp-8h]@5

	thisa = this;
	if (!pName)
		_CriticalMsg("cZipSubstorage::AddStream -- null name!", "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 0x238u);
	if (cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::Search(
		&thisa->m_pStreamTable->baseclass_0.baseclass_0,
		pName))
		_CriticalMsg(
		"cZipSubstorage::AddStream -- adding duplicate stream!",
		"x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp",
		0x23Au);
	v6 = j__new(0x16u, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 572);
	if (v6)
	{
		cNamedZipStream::cNamedZipStream(
			(cNamedZipStream *)v6,
			pName,
			pDirRecord->CompressedSize,
			pDirRecord->UncompressedSize,
			pDirRecord->HeaderOffset,
			pDirRecord->CompressionMethod);
		v4 = v3;
	}
	else
	{
		v4 = 0;
	}
	cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::Insert(
		&thisa->m_pStreamTable->baseclass_0.baseclass_0,
		v4);
}

//----- (008ECE3B) --------------------------------------------------------
IStoreStream *__stdcall cZipSubstorage::OpenStream(cZipSubstorage *this, const char *pName, unsigned int __formal)
{
	IStoreStream *result; // eax@4
	IStoreStream *v4; // eax@6
	IStoreStream *v5; // [sp+0h] [bp-10h]@6
	void *v6; // [sp+4h] [bp-Ch]@5
	cNamedStream *pStreamEntry; // [sp+8h] [bp-8h]@3

	if (!pName)
		_CriticalMsg("cZipSubstorage::OpenStream -- null pName!", "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 0x250u);
	pStreamEntry = cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::Search(
		&this->m_pStreamTable->baseclass_0.baseclass_0,
		pName);
	if (pStreamEntry)
	{
		v6 = j__new(0x24u, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 600);
		if (v6)
		{
			cZipStream::cZipStream(
				(cZipStream *)v6,
				&this->baseclass_0.baseclass_0,
				this->m_pZipStorage,
				(cNamedZipStream *)pStreamEntry);
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
	return result;
}

//----- (008ECEFE) --------------------------------------------------------
void *__stdcall cZipSubstorage::BeginContents(cZipSubstorage *this, const char *pPattern, unsigned int fFlags)
{
	size_t v3; // eax@2
	void *pState; // [sp+0h] [bp-4h]@1

	pState = MallocSpew(0x18u, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 624);
	*(_DWORD *)pState = 1;
	*((_DWORD *)pState + 1) = fFlags;
	if (pPattern)
	{
		v3 = strlen(pPattern);
		*((_DWORD *)pState + 2) = MallocSpew(v3 + 1, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 628);
		strcpy(*((char **)pState + 2), pPattern);
	}
	else
	{
		*((_DWORD *)pState + 2) = 0;
	}
	return pState;
}

//----- (008ECF81) --------------------------------------------------------
int __stdcall cZipSubstorage::Next(cZipSubstorage *this, void *pCookie, char *foundName)
{
	int result; // eax@16
	cNamedStream *v4; // [sp+0h] [bp-18h]@13
	cNamedStorage *v5; // [sp+4h] [bp-14h]@10
	cNamedStream *pStreamEntry; // [sp+8h] [bp-10h]@6
	cNamedStorage *pStoreEntry; // [sp+Ch] [bp-Ch]@3
	const char *pName; // [sp+10h] [bp-8h]@1

	pName = 0;
	if (*(_DWORD *)pCookie)
	{
		if (*((_DWORD *)pCookie + 1) & 2)
		{
			pStoreEntry = cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::GetFirst(
				&this->m_pSubstorageTable->baseclass_0.baseclass_0,
				(tHashSetHandle *)pCookie + 1);
			if (pStoreEntry)
				pName = pStoreEntry->m_pName;
		}
		else
		{
			pStreamEntry = cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::GetFirst(
				&this->m_pStreamTable->baseclass_0.baseclass_0,
				(tHashSetHandle *)pCookie + 1);
			if (pStreamEntry)
				pName = pStreamEntry->m_pName;
		}
		*(_DWORD *)pCookie = 0;
	}
	else
	{
		if (*((_DWORD *)pCookie + 1) & 2)
		{
			v5 = cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::GetNext(
				&this->m_pSubstorageTable->baseclass_0.baseclass_0,
				(tHashSetHandle *)pCookie + 1);
			if (v5)
				pName = v5->m_pName;
		}
		else
		{
			v4 = cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::GetNext(
				&this->m_pStreamTable->baseclass_0.baseclass_0,
				(tHashSetHandle *)pCookie + 1);
			if (v4)
				pName = v4->m_pName;
		}
	}
	if (pName)
	{
		strcpy(foundName, pName);
		result = 1;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008ED078) --------------------------------------------------------
void __stdcall cZipSubstorage::EndContents(cZipSubstorage *this, void *pCookie)
{
	if (*((_DWORD *)pCookie + 2))
		FreeSpew(*((void **)pCookie + 2), "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 694);
	FreeSpew(pCookie, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 696);
}

//----- (008ED0C0) --------------------------------------------------------
void __stdcall cZipSubstorage::GetCanonPath(cZipSubstorage *this, char **ppCanonPath)
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
			"x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp",
			719);
		strcat(*ppCanonPath, pName);
	}
	else
	{
		*ppCanonPath = (char *)MallocSpew(1u, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 711);
		**ppCanonPath = 0;
	}
}

//----- (008ED178) --------------------------------------------------------
void __stdcall cZipSubstorage::RegisterSubstorage(cZipSubstorage *this, IStore *pSubstore, const char *pName)
{
	void *v3; // eax@4
	void *v4; // [sp+0h] [bp-14h]@4
	void *v5; // [sp+4h] [bp-10h]@3
	void *pSubstoreHier; // [sp+8h] [bp-Ch]@6
	cNamedStorage *pOldSubstore; // [sp+Ch] [bp-8h]@1
	void *pStoreEntry; // [sp+10h] [bp-4h]@6

	pOldSubstore = cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Search(
		(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *)this->m_pZipStorage,
		pName);
	if (pOldSubstore)
		_CriticalMsg(
		"cZipSubstorage::RegisterSubstorage -- substituting...",
		"x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp",
		0x2E2u);
	v5 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 744);
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
		(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *)this->m_pZipStorage,
		(cNamedStorage *)v4);
	if (pSubstore->baseclass_0.vfptr->QueryInterface((IUnknown *)pSubstore, &IID_IStoreHierarchy, &pSubstoreHier) >= 0)
	{
		(*(void(__stdcall **)(void *, char *))(*(_DWORD *)pSubstoreHier + 20))(pSubstoreHier, (char *)this - 4);
		(*(void(__stdcall **)(void *))(*(_DWORD *)pSubstoreHier + 8))(pSubstoreHier);
	}
}

//----- (008ED239) --------------------------------------------------------
void __stdcall cZipSubstorage::SetParent(cZipSubstorage *this, IStore *pNewParent)
{
	unsigned int v2; // eax@11
	unsigned int v3; // eax@15
	unsigned int v4; // [sp+0h] [bp-2Ch]@15
	unsigned int v5; // [sp+4h] [bp-28h]@11
	void *v6; // [sp+Ch] [bp-20h]@14
	void *v7; // [sp+10h] [bp-1Ch]@10
	cFilePath *v8; // [sp+18h] [bp-14h]@4
	const char *pParentName; // [sp+1Ch] [bp-10h]@9
	cFilePath LocalPath; // [sp+20h] [bp-Ch]@9

	if (this->m_pName)
	{
		if ((IStore *)this->m_pName == pNewParent)
			return;
		(*(void(__stdcall **)(char *))(*(_DWORD *)this->m_pName + 8))(this->m_pName);
		if (this->baseclass_0.m_ulRefs)
		{
			v8 = (cFilePath *)this->baseclass_0.m_ulRefs;
			if (v8)
				cFilePath::_scalar_deleting_destructor_(v8, 1u);
			this->baseclass_0.m_ulRefs = 0;
		}
	}
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
				v7 = j__new(0xCu, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 782);
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
				v6 = j__new(0xCu, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 787);
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

//----- (008ED3AD) --------------------------------------------------------
void __stdcall cZipSubstorage::SetStoreManager(cZipSubstorage *this, IStoreManager *pMan)
{
	tHashSetHandle h; // [sp+0h] [bp-14h]@6
	cNamedStorage *pEntry; // [sp+Ch] [bp-8h]@6
	void *pHier; // [sp+10h] [bp-4h]@8

	if (this->m_pStreamTable)
		((void(__stdcall *)(cStreamHashByName *))this->m_pStreamTable->baseclass_0.baseclass_0.baseclass_0.vfptr->IsEqual)(this->m_pStreamTable);
	this->m_pStreamTable = (cStreamHashByName *)pMan;
	if (this->m_pStreamTable)
		((void(__stdcall *)(cStreamHashByName *))this->m_pStreamTable->baseclass_0.baseclass_0.baseclass_0.vfptr->DestroyAll)(this->m_pStreamTable);
	if (this->m_pZipStorage)
	{
		for (pEntry = cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::GetFirst(
			(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *)this->m_pZipStorage,
			&h);
		pEntry;
		pEntry = cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::GetNext(
			(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *)this->m_pZipStorage,
			&h))
		{
			if (pEntry->m_pStore->baseclass_0.vfptr->QueryInterface(
				(IUnknown *)pEntry->m_pStore,
				&IID_IStoreHierarchy,
				&pHier) >= 0)
			{
				(*(void(__stdcall **)(void *, IStoreManager *))(*(_DWORD *)pHier + 12))(pHier, pMan);
				(*(void(__stdcall **)(void *))(*(_DWORD *)pHier + 8))(pHier);
			}
		}
	}
}

//----- (008ED467) --------------------------------------------------------
void __stdcall cZipSubstorage::SetDataStream(cZipSubstorage *this, IStoreStream *__formal)
{
	_CriticalMsg("cZipSubstorage::SetDataStream called!", "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 0x348u);
}

//----- (008ED482) --------------------------------------------------------
void __stdcall cZipSubstorage::DeclareContextRoot(cZipSubstorage *this, int bIsRoot)
{
	if (bIsRoot)
		this->m_pStoreManager = (IStoreManager *)((unsigned int)this->m_pStoreManager | 1);
	else
		this->m_pStoreManager = (IStoreManager *)((unsigned int)this->m_pStoreManager & 0xFFFFFFFE);
}

//----- (008ED4AF) --------------------------------------------------------
void __stdcall cZipSubstorage::Close(cZipSubstorage *this)
{
	tHashSetHandle h; // [sp+Ch] [bp-14h]@2
	cNamedStorage *pEntry; // [sp+18h] [bp-8h]@2
	void *pHier; // [sp+1Ch] [bp-4h]@4

	if (this->m_pZipStorage)
	{
		for (pEntry = cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::GetFirst(
			(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *)this->m_pZipStorage,
			&h);
		pEntry;
		pEntry = cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::GetNext(
			(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *)this->m_pZipStorage,
			&h))
		{
			cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Remove(
				(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *)this->m_pZipStorage,
				pEntry);
			if (pEntry->m_pStore->baseclass_0.vfptr->QueryInterface(
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

//----- (008ED564) --------------------------------------------------------
void __thiscall cZipStorage::cZipStorage(cZipStorage *this, IStore *pParent, IStoreStream *pZipStream, const char *pName)
{
	int v4; // eax@15
	const char *v5; // eax@19
	cZipStorage *thisa; // [sp+0h] [bp-280h]@1
	int nRecordsLeft; // [sp+4h] [bp-27Ch]@11
	char pFileRoot[32]; // [sp+8h] [bp-278h]@17
	void *pFilename; // [sp+28h] [bp-258h]@15
	sDirEndRecord EndRecord; // [sp+2Ch] [bp-254h]@11
	unsigned int EndRecStart; // [sp+44h] [bp-23Ch]@7
	void *pSubstore; // [sp+48h] [bp-238h]@16
	char pPath[512]; // [sp+4Ch] [bp-234h]@17
	unsigned int ZipSize; // [sp+24Ch] [bp-34h]@7
	sDirFileRecord DirRecord; // [sp+250h] [bp-30h]@13

	thisa = this;
	cZipSubstorage::cZipSubstorage(&this->baseclass_0, pParent, pName);
	thisa->baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cZipStorage::_vftable_;
	thisa->baseclass_0.baseclass_0.baseclass_4.baseclass_0.vfptr = (IUnknownVtbl *)&cZipStorage::_vftable_;
	if (!pParent)
		_CriticalMsg("Zip file created without a parent storage!", "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 0x388u);
	if (!pZipStream)
		_CriticalMsg("Zip file created without an input stream!", "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 0x389u);
	if (!pName)
		_CriticalMsg("Zip file created without a name!", "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 0x38Au);
	thisa->m_pZipStream = pZipStream;
	thisa->m_pZipStream->baseclass_0.vfptr->AddRef((IUnknown *)thisa->m_pZipStream);
	thisa->baseclass_0.m_pZipStorage = thisa;
	ZipSize = thisa->m_pZipStream->baseclass_0.vfptr[3].AddRef((IUnknown *)thisa->m_pZipStream);
	EndRecStart = ZipSize - 22;
	if (ZipSize == 22)
		_CriticalMsg("Zip file too small!", "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 0x39Bu);
	if (!((int(__stdcall *)(IStoreStream *, unsigned int))thisa->m_pZipStream->baseclass_0.vfptr[2].AddRef)(
		thisa->m_pZipStream,
		EndRecStart))
		_CriticalMsg(
		"Couldn't go to the start of zipfile end record",
		"x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp",
		0x39Du);
	((void(__stdcall *)(IStoreStream *, signed int, sDirEndRecord *))thisa->m_pZipStream->baseclass_0.vfptr[3].Release)(
		thisa->m_pZipStream,
		22,
		&EndRecord);
	((void(__stdcall *)(IStoreStream *, unsigned int))thisa->m_pZipStream->baseclass_0.vfptr[2].AddRef)(
		thisa->m_pZipStream,
		EndRecord.DirOffset);
	for (nRecordsLeft = EndRecord.NumEntries; nRecordsLeft; --nRecordsLeft)
	{
		((void(__stdcall *)(IStoreStream *, signed int, sDirFileRecord *))thisa->m_pZipStream->baseclass_0.vfptr[3].Release)(
			thisa->m_pZipStream,
			46,
			&DirRecord);
		if (DirRecord.Signature != 33639248)
			_CriticalMsg("Zip directory record with bad signature!", "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 0x3B6u);
		pFilename = MallocSpew(DirRecord.FilenameLen + 1, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 956);
		((void(__stdcall *)(IStoreStream *, _DWORD, void *))thisa->m_pZipStream->baseclass_0.vfptr[3].Release)(
			thisa->m_pZipStream,
			DirRecord.FilenameLen,
			pFilename);
		*((_BYTE *)pFilename + DirRecord.FilenameLen) = 0;
		v4 = thisa->m_pZipStream->baseclass_0.vfptr[2].Release((IUnknown *)thisa->m_pZipStream);
		((void(__stdcall *)(IStoreStream *, int))thisa->m_pZipStream->baseclass_0.vfptr[2].AddRef)(
			thisa->m_pZipStream,
			DirRecord.CommentLen + DirRecord.ExtraLen + v4);
		if (DirRecord.ExternalAttributes & 0x10)
		{
			pSubstore = cZipSubstorage::MakeSubstorage(&thisa->baseclass_0, (const char *)pFilename);
			(*(void(__stdcall **)(void *))(*(_DWORD *)pSubstore + 8))(pSubstore);
		}
		else
		{
			if (PathAndName((const char *)pFilename, pPath, pFileRoot))
			{
				pSubstore = cZipSubstorage::MakeSubstorage(&thisa->baseclass_0, pPath);
				if (!pSubstore)
				{
					v5 = _LogFmt("Couldn't create zip substorage %s!");
					_CriticalMsg(v5, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 0x3CFu);
				}
				cZipSubstorage::AddStream((cZipSubstorage *)pSubstore, pFileRoot, &DirRecord);
				(*(void(__stdcall **)(void *))(*(_DWORD *)pSubstore + 8))(pSubstore);
			}
			else
			{
				cZipSubstorage::AddStream(&thisa->baseclass_0, pFileRoot, &DirRecord);
			}
		}
		FreeSpew(pFilename, "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 985);
	}
}
// 9A8AC0: using guessed type int (__stdcall *cZipStorage___vftable_)(int this, int, int);
// 9A8AE4: using guessed type int (__stdcall *cZipStorage___vftable_)(int this, int id, int ppReturn);

//----- (008ED92C) --------------------------------------------------------
void __thiscall cZipStorage::_cZipStorage(cZipStorage *this)
{
	cZipStorage *v1; // ST04_4@1

	v1 = this;
	this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cZipStorage::_vftable_;
	this->baseclass_0.baseclass_0.baseclass_4.baseclass_0.vfptr = (IUnknownVtbl *)&cZipStorage::_vftable_;
	this->m_pZipStream->baseclass_0.vfptr[1].Release((IUnknown *)this->m_pZipStream);
	v1->m_pZipStream->baseclass_0.vfptr->Release((IUnknown *)v1->m_pZipStream);
	v1->m_pZipStream = 0;
	cZipSubstorage::_cZipSubstorage(&v1->baseclass_0);
}
// 9A8AC0: using guessed type int (__stdcall *cZipStorage___vftable_)(int this, int, int);
// 9A8AE4: using guessed type int (__stdcall *cZipStorage___vftable_)(int this, int id, int ppReturn);

//----- (008ED980) --------------------------------------------------------
IStoreStream *__thiscall cZipStorage::ReadyStreamAt(cZipStorage *this, int nPos)
{
	int v2; // eax@3
	cZipStorage *thisa; // [sp+0h] [bp-24h]@1
	sLocalFileHeader Header; // [sp+4h] [bp-20h]@1

	thisa = this;
	((void(__stdcall *)(IStoreStream *, int))this->m_pZipStream->baseclass_0.vfptr[2].AddRef)(this->m_pZipStream, nPos);
	((void(__stdcall *)(IStoreStream *, signed int, sLocalFileHeader *))thisa->m_pZipStream->baseclass_0.vfptr[3].Release)(
		thisa->m_pZipStream,
		30,
		&Header);
	if (Header.Signature != 67324752)
		_CriticalMsg("Zip file header with bad signature!", "x:\\prj\\tech\\libsrc\\namedres\\storezip.cpp", 0x3F7u);
	v2 = thisa->m_pZipStream->baseclass_0.vfptr[2].Release((IUnknown *)thisa->m_pZipStream);
	((void(__stdcall *)(IStoreStream *, int))thisa->m_pZipStream->baseclass_0.vfptr[2].AddRef)(
		thisa->m_pZipStream,
		Header.ExtraLen + Header.FilenameLen + v2);
	thisa->m_pZipStream->baseclass_0.vfptr->AddRef((IUnknown *)thisa->m_pZipStream);
	return thisa->m_pZipStream;
}

//----- (008EDA35) --------------------------------------------------------
unsigned int __thiscall cZipStorage::LastModified(cZipStorage *this)
{
	return this->m_pZipStream->baseclass_0.vfptr[4].Release((IUnknown *)this->m_pZipStream);
}

//----- (008EDA60) --------------------------------------------------------
void *__thiscall cZipSubstorage::_scalar_deleting_destructor_(cZipSubstorage *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cZipSubstorage::_cZipSubstorage(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008EDA90) --------------------------------------------------------
void *__thiscall cFilePath::_scalar_deleting_destructor_(cFilePath *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cFilePath::_cFilePath(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008EDAC0) --------------------------------------------------------
void *__thiscall cZipStorage::_vector_deleting_destructor_(cZipStorage *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cZipStorage::_cZipStorage(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008EDAF0) --------------------------------------------------------
cNamedStorage *__thiscall cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Insert(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *this, cNamedStorage *node)
{
	return (cNamedStorage *)cHashSetBase::Insert(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008EDB10) --------------------------------------------------------
cNamedStorage *__thiscall cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Search(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *this, const char *key)
{
	return (cNamedStorage *)cHashSetBase::Search(&this->baseclass_0, (tHashSetKey__ *)key);
}

//----- (008EDB30) --------------------------------------------------------
cNamedStorage *__thiscall cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Remove(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *this, cNamedStorage *node)
{
	return (cNamedStorage *)cHashSetBase::Remove(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008EDB50) --------------------------------------------------------
cNamedStorage *__thiscall cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::GetFirst(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *this, tHashSetHandle *Handle)
{
	return (cNamedStorage *)cHashSetBase::GetFirst(&this->baseclass_0, Handle);
}

//----- (008EDB70) --------------------------------------------------------
cNamedStorage *__thiscall cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::GetNext(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *this, tHashSetHandle *Handle)
{
	return (cNamedStorage *)cHashSetBase::GetNext(&this->baseclass_0, Handle);
}

//----- (008EDB90) --------------------------------------------------------
cNamedStream *__thiscall cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::Remove(cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> *this, cNamedStream *node)
{
	return (cNamedStream *)cHashSetBase::Remove(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008EDBB0) --------------------------------------------------------
cNamedStream *__thiscall cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::GetFirst(cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> *this, tHashSetHandle *Handle)
{
	return (cNamedStream *)cHashSetBase::GetFirst(&this->baseclass_0, Handle);
}

//----- (008EDBD0) --------------------------------------------------------
cNamedStream *__thiscall cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::GetNext(cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> *this, tHashSetHandle *Handle)
{
	return (cNamedStream *)cHashSetBase::GetNext(&this->baseclass_0, Handle);
}

