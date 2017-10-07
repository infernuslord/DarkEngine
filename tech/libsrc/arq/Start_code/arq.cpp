//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include <arqapi.h>
#include "arq.h"






/*
//----- (008CFA98) --------------------------------------------------------
int __stdcall cARQManager::QueryInterface(cARQManager *this, _GUID *id, void **ppI)
{
	IUnknown *v3; // eax@1

	v3 = cARQManager::cOuterPointer::operator_ > (&this->__m_pOuterUnknown);
	return ((int(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))v3->vfptr->QueryInterface)(v3, id, ppI, v3);
}

//----- (008CFAC3) --------------------------------------------------------
unsigned int __stdcall cARQManager::AddRef(cARQManager *this)
{
	IUnknown *v1; // eax@1

	v1 = cARQManager::cOuterPointer::operator_ > (&this->__m_pOuterUnknown);
	return ((int(__stdcall *)(_DWORD, _DWORD))v1->vfptr->AddRef)(v1, v1);
}

//----- (008CFAE7) --------------------------------------------------------
unsigned int __stdcall cARQManager::Release(cARQManager *this)
{
	IUnknown *v1; // eax@1

	v1 = cARQManager::cOuterPointer::operator_ > (&this->__m_pOuterUnknown);
	return ((int(__stdcall *)(_DWORD, _DWORD))v1->vfptr->Release)(v1, v1);
}

//----- (008CFB0B) --------------------------------------------------------
int __stdcall cARQManager::cComplexAggregateControl::Connect(cARQManager::cComplexAggregateControl *this)
{
	int result; // eax@2

	if (this->m_pAggregateMember)
		result = cARQManager::Connect(this->m_pAggregateMember);
	else
		result = 0;
	return result;
}

//----- (008CFB2A) --------------------------------------------------------
int __stdcall cARQManager::cComplexAggregateControl::PostConnect(cARQManager::cComplexAggregateControl *this)
{
	int result; // eax@2

	if (this->m_pAggregateMember)
		result = cARQManager::PostConnect(this->m_pAggregateMember);
	else
		result = 0;
	return result;
}

//----- (008CFB49) --------------------------------------------------------
int __stdcall cARQManager::cComplexAggregateControl::Init(cARQManager::cComplexAggregateControl *this)
{
	int result; // eax@2

	if (this->m_pAggregateMember)
		result = cARQManager::Init(this->m_pAggregateMember);
	else
		result = 0;
	return result;
}

//----- (008CFB68) --------------------------------------------------------
int __stdcall cARQManager::cComplexAggregateControl::End(cARQManager::cComplexAggregateControl *this)
{
	int result; // eax@2

	if (this->m_pAggregateMember)
		result = cARQManager::End(this->m_pAggregateMember);
	else
		result = 0;
	return result;
}

//----- (008CFB87) --------------------------------------------------------
int __stdcall cARQManager::cComplexAggregateControl::Disconnect(cARQManager::cComplexAggregateControl *this)
{
	int result; // eax@2

	if (this->m_pAggregateMember)
		result = cARQManager::Disconnect(this->m_pAggregateMember);
	else
		result = 0;
	return result;
}

//----- (008CFBA6) --------------------------------------------------------
int __stdcall cARQManager::cComplexAggregateControl::QueryInterface(cARQManager::cComplexAggregateControl *this, _GUID *id, void **ppI)
{
	int result; // eax@5

	if (id != &IID_IAggregateMemberControl
		&& id != &IID_IUnknown
		&& memcmp(id, &IID_IAggregateMemberControl, 16u)
		&& memcmp(id, &IID_IUnknown, 16u))
	{
		*ppI = 0;
		result = 0x80004002u;
	}
	else
	{
		*ppI = this;
		this->baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)this);
		result = 0;
	}
	return result;
}

//----- (008CFC13) --------------------------------------------------------
unsigned int __stdcall cARQManager::cComplexAggregateControl::AddRef(cARQManager::cComplexAggregateControl *this)
{
	return cARQManager::cComplexAggregateControl::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008CFC25) --------------------------------------------------------
unsigned int __stdcall cARQManager::cComplexAggregateControl::Release(cARQManager::cComplexAggregateControl *this)
{
	unsigned int result; // eax@2

	if (cARQManager::cComplexAggregateControl::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cARQManager::cComplexAggregateControl::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cARQManager::cComplexAggregateControl::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (008CFC52) --------------------------------------------------------
void __thiscall cARQManager::cARQManager(cARQManager *this, IUnknown *pOuterUnknown)
{
	cARQManager *thisa; // [sp+0h] [bp-30h]@1
	sAggAddInfo aAggAddInfo; // [sp+8h] [bp-28h]@2
	sRelativeConstraint constraints[2]; // [sp+20h] [bp-10h]@1

	thisa = this;
	IAsyncReadQueue::IAsyncReadQueue(&this->baseclass_0);
	cARQManager::cOuterPointer::cOuterPointer(&thisa->__m_pOuterUnknown);
	cARQManager::cComplexAggregateControl::cComplexAggregateControl(&thisa->__m_AggregateControl);
	cARQRequestQueue::cARQRequestQueue(&thisa->m_RequestQueue, 0);
	cARQFulfillerThread::cARQFulfillerThread(&thisa->m_Fulfiller, &thisa->m_RequestQueue);
	thisa->m_iSuspendCount = 0;
	thisa->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cARQManager::_vftable_;
	constraints[0].kind = 2;
	constraints[0].pIDAgainst = &IID_IGameShell;
	constraints[1].kind = 0;
	constraints[1].pIDAgainst = 0;
	cARQManager::cOuterPointer::Init(&thisa->__m_pOuterUnknown, pOuterUnknown);
	cARQManager::cComplexAggregateControl::InitControl(&thisa->__m_AggregateControl, thisa);
	if (pOuterUnknown)
	{
		aAggAddInfo.pID = &IID_IAsyncReadQueue;
		aAggAddInfo.pszName = "IID_IAsyncReadQueue";
		aAggAddInfo.pAggregated = (IUnknown *)thisa;
		aAggAddInfo.pControl = (IUnknown *)&thisa->__m_AggregateControl;
		aAggAddInfo.controlPriority = 4096;
		aAggAddInfo.pControlConstraints = constraints;
		_AddToAggregate(pOuterUnknown, &aAggAddInfo, 1u);
	}
	thisa->__m_AggregateControl.baseclass_0.baseclass_0.vfptr->Release((IUnknown *)&thisa->__m_AggregateControl);
}
// 9A781C: using guessed type int (__stdcall *cARQManager___vftable_)(int this, int id, int ppI);

//----- (008CFD7C) --------------------------------------------------------
void __thiscall cARQManager::_cARQManager(cARQManager *this)
{
	cARQManager *v1; // ST00_4@1

	v1 = this;
	this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cARQManager::_vftable_;
	cARQFulfillerThread::_cARQFulfillerThread(&this->m_Fulfiller);
	cARQRequestQueue::_cARQRequestQueue(&v1->m_RequestQueue);
}
// 9A781C: using guessed type int (__stdcall *cARQManager___vftable_)(int this, int id, int ppI);

//----- (008CFDA6) --------------------------------------------------------
int __thiscall cARQManager::Init(cARQManager *this)
{
	int result; // eax@2
	cARQManager *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (cWorkerThread::Create(&this->m_Fulfiller.baseclass_0))
	{
		cARQManager::BalanceThreadPriority(thisa);
		result = 0;
	}
	else
	{
		_CriticalMsg("Failed to create ARQ fulfiller thread", "x:\\prj\\tech\\libsrc\\arq\\arq.cpp", 0xA3u);
		result = 0x80004005u;
	}
	return result;
}

//----- (008CFDE5) --------------------------------------------------------
int __thiscall cARQManager::End(cARQManager *this)
{
	cARQManager *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (cWorkerThread::ThreadExists(&this->m_Fulfiller.baseclass_0))
	{
		cWorkerThread::CallWorker(&thisa->m_Fulfiller.baseclass_0, 0, 1);
		cWorkerThread::WaitForClose(&thisa->m_Fulfiller.baseclass_0, 0x2710u);
	}
	return 0;
}

//----- (008CFE20) --------------------------------------------------------
int __stdcall cARQManager::QueueRequest(cARQManager *this, sARQRequest *pClientRequest, IAsyncReadControl **ppControl)
{
	cARQRequest *v3; // eax@2
	cARQRequest *v5; // [sp+0h] [bp-Ch]@2
	void *v6; // [sp+4h] [bp-8h]@1

	cARQManager::BalanceThreadPriority(this);
	v6 = operator new(0x78u);
	if (v6)
	{
		cARQRequest::cARQRequest((cARQRequest *)v6, pClientRequest);
		v5 = v3;
	}
	else
	{
		v5 = 0;
	}
	cARQRequestQueue::AddRequest(&this->m_RequestQueue, v5, 0);
	if (ppControl)
		*ppControl = (IAsyncReadControl *)v5;
	else
		v5->baseclass_0.baseclass_0.vfptr->Release((IUnknown *)v5);
	return 0;
}

//----- (008CFE94) --------------------------------------------------------
int __stdcall cARQManager::QueueStreamRequest(cARQManager *this, sARQStreamRequest *pClientRequest, IAsyncReadControl **ppControl)
{
	IAsyncReadFulfiller *v3; // eax@2
	IAsyncReadFulfiller *v5; // [sp+0h] [bp-38h]@2
	void *v6; // [sp+4h] [bp-34h]@1
	sARQRequest request; // [sp+Ch] [bp-2Ch]@4
	int result; // [sp+34h] [bp-4h]@4

	v6 = operator new(0x2Cu);
	if (v6)
	{
		cAsyncStreamReader::cAsyncStreamReader((cAsyncStreamReader *)v6, pClientRequest);
		v5 = v3;
	}
	else
	{
		v5 = 0;
	}
	request.pFulfiller = v5;
	request.queue = pClientRequest->queue;
	request.priority = pClientRequest->priority;
	request.dwData[0] = 0;
	request.dwData[1] = 0;
	request.dwData[2] = 0;
	request.dwData[3] = 0;
	request.dwData[4] = 0;
	request.dwData[5] = 0;
	request.pszTrace = pClientRequest->pszTrace;
	result = this->baseclass_0.baseclass_0.vfptr[1].QueryInterface(
		(IUnknown *)this,
		(_GUID *)&request,
		(void **)ppControl);
	v5->baseclass_0.vfptr->Release((IUnknown *)v5);
	return result;
}

//----- (008CFF42) --------------------------------------------------------
int __stdcall cARQManager::GetAsyncStreamer(cARQManager *this, sARQStreamerDesc *__formal, IAsyncStreamer **a3)
{
	_CriticalMsg("Unimplemented function call", "x:\\prj\\tech\\libsrc\\arq\\arq.cpp", 239u);
	return 0x80004001u;
}

//----- (008CFF62) --------------------------------------------------------
int __stdcall cARQManager::Suspend(cARQManager *this)
{
	unsigned int presentThreadSuspendCount; // [sp+0h] [bp-8h]@2
	int result; // [sp+4h] [bp-4h]@1

	result = 0;
	if (!this->m_iSuspendCount)
	{
		presentThreadSuspendCount = cWorkerThread::Suspend(&this->m_Fulfiller.baseclass_0);
		cWorkerThread::Resume(&this->m_Fulfiller.baseclass_0);
		if (presentThreadSuspendCount)
			_CriticalMsg(
			"ARQ worker thread suspended preciously but not through approved API",
			"x:\\prj\\tech\\libsrc\\arq\\arq.cpp",
			258u);
		if (!presentThreadSuspendCount)
		{
			result = cWorkerThread::CallWorker(&this->m_Fulfiller.baseclass_0, 1u, 1);
			while (!cWorkerThread::Suspend(&this->m_Fulfiller.baseclass_0))
			{
				cWorkerThread::Resume(&this->m_Fulfiller.baseclass_0);
				Sleep(0);
			}
			cWorkerThread::Resume(&this->m_Fulfiller.baseclass_0);
		}
	}
	++this->m_iSuspendCount;
	return result;
}

//----- (008D001F) --------------------------------------------------------
int __stdcall cARQManager::Resume(cARQManager *this)
{
	int result; // eax@5

	if (this->m_iSuspendCount < 1)
		_CriticalMsg("Invalid call to resume: not suspended!", "x:\\prj\\tech\\libsrc\\arq\\arq.cpp", 284u);
	--this->m_iSuspendCount;
	if (this->m_iSuspendCount || cWorkerThread::Resume(&this->m_Fulfiller.baseclass_0) == -1)
	{
		_CriticalMsg("ARQ thread resume failed!", "x:\\prj\\tech\\libsrc\\arq\\arq.cpp", 289u);
		result = 0x80004005u;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008D009C) --------------------------------------------------------
int __stdcall cARQManager::IsStreamerBlocking(cARQManager *this)
{
	_CriticalMsg("Unimplemented function call", "x:\\prj\\tech\\libsrc\\arq\\arq.cpp", 300u);
	return 0;
}

//----- (008D00B9) --------------------------------------------------------
int __stdcall cARQManager::FulfillAll(cARQManager *this)
{
	return ((int(__stdcall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[3].AddRef)(this, 2147483647);
}

//----- (008D00D1) --------------------------------------------------------
int __stdcall cARQManager::FulfillToPriority(cARQManager *this, int priority)
{
	int v2; // ecx@0
	int v3; // ST04_4@1
	cARQRequest *pRequest; // [sp+0h] [bp-4h]@1
	int pRequesta; // [sp+0h] [bp-4h]@5
	int pRequestb; // [sp+0h] [bp-4h]@9

	v3 = v2;
	cARQManager::BalanceThreadPriority(this);
	((void(__stdcall *)(cARQManager *, int))this->baseclass_0.baseclass_0.vfptr[2].QueryInterface)(this, v3);
	for (pRequest = 0; cARQRequestQueue::GetCount(&this->m_RequestQueue); pRequest = 0)
	{
		pRequest = cARQRequestQueue::GetRequest(&this->m_RequestQueue);
		if (!pRequest)
			break;
		if (cARQRequest::GetPriority(pRequest) > priority)
			break;
		pRequest->baseclass_0.baseclass_0.vfptr[1].AddRef((IUnknown *)pRequest);
		if (pRequesta)
			(*(void(__stdcall **)(int))(*(_DWORD *)pRequesta + 8))(pRequesta);
	}
	if (pRequest)
	{
		cARQRequestQueue::AddRequest(&this->m_RequestQueue, (cARQRequest *)1, kAtFront);
		if (pRequestb)
			(*(void(__stdcall **)(int))(*(_DWORD *)pRequestb + 8))(pRequestb);
	}
	this->baseclass_0.baseclass_0.vfptr[2].AddRef((IUnknown *)this);
	return 0x80004005u;
}

//----- (008D0192) --------------------------------------------------------
int __stdcall cARQManager::KillAll(cARQManager *this)
{
	int v1; // ecx@0
	int v2; // ST04_4@1
	int pRequest; // [sp+0h] [bp-4h]@4

	v2 = v1;
	cARQManager::BalanceThreadPriority(this);
	((void(__stdcall *)(cARQManager *, int))this->baseclass_0.baseclass_0.vfptr[2].QueryInterface)(this, v2);
	while (cARQRequestQueue::GetCount(&this->m_RequestQueue) && cARQRequestQueue::GetRequest(&this->m_RequestQueue))
	{
		(*(void(__stdcall **)(signed int, signed int))(::v1 + 20))(1, 1);
		if (pRequest)
			(*(void(__stdcall **)(int))(*(_DWORD *)pRequest + 8))(pRequest);
	}
	this->baseclass_0.baseclass_0.vfptr[2].AddRef((IUnknown *)this);
	return 0x80004005u;
}

//----- (008D0214) --------------------------------------------------------
void __thiscall cARQManager::BalanceThreadPriority(cARQManager *this)
{
	HANDLE v1; // eax@1
	cARQManager *thisa; // [sp+0h] [bp-8h]@1
	int iCurrentThreadPriority; // [sp+4h] [bp-4h]@1

	thisa = this;
	v1 = GetCurrentThread();
	iCurrentThreadPriority = GetThreadPriority(v1);
	if (cWorkerThread::GetPriority(&thisa->m_Fulfiller.baseclass_0) != iCurrentThreadPriority)
	{
		cWorkerThread::SetPriority(&thisa->m_Fulfiller.baseclass_0, iCurrentThreadPriority);
		cARQFulfillerThread::SetPrioirities(&thisa->m_Fulfiller, iCurrentThreadPriority, iCurrentThreadPriority);
	}
}

//----- (008D0270) --------------------------------------------------------
IUnknown *__thiscall cARQManager::cOuterPointer::operator_ > (cARQManager::cOuterPointer *this)
{
	return this->m_pOuterUnknown;
}

//----- (008D0280) --------------------------------------------------------
int __thiscall cARQManager::Connect(cARQManager *this)
{
	return 0;
}

//----- (008D0290) --------------------------------------------------------
int __thiscall cARQManager::PostConnect(cARQManager *this)
{
	return 0;
}

//----- (008D02A0) --------------------------------------------------------
int __thiscall cARQManager::Disconnect(cARQManager *this)
{
	return 0;
}

//----- (008D02B0) --------------------------------------------------------
unsigned int __thiscall cARQManager::cComplexAggregateControl::cRefCount::AddRef(cARQManager::cComplexAggregateControl::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008D02D0) --------------------------------------------------------
unsigned int __thiscall cARQManager::cComplexAggregateControl::cRefCount::Release(cARQManager::cComplexAggregateControl::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008D02F0) --------------------------------------------------------
unsigned int __thiscall cARQManager::cComplexAggregateControl::cRefCount::operator unsigned_long(cARQManager::cComplexAggregateControl::cRefCount *this)
{
	return this->ul;
}

//----- (008D0300) --------------------------------------------------------
void __thiscall cARQManager::cComplexAggregateControl::OnFinalRelease(cARQManager::cComplexAggregateControl *this)
{
	if (this->m_pAggregateMember)
		cARQManager::OnFinalRelease(this->m_pAggregateMember);
}

//----- (008D0320) --------------------------------------------------------
void __thiscall cARQManager::OnFinalRelease(cARQManager *this)
{
	if (this)
		((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[4].QueryInterface)(this, 1);
}


//----- (008D03F0) --------------------------------------------------------
void __thiscall cARQManager::cOuterPointer::cOuterPointer(cARQManager::cOuterPointer *this)
{
	this->m_pOuterUnknown = 0;
}

//----- (008D0410) --------------------------------------------------------
void __thiscall cARQManager::cOuterPointer::Init(cARQManager::cOuterPointer *this, IUnknown *p)
{
	this->m_pOuterUnknown = p;
}

//----- (008D0430) --------------------------------------------------------
void __thiscall cARQManager::cComplexAggregateControl::cComplexAggregateControl(cARQManager::cComplexAggregateControl *this)
{
	cARQManager::cComplexAggregateControl *v1; // ST00_4@1

	v1 = this;
	IAggregateMemberControl::IAggregateMemberControl(&this->baseclass_0);
	cARQManager::cComplexAggregateControl::cRefCount::cRefCount(&v1->__m_ulRefs);
	v1->m_pAggregateMember = 0;
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cARQManager::cComplexAggregateControl::_vftable_;
}
// 9A7858: using guessed type int (__stdcall *cARQManager__cComplexAggregateControl___vftable_)(int this, int id, int ppI);

//----- (008D0470) --------------------------------------------------------
void __thiscall cARQManager::cComplexAggregateControl::cRefCount::cRefCount(cARQManager::cComplexAggregateControl::cRefCount *this)
{
	this->ul = 1;
}

//----- (008D0490) --------------------------------------------------------
void __thiscall cARQManager::cComplexAggregateControl::InitControl(cARQManager::cComplexAggregateControl *this, cARQManager *p)
{
	this->m_pAggregateMember = p;
}

//----- (008D04B0) --------------------------------------------------------
void *__thiscall cARQManager::_scalar_deleting_destructor_(cARQManager *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cARQManager::_cARQManager(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}



*/