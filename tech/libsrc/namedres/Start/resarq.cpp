//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>


//----- (008E25DF) --------------------------------------------------------
void __cdecl _E3_50()
{
	cResARQFulfiller::cResARQFulfiller(&g_ResARQFulfiller);
}

//----- (008E25EE) --------------------------------------------------------
int __cdecl _E5_39()
{
	return atexit(_E4_55);
}

//----- (008E2600) --------------------------------------------------------
void __cdecl _E4_55()
{
	cResARQFulfiller::_cResARQFulfiller(&g_ResARQFulfiller);
}

//----- (008E260F) --------------------------------------------------------
void __thiscall cResManARQ::Init(cResManARQ *this, cResMan *pManager)
{
	cResARQFulfiller::Init(&g_ResARQFulfiller);
	g_pResMan = pManager;
}

//----- (008E262E) --------------------------------------------------------
void __thiscall cResManARQ::ClearPreload(cResManARQ *this, cResourceTypeData *id)
{
	cResARQFulfiller::ClearPreload(&g_ResARQFulfiller, id);
}

//----- (008E2649) --------------------------------------------------------
void __thiscall cResManARQ::Term(cResManARQ *this)
{
	g_pResMan = 0;
	cResARQFulfiller::Term(&g_ResARQFulfiller);
}

//----- (008E2668) --------------------------------------------------------
int __thiscall cResManARQ::Lock(cResManARQ *this, IRes *pRes, int priority)
{
	return cResARQFulfiller::Lock(&g_ResARQFulfiller, pRes, priority);
}

//----- (008E2687) --------------------------------------------------------
int __thiscall cResManARQ::Extract(cResManARQ *this, IRes *pRes, int priority, void *buf, int bufSize)
{
	return cResARQFulfiller::Extract(&g_ResARQFulfiller, pRes, priority, buf, bufSize);
}

//----- (008E26AE) --------------------------------------------------------
int __thiscall cResManARQ::Preload(cResManARQ *this, IRes *pRes)
{
	return cResARQFulfiller::Preload(&g_ResARQFulfiller, pRes);
}

//----- (008E26C9) --------------------------------------------------------
int __thiscall cResManARQ::IsFulfilled(cResManARQ *this, IRes *pRes)
{
	return cResARQFulfiller::IsFulfilled(&g_ResARQFulfiller, pRes);
}

//----- (008E26E4) --------------------------------------------------------
int __thiscall cResManARQ::Kill(cResManARQ *this, IRes *pRes)
{
	return cResARQFulfiller::Kill(&g_ResARQFulfiller, pRes);
}

//----- (008E26FF) --------------------------------------------------------
int __thiscall cResManARQ::GetResult(cResManARQ *this, IRes *pRes, void **ppResult)
{
	return cResARQFulfiller::GetResult(&g_ResARQFulfiller, pRes, ppResult);
}

//----- (008E271E) --------------------------------------------------------
int __stdcall cResARQFulfiller::QueryInterface(cResARQFulfiller *this, _GUID *id, void **ppI)
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

//----- (008E278B) --------------------------------------------------------
unsigned int __stdcall cResARQFulfiller::AddRef(cResARQFulfiller *this)
{
	return cResARQFulfiller::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008E279D) --------------------------------------------------------
