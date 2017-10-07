//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include <aggmemb.h>

#include <dynarray.h>
#include <hashset.h>

#include <looptype.h>
#include <loopapi.h>

#include "loopman.h"

cLoopManager::cLoopManager(IUnknown *pOuterUnknown, unsigned int nMaxModes)
{
    cLoopManager *thisa;
    sAggAddInfo aAggAddInfo[2];

    thisa = this;




}

cLoopManager::~cLoopManager()
{

}



/*

//----- (0089DBAC) --------------------------------------------------------
void __thiscall cLoopManager::cLoopManager(cLoopManager *this, IUnknown *pOuterUnknown, unsigned int nMaxModes)
{
cLoopManager *thisa; // [sp+0h] [bp-38h]@1
sAggAddInfo aAggAddInfo[2]; // [sp+8h] [bp-30h]@2

thisa = this;
ILoopManager::ILoopManager(&this->baseclass_0);
cLoopManager::cOuterPointer::cOuterPointer((cLoopManager::cOuterPointer *)&thisa->m_Loop);
cLoopManager::cComplexAggregateControl::cComplexAggregateControl((cLoopManager::cComplexAggregateControl *)&thisa->m_Loop.__m_pOuterUnknown);
cLoopManager::cLoop::cLoop((cLoopManager::cLoop *)((char *)&thisa->m_Loop + 16), pOuterUnknown, thisa);
thisa->m_Factory.m_ClientDescs.baseclass_0.baseclass_0.baseclass_0.m_Table = (sHashSetChunk **)nMaxModes;
cLoopClientFactory::cLoopClientFactory((cLoopClientFactory *)((char *)&thisa->m_Factory + 16));
cInterfaceTable::cInterfaceTable((cInterfaceTable *)((char *)&thisa->m_nLoopModes + 16));
thisa[1].m_Loop.m_pCurrentDispatch = 0;
thisa->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cLoopManager::_vftable_;
cLoopManager::cOuterPointer::Init((cLoopManager::cOuterPointer *)&thisa->m_Loop, pOuterUnknown);
cLoopManager::cComplexAggregateControl::InitControl(
(cLoopManager::cComplexAggregateControl *)&thisa->m_Loop.__m_pOuterUnknown,
thisa);
if (pOuterUnknown)
{
aAggAddInfo[0].pID = &IID_ILoopManager;
aAggAddInfo[0].pszName = "IID_ILoopManager";
aAggAddInfo[0].pAggregated = (IUnknown *)thisa;
aAggAddInfo[0].pControl = (IUnknown *)&thisa->m_Loop.__m_pOuterUnknown;
aAggAddInfo[0].controlPriority = 4095;
aAggAddInfo[0].pControlConstraints = 0;
aAggAddInfo[1].pID = &IID_ILoop;
aAggAddInfo[1].pszName = "IID_ILoop";
aAggAddInfo[1].pAggregated = (IUnknown *)&thisa->m_Loop.m_FrameInfo;
aAggAddInfo[1].pControl = 0;
aAggAddInfo[1].controlPriority = 0;
aAggAddInfo[1].pControlConstraints = 0;
_AddToAggregate(pOuterUnknown, aAggAddInfo, 2u);
}
((void(__stdcall *)(cLoopManager::cLoop::cOuterPointer *))thisa->m_Loop.__m_pOuterUnknown.m_pOuterUnknown[2].vfptr)(&thisa->m_Loop.__m_pOuterUnknown);
}
// 9A69F4: using guessed type int (__stdcall *cLoopManager___vftable_)(int this, int id, int ppI);

//----- (0089DD33) --------------------------------------------------------
void __thiscall cLoopManager::_cLoopManager(cLoopManager *this)
{
cLoopManager *v1; // ST00_4@1

v1 = this;
this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cLoopManager::_vftable_;
cInterfaceTable::_cInterfaceTable((cInterfaceTable *)((char *)&this->m_nLoopModes + 16));
cLoopClientFactory::_cLoopClientFactory((cLoopClientFactory *)((char *)&v1->m_Factory + 16));
cLoopManager::cLoop::_cLoop((cLoopManager::cLoop *)((char *)&v1->m_Loop + 16));
}
// 9A69F4: using guessed type int (__stdcall *cLoopManager___vftable_)(int this, int id, int ppI);



//----- (0089D930) --------------------------------------------------------
int __stdcall _LoopManagerCreate(_GUID *__formal, ILoopManager **ppLoopManager, IUnknown *pOuterUnknown, unsigned int nMaxModes)
{
	ILoopManager *v4; // eax@2
	ILoopManager *v6; // [sp+0h] [bp-Ch]@2
	void *this; // [sp+4h] [bp-8h]@1

	this = j__new(0x98u, "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 29);
	if (this)
	{
		cLoopManager::cLoopManager((cLoopManager *)this, pOuterUnknown, nMaxModes);
		v6 = v4;
	}
	else
	{
		v6 = 0;
	}
	if (ppLoopManager)
		*ppLoopManager = v6;
	return v6 != 0 ? 0 : -2147467259;
}

//----- (0089D99A) --------------------------------------------------------
const char *__stdcall LoopGetMessageName(int message)
{
	int iMessage; // [sp+0h] [bp-8h]@1
	signed int currentMessage; // [sp+4h] [bp-4h]@1

	currentMessage = 1;
	iMessage = 0;
	while (currentMessage && !(message & currentMessage))
	{
		++iMessage;
		currentMessage *= 2;
	}
	if (iMessage == 33)
		iMessage = 0;
	return ppszLoopMessageNames[iMessage];
}

//----- (0089D9F2) --------------------------------------------------------
int __stdcall cLoopManager::QueryInterface(cLoopManager *this, _GUID *id, void **ppI)
{
	IUnknown *v3; // eax@1

	v3 = cLoopManager::cOuterPointer::operator_ > ((cLoopManager::cOuterPointer *)&this->m_Loop);
	return ((int(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))v3->vfptr->QueryInterface)(v3, id, ppI, v3);
}

//----- (0089DA1D) --------------------------------------------------------
unsigned int __stdcall cLoopManager::AddRef(cLoopManager *this)
{
	IUnknown *v1; // eax@1

	v1 = cLoopManager::cOuterPointer::operator_ > ((cLoopManager::cOuterPointer *)&this->m_Loop);
	return ((int(__stdcall *)(_DWORD, _DWORD))v1->vfptr->AddRef)(v1, v1);
}

//----- (0089DA41) --------------------------------------------------------
unsigned int __stdcall cLoopManager::Release(cLoopManager *this)
{
	IUnknown *v1; // eax@1

	v1 = cLoopManager::cOuterPointer::operator_ > ((cLoopManager::cOuterPointer *)&this->m_Loop);
	return ((int(__stdcall *)(_DWORD, _DWORD))v1->vfptr->Release)(v1, v1);
}

//----- (0089DA65) --------------------------------------------------------
int __stdcall cLoopManager::cComplexAggregateControl::Connect(cLoopManager::cComplexAggregateControl *this)
{
	int result; // eax@2

	if (this->m_pAggregateMember)
		result = cLoopManager::Connect(this->m_pAggregateMember);
	else
		result = 0;
	return result;
}

//----- (0089DA84) --------------------------------------------------------
int __stdcall cLoopManager::cComplexAggregateControl::PostConnect(cLoopManager::cComplexAggregateControl *this)
{
	int result; // eax@2

	if (this->m_pAggregateMember)
		result = cLoopManager::PostConnect(this->m_pAggregateMember);
	else
		result = 0;
	return result;
}

//----- (0089DAA3) --------------------------------------------------------
int __stdcall cLoopManager::cComplexAggregateControl::Init(cLoopManager::cComplexAggregateControl *this)
{
	int result; // eax@2

	if (this->m_pAggregateMember)
		result = cLoopManager::Init(this->m_pAggregateMember);
	else
		result = 0;
	return result;
}

//----- (0089DAC2) --------------------------------------------------------
int __stdcall cLoopManager::cComplexAggregateControl::End(cLoopManager::cComplexAggregateControl *this)
{
	int result; // eax@2

	if (this->m_pAggregateMember)
		result = cLoopManager::End(this->m_pAggregateMember);
	else
		result = 0;
	return result;
}

//----- (0089DAE1) --------------------------------------------------------
int __stdcall cLoopManager::cComplexAggregateControl::Disconnect(cLoopManager::cComplexAggregateControl *this)
{
	int result; // eax@2

	if (this->m_pAggregateMember)
		result = cLoopManager::Disconnect(this->m_pAggregateMember);
	else
		result = 0;
	return result;
}

//----- (0089DB00) --------------------------------------------------------
int __stdcall cLoopManager::cComplexAggregateControl::QueryInterface(cLoopManager::cComplexAggregateControl *this, _GUID *id, void **ppI)
{
	int result; // eax@5

	if (id != &IID_IAggregateMemberControl
		&& id != &IID_IUnknown
		&& memcmp(id, &IID_IAggregateMemberControl, 0x10u)
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

//----- (0089DB6D) --------------------------------------------------------
unsigned int __stdcall cLoopManager::cComplexAggregateControl::AddRef(cLoopManager::cComplexAggregateControl *this)
{
	return cLoopManager::cComplexAggregateControl::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (0089DB7F) --------------------------------------------------------
unsigned int __stdcall cLoopManager::cComplexAggregateControl::Release(cLoopManager::cComplexAggregateControl *this)
{
	unsigned int result; // eax@2

	if (cLoopManager::cComplexAggregateControl::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cLoopManager::cComplexAggregateControl::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cLoopManager::cComplexAggregateControl::OnFinalRelease(this);
		result = 0;
	}
	return result;
}


//----- (0089DD6B) --------------------------------------------------------
int __stdcall cLoopManager::AddClient(cLoopManager *this, ILoopClient *pClient, unsigned int *pCookie)
{
	int v3; // ecx@0
	unsigned int *pClientDesc; // [sp+0h] [bp-4h]@1

	pClientDesc = (unsigned int *)((int(__stdcall *)(ILoopClient *, int))pClient->baseclass_0.vfptr[1].AddRef)(
		pClient,
		v3);
	if ((*(int(__stdcall **)(unsigned int *, unsigned int))(this->m_Factory.m_ClientDescs.baseclass_0.baseclass_0.baseclass_0.m_nPts
		+ 20))(
		&this->m_Factory.m_ClientDescs.baseclass_0.baseclass_0.baseclass_0.m_nPts,
		*pClientDesc))
		_CriticalMsg("Double add of loop client", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0x92u);
	*pCookie = *pClientDesc;
	return cLoopClientFactory::AddClient(
		(cLoopClientFactory *)((char *)&this->m_Factory + 16),
		(sLoopClientDesc *)pClientDesc);
}

//----- (0089DDD3) --------------------------------------------------------
int __stdcall cLoopManager::RemoveClient(cLoopManager *this, unsigned int cookie)
{
	return cLoopClientFactory::RemoveClient((cLoopClientFactory *)((char *)&this->m_Factory + 16), (_GUID *)cookie);
}

//----- (0089DDE9) --------------------------------------------------------
int __stdcall cLoopManager::AddClientFactory(cLoopManager *this, ILoopClientFactory *pFactory, unsigned int *pCookie)
{
	*pCookie = (unsigned int)pFactory;
	return cLoopClientFactory::AddInnerFactory((cLoopClientFactory *)((char *)&this->m_Factory + 16), pFactory);
}

//----- (0089DE07) --------------------------------------------------------
int __stdcall cLoopManager::RemoveClientFactory(cLoopManager *this, unsigned int cookie)
{
	return cLoopClientFactory::RemoveInnerFactory(
		(cLoopClientFactory *)((char *)&this->m_Factory + 16),
		(ILoopClientFactory *)cookie);
}

//----- (0089DE1D) --------------------------------------------------------
int __stdcall cLoopManager::GetClient(cLoopManager *this, _GUID *pID, tLoopClientData__ *data, ILoopClient **ppReturn)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(this->m_Factory.m_ClientDescs.baseclass_0.baseclass_0.baseclass_0.m_nPts
		+ 24))(
		&this->m_Factory.m_ClientDescs.baseclass_0.baseclass_0.baseclass_0.m_nPts,
		pID,
		data,
		ppReturn);
}

//----- (0089DE40) --------------------------------------------------------
int __stdcall cLoopManager::AddMode(cLoopManager *this, sLoopModeDesc *pDesc)
{
	int result; // eax@4
	cInterfaceInfo *v3; // eax@6
	cInterfaceInfo *v4; // [sp+0h] [bp-10h]@6
	void *v5; // [sp+4h] [bp-Ch]@5
	IUnknown *pLoopMode; // [sp+8h] [bp-8h]@1

	pLoopMode = (IUnknown *)_LoopModeCreate(pDesc);
	if (!pLoopMode)
		_CriticalMsg("Failed to create loop mode", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0xC9u);
	if (pLoopMode)
	{
		v5 = j__new(0x1Cu, "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 206);
		if (v5)
		{
			cInterfaceInfo::cInterfaceInfo((cInterfaceInfo *)v5, pDesc->name.pID, pLoopMode, 0);
			v4 = v3;
		}
		else
		{
			v4 = 0;
		}
		cHashSet<cInterfaceInfo____GUID_const___cHashFunctions>::Insert(
			(cHashSet<cInterfaceInfo *, _GUID const *, cHashFunctions> *)((char *)&this->m_nLoopModes.baseclass_0.baseclass_0
			+ 16),
			v4);
		result = 0;
	}
	else
	{
		result = -2147467259;
	}
	return result;
}

//----- (0089DEDE) --------------------------------------------------------
ILoopMode *__stdcall cLoopManager::GetMode(cLoopManager *this, _GUID *pID)
{
	ILoopMode *result; // eax@2
	ILoopMode *pLoopMode; // [sp+0h] [bp-8h]@2
	cInterfaceInfo *pLoopModeInfo; // [sp+4h] [bp-4h]@1

	pLoopModeInfo = cHashSet<cInterfaceInfo____GUID_const___cHashFunctions>::Search(
		(cHashSet<cInterfaceInfo *, _GUID const *, cHashFunctions> *)((char *)&this->m_nLoopModes.baseclass_0.baseclass_0
		+ 16),
		pID);
	if (pLoopModeInfo)
	{
		(**(void(__stdcall ***)(_DWORD, _DWORD, _DWORD))pLoopModeInfo->pUnknown)(
			pLoopModeInfo->pUnknown,
			&IID_ILoopMode,
			&pLoopMode);
		result = pLoopMode;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (0089DF26) --------------------------------------------------------
int __stdcall cLoopManager::RemoveMode(cLoopManager *this, _GUID *pID)
{
	int result; // eax@8
	cInterfaceInfo *pLoopModeInfo; // [sp+Ch] [bp-4h]@1

	pLoopModeInfo = cHashSet<cInterfaceInfo____GUID_const___cHashFunctions>::Search(
		(cHashSet<cInterfaceInfo *, _GUID const *, cHashFunctions> *)((char *)&this->m_nLoopModes.baseclass_0.baseclass_0
		+ 16),
		pID);
	if (!pLoopModeInfo)
		_CriticalMsg("Attempted to remove mode that was never added", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0xEDu);
	if (pLoopModeInfo)
	{
		cHashSet<cInterfaceInfo____GUID_const___cHashFunctions>::Remove(
			(cHashSet<cInterfaceInfo *, _GUID const *, cHashFunctions> *)((char *)&this->m_nLoopModes.baseclass_0.baseclass_0
			+ 16),
			pLoopModeInfo);
		if (pLoopModeInfo->pUnknown)
			pLoopModeInfo->pUnknown->vfptr->Release(pLoopModeInfo->pUnknown);
		pLoopModeInfo->pUnknown = 0;
		if (pLoopModeInfo)
			cInterfaceInfo::_scalar_deleting_destructor_(pLoopModeInfo, 1u);
		result = 0;
	}
	else
	{
		result = -2147467259;
	}
	return result;
}

//----- (0089DFD7) --------------------------------------------------------
int __stdcall cLoopManager::SetBaseMode(cLoopManager *this, _GUID *pID)
{
	int result; // eax@4
	cInterfaceInfo *pMode; // [sp+0h] [bp-4h]@1

	pMode = cHashSet<cInterfaceInfo____GUID_const___cHashFunctions>::Search(
		(cHashSet<cInterfaceInfo *, _GUID const *, cHashFunctions> *)((char *)&this->m_nLoopModes.baseclass_0.baseclass_0
		+ 16),
		pID);
	if (!pMode)
		_CriticalMsg(
		"Attempted to set a base mode that was never added",
		"x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp",
		0x102u);
	if (pMode)
	{
		this[1].m_Loop.m_pCurrentDispatch = (ILoopDispatch *)pID;
		result = 0;
	}
	else
	{
		this[1].m_Loop.m_pCurrentDispatch = 0;
		result = -2147467259;
	}
	return result;
}

//----- (0089E040) --------------------------------------------------------
ILoopMode *__stdcall cLoopManager::GetBaseMode(cLoopManager *this)
{
	ILoopMode *result; // eax@2

	if (this[1].m_Loop.m_pCurrentDispatch)
		result = (ILoopMode *)((int(__stdcall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[3].QueryInterface)(
		this,
		this[1].m_Loop.m_pCurrentDispatch);
	else
		result = 0;
	return result;
}

//----- (0089E06D) --------------------------------------------------------
int __thiscall cLoopManager::End(cLoopManager *this)
{
	cLoopManager *v1; // ST04_4@1

	v1 = this;
	cLoopClientFactory::ReleaseAll((cLoopClientFactory *)((char *)&this->m_Factory + 16));
	cInterfaceTable::ReleaseAll((cInterfaceTable *)((char *)&v1->m_nLoopModes + 16), 1);
	return 0;
}

//----- (0089E095) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::QueryInterface(cLoopManager::cLoop *this, _GUID *id, void **ppI)
{
	IUnknown *v3; // eax@1

	v3 = cLoopManager::cLoop::cOuterPointer::operator_ > (&this->__m_pOuterUnknown);
	return ((int(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))v3->vfptr->QueryInterface)(v3, id, ppI, v3);
}

//----- (0089E0C0) --------------------------------------------------------
unsigned int __stdcall cLoopManager::cLoop::AddRef(cLoopManager::cLoop *this)
{
	IUnknown *v1; // eax@1

	v1 = cLoopManager::cLoop::cOuterPointer::operator_ > (&this->__m_pOuterUnknown);
	return ((int(__stdcall *)(_DWORD, _DWORD))v1->vfptr->AddRef)(v1, v1);
}

//----- (0089E0E4) --------------------------------------------------------
unsigned int __stdcall cLoopManager::cLoop::Release(cLoopManager::cLoop *this)
{
	IUnknown *v1; // eax@1

	v1 = cLoopManager::cLoop::cOuterPointer::operator_ > (&this->__m_pOuterUnknown);
	return ((int(__stdcall *)(_DWORD, _DWORD))v1->vfptr->Release)(v1, v1);
}

//----- (0089E108) --------------------------------------------------------
void __thiscall cLoopManager::cLoop::_cLoop(cLoopManager::cLoop *this)
{
	cLoopManager::cLoop *v1; // ST0C_4@1

	v1 = this;
	this->baseclass_0.lpVtbl = (ILoopVtbl *)&cLoopManager::cLoop::_vftable_;
	operator delete(this->m_pLoopStack);
	if (v1->m_pCurrentDispatch)
		_CriticalMsg(
		"Expected exit of loop manager before destruction!",
		"x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp",
		0x138u);
}
// 9A6A4C: using guessed type int (__stdcall *cLoopManager__cLoop___vftable_)(int this, int id, int ppI);

//----- (0089E158) --------------------------------------------------------
ILoopMode *__stdcall cLoopManager::cLoop::GetCurrentMode(cLoopManager::cLoop *this)
{
	int v1; // ecx@0
	int v2; // eax@1

	v2 = ((int(__stdcall *)(ILoopDispatch *, _DWORD, int))this->m_pCurrentDispatch->baseclass_0.vfptr[2].Release)(
		this->m_pCurrentDispatch,
		0,
		v1);
	return (ILoopMode *)((int(__stdcall *)(ILoopManager *, _DWORD))this->m_pLoopManager->baseclass_0.vfptr[3].QueryInterface)(
		this->m_pLoopManager,
		*(_DWORD *)v2);
}

//----- (0089E191) --------------------------------------------------------
ILoopDispatch *__stdcall cLoopManager::cLoop::GetCurrentDispatch(cLoopManager::cLoop *this)
{
	return this->m_pCurrentDispatch;
}

//----- (0089E19E) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::Go(cLoopManager::cLoop *this, sLoopInstantiator *loop)
{
	sModeData *v2; // eax@1
	cLoopModeStack *v3; // eax@2
	IUnknownVtbl *v4; // eax@4
	int v5; // eax@7
	int v6; // edx@8
	int v7; // edx@9
	IUnknown *v8; // eax@12
	IUnknownVtbl *v9; // eax@17
	IUnknownVtbl *v10; // edx@18
	IUnknownVtbl *v11; // eax@18
	IUnknownVtbl *v12; // edx@18
	unsigned int v13; // ecx@18
	IUnknownVtbl *v14; // eax@20
	IUnknownVtbl *v15; // edx@22
	IUnknownVtbl *v16; // ecx@23
	IGameShell *v17; // eax@24
	IUnknownVtbl *v18; // eax@24
	IUnknownVtbl *v19; // eax@25
	IUnknownVtbl *v20; // edx@26
	IUnknownVtbl *v21; // eax@27
	IUnknownVtbl *v22; // ecx@27
	IGameShell *v23; // eax@28
	IUnknownVtbl *v24; // eax@28
	unsigned int v25; // eax@33
	unsigned int v26; // eax@33
	IUnknownVtbl *v27; // edx@38
	IUnknownVtbl *v28; // ecx@39
	IUnknownVtbl *v29; // eax@41
	IUnknownVtbl *v30; // edx@41
	IUnknownVtbl *v31; // ecx@41
	IUnknownVtbl *v32; // eax@42
	sModeData *v33; // eax@44
	sModeData v34; // [sp-18h] [bp-C4h]@1
	int v35; // [sp-14h] [bp-C0h]@1
	unsigned int v36; // [sp-10h] [bp-BCh]@1
	signed int v37; // [sp-Ch] [bp-B8h]@1
	int v38; // [sp-8h] [bp-B4h]@1
	void *v39; // [sp-4h] [bp-B0h]@1
	void *v40; // [sp+0h] [bp-ACh]@28
	IGameShell *v41; // [sp+4h] [bp-A8h]@26
	int v42; // [sp+8h] [bp-A4h]@24
	IGameShell *v43; // [sp+Ch] [bp-A0h]@22
	cLoopModeStack *v44; // [sp+10h] [bp-9Ch]@2
	int v45; // [sp+14h] [bp-98h]@44
	sModeData result; // [sp+18h] [bp-94h]@44
	void *p; // [sp+30h] [bp-7Ch]@44
	void *v48; // [sp+34h] [bp-78h]@1
	char v49; // [sp+38h] [bp-74h]@1
	int outmsg; // [sp+54h] [bp-58h]@36
	int inmsg; // [sp+58h] [bp-54h]@15
	int ticks; // [sp+5Ch] [bp-50h]@29
	sModeData old; // [sp+60h] [bp-4Ch]@44
	sLoopTransition trans; // [sp+78h] [bp-34h]@1
	cLoopModeStack *old_stack; // [sp+90h] [bp-1Ch]@1
	int minorMode; // [sp+94h] [bp-18h]@1
	int frameMessage; // [sp+98h] [bp-14h]@12
	_GUID *pID; // [sp+9Ch] [bp-10h]@1
	signed int pMode; // [sp+A0h] [bp-Ch]@4
	sLoopModeInitParm *parmList; // [sp+A4h] [bp-8h]@1
	cAutoIPtr<IGameShell> pGameShell; // [sp+A8h] [bp-4h]@12

	pID = loop->pID;
	minorMode = loop->minorMode;
	parmList = loop->init;
	trans.from.pID = &GUID_NULL;
	trans.to.pID = loop->pID;
	trans.to.minorMode = loop->minorMode;
	trans.to.init = loop->init;
	v39 = (void *)128;
	v35 = this->m_FrameInfo.fMinorMode;
	v36 = this->m_FrameInfo.nCount;
	v37 = this->m_FrameInfo.nTicks;
	v38 = this->m_FrameInfo.dTicks;
	sModeData::sModeData((sModeData *)&v49, this->m_pCurrentDispatch, *(sLoopFrameInfo *)&v35, 0x80u);
	sModeData::sModeData(&v34, v2);
	cLoopModeStack::Push(this->m_pLoopStack, v34);
	old_stack = this->m_pLoopStack;
	v48 = j__new(8u, "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 355);
	if (v48)
	{
		cLoopModeStack::cLoopModeStack((cLoopModeStack *)v48);
		v44 = v3;
	}
	else
	{
		v44 = 0;
	}
	this->m_pLoopStack = v44;
	v39 = (void *)pID;
	v4 = this->m_pLoopManager->baseclass_0.vfptr;
	v38 = (int)this->m_pLoopManager;
	pMode = ((int(__stdcall *)(int, _GUID *))v4[3].QueryInterface)(v38, pID);
	if (!pMode)
		_CriticalMsg(
		"Attempted to \"go\" on mode that was never added",
		"x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp",
		0x167u);
	if (pMode)
	{
		v39 = &this->m_pNextDispatch;
		v38 = (int)parmList;
		v6 = *(_DWORD *)pMode;
		v37 = pMode;
		(*(void(__stdcall **)(signed int, sLoopModeInitParm *, ILoopDispatch **))(v6 + 16))(
			pMode,
			parmList,
			&this->m_pNextDispatch);
		if (pMode)
		{
			v7 = *(_DWORD *)pMode;
			v39 = (void *)pMode;
			(*(void(__stdcall **)(signed int))(v7 + 8))(pMode);
		}
		pMode = 0;
		if (!DoneAtExit[0])
		{
			atexit(cLoopManager::cLoop::OnExit);
			DoneAtExit[0] = 1;
		}
		this->m_fNewMinorMode = minorMode;
		this->m_fState |= 0x10u;
		v8 = _AppGetAggregated(&IID_IGameShell);
		cAutoIPtr<IGameShell>::cAutoIPtr<IGameShell>(&pGameShell, (IGameShell *)v8);
		frameMessage = 128;
		this->m_fState |= 0x21u;
		while (this->m_fState & 1)
		{
			if (this->m_fState & 0x20)
			{
				inmsg = 4096;
				if (this->m_fState & 0x80)
				{
					inmsg = 16384;
				}
				else
				{
					v9 = this->m_pNextDispatch->baseclass_0.vfptr;
					v39 = this->m_pNextDispatch;
					v9[2].AddRef((IUnknown *)v39);
				}
				this->m_pCurrentDispatch = this->m_pNextDispatch;
				this->m_pNextDispatch = 0;
				v39 = (void *)this->m_tempDiagnosticSet;
				v38 = this->m_fTempDiagnostics;
				v10 = this->m_pCurrentDispatch->baseclass_0.vfptr;
				v37 = (signed int)this->m_pCurrentDispatch;
				v10[3].QueryInterface((IUnknown *)v37, (_GUID *)v38, (void **)v39);
				v39 = (void *)this->m_pTempProfileClientId;
				v38 = this->m_TempProfileSet;
				v11 = this->m_pCurrentDispatch->baseclass_0.vfptr;
				v37 = (signed int)this->m_pCurrentDispatch;
				((void(__stdcall *)(signed int, int, void *))v11[3].Release)(v37, v38, v39);
				v39 = (void *)1;
				v38 = (int)&trans;
				v37 = inmsg;
				v12 = this->m_pCurrentDispatch->baseclass_0.vfptr;
				v36 = (unsigned int)this->m_pCurrentDispatch;
				((void(__stdcall *)(unsigned int, int, sLoopTransition *, signed int))v12[1].QueryInterface)(
					v36,
					inmsg,
					&trans,
					1);
				v13 = this->m_fState;
				LOBYTE(v13) = v13 & 0x1F;
				this->m_fState = v13;
				this->m_FrameInfo.nTicks = tm_get_millisec();
				this->m_FrameInfo.dTicks = 0;
			}
			if (this->m_fState & 0x10)
			{
				this->m_FrameInfo.fMinorMode = this->m_fNewMinorMode;
				v39 = (void *)1;
				v38 = this->m_FrameInfo.fMinorMode;
				v37 = 65536;
				v14 = this->m_pCurrentDispatch->baseclass_0.vfptr;
				v36 = (unsigned int)this->m_pCurrentDispatch;
				((void(__stdcall *)(unsigned int, signed int, int, signed int))v14[1].QueryInterface)(v36, 65536, v38, 1);
				this->m_fState &= 0xFFFFFFEFu;
			}
			if (cIPtr<IGameShell>::operator__(&pGameShell.baseclass_0, 0))
			{
				v43 = cIPtr<IGameShell>::operator_ > (&pGameShell.baseclass_0);
				v15 = v43->baseclass_0.vfptr;
				v39 = v43;
				((void(__stdcall *)(IGameShell *))v15[1].QueryInterface)(v43);
			}
			v39 = (void *)1;
			v38 = (int)&this->m_FrameInfo;
			v37 = 64;
			v16 = this->m_pCurrentDispatch->baseclass_0.vfptr;
			v36 = (unsigned int)this->m_pCurrentDispatch;
			((void(__stdcall *)(unsigned int, signed int, sLoopFrameInfo *, signed int))v16[1].QueryInterface)(
				v36,
				64,
				&this->m_FrameInfo,
				1);
			if (cIPtr<IGameShell>::operator__(&pGameShell.baseclass_0, 0))
			{
				v39 = 0;
				v17 = cIPtr<IGameShell>::operator_ > (&pGameShell.baseclass_0);
				v42 = (int)v17;
				v18 = v17->baseclass_0.vfptr;
				v38 = v42;
				((void(__stdcall *)(int, void *))v18[2].AddRef)(v42, v39);
			}
			v39 = (void *)1;
			v38 = (int)&this->m_FrameInfo;
			v37 = frameMessage;
			v19 = this->m_pCurrentDispatch->baseclass_0.vfptr;
			v36 = (unsigned int)this->m_pCurrentDispatch;
			((void(__stdcall *)(unsigned int, int, sLoopFrameInfo *, signed int))v19[1].QueryInterface)(
				v36,
				frameMessage,
				&this->m_FrameInfo,
				1);
			if (cIPtr<IGameShell>::operator__(&pGameShell.baseclass_0, 0))
			{
				v39 = 0;
				v41 = cIPtr<IGameShell>::operator_ > (&pGameShell.baseclass_0);
				v20 = v41->baseclass_0.vfptr;
				v38 = (int)v41;
				((void(__stdcall *)(IGameShell *, void *))v20[2].AddRef)(v41, v39);
			}
			v21 = this->m_pCurrentDispatch->baseclass_0.vfptr;
			v39 = this->m_pCurrentDispatch;
			v21[2].AddRef((IUnknown *)v39);
			v39 = (void *)2;
			v38 = (int)&this->m_FrameInfo;
			v37 = 512;
			v22 = this->m_pCurrentDispatch->baseclass_0.vfptr;
			v36 = (unsigned int)this->m_pCurrentDispatch;
			((void(__stdcall *)(unsigned int, signed int, sLoopFrameInfo *, signed int))v22[1].QueryInterface)(
				v36,
				512,
				&this->m_FrameInfo,
				2);
			if (cIPtr<IGameShell>::operator__(&pGameShell.baseclass_0, 0))
			{
				v23 = cIPtr<IGameShell>::operator_ > (&pGameShell.baseclass_0);
				v40 = v23;
				v24 = v23->baseclass_0.vfptr;
				v39 = v40;
				v24[1].AddRef((IUnknown *)v40);
			}
			++this->m_FrameInfo.nCount;
			ticks = tm_get_millisec();
			this->m_FrameInfo.dTicks = ticks - this->m_FrameInfo.nTicks;
			this->m_FrameInfo.nTicks = ticks;
			if (this->m_fState & 0xC)
			{
				if (this->m_fState & 4)
					frameMessage = 256;
				else
					frameMessage = 128;
				v25 = this->m_fState;
				LOBYTE(v25) = v25 & 0xF3;
				this->m_fState = v25;
				v26 = this->m_fState;
				LOBYTE(v26) = v26 | 2;
				this->m_fState = v26;
			}
			if (this->m_fState & 0x20 || !(this->m_fState & 1))
			{
				outmsg = 32768;
				if (this->m_fState & 0x40)
					outmsg = 8192;
				v39 = &trans.from.init;
				v27 = this->m_pCurrentDispatch->baseclass_0.vfptr;
				v38 = (int)this->m_pCurrentDispatch;
				trans.from.pID = *(_GUID **)((int(__stdcall *)(int, sLoopModeInitParm **))v27[2].Release)(
					v38,
					&trans.from.init);
				trans.from.minorMode = this->m_FrameInfo.fMinorMode;
				if (this->m_pNextDispatch)
				{
					v39 = &trans.to.init;
					v28 = this->m_pNextDispatch->baseclass_0.vfptr;
					v38 = (int)this->m_pNextDispatch;
					trans.to.pID = *(_GUID **)((int(__stdcall *)(int, sLoopModeInitParm **))v28[2].Release)(v38, &trans.to.init);
					trans.to.minorMode = this->m_fNewMinorMode;
				}
				else
				{
					trans.to.pID = &GUID_NULL;
				}
				v39 = (void *)2;
				v38 = (int)&trans;
				v37 = outmsg;
				v29 = this->m_pCurrentDispatch->baseclass_0.vfptr;
				v36 = (unsigned int)this->m_pCurrentDispatch;
				((void(__stdcall *)(unsigned int, int, sLoopTransition *, signed int))v29[1].QueryInterface)(
					v36,
					outmsg,
					&trans,
					2);
				v39 = &this->m_tempDiagnosticSet;
				v38 = (int)&this->m_fTempDiagnostics;
				v30 = this->m_pCurrentDispatch->baseclass_0.vfptr;
				v37 = (signed int)this->m_pCurrentDispatch;
				((void(__stdcall *)(signed int, unsigned int *, unsigned int *))v30[3].AddRef)(
					v37,
					&this->m_fTempDiagnostics,
					&this->m_tempDiagnosticSet);
				v39 = &this->m_pTempProfileClientId;
				v38 = (int)&this->m_TempProfileSet;
				v31 = this->m_pCurrentDispatch->baseclass_0.vfptr;
				v37 = (signed int)this->m_pCurrentDispatch;
				v31[4].QueryInterface((IUnknown *)v37, (_GUID *)&this->m_TempProfileSet, (void **)&this->m_pTempProfileClientId);
				if (!(this->m_fState & 0x40))
				{
					v32 = this->m_pCurrentDispatch->baseclass_0.vfptr;
					v39 = this->m_pCurrentDispatch;
					v32->Release((IUnknown *)v39);
				}
			}
		}
		p = this->m_pLoopStack;
		operator delete(p);
		this->m_pLoopStack = old_stack;
		v33 = cLoopModeStack::Pop(old_stack, &result);
		sModeData::sModeData(&old, v33);
		this->m_pCurrentDispatch = old.dispatch;
		this->m_FrameInfo.fMinorMode = old.frame.fMinorMode;
		this->m_FrameInfo.nCount = old.frame.nCount;
		this->m_FrameInfo.nTicks = old.frame.nTicks;
		this->m_FrameInfo.dTicks = old.frame.dTicks;
		v45 = this->m_fGoReturn;
		cAutoIPtr<IGameShell>::_cAutoIPtr<IGameShell>(&pGameShell);
		v5 = v45;
	}
	else
	{
		v5 = -2147467259;
	}
	return v5;
}

//----- (0089E7AE) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::EndAllModes(cLoopManager::cLoop *this, int goRetVal)
{
	int v2; // eax@2
	sLoopFrameInfo v3; // ST04_16@3
	unsigned int v4; // eax@6
	char v5; // [sp+8h] [bp-70h]@5
	sModeData result; // [sp+20h] [bp-58h]@3
	__int64 v7; // [sp+38h] [bp-40h]@3
	__int64 v8; // [sp+40h] [bp-38h]@3
	sLoopTransition trans; // [sp+48h] [bp-30h]@5
	sModeData mode; // [sp+60h] [bp-18h]@3

	if (this->m_pCurrentDispatch)
	{
		this->m_fGoReturn = goRetVal;
		*(_QWORD *)&v3.fMinorMode = v7;
		*(_QWORD *)&v3.nTicks = v8;
		sModeData::sModeData(&mode, 0, v3, 0x80u);
		memcpy(&mode, cLoopModeStack::Pop(this->m_pLoopStack, &result), sizeof(mode));
		while ((_DWORD)mode.dispatch)
		{
			trans.from.pID = *(_GUID **)((int(__stdcall *)(ILoopDispatch *, sLoopModeInitParm **))mode.dispatch->baseclass_0.vfptr[2].Release)(
				mode.dispatch,
				&trans.from.init);
			trans.from.minorMode = mode.frame.fMinorMode;
			trans.to.pID = &GUID_NULL;
			((void(__stdcall *)(ILoopDispatch *, signed int, sLoopTransition *, signed int))mode.dispatch->baseclass_0.vfptr[1].QueryInterface)(
				mode.dispatch,
				32768,
				&trans,
				2);
			mode.dispatch->baseclass_0.vfptr->Release((IUnknown *)mode.dispatch);
			memcpy(&mode, cLoopModeStack::Pop(this->m_pLoopStack, (sModeData *)&v5), sizeof(mode));
		}
		v4 = this->m_fState;
		LOBYTE(v4) = v4 & 0xFE;
		this->m_fState = v4;
		v2 = 0;
	}
	else
	{
		v2 = 1;
	}
	return v2;
}

//----- (0089E89A) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::Terminate(cLoopManager::cLoop *this)
{
	sLoopTransition trans; // [sp+0h] [bp-18h]@2

	if (this->m_pCurrentDispatch)
	{
		trans.from.pID = *(_GUID **)((int(__stdcall *)(ILoopDispatch *, sLoopModeInitParm **))this->m_pCurrentDispatch->baseclass_0.vfptr[2].Release)(
			this->m_pCurrentDispatch,
			&trans.from.init);
		trans.from.minorMode = this->m_FrameInfo.fMinorMode;
		trans.to.pID = &GUID_NULL;
		((void(__stdcall *)(ILoopDispatch *, signed int, sLoopTransition *, signed int))this->m_pCurrentDispatch->baseclass_0.vfptr[1].QueryInterface)(
			this->m_pCurrentDispatch,
			32768,
			&trans,
			2);
		if (this->m_pCurrentDispatch)
			this->m_pCurrentDispatch->baseclass_0.vfptr->Release((IUnknown *)this->m_pCurrentDispatch);
		this->m_pCurrentDispatch = 0;
		this->baseclass_0.lpVtbl->EndAllModes((ILoop *)this, 0);
	}
	return 0;
}

//----- (0089E92C) --------------------------------------------------------
sLoopFrameInfo *__stdcall cLoopManager::cLoop::GetFrameInfo(cLoopManager::cLoop *this)
{
	return &this->m_FrameInfo;
}

//----- (0089E939) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::ChangeMode(cLoopManager::cLoop *this, int kind, sLoopInstantiator *loop)
{
	_GUID **v3; // eax@6
	int v4; // eax@7
	sModeData *v5; // eax@13
	unsigned int v6; // eax@15
	int v7; // edx@20
	IUnknownVtbl *v8; // edx@22
	unsigned int v9; // edx@23
	IUnknownVtbl *v10; // ecx@24
	IUnknownVtbl *v11; // ecx@24
	int v12; // ecx@26
	unsigned int v13; // eax@27
	sModeData *v14; // eax@28
	ILoopDispatch *v15; // [sp-18h] [bp-F8h]@13
	int v16; // [sp-14h] [bp-F4h]@13
	int v17; // [sp-10h] [bp-F0h]@13
	unsigned int v18; // [sp-Ch] [bp-ECh]@13
	int v19; // [sp-8h] [bp-E8h]@13
	void *v20; // [sp-4h] [bp-E4h]@13
	char v21; // [sp+8h] [bp-D8h]@28
	char v22; // [sp+24h] [bp-BCh]@24
	char v23; // [sp+3Ch] [bp-A4h]@20
	int v24; // [sp+54h] [bp-8Ch]@20
	int v25; // [sp+58h] [bp-88h]@20
	unsigned int v26; // [sp+5Ch] [bp-84h]@20
	int v27; // [sp+60h] [bp-80h]@20
	sModeData result; // [sp+64h] [bp-7Ch]@15
	char v29; // [sp+7Ch] [bp-64h]@13
	sModeData mode; // [sp+98h] [bp-48h]@20
	sLoopTransition trans; // [sp+B0h] [bp-30h]@20
	sLoopFrameInfo push_info; // [sp+C8h] [bp-18h]@13
	unsigned int next; // [sp+D8h] [bp-8h]@3
	ILoopDispatch *dispatch; // [sp+DCh] [bp-4h]@5

	if (!this->m_pCurrentDispatch)
		_CriticalMsg("Changing modes outside GO", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0x267u);
	next = ((int(__stdcall *)(ILoopManager *, _GUID *))this->m_pLoopManager->baseclass_0.vfptr[3].QueryInterface)(
		this->m_pLoopManager,
		loop->pID);
	if (!next)
		_CriticalMsg("Change to unknown loopmode", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0x26Au);
	dispatch = 0;
	if (this->m_fState & 0x20
		&& (v3 = (_GUID **)((int(__stdcall *)(ILoopDispatch *, _DWORD))this->m_pNextDispatch->baseclass_0.vfptr[2].Release)(
		this->m_pNextDispatch,
		0),
		operator__(loop->pID, *v3)))
	{
		v4 = 1;
	}
	else
	{
		if (kind || (this->m_fState & 0xA0) != 160)
		{
			if (this->m_fState & 0x20)
			{
				if (kind)
				{
					if (this->m_fState & 0x40)
					{
						cLoopModeStack::Pop(this->m_pLoopStack, &result);
						v6 = this->m_fState;
						LOBYTE(v6) = v6 & 0xBF;
						this->m_fState = v6;
					}
					if (this->m_pNextDispatch)
						this->m_pNextDispatch->baseclass_0.vfptr->Release((IUnknown *)this->m_pNextDispatch);
					this->m_pNextDispatch = 0;
				}
				else
				{
					push_info.fMinorMode = this->m_FrameInfo.fMinorMode;
					push_info.nCount = this->m_FrameInfo.nCount;
					push_info.nTicks = this->m_FrameInfo.nTicks;
					push_info.dTicks = this->m_FrameInfo.dTicks;
					push_info.fMinorMode = this->m_fNewMinorMode;
					v20 = 0;
					v16 = push_info.fMinorMode;
					v17 = push_info.nCount;
					v18 = push_info.nTicks;
					v19 = push_info.dTicks;
					sModeData::sModeData((sModeData *)&v29, this->m_pNextDispatch, *(sLoopFrameInfo *)&v16, 0);
					sModeData::sModeData((sModeData *)&v15, v5);
					cLoopModeStack::Push(this->m_pLoopStack, *(sModeData *)&v15);
					kind = 1;
				}
			}
			if (kind == 2)
			{
				v16 = v24;
				v17 = v25;
				v18 = v26;
				v19 = v27;
				sModeData::sModeData(&mode, 0, *(sLoopFrameInfo *)&v16, 0x80u);
				v7 = *(_DWORD *)next;
				v20 = (void *)next;
				trans.to.pID = *(_GUID **)(*(int(__stdcall **)(unsigned int))(v7 + 12))(next);
				trans.to.minorMode = 0;
				trans.to.init = 0;
				v20 = &v23;
				memcpy(&mode, cLoopModeStack::Pop(this->m_pLoopStack, (sModeData *)&v23), sizeof(mode));
				while ((_DWORD)mode.dispatch)
				{
					v20 = &trans.from.init;
					v8 = mode.dispatch->baseclass_0.vfptr;
					v19 = (signed int)mode.dispatch;
					trans.from.pID = *(_GUID **)((int(__stdcall *)(ILoopDispatch *, sLoopModeInitParm **))v8[2].Release)(
						mode.dispatch,
						&trans.from.init);
					if (operator__(trans.from.pID, trans.to.pID))
					{
						dispatch = mode.dispatch;
						this->m_fNewMinorMode = mode.frame.fMinorMode;
						v9 = this->m_fState;
						LOBYTE(v9) = v9 | 0x80;
						this->m_fState = v9;
						break;
					}
					trans.from.minorMode = mode.frame.fMinorMode;
					v20 = (void *)2;
					v19 = (int)&trans;
					v18 = 32768;
					v10 = mode.dispatch->baseclass_0.vfptr;
					v17 = (signed int)mode.dispatch;
					((void(__stdcall *)(ILoopDispatch *, signed int, sLoopTransition *, signed int))v10[1].QueryInterface)(
						mode.dispatch,
						32768,
						&trans,
						2);
					v11 = mode.dispatch->baseclass_0.vfptr;
					v20 = mode.dispatch;
					v11->Release((IUnknown *)mode.dispatch);
					v20 = &v22;
					memcpy(&mode, cLoopModeStack::Pop(this->m_pLoopStack, (sModeData *)&v22), sizeof(mode));
				}
			}
			if (!dispatch)
			{
				v20 = &dispatch;
				v19 = (int)loop->init;
				v12 = *(_DWORD *)next;
				v18 = next;
				(*(void(__stdcall **)(unsigned int, int, ILoopDispatch **))(v12 + 16))(next, v19, &dispatch);
				this->m_fNewMinorMode = loop->minorMode;
			}
			this->m_pNextDispatch = dispatch;
			v13 = this->m_fState;
			LOBYTE(v13) = v13 | 0x38;
			this->m_fState = v13;
			if (!kind)
			{
				v20 = (void *)128;
				v16 = this->m_FrameInfo.fMinorMode;
				v17 = this->m_FrameInfo.nCount;
				v18 = this->m_FrameInfo.nTicks;
				v19 = this->m_FrameInfo.dTicks;
				v15 = this->m_pCurrentDispatch;
				sModeData::sModeData((sModeData *)&v21, v15, *(sLoopFrameInfo *)&v16, 0x80u);
				sModeData::sModeData((sModeData *)&v15, v14);
				cLoopModeStack::Push(this->m_pLoopStack, *(sModeData *)&v15);
				this->m_fState |= 0x40u;
			}
			v4 = 0;
		}
		else
		{
			v4 = -2147467259;
		}
	}
	return v4;
}

//----- (0089ECAE) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::EndMode(cLoopManager::cLoop *this, int goRetVal)
{
	sModeData *v2; // eax@3
	sModeData result; // [sp+0h] [bp-30h]@3
	sModeData next; // [sp+18h] [bp-18h]@3

	if (!this->m_pCurrentDispatch)
		_CriticalMsg("No loop mode to end!", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0x2CFu);
	this->m_fGoReturn = goRetVal;
	v2 = cLoopModeStack::Pop(this->m_pLoopStack, &result);
	sModeData::sModeData(&next, v2);
	if ((_DWORD)next.dispatch)
	{
		this->m_pNextDispatch = next.dispatch;
		this->m_fNewMinorMode = next.frame.fMinorMode;
		this->m_fState |= 0x30u;
		this->m_fState |= next.flags;
	}
	else
	{
		this->m_fState &= 0xFFFFFFFEu;
		this->m_fState |= 0x20u;
		this->m_pNextDispatch = 0;
	}
	return 0;
}

//----- (0089ED62) --------------------------------------------------------
void __stdcall cLoopManager::cLoop::Pause(cLoopManager::cLoop *this, int fPause)
{
	unsigned int v2; // eax@3
	unsigned int v3; // eax@6
	unsigned int fPaused; // [sp+0h] [bp-4h]@1

	fPaused = this->m_fState & 2;
	if (!fPause || fPaused)
	{
		if (!fPause)
		{
			if (fPaused)
			{
				v3 = this->m_fState;
				LOBYTE(v3) = v3 | 8;
				this->m_fState = v3;
			}
		}
	}
	else
	{
		v2 = this->m_fState;
		LOBYTE(v2) = v2 | 4;
		this->m_fState = v2;
	}
}

//----- (0089EDAE) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::IsPaused(cLoopManager::cLoop *this)
{
	return (this->m_fState & 2) != 0;
}

//----- (0089EDC4) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::ChangeMinorMode(cLoopManager::cLoop *this, int minorMode)
{
	int result; // eax@2

	if (minorMode == this->m_FrameInfo.fMinorMode)
	{
		result = 1;
	}
	else
	{
		this->m_fNewMinorMode = minorMode;
		this->m_fState |= 0x10u;
		result = 0;
	}
	return result;
}

//----- (0089EDF7) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::GetMinorMode(cLoopManager::cLoop *this)
{
	return this->m_FrameInfo.fMinorMode;
}

//----- (0089EE04) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::SendMessage(cLoopManager::cLoop *this, int message, tLoopMessageData__ *hData, int flags)
{
	int result; // eax@3

	if (!this->m_pCurrentDispatch
		|| ((int(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->m_pCurrentDispatch->baseclass_0.vfptr[1].QueryInterface)(
		this->m_pCurrentDispatch,
		message,
		hData,
		flags))
	{
		if (!this->m_pCurrentDispatch)
			_CriticalMsg("Cannot dispatch messages: no loop mode", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0x31Au);
		result = -2147467259;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (0089EE64) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::SendSimpleMessage(cLoopManager::cLoop *this, int message)
{
	int result; // eax@3

	if (!this->m_pCurrentDispatch
		|| ((int(__stdcall *)(_DWORD, _DWORD))this->m_pCurrentDispatch->baseclass_0.vfptr[1].AddRef)(
		this->m_pCurrentDispatch,
		message))
	{
		if (!this->m_pCurrentDispatch)
			_CriticalMsg("Cannot dispatch messages: no loop mode", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0x323u);
		result = -2147467259;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (0089EEBC) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::PostMessage(cLoopManager::cLoop *this, int message, tLoopMessageData__ *hData, int flags)
{
	int result; // eax@3

	if (!this->m_pCurrentDispatch
		|| ((int(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->m_pCurrentDispatch->baseclass_0.vfptr[1].Release)(
		this->m_pCurrentDispatch,
		message,
		hData,
		flags))
	{
		if (!this->m_pCurrentDispatch)
			_CriticalMsg("Cannot dispatch messages: no loop mode", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0x32Cu);
		result = -2147467259;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (0089EF1C) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::PostSimpleMessage(cLoopManager::cLoop *this, int message)
{
	int result; // eax@3

	if (!this->m_pCurrentDispatch
		|| ((int(__stdcall *)(_DWORD, _DWORD))this->m_pCurrentDispatch->baseclass_0.vfptr[2].QueryInterface)(
		this->m_pCurrentDispatch,
		message))
	{
		if (!this->m_pCurrentDispatch)
			_CriticalMsg("Cannot dispatch messages: no loop mode", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0x335u);
		result = -2147467259;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (0089EF74) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::ProcessQueue(cLoopManager::cLoop *this)
{
	int result; // eax@3

	if (!this->m_pCurrentDispatch
		|| this->m_pCurrentDispatch->baseclass_0.vfptr[2].AddRef((IUnknown *)this->m_pCurrentDispatch))
	{
		if (!this->m_pCurrentDispatch)
			_CriticalMsg("Cannot dispatch messages: no loop mode", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0x33Eu);
		result = -2147467259;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (0089EFC8) --------------------------------------------------------
void __stdcall cLoopManager::cLoop::SetDiagnostics(cLoopManager::cLoop *this, unsigned int fDiagnostics, unsigned int messages)
{
	if (this->m_pCurrentDispatch)
	{
		this->m_pCurrentDispatch->baseclass_0.vfptr[3].QueryInterface(
			(IUnknown *)this->m_pCurrentDispatch,
			(_GUID *)fDiagnostics,
			(void **)messages);
	}
	else
	{
		this->m_fTempDiagnostics = fDiagnostics;
		this->m_tempDiagnosticSet = messages;
	}
}

//----- (0089F006) --------------------------------------------------------
void __stdcall cLoopManager::cLoop::GetDiagnostics(cLoopManager::cLoop *this, unsigned int *pfDiagnostics, unsigned int *pMessages)
{
	if (this->m_pCurrentDispatch)
	{
		((void(__stdcall *)(_DWORD, _DWORD, _DWORD))this->m_pCurrentDispatch->baseclass_0.vfptr[3].AddRef)(
			this->m_pCurrentDispatch,
			pfDiagnostics,
			pMessages);
	}
	else
	{
		*pfDiagnostics = this->m_fTempDiagnostics;
		*pMessages = this->m_tempDiagnosticSet;
	}
}

//----- (0089F048) --------------------------------------------------------
void __stdcall cLoopManager::cLoop::SetProfile(cLoopManager::cLoop *this, unsigned int messages, _GUID *pClientId)
{
	if (this->m_pCurrentDispatch)
	{
		((void(__stdcall *)(_DWORD, _DWORD, _DWORD))this->m_pCurrentDispatch->baseclass_0.vfptr[3].Release)(
			this->m_pCurrentDispatch,
			messages,
			pClientId);
	}
	else
	{
		this->m_TempProfileSet = messages;
		this->m_pTempProfileClientId = pClientId;
	}
}

//----- (0089F086) --------------------------------------------------------
void __stdcall cLoopManager::cLoop::GetProfile(cLoopManager::cLoop *this, unsigned int *pMessages, _GUID **ppClientId)
{
	if (this->m_pCurrentDispatch)
	{
		this->m_pCurrentDispatch->baseclass_0.vfptr[4].QueryInterface(
			(IUnknown *)this->m_pCurrentDispatch,
			(_GUID *)pMessages,
			(void **)ppClientId);
	}
	else
	{
		*pMessages = this->m_TempProfileSet;
		*ppClientId = this->m_pTempProfileClientId;
	}
}

//----- (0089F0C8) --------------------------------------------------------
int __cdecl cLoopManager::cLoop::OnExit()
{
	int result; // eax@2

	if (cLoopManager::cLoop::gm_pLoop)
	{
		result = cLoopManager::cLoop::gm_pLoop;
		if (*(_DWORD *)(cLoopManager::cLoop::gm_pLoop + 8))
		{
			result = (*(int(__stdcall **)(_DWORD))(**(_DWORD **)(cLoopManager::cLoop::gm_pLoop + 8) + 8))(*(_DWORD *)(cLoopManager::cLoop::gm_pLoop + 8));
			*(_DWORD *)(cLoopManager::cLoop::gm_pLoop + 8) = 0;
		}
	}
	return result;
}
// EA66C8: using guessed type int cLoopManager__cLoop__gm_pLoop;

//----- (0089F110) --------------------------------------------------------
IUnknown *__thiscall cLoopManager::cOuterPointer::operator_ > (cLoopManager::cOuterPointer *this)
{
	return this->m_pOuterUnknown;
}

//----- (0089F120) --------------------------------------------------------
int __thiscall cLoopManager::Connect(cLoopManager *this)
{
	return 0;
}

//----- (0089F130) --------------------------------------------------------
int __thiscall cLoopManager::PostConnect(cLoopManager *this)
{
	return 0;
}

//----- (0089F140) --------------------------------------------------------
int __thiscall cLoopManager::Init(cLoopManager *this)
{
	return 0;
}

//----- (0089F150) --------------------------------------------------------
int __thiscall cLoopManager::Disconnect(cLoopManager *this)
{
	return 0;
}

//----- (0089F160) --------------------------------------------------------
unsigned int __thiscall cLoopManager::cComplexAggregateControl::cRefCount::AddRef(cLoopManager::cComplexAggregateControl::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (0089F180) --------------------------------------------------------
unsigned int __thiscall cLoopManager::cComplexAggregateControl::cRefCount::Release(cLoopManager::cComplexAggregateControl::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (0089F1A0) --------------------------------------------------------
unsigned int __thiscall cLoopManager::cComplexAggregateControl::cRefCount::operator unsigned_long(cLoopManager::cComplexAggregateControl::cRefCount *this)
{
	return this->ul;
}

//----- (0089F1B0) --------------------------------------------------------
void __thiscall cLoopManager::cComplexAggregateControl::OnFinalRelease(cLoopManager::cComplexAggregateControl *this)
{
	if (this->m_pAggregateMember)
		cLoopManager::OnFinalRelease(this->m_pAggregateMember);
}

//----- (0089F1D0) --------------------------------------------------------
void __thiscall cLoopManager::OnFinalRelease(cLoopManager *this)
{
	if (this)
		((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[4].AddRef)(this, 1);
}

//----- (0089F210) --------------------------------------------------------
void __thiscall cLoopManager::cOuterPointer::cOuterPointer(cLoopManager::cOuterPointer *this)
{
	this->m_pOuterUnknown = 0;
}

//----- (0089F230) --------------------------------------------------------
void __thiscall cLoopManager::cOuterPointer::Init(cLoopManager::cOuterPointer *this, IUnknown *p)
{
	this->m_pOuterUnknown = p;
}

//----- (0089F250) --------------------------------------------------------
void __thiscall cLoopManager::cComplexAggregateControl::cComplexAggregateControl(cLoopManager::cComplexAggregateControl *this)
{
	cLoopManager::cComplexAggregateControl *v1; // ST00_4@1

	v1 = this;
	IAggregateMemberControl::IAggregateMemberControl(&this->baseclass_0);
	cLoopManager::cComplexAggregateControl::cRefCount::cRefCount(&v1->__m_ulRefs);
	v1->m_pAggregateMember = 0;
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cLoopManager::cComplexAggregateControl::_vftable_;
}
// 9A6A2C: using guessed type int (__stdcall *cLoopManager__cComplexAggregateControl___vftable_)(int this, int id, int ppI);

//----- (0089F290) --------------------------------------------------------
void __thiscall cLoopManager::cComplexAggregateControl::cRefCount::cRefCount(cLoopManager::cComplexAggregateControl::cRefCount *this)
{
	this->ul = 1;
}

//----- (0089F2B0) --------------------------------------------------------
void __thiscall cLoopManager::cComplexAggregateControl::InitControl(cLoopManager::cComplexAggregateControl *this, cLoopManager *p)
{
	this->m_pAggregateMember = p;
}

//----- (0089F2D0) --------------------------------------------------------
void __thiscall cLoopManager::cLoop::cLoop(cLoopManager::cLoop *this, IUnknown *pOuterUnknown, cLoopManager *pLoopManager)
{
	cLoopModeStack *v3; // eax@2
	cLoopModeStack *v4; // [sp+0h] [bp-Ch]@2
	cLoopManager::cLoop *thisa; // [sp+4h] [bp-8h]@1
	void *v6; // [sp+8h] [bp-4h]@1

	thisa = this;
	ILoop::ILoop(&this->baseclass_0);
	cLoopManager::cLoop::cOuterPointer::cOuterPointer(&thisa->__m_pOuterUnknown);
	thisa->m_pCurrentDispatch = 0;
	thisa->m_fState = 0;
	thisa->m_fGoReturn = 0;
	thisa->m_pLoopManager = (ILoopManager *)pLoopManager;
	v6 = j__new(8u, "x:\\prj\\tech\\libsrc\\darkloop\\loopman.h", 167);
	if (v6)
	{
		cLoopModeStack::cLoopModeStack((cLoopModeStack *)v6);
		v4 = v3;
	}
	else
	{
		v4 = 0;
	}
	thisa->m_pLoopStack = v4;
	thisa->m_pNextDispatch = 0;
	thisa->m_fTempDiagnostics = 0;
	thisa->m_tempDiagnosticSet = 0;
	thisa->m_TempProfileSet = 0;
	thisa->m_pTempProfileClientId = 0;
	thisa->baseclass_0.lpVtbl = (ILoopVtbl *)&cLoopManager::cLoop::_vftable_;
	cLoopManager::cLoop::cOuterPointer::Init(&thisa->__m_pOuterUnknown, pOuterUnknown);
	thisa->m_FrameInfo.nCount = 0;
	thisa->m_FrameInfo.fMinorMode = 0;
	cLoopManager::cLoop::gm_pLoop = (int)thisa;
}
// 9A6A4C: using guessed type int (__stdcall *cLoopManager__cLoop___vftable_)(int this, int id, int ppI);
// EA66C8: using guessed type int cLoopManager__cLoop__gm_pLoop;

//----- (0089F3C0) --------------------------------------------------------
void __thiscall cLoopModeStack::cLoopModeStack(cLoopModeStack *this)
{
	cDList<cLoopModeElem_1>::cDList<cLoopModeElem_1>(&this->baseclass_0);
}

//----- (0089F3E0) --------------------------------------------------------
void __thiscall cDList<cLoopModeElem_1>::cDList<cLoopModeElem_1>(cDList<cLoopModeElem, 1> *this)
{
	cDListBase::cDListBase(&this->baseclass_0);
}

//----- (0089F400) --------------------------------------------------------
void __thiscall cLoopManager::cLoop::cOuterPointer::cOuterPointer(cLoopManager::cLoop::cOuterPointer *this)
{
	this->m_pOuterUnknown = 0;
}

//----- (0089F420) --------------------------------------------------------
void __thiscall cLoopManager::cLoop::cOuterPointer::Init(cLoopManager::cLoop::cOuterPointer *this, IUnknown *p)
{
	this->m_pOuterUnknown = p;
}

//----- (0089F440) --------------------------------------------------------
void *__thiscall cLoopManager::cLoop::_scalar_deleting_destructor_(cLoopManager::cLoop *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cLoopManager::cLoop::_cLoop(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (0089F470) --------------------------------------------------------
void __thiscall ILoop::ILoop(ILoop *this)
{
	ILoop *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown((IUnknown *)this);
	v1->lpVtbl = (ILoopVtbl *)ILoop::_vftable_;
}
// 9A6AB0: using guessed type int (*ILoop___vftable_[37])();

//----- (0089F490) --------------------------------------------------------
void *__thiscall cLoopManager::_vector_deleting_destructor_(cLoopManager *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cLoopManager::_cLoopManager(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (0089F4C0) --------------------------------------------------------
void __thiscall ILoopManager::ILoopManager(ILoopManager *this)
{
	ILoopManager *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)ILoopManager::_vftable_;
}
// 9A6B10: using guessed type int (*ILoopManager___vftable_[13])();

//----- (0089F4E0) --------------------------------------------------------
IUnknown *__thiscall cLoopManager::cLoop::cOuterPointer::operator_ > (cLoopManager::cLoop::cOuterPointer *this)
{
	return this->m_pOuterUnknown;
}



*/