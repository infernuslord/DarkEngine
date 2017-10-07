//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>






//----- (008EF0F0) --------------------------------------------------------
int __stdcall cDefaultStorageFactory::QueryInterface(cDefaultStorageFactory *this, _GUID *id, void **ppI)
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

//----- (008EF15D) --------------------------------------------------------
unsigned int __stdcall cDefaultStorageFactory::AddRef(cDefaultStorageFactory *this)
{
	return cDefaultStorageFactory::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008EF16F) --------------------------------------------------------
unsigned int __stdcall cDefaultStorageFactory::Release(cDefaultStorageFactory *this)
{
	unsigned int result; // eax@2

	if (cDefaultStorageFactory::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cDefaultStorageFactory::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cDefaultStorageFactory::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (008EF19C) --------------------------------------------------------
void __stdcall cDefaultStorageFactory::EnumerateTypes(cDefaultStorageFactory *this, void(__cdecl *__formal)(const char *, IStoreFactory *, void *), void *a3)
{
	;
}

//----- (008EF1A3) --------------------------------------------------------
IStore *__stdcall cDefaultStorageFactory::CreateStore(cDefaultStorageFactory *this, IStore *pParent, const char *pName, const char *pExt)
{
	void *v4; // eax@4
	int v6; // eax@10
	void *v7; // [sp+0h] [bp-1Ch]@4
	void *v8; // [sp+4h] [bp-18h]@3
	int pDataStream; // [sp+8h] [bp-14h]@11
	signed int needsData; // [sp+Ch] [bp-10h]@2
	void *pHier; // [sp+10h] [bp-Ch]@13
	void *pParentHier; // [sp+14h] [bp-8h]@8
	IStore *pStore; // [sp+18h] [bp-4h]@6

	if (strcmp(pExt, "zip"))
	{
		v8 = j__new(0x2Cu, "x:\\prj\\tech\\libsrc\\namedres\\defstfct.cpp", 42);
		if (v8)
		{
			cDirectoryStorage::cDirectoryStorage((cDirectoryStorage *)v8, pName);
			v7 = v4;
		}
		else
		{
			v7 = 0;
		}
		pStore = (IStore *)v7;
		needsData = 0;
	}
	else
	{
		needsData = 1;
	}
	if (pParent)
	{
		if (pParent->baseclass_0.vfptr->QueryInterface((IUnknown *)pParent, &IID_IStoreHierarchy, &pParentHier) < 0)
		{
			_CriticalMsg("Couldn't QI a StoreHierarchy!", "x:\\prj\\tech\\libsrc\\namedres\\defstfct.cpp", 0x33u);
			pStore->baseclass_0.vfptr->Release((IUnknown *)pStore);
			return 0;
		}
		v6 = ((int(__stdcall *)(IStore *))pStore->baseclass_0.vfptr[1].QueryInterface)(pStore);
		(*(void(__stdcall **)(void *, IStore *, int))(*(_DWORD *)pParentHier + 16))(pParentHier, pStore, v6);
		(*(void(__stdcall **)(void *))(*(_DWORD *)pParentHier + 8))(pParentHier);
		if (needsData)
		{
			pDataStream = pParent->baseclass_0.vfptr[4].QueryInterface((IUnknown *)pParent, (_GUID *)pName, 0);
			if (!pDataStream)
			{
				pStore->baseclass_0.vfptr->Release((IUnknown *)pStore);
				return 0;
			}
			if (pStore->baseclass_0.vfptr->QueryInterface((IUnknown *)pStore, &IID_IStoreHierarchy, &pHier) < 0)
			{
				_CriticalMsg("Couldn't QI a StoreHierarchy!", "x:\\prj\\tech\\libsrc\\namedres\\defstfct.cpp", 0x44u);
				pStore->baseclass_0.vfptr->Release((IUnknown *)pStore);
				return 0;
			}
			(*(void(__stdcall **)(void *, int))(*(_DWORD *)pHier + 24))(pHier, pDataStream);
			(*(void(__stdcall **)(int))(*(_DWORD *)pDataStream + 8))(pDataStream);
			(*(void(__stdcall **)(void *))(*(_DWORD *)pHier + 8))(pHier);
		}
	}
	return pStore;
}

//----- (008EF320) --------------------------------------------------------
unsigned int __thiscall cDefaultStorageFactory::cRefCount::AddRef(cDefaultStorageFactory::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008EF340) --------------------------------------------------------
unsigned int __thiscall cDefaultStorageFactory::cRefCount::Release(cDefaultStorageFactory::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008EF360) --------------------------------------------------------
unsigned int __thiscall cDefaultStorageFactory::cRefCount::operator unsigned_long(cDefaultStorageFactory::cRefCount *this)
{
	return this->ul;
}

//----- (008EF370) --------------------------------------------------------
void __thiscall cDefaultStorageFactory::OnFinalRelease(cDefaultStorageFactory *this)
{
	operator delete(this);
}

