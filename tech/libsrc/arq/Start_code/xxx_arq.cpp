#include <windows.h>
#include <lg.h>
#include <comtools.h>
#include "xxx_arq.h"



#if 0

//----- (008CFA30) --------------------------------------------------------
int __stdcall _AsyncReadQueueCreate(_GUID *__formal, IAsyncReadQueue **a2, IUnknown *pOuterUnknown)
{
	int result; // eax@2
	int v4; // eax@4
	int v5; // [sp+0h] [bp-8h]@4
	void *this; // [sp+4h] [bp-4h]@3

	if ( GetPrivateProfileIntA("Threading", "Enabled", 1, "lg.ini") )
	{
		this = operator new(0xA0u);
		if ( this )
		{
			cARQManager::cARQManager((cARQManager *)this, pOuterUnknown);
			v5 = v4;
		}
		else
		{
			v5 = 0;
		}
		if ( v5 )
			result = 0;
		else
			result = -2147467259;
	}
	else
	{
		result = 0;
	}
	return result;
}



//----- (008D04E0) --------------------------------------------------------
void __thiscall IAsyncReadQueue::IAsyncReadQueue(IAsyncReadQueue *this)
{
	IAsyncReadQueue *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)IAsyncReadQueue::_vftable_;
}
// 9A7878: using guessed type int (*IAsyncReadQueue___vftable_[12])();


//----- (008D05F0) --------------------------------------------------------
void __thiscall IAsyncReadControl::IAsyncReadControl(IAsyncReadControl *this)
{
	IAsyncReadControl *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)IAsyncReadControl::_vftable_;
}
// 9A78CC: using guessed type int (*IAsyncReadControl___vftable_[8])();

//----- (008D0610) --------------------------------------------------------
void __thiscall cDListNode<cARQRequest_1>::cDListNode<cARQRequest_1>(cDListNode<cARQRequest,1> *this)
{
	cDListNodeBase::cDListNodeBase(&this->baseclass_0);
}



//----- (008D06E0) --------------------------------------------------------
void __thiscall IAsyncReadFulfiller::IAsyncReadFulfiller(IAsyncReadFulfiller *this)
{
	IAsyncReadFulfiller *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)IAsyncReadFulfiller::_vftable_;
}
// 9A7904: using guessed type int (*IAsyncReadFulfiller___vftable_[5])();



//----- (008D0740) --------------------------------------------------------
unsigned int __thiscall cWorkerThread::Suspend(cWorkerThread *this)
{
	return SuspendThread(this->m_hThread);
}

//----- (008D0760) --------------------------------------------------------
unsigned int __thiscall cWorkerThread::Resume(cWorkerThread *this)
{
	return ResumeThread(this->m_hThread);
}





//----- (008D07D0) --------------------------------------------------------
int __thiscall cWorkerThread::GetPriority(cWorkerThread *this)
{
	return GetThreadPriority(this->m_hThread);
}





//----- (008D0AF0) --------------------------------------------------------
void __thiscall cDList<cARQRequest_1>::cDList<cARQRequest_1>(cDList<cARQRequest,1> *this)
{
	cDListBase::cDListBase(&this->baseclass_0);
}

//----- (008D0B10) --------------------------------------------------------
void __thiscall cThreadSemaphore::_cThreadSemaphore(cThreadSemaphore *this)
{
	cThreadSyncObject::_cThreadSyncObject(&this->baseclass_0);
}




//----- (008D0C00) --------------------------------------------------------
void __thiscall cDList<cARQRequest_1>::Append(cDList<cARQRequest,1> *this, cARQRequest *Node)
{
	cDListNodeBase *pNode; // [sp+0h] [bp-8h]@2

	if ( Node )
		pNode = (cDListNodeBase *)&Node->baseclass_4;
	else
		pNode = 0;
	cDListBase::Append(&this->baseclass_0, pNode);
}

//----- (008D0C40) --------------------------------------------------------
void __thiscall cDList<cARQRequest_1>::Prepend(cDList<cARQRequest,1> *this, cARQRequest *Node)
{
	cDListNodeBase *pNode; // [sp+0h] [bp-8h]@2

	if ( Node )
		pNode = (cDListNodeBase *)&Node->baseclass_4;
	else
		pNode = 0;
	cDListBase::Prepend(&this->baseclass_0, pNode);
}

//----- (008D0C80) --------------------------------------------------------
cARQRequest *__thiscall cDList<cARQRequest_1>::Remove(cDList<cARQRequest,1> *this, cARQRequest *Node)
{
	cARQRequest *v3; // [sp+0h] [bp-10h]@5
	cDListNodeBase *v4; // [sp+4h] [bp-Ch]@4
	cDListNodeBase *pNode; // [sp+8h] [bp-8h]@2

	if ( Node )
		pNode = (cDListNodeBase *)&Node->baseclass_4;
	else
		pNode = 0;
	v4 = cDListBase::Remove(&this->baseclass_0, pNode);
	if ( v4 )
		v3 = (cARQRequest *)((char *)v4 - 4);
	else
		v3 = 0;
	return v3;
}

//----- (008D0CE0) --------------------------------------------------------
cARQRequest *__thiscall cDList<cARQRequest_1>::GetFirst(cDList<cARQRequest,1> *this)
{
	cARQRequest *v2; // [sp+0h] [bp-Ch]@2
	cDListNodeBase *v3; // [sp+4h] [bp-8h]@1

	v3 = cDListBase::GetFirst(&this->baseclass_0);
	if ( v3 )
		v2 = (cARQRequest *)((char *)v3 - 4);
	else
		v2 = 0;
	return v2;
}

//----- (008D0D20) --------------------------------------------------------
cARQRequest *__thiscall cDList<cARQRequest_1>::GetLast(cDList<cARQRequest,1> *this)
{
	cARQRequest *v2; // [sp+0h] [bp-Ch]@2
	cDListNodeBase *v3; // [sp+4h] [bp-8h]@1

	v3 = cDListBase::GetLast(&this->baseclass_0);
	if ( v3 )
		v2 = (cARQRequest *)((char *)v3 - 4);
	else
		v2 = 0;
	return v2;
}

//----- (008D0D60) --------------------------------------------------------
void __thiscall cDList<cARQRequest_1>::InsertAfter(cDList<cARQRequest,1> *this, cARQRequest *Before, cARQRequest *Node)
{
	cDListNodeBase *pBefore; // [sp+0h] [bp-Ch]@5
	cDListNodeBase *pNode; // [sp+4h] [bp-8h]@2

	if ( Node )
		pNode = (cDListNodeBase *)&Node->baseclass_4;
	else
		pNode = 0;
	if ( Before )
		pBefore = (cDListNodeBase *)&Before->baseclass_4;
	else
		pBefore = 0;
	cDListBase::InsertAfter(&this->baseclass_0, pBefore, pNode);
}

//----- (008D0DB0) --------------------------------------------------------
cARQRequest *__thiscall cDListNode<cARQRequest_1>::GetPrevious(cDListNode<cARQRequest,1> *this)
{
	cARQRequest *v2; // [sp+0h] [bp-Ch]@2
	cDListNodeBase *v3; // [sp+4h] [bp-8h]@1

	v3 = cDListNodeBase::GetPrevious(&this->baseclass_0);
	if ( v3 )
		v2 = (cARQRequest *)((char *)v3 - 4);
	else
		v2 = 0;
	return v2;
}



#endif