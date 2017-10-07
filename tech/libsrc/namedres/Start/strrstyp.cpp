//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>




//----- (008DFEF0) --------------------------------------------------------
int __stdcall cStringResourceType::QueryInterface(cStringResourceType *this, _GUID *id, void **ppI)
{
	int result; // eax@5

	if (id != &IID_IResType
		&& id != &IID_IUnknown
		&& memcmp(id, &IID_IResType, 0x10u)
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

//----- (008DFF5D) --------------------------------------------------------
unsigned int __stdcall cStringResourceType::AddRef(cStringResourceType *this)
{
	return cStringResourceType::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008DFF6F) --------------------------------------------------------
unsigned int __stdcall cStringResourceType::Release(cStringResourceType *this)
{
	unsigned int result; // eax@2

	if (cStringResourceType::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cStringResourceType::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cStringResourceType::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (008DFF9C) --------------------------------------------------------
const char *__stdcall cStringResourceType::GetName(cStringResourceType *this)
{
	return "String";
}

//----- (008DFFA8) --------------------------------------------------------
void __stdcall cStringResourceType::EnumerateExts(cStringResourceType *this, void(__cdecl *Callback)(const char *, IResType *, void *), void *pClientData)
{
	Callback(".str", &this->baseclass_0, pClientData);
}

//----- (008DFFC2) --------------------------------------------------------
int __stdcall cStringResourceType::IsLegalExt(cStringResourceType *this, const char *pExt)
{
	return _strcmpi(".str", pExt) == 0;
}

//----- (008DFFDF) --------------------------------------------------------
IRes *__stdcall cStringResourceType::CreateRes(cStringResourceType *this, IStore *pStore, const char *pName, const char *pExt, IResMemOverride **__formal)
{
	IRes *result; // eax@2
	int v6; // eax@4
	IRes *v7; // [sp+0h] [bp-Ch]@7
	int v8; // [sp+4h] [bp-8h]@4
	void *v9; // [sp+8h] [bp-4h]@3

	if (((int(__stdcall *)(cStringResourceType *, const char *))this->baseclass_0.baseclass_0.vfptr[1].Release)(
		this,
		pExt))
	{
		v9 = j__new(0x48u, "x:\\prj\\tech\\libsrc\\namedres\\strrstyp.cpp", 73);
		if (v9)
		{
			cStringResource::cStringResource((cStringResource *)v9, pStore, pName, &this->baseclass_0);
			v8 = v6;
		}
		else
		{
			v8 = 0;
		}
		if (v8)
			v7 = (IRes *)(v8 + 8);
		else
			v7 = 0;
		result = v7;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008E0058) --------------------------------------------------------
IResType *__cdecl MakeStringResourceType()
{
	IResType *v0; // eax@2
	IResType *v2; // [sp+0h] [bp-8h]@2
	void *this; // [sp+4h] [bp-4h]@1

	this = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\strrstyp.cpp", 83);
	if (this)
	{
		cStringResourceType::cStringResourceType((cStringResourceType *)this);
		v2 = v0;
	}
	else
	{
		v2 = 0;
	}
	return v2;
}

//----- (008E00A0) --------------------------------------------------------
unsigned int __thiscall cStringResourceType::cRefCount::AddRef(cStringResourceType::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008E00C0) --------------------------------------------------------
unsigned int __thiscall cStringResourceType::cRefCount::Release(cStringResourceType::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008E00E0) --------------------------------------------------------
unsigned int __thiscall cStringResourceType::cRefCount::operator unsigned_long(cStringResourceType::cRefCount *this)
{
	return this->ul;
}

//----- (008E00F0) --------------------------------------------------------
void __thiscall cStringResourceType::OnFinalRelease(cStringResourceType *this)
{
	operator delete(this);
}

//----- (008E0110) --------------------------------------------------------
void __thiscall cStringResourceType::cStringResourceType(cStringResourceType *this)
{
	cStringResourceType *v1; // ST00_4@1

	v1 = this;
	IResType::IResType(&this->baseclass_0);
	cStringResourceType::cRefCount::cRefCount(&v1->__m_ulRefs);
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cStringResourceType::_vftable_;
}
// 9A8108: using guessed type int (__stdcall *cStringResourceType___vftable_)(int this, int id, int ppI);

//----- (008E0140) --------------------------------------------------------
void __thiscall cStringResourceType::cRefCount::cRefCount(cStringResourceType::cRefCount *this)
{
	this->ul = 1;
}

//----- (008E0160) --------------------------------------------------------
void __thiscall cStrIHashSet<cStringResEntry__>::cStrIHashSet<cStringResEntry__>(cStrIHashSet<cStringResEntry *> *this, unsigned int n)
{
	cStrIHashSet<cStringResEntry *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>::cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		n);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<cStringResEntry__>::_vftable_;
}
// 9A8124: using guessed type int (__stdcall *cStrIHashSet_cStringResEntry _____vftable_)(int __flags);

//----- (008E0190) --------------------------------------------------------
void __thiscall cStrIHashSet<cStringResEntry__>::cStrIHashSet<cStringResEntry__>(cStrIHashSet<cStringResEntry *> *this, cHashSet<cStringResEntry *, char const *, cCaselessStringHashFuncs> *__formal)
{
	cStrIHashSet<cStringResEntry *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>::cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		&this->baseclass_0);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<cStringResEntry__>::_vftable_;
}
// 9A8124: using guessed type int (__stdcall *cStrIHashSet_cStringResEntry _____vftable_)(int __flags);

//----- (008E01C0) --------------------------------------------------------
void *__thiscall cStrIHashSet<cStringResEntry__>::_vector_deleting_destructor_(cStrIHashSet<cStringResEntry *> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStrIHashSet<cStringResEntry__>::_cStrIHashSet<cStringResEntry__>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E01F0) --------------------------------------------------------
void __thiscall cStrIHashSet<cStringResEntry__>::_cStrIHashSet<cStringResEntry__>(cStrIHashSet<cStringResEntry *> *this)
{
	cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>::_cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>(&this->baseclass_0);
}

//----- (008E0210) --------------------------------------------------------
void __thiscall cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>::_cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>(cHashSet<cStringResEntry *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSetBase::_cHashSetBase(&this->baseclass_0);
}

//----- (008E0230) --------------------------------------------------------
void __thiscall cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>::cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>(cHashSet<cStringResEntry *, char const *, cCaselessStringHashFuncs> *this, unsigned int n)
{
	cHashSet<cStringResEntry *, char const *, cCaselessStringHashFuncs> *v2; // ST14_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, n);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A8144: using guessed type int (__stdcall *cHashSet_cStringResEntry __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008E02A0) --------------------------------------------------------
void __thiscall cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>::cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>(cHashSet<cStringResEntry *, char const *, cCaselessStringHashFuncs> *this, cHashSet<cStringResEntry *, char const *, cCaselessStringHashFuncs> *__formal)
{
	cHashSet<cStringResEntry *, char const *, cCaselessStringHashFuncs> *v2; // ST04_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, &this->baseclass_0);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A8144: using guessed type int (__stdcall *cHashSet_cStringResEntry __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008E02D0) --------------------------------------------------------
void *__thiscall cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>::_scalar_deleting_destructor_(cHashSet<cStringResEntry *, char const *, cCaselessStringHashFuncs> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>::_cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E0300) --------------------------------------------------------
int __thiscall cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>::IsEqual(cHashSet<cStringResEntry *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k1, tHashSetKey__ *k2)
{
	return cCaselessStringHashFuncs::IsEqual((const char *)k1, (const char *)k2);
}

//----- (008E0320) --------------------------------------------------------
unsigned int __thiscall cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>::Hash(cHashSet<cStringResEntry *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k)
{
	return cCaselessStringHashFuncs::Hash((const char *)k);
}
