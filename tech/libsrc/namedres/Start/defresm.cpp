//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>




//----- (008E1A40) --------------------------------------------------------
int __stdcall cDefResMem::QueryInterface(cDefResMem *this, _GUID *id, void **ppI)
{
	int result; // eax@5

	if (id != &IID_IResMemOverride
		&& id != &IID_IUnknown
		&& memcmp(id, &IID_IResMemOverride, 0x10u)
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

//----- (008E1AAD) --------------------------------------------------------
unsigned int __stdcall cDefResMem::AddRef(cDefResMem *this)
{
	return cDefResMem::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008E1ABF) --------------------------------------------------------
unsigned int __stdcall cDefResMem::Release(cDefResMem *this)
{
	unsigned int result; // eax@2

	if (cDefResMem::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cDefResMem::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cDefResMem::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (008E1AEC) --------------------------------------------------------
void *__stdcall cDefResMem::ResMalloc(cDefResMem *this, unsigned int nNumBytes)
{
	return MallocSpew(nNumBytes, "x:\\prj\\tech\\libsrc\\namedres\\defresm.cpp", 22);
}

//----- (008E1B06) --------------------------------------------------------
void __stdcall cDefResMem::ResFree(cDefResMem *this, void *pData)
{
	FreeSpew(pData, "x:\\prj\\tech\\libsrc\\namedres\\defresm.cpp", 26);
}

//----- (008E1B20) --------------------------------------------------------
unsigned int __stdcall cDefResMem::GetSize(cDefResMem *this, void *pData)
{
	return f_msize(pData);
}
// B1950C: using guessed type int (__cdecl *f_msize)(_DWORD);

//----- (008E1B34) --------------------------------------------------------
void __thiscall cDefResMem::OnFinalRelease(cDefResMem *this)
{
	;
}

//----- (008E1B40) --------------------------------------------------------
unsigned int __thiscall cDefResMem::cRefCount::AddRef(cDefResMem::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008E1B60) --------------------------------------------------------
unsigned int __thiscall cDefResMem::cRefCount::Release(cDefResMem::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008E1B80) --------------------------------------------------------
unsigned int __thiscall cDefResMem::cRefCount::operator unsigned_long(cDefResMem::cRefCount *this)
{
	return this->ul;
}