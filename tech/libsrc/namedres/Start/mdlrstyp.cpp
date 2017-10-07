//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>



//----- (008DF6F0) --------------------------------------------------------
int __stdcall cModelResourceType::QueryInterface(cModelResourceType *this, _GUID *id, void **ppI)
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

//----- (008DF75D) --------------------------------------------------------
unsigned int __stdcall cModelResourceType::AddRef(cModelResourceType *this)
{
	return cModelResourceType::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008DF76F) --------------------------------------------------------
unsigned int __stdcall cModelResourceType::Release(cModelResourceType *this)
{
	unsigned int result; // eax@2

	if (cModelResourceType::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cModelResourceType::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cModelResourceType::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (008DF79C) --------------------------------------------------------
const char *__stdcall cModelResourceType::GetName(cModelResourceType *this)
{
	return "Model";
}

//----- (008DF7A8) --------------------------------------------------------
void __stdcall cModelResourceType::EnumerateExts(cModelResourceType *this, void(__cdecl *Callback)(const char *, IResType *, void *), void *pClientData)
{
	Callback(".bin", &this->baseclass_0, pClientData);
}

//----- (008DF7C2) --------------------------------------------------------
int __stdcall cModelResourceType::IsLegalExt(cModelResourceType *this, const char *pExt)
{
	int result; // eax@2

	if (_strcmpi(pExt, ".bin"))
		result = 0;
	else
		result = 1;
	return result;
}

//----- (008DF7E7) --------------------------------------------------------
IRes *__stdcall cModelResourceType::CreateRes(cModelResourceType *this, IStore *pStore, const char *pName, const char *pExt, IResMemOverride **__formal)
{
	IRes *result; // eax@2
	int v6; // eax@4
	IRes *v7; // [sp+0h] [bp-Ch]@7
	int v8; // [sp+4h] [bp-8h]@4
	void *v9; // [sp+8h] [bp-4h]@3

	if (((int(__stdcall *)(cModelResourceType *, const char *))this->baseclass_0.baseclass_0.vfptr[1].Release)(
		this,
		pExt))
	{
		v9 = j__new(0x48u, "x:\\prj\\tech\\libsrc\\namedres\\mdlrstyp.cpp", 80);
		if (v9)
		{
			cResourceBase<IRes___GUID_const_IID_IRes>::cResourceBase<IRes___GUID_const_IID_IRes>(
				(cResourceBase<IRes, &IID_IRes> *)v9,
				pStore,
				pName,
				&this->baseclass_0);
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
		DbgReportWarning("cModelResourceType called for illegal extension %s\n");
		result = 0;
	}
	return result;
}

//----- (008DF871) --------------------------------------------------------
IResType *__cdecl MakeModelResourceType()
{
	IResType *v0; // eax@2
	IResType *v2; // [sp+0h] [bp-8h]@2
	void *this; // [sp+4h] [bp-4h]@1

	this = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\mdlrstyp.cpp", 90);
	if (this)
	{
		cModelResourceType::cModelResourceType((cModelResourceType *)this);
		v2 = v0;
	}
	else
	{
		v2 = 0;
	}
	return v2;
}

//----- (008DF8B0) --------------------------------------------------------
unsigned int __thiscall cModelResourceType::cRefCount::AddRef(cModelResourceType::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008DF8D0) --------------------------------------------------------
unsigned int __thiscall cModelResourceType::cRefCount::Release(cModelResourceType::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008DF8F0) --------------------------------------------------------
unsigned int __thiscall cModelResourceType::cRefCount::operator unsigned_long(cModelResourceType::cRefCount *this)
{
	return this->ul;
}

//----- (008DF900) --------------------------------------------------------
void __thiscall cModelResourceType::OnFinalRelease(cModelResourceType *this)
{
	operator delete(this);
}

//----- (008DF920) --------------------------------------------------------
void __thiscall cModelResourceType::cModelResourceType(cModelResourceType *this)
{
	cModelResourceType *v1; // ST00_4@1

	v1 = this;
	IResType::IResType(&this->baseclass_0);
	cModelResourceType::cRefCount::cRefCount(&v1->__m_ulRefs);
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cModelResourceType::_vftable_;
}
// 9A8098: using guessed type int (__stdcall *cModelResourceType___vftable_)(int this, int id, int ppI);

//----- (008DF950) --------------------------------------------------------
void __thiscall cModelResourceType::cRefCount::cRefCount(cModelResourceType::cRefCount *this)
{
	this->ul = 1;
}

//----- (008DF970) --------------------------------------------------------
void __thiscall IResType::IResType(IResType *this)
{
	IResType *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)IResType::_vftable_;
}
// 9A80B4: using guessed type int (*IResType___vftable_[7])();
