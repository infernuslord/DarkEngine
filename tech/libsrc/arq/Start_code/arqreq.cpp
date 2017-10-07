//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include <arqapi.h>
#include <thrdtool.h>
#include "arqqueue.h"
#include "arqreq.h"






/*

//----- (008D105D) --------------------------------------------------------
unsigned int cARQRequest::AddRef()
{
	return cARQRequest::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008D106F) --------------------------------------------------------
unsigned int cARQRequest::Release()
{
	unsigned int result; // eax@2

	if (cARQRequest::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cARQRequest::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cARQRequest::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (008D109C) --------------------------------------------------------
cARQRequest::~cARQRequest()
{
	cARQRequest *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cARQRequest::_vftable_;
	if (this->m_ReqInfo.pFulfiller)
		this->m_ReqInfo.pFulfiller->baseclass_0.vfptr->Release((IUnknown *)this->m_ReqInfo.pFulfiller);
	thisa->m_ReqInfo.pFulfiller = 0;
	cThreadLock::_cThreadLock(&thisa->m_Lock);
}
// 9A78A8: using guessed type int (__stdcall *cARQRequest___vftable_)(int this, int id, int ppI);

//----- (008D10E0) --------------------------------------------------------
int __stdcall cARQRequest::IsFulfilled()
{
	return this->m_State == 3;
}

//----- (008D10F5) --------------------------------------------------------
int cARQRequest::Fulfill()
{
	cThreadLock *queueLock; // [sp+Ch] [bp-Ch]@3
	int retVal; // [sp+10h] [bp-8h]@7
	cAutoLock autoLock; // [sp+14h] [bp-4h]@1

	cAutoLock::cAutoLock(&autoLock, &this->m_Lock);
	this->baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)this);
	switch (this->m_State)
	{
	case 0:
	case 1:
		if (this->m_pOwningQueue)
		{
			queueLock = &this->m_pOwningQueue->m_Lock;
			cThreadLock::Lock(&this->m_pOwningQueue->m_Lock);
			if (this->m_pOwningQueue)
				cARQRequestQueue::RemoveRequest(this->m_pOwningQueue, this);
			cThreadLock::Unlock(queueLock);
			if (this->m_pOwningQueue)
				_CriticalMsg("RemoveRequest() failed", "x:\\prj\\tech\\libsrc\\arq\\arqreq.cpp", 0x4Du);
		}
		this->m_State = 2;
		retVal = this->m_ReqInfo.pFulfiller->baseclass_0.vfptr[1].QueryInterface(
			(IUnknown *)this->m_ReqInfo.pFulfiller,
			(_GUID *)&this->m_ReqInfo,
			(void **)&this->m_Result);
		if (this->m_ReqInfo.pFulfiller)
			this->m_ReqInfo.pFulfiller->baseclass_0.vfptr->Release((IUnknown *)this->m_ReqInfo.pFulfiller);
		this->m_ReqInfo.pFulfiller = 0;
		if (retVal > -2147024882)
		{
			if (!retVal)
				goto LABEL_17;
			goto LABEL_16;
		}
		if (retVal != -2147024882 && retVal != -2147467259 && retVal != -2147024891)
		LABEL_16:
		retVal = -2147467259;
	LABEL_17:
		this->m_State = 3;
	LABEL_22:
		this->baseclass_0.baseclass_0.vfptr->Release((IUnknown *)this);
		cAutoLock::_cAutoLock(&autoLock);
		return retVal;
	case 2:
		_CriticalMsg(
			"Should not be able to use request while in progress",
			"x:\\prj\\tech\\libsrc\\arq\\arqreq.cpp",
			0x6Au);
		goto $L43811;
	case 3:
	$L43811 :
		retVal = 0;
			goto LABEL_22;
	case 4:
		retVal = -2147467259;
		goto LABEL_22;
	default:
		_CriticalMsg("Unknown ARQ request state", "x:\\prj\\tech\\libsrc\\arq\\arqreq.cpp", 0x76u);
		retVal = -2147467259;
		goto LABEL_22;
	}
}

//----- (008D129F) --------------------------------------------------------
int cARQRequest::Kill(int fDiscard)
{
	cThreadLock *v2; // ST18_4@3
	unsigned int v3; // eax@11
	int retVal; // [sp+10h] [bp-8h]@5
	cAutoLock autoLock; // [sp+14h] [bp-4h]@1

	cAutoLock::cAutoLock(&autoLock, &this->m_Lock);
	this->baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)this);
	switch (this->m_State)
	{
	case 0:
	case 1:
		if (this->m_pOwningQueue)
		{
			v2 = &this->m_pOwningQueue->m_Lock;
			cThreadLock::Lock(&this->m_pOwningQueue->m_Lock);
			cARQRequestQueue::RemoveRequest(this->m_pOwningQueue, this);
			cThreadLock::Unlock(v2);
			if (this->m_pOwningQueue)
				_CriticalMsg("RemoveRequest() failed", "x:\\prj\\tech\\libsrc\\arq\\arqreq.cpp", 0x99u);
		}
		retVal = ((int(__stdcall *)(IAsyncReadFulfiller *, sARQRequest *, int))this->m_ReqInfo.pFulfiller->baseclass_0.vfptr[1].AddRef)(
			this->m_ReqInfo.pFulfiller,
			&this->m_ReqInfo,
			fDiscard);
		if (this->m_ReqInfo.pFulfiller)
			this->m_ReqInfo.pFulfiller->baseclass_0.vfptr->Release((IUnknown *)this->m_ReqInfo.pFulfiller);
		this->m_ReqInfo.pFulfiller = 0;
		if (retVal != -2147467259 && retVal)
			retVal = -2147467259;
		this->m_Result.result = 1;
		v3 = this->m_Result.flags;
		LOBYTE(v3) = v3 | 4;
		this->m_Result.flags = v3;
		this->m_State = 4;
		break;
	case 4:
		retVal = 0;
		break;
	case 2:
	case 3:
		retVal = -2147467259;
		break;
	default:
		_CriticalMsg("Unknown ARQ request state", "x:\\prj\\tech\\libsrc\\arq\\arqreq.cpp", 0xBFu);
		retVal = -2147467259;
		break;
	}
	this->baseclass_0.baseclass_0.vfptr->Release((IUnknown *)this);
	cAutoLock::_cAutoLock(&autoLock);
	return retVal;
}

//----- (008D1423) --------------------------------------------------------
int cARQRequest::GetResult(sARQResult *pResult)
{
	int retVal; // [sp+10h] [bp-8h]@2
	cAutoLock autoLock; // [sp+14h] [bp-4h]@1

	cAutoLock::cAutoLock(&autoLock, &this->m_Lock);
	this->baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)this);
	switch (this->m_State)
	{
	case 0:
	case 1:
	case 2:
		retVal = 1;
		break;
	case 3:
	case 4:
		memcpy(pResult, &this->m_Result, 0x14u);
		retVal = 0;
		break;
	default:
		_CriticalMsg("Unknown ARQ request state", "x:\\prj\\tech\\libsrc\\arq\\arqreq.cpp", 0xE5u);
		retVal = -2147467259;
		break;
	}
	this->baseclass_0.baseclass_0.vfptr->Release((IUnknown *)this);
	cAutoLock::_cAutoLock(&autoLock);
	return retVal;
}

//----- (008D14D5) --------------------------------------------------------
int cARQRequest::IsFinished()
{
	return this->m_State == 4 || this->m_State == 3;
}

//----- (008D1510) --------------------------------------------------------
unsigned int __thiscall cARQRequest::cRefCount::AddRef(cARQRequest::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008D1530) --------------------------------------------------------
unsigned int __thiscall cARQRequest::cRefCount::Release(cARQRequest::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008D1550) --------------------------------------------------------
unsigned int __thiscall cARQRequest::cRefCount::operator unsigned_long(cARQRequest::cRefCount *this)
{
	return this->ul;
}

//----- (008D1560) --------------------------------------------------------
void __thiscall cARQRequest::OnFinalRelease(cARQRequest *this)
{
	if (this)
		((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[2].Release)(this, 1);
}


//----- (008D0500) --------------------------------------------------------
void __thiscall cARQRequest::cARQRequest(cARQRequest *this, sARQRequest *reqInfo)
{
	cARQRequest *v2; // ST14_4@1

	v2 = this;
	IAsyncReadControl::IAsyncReadControl(&this->baseclass_0);
	cDListNode<cARQRequest_1>::cDListNode<cARQRequest_1>(&v2->baseclass_4);
	cARQRequest::cRefCount::cRefCount(&v2->__m_ulRefs);
	memcpy(&v2->m_ReqInfo, reqInfo, sizeof(v2->m_ReqInfo));
	cThreadLock::cThreadLock(&v2->m_Lock);
	v2->m_State = 0;
	v2->m_pOwningQueue = 0;
	v2->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cARQRequest::_vftable_;
	v2->m_ReqInfo.queue = 0;
	v2->m_ReqInfo.pFulfiller->baseclass_0.vfptr->AddRef((IUnknown *)v2->m_ReqInfo.pFulfiller);
	memset(&v2->m_Result, 0, 0x14u);
}
// 9A78A8: using guessed type int (__stdcall *cARQRequest___vftable_)(int this, int id, int ppI);

//----- (008D05A0) --------------------------------------------------------
void __thiscall cARQRequest::cRefCount::cRefCount(cARQRequest::cRefCount *this)
{
	this->ul = 1;
}

//----- (008D05C0) --------------------------------------------------------
void *__thiscall cARQRequest::_scalar_deleting_destructor_(cARQRequest *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cARQRequest::_cARQRequest(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}


//----- (008D0B30) --------------------------------------------------------
int __thiscall cARQRequest::GetQueueID(cARQRequest *this)
{
	return this->m_ReqInfo.queue;
}

//----- (008D0B50) --------------------------------------------------------
void __thiscall cARQRequest::SetOwningQueue(cARQRequest *this, cARQRequestQueue *pOwningQueue)
{
	cARQRequest *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (pOwningQueue && this->m_State)
		_CriticalMsg("Can only queue unserviced requests", "x:\\prj\\tech\\libsrc\\arq\\arqreq.h", 0x8Bu);
	thisa->m_pOwningQueue = pOwningQueue;
	thisa->m_State = 1;
}


//----- (008D0FF0) --------------------------------------------------------
int __stdcall cARQRequest::QueryInterface(cARQRequest *this, _GUID *id, void **ppI)
{
	int result; // eax@5

	if (id != &IID_IAsyncReadControl
		&& id != &IID_IUnknown
		&& memcmp(id, &IID_IAsyncReadControl, 0x10u)
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



//----- (008D07B0) --------------------------------------------------------
int __thiscall cARQRequest::GetPriority(cARQRequest *this)
{
	return this->m_ReqInfo.priority;
}

*/