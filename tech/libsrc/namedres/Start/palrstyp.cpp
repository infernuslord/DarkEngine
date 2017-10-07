//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>


//----- (008E0630) --------------------------------------------------------
int __stdcall cPaletteResourceType::QueryInterface(cPaletteResourceType *this, _GUID *id, void **ppI)
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

//----- (008E069D) --------------------------------------------------------
unsigned int __stdcall cPaletteResourceType::AddRef(cPaletteResourceType *this)
{
	return cPaletteResourceType::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008E06AF) --------------------------------------------------------
unsigned int __stdcall cPaletteResourceType::Release(cPaletteResourceType *this)
{
	unsigned int result; // eax@2

	if (cPaletteResourceType::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cPaletteResourceType::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cPaletteResourceType::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (008E06DC) --------------------------------------------------------
const char *__stdcall cPaletteResourceType::GetName(cPaletteResourceType *this)
{
	return "Palette";
}

//----- (008E06E8) --------------------------------------------------------
void __stdcall cPaletteResourceType::EnumerateExts(cPaletteResourceType *this, void(__cdecl *Callback)(const char *, IResType *, void *), void *pClientData)
{
	const char **pMap; // [sp+0h] [bp-4h]@1

	for (pMap = (const char **)extMaps_1; *pMap; pMap += 2)
		Callback(*pMap, &this->baseclass_0, pClientData);
}

//----- (008E0720) --------------------------------------------------------
int __stdcall cPaletteResourceType::IsLegalExt(cPaletteResourceType *this, const char *pExt)
{
	const char **pMap; // [sp+0h] [bp-4h]@1

	for (pMap = (const char **)extMaps_1; *pMap; pMap += 2)
	{
		if (!_strcmpi(pExt, *pMap))
			return 1;
	}
	return 0;
}

//----- (008E0763) --------------------------------------------------------
IRes *__stdcall cPaletteResourceType::CreateRes(cPaletteResourceType *this, IStore *pStore, const char *pName, const char *pExt, IResMemOverride **__formal)
{
	const char *v5; // eax@7
	IRes *result; // eax@7
	int v7; // eax@9
	IRes *v8; // [sp+0h] [bp-14h]@12
	int v9; // [sp+4h] [bp-10h]@9
	void *v10; // [sp+8h] [bp-Ch]@8
	ePalKind Kind; // [sp+Ch] [bp-8h]@0
	sExtMap *pMap; // [sp+10h] [bp-4h]@1

	for (pMap = extMaps_1; pMap->ext; ++pMap)
	{
		if (!_strcmpi(pExt, pMap->ext))
		{
			Kind = pMap->kind;
			break;
		}
	}
	if (pMap->ext)
	{
		v10 = j__new(0x4Cu, "x:\\prj\\tech\\libsrc\\namedres\\palrstyp.cpp", 122);
		if (v10)
		{
			cPaletteResource::cPaletteResource((cPaletteResource *)v10, pStore, pName, &this->baseclass_0, Kind);
			v9 = v7;
		}
		else
		{
			v9 = 0;
		}
		if (v9)
			v8 = (IRes *)(v9 + 8);
		else
			v8 = 0;
		result = v8;
	}
	else
	{
		v5 = _LogFmt("Invalid extension %s given to create palette resource!");
		_CriticalMsg(v5, "x:\\prj\\tech\\libsrc\\namedres\\palrstyp.cpp", 0x75u);
		result = 0;
	}
	return result;
}

//----- (008E082D) --------------------------------------------------------
IResType *__cdecl MakePaletteResourceType()
{
	IResType *v0; // eax@2
	IResType *v2; // [sp+0h] [bp-8h]@2
	void *this; // [sp+4h] [bp-4h]@1

	this = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\palrstyp.cpp", 132);
	if (this)
	{
		cPaletteResourceType::cPaletteResourceType((cPaletteResourceType *)this);
		v2 = v0;
	}
	else
	{
		v2 = 0;
	}
	return v2;
}

//----- (008E0870) --------------------------------------------------------
unsigned int __thiscall cPaletteResourceType::cRefCount::AddRef(cPaletteResourceType::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008E0890) --------------------------------------------------------
unsigned int __thiscall cPaletteResourceType::cRefCount::Release(cPaletteResourceType::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008E08B0) --------------------------------------------------------
unsigned int __thiscall cPaletteResourceType::cRefCount::operator unsigned_long(cPaletteResourceType::cRefCount *this)
{
	return this->ul;
}

//----- (008E08C0) --------------------------------------------------------
void __thiscall cPaletteResourceType::OnFinalRelease(cPaletteResourceType *this)
{
	operator delete(this);
}

//----- (008E08E0) --------------------------------------------------------
void __thiscall cPaletteResourceType::cPaletteResourceType(cPaletteResourceType *this)
{
	cPaletteResourceType *v1; // ST00_4@1

	v1 = this;
	IResType::IResType(&this->baseclass_0);
	cPaletteResourceType::cRefCount::cRefCount(&v1->__m_ulRefs);
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cPaletteResourceType::_vftable_;
}
// 9A8180: using guessed type int (__stdcall *cPaletteResourceType___vftable_)(int this, int id, int ppI);

//----- (008E0910) --------------------------------------------------------
void __thiscall cPaletteResourceType::cRefCount::cRefCount(cPaletteResourceType::cRefCount *this)
{
	this->ul = 1;
}
