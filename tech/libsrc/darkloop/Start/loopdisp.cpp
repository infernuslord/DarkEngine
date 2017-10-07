//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include <aggmemb.h>

#include <dynarray.h>
#include <hashset.h>

#include <looptype.h>
#include <loopapi.h>

#include "loopdisp.h"



cLoopDispatch::cLoopDispatch(ILoopMode *loop, sLoopModeInitParm *parmList, unsigned int msgs)
{


}

cLoopDispatch::~cLoopDispatch()
{
}




/*

//----- (0089FB3C) --------------------------------------------------------
void __thiscall cLoopDispatch::cLoopDispatch(cLoopDispatch *this, ILoopMode *loop, sLoopModeInitParm *parmList, unsigned int msgs)
{
unsigned int v4; // eax@1
IUnknown *v5; // eax@1
ILoopManager *v6; // ST14_4@2
IUnknown *v7; // ST10_4@5
cLoopDispatch *thisa; // [sp+8h] [bp-10Ch]@1
ILoopMode *pBaseMode; // [sp+Ch] [bp-108h]@2
ConstraintTable constraints; // [sp+10h] [bp-104h]@1
cAutoIPtr<ILoopManager> pLoopManager; // [sp+110h] [bp-4h]@1

thisa = this;
ILoopDispatch::ILoopDispatch(&this->baseclass_0);
cLoopDispatch::cRefCount::cRefCount(&thisa->__m_ulRefs);
v4 = msgs;
LOBYTE(v4) = msgs | 3;
thisa->m_msgs = v4;
cLoopQueue::cLoopQueue(&thisa->m_Queue);

_vector_constructor_iterator_(
thisa->m_DispatchLists,
8u,
32,
(void(__thiscall *)(void *))cPriIntArray<ILoopClient>::cPriIntArray<ILoopClient>);
thisa->m_pLoopMode = loop;
cClientInfoList::cClientInfoList(&thisa->m_aClientInfo);
thisa->m_fDiagnostics = 0;
thisa->m_diagnosticSet = 0;
thisa->m_ProfileSet = 0;
thisa->m_pProfileClientId = 0;
cAverageTimer::cAverageTimer(&thisa->m_AverageFrameTimer);
cSimpleTimer::cSimpleTimer(&thisa->m_TotalModeTime);
cLoopDispatch::cInitParmTable::cInitParmTable(&thisa->m_Parms, parmList);
thisa->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cLoopDispatch::_vftable_;
ConstraintTable::ConstraintTable(&constraints);
cLoopDispatch::AddClientsFromMode(thisa, loop, &constraints);
v5 = _AppGetAggregated(&IID_ILoopManager);
cAutoIPtr<ILoopManager>::cAutoIPtr<ILoopManager>(&pLoopManager, (ILoopManager *)v5);
if (cIPtr<ILoopManager>::operator__(&pLoopManager.baseclass_0, 0))
{
v6 = cIPtr<ILoopManager>::operator_ > (&pLoopManager.baseclass_0);
pBaseMode = (ILoopMode *)((int(__stdcall *)(ILoopManager *))v6->baseclass_0.vfptr[4].QueryInterface)(v6);
cLoopDispatch::AddClientsFromMode(thisa, pBaseMode, &constraints);
if (pBaseMode)
pBaseMode->baseclass_0.vfptr->Release((IUnknown *)pBaseMode);
}
cLoopDispatch::SortClients(thisa, &constraints);
if (cIPtrBase::operator IUnknown__(&pLoopManager.baseclass_0.baseclass_0))
{
v7 = cIPtrBase::operator IUnknown__(&pLoopManager.baseclass_0.baseclass_0);
v7->vfptr->Release(v7);
}
cAutoIPtr<ILoopManager>::operator_(&pLoopManager, 0);
cLoopDispatch::SendSimpleMessage(thisa, 1);
cAutoIPtr<ILoopManager>::_cAutoIPtr<ILoopManager>(&pLoopManager);
ConstraintTable::_ConstraintTable(&constraints);
}
// 9A6B80: using guessed type int (__stdcall *cLoopDispatch___vftable_)(int this, int id, int ppI);




//----- (0089FA90) --------------------------------------------------------
int __stdcall cLoopDispatch::QueryInterface(cLoopDispatch *this, _GUID *id, void **ppI)
{
	int result; // eax@5

	if (id != &IID_ILoopDispatch
		&& id != &IID_IUnknown
		&& memcmp(id, &IID_ILoopDispatch, 0x10u)
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

//----- (0089FAFD) --------------------------------------------------------
unsigned int __stdcall cLoopDispatch::AddRef(cLoopDispatch *this)
{
	return cLoopDispatch::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (0089FB0F) --------------------------------------------------------
unsigned int __stdcall cLoopDispatch::Release(cLoopDispatch *this)
{
	unsigned int result; // eax@2

	if (cLoopDispatch::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cLoopDispatch::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cLoopDispatch::OnFinalRelease(this);
		result = 0;
	}
	return result;
}


//----- (0089FD5B) --------------------------------------------------------
void __thiscall cLoopDispatch::SortClients(cLoopDispatch *this, ConstraintTable *constraints)
{
	cDynArray<sAbsoluteConstraint> *v2; // eax@3
	unsigned int v3; // ST04_4@3
	cDynArray<sAbsoluteConstraint> *v4; // eax@3
	sAbsoluteConstraint *v5; // ST00_4@3
	cLoopDispatch *thisa; // [sp+0h] [bp-8h]@1
	int i; // [sp+4h] [bp-4h]@1

	thisa = this;
	for (i = 0; i < 32; ++i)
	{
		v2 = ConstraintTable::operator__(constraints, i);
		v3 = cDABase<sAbsoluteConstraint_4_cDARawSrvFns<sAbsoluteConstraint>>::Size((cDABase<sAbsoluteConstraint, 4, cDARawSrvFns<sAbsoluteConstraint>> *)v2);
		v4 = ConstraintTable::operator__(constraints, i);
		v5 = cDABase<sAbsoluteConstraint_4_cDARawSrvFns<sAbsoluteConstraint>>::AsPointer((cDABase<sAbsoluteConstraint, 4, cDARawSrvFns<sAbsoluteConstraint>> *)v4);
		cPriGuidSetBase::Sort(&thisa->m_DispatchLists[i].baseclass_0.baseclass_0, v5, v3);
	}
}

//----- (0089FDBE) --------------------------------------------------------
void __thiscall cLoopDispatch::AddClientsFromMode(cLoopDispatch *this, ILoopMode *pLoop, ConstraintTable *constraints)
{
	IUnknown *v3; // eax@2
	int v4; // eax@9
	_GUID **v5; // eax@10
	_GUID *v6; // ST04_4@17
	ILoopManager *v7; // eax@17
	_GUID *v8; // ST0C_4@18
	ILoopManager *v9; // ST10_4@18
	sClientInfo *v10; // eax@25
	tLoopClientData__ *v11; // [sp+8h] [bp-C8h]@15
	cLoopDispatch *thisa; // [sp+Ch] [bp-C4h]@1
	char v13; // [sp+10h] [bp-C0h]@25
	int msg; // [sp+8Ch] [bp-44h]@26
	int i; // [sp+90h] [bp-40h]@26
	ILoopMode *mode; // [sp+94h] [bp-3Ch]@18
	sLoopModeInitParm *pInitParms; // [sp+98h] [bp-38h]@14
	sClientInfo *info; // [sp+9Ch] [bp-34h]@25
	char next_client; // [sp+A0h] [bp-30h]@8
	int pClientDesc; // [sp+A4h] [bp-2Ch]@25
	_GUID *pID; // [sp+A8h] [bp-28h]@7
	ILoopClient *pClient; // [sp+ACh] [bp-24h]@14
	int infoidx; // [sp+B0h] [bp-20h]@25
	int idx; // [sp+B4h] [bp-1Ch]@8
	char *ppLimit; // [sp+B8h] [bp-18h]@4
	cAutoIPtr<ILoopManager> pLoopManager; // [sp+BCh] [bp-14h]@2
	int fFirstWarning; // [sp+C0h] [bp-10h]@4
	cLoopDispatch::cInitParmTable *initParmTable; // [sp+C4h] [bp-Ch]@4
	int desc; // [sp+C8h] [bp-8h]@4
	char *ppIDs; // [sp+CCh] [bp-4h]@4

	thisa = this;
	if (pLoop)
	{
		v3 = _AppGetAggregated(&IID_ILoopManager);
		cAutoIPtr<ILoopManager>::cAutoIPtr<ILoopManager>(&pLoopManager, (ILoopManager *)v3);
		if (cIPtrBase::operator_(&pLoopManager.baseclass_0.baseclass_0))
			_CriticalMsg(
			"Failed to locate ILoopManager implementation",
			"x:\\prj\\tech\\libsrc\\darkloop\\loopdisp.cpp",
			0xB3u);
		fFirstWarning = 1;
		desc = ((int(__stdcall *)(ILoopMode *))pLoop->baseclass_0.vfptr[2].QueryInterface)(pLoop);
		ppIDs = *(char **)(desc + 36);
		ppLimit = &ppIDs[4 * *(_DWORD *)(desc + 40)];
		initParmTable = &thisa->m_Parms;
		while (ppIDs < ppLimit)
		{
			pID = *(_GUID **)ppIDs;
			if (!operator__(pID, &GUID_NULL))
			{
				next_client = 0;
				for (idx = 0;; ++idx)
				{
					v4 = cClientInfoList::Size(&thisa->m_aClientInfo);
					if (idx >= v4)
						break;
					v5 = (_GUID **)cClientInfoList::operator__(&thisa->m_aClientInfo, idx);
					if (operator__(pID, *v5))
					{
						next_client = 1;
						break;
					}
				}
				if (!next_client)
				{
					pInitParms = cLoopDispatch::cInitParmTable::Search(initParmTable, pID);
					pClient = 0;
					if (pInitParms)
						v11 = pInitParms->data;
					else
						v11 = 0;
					v6 = pID;
					v7 = cIPtr<ILoopManager>::operator_ > (&pLoopManager.baseclass_0);
					((void(__stdcall *)(ILoopManager *, _GUID *, tLoopClientData__ *, ILoopClient **))v7->baseclass_0.vfptr[2].AddRef)(
						v7,
						v6,
						v11,
						&pClient);
					if (pClient)
					{
						pClientDesc = pClient->baseclass_0.vfptr[1].AddRef((IUnknown *)pClient);
						sClientInfo::sClientInfo((sClientInfo *)&v13);
						infoidx = cClientInfoList::Append(&thisa->m_aClientInfo, v10);
						sClientInfo::_sClientInfo((sClientInfo *)&v13);
						info = cClientInfoList::operator__(&thisa->m_aClientInfo, infoidx);
						cTimerBase::SetName(&info->timer.baseclass_0, (const char *)(pClientDesc + 4));
						info->priIntInfo.baseclass_0.pID = pID;
						info->priIntInfo.pInterface = pClient;
						info->priIntInfo.baseclass_0.priority = *(_DWORD *)(pClientDesc + 44);
						cAnsiStr::operator_(&info->priIntInfo.nameStr, (const char *)(pClientDesc + 4));
						info->priIntInfo.pData = cClientInfoList::operator__(&thisa->m_aClientInfo, infoidx);
						info->interests = *(_DWORD *)(pClientDesc + 48);
						if (thisa->m_msgs & info->interests)
						{
							msg = 1;
							i = 0;
							while (msg)
							{
								if (thisa->m_msgs & msg & info->interests)
									cPriGuidSet<sPriIntInfo<ILoopClient>>::Append(
									&thisa->m_DispatchLists[i].baseclass_0,
									&info->priIntInfo);
								++i;
								msg *= 2;
							}
						}
						TableAddClientConstraints(constraints, (sLoopClientDesc *)pClientDesc);
					}
					else
					{
						v8 = pID;
						v9 = cIPtr<ILoopManager>::operator_ > (&pLoopManager.baseclass_0);
						mode = (ILoopMode *)((int(__stdcall *)(ILoopManager *, _GUID *))v9->baseclass_0.vfptr[3].QueryInterface)(
							v9,
							v8);
						if (mode)
						{
							cLoopDispatch::AddClientsFromMode(thisa, mode, constraints);
							if (mode)
								mode->baseclass_0.vfptr->Release((IUnknown *)mode);
							mode = 0;
						}
						else
						{
							if (fFirstWarning)
							{
								DbgReportWarning("Loop mode \"%s\" did not find all expected clients\n");
								fFirstWarning = 0;
							}
						}
					}
				}
			}
			ppIDs += 4;
		}
		cAutoIPtr<ILoopManager>::_cAutoIPtr<ILoopManager>(&pLoopManager);
	}
}

//----- (008A0121) --------------------------------------------------------
void __cdecl TableAddClientConstraints(ConstraintTable *table, sLoopClientDesc *desc)
{
	cDynArray<sAbsoluteConstraint> *v2; // eax@10
	sAbsoluteConstraint absoluteConstraint; // [sp+0h] [bp-14h]@7
	int i; // [sp+8h] [bp-Ch]@7
	int currentMessage; // [sp+Ch] [bp-8h]@7
	sLoopClientDesc *pRel; // [sp+10h] [bp-4h]@1

	for (pRel = desc + 1; pRel->pID; pRel = (sLoopClientDesc *)((char *)pRel + 12))
	{
		if (pRel->pID != (_GUID *)1 && pRel->pID != (_GUID *)2)
			_CriticalMsg("Bad constraint", "x:\\prj\\tech\\libsrc\\darkloop\\loopdisp.cpp", 0x93u);
		MakeAbsolute((sRelativeConstraint *)pRel, desc->pID, &absoluteConstraint);
		currentMessage = 1;
		i = 0;
		while (currentMessage)
		{
			if (currentMessage & *(_DWORD *)&pRel->szName[4])
			{
				v2 = ConstraintTable::operator__(table, i);
				cDABase<sAbsoluteConstraint_4_cDARawSrvFns<sAbsoluteConstraint>>::Append(
					(cDABase<sAbsoluteConstraint, 4, cDARawSrvFns<sAbsoluteConstraint>> *)v2,
					&absoluteConstraint);
			}
			++i;
			currentMessage *= 2;
		}
	}
}

//----- (008A01DD) --------------------------------------------------------
void __thiscall cLoopDispatch::_cLoopDispatch(cLoopDispatch *this)
{
	sClientInfo *v1; // eax@4
	cLoopDispatch *thisa; // [sp+4h] [bp-8h]@1
	int i; // [sp+8h] [bp-4h]@1

	thisa = this;
	this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cLoopDispatch::_vftable_;
	cLoopDispatch::SendMessage(this, 2, 0, 2);
	for (i = 0; i < cClientInfoList::Size(&thisa->m_aClientInfo); ++i)
	{
		if (cClientInfoList::operator__(&thisa->m_aClientInfo, i)->priIntInfo.pInterface)
		{
			v1 = cClientInfoList::operator__(&thisa->m_aClientInfo, i);
			v1->priIntInfo.pInterface->baseclass_0.vfptr->Release((IUnknown *)v1->priIntInfo.pInterface);
		}
		cClientInfoList::operator__(&thisa->m_aClientInfo, i)->priIntInfo.pInterface = 0;
	}
	cLoopDispatch::cInitParmTable::_cInitParmTable(&thisa->m_Parms);
	cSimpleTimer::_cSimpleTimer(&thisa->m_TotalModeTime);
	cAverageTimer::_cAverageTimer(&thisa->m_AverageFrameTimer);
	cClientInfoList::_cClientInfoList(&thisa->m_aClientInfo);
	_vector_destructor_iterator_(
		thisa->m_DispatchLists,
		8u,
		32,
		(void(__thiscall *)(void *))cPriIntArray<ILoopClient>::_cPriIntArray<ILoopClient>);
}
// 9A6B80: using guessed type int (__stdcall *cLoopDispatch___vftable_)(int this, int id, int ppI);

//----- (008A02CE) --------------------------------------------------------
int __cdecl LoopProfileSend(ILoopClient *pClient, int message, tLoopMessageData__ *hData)
{
	return ((int(__stdcall *)(_DWORD, _DWORD, _DWORD))pClient->baseclass_0.vfptr[1].Release)(pClient, message, hData);
}

//----- (008A02E7) --------------------------------------------------------
void __stdcall cLoopDispatch::ClearTimers(cLoopDispatch *this)
{
	sClientInfo *v1; // eax@3
	int i; // [sp+0h] [bp-4h]@1

	cSimpleTimer::Clear(&this->m_TotalModeTime);
	cAverageTimer::Clear(&this->m_AverageFrameTimer);
	for (i = 0; i < cClientInfoList::Size(&this->m_aClientInfo); ++i)
	{
		v1 = cClientInfoList::operator__(&this->m_aClientInfo, i);
		cAverageTimer::Clear(&v1->timer);
	}
}

//----- (008A0350) --------------------------------------------------------
void __stdcall cLoopDispatch::DumpTimerInfo(cLoopDispatch *this)
{
	int v1; // eax@3
	sClientInfo *v2; // eax@4
	double v3; // ST64_8@6
	double v4; // ST3C_8@6
	double v5; // ST34_8@6
	double v6; // ST54_8@6
	double v7; // ST2C_8@6
	double v8; // ST1C_8@6
	double v9; // ST14_8@6
	int v10; // ST0C_4@6
	const char *v11; // eax@8
	int v12; // eax@10
	unsigned int v13; // eax@13
	cAverageTimer **v14; // eax@14
	cAverageTimer **v15; // eax@15
	cAverageTimer **v16; // eax@15
	cTimerBase **v17; // eax@15
	const char *v18; // eax@15
	const char *v19; // eax@18
	int v20; // eax@22
	sClientInfo *v21; // eax@23
	cAverageTimer *item; // [sp+58h] [bp-40h]@11
	long double clientAvg; // [sp+5Ch] [bp-3Ch]@14
	long double sumAvg; // [sp+64h] [bp-34h]@12
	cDynArray<cAverageTimer *> timers; // [sp+6Ch] [bp-2Ch]@9
	long double clientPctOfFrame; // [sp+74h] [bp-24h]@14
	long double frameAvg; // [sp+7Ch] [bp-1Ch]@12
	cAnsiStr msg; // [sp+84h] [bp-14h]@1
	int i; // [sp+90h] [bp-8h]@2
	int was_active; // [sp+94h] [bp-4h]@1

	cAnsiStr::cAnsiStr(&msg);
	was_active = cTimerBase::IsActive(&this->m_AverageFrameTimer.baseclass_0);
	if (was_active)
	{
		cAverageTimer::Stop(&this->m_AverageFrameTimer);
		for (i = 0;; ++i)
		{
			v1 = cClientInfoList::Size(&this->m_aClientInfo);
			if (i >= v1)
				break;
			v2 = cClientInfoList::operator__(&this->m_aClientInfo, i);
			cAverageTimer::Stop(&v2->timer);
		}
	}
	if (cAverageTimer::GetIters(&this->m_AverageFrameTimer) < 0xA)
	{
		cAnsiStr::FmtStr(
			&msg,
			"+----------------------------------------------------------------------------+\n[ Insufficient samples to calculate frame timings ]\n");
	}
	else
	{
		v3 = cSimpleTimer::GetResult(&this->m_TotalModeTime) - 2500.0;
		v4 = 1000.0 / (v3 / (double)cAverageTimer::GetIters(&this->m_AverageFrameTimer));
		v5 = 1000.0 / cAverageTimer::GetResult(&this->m_AverageFrameTimer);
		v6 = cSimpleTimer::GetResult(&this->m_TotalModeTime) - 2500.0;
		v7 = v6 - (double)cAverageTimer::GetTotalTime(&this->m_AverageFrameTimer);
		cAverageTimer::GetResult(&this->m_AverageFrameTimer);
		v8 = cSimpleTimer::GetResult(&this->m_TotalModeTime) - 2500.0;
		v9 = (double)cAverageTimer::GetTotalTime(&this->m_AverageFrameTimer);
		cAverageTimer::GetIters(&this->m_AverageFrameTimer);
		v10 = ((int(__stdcall *)(ILoopMode *))this->m_pLoopMode->baseclass_0.vfptr[1].QueryInterface)(this->m_pLoopMode)
			+ 4;
		cAnsiStr::FmtStr(
			&msg,
			0x500u,
			"+----------------------------------------------------------------------------+\n|                       FRAME TIMINGS: %-16s                      |\n+----------------------------------------------------------------------------+\n\nFrames sampled:     %12d frames\n \nIn-loop time:       %12.0f ms    Total mode time:    %12.0f ms\nIn-loop frame avg:  %12.2f ms    Total out-of-loop:  %12.0f ms\nIn-loop framerate:  %12.2f fps   Mode framerate:     %12.2f fps\n \n");
	}
	v11 = cAnsiStr::operator char_const__(&msg);
	mprint(v11);
	if (cAverageTimer::GetIters(&this->m_AverageFrameTimer) >= 0xA)
	{
		mprintf(" Loop Client                Average Time     %% of Frame  Max Time  Min Time\n ----------------------------------------------------------------------------\n");
		cDynArray<cAverageTimer__>::cDynArray<cAverageTimer__>(&timers);
		for (i = 0;; ++i)
		{
			v12 = cClientInfoList::Size(&this->m_aClientInfo);
			if (i >= v12)
				break;
			item = &cClientInfoList::operator__(&this->m_aClientInfo, i)->timer;
			cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::Append(&timers.baseclass_0.baseclass_0, &item);
			cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::Sort(&timers.baseclass_0.baseclass_0, TimerSortFunc);
		}
		frameAvg = cAverageTimer::GetResult(&this->m_AverageFrameTimer);
		sumAvg = 0.0;
		for (i = 0;; ++i)
		{
			v13 = cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::Size(&timers.baseclass_0.baseclass_0);
			if (i >= v13)
				break;
			v14 = cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::operator__(&timers.baseclass_0.baseclass_0, i);
			clientAvg = cAverageTimer::GetResult(*v14);
			clientPctOfFrame = clientAvg / frameAvg * 100.0;
			if (clientAvg > 1.0)
			{
				sumAvg = sumAvg + clientAvg;
				v15 = cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::operator__(&timers.baseclass_0.baseclass_0, i);
				cAverageTimer::GetMinTime(*v15);
				v16 = cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::operator__(&timers.baseclass_0.baseclass_0, i);
				cAverageTimer::GetMaxTime(*v16);
				v17 = (cTimerBase **)cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::operator__(
					&timers.baseclass_0.baseclass_0,
					i);
				cTimerBase::GetName(*v17);
				cAnsiStr::FmtStr(&msg, " %-25s %#12.4f %#12.2f%% %#10lu %#10lu\n");
				v18 = cAnsiStr::operator char_const__(&msg);
				mprint(v18);
			}
		}
		clientAvg = frameAvg - sumAvg;
		if (clientAvg > 0.0)
		{
			cAnsiStr::FmtStr(&msg, " %-25s %#12.4f %#12.2f%%\n");
			v19 = cAnsiStr::operator char_const__(&msg);
			mprint(v19);
		}
		cDynArray<cAverageTimer__>::_cDynArray<cAverageTimer__>(&timers);
	}
	mprintf("+----------------------------------------------------------------------------+\n");
	if (was_active)
	{
		cAverageTimer::Start(&this->m_AverageFrameTimer);
		for (i = 0;; ++i)
		{
			v20 = cClientInfoList::Size(&this->m_aClientInfo);
			if (i >= v20)
				break;
			v21 = cClientInfoList::operator__(&this->m_aClientInfo, i);
			cAverageTimer::Start(&v21->timer);
		}
	}
	cAnsiStr::_cAnsiStr(&msg);
}

//----- (008A076F) --------------------------------------------------------
int __cdecl TimerSortFunc(cAverageTimer *const *pLeft, cAverageTimer *const *pRight)
{
	double v2; // ST00_8@1
	int v3; // eax@2
	double result; // [sp+8h] [bp-8h]@1

	v2 = cAverageTimer::GetResult(*pRight);
	result = v2 - cAverageTimer::GetResult(*pLeft);
	if (result <= 0.0)
	{
		if (result >= 0.0)
			v3 = 0;
		else
			v3 = -1;
	}
	else
	{
		v3 = 1;
	}
	return v3;
}

//----- (008A07C4) --------------------------------------------------------
int __stdcall cLoopDispatch::SendMessage(cLoopDispatch *this, int message, tLoopMessageData__ *hData, int flags)
{
	sPriIntInfo<ILoopClient> **v4; // eax@26
	sClientInfo *v5; // eax@51
	sClientInfo *v6; // eax@56
	int v7; // eax@60
	int v8; // [sp+0h] [bp-50h]@24
	int v9; // [sp+4h] [bp-4Ch]@15
	int v10; // [sp+8h] [bp-48h]@10
	int v11; // [sp+Ch] [bp-44h]@4
	const char *pszClient; // [sp+10h] [bp-40h]@26
	int clientResult; // [sp+14h] [bp-3Ch]@31
	unsigned int fFrameHeapchk; // [sp+1Ch] [bp-34h]@6
	unsigned int fLoopTime; // [sp+20h] [bp-30h]@6
	unsigned int fClientHeapchk; // [sp+24h] [bp-2Ch]@6
	int fPassedSkipTime; // [sp+28h] [bp-28h]@0
	unsigned int iLast; // [sp+2Ch] [bp-24h]@21
	int i; // [sp+30h] [bp-20h]@21
	int ia; // [sp+30h] [bp-20h]@49
	int ib; // [sp+30h] [bp-20h]@54
	cAverageTimer *pTimer; // [sp+38h] [bp-18h]@0
	ILoopClient *pClient; // [sp+3Ch] [bp-14h]@26
	int fLoopTimeThisMsg; // [sp+44h] [bp-Ch]@17
	int result; // [sp+48h] [bp-8h]@2
	cPriGuidSetBase *targetList; // [sp+4Ch] [bp-4h]@21

	if (this->m_msgs & message)
	{
		result = 0;
		v11 = this->m_fDiagnostics & 1 && message & this->m_diagnosticSet;
		fLoopTime = this->m_fDiagnostics & 2;
		fFrameHeapchk = this->m_fDiagnostics & 8;
		fClientHeapchk = this->m_fDiagnostics & 0x10;
		if (message & 0x4001)
			cSimpleTimer::Start(&this->m_TotalModeTime);
		if (cTimerBase::IsActive(&this->m_TotalModeTime.baseclass_0))
		{
			cSimpleTimer::Stop(&this->m_TotalModeTime);
			v10 = cSimpleTimer::GetResult(&this->m_TotalModeTime) > 2500.0;
			fPassedSkipTime = v10;
			cSimpleTimer::Start(&this->m_TotalModeTime);
			v9 = v10 && fLoopTime && message & 0x3C0;
			fLoopTimeThisMsg = v9;
		}
		else
		{
			fLoopTimeThisMsg = 0;
		}
		if (fLoopTimeThisMsg)
			cAverageTimer::Start(&this->m_AverageFrameTimer);
		targetList = (cPriGuidSetBase *)&this->m_DispatchLists[MessageToIndex(message)];
		iLast = cPriGuidSetBase::Size(targetList) - 1;
		for (i = 0; i <= (signed int)iLast; ++i)
		{
			if (flags & 1)
				v8 = i;
			else
				v8 = iLast - i;
			pClient = (*cPriGuidSet<sPriIntInfo<ILoopClient>>::operator__(
				(cPriGuidSet<sPriIntInfo<ILoopClient> > *)targetList,
				v8))->pInterface;
			v4 = cPriGuidSet<sPriIntInfo<ILoopClient>>::operator__((cPriGuidSet<sPriIntInfo<ILoopClient> > *)targetList, v8);
			pszClient = cAnsiStr::operator char_const__(&(*v4)->nameStr);
			if (v11)
				LoopTrack(message, pszClient);
			if (fLoopTimeThisMsg)
			{
				pTimer = (cAverageTimer *)((char *)(*cPriGuidSet<sPriIntInfo<ILoopClient>>::operator__(
					(cPriGuidSet<sPriIntInfo<ILoopClient> > *)targetList,
					v8))->pData
					+ 32);
				cAverageTimer::Start(pTimer);
			}
			if (this->m_ProfileSet & message)
				clientResult = LoopProfileSend(pClient, message, hData);
			else
				clientResult = ((int(__stdcall *)(ILoopClient *, int, tLoopMessageData__ *))pClient->baseclass_0.vfptr[1].Release)(
				pClient,
				message,
				hData);
			if (fLoopTimeThisMsg)
				cAverageTimer::Stop(pTimer);
			if (fClientHeapchk)
				j___heapchk();
			if (clientResult == 1)
			{
				result = -2147467259;
				break;
			}
		}
		if (fFrameHeapchk)
			j___heapchk();
		if (message & 0x2002)
			cSimpleTimer::Stop(&this->m_TotalModeTime);
		if (fLoopTime)
		{
			if (fLoopTimeThisMsg)
				cAverageTimer::Stop(&this->m_AverageFrameTimer);
			if (fPassedSkipTime && message & 0x200)
			{
				cAverageTimer::Mark(&this->m_AverageFrameTimer);
				for (ia = 0; ia < cClientInfoList::Size(&this->m_aClientInfo); ++ia)
				{
					v5 = cClientInfoList::operator__(&this->m_aClientInfo, ia);
					cAverageTimer::Mark(&v5->timer);
				}
			}
			if (message & 0x2002)
			{
				if (cTimerBase::IsActive(&this->m_AverageFrameTimer.baseclass_0))
				{
					cAverageTimer::Stop(&this->m_AverageFrameTimer);
					for (ib = 0; ib < cClientInfoList::Size(&this->m_aClientInfo); ++ib)
					{
						v6 = cClientInfoList::operator__(&this->m_aClientInfo, ib);
						cAverageTimer::Stop(&v6->timer);
					}
				}
				this->baseclass_0.baseclass_0.vfptr[4].Release((IUnknown *)this);
				this->baseclass_0.baseclass_0.vfptr[4].AddRef((IUnknown *)this);
			}
		}
		if (v11)
			LoopTrackClear();
		v7 = result;
	}
	else
	{
		if (message && !(this->m_msgs & message))
			DbgReportWarning("Message 0x%02X not supported by this dispatch chain\n");
		v7 = 1;
	}
	return v7;
}

//----- (008A0BBE) --------------------------------------------------------
int __cdecl MessageToIndex(unsigned int message)
{
	int i; // [sp+0h] [bp-8h]@1
	signed int currentMessage; // [sp+4h] [bp-4h]@1

	currentMessage = 1;
	i = 0;
	while (currentMessage && !(message & currentMessage))
	{
		++i;
		currentMessage *= 2;
	}
	return i;
}

//----- (008A0C00) --------------------------------------------------------
void __cdecl LoopTrack(unsigned int message, const char *pszClient)
{
	int y; // [sp+0h] [bp-8h]@3
	int x; // [sp+4h] [bp-4h]@3

	if (!fSplitMono)
	{
		mono_split(1, 2);
		mono_setwin(2);
		fSplitMono = 1;
	}
	mono_getxy(&x, &y);
	mono_setwin(1);
	mono_setxy(0, 0);
	LoopGetMessageName(message);
	mprintf("%20s");
	mono_setxy(21, 0);
	mprintf("--> %-20s          ");
	mono_setwin(2);
	mono_setxy(x, y);
}

//----- (008A0CA7) --------------------------------------------------------
char __cdecl LoopTrackClear()
{
	mono_setwin(1);
	mono_clear();
	return mono_setwin(2);
}

//----- (008A0CC5) --------------------------------------------------------
int __stdcall cLoopDispatch::SendSimpleMessage(cLoopDispatch *this, int message)
{
	return ((int(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[1].QueryInterface)(
		this,
		message,
		0,
		1);
}

//----- (008A0CE0) --------------------------------------------------------
int __stdcall cLoopDispatch::PostMessage(cLoopDispatch *this, int message, tLoopMessageData__ *hData, int flags)
{
	sLoopQueueMessage queueMessage; // [sp+0h] [bp-10h]@1

	queueMessage.message = message;
	queueMessage.hData = hData;
	queueMessage.flags = flags;
	cLoopQueue::Append(&this->m_Queue, &queueMessage);
	return 0;
}

//----- (008A0D0F) --------------------------------------------------------
int __stdcall cLoopDispatch::PostSimpleMessage(cLoopDispatch *this, int message)
{
	sLoopQueueMessage queueMessage; // [sp+0h] [bp-10h]@1

	queueMessage.message = message;
	queueMessage.hData = 0;
	queueMessage.flags = 0;
	cLoopQueue::Append(&this->m_Queue, &queueMessage);
	return 0;
}

//----- (008A0D40) --------------------------------------------------------
int __stdcall cLoopDispatch::ProcessQueue(cLoopDispatch *this)
{
	int retVal; // [sp+0h] [bp-14h]@1
	sLoopQueueMessage queueMessage; // [sp+4h] [bp-10h]@2

	retVal = 1;
	do
	{
		if (!cLoopQueue::GetMessage(&this->m_Queue, &queueMessage))
			break;
		retVal = ((int(__stdcall *)(cLoopDispatch *, int, tLoopMessageData__ *, int))this->baseclass_0.baseclass_0.vfptr[1].QueryInterface)(
			this,
			queueMessage.message,
			queueMessage.hData,
			queueMessage.flags);
	} while (!retVal);
	return retVal;
}

//----- (008A0D8E) --------------------------------------------------------
sLoopModeName *__stdcall cLoopDispatch::Describe(cLoopDispatch *this, sLoopModeInitParm **list)
{
	int v2; // ecx@0
	sLoopModeName *name; // [sp+0h] [bp-4h]@1

	name = (sLoopModeName *)((int(__stdcall *)(ILoopMode *, int))this->m_pLoopMode->baseclass_0.vfptr[1].QueryInterface)(
		this->m_pLoopMode,
		v2);
	if (list)
		*list = cLoopDispatch::cInitParmTable::List(&this->m_Parms);
	return name;
}

//----- (008A0DCF) --------------------------------------------------------
void __stdcall cLoopDispatch::SetDiagnostics(cLoopDispatch *this, unsigned int fDiagnostics, unsigned int messages)
{
	this->m_fDiagnostics = fDiagnostics;
	this->m_diagnosticSet = messages;
}

//----- (008A0DEE) --------------------------------------------------------
void __stdcall cLoopDispatch::GetDiagnostics(cLoopDispatch *this, unsigned int *pfDiagnostics, unsigned int *pMessages)
{
	*pfDiagnostics = this->m_fDiagnostics;
	*pMessages = this->m_diagnosticSet;
}

//----- (008A0E11) --------------------------------------------------------
void __stdcall cLoopDispatch::SetProfile(cLoopDispatch *this, unsigned int messages, _GUID *pClientId)
{
	this->m_ProfileSet = messages;
	this->m_pProfileClientId = pClientId;
}

//----- (008A0E30) --------------------------------------------------------
void __stdcall cLoopDispatch::GetProfile(cLoopDispatch *this, unsigned int *pMessages, _GUID **ppClientId)
{
	*pMessages = this->m_ProfileSet;
	*ppClientId = this->m_pProfileClientId;
}

//----- (008A0E53) --------------------------------------------------------
int __thiscall cLoopDispatch::DispatchNormalFrame(cLoopDispatch *this, ILoopClient *pClient, tLoopMessageData__ *hData)
{
	return ((int(__stdcall *)(_DWORD, _DWORD, _DWORD))pClient->baseclass_0.vfptr[1].Release)(pClient, 128, hData) != 1;
}

//----- (008A0E80) --------------------------------------------------------
unsigned int __thiscall cLoopDispatch::cRefCount::AddRef(cLoopDispatch::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008A0EA0) --------------------------------------------------------
unsigned int __thiscall cLoopDispatch::cRefCount::Release(cLoopDispatch::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008A0EC0) --------------------------------------------------------
unsigned int __thiscall cLoopDispatch::cRefCount::operator unsigned_long(cLoopDispatch::cRefCount *this)
{
	return this->ul;
}

//----- (008A0ED0) --------------------------------------------------------
void __thiscall cLoopDispatch::OnFinalRelease(cLoopDispatch *this)
{
	if (this)
		((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[5].QueryInterface)(this, 1);
}


//----- (008A0FE0) --------------------------------------------------------
void __thiscall cLoopDispatch::cRefCount::cRefCount(cLoopDispatch::cRefCount *this)
{
	this->ul = 1;
}

//----- (008A1000) --------------------------------------------------------
void __thiscall cLoopDispatch::cInitParmTable::cInitParmTable(cLoopDispatch::cInitParmTable *this, sLoopModeInitParm *list)
{
	this->m_list = cLoopDispatch::cInitParmTable::copy_parm(this, list);
}

//----- (008A1030) --------------------------------------------------------
sLoopModeInitParm *__thiscall cLoopDispatch::cInitParmTable::copy_parm(cLoopDispatch::cInitParmTable *this, sLoopModeInitParm *list)
{
	sLoopModeInitParm *result; // eax@2
	void *v3; // ST18_4@6
	int n; // [sp+8h] [bp-8h]@3

	if (list)
	{
		for (n = 0; list[n].pID; ++n)
			;
		v3 = operator new(8 * n + 8);
		memcpy(v3, list, 8 * n + 8);
		result = (sLoopModeInitParm *)v3;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008A10B0) --------------------------------------------------------
void *__thiscall cLoopDispatch::_scalar_deleting_destructor_(cLoopDispatch *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cLoopDispatch::_cLoopDispatch(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008A10E0) --------------------------------------------------------
void __thiscall ILoopDispatch::ILoopDispatch(ILoopDispatch *this)
{
	ILoopDispatch *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)ILoopDispatch::_vftable_;
}
// 9A6BC0: using guessed type int (*ILoopDispatch___vftable_[15])();



//----- (008A1460) --------------------------------------------------------
sLoopModeInitParm *__thiscall cLoopDispatch::cInitParmTable::Search(cLoopDispatch::cInitParmTable *this, _GUID *pID)
{
	sLoopModeInitParm *result; // eax@2
	_GUID **p; // [sp+4h] [bp-4h]@1

	p = (_GUID **)this->m_list;
	if (this->m_list)
	{
		while (*p && operator__(*p, pID))
			p += 2;
		if (*p)
			result = (sLoopModeInitParm *)p;
		else
			result = 0;
	}
	else
	{
		result = 0;
	}
	return result;
}


//----- (008A1A30) --------------------------------------------------------
sLoopModeInitParm *__thiscall cLoopDispatch::cInitParmTable::List(cLoopDispatch::cInitParmTable *this)
{
	return this->m_list;
}


*/