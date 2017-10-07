//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include <arqapi.h>
#include "arqqueue.h"
#include "arqreq.h"


__thiscall cARQRequestQueue::cARQRequestQueue(unsigned int queueID)
{

}



/*
//----- (008D0810) --------------------------------------------------------
void __thiscall cARQRequestQueue::cARQRequestQueue(unsigned int queueID)
{
	cARQRequestQueue *v2; // ST08_4@1

	v2 = this;
	cDList<cARQRequest_1>::cDList<cARQRequest_1>(&this->baseclass_0);
	cThreadLock::cThreadLock(&v2->m_Lock);
	cThreadEvent::cThreadEvent(&v2->m_AvailabilitySignal, 1);
	cThreadSemaphore::cThreadSemaphore(&v2->m_PutSemaphore, 32, 32);
	v2->m_cEntries = 0;
	v2->m_queueID = queueID;
	v2->m_flags = 0;
}

//----- (008D086C) --------------------------------------------------------
__thiscall cARQRequestQueue::~cARQRequestQueue()
{
	cARQRequestQueue *v1; // ST00_4@1

	v1 = this;
	cThreadSemaphore::_cThreadSemaphore(&this->m_PutSemaphore);
	cThreadEvent::_cThreadEvent(&v1->m_AvailabilitySignal);
	cThreadLock::_cThreadLock(&v1->m_Lock);
}

//----- (008D0898) --------------------------------------------------------
int __thiscall cARQRequestQueue::AddRequest(cARQRequest *pRequest, cARQRequestQueue::eAddFlags flags)
{
	int v3; // esi@11
	cARQRequestQueue *thisa; // [sp+8h] [bp-8h]@1
	cARQRequest *pScan; // [sp+Ch] [bp-4h]@9

	thisa = this;
	if (!pRequest)
		_CriticalMsg("Invalid request add", "x:\\prj\\tech\\libsrc\\arq\\arqqueue.cpp", 0x38u);
	if (cARQRequest::GetQueueID(pRequest) != thisa->m_queueID)
		_CriticalMsg("Attempt to add request to wrong queue", "x:\\prj\\tech\\libsrc\\arq\\arqqueue.cpp", 0x39u);
	cARQRequestQueue::WaitPut(thisa);
	cThreadLock::Lock(&thisa->m_Lock);
	pRequest->baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)pRequest);
	if (!flags)
	{
		for (pScan = cDList<cARQRequest_1>::GetLast(&thisa->baseclass_0);
			;
			pScan = cDListNode<cARQRequest_1>::GetPrevious(&pScan->baseclass_4))
		{
			if (pScan)
			{
				v3 = cARQRequest::GetPriority(pRequest);
				if (v3 < cARQRequest::GetPriority(pScan))
					continue;
			}
			break;
		}
		if (pScan)
		{
			cDList<cARQRequest_1>::InsertAfter(&thisa->baseclass_0, pScan, pRequest);
			goto LABEL_17;
		}
		goto LABEL_15;
	}
	if (flags == 1)
	{
	LABEL_15:
		cDList<cARQRequest_1>::Prepend(&thisa->baseclass_0, pRequest);
		goto LABEL_17;
	}
	if (flags == 2)
		cDList<cARQRequest_1>::Append(&thisa->baseclass_0, pRequest);
	else
		_CriticalMsg("Unknown flag", "x:\\prj\\tech\\libsrc\\arq\\arqqueue.cpp", 0x61u);
LABEL_17:
	cARQRequest::SetOwningQueue(pRequest, thisa);
	++thisa->m_cEntries;
	if (thisa->m_cEntries == 1)
		cThreadEvent::Set(&thisa->m_AvailabilitySignal);
	cThreadLock::Unlock(&thisa->m_Lock);
	return 0;
}

//----- (008D09E2) --------------------------------------------------------
int __thiscall cARQRequestQueue::RemoveRequest(cARQRequest *pRequest)
{
	cARQRequestQueue *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (!pRequest)
		_CriticalMsg("Invalid request remove", "x:\\prj\\tech\\libsrc\\arq\\arqqueue.cpp", 0x7Au);
	if (cARQRequest::GetQueueID(pRequest) != thisa->m_queueID)
		_CriticalMsg("Attempt to remove request from wrong queue", "x:\\prj\\tech\\libsrc\\arq\\arqqueue.cpp", 0x7Bu);
	cThreadLock::Lock(&thisa->m_Lock);
	cDList<cARQRequest_1>::Remove(&thisa->baseclass_0, pRequest);
	cARQRequest::SetOwningQueue(pRequest, 0);
	pRequest->baseclass_0.baseclass_0.vfptr->Release((IUnknown *)pRequest);
	--thisa->m_cEntries;
	cARQRequestQueue::ReleasePut(thisa);
	if (!thisa->m_cEntries)
		cThreadEvent::Reset(&thisa->m_AvailabilitySignal);
	cThreadLock::Unlock(&thisa->m_Lock);
	return 1;
}

//----- (008D0A9F) --------------------------------------------------------
cARQRequest* __thiscall cARQRequestQueue::GetRequest()
{
	cARQRequestQueue *thisa; // [sp+0h] [bp-8h]@1
	cARQRequest *pReturn; // [sp+4h] [bp-4h]@1

	thisa = this;
	cThreadLock::Lock(&this->m_Lock);
	pReturn = cDList<cARQRequest_1>::GetFirst(&thisa->baseclass_0);
	if (pReturn)
	{
		pReturn->baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)pReturn);
		cARQRequestQueue::RemoveRequest(thisa, pReturn);
	}
	cThreadLock::Unlock(&thisa->m_Lock);
	return pReturn;
}



//----- (008D0FC0) --------------------------------------------------------
unsigned int __thiscall cARQRequestQueue::GetMax()
{
	return 32;
}

//----- (008D0FD0) --------------------------------------------------------
void *__thiscall cARQRequestQueue::GetAvailabilitySignalHandle()
{
	return cThreadSyncObject::operator void__(&this->m_AvailabilitySignal.baseclass_0);
}



//----- (008D0780) --------------------------------------------------------
unsigned int __thiscall cARQRequestQueue::GetCount()
{
	cARQRequestQueue *v1; // ST04_4@1
	unsigned int v2; // ST08_4@1
	cAutoLock autoLock; // [sp+8h] [bp-4h]@1

	v1 = this;
	cAutoLock::cAutoLock(&autoLock, &this->m_Lock);
	v2 = v1->m_cEntries;
	cAutoLock::_cAutoLock(&autoLock);
	return v2;
}


//----- (008D0BA0) --------------------------------------------------------
void __thiscall cARQRequestQueue::WaitPut()
{
	if (!(this->m_flags & 1))
		cThreadSyncObject::Wait(&this->m_PutSemaphore.baseclass_0, 0xFFFFFFFFu);
}

//----- (008D0BD0) --------------------------------------------------------
void __thiscall cARQRequestQueue::ReleasePut()
{
	if (!(this->m_flags & 1))
		cThreadSemaphore::Release(&this->m_PutSemaphore, 1, 0);
}

*/
