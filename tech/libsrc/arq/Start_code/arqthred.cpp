//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include "thrdtool.h"

#include <arqapi.h>
#include "arqqueue.h"
#include "arqreq.h"
#include "arqthred.h"








/*
__thiscall cARQFulfillerThread::~cARQFulfillerThread()
{
	cWorkerThread::~cWorkerThread();
}



unsigned int __thiscall cARQFulfillerThread::ThreadProc()
{
	int v2; // [sp+0h] [bp-34h]@17
	unsigned int v3; // [sp+4h] [bp-30h]@10
	signed int v4; // [sp+Ch] [bp-28h]@2
	cARQFulfillerThread *thisa; // [sp+10h] [bp-24h]@1
	cARQRequest *pRequest; // [sp+18h] [bp-1Ch]@21
	DWORD fWaitResult; // [sp+20h] [bp-14h]@6
	signed int fExit; // [sp+24h] [bp-10h]@4
	void *waitHandles[2]; // [sp+28h] [bp-Ch]@4
	int iCurrentPriority; // [sp+30h] [bp-4h]@4

	thisa = this;
	if (cARQRequestQueue::GetMax(this->m_RequestQueue) / 5 >= 5)
		v4 = 5;
	else
		v4 = cARQRequestQueue::GetMax(thisa->m_RequestQueue) / 5;
	iCurrentPriority = thisa->m_LightPriority;
	cWorkerThread::SetPriority(&thisa->baseclass_0, iCurrentPriority);
	fExit = 0;
	waitHandles[0] = cWorkerThread::GetCallHandle(&thisa->baseclass_0);
	waitHandles[1] = cARQRequestQueue::GetAvailabilitySignalHandle(thisa->m_RequestQueue);
	while (!fExit)
	{
		fWaitResult = WaitForMultipleObjects(2u, waitHandles, 0, 0xFFFFFFFFu);
		if (fWaitResult == -1)
			break;
		if (fWaitResult)
		{
			if (fWaitResult == 1)
			{
				cThreadLock::Lock(&thisa->m_RequestQueue->m_Lock);
				if (cARQRequestQueue::GetCount(thisa->m_RequestQueue) < v4)
					v2 = thisa->m_LightPriority;
				else
					v2 = thisa->m_NormalPriority;
				if (v2 != iCurrentPriority)
				{
					iCurrentPriority = v2;
					cWorkerThread::SetPriority(&thisa->baseclass_0, v2);
				}
				pRequest = cARQRequestQueue::GetRequest(thisa->m_RequestQueue);
				cThreadLock::Unlock(&thisa->m_RequestQueue->m_Lock);
				if (pRequest)
				{
					pRequest->baseclass_0.baseclass_0.vfptr[1].AddRef((IUnknown *)pRequest);
					pRequest->baseclass_0.baseclass_0.vfptr->Release((IUnknown *)pRequest);
				}
			}
			else
			{
				_CriticalMsg("There was nothing to do!", "x:\\prj\\tech\\libsrc\\arq\\arqthred.cpp", 0x71u);
			}
		}
		else
		{
			v3 = cWorkerThread::GetCallParam(&thisa->baseclass_0);
			if (v3)
			{
				if (v3 == 1)
				{
					cWorkerThread::Reply(&thisa->baseclass_0, 0);
					cWorkerThread::Suspend(&thisa->baseclass_0);
				}
				else
				{
					_CriticalMsg("Unknown call to ARQ fulfiller", "x:\\prj\\tech\\libsrc\\arq\\arqthred.cpp", 0x42u);
					cWorkerThread::Reply(&thisa->baseclass_0, 0x80004005u);
				}
			}
			else
			{
				cWorkerThread::Reply(&thisa->baseclass_0, 0);
				fExit = 1;
			}
		}
	}
	return 0;
}



//----- (008D0360) --------------------------------------------------------
__thiscall cARQFulfillerThread::cARQFulfillerThread(cARQRequestQueue *requestQueue)
{
	cARQFulfillerThread *v2; // ST00_4@1

	v2 = this;
	cWorkerThread::cWorkerThread(&this->baseclass_0);
	v2->m_RequestQueue = requestQueue;
	v2->m_LightPriority = 0;
	v2->m_NormalPriority = 0;
	v2->baseclass_0.vfptr = (cWorkerThreadVtbl *)&cARQFulfillerThread::_vftable_;
}
// 9A7850: using guessed type int (__stdcall *cARQFulfillerThread___vftable_)(int __flags);

//----- (008D03A0) --------------------------------------------------------
void *__thiscall cARQFulfillerThread::_vector_deleting_destructor_(unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cARQFulfillerThread::_cARQFulfillerThread(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008D03D0) --------------------------------------------------------



//----- (008D07F0) --------------------------------------------------------
void __thiscall cARQFulfillerThread::SetPrioirities(int light, int normal)
{
	this->m_LightPriority = light;
	this->m_NormalPriority = normal;
}


*/