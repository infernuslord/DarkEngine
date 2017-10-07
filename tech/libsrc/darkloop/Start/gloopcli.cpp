//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include <aggmemb.h>

#include <dynarray.h>
#include <hashset.h>

#include <looptype.h>
#include <loopapi.h>

#include "gloopcli.h"

#include <lgassert.h>

#include <coremutx.h>

#include <memall.h>



ILoopClient *__stdcall CreateSimpleLoopClient(int(__stdcall *pCallback)(void *, int, tLoopMessageData__ *), void *pContext, sLoopClientDesc *pClientDesc)
{
    ILoopClient *v3; // eax@2
    ILoopClient *v5; // [sp+0h] [bp-8h]@2
    //void *result; // [sp+4h] [bp-4h]@1

    //result = j__new(0x14u, "x:\\prj\\tech\\libsrc\\darkloop\\gloopcli.cpp", 51);
    
    //if(result)
    //{
        cGenericLoopClient::cGenericLoopClient(pCallback, pContext, pClientDesc);
        v5 = v3;
        //}
        //else
        //{
        //v5 = 0;
        //}
    return v5;
}




cGenericLoopClient::cGenericLoopClient(int(__stdcall *pCallback)(void *, int, tLoopMessageData__ *), void *pContext, sLoopClientDesc *pClientDesc)
{

}

cGenericLoopClient::~cGenericLoopClient()
{
}





