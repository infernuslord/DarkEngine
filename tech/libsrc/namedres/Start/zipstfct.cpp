//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>


//----- (008E4460) --------------------------------------------------------
int __stdcall cZipStorageFactory::QueryInterface(cZipStorageFactory *this, _GUID *id, void **ppI)
{
	int result; // eax@5

	if (id != &IID_IStoreFactory
		&& id != &IID_IUnknown
		&& memcmp(id, &IID_IStoreFactory, 0x10u)
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

//----- (008E44CD) --------------------------------------------------------
unsigned int __stdcall cZipStorageFactory::AddRef(cZipStorageFactory *this)
{
	return cZipStorageFactory::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008E44DF) --------------------------------------------------------
unsigned int __stdcall cZipStorageFactory::Release(cZipStorageFactory *this)
{
	unsigned int result; // eax@2

	if (cZipStorageFactory::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cZipStorageFactory::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cZipStorageFactory::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (008E450C) --------------------------------------------------------
void __stdcall cZipStorageFactory::EnumerateTypes(cZipStorageFactory *this, void(__cdecl *Callback)(const char *, IStoreFactory *, void *), void *pClientData)
{
	Callback(".crf", &this->baseclass_0, pClientData);
	Callback(".zip", &this->baseclass_0, pClientData);
}

//----- (008E4539) --------------------------------------------------------
IStore *__stdcall cZipStorageFactory::CreateStore(cZipStorageFactory *this, IStore *pParent, const char *pName, const char *pExt)
{
	IStore *result; // eax@4
	const char *v5; // eax@6
	void *v6; // eax@6
	int v7; // eax@10
	IStore *v8; // ST10_4@10
	void *v9; // [sp+0h] [bp-30h]@6
	void *v10; // [sp+Ch] [bp-24h]@5
	void *pParentHier; // [sp+10h] [bp-20h]@8
	cFileSpec fileSpec; // [sp+14h] [bp-1Ch]@5
	void *pStore; // [sp+1Ch] [bp-14h]@8
	cAnsiStr Root; // [sp+20h] [bp-10h]@5
	IStoreStream *pDataStream; // [sp+2Ch] [bp-4h]@3

	if (!pParent)
		_CriticalMsg("cZipStorageFactory: no parent!", "x:\\prj\\tech\\libsrc\\namedres\\zipstfct.cpp", 0x35u);
	pDataStream = (IStoreStream *)pParent->baseclass_0.vfptr[4].QueryInterface((IUnknown *)pParent, (_GUID *)pName, 0);
	if (pDataStream)
	{
		cAnsiStr::cAnsiStr(&Root);
		cFileSpec::cFileSpec(&fileSpec, pName);
		cFileSpec::GetFileRoot(&fileSpec, &Root);
		v10 = j__new(0x30u, "x:\\prj\\tech\\libsrc\\namedres\\zipstfct.cpp", 67);
		if (v10)
		{
			v5 = cAnsiStr::operator char_const__(&Root);
			cZipStorage::cZipStorage((cZipStorage *)v10, pParent, pDataStream, v5);
			v9 = v6;
		}
		else
		{
			v9 = 0;
		}
		pStore = v9;
		pDataStream->baseclass_0.vfptr->Release((IUnknown *)pDataStream);
		if (pParent->baseclass_0.vfptr->QueryInterface((IUnknown *)pParent, &IID_IStoreHierarchy, &pParentHier) >= 0)
		{
			v7 = (*(int(__stdcall **)(void *))(*(_DWORD *)pStore + 12))(pStore);
			(*(void(__stdcall **)(void *, void *, int))(*(_DWORD *)pParentHier + 16))(pParentHier, pStore, v7);
			(*(void(__stdcall **)(void *))(*(_DWORD *)pParentHier + 8))(pParentHier);
			v8 = (IStore *)pStore;
			cFileSpec::_cFileSpec(&fileSpec);
			cAnsiStr::_cAnsiStr(&Root);
			result = v8;
		}
		else
		{
			_CriticalMsg("Couldn't QI a StoreHierarchy!", "x:\\prj\\tech\\libsrc\\namedres\\zipstfct.cpp", 0x4Du);
			(*(void(__stdcall **)(void *))(*(_DWORD *)pStore + 8))(pStore);
			cFileSpec::_cFileSpec(&fileSpec);
			cAnsiStr::_cAnsiStr(&Root);
			result = 0;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008E468A) --------------------------------------------------------
IStoreFactory *__cdecl MakeZipStorageFactory()
{
	IStoreFactory *v0; // eax@2
	IStoreFactory *v2; // [sp+0h] [bp-8h]@2
	void *this; // [sp+4h] [bp-4h]@1

	this = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\zipstfct.cpp", 94);
	if (this)
	{
		cZipStorageFactory::cZipStorageFactory((cZipStorageFactory *)this);
		v2 = v0;
	}
	else
	{
		v2 = 0;
	}
	return v2;
}

//----- (008E46D0) --------------------------------------------------------
unsigned int __thiscall cZipStorageFactory::cRefCount::AddRef(cZipStorageFactory::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008E46F0) --------------------------------------------------------
unsigned int __thiscall cZipStorageFactory::cRefCount::Release(cZipStorageFactory::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008E4710) --------------------------------------------------------
unsigned int __thiscall cZipStorageFactory::cRefCount::operator unsigned_long(cZipStorageFactory::cRefCount *this)
{
	return this->ul;
}

//----- (008E4720) --------------------------------------------------------
void __thiscall cZipStorageFactory::OnFinalRelease(cZipStorageFactory *this)
{
	operator delete(this);
}

//----- (008E4740) --------------------------------------------------------
void __thiscall cZipStorageFactory::cZipStorageFactory(cZipStorageFactory *this)
{
	cZipStorageFactory *v1; // ST00_4@1

	v1 = this;
	IStoreFactory::IStoreFactory(&this->baseclass_0);
	cZipStorageFactory::cRefCount::cRefCount(&v1->__m_ulRefs);
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cZipStorageFactory::_vftable_;
}
// 9A82B0: using guessed type int (__stdcall *cZipStorageFactory___vftable_)(int this, int id, int ppI);

//----- (008E4770) --------------------------------------------------------
void __thiscall cZipStorageFactory::cRefCount::cRefCount(cZipStorageFactory::cRefCount *this)
{
	this->ul = 1;
}
