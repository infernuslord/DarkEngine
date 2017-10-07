//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>



//----- (008EDBF0) --------------------------------------------------------
int __stdcall cStorageBase::QueryInterface(cStorageBase *this, _GUID *a2, void **a3)
{
	return cStorageBase::QueryInterface((cStorageBase *)((char *)this - 4), a2, a3);
}

//----- (008EDC00) --------------------------------------------------------
unsigned int __stdcall cStorageBase::AddRef(cStorageBase *this)
{
	return cStorageBase::AddRef((cStorageBase *)((char *)this - 4));
}

//----- (008EDC10) --------------------------------------------------------
unsigned int __stdcall cStorageBase::Release(cStorageBase *this)
{
	return cStorageBase::Release((cStorageBase *)((char *)this - 4));
}



//----- (008EF390) --------------------------------------------------------
void __thiscall cNamedStorage::cNamedStorage(cNamedStorage *this, IStore *pStore)
{
	const char *v2; // eax@2
	const char *v3; // ST10_4@2
	size_t v4; // eax@2
	cNamedStorage *thisa; // [sp+0h] [bp-8h]@1

	thisa = this;
	this->m_pStore = 0;
	this->m_pName = 0;
	if (pStore)
	{
		this->m_pStore = pStore;
		pStore->baseclass_0.vfptr->AddRef((IUnknown *)pStore);
		v2 = (const char *)((int(__stdcall *)(_DWORD))pStore->baseclass_0.vfptr[1].QueryInterface)(pStore);
		v3 = v2;
		v4 = strlen(v2);
		thisa->m_pName = (char *)MallocSpew(v4 + 1, "x:\\prj\\tech\\libsrc\\namedres\\storbase.cpp", 35);
		strcpy(thisa->m_pName, v3);
	}
}

//----- (008EF416) --------------------------------------------------------
void __thiscall cNamedStorage::cNamedStorage(cNamedStorage *this, const char *pName)
{
	size_t v2; // eax@3
	cNamedStorage *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	this->m_pStore = 0;
	this->m_pName = 0;
	if (!pName)
		_CriticalMsg("cNamedStorage being created without a name!", "x:\\prj\\tech\\libsrc\\namedres\\storbase.cpp", 0x2Du);
	v2 = strlen(pName);
	thisa->m_pName = (char *)MallocSpew(v2 + 1, "x:\\prj\\tech\\libsrc\\namedres\\storbase.cpp", 46);
	strcpy(thisa->m_pName, pName);
}

//----- (008EF490) --------------------------------------------------------
void __thiscall cNamedStorage::_cNamedStorage(cNamedStorage *this)
{
	cNamedStorage *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (this->m_pStore)
	{
		this->m_pStore->baseclass_0.vfptr->Release((IUnknown *)this->m_pStore);
		thisa->m_pStore = 0;
	}
	if (thisa->m_pName)
	{
		FreeSpew(thisa->m_pName, "x:\\prj\\tech\\libsrc\\namedres\\storbase.cpp", 56);
		thisa->m_pName = 0;
	}
}

//----- (008EF4E5) --------------------------------------------------------
void __thiscall cStorageHashByName::cStorageHashByName(cStorageHashByName *this)
{
	cStorageHashByName *v1; // ST04_4@1

	v1 = this;
	cStrIHashSet<cNamedStorage__>::cStrIHashSet<cNamedStorage__>(&this->baseclass_0, 0x65u);
	v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStorageHashByName::_vftable_;
}
// 9A8B98: using guessed type int (__stdcall *cStorageHashByName___vftable_)(int __flags);

//----- (008EF506) --------------------------------------------------------
void __thiscall cStorageHashByName::_cStorageHashByName(cStorageHashByName *this)
{
	cStrIHashSet<cNamedStorage *> *v1; // ST00_4@1

	v1 = (cStrIHashSet<cNamedStorage *> *)this;
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStorageHashByName::_vftable_;
	cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::DestroyAll(&this->baseclass_0.baseclass_0);
	cStrIHashSet<cNamedStorage__>::_cStrIHashSet<cNamedStorage__>(v1);
}
// 9A8B98: using guessed type int (__stdcall *cStorageHashByName___vftable_)(int __flags);

//----- (008EF52A) --------------------------------------------------------
tHashSetKey__ *__thiscall cStorageHashByName::GetKey(cStorageHashByName *this, tHashSetNode__ *node)
{
	return (tHashSetKey__ *)node[1].unused;
}

//----- (008EF53D) --------------------------------------------------------
void __thiscall cNamedStream::cNamedStream(cNamedStream *this, const char *pName, int bExists)
{
	size_t v3; // eax@3
	char **thisa; // [sp+0h] [bp-4h]@1

	thisa = (char **)this;
	this->m_pName = 0;
	this->m_bExists = bExists;
	if (!pName)
		_CriticalMsg("cNamedStream being created without a name!", "x:\\prj\\tech\\libsrc\\namedres\\storbase.cpp", 0x50u);
	v3 = strlen(pName);
	*thisa = (char *)MallocSpew(v3 + 1, "x:\\prj\\tech\\libsrc\\namedres\\storbase.cpp", 81);
	strcpy(*thisa, pName);
}

//----- (008EF5B4) --------------------------------------------------------
void __thiscall cNamedStream::_cNamedStream(cNamedStream *this)
{
	cNamedStream *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (this->m_pName)
	{
		FreeSpew(this->m_pName, "x:\\prj\\tech\\libsrc\\namedres\\storbase.cpp", 87);
		thisa->m_pName = 0;
	}
}

