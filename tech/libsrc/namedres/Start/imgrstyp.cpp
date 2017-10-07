//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>



//----- (008E0340) --------------------------------------------------------
int __stdcall cImageResourceType::QueryInterface(cImageResourceType *this, _GUID *id, void **ppI)
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

//----- (008E03AD) --------------------------------------------------------
unsigned int __stdcall cImageResourceType::AddRef(cImageResourceType *this)
{
	return cImageResourceType::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008E03BF) --------------------------------------------------------
unsigned int __stdcall cImageResourceType::Release(cImageResourceType *this)
{
	unsigned int result; // eax@2

	if (cImageResourceType::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cImageResourceType::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cImageResourceType::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (008E03EC) --------------------------------------------------------
const char *__stdcall cImageResourceType::GetName(cImageResourceType *this)
{
	return "Image";
}

//----- (008E03F8) --------------------------------------------------------
void __stdcall cImageResourceType::EnumerateExts(cImageResourceType *this, void(__cdecl *Callback)(const char *, IResType *, void *), void *pClientData)
{
	const char **pMap; // [sp+0h] [bp-4h]@1

	for (pMap = (const char **)extMaps; *pMap; pMap += 2)
		Callback(*pMap, &this->baseclass_0, pClientData);
}

//----- (008E0430) --------------------------------------------------------
int __stdcall cImageResourceType::IsLegalExt(cImageResourceType *this, const char *pExt)
{
	const char **pMap; // [sp+0h] [bp-4h]@1

	for (pMap = (const char **)extMaps; *pMap; pMap += 2)
	{
		if (!_strcmpi(pExt, *pMap))
			return 1;
	}
	return 0;
}

//----- (008E0473) --------------------------------------------------------
IRes *__stdcall cImageResourceType::CreateRes(cImageResourceType *this, IStore *pStore, const char *pName, const char *pExt, IResMemOverride **__formal)
{
	IRes *result; // eax@7
	int v6; // eax@9
	IRes *v7; // [sp+0h] [bp-14h]@12
	int v8; // [sp+4h] [bp-10h]@9
	void *v9; // [sp+8h] [bp-Ch]@8
	eImgKind Kind; // [sp+Ch] [bp-8h]@0
	sExtMap *pMap; // [sp+10h] [bp-4h]@1

	for (pMap = extMaps; pMap->ext; ++pMap)
	{
		if (!_strcmpi(pExt, pMap->ext))
		{
			Kind = pMap->kind;
			break;
		}
	}
	if (pMap->ext)
	{
		v9 = j__new(0x4Cu, "x:\\prj\\tech\\libsrc\\namedres\\imgrstyp.cpp", 122);
		if (v9)
		{
			cImageResource::cImageResource((cImageResource *)v9, pStore, pName, &this->baseclass_0, Kind);
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
		DbgReportWarning("Invalid extension %s given to create image resource!");
		result = 0;
	}
	return result;
}

//----- (008E0530) --------------------------------------------------------
IResType *__cdecl MakeImageResourceType()
{
	IResType *v0; // eax@2
	IResType *v2; // [sp+0h] [bp-8h]@2
	void *this; // [sp+4h] [bp-4h]@1

	this = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\imgrstyp.cpp", 132);
	if (this)
	{
		cImageResourceType::cImageResourceType((cImageResourceType *)this);
		v2 = v0;
	}
	else
	{
		v2 = 0;
	}
	return v2;
}

//----- (008E0570) --------------------------------------------------------
unsigned int __thiscall cImageResourceType::cRefCount::AddRef(cImageResourceType::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008E0590) --------------------------------------------------------
unsigned int __thiscall cImageResourceType::cRefCount::Release(cImageResourceType::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008E05B0) --------------------------------------------------------
unsigned int __thiscall cImageResourceType::cRefCount::operator unsigned_long(cImageResourceType::cRefCount *this)
{
	return this->ul;
}

//----- (008E05C0) --------------------------------------------------------
void __thiscall cImageResourceType::OnFinalRelease(cImageResourceType *this)
{
	operator delete(this);
}

//----- (008E05E0) --------------------------------------------------------
void __thiscall cImageResourceType::cImageResourceType(cImageResourceType *this)
{
	cImageResourceType *v1; // ST00_4@1

	v1 = this;
	IResType::IResType(&this->baseclass_0);
	cImageResourceType::cRefCount::cRefCount(&v1->__m_ulRefs);
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cImageResourceType::_vftable_;
}
// 9A8164: using guessed type int (__stdcall *cImageResourceType___vftable_)(int this, int id, int ppI);

//----- (008E0610) --------------------------------------------------------
void __thiscall cImageResourceType::cRefCount::cRefCount(cImageResourceType::cRefCount *this)
{
	this->ul = 1;
}