unsigned int __stdcall cResARQFulfiller::Release(cResARQFulfiller *this)
{
	unsigned int result; // eax@2

	if (cResARQFulfiller::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cResARQFulfiller::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cResARQFulfiller::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (008E27CA) --------------------------------------------------------
void __thiscall cResARQFulfiller::cResARQFulfiller(cResARQFulfiller *this)
{
	cResARQFulfiller *v1; // ST00_4@1

	v1 = this;
	IAsyncReadFulfiller::IAsyncReadFulfiller(&this->baseclass_0);
	cResARQFulfiller::cRefCount::cRefCount(&v1->__m_ulRefs);
	v1->m_pAsyncReadQueue = 0;
	cResARQFulfiller::cResControlTable::cResControlTable(&v1->m_Controls);
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cResARQFulfiller::_vftable_;
}
// 9A821C: using guessed type int (__stdcall *cResARQFulfiller___vftable_)(int this, int id, int ppI);

//----- (008E2809) --------------------------------------------------------
void __thiscall cResARQFulfiller::_cResARQFulfiller(cResARQFulfiller *this)
{
	this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cResARQFulfiller::_vftable_;
	cResARQFulfiller::cResControlTable::_cResControlTable(&this->m_Controls);
}
// 9A821C: using guessed type int (__stdcall *cResARQFulfiller___vftable_)(int this, int id, int ppI);

//----- (008E2828) --------------------------------------------------------
void __thiscall cResARQFulfiller::Init(cResARQFulfiller *this)
{
	cResARQFulfiller *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (GetPrivateProfileIntA("Res", "ARQ", 1, "lg.ini"))
		thisa->m_pAsyncReadQueue = (IAsyncReadQueue *)_AppGetAggregated(&IID_IAsyncReadQueue);
}

//----- (008E285E) --------------------------------------------------------
void __thiscall cResARQFulfiller::Term(cResARQFulfiller *this)
{
	cResARQFulfiller *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (this->m_pAsyncReadQueue)
		this->m_pAsyncReadQueue->baseclass_0.vfptr->Release((IUnknown *)this->m_pAsyncReadQueue);
	thisa->m_pAsyncReadQueue = 0;
}

//----- (008E288E) --------------------------------------------------------
int __thiscall cResARQFulfiller::IsFulfilled(cResARQFulfiller *this, IRes *pRes)
{
	cResourceTypeData *v2; // ST18_4@1
	const char *v3; // eax@2
	int result; // eax@5
	cResARQFulfiller *thisa; // [sp+0h] [bp-Ch]@1
	cResARQFulfiller::sResRequest *pResRequest; // [sp+4h] [bp-8h]@1

	thisa = this;
	v2 = cResMan::GetResourceTypeData(g_pResMan, pRes);
	pResRequest = cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::Search(
		&thisa->m_Controls.baseclass_0.baseclass_0,
		v2);
	if (!pResRequest)
	{
		v3 = _LogFmt("Resource 0x%x was never queued");
		_CriticalMsg(v3, "x:\\prj\\tech\\libsrc\\namedres\\resarq.cpp", 0xB0u);
	}
	if (pResRequest && cResARQFulfiller::IsAsynchronous(thisa))
		result = ((int(__stdcall *)(_DWORD))pResRequest->pControl->baseclass_0.vfptr[1].QueryInterface)(pResRequest->pControl);
	else
		result = 1;
	return result;
}

//----- (008E2919) --------------------------------------------------------
int __thiscall cResARQFulfiller::Kill(cResARQFulfiller *this, IRes *pRes)
{
	cResourceTypeData *v2; // ST20_4@1
	int result; // eax@9
	cResARQFulfiller *thisa; // [sp+4h] [bp-18h]@1
	int retVal; // [sp+10h] [bp-Ch]@2
	cResARQFulfiller::sResRequest *pResRequest; // [sp+14h] [bp-8h]@1

	thisa = this;
	_ResThreadLock();
	v2 = cResMan::GetResourceTypeData(g_pResMan, pRes);
	pResRequest = cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::Search(
		&thisa->m_Controls.baseclass_0.baseclass_0,
		v2);
	if (pResRequest)
	{
		retVal = 0;
		--pResRequest->nRequests;
		if (!pResRequest->nRequests)
		{
			if (cResARQFulfiller::IsAsynchronous(thisa))
			{
				_ResThreadUnlock();
				retVal = ((int(__stdcall *)(_DWORD, _DWORD))pResRequest->pControl->baseclass_0.vfptr[1].Release)(
					pResRequest->pControl,
					1);
				_ResThreadLock();
				if (retVal == -2147467259)
				{
					if (!pResRequest->kind)
						((void(__stdcall *)(_DWORD, _DWORD))g_pResMan->baseclass_18.baseclass_0.baseclass_0.vfptr[2].QueryInterface)(
						&g_pResMan->baseclass_18,
						pResRequest->pResource);
				}
			}
			if (pResRequest)
				cResARQFulfiller::sResRequest::_scalar_deleting_destructor_(pResRequest, 1u);
		}
		_ResThreadUnlock();
		result = retVal;
	}
	else
	{
		_ResThreadUnlock();
		result = -2147467259;
	}
	return result;
}

//----- (008E2A13) --------------------------------------------------------
int __thiscall cResARQFulfiller::GetResult(cResARQFulfiller *this, IRes *pRes, void **ppResult)
{
	int v3; // eax@13
	cResARQFulfiller *thisa; // [sp+4h] [bp-2Ch]@1
	sARQResult result; // [sp+10h] [bp-20h]@3
	int retVal; // [sp+24h] [bp-Ch]@3
	cResARQFulfiller::sResRequest *pResRequest; // [sp+28h] [bp-8h]@1
	cResourceTypeData *Handle; // [sp+2Ch] [bp-4h]@1

	thisa = this;
	_ResThreadLock();
	Handle = cResMan::GetResourceTypeData(g_pResMan, pRes);
	pResRequest = cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::Search(
		&thisa->m_Controls.baseclass_0.baseclass_0,
		Handle);
	if (pResRequest)
	{
		if (cResARQFulfiller::IsAsynchronous(thisa))
		{
			_ResThreadUnlock();
			pResRequest->pControl->baseclass_0.vfptr[1].AddRef((IUnknown *)pResRequest->pControl);
			retVal = ((int(__stdcall *)(IAsyncReadControl *, sARQResult *))pResRequest->pControl->baseclass_0.vfptr[2].QueryInterface)(
				pResRequest->pControl,
				&result);
			_ResThreadLock();
			if (pResRequest->nRequests > 1 && !pResRequest->kind)
				((void(__stdcall *)(cCTDelegating<IResManHelper> *, IRes *))g_pResMan->baseclass_18.baseclass_0.baseclass_0.vfptr[1].QueryInterface)(
				&g_pResMan->baseclass_18,
				pRes);
			*ppResult = result.buffer;
		}
		else
		{
			retVal = cResARQFulfiller::SatisfyRequest(thisa, pResRequest, ppResult);
		}
		if (!pResRequest->nRequests)
			_CriticalMsg("Expected request count to be non-zero", "x:\\prj\\tech\\libsrc\\namedres\\resarq.cpp", 0x10Au);
		--pResRequest->nRequests;
		if (!pResRequest->nRequests)
		{
			if (pResRequest)
				cResARQFulfiller::sResRequest::_scalar_deleting_destructor_(pResRequest, 1u);
		}
		_ResThreadUnlock();
		v3 = retVal;
	}
	else
	{
		_CriticalMsg(
			"Tried to get the result of an unknown async request.",
			"x:\\prj\\tech\\libsrc\\namedres\\resarq.cpp",
			0x112u);
		*ppResult = 0;
		_ResThreadUnlock();
		v3 = -2147467259;
	}
	return v3;
}

//----- (008E2B70) --------------------------------------------------------
void __thiscall cResARQFulfiller::ClearPreload(cResARQFulfiller *this, cResourceTypeData *id)
{
	cResARQFulfiller *thisa; // [sp+0h] [bp-Ch]@1
	cResARQFulfiller::sResRequest *pResRequest; // [sp+4h] [bp-8h]@2
	cAutoResThreadLock lock; // [sp+8h] [bp-4h]@1

	thisa = this;
	cAutoResThreadLock::cAutoResThreadLock(&lock);
	if (cResARQFulfiller::IsAsynchronous(thisa))
	{
		pResRequest = cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::Search(
			&thisa->m_Controls.baseclass_0.baseclass_0,
			id);
		if (pResRequest)
		{
			if (pResRequest->kind == 2 && !pResRequest->satisfyingPreload)
				cResARQFulfiller::Kill(thisa, pResRequest->pResource);
		}
	}
	cAutoResThreadLock::_cAutoResThreadLock(&lock);
}

//----- (008E2BD4) --------------------------------------------------------
int __stdcall cResARQFulfiller::DoFulfill(cResARQFulfiller *this, sARQRequest *pRequest, sARQResult *pResult)
{
	int v3; // ST10_4@7
	unsigned int pResRequest; // [sp+10h] [bp-8h]@1
	cAutoResThreadLock lock; // [sp+14h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&lock);
	pResRequest = pRequest->dwData[0];
	if (!cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::Search(
		&this->m_Controls.baseclass_0.baseclass_0,
		*(const void **)(pResRequest + 4)))
		_CriticalMsg("Fuck!", "x:\\prj\\tech\\libsrc\\namedres\\resarq.cpp", 0x132u);
	pResult->flags = 0;
	pResult->streamIndex = 0;
	pResult->length = 0;
	pResult->result = cResARQFulfiller::SatisfyRequest(
		this,
		(cResARQFulfiller::sResRequest *)pResRequest,
		&pResult->buffer);
	if (*(_DWORD *)(pResRequest + 16) == 2)
	{
		--*(_DWORD *)(pResRequest + 28);
		if (!*(_DWORD *)(pResRequest + 28))
		{
			if (pResRequest)
				cResARQFulfiller::sResRequest::_scalar_deleting_destructor_((cResARQFulfiller::sResRequest *)pResRequest, 1u);
		}
	}
	v3 = pResult->result;
	cAutoResThreadLock::_cAutoResThreadLock(&lock);
	return v3;
}

//----- (008E2CB5) --------------------------------------------------------
int __stdcall cResARQFulfiller::DoKill(cResARQFulfiller *this, sARQRequest *__formal, int a3)
{
	return 0;
}

//----- (008E2CBE) --------------------------------------------------------
int __thiscall cResARQFulfiller::QueueRequest(cResARQFulfiller *this, IRes *pRes, int priority, cResARQFulfiller::sResRequest::eRequestKind kind, void *pBuf, int bufSize)
{
	int result; // eax@5
	unsigned int v7; // eax@22
	unsigned int v8; // [sp+4h] [bp-78h]@22
	cResARQFulfiller::sResRequest::eRequestKind v9; // [sp+8h] [bp-74h]@2
	cResARQFulfiller *thisa; // [sp+Ch] [bp-70h]@1
	void *v11; // [sp+20h] [bp-5Ch]@21
	cResARQFulfiller::sResRequest *pResRequest; // [sp+48h] [bp-34h]@1
	sARQRequest request; // [sp+4Ch] [bp-30h]@24
	cResourceTypeData *Handle; // [sp+74h] [bp-8h]@1
	cAutoResThreadLock lock; // [sp+78h] [bp-4h]@1

	thisa = this;
	cAutoResThreadLock::cAutoResThreadLock(&lock);
	Handle = cResMan::GetResourceTypeData(g_pResMan, pRes);
	pResRequest = cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::Search(
		&thisa->m_Controls.baseclass_0.baseclass_0,
		Handle);
	if (pResRequest)
	{
		v9 = pResRequest->kind;
		if (v9)
		{
			if (v9 == 1)
			{
				_CriticalMsg(
					"Can't mix async Extract with any other async resource operation",
					"x:\\prj\\tech\\libsrc\\namedres\\resarq.cpp",
					0x17Cu);
				cAutoResThreadLock::_cAutoResThreadLock(&lock);
				result = 0;
			}
			else
			{
				if (v9 == 2)
				{
					if (kind == 2)
					{
						cAutoResThreadLock::_cAutoResThreadLock(&lock);
						result = 1;
					}
					else
					{
						_CriticalMsg(
							"Oof! Don't know how to turn a preload into something else right now!",
							"x:\\prj\\tech\\libsrc\\namedres\\resarq.cpp",
							0x18Bu);
						cAutoResThreadLock::_cAutoResThreadLock(&lock);
						result = 0;
					}
				}
				else
				{
					_CriticalMsg("Unknown async request kind!", "x:\\prj\\tech\\libsrc\\namedres\\resarq.cpp", 0x18Fu);
					cAutoResThreadLock::_cAutoResThreadLock(&lock);
					result = 0;
				}
			}
		}
		else
		{
			if (kind == 1)
			{
				_CriticalMsg("Can't mix async Lock/Extract", "x:\\prj\\tech\\libsrc\\namedres\\resarq.cpp", 0x163u);
				cAutoResThreadLock::_cAutoResThreadLock(&lock);
				result = 0;
			}
			else
			{
				if (kind == 2)
				{
					cAutoResThreadLock::_cAutoResThreadLock(&lock);
					result = 1;
				}
				else
				{
					if (pResRequest->priority - priority < 0)
					{
						DbgReportWarning("ResAsync: Cannot boost request priority (not yet imlemented)");
						cAutoResThreadLock::_cAutoResThreadLock(&lock);
						result = 1;
					}
					else
					{
						++pResRequest->nRequests;
						cAutoResThreadLock::_cAutoResThreadLock(&lock);
						result = 1;
					}
				}
			}
		}
	}
	else
	{
		if (kind != 2 || !Handle->m_pData && cResARQFulfiller::IsAsynchronous(thisa))
		{
			v11 = j__new(0x28u, "x:\\prj\\tech\\libsrc\\namedres\\resarq.cpp", 419);
			if (v11)
			{
				cResARQFulfiller::sResRequest::sResRequest(
					(cResARQFulfiller::sResRequest *)v11,
					&thisa->m_Controls,
					Handle,
					pRes,
					priority,
					kind,
					pBuf,
					bufSize);
				v8 = v7;
			}
			else
			{
				v8 = 0;
			}
			request.pFulfiller = (IAsyncReadFulfiller *)thisa;
			request.queue = 0;
			request.priority = priority;
			request.dwData[0] = v8;
			request.dwData[1] = 0;
			request.dwData[2] = 0;
			request.dwData[3] = 0;
			request.dwData[4] = 0;
			request.dwData[5] = 0;
			request.pszTrace = "Resource";
			if (cResARQFulfiller::IsAsynchronous(thisa)
				&& thisa->m_pAsyncReadQueue->baseclass_0.vfptr[1].QueryInterface(
				(IUnknown *)thisa->m_pAsyncReadQueue,
				(_GUID *)&request,
				(void **)v8))
			{
				if (v8)
					cResARQFulfiller::sResRequest::_scalar_deleting_destructor_((cResARQFulfiller::sResRequest *)v8, 1u);
				cAutoResThreadLock::_cAutoResThreadLock(&lock);
				result = 0;
			}
			else
			{
				++*(_DWORD *)(v8 + 28);
				cAutoResThreadLock::_cAutoResThreadLock(&lock);
				result = 1;
			}
		}
		else
		{
			((void(__stdcall *)(cCTDelegating<IResManHelper> *, IRes *))g_pResMan->baseclass_18.baseclass_0.baseclass_0.vfptr[1].QueryInterface)(
				&g_pResMan->baseclass_18,
				pRes);
			((void(__stdcall *)(cCTDelegating<IResManHelper> *, IRes *))g_pResMan->baseclass_18.baseclass_0.baseclass_0.vfptr[2].QueryInterface)(
				&g_pResMan->baseclass_18,
				pRes);
			cAutoResThreadLock::_cAutoResThreadLock(&lock);
			result = 1;
		}
	}
	return result;
}

//----- (008E300D) --------------------------------------------------------
int __thiscall cResARQFulfiller::SatisfyRequest(cResARQFulfiller *this, cResARQFulfiller::sResRequest *pResRequest, void **ppResult)
{
	IRes *v3; // ST14_4@11
	cResARQFulfiller::sResRequest::eRequestKind v5; // [sp+0h] [bp-10h]@3
	int pResult; // [sp+Ch] [bp-4h]@0

	if (!cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::Search(
		&this->m_Controls.baseclass_0.baseclass_0,
		pResRequest->id))
		_CriticalMsg("Fuck!", "x:\\prj\\tech\\libsrc\\namedres\\resarq.cpp", 0x1CAu);
	v5 = pResRequest->kind;
	if (v5)
	{
		if (v5 == 1)
		{
			pResult = ((int(__stdcall *)(_DWORD, _DWORD, _DWORD))g_pResMan->baseclass_18.baseclass_0.baseclass_0.vfptr[1].AddRef)(
				&g_pResMan->baseclass_18,
				pResRequest->pResource,
				pResRequest->pBuf);
		}
		else
		{
			if (v5 == 2)
			{
				v3 = pResRequest->pResource;
				pResRequest->satisfyingPreload = 1;
				pResult = ((int(__stdcall *)(_DWORD))v3->baseclass_0.baseclass_0.vfptr[6].QueryInterface)(v3);
				pResRequest->satisfyingPreload = 0;
			}
			else
			{
				_CriticalMsg("Unknown async request kind!", "x:\\prj\\tech\\libsrc\\namedres\\resarq.cpp", 0x1E4u);
			}
		}
	}
	else
	{
		if (!ppResult)
			_CriticalMsg("Must have a destination for ResLock()", "x:\\prj\\tech\\libsrc\\namedres\\resarq.cpp", 0x1CFu);
		pResult = ((int(__stdcall *)(_DWORD, _DWORD))g_pResMan->baseclass_18.baseclass_0.baseclass_0.vfptr[1].QueryInterface)(
			&g_pResMan->baseclass_18,
			pResRequest->pResource);
	}
	if (ppResult)
		*ppResult = (void *)pResult;
	return pResult != 0 ? 0 : -2147467259;
}

//----- (008E313A) --------------------------------------------------------
tHashSetKey__ *__thiscall cResARQFulfiller::cResControlTable::GetKey(cResARQFulfiller::cResControlTable *this, tHashSetNode__ *node)
{
	return (tHashSetKey__ *)node[1].unused;
}

//----- (008E3150) --------------------------------------------------------
int __thiscall cResARQFulfiller::Lock(cResARQFulfiller *this, IRes *pRes, int priority)
{
	return cResARQFulfiller::QueueRequest(this, pRes, priority, 0, 0, 0);
}

//----- (008E3180) --------------------------------------------------------
int __thiscall cResARQFulfiller::Extract(cResARQFulfiller *this, IRes *pRes, int priority, void *buf, int bufSize)
{
	return cResARQFulfiller::QueueRequest(this, pRes, priority, kExtract, buf, bufSize);
}

//----- (008E31B0) --------------------------------------------------------
int __thiscall cResARQFulfiller::Preload(cResARQFulfiller *this, IRes *pRes)
{
	return cResARQFulfiller::QueueRequest(this, pRes, 32768, kPreload, 0, 0);
}

//----- (008E31E0) --------------------------------------------------------
unsigned int __thiscall cResARQFulfiller::cRefCount::AddRef(cResARQFulfiller::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008E3200) --------------------------------------------------------
unsigned int __thiscall cResARQFulfiller::cRefCount::Release(cResARQFulfiller::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008E3220) --------------------------------------------------------
unsigned int __thiscall cResARQFulfiller::cRefCount::operator unsigned_long(cResARQFulfiller::cRefCount *this)
{
	return this->ul;
}

//----- (008E3230) --------------------------------------------------------
void __thiscall cResARQFulfiller::OnFinalRelease(cResARQFulfiller *this)
{
	;
}

//----- (008E3240) --------------------------------------------------------
void __thiscall cResARQFulfiller::cRefCount::cRefCount(cResARQFulfiller::cRefCount *this)
{
	this->ul = 1;
}

//----- (008E3260) --------------------------------------------------------
void __thiscall cResARQFulfiller::cResControlTable::cResControlTable(cResARQFulfiller::cResControlTable *this)
{
	cResARQFulfiller::cResControlTable *v1; // ST00_4@1

	v1 = this;
	cPtrHashSet<cResARQFulfiller::sResRequest__>::cPtrHashSet<cResARQFulfiller::sResRequest__>(&this->baseclass_0);
	v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cResARQFulfiller::cResControlTable::_vftable_;
}
// 9A8230: using guessed type int (__stdcall *cResARQFulfiller__cResControlTable___vftable_)(int __flags);

//----- (008E3280) --------------------------------------------------------
void *__thiscall cResARQFulfiller::cResControlTable::_vector_deleting_destructor_(cResARQFulfiller::cResControlTable *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cResARQFulfiller::cResControlTable::_cResControlTable(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E32B0) --------------------------------------------------------
void __thiscall cResARQFulfiller::cResControlTable::_cResControlTable(cResARQFulfiller::cResControlTable *this)
{
	cPtrHashSet<cResARQFulfiller::sResRequest__>::_cPtrHashSet<cResARQFulfiller::sResRequest__>(&this->baseclass_0);
}

//----- (008E32D0) --------------------------------------------------------
void __thiscall cPtrHashSet<cResARQFulfiller::sResRequest__>::cPtrHashSet<cResARQFulfiller::sResRequest__>(cPtrHashSet<cResARQFulfiller::sResRequest *> *this)
{
	cPtrHashSet<cResARQFulfiller::sResRequest *> *v1; // ST04_4@1

	v1 = this;
	cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>(
		&this->baseclass_0,
		0x65u);
	v1->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cPtrHashSet<cResARQFulfiller::sResRequest__>::_vftable_;
}
// 9A8250: using guessed type int (__stdcall *cPtrHashSet_cResARQFulfiller__sResRequest _____vftable_)(int __flags);

//----- (008E3300) --------------------------------------------------------
void __thiscall cPtrHashSet<cResARQFulfiller::sResRequest__>::_cPtrHashSet<cResARQFulfiller::sResRequest__>(cPtrHashSet<cResARQFulfiller::sResRequest *> *this)
{
	cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::_cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>(&this->baseclass_0);
}

//----- (008E3320) --------------------------------------------------------
void *__thiscall cPtrHashSet<cResARQFulfiller::sResRequest__>::_vector_deleting_destructor_(cPtrHashSet<cResARQFulfiller::sResRequest *> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cPtrHashSet<cResARQFulfiller::sResRequest__>::_cPtrHashSet<cResARQFulfiller::sResRequest__>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E3350) --------------------------------------------------------
void __thiscall cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::_cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>(cHashSet<cResARQFulfiller::sResRequest *, void const *, cHashFunctions> *this)
{
	cHashSetBase::_cHashSetBase(&this->baseclass_0);
}

//----- (008E3370) --------------------------------------------------------
int __thiscall cResARQFulfiller::IsAsynchronous(cResARQFulfiller *this)
{
	return this->m_pAsyncReadQueue != 0;
}

//----- (008E3390) --------------------------------------------------------
void *__thiscall cResARQFulfiller::sResRequest::_scalar_deleting_destructor_(cResARQFulfiller::sResRequest *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cResARQFulfiller::sResRequest::_sResRequest(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E33C0) --------------------------------------------------------
void __thiscall cResARQFulfiller::sResRequest::_sResRequest(cResARQFulfiller::sResRequest *this)
{
	cResARQFulfiller::sResRequest *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (!cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::Remove(
		&thisa->m_OwningControlTable->baseclass_0.baseclass_0,
		thisa))
		_CriticalMsg("m_OwningControlTable.Remove(this)", "x:\\prj\\tech\\libsrc\\namedres\\resarq.h", 0x66u);
	thisa->pResource->baseclass_0.baseclass_0.vfptr->Release((IUnknown *)thisa->pResource);
	if (thisa->pControl)
		thisa->pControl->baseclass_0.vfptr->Release((IUnknown *)thisa->pControl);
	memset(thisa, 254, 0x28u);
}

//----- (008E3440) --------------------------------------------------------
void __thiscall cResARQFulfiller::sResRequest::sResRequest(cResARQFulfiller::sResRequest *this, cResARQFulfiller::cResControlTable *owningControlTable, cResourceTypeData *id, IRes *pRes, int priority, cResARQFulfiller::sResRequest::eRequestKind kind, void *pBuf, int bufSize)
{
	cResARQFulfiller::sResRequest *v8; // ST04_4@1

	v8 = this;
	this->pControl = 0;
	this->id = id;
	this->pResource = pRes;
	this->priority = priority;
	this->kind = kind;
	this->pBuf = pBuf;
	this->bufSize = bufSize;
	this->nRequests = 0;
	this->m_OwningControlTable = owningControlTable;
	this->satisfyingPreload = 0;
	this->pResource->baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)this->pResource);
	cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::Insert(
		&v8->m_OwningControlTable->baseclass_0.baseclass_0,
		v8);
}



//----- (008E34D0) --------------------------------------------------------
void __thiscall cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>(cHashSet<cResARQFulfiller::sResRequest *, void const *, cHashFunctions> *this, unsigned int n)
{
	cHashSet<cResARQFulfiller::sResRequest *, void const *, cHashFunctions> *v2; // ST14_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, n);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::_vftable_;
}
// 9A8270: using guessed type int (__stdcall *cHashSet_cResARQFulfiller__sResRequest __void const __cHashFunctions____vftable_)(int __flags);

//----- (008E3540) --------------------------------------------------------
void *__thiscall cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::_vector_deleting_destructor_(cHashSet<cResARQFulfiller::sResRequest *, void const *, cHashFunctions> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::_cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E3570) --------------------------------------------------------
void __thiscall cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::DestroyAll(cHashSet<cNamedStatsData *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSet<cNamedStatsData *, char const *, cCaselessStringHashFuncs> *thisa; // [sp+4h] [bp-1Ch]@1
	sHashSetChunk *pNext; // [sp+14h] [bp-Ch]@6
	sHashSetChunk *p; // [sp+18h] [bp-8h]@4
	unsigned int i; // [sp+1Ch] [bp-4h]@2

	thisa = this;
	if (this->baseclass_0.m_nItems)
	{
		for (i = 0; i < thisa->baseclass_0.m_nPts; ++i)
		{
			for (p = thisa->baseclass_0.m_Table[i]; p; p = pNext)
			{
				pNext = p->pNext;
				if (p->node)
					cNamedStatsData::_scalar_deleting_destructor_((cNamedStatsData *)p->node, 1u);
				sHashSetChunk::operator delete(p, 8u);
			}
			thisa->baseclass_0.m_Table[i] = 0;
		}
		thisa->baseclass_0.m_nItems = 0;
	}
}

//----- (008E3630) --------------------------------------------------------
void __thiscall cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::DestroyAll(cHashSet<cResourceTypeData *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSet<cResourceTypeData *, char const *, cCaselessStringHashFuncs> *thisa; // [sp+4h] [bp-1Ch]@1
	sHashSetChunk *pNext; // [sp+14h] [bp-Ch]@6
	sHashSetChunk *p; // [sp+18h] [bp-8h]@4
	unsigned int i; // [sp+1Ch] [bp-4h]@2

	thisa = this;
	if (this->baseclass_0.m_nItems)
	{
		for (i = 0; i < thisa->baseclass_0.m_nPts; ++i)
		{
			for (p = thisa->baseclass_0.m_Table[i]; p; p = pNext)
			{
				pNext = p->pNext;
				if (p->node)
					cResourceTypeData::_scalar_deleting_destructor_((cResourceTypeData *)p->node, 1u);
				sHashSetChunk::operator delete(p, 8u);
			}
			thisa->baseclass_0.m_Table[i] = 0;
		}
		thisa->baseclass_0.m_nItems = 0;
	}
}

//----- (008E36F0) --------------------------------------------------------
void __thiscall cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::DestroyAll(cHashSet<cResourceName *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSet<cResourceName *, char const *, cCaselessStringHashFuncs> *thisa; // [sp+4h] [bp-1Ch]@1
	sHashSetChunk *pNext; // [sp+14h] [bp-Ch]@6
	sHashSetChunk *p; // [sp+18h] [bp-8h]@4
	unsigned int i; // [sp+1Ch] [bp-4h]@2

	thisa = this;
	if (this->baseclass_0.m_nItems)
	{
		for (i = 0; i < thisa->baseclass_0.m_nPts; ++i)
		{
			for (p = thisa->baseclass_0.m_Table[i]; p; p = pNext)
			{
				pNext = p->pNext;
				if (p->node)
					cResourceName::_scalar_deleting_destructor_((cResourceName *)p->node, 1u);
				sHashSetChunk::operator delete(p, 8u);
			}
			thisa->baseclass_0.m_Table[i] = 0;
		}
		thisa->baseclass_0.m_nItems = 0;
	}
}

//----- (008E37B0) --------------------------------------------------------
void __thiscall cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::DestroyAll(cHashSet<cResTypeData *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSet<cResTypeData *, char const *, cCaselessStringHashFuncs> *thisa; // [sp+4h] [bp-1Ch]@1
	sHashSetChunk *pNext; // [sp+14h] [bp-Ch]@6
	sHashSetChunk *p; // [sp+18h] [bp-8h]@4
	unsigned int i; // [sp+1Ch] [bp-4h]@2

	thisa = this;
	if (this->baseclass_0.m_nItems)
	{
		for (i = 0; i < thisa->baseclass_0.m_nPts; ++i)
		{
			for (p = thisa->baseclass_0.m_Table[i]; p; p = pNext)
			{
				pNext = p->pNext;
				if (p->node)
					cResTypeData::_scalar_deleting_destructor_((cResTypeData *)p->node, 1u);
				sHashSetChunk::operator delete(p, 8u);
			}
			thisa->baseclass_0.m_Table[i] = 0;
		}
		thisa->baseclass_0.m_nItems = 0;
	}
}

//----- (008E3870) --------------------------------------------------------
void __thiscall cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::DestroyAll(cHashSet<cNamedResType *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSet<cNamedResType *, char const *, cCaselessStringHashFuncs> *thisa; // [sp+4h] [bp-1Ch]@1
	sHashSetChunk *pNext; // [sp+14h] [bp-Ch]@6
	sHashSetChunk *p; // [sp+18h] [bp-8h]@4
	unsigned int i; // [sp+1Ch] [bp-4h]@2

	thisa = this;
	if (this->baseclass_0.m_nItems)
	{
		for (i = 0; i < thisa->baseclass_0.m_nPts; ++i)
		{
			for (p = thisa->baseclass_0.m_Table[i]; p; p = pNext)
			{
				pNext = p->pNext;
				if (p->node)
					cNamedResType::_scalar_deleting_destructor_((cNamedResType *)p->node, 1u);
				sHashSetChunk::operator delete(p, 8u);
			}
			thisa->baseclass_0.m_Table[i] = 0;
		}
		thisa->baseclass_0.m_nItems = 0;
	}
}

//----- (008E3930) --------------------------------------------------------
cResARQFulfiller::sResRequest *__thiscall cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::Insert(cHashSet<cResARQFulfiller::sResRequest *, void const *, cHashFunctions> *this, cResARQFulfiller::sResRequest *node)
{
	return (cResARQFulfiller::sResRequest *)cHashSetBase::Insert(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008E3950) --------------------------------------------------------
cResARQFulfiller::sResRequest *__thiscall cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::Search(cHashSet<cResARQFulfiller::sResRequest *, void const *, cHashFunctions> *this, const void *key)
{
	return (cResARQFulfiller::sResRequest *)cHashSetBase::Search(&this->baseclass_0, (tHashSetKey__ *)key);
}

//----- (008E3970) --------------------------------------------------------
cResARQFulfiller::sResRequest *__thiscall cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::Remove(cHashSet<cResARQFulfiller::sResRequest *, void const *, cHashFunctions> *this, cResARQFulfiller::sResRequest *node)
{
	return (cResARQFulfiller::sResRequest *)cHashSetBase::Remove(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008E3990) --------------------------------------------------------
void __thiscall cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::DestroyAll(cHashSet<cResARQFulfiller::sResRequest *, void const *, cHashFunctions> *this)
{
	cHashSet<cResARQFulfiller::sResRequest *, void const *, cHashFunctions> *thisa; // [sp+4h] [bp-1Ch]@1
	sHashSetChunk *pNext; // [sp+14h] [bp-Ch]@6
	sHashSetChunk *p; // [sp+18h] [bp-8h]@4
	unsigned int i; // [sp+1Ch] [bp-4h]@2

	thisa = this;
	if (this->baseclass_0.m_nItems)
	{
		for (i = 0; i < thisa->baseclass_0.m_nPts; ++i)
		{
			for (p = thisa->baseclass_0.m_Table[i]; p; p = pNext)
			{
				pNext = p->pNext;
				if (p->node)
					cResARQFulfiller::sResRequest::_scalar_deleting_destructor_((cResARQFulfiller::sResRequest *)p->node, 1u);
				sHashSetChunk::operator delete(p, 8u);
			}
			thisa->baseclass_0.m_Table[i] = 0;
		}
		thisa->baseclass_0.m_nItems = 0;
	}
}

//----- (008E3A50) --------------------------------------------------------
int __thiscall cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::IsEqual(cHashSet<cResARQFulfiller::sResRequest *, void const *, cHashFunctions> *this, tHashSetKey__ *k1, tHashSetKey__ *k2)
{
	return cHashFunctions::IsEqual(k1, k2);
}

//----- (008E3A70) --------------------------------------------------------
int __cdecl cHashFunctions::IsEqual(const void *p1, const void *p2)
{
	return p1 == p2;
}

//----- (008E3A90) --------------------------------------------------------
unsigned int __thiscall cHashSet<cResARQFulfiller::sResRequest___void_const___cHashFunctions>::Hash(cHashSet<cResARQFulfiller::sResRequest *, void const *, cHashFunctions> *this, tHashSetKey__ *k)
{
	return cHashFunctions::Hash(k);
}


