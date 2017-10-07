//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>




//----- (008DFC40) --------------------------------------------------------
int __stdcall cSoundResourceType::QueryInterface(cSoundResourceType *this, _GUID *id, void **ppI)
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

//----- (008DFCAD) --------------------------------------------------------
unsigned int __stdcall cSoundResourceType::AddRef(cSoundResourceType *this)
{
	return cSoundResourceType::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008DFCBF) --------------------------------------------------------
unsigned int __stdcall cSoundResourceType::Release(cSoundResourceType *this)
{
	unsigned int result; // eax@2

	if (cSoundResourceType::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cSoundResourceType::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cSoundResourceType::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (008DFCEC) --------------------------------------------------------
const char *__stdcall cSoundResourceType::GetName(cSoundResourceType *this)
{
	return "Sound";
}

//----- (008DFCF8) --------------------------------------------------------
void __stdcall cSoundResourceType::EnumerateExts(cSoundResourceType *this, void(__cdecl *Callback)(const char *, IResType *, void *), void *pClientData)
{
	Callback(".wav", &this->baseclass_0, pClientData);
	Callback(".voc", &this->baseclass_0, pClientData);
}

//----- (008DFD25) --------------------------------------------------------
int __stdcall cSoundResourceType::IsLegalExt(cSoundResourceType *this, const char *pExt)
{
	return !_strcmpi(pExt, ".wav") || !_strcmpi(pExt, ".voc");
}

//----- (008DFD5F) --------------------------------------------------------
IRes *__stdcall cSoundResourceType::CreateRes(cSoundResourceType *this, IStore *pStore, const char *pName, const char *pExt, IResMemOverride **__formal)
{
	IRes *result; // eax@2
	int v6; // eax@4
	IRes *v7; // [sp+0h] [bp-Ch]@7
	int v8; // [sp+4h] [bp-8h]@4
	void *v9; // [sp+8h] [bp-4h]@3

	if (((int(__stdcall *)(cSoundResourceType *, const char *))this->baseclass_0.baseclass_0.vfptr[1].Release)(
		this,
		pExt))
	{
		v9 = j__new(0x48u, "x:\\prj\\tech\\libsrc\\namedres\\sndrstyp.cpp", 82);
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
		DbgReportWarning("cSoundResourceType called for illegal extension %s\n");
		result = 0;
	}
	return result;
}

//----- (008DFDE9) --------------------------------------------------------
IResType *__cdecl MakeSoundResourceType()
{
	IResType *v0; // eax@2
	IResType *v2; // [sp+0h] [bp-8h]@2
	void *this; // [sp+4h] [bp-4h]@1

	this = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\sndrstyp.cpp", 92);
	if (this)
	{
		cSoundResourceType::cSoundResourceType((cSoundResourceType *)this);
		v2 = v0;
	}
	else
	{
		v2 = 0;
	}
	return v2;
}

//----- (008DFE30) --------------------------------------------------------
unsigned int __thiscall cSoundResourceType::cRefCount::AddRef(cSoundResourceType::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008DFE50) --------------------------------------------------------
unsigned int __thiscall cSoundResourceType::cRefCount::Release(cSoundResourceType::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008DFE70) --------------------------------------------------------
unsigned int __thiscall cSoundResourceType::cRefCount::operator unsigned_long(cSoundResourceType::cRefCount *this)
{
	return this->ul;
}

//----- (008DFE80) --------------------------------------------------------
void __thiscall cSoundResourceType::OnFinalRelease(cSoundResourceType *this)
{
	operator delete(this);
}

//----- (008DFEA0) --------------------------------------------------------
void __thiscall cSoundResourceType::cSoundResourceType(cSoundResourceType *this)
{
	cSoundResourceType *v1; // ST00_4@1

	v1 = this;
	IResType::IResType(&this->baseclass_0);
	cSoundResourceType::cRefCount::cRefCount(&v1->__m_ulRefs);
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cSoundResourceType::_vftable_;
}
// 9A80EC: using guessed type int (__stdcall *cSoundResourceType___vftable_)(int this, int id, int ppI);

//----- (008DFED0) --------------------------------------------------------
void __thiscall cSoundResourceType::cRefCount::cRefCount(cSoundResourceType::cRefCount *this)
{
	this->ul = 1;
}
