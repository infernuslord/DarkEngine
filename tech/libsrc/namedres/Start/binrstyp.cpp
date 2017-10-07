//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>



//----- (008E58E0) --------------------------------------------------------
int __stdcall cBinaryResourceType::QueryInterface(cBinaryResourceType *this, _GUID *id, void **ppI)
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

//----- (008E594D) --------------------------------------------------------
unsigned int __stdcall cBinaryResourceType::AddRef(cBinaryResourceType *this)
{
	return cBinaryResourceType::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008E595F) --------------------------------------------------------
unsigned int __stdcall cBinaryResourceType::Release(cBinaryResourceType *this)
{
	unsigned int result; // eax@2

	if (cBinaryResourceType::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cBinaryResourceType::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cBinaryResourceType::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (008E598C) --------------------------------------------------------
const char *__stdcall cBinaryResourceType::GetName(cBinaryResourceType *this)
{
	return "Binary";
}

//----- (008E5998) --------------------------------------------------------
void __stdcall cBinaryResourceType::EnumerateExts(cBinaryResourceType *this, void(__cdecl *Callback)(const char *, IResType *, void *), void *pClientData)
{
	Callback(".bin", &this->baseclass_0, pClientData);
	Callback(".cal", &this->baseclass_0, pClientData);
	Callback(".mi", &this->baseclass_0, pClientData);
	Callback(".mc", &this->baseclass_0, pClientData);
}

//----- (008E59EB) --------------------------------------------------------
int __stdcall cBinaryResourceType::IsLegalExt(cBinaryResourceType *this, const char *__formal)
{
	return 1;
}

//----- (008E59F7) --------------------------------------------------------
IRes *__stdcall cBinaryResourceType::CreateRes(cBinaryResourceType *this, IStore *pStore, const char *pName, const char *__formal, IResMemOverride **a5)
{
	int v5; // eax@2
	IRes *v7; // [sp+0h] [bp-Ch]@5
	int v8; // [sp+4h] [bp-8h]@2
	void *v9; // [sp+8h] [bp-4h]@1

	v9 = j__new(0x48u, "x:\\prj\\tech\\libsrc\\namedres\\binrstyp.cpp", 76);
	if (v9)
	{
		cResourceBase<IRes___GUID_const_IID_IRes>::cResourceBase<IRes___GUID_const_IID_IRes>(
			(cResourceBase<IRes, &IID_IRes> *)v9,
			pStore,
			pName,
			&this->baseclass_0);
		v8 = v5;
	}
	else
	{
		v8 = 0;
	}
	if (v8)
		v7 = (IRes *)(v8 + 8);
	else
		v7 = 0;
	return v7;
}

//----- (008E5A58) --------------------------------------------------------
IResType *__cdecl MakeBinaryResourceType()
{
	IResType *v0; // eax@2
	IResType *v2; // [sp+0h] [bp-8h]@2
	void *this; // [sp+4h] [bp-4h]@1

	this = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\binrstyp.cpp", 86);
	if (this)
	{
		cBinaryResourceType::cBinaryResourceType((cBinaryResourceType *)this);
		v2 = v0;
	}
	else
	{
		v2 = 0;
	}
	return v2;
}

//----- (008E5AA0) --------------------------------------------------------
unsigned int __thiscall cBinaryResourceType::cRefCount::AddRef(cBinaryResourceType::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008E5AC0) --------------------------------------------------------
unsigned int __thiscall cBinaryResourceType::cRefCount::Release(cBinaryResourceType::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008E5AE0) --------------------------------------------------------
unsigned int __thiscall cBinaryResourceType::cRefCount::operator unsigned_long(cBinaryResourceType::cRefCount *this)
{
	return this->ul;
}

//----- (008E5AF0) --------------------------------------------------------
void __thiscall cBinaryResourceType::OnFinalRelease(cBinaryResourceType *this)
{
	operator delete(this);
}

//----- (008E5B10) --------------------------------------------------------
void __thiscall cBinaryResourceType::cBinaryResourceType(cBinaryResourceType *this)
{
	cBinaryResourceType *v1; // ST00_4@1

	v1 = this;
	IResType::IResType(&this->baseclass_0);
	cBinaryResourceType::cRefCount::cRefCount(&v1->__m_ulRefs);
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cBinaryResourceType::_vftable_;
}
// 9A8428: using guessed type int (__stdcall *cBinaryResourceType___vftable_)(int this, int id, int ppI);

//----- (008E5B40) --------------------------------------------------------
void __thiscall cBinaryResourceType::cRefCount::cRefCount(cBinaryResourceType::cRefCount *this)
{
	this->ul = 1;
}