/*
//----- (0089C800) --------------------------------------------------------
ILoopClient *__stdcall CreateSimpleLoopClient(int(__stdcall *pCallback)(void *, int, tLoopMessageData__ *), void *pContext, sLoopClientDesc *pClientDesc)
{
	ILoopClient *v3; // eax@2
	ILoopClient *v5; // [sp+0h] [bp-8h]@2
	void *this; // [sp+4h] [bp-4h]@1

	this = j__new(0x14u, "x:\\prj\\tech\\libsrc\\darkloop\\gloopcli.cpp", 51);
	if (this)
	{
		cGenericLoopClient::cGenericLoopClient((cGenericLoopClient *)this, pCallback, pContext, pClientDesc);
		v5 = v3;
	}
	else
	{
		v5 = 0;
	}
	return v5;
}

//----- (0089C849) --------------------------------------------------------
int __stdcall cGenericLoopClient::QueryInterface(cGenericLoopClient *this, _GUID *id, void **ppI)
{
	int result; // eax@5

	if (id != &IID_ILoopClient
		&& id != &IID_IUnknown
		&& memcmp(id, &IID_ILoopClient, 0x10u)
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

//----- (0089C8B6) --------------------------------------------------------
unsigned int __stdcall cGenericLoopClient::AddRef(cGenericLoopClient *this)
{
	return cGenericLoopClient::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (0089C8C8) --------------------------------------------------------
unsigned int __stdcall cGenericLoopClient::Release(cGenericLoopClient *this)
{
	unsigned int result; // eax@2

	if (cGenericLoopClient::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cGenericLoopClient::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cGenericLoopClient::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (0089C8F5) --------------------------------------------------------
void __thiscall cGenericLoopClient::cGenericLoopClient(cGenericLoopClient *this, int(__stdcall *pCallback)(void *, int, tLoopMessageData__ *), void *pContext, sLoopClientDesc *pClientDesc)
{
	cGenericLoopClient *v4; // ST00_4@1

	v4 = this;
	ILoopClient::ILoopClient(&this->baseclass_0);
	cGenericLoopClient::cRefCount::cRefCount(&v4->__m_ulRefs);
	v4->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cGenericLoopClient::_vftable_;
	v4->m_pCallback = pCallback;
	v4->m_pDesc = pClientDesc;
	v4->m_pContext = pContext;
}
// 9A6918: using guessed type int (__stdcall *cGenericLoopClient___vftable_)(int this, int id, int ppI);

//----- (0089C93C) --------------------------------------------------------
__int16 __stdcall cGenericLoopClient::GetVersion(cGenericLoopClient *this)
{
	return 1;
}

//----- (0089C947) --------------------------------------------------------
sLoopClientDesc *__stdcall cGenericLoopClient::GetDescription(cGenericLoopClient *this)
{
	return this->m_pDesc;
}

//----- (0089C954) --------------------------------------------------------
int __stdcall cGenericLoopClient::ReceiveMessage(cGenericLoopClient *this, int message, tLoopMessageData__ *hData)
{
	return this->m_pCallback(this->m_pContext, message, hData);
}

//----- (0089C970) --------------------------------------------------------
unsigned int __thiscall cGenericLoopClient::cRefCount::AddRef(cGenericLoopClient::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (0089C990) --------------------------------------------------------
unsigned int __thiscall cGenericLoopClient::cRefCount::Release(cGenericLoopClient::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (0089C9B0) --------------------------------------------------------
unsigned int __thiscall cGenericLoopClient::cRefCount::operator unsigned_long(cGenericLoopClient::cRefCount *this)
{
	return this->ul;
}

//----- (0089C9C0) --------------------------------------------------------
void __thiscall cGenericLoopClient::OnFinalRelease(cGenericLoopClient *this)
{
	operator delete(this);
}

//----- (0089C9E0) --------------------------------------------------------
void __thiscall cGenericLoopClient::cRefCount::cRefCount(cGenericLoopClient::cRefCount *this)
{
	this->ul = 1;
}






//----- (0089CA00) --------------------------------------------------------
tHashSetKey__ *__thiscall cLoopClientDescTable::GetKey(cLoopClientDescTable *this, tHashSetNode__ *node)
{
	return (tHashSetKey__ *)node->unused;
}



//----- (0089CF70) --------------------------------------------------------
void __thiscall cLoopClientDescTable::_cLoopClientDescTable(cLoopClientDescTable *this)
{
	cGuidHashSet<sLoopClientDesc_const__>::_cGuidHashSet<sLoopClientDesc_const__>(&this->baseclass_0);
}

//----- (0089CF90) --------------------------------------------------------
void __thiscall cDynArray<ILoopClientFactory__>::_cDynArray<ILoopClientFactory__>(cDynArray<ILoopClientFactory *> *this)
{
	cDynArray_<ILoopClientFactory___4>::_cDynArray_<ILoopClientFactory___4>(&this->baseclass_0);
}

//----- (0089CFB0) --------------------------------------------------------
void *__thiscall cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::_scalar_deleting_destructor_(cCTUnaggregated<ILoopClientFactory, &IID_ILoopClientFactory, 0> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::_cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (0089CFE0) --------------------------------------------------------
void __thiscall ILoopClientFactory::ILoopClientFactory(ILoopClientFactory *this)
{
	ILoopClientFactory *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)ILoopClientFactory::_vftable_;
}
// 9A6998: using guessed type int (*ILoopClientFactory___vftable_[7])();

//----- (0089D000) --------------------------------------------------------
void *__thiscall cLoopClientDescTable::_vector_deleting_destructor_(cLoopClientDescTable *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cLoopClientDescTable::_cLoopClientDescTable(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (0089D030) --------------------------------------------------------
void __thiscall cGuidHashSet<sLoopClientDesc_const__>::cGuidHashSet<sLoopClientDesc_const__>(cGuidHashSet<sLoopClientDesc const *> *this)
{
	cGuidHashSet<sLoopClientDesc const *> *v1; // ST04_4@1

	v1 = this;
	cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>(
		&this->baseclass_0,
		0x65u);
	v1->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cGuidHashSet<sLoopClientDesc_const__>::_vftable_;
}
// 9A69B4: using guessed type int (__stdcall *cGuidHashSet_sLoopClientDesc const _____vftable_)(int __flags);

//----- (0089D060) --------------------------------------------------------
void __thiscall cGuidHashSet<sLoopClientDesc_const__>::_cGuidHashSet<sLoopClientDesc_const__>(cGuidHashSet<sLoopClientDesc const *> *this)
{
	cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::_cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>(&this->baseclass_0);
}

//----- (0089D080) --------------------------------------------------------
void __thiscall cDynArray_<ILoopClientFactory___4>::_cDynArray_<ILoopClientFactory___4>(cDynArray_<ILoopClientFactory *, 4> *this)
{
	cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::_cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>(&this->baseclass_0);
}

//----- (0089D0A0) --------------------------------------------------------
void *__thiscall cGuidHashSet<sLoopClientDesc_const__>::_vector_deleting_destructor_(cGuidHashSet<sLoopClientDesc const *> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cGuidHashSet<sLoopClientDesc_const__>::_cGuidHashSet<sLoopClientDesc_const__>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (0089D0D0) --------------------------------------------------------
void __thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::_cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this)
{
	cHashSetBase::_cHashSetBase(&this->baseclass_0);
}

//----- (0089D0F0) --------------------------------------------------------
void __thiscall cDynArray<_GUID_const__>::_cDynArray<_GUID_const__>(cDynArray<_GUID const *> *this)
{
	cDynArray_<_GUID_const___4>::_cDynArray_<_GUID_const___4>(&this->baseclass_0);
}

//----- (0089D110) --------------------------------------------------------
void __thiscall cDynArray_<_GUID_const___4>::_cDynArray_<_GUID_const___4>(cDynArray_<_GUID const *, 4> *this)
{
	cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::_cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>(&this->baseclass_0);
}

//----- (0089D130) --------------------------------------------------------
void __thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this, unsigned int n)
{
	cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *v2; // ST14_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, n);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::_vftable_;
}
// 9A69D4: using guessed type int (__stdcall *cHashSet_sLoopClientDesc const ___GUID const __cHashFunctions____vftable_)(int __flags);

//----- (0089D1A0) --------------------------------------------------------
void __thiscall cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::_cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>(cCTUnaggregated<ILoopClientFactory, &IID_ILoopClientFactory, 0> *this)
{
	this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::_vftable_;
}
// 9A6954: using guessed type int (__stdcall *cCTUnaggregated_ILoopClientFactory___GUID const IID_ILoopClientFactory_0____vftable_)(int this, int id, int ppI);

//----- (0089D1C0) --------------------------------------------------------
void __thiscall cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::OnFinalRelease(cCTUnaggregated<ILoopClientFactory, &IID_ILoopClientFactory, 0> *this)
{
	;
}

//----- (0089D1D0) --------------------------------------------------------
int __stdcall cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::QueryInterface(cCTUnaggregated<ILoopClientFactory, &IID_ILoopClientFactory, 0> *this, _GUID *id, void **ppI)
{
	int result; // eax@5

	if (id != &IID_ILoopClientFactory
		&& id != &IID_IUnknown
		&& memcmp(id, &IID_ILoopClientFactory, 0x10u)
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

//----- (0089D240) --------------------------------------------------------
unsigned int __stdcall cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::AddRef(cCTUnaggregated<ILoopClientFactory, &IID_ILoopClientFactory, 0> *this)
{
	return cCTRefCount::AddRef(&this->__m_ulRefs);
}

//----- (0089D260) --------------------------------------------------------
unsigned int __stdcall cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::Release(cCTUnaggregated<ILoopClientFactory, &IID_ILoopClientFactory, 0> *this)
{
	unsigned int result; // eax@2

	if (cCTRefCount::Release(&this->__m_ulRefs))
	{
		result = cCTRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		((void(__thiscall *)(_DWORD))this->baseclass_0.baseclass_0.vfptr[2].Release)(this);
		if (this)
			((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[2].AddRef)(this, 1);
		result = 0;
	}
	return result;
}

//----- (0089D2D0) --------------------------------------------------------
void __thiscall cDynArray<ILoopClientFactory__>::cDynArray<ILoopClientFactory__>(cDynArray<ILoopClientFactory *> *this)
{
	cDynArray_<ILoopClientFactory___4>::cDynArray_<ILoopClientFactory___4>(&this->baseclass_0);
}

//----- (0089D2F0) --------------------------------------------------------
void __thiscall cDynArray<_GUID_const__>::cDynArray<_GUID_const__>(cDynArray<_GUID const *> *this)
{
	cDynArray_<_GUID_const___4>::cDynArray_<_GUID_const___4>(&this->baseclass_0);
}

//----- (0089D310) --------------------------------------------------------
void *__thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::_scalar_deleting_destructor_(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::_cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (0089D340) --------------------------------------------------------
void __thiscall cDynArray_<ILoopClientFactory___4>::cDynArray_<ILoopClientFactory___4>(cDynArray_<ILoopClientFactory *, 4> *this)
{
	cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>(&this->baseclass_0);
}

//----- (0089D360) --------------------------------------------------------
void __thiscall cDynArray_<_GUID_const___4>::cDynArray_<_GUID_const___4>(cDynArray_<_GUID const *, 4> *this)
{
	cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>(&this->baseclass_0);
}

//----- (0089D380) --------------------------------------------------------
sLoopClientDesc *__thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::Insert(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this, sLoopClientDesc *node)
{
	return (sLoopClientDesc *)cHashSetBase::Insert(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (0089D3A0) --------------------------------------------------------
sLoopClientDesc *__thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::Search(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this, _GUID *key)
{
	return (sLoopClientDesc *)cHashSetBase::Search(&this->baseclass_0, (tHashSetKey__ *)key);
}

//----- (0089D3C0) --------------------------------------------------------
sLoopClientDesc *__thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::RemoveByKey(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this, _GUID *k)
{
	return (sLoopClientDesc *)cHashSetBase::RemoveByKey(&this->baseclass_0, (tHashSetKey__ *)k);
}

//----- (0089D3E0) --------------------------------------------------------
void __thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::DestroyAll(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this)
{
	sHashSetChunk *v1; // ST10_4@6
	cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *thisa; // [sp+0h] [bp-14h]@1
	sHashSetChunk *p; // [sp+Ch] [bp-8h]@4
	unsigned int i; // [sp+10h] [bp-4h]@2

	thisa = this;
	if (this->baseclass_0.m_nItems)
	{
		for (i = 0; i < thisa->baseclass_0.m_nPts; ++i)
		{
			for (p = thisa->baseclass_0.m_Table[i]; p; p = v1)
			{
				v1 = p->pNext;
				sHashSetChunk::operator delete(p, 8u);
			}
			thisa->baseclass_0.m_Table[i] = 0;
		}
		thisa->baseclass_0.m_nItems = 0;
	}
}

//----- (0089D470) --------------------------------------------------------
sLoopClientDesc *__thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::GetFirst(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this, tHashSetHandle *Handle)
{
	return (sLoopClientDesc *)cHashSetBase::GetFirst(&this->baseclass_0, Handle);
}

//----- (0089D490) --------------------------------------------------------
sLoopClientDesc *__thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::GetNext(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this, tHashSetHandle *Handle)
{
	return (sLoopClientDesc *)cHashSetBase::GetNext(&this->baseclass_0, Handle);
}

//----- (0089D4B0) --------------------------------------------------------
int __thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::IsEqual(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this, tHashSetKey__ *k1, tHashSetKey__ *k2)
{
	return cHashFunctions::IsEqual((_GUID *)k1, (_GUID *)k2);
}

//----- (0089D4D0) --------------------------------------------------------
unsigned int __thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::Hash(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this, tHashSetKey__ *k)
{
	return cHashFunctions::Hash((_GUID *)k);
}

*/