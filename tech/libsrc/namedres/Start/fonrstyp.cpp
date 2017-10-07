//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>



//----- (008DF990) --------------------------------------------------------
int __stdcall cFontResourceType::QueryInterface(cFontResourceType *this, _GUID *id, void **ppI)
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

//----- (008DF9FD) --------------------------------------------------------
unsigned int __stdcall cFontResourceType::AddRef(cFontResourceType *this)
{
	return cFontResourceType::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008DFA0F) --------------------------------------------------------
unsigned int __stdcall cFontResourceType::Release(cFontResourceType *this)
{
	unsigned int result; // eax@2

	if (cFontResourceType::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cFontResourceType::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cFontResourceType::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (008DFA3C) --------------------------------------------------------
const char *__stdcall cFontResourceType::GetName(cFontResourceType *this)
{
	return "Font";
}

//----- (008DFA48) --------------------------------------------------------
void __stdcall cFontResourceType::EnumerateExts(cFontResourceType *this, void(__cdecl *Callback)(const char *, IResType *, void *), void *pClientData)
{
	Callback(".fon", &this->baseclass_0, pClientData);
	Callback(".bin", &this->baseclass_0, pClientData);
}

//----- (008DFA75) --------------------------------------------------------
int __stdcall cFontResourceType::IsLegalExt(cFontResourceType *this, const char *pExt)
{
	return !_strcmpi(pExt, ".fon") || !_strcmpi(pExt, ".bin");
}

//----- (008DFAAF) --------------------------------------------------------
IRes *__stdcall cFontResourceType::CreateRes(cFontResourceType *this, IStore *pStore, const char *pName, const char *pExt, IResMemOverride **__formal)
{
	IRes *result; // eax@2
	int v6; // eax@4
	IRes *v7; // [sp+0h] [bp-Ch]@7
	int v8; // [sp+4h] [bp-8h]@4
	void *v9; // [sp+8h] [bp-4h]@3

	if (((int(__stdcall *)(cFontResourceType *, const char *))this->baseclass_0.baseclass_0.vfptr[1].Release)(
		this,
		pExt))
	{
		v9 = j__new(0x48u, "x:\\prj\\tech\\libsrc\\namedres\\fonrstyp.cpp", 84);
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
		DbgReportWarning("cFontResourceType called for illegal extension %s\n");
		result = 0;
	}
	return result;
}

//----- (008DFB39) --------------------------------------------------------
IResType *__cdecl MakeFontResourceType()
{
	IResType *v0; // eax@2
	IResType *v2; // [sp+0h] [bp-8h]@2
	void *this; // [sp+4h] [bp-4h]@1

	this = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\fonrstyp.cpp", 94);
	if (this)
	{
		cFontResourceType::cFontResourceType((cFontResourceType *)this);
		v2 = v0;
	}
	else
	{
		v2 = 0;
	}
	return v2;
}

//----- (008DFB80) --------------------------------------------------------
unsigned int __thiscall cFontResourceType::cRefCount::AddRef(cFontResourceType::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008DFBA0) --------------------------------------------------------
unsigned int __thiscall cFontResourceType::cRefCount::Release(cFontResourceType::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008DFBC0) --------------------------------------------------------
unsigned int __thiscall cFontResourceType::cRefCount::operator unsigned_long(cFontResourceType::cRefCount *this)
{
	return this->ul;
}

//----- (008DFBD0) --------------------------------------------------------
void __thiscall cFontResourceType::OnFinalRelease(cFontResourceType *this)
{
	operator delete(this);
}

//----- (008DFBF0) --------------------------------------------------------
void __thiscall cFontResourceType::cFontResourceType(cFontResourceType *this)
{
	cFontResourceType *v1; // ST00_4@1

	v1 = this;
	IResType::IResType(&this->baseclass_0);
	cFontResourceType::cRefCount::cRefCount(&v1->__m_ulRefs);
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cFontResourceType::_vftable_;
}
// 9A80D0: using guessed type int (__stdcall *cFontResourceType___vftable_)(int this, int id, int ppI);

//----- (008DFC20) --------------------------------------------------------
void __thiscall cFontResourceType::cRefCount::cRefCount(cFontResourceType::cRefCount *this)
{
	this->ul = 1;
}