//----- (008EF5E5) --------------------------------------------------------
void __thiscall cStreamHashByName::cStreamHashByName(cStreamHashByName *this)
{
	cStreamHashByName *v1; // ST04_4@1

	v1 = this;
	cStrIHashSet<cNamedStream__>::cStrIHashSet<cNamedStream__>(&this->baseclass_0, 0x65u);
	v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStreamHashByName::_vftable_;
}
// 9A8BB8: using guessed type int (__stdcall *cStreamHashByName___vftable_)(int __flags);

//----- (008EF606) --------------------------------------------------------
void __thiscall cStreamHashByName::_cStreamHashByName(cStreamHashByName *this)
{
	cStrIHashSet<cNamedStream *> *v1; // ST00_4@1

	v1 = (cStrIHashSet<cNamedStream *> *)this;
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStreamHashByName::_vftable_;
	cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::DestroyAll(&this->baseclass_0.baseclass_0);
	cStrIHashSet<cNamedStream__>::_cStrIHashSet<cNamedStream__>(v1);
}
// 9A8BB8: using guessed type int (__stdcall *cStreamHashByName___vftable_)(int __flags);

//----- (008EF62A) --------------------------------------------------------
tHashSetKey__ *__thiscall cStreamHashByName::GetKey(cStreamHashByName *this, tHashSetNode__ *node)
{
	return (tHashSetKey__ *)node->unused;
}


//----- (008EF63C) --------------------------------------------------------
void __thiscall cStorageBase::cStorageBase(cStorageBase *this)
{
	cStorageBase *v1; // ST00_4@1

	v1 = this;
	IStore::IStore(&this->baseclass_0);
	IStoreHierarchy::IStoreHierarchy(&v1->baseclass_4);
	v1->m_ulRefs = 1;
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cStorageBase::_vftable_;
	v1->baseclass_4.baseclass_0.vfptr = (IUnknownVtbl *)&cStorageBase::_vftable_;
}
// 9A8BD8: using guessed type int (__stdcall *cStorageBase___vftable_)(int this, int, int);
// 9A8BFC: using guessed type int (__stdcall *cStorageBase___vftable_)(int this, int id, int ppReturn);

//----- (008EF67A) --------------------------------------------------------
void __thiscall cStorageBase::_cStorageBase(cStorageBase *this)
{
	this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cStorageBase::_vftable_;
	this->baseclass_4.baseclass_0.vfptr = (IUnknownVtbl *)&cStorageBase::_vftable_;
}
// 9A8BD8: using guessed type int (__stdcall *cStorageBase___vftable_)(int this, int, int);
// 9A8BFC: using guessed type int (__stdcall *cStorageBase___vftable_)(int this, int id, int ppReturn);

//----- (008EF698) --------------------------------------------------------
int __stdcall cStorageBase::QueryInterface(cStorageBase *this, _GUID *id, void **ppReturn)
{
	int result; // eax@12
	void *v4; // [sp+0h] [bp-4h]@8

	*ppReturn = 0;
	if (id != &IID_IStore && id != &IID_IUnknown && memcmp(id, &IID_IStore, 0x10u) && memcmp(id, &IID_IUnknown, 0x10u))
	{
		if (operator__(id, &IID_IStoreHierarchy))
		{
			if (this)
				v4 = &this->baseclass_4;
			else
				v4 = 0;
			*ppReturn = v4;
			this->baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)this);
		}
	}
	else
	{
		*ppReturn = this;
		this->baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)this);
	}
	if (*ppReturn)
		result = 0;
	else
		result = -2147467262;
	return result;
}

//----- (008EF753) --------------------------------------------------------
unsigned int __stdcall cStorageBase::AddRef(cStorageBase *this)
{
	++this->m_ulRefs;
	return this->m_ulRefs;
}

//----- (008EF76F) --------------------------------------------------------
unsigned int __stdcall cStorageBase::Release(cStorageBase *this)
{
	unsigned int result; // eax@2

	--this->m_ulRefs;
	if (this->m_ulRefs)
	{
		result = this->m_ulRefs;
	}
	else
	{
		if (this)
			((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[5].Release)(this, 1);
		result = 0;
	}
	return result;
}

//----- (008EF7D0) --------------------------------------------------------
void *__thiscall cStorageHashByName::_scalar_deleting_destructor_(cStorageHashByName *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStorageHashByName::_cStorageHashByName(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008EF800) --------------------------------------------------------
void *__thiscall cStreamHashByName::_scalar_deleting_destructor_(cStreamHashByName *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStreamHashByName::_cStreamHashByName(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008EF830) --------------------------------------------------------
void *__thiscall cStorageBase::_vector_deleting_destructor_(cStorageBase *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStorageBase::_cStorageBase(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008EF860) --------------------------------------------------------
void __thiscall IStore::IStore(IStore *this)
{
	IStore *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)IStore::_vftable_;
}
// 9A8C44: using guessed type int (*IStore___vftable_[26])();

//----- (008EF880) --------------------------------------------------------
void __thiscall IStoreHierarchy::IStoreHierarchy(IStoreHierarchy *this)
{
	IStoreHierarchy *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)IStoreHierarchy::_vftable_;
}
// 9A8C88: using guessed type int (*IStoreHierarchy___vftable_[9])();
