//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include <arqapi.h>
#include "arqstrrd.h"





/*

//----- (008D15A0) --------------------------------------------------------
int __stdcall cAsyncStreamReader::QueryInterface(cAsyncStreamReader *this, _GUID *id, void **ppI)
{
	int result; // eax@5

	if (id != &IID_IAsyncReadFulfiller
		&& id != &IID_IUnknown
		&& memcmp(id, &IID_IAsyncReadFulfiller, 0x10u)
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

//----- (008D160D) --------------------------------------------------------
unsigned int __stdcall cAsyncStreamReader::AddRef(cAsyncStreamReader *this)
{
	return cAsyncStreamReader::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008D161F) --------------------------------------------------------
unsigned int __stdcall cAsyncStreamReader::Release(cAsyncStreamReader *this)
{
	unsigned int result; // eax@2

	if (cAsyncStreamReader::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cAsyncStreamReader::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cAsyncStreamReader::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (008D164C) --------------------------------------------------------
int __stdcall cAsyncStreamReader::DoFulfill(cAsyncStreamReader *this, sARQRequest *__formal, sARQResult *pResult)
{
	if (!this->m_StreamRequest.pBufOut || this->m_StreamRequest.flags & 1)
		_CriticalMsg("Dynamic ARQ requests not yet supported", "x:\\prj\\tech\\libsrc\\arq\\arqstrrd.cpp", 0x25u);
	if (this->m_StreamRequest.offset != -1)
		((void(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->m_StreamRequest.pSource->baseclass_0.baseclass_0.vfptr[1].Release)(
		this->m_StreamRequest.pSource,
		this->m_StreamRequest.offset,
		(unsigned __int64)this->m_StreamRequest.offset >> 32,
		0,
		0);
	((void(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->m_StreamRequest.pSource->baseclass_0.baseclass_0.vfptr[1].QueryInterface)(
		this->m_StreamRequest.pSource,
		this->m_StreamRequest.pBufOut,
		this->m_StreamRequest.length,
		0);
	pResult->result = 0;
	pResult->buffer = this->m_StreamRequest.pBufOut;
	pResult->length = this->m_StreamRequest.length;
	pResult->flags = 0;
	pResult->streamIndex = 0;
	if (this->m_StreamRequest.pSource)
		this->m_StreamRequest.pSource->baseclass_0.baseclass_0.vfptr->Release((IUnknown *)this->m_StreamRequest.pSource);
	this->m_StreamRequest.pSource = 0;
	return 0;
}

//----- (008D1739) --------------------------------------------------------
int __stdcall cAsyncStreamReader::DoKill(cAsyncStreamReader *this, sARQRequest *__formal, int a3)
{
	if (this->m_StreamRequest.pSource)
		this->m_StreamRequest.pSource->baseclass_0.baseclass_0.vfptr->Release((IUnknown *)this->m_StreamRequest.pSource);
	this->m_StreamRequest.pSource = 0;
	return 0;
}

//----- (008D1770) --------------------------------------------------------
unsigned int __thiscall cAsyncStreamReader::cRefCount::AddRef(cAsyncStreamReader::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008D1790) --------------------------------------------------------
unsigned int __thiscall cAsyncStreamReader::cRefCount::Release(cAsyncStreamReader::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008D17B0) --------------------------------------------------------
unsigned int __thiscall cAsyncStreamReader::cRefCount::operator unsigned_long(cAsyncStreamReader::cRefCount *this)
{
	return this->ul;
}

//----- (008D17C0) --------------------------------------------------------
void __thiscall cAsyncStreamReader::OnFinalRelease(cAsyncStreamReader *this)
{
	if (this)
		((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[1].Release)(this, 1);
}


//----- (008D0630) --------------------------------------------------------
void __thiscall cAsyncStreamReader::cAsyncStreamReader(cAsyncStreamReader *this, sARQStreamRequest *streamRequest)
{
	cAsyncStreamReader *v2; // ST0C_4@1

	v2 = this;
	IAsyncReadFulfiller::IAsyncReadFulfiller(&this->baseclass_0);
	cAsyncStreamReader::cRefCount::cRefCount(&v2->__m_ulRefs);
	memcpy(&v2->m_StreamRequest, streamRequest, sizeof(v2->m_StreamRequest));
	v2->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cAsyncStreamReader::_vftable_;
	v2->m_StreamRequest.pSource->baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)v2->m_StreamRequest.pSource);
}
// 9A78EC: using guessed type int (__stdcall *cAsyncStreamReader___vftable_)(int this, int id, int ppI);

//----- (008D0690) --------------------------------------------------------
void __thiscall cAsyncStreamReader::cRefCount::cRefCount(cAsyncStreamReader::cRefCount *this)
{
	this->ul = 1;
}

//----- (008D06B0) --------------------------------------------------------
void *__thiscall cAsyncStreamReader::_scalar_deleting_destructor_(cAsyncStreamReader *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cAsyncStreamReader::_cAsyncStreamReader(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008D0700) --------------------------------------------------------
void __thiscall cAsyncStreamReader::_cAsyncStreamReader(cAsyncStreamReader *this)
{
	cAsyncStreamReader *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cAsyncStreamReader::_vftable_;
	if (this->m_StreamRequest.pSource)
		this->m_StreamRequest.pSource->baseclass_0.baseclass_0.vfptr->Release((IUnknown *)this->m_StreamRequest.pSource);
	thisa->m_StreamRequest.pSource = 0;
}
// 9A78EC: using guessed type int (__stdcall *cAsyncStreamReader___vftable_)(int this, int id, int ppI);



*/