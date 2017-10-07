//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include <aggmemb.h>

#include <dynarray.h>
#include <hashset.h>

#include <looptype.h>
#include <loopapi.h>

#include "loopfact.h"






cLoopClientFactory::cLoopClientFactory(cLoopClientFactory *)
{

}

cLoopClientFactory::~cLoopClientFactory()
{
}






/*
//----- (0089CA12) --------------------------------------------------------
void __thiscall cLoopClientFactory::cLoopClientFactory(cLoopClientFactory *this)
{
	cLoopClientFactory *v1; // ST00_4@1

	v1 = this;
	cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>(&this->baseclass_0);
	cLoopClientDescTable::cLoopClientDescTable(&v1->m_ClientDescs);
	cDynArray<ILoopClientFactory__>::cDynArray<ILoopClientFactory__>(&v1->m_InnerFactories);
	v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cLoopClientFactory::_vftable_;
}
// 9A6930: using guessed type int (__stdcall *cLoopClientFactory___vftable_)(int this, int id, int ppI);




//----- (0089CA47) --------------------------------------------------------
_GUID **__stdcall cLoopClientFactory::QuerySupport(cLoopClientFactory *this)
{
	_GUID **v1; // ST04_4@4
	_GUID *item; // [sp+4h] [bp-1Ch]@4
	tHashSetHandle h; // [sp+8h] [bp-18h]@1
	sLoopClientDesc *pClientDesc; // [sp+14h] [bp-Ch]@1
	cDynArray<_GUID const *> result; // [sp+18h] [bp-8h]@1

	cDynArray<_GUID_const__>::cDynArray<_GUID_const__>(&result);
	for (pClientDesc = cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::GetFirst(
		&this->m_ClientDescs.baseclass_0.baseclass_0,
		&h);
	pClientDesc;
	pClientDesc = cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::GetNext(
		&this->m_ClientDescs.baseclass_0.baseclass_0,
		&h))
		cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::Append(&result.baseclass_0.baseclass_0, &pClientDesc->pID);
	item = 0;
	cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::Append(&result.baseclass_0.baseclass_0, &item);
	v1 = cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::Detach(&result.baseclass_0.baseclass_0);
	cDynArray<_GUID_const__>::_cDynArray<_GUID_const__>(&result);
	return v1;
}

//----- (0089CABC) --------------------------------------------------------
int __stdcall cLoopClientFactory::DoesSupport(cLoopClientFactory *this, _GUID *pID)
{
	int result; // eax@2

	if (cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::Search(
		&this->m_ClientDescs.baseclass_0.baseclass_0,
		pID))
		result = 1;
	else
		result = 0;
	return result;
}

//----- (0089CADF) --------------------------------------------------------
int __stdcall cLoopClientFactory::GetClient(cLoopClientFactory *this, _GUID *pID, tLoopClientData__ *data, ILoopClient **ppResult)
{
	ILoopClientFactory **v4; // eax@11
	int i; // [sp+8h] [bp-8h]@8
	sLoopClientDesc *pClientDesc; // [sp+Ch] [bp-4h]@1

	pClientDesc = cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::Search(
		&this->m_ClientDescs.baseclass_0.baseclass_0,
		pID);
	*ppResult = 0;
	if (pClientDesc)
	{
		switch (pClientDesc->factoryType)
		{
		case 0:
			return ppResult != 0 ? 0 : -2147467259;
		case 1:
			*ppResult = (ILoopClient *)pClientDesc->___u5.p;
			(*ppResult)->baseclass_0.vfptr->AddRef((IUnknown *)*ppResult);
			break;
		case 2:
			*ppResult = (ILoopClient *)((int(__stdcall *)(_DWORD, _DWORD))pClientDesc->___u5.p)(pClientDesc, data);
			break;
		case 3:
			(*(void(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)pClientDesc->___u5.p + 24))(
				pClientDesc->___u5.p,
				pID,
				data,
				ppResult);
			break;
		default:
			_CriticalMsg("Invalid factory type", "x:\\prj\\tech\\libsrc\\darkloop\\loopfact.cpp", 0x6Bu);
			break;
		}
	}
	else
	{
		for (i = 0;
			!*ppResult
			&& i < cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Size(&this->m_InnerFactories.baseclass_0.baseclass_0);
		++i)
		{
			v4 = cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::operator__(
				&this->m_InnerFactories.baseclass_0.baseclass_0,
				i);
			((void(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))(*v4)->baseclass_0.vfptr[2].QueryInterface)(
				*v4,
				pID,
				data,
				ppResult);
		}
	}
	return ppResult != 0 ? 0 : -2147467259;
}

//----- (0089CC09) --------------------------------------------------------
int __thiscall cLoopClientFactory::AddInnerFactory(cLoopClientFactory *this, ILoopClientFactory *pFactory)
{
	cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Append(
		&this->m_InnerFactories.baseclass_0.baseclass_0,
		&pFactory);
	pFactory->baseclass_0.vfptr->AddRef((IUnknown *)pFactory);
	return 0;
}

//----- (0089CC33) --------------------------------------------------------
int __thiscall cLoopClientFactory::RemoveInnerFactory(cLoopClientFactory *this, ILoopClientFactory *pFactory)
{
	cLoopClientFactory *thisa; // [sp+0h] [bp-8h]@1
	unsigned int i; // [sp+4h] [bp-4h]@1

	thisa = this;
	for (i = 0;
		i < cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Size(&thisa->m_InnerFactories.baseclass_0.baseclass_0);
		++i)
	{
		if (*cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::operator__(
			&thisa->m_InnerFactories.baseclass_0.baseclass_0,
			i) == pFactory)
		{
			pFactory->baseclass_0.vfptr->Release((IUnknown *)pFactory);
			cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::FastDeleteItem(
				&thisa->m_InnerFactories.baseclass_0.baseclass_0,
				i);
			return 0;
		}
	}
	return -2147467259;
}

//----- (0089CCA0) --------------------------------------------------------
void __thiscall cLoopClientFactory::ReleaseAll(cLoopClientFactory *this)
{
	ILoopClientFactory **v1; // eax@3
	cLoopClientFactory *thisa; // [sp+4h] [bp-8h]@1
	int i; // [sp+8h] [bp-4h]@1

	thisa = this;
	for (i = 0;
		i < cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Size(&thisa->m_InnerFactories.baseclass_0.baseclass_0);
		++i)
	{
		v1 = cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::operator__(
			&thisa->m_InnerFactories.baseclass_0.baseclass_0,
			i);
		(*v1)->baseclass_0.vfptr->Release((IUnknown *)*v1);
	}
}

//----- (0089CCF1) --------------------------------------------------------
int __thiscall cLoopClientFactory::AddClient(cLoopClientFactory *this, sLoopClientDesc *pClientDesc)
{
	eLoopClientFactoryType v3; // [sp+0h] [bp-8h]@3
	cLoopClientFactory *thisa; // [sp+4h] [bp-4h]@1

	thisa = this;
	if (cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::Search(
		&this->m_ClientDescs.baseclass_0.baseclass_0,
		pClientDesc->pID))
		_CriticalMsg("Double add of loop client", "x:\\prj\\tech\\libsrc\\darkloop\\loopfact.cpp", 0xA0u);
	cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::Insert(
		&thisa->m_ClientDescs.baseclass_0.baseclass_0,
		pClientDesc);
	v3 = pClientDesc->factoryType;
	if (v3 == 1)
	{
		(*(void(__stdcall **)(_DWORD))(*(_DWORD *)pClientDesc->___u5.p + 4))(pClientDesc->___u5.p);
	}
	else
	{
		if (v3 == 3)
			(*(void(__stdcall **)(_DWORD))(*(_DWORD *)pClientDesc->___u5.p + 4))(pClientDesc->___u5.p);
	}
	return 0;
}

//----- (0089CD7F) --------------------------------------------------------
int __thiscall cLoopClientFactory::AddClients(cLoopClientFactory *this, sLoopClientDesc **ppClientDescs)
{
	cLoopClientFactory *thisa; // [sp+0h] [bp-8h]@1
	int result; // [sp+4h] [bp-4h]@1

	thisa = this;
	result = 0;
	while (*ppClientDescs)
	{
		if (cLoopClientFactory::AddClient(thisa, *ppClientDescs))
			result = -2147467259;
		++ppClientDescs;
	}
	return result;
}

//----- (0089CDC4) --------------------------------------------------------
int __thiscall cLoopClientFactory::RemoveClient(cLoopClientFactory *this, _GUID *pID)
{
	eLoopClientFactoryType v3; // [sp+0h] [bp-Ch]@4
	sLoopClientDesc *pClientDesc; // [sp+8h] [bp-4h]@1

	pClientDesc = cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::RemoveByKey(
		&this->m_ClientDescs.baseclass_0.baseclass_0,
		pID);
	if (!pClientDesc)
		_CriticalMsg(
		"Client to remove from simple factory is not present",
		"x:\\prj\\tech\\libsrc\\darkloop\\loopfact.cpp",
		0xC7u);
	if (pClientDesc)
	{
		v3 = pClientDesc->factoryType;
		if (v3 == 1)
		{
			(*(void(__stdcall **)(_DWORD))(*(_DWORD *)pClientDesc->___u5.p + 8))(pClientDesc->___u5.p);
		}
		else
		{
			if (v3 == 3)
				(*(void(__stdcall **)(_DWORD))(*(_DWORD *)pClientDesc->___u5.p + 8))(pClientDesc->___u5.p);
		}
	}
	return pClientDesc != 0 ? 0 : -2147467259;
}

//----- (0089CE5B) --------------------------------------------------------
__int16 __stdcall cLoopClientFactory::GetVersion(cLoopClientFactory *this)
{
	return 1;
}

//----- (0089CE66) --------------------------------------------------------
ILoopClientFactory *__stdcall CreateLoopFactory(sLoopClientDesc **descs)
{
	cLoopClientFactory *v1; // eax@2
	cLoopClientFactory *v3; // [sp+0h] [bp-Ch]@2
	void *this; // [sp+4h] [bp-8h]@1

	this = j__new(0x24u, "x:\\prj\\tech\\libsrc\\darkloop\\loopfact.cpp", 230);
	if (this)
	{
		cLoopClientFactory::cLoopClientFactory((cLoopClientFactory *)this);
		v3 = v1;
	}
	else
	{
		v3 = 0;
	}
	cLoopClientFactory::AddClients(v3, descs);
	return (ILoopClientFactory *)v3;
}

//----- (0089CEC0) --------------------------------------------------------
void *__thiscall cLoopClientFactory::_scalar_deleting_destructor_(cLoopClientFactory *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cLoopClientFactory::_cLoopClientFactory(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (0089CEF0) --------------------------------------------------------
void __thiscall cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>(cCTUnaggregated<ILoopClientFactory, &IID_ILoopClientFactory, 0> *this)
{
	cCTUnaggregated<ILoopClientFactory, &IID_ILoopClientFactory, 0> *v1; // ST00_4@1

	v1 = this;
	ILoopClientFactory::ILoopClientFactory(&this->baseclass_0);
	cCTRefCount::cCTRefCount(&v1->__m_ulRefs);
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::_vftable_;
}
// 9A6954: using guessed type int (__stdcall *cCTUnaggregated_ILoopClientFactory___GUID const IID_ILoopClientFactory_0____vftable_)(int this, int id, int ppI);

//----- (0089CF20) --------------------------------------------------------
void __thiscall cLoopClientDescTable::cLoopClientDescTable(cLoopClientDescTable *this)
{
	cLoopClientDescTable *v1; // ST00_4@1

	v1 = this;
	cGuidHashSet<sLoopClientDesc_const__>::cGuidHashSet<sLoopClientDesc_const__>(&this->baseclass_0);
	v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cLoopClientDescTable::_vftable_;
}
// 9A6978: using guessed type int (__stdcall *cLoopClientDescTable___vftable_)(int __flags);

//----- (0089CF40) --------------------------------------------------------
void __thiscall cLoopClientFactory::_cLoopClientFactory(cLoopClientFactory *this)
{
	cLoopClientFactory *v1; // ST00_4@1

	v1 = this;
	cDynArray<ILoopClientFactory__>::_cDynArray<ILoopClientFactory__>(&this->m_InnerFactories);
	cLoopClientDescTable::_cLoopClientDescTable(&v1->m_ClientDescs);
	cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::_cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>(&v1->baseclass_0);
}




//----- (0089D4F0) --------------------------------------------------------
void __thiscall cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>(cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *this)
{
	this->m_pItems = 0;
	this->m_nItems = 0;
	cDABaseSrvFns::TrackCreate(4u);
}

//----- (0089D520) --------------------------------------------------------
void __thiscall cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::_cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>(cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *this)
{
	cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cDABaseSrvFns::TrackDestroy();
	if (thisa->m_pItems)
	{
		cDARawSrvFns<ILoopClientFactory__>::PreSetSize(thisa->m_pItems, thisa->m_nItems, 0);
		cDABaseSrvFns::DoResize((void **)&thisa->m_pItems, 4u, 0);
	}
}

//----- (0089D560) --------------------------------------------------------
ILoopClientFactory **__thiscall cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::operator__(cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *this, int index)
{
	const char *v2; // eax@2
	cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (index >= this->m_nItems)
	{
		v2 = _LogFmt("Index %d out of range");
		_CriticalMsg(v2, "x:\\prj\\tech\\h\\dynarray.h", 0x17Bu);
	}
	return &thisa->m_pItems[index];
}

//----- (0089D5B0) --------------------------------------------------------
unsigned int __thiscall cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Append(cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *this, ILoopClientFactory *const *item)
{
	cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *v2; // ST08_4@1
	unsigned int v3; // ST0C_4@1

	v2 = this;
	cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Resize(this, this->m_nItems + 1);
	v3 = v2->m_nItems++;
	cDARawSrvFns<ILoopClientFactory__>::ConstructItem(&v2->m_pItems[v3], item);
	return cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Size(v2) - 1;
}

//----- (0089D610) --------------------------------------------------------
unsigned int __thiscall cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Size(cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *this)
{
	return this->m_nItems;
}

//----- (0089D630) --------------------------------------------------------
void __thiscall cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::FastDeleteItem(cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *this, unsigned int index)
{
	const char *v2; // eax@2
	cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *thisa; // [sp+0h] [bp-8h]@1
	unsigned int last; // [sp+4h] [bp-4h]@3

	thisa = this;
	if (index >= this->m_nItems)
	{
		v2 = _LogFmt("Index %d out of range");
		_CriticalMsg(v2, "x:\\prj\\tech\\h\\dynarray.h", 0x2ACu);
	}
	last = thisa->m_nItems - 1;
	if (index == last)
		cDARawSrvFns<ILoopClientFactory__>::OnDeleteItem(&thisa->m_pItems[last]);
	else
		cDARawSrvFns<ILoopClientFactory__>::SwapDelete(&thisa->m_pItems[index], &thisa->m_pItems[last]);
	cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Resize(thisa, last);
	--thisa->m_nItems;
}

//----- (0089D6E0) --------------------------------------------------------
void __thiscall cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>(cDABase<_GUID const *, 4, cDARawSrvFns<_GUID const *> > *this)
{
	this->m_pItems = 0;
	this->m_nItems = 0;
	cDABaseSrvFns::TrackCreate(4u);
}

//----- (0089D710) --------------------------------------------------------
void __thiscall cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::_cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>(cDABase<_GUID const *, 4, cDARawSrvFns<_GUID const *> > *this)
{
	cDABase<_GUID const *, 4, cDARawSrvFns<_GUID const *> > *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cDABaseSrvFns::TrackDestroy();
	if (thisa->m_pItems)
	{
		cDARawSrvFns<_GUID_const__>::PreSetSize(thisa->m_pItems, thisa->m_nItems, 0);
		cDABaseSrvFns::DoResize((void **)&thisa->m_pItems, 4u, 0);
	}
}

//----- (0089D750) --------------------------------------------------------
_GUID **__thiscall cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::Detach(cDABase<_GUID const *, 4, cDARawSrvFns<_GUID const *> > *this)
{
	_GUID **v1; // ST04_4@1

	v1 = this->m_pItems;
	this->m_nItems = 0;
	this->m_pItems = 0;
	return v1;
}

//----- (0089D780) --------------------------------------------------------
unsigned int __thiscall cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::Append(cDABase<_GUID const *, 4, cDARawSrvFns<_GUID const *> > *this, _GUID *const *item)
{
	cDABase<_GUID const *, 4, cDARawSrvFns<_GUID const *> > *v2; // ST08_4@1
	unsigned int v3; // ST0C_4@1

	v2 = this;
	cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::Resize(this, this->m_nItems + 1);
	v3 = v2->m_nItems++;
	cDARawSrvFns<_GUID_const__>::ConstructItem(&v2->m_pItems[v3], item);
	return cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::Size(v2) - 1;
}

//----- (0089D7E0) --------------------------------------------------------
void __cdecl cDARawSrvFns<ILoopClientFactory__>::PreSetSize(ILoopClientFactory **__formal, unsigned int a2, unsigned int a3)
{
	;
}

//----- (0089D7F0) --------------------------------------------------------
void __cdecl cDARawSrvFns<ILoopClientFactory__>::ConstructItem(ILoopClientFactory **pItem, ILoopClientFactory *const *pFrom)
{
	memcpy(pItem, pFrom, 4u);
}

//----- (0089D810) --------------------------------------------------------
void __cdecl cDARawSrvFns<ILoopClientFactory__>::OnDeleteItem(ILoopClientFactory **__formal)
{
	;
}

//----- (0089D820) --------------------------------------------------------
void __cdecl cDARawSrvFns<ILoopClientFactory__>::SwapDelete(ILoopClientFactory **pItem1, ILoopClientFactory **pItem2)
{
	memcpy(pItem1, pItem2, 4u);
}

//----- (0089D840) --------------------------------------------------------
void __cdecl cDARawSrvFns<_GUID_const__>::PreSetSize(_GUID **__formal, unsigned int a2, unsigned int a3)
{
	;
}

//----- (0089D850) --------------------------------------------------------
void __cdecl cDARawSrvFns<_GUID_const__>::ConstructItem(_GUID **pItem, _GUID *const *pFrom)
{
	memcpy(pItem, pFrom, 4u);
}

//----- (0089D870) --------------------------------------------------------
int __thiscall cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Resize(cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *this, unsigned int newSlotCount)
{
	int result; // eax@2
	unsigned int evenSlots; // [sp+8h] [bp-4h]@1

	evenSlots = (newSlotCount + 3) & 0xFFFFFFFC;
	if (((this->m_nItems + 3) & 0xFFFFFFFC) == evenSlots)
		result = 1;
	else
		result = cDABaseSrvFns::DoResize((void **)&this->m_pItems, 4u, evenSlots);
	return result;
}

*/
