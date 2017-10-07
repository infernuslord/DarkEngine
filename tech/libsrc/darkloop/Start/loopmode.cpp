//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include <aggmemb.h>

#include <dynarray.h>
#include <hashset.h>

#include <looptype.h>
#include <loopapi.h>

#include "loopmode.h"



cLoopMode::cLoopMode(sLoopModeDesc *pDescription)
{

}


cLoopMode::~cLoopMode()
{

}


sLoopModeName* cLoopMode::GetName()
{
    //return &m_desc.name;
}


/*
//----- (0089F7DE) --------------------------------------------------------
unsigned int __stdcall cLoopMode::AddRef()
{
	return cLoopMode::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (0089F7F0) --------------------------------------------------------
unsigned int __stdcall cLoopMode::Release(cLoopMode *this)
{
	unsigned int result; // eax@2

	if (cLoopMode::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cLoopMode::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cLoopMode::OnFinalRelease(this);
		result = 0;
	}
	return result;
}
*/

/*

cLoopMode::cLoopMode(sLoopModeDesc *pDescription)
{
cLoopMode *thisa;

thisa = this;
ILoopMode::ILoopMode(&this->baseclass_0);
cLoopMode::cRefCount::cRefCount(&thisa->__m_ulRefs);
thisa->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cLoopMode::_vftable_;
if(!pDescription->ppClientIDs)
_CriticalMsg("Empty loop modes are not supported", "x:\\prj\\tech\\libsrc\\darkloop\\loopmode.cpp", 0x26u);
memcpy(&thisa->m_desc, pDescription, sizeof(thisa->m_desc));
thisa->m_desc.ppClientIDs = (_GUID **)j__new(4 * thisa->m_desc.nClients, "x:\\prj\\tech\\libsrc\\darkloop\\loopmode.cpp", 41);
memcpy(thisa->m_desc.ppClientIDs, pDescription->ppClientIDs, 4 * pDescription->nClients);
}


cLoopMode::~cLoopMode()
{
this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cLoopMode::_vftable_;
operator delete(this->m_desc.ppClientIDs);
}

//----- (0089F8FE) --------------------------------------------------------
int __stdcall cLoopMode::CreatePartialDispatch(sLoopModeInitParm *list, unsigned int msgs, ILoopDispatch **result)
{
	ILoopDispatch *v4; // eax@2
	ILoopDispatch *v6; // [sp+0h] [bp-8h]@2
	void *v7; // [sp+4h] [bp-4h]@1

	v7 = j__new(0x2DCu, "x:\\prj\\tech\\libsrc\\darkloop\\loopmode.cpp", 71);
	if (v7)
	{
		cLoopDispatch::cLoopDispatch((cLoopDispatch *)v7, &this->baseclass_0, list, msgs);
		v6 = v4;
	}
	else
	{
		v6 = 0;
	}
	*result = v6;
	return *result != 0 ? 0 : -2147467259;
}







//----- (0089F962) --------------------------------------------------------
int __stdcall cLoopMode::CreateDispatch(cLoopMode *this, sLoopModeInitParm *list, ILoopDispatch **result)
{
	return ((int(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[1].Release)(
		this,
		list,
		-1,
		result);
}

//----- (0089F97F) --------------------------------------------------------
sLoopModeDesc *__stdcall cLoopMode::Describe(cLoopMode *this)
{
	return &this->m_desc;
}

//----- (0089F990) --------------------------------------------------------
unsigned int __thiscall cLoopMode::cRefCount::AddRef(cLoopMode::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (0089F9B0) --------------------------------------------------------
unsigned int __thiscall cLoopMode::cRefCount::Release(cLoopMode::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (0089F9D0) --------------------------------------------------------
unsigned int __thiscall cLoopMode::cRefCount::operator unsigned_long(cLoopMode::cRefCount *this)
{
	return this->ul;
}

//----- (0089F9E0) --------------------------------------------------------
void __thiscall cLoopMode::OnFinalRelease(cLoopMode *this)
{
	if (this)
		((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[2].AddRef)(this, 1);
}

//----- (0089FA20) --------------------------------------------------------
void __thiscall cLoopMode::cRefCount::cRefCount(cLoopMode::cRefCount *this)
{
	this->ul = 1;
}

//----- (0089FA40) --------------------------------------------------------
void *__thiscall cLoopMode::_vector_deleting_destructor_(cLoopMode *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cLoopMode::_cLoopMode(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}




//----- (0089F4F0) --------------------------------------------------------
void __thiscall sModeData::sModeData(sModeData *this, ILoopDispatch *chain, sLoopFrameInfo info, unsigned int f)
{
	this->dispatch = chain;
	this->frame.fMinorMode = info.fMinorMode;
	this->frame.nCount = info.nCount;
	this->frame.nTicks = info.nTicks;
	this->frame.dTicks = info.dTicks;
	this->flags = f;
}

//----- (0089F530) --------------------------------------------------------
void __thiscall sModeData::sModeData(sModeData *this, sModeData *mode)
{
	memcpy(this, mode, 0x18u);
}

//----- (0089F560) --------------------------------------------------------
void __thiscall cLoopModeStack::Push(cLoopModeStack *this, sModeData data)
{
	cLoopModeElem *v2; // eax@2
	cLoopModeElem *v3; // [sp+0h] [bp-10h]@2
	cDList<cLoopModeElem, 1> *thisa; // [sp+4h] [bp-Ch]@1
	void *v5; // [sp+8h] [bp-8h]@1

	thisa = (cDList<cLoopModeElem, 1> *)this;
	v5 = j__new(0x20u, "x:\\prj\\tech\\libsrc\\darkloop\\loopman.h", 81);
	if (v5)
	{
		cLoopModeElem::cLoopModeElem((cLoopModeElem *)v5, &data);
		v3 = v2;
	}
	else
	{
		v3 = 0;
	}
	cDList<cLoopModeElem_1>::Prepend(thisa, v3);
}




//----- (0089F730) --------------------------------------------------------
ILoopMode *__stdcall _LoopModeCreate(sLoopModeDesc *pDescription)
{
	ILoopMode *v1; // eax@2
	ILoopMode *v3; // [sp+0h] [bp-8h]@2
	void *this; // [sp+4h] [bp-4h]@1

	this = j__new(0x34u, "x:\\prj\\tech\\libsrc\\darkloop\\loopmode.cpp", 22);
	if (this)
	{
		cLoopMode::cLoopMode((cLoopMode *)this, pDescription);
		v3 = v1;
	}
	else
	{
		v3 = 0;
	}
	return v3;
}

//----- (0089F771) --------------------------------------------------------
int __stdcall cLoopMode::QueryInterface(cLoopMode *this, _GUID *id, void **ppI)
{
	int result; // eax@5

	if (id != &IID_ILoopMode
		&& id != &IID_IUnknown
		&& memcmp(id, &IID_ILoopMode, 0x10u)
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


//----- (0089FA70) --------------------------------------------------------
void __thiscall ILoopMode::ILoopMode(ILoopMode *this)
{
	ILoopMode *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)ILoopMode::_vftable_;
}
// 9A6B64: using guessed type int (*ILoopMode___vftable_[7])();



//----- (0089F5C0) --------------------------------------------------------
void __thiscall cLoopModeElem::cLoopModeElem(cLoopModeElem *this, sModeData *data)
{
	cLoopModeElem *v2; // ST04_4@1

	v2 = this;
	cDListNode<cLoopModeElem_1>::cDListNode<cLoopModeElem_1>(&this->baseclass_0);
	sModeData::sModeData(&v2->modedata, data);
}

//----- (0089F5F0) --------------------------------------------------------
void __thiscall cDListNode<cLoopModeElem_1>::cDListNode<cLoopModeElem_1>(cDListNode<cLoopModeElem, 1> *this)
{
	cDListNodeBase::cDListNodeBase(&this->baseclass_0);
}

//----- (0089F610) --------------------------------------------------------
sModeData *__thiscall cLoopModeStack::Pop(cLoopModeStack *this, sModeData *result)
{
	sLoopFrameInfo v2; // ST04_16@2
	sModeData *v3; // eax@2
	sModeData *v4; // eax@2
	cDList<cLoopModeElem, 1> *thisa; // [sp+0h] [bp-4Ch]@1
	__int64 v6; // [sp+8h] [bp-44h]@0
	__int64 v7; // [sp+10h] [bp-3Ch]@0
	char v8; // [sp+18h] [bp-34h]@2
	sModeData outval; // [sp+30h] [bp-1Ch]@3
	cLoopModeElem *first; // [sp+48h] [bp-4h]@1

	thisa = (cDList<cLoopModeElem, 1> *)this;
	first = cDList<cLoopModeElem_1>::GetFirst(&this->baseclass_0);
	if (first)
	{
		sModeData::sModeData(&outval, &first->modedata);
		cDList<cLoopModeElem_1>::Remove(thisa, first);
		operator delete(first);
		sModeData::sModeData(result, &outval);
		v4 = result;
	}
	else
	{
		*(_QWORD *)&v2.fMinorMode = v6;
		*(_QWORD *)&v2.nTicks = v7;
		sModeData::sModeData((sModeData *)&v8, 0, v2, 0x80u);
		sModeData::sModeData(result, v3);
		v4 = result;
	}
	return v4;
}

//----- (0089F6B0) --------------------------------------------------------
int __thiscall cIPtr<IGameShell>::operator__(cIPtr<IGameShell> *this, IGameShell *p)
{
	return cIPtrBase::operator__(&this->baseclass_0, p);
}

//----- (0089F6D0) --------------------------------------------------------
void __thiscall cDList<cLoopModeElem_1>::Prepend(cDList<cLoopModeElem, 1> *this, cLoopModeElem *Node)
{
	cDListBase::Prepend(&this->baseclass_0, &Node->baseclass_0.baseclass_0);
}

//----- (0089F6F0) --------------------------------------------------------
cLoopModeElem *__thiscall cDList<cLoopModeElem_1>::Remove(cDList<cLoopModeElem, 1> *this, cLoopModeElem *Node)
{
	return (cLoopModeElem *)cDListBase::Remove(&this->baseclass_0, &Node->baseclass_0.baseclass_0);
}

//----- (0089F710) --------------------------------------------------------
cLoopModeElem *__thiscall cDList<cLoopModeElem_1>::GetFirst(cDList<cLoopModeElem, 1> *this)
{
	return (cLoopModeElem *)cDListBase::GetFirst(&this->baseclass_0);
}
*/







