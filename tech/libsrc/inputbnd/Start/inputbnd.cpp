//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include "inpbnd_i.h"






/*

//----- (008D51E0) --------------------------------------------------------
void __thiscall cInputBinder::SetGlobObjs(cInputBinder *this)
{
	g_IB_variable_manager = this->m_IB_variable_manager;
	g_IB_input_mapper = this->m_IB_input_mappers[this->m_cur_context_idx];
}

//----- (008D520D) --------------------------------------------------------
int __stdcall _CreateInputBinder(_GUID *__formal, IInputBinder **ppInputBinder, IUnknown *pOuter)
{
	IInputBinder *v3; // eax@2
	int result; // eax@5
	IInputBinder *v5; // [sp+0h] [bp-8h]@2
	void *this; // [sp+4h] [bp-4h]@1

	this = j__new(0xA0u, "x:\\prj\\tech\\libsrc\\inputbnd\\inputbnd.cpp", 517);
	if (this)
	{
		cInputBinder::cInputBinder((cInputBinder *)this, pOuter);
		v5 = v3;
	}
	else
	{
		v5 = 0;
	}
	*ppInputBinder = v5;
	if (ppInputBinder)
		result = 0;
	else
		result = -2147467259;
	return result;
}

//----- (008D5270) --------------------------------------------------------
void __thiscall cInputBinder::cInputBinder(cInputBinder *this, IUnknown *pOuter)
{
	IUnknown *v2; // [sp+0h] [bp-24h]@3
	cInputBinder *thisa; // [sp+4h] [bp-20h]@1
	sAggAddInfo aAggAddInfo; // [sp+Ch] [bp-18h]@2

	thisa = this;
	cCTDelegating<IInputBinder>::cCTDelegating<IInputBinder>(&this->baseclass_0);
	cCTAggregateMemberControl<0>::cCTAggregateMemberControl<0>(&thisa->baseclass_8);
	cDynArray<_sBindContext>::cDynArray<_sBindContext>(&thisa->m_BndCtxtArray);
	thisa->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cInputBinder::_vftable_;
	thisa->baseclass_8.baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cInputBinder::_vftable_;
	cCTDelegating<IInputBinder>::InitDelegation(&thisa->baseclass_0, pOuter);
	if (pOuter)
	{
		aAggAddInfo.pID = &IID_IInputBinder;
		aAggAddInfo.pszName = "IID_IInputBinder";
		aAggAddInfo.pAggregated = (IUnknown *)thisa;
		if (thisa)
			v2 = (IUnknown *)&thisa->baseclass_8;
		else
			v2 = 0;
		aAggAddInfo.pControl = v2;
		aAggAddInfo.controlPriority = 16384;
		aAggAddInfo.pControlConstraints = 0;
		_AddToAggregate(pOuter, &aAggAddInfo, 1u);
	}
	cCTAggregateMemberControl<0>::AggregateMemberControlRelease(&thisa->baseclass_8);
}
// 9A7918: using guessed type int (__stdcall *cInputBinder___vftable_)(int, int, int);
// 9A7940: using guessed type int (__stdcall *cInputBinder___vftable_)(int this, int id, int ppI);

//----- (008D5370) --------------------------------------------------------
char *__stdcall cInputBinder::Init(cInputBinder *this, _IB_var *p_vars, char *p_bnd_filename)
{
	cIBVariableManager *v3; // eax@2
	cIBInputMapper *v4; // eax@5
	cIBInputMapper *v6; // [sp+0h] [bp-10h]@5
	cIBVariableManager *v7; // [sp+4h] [bp-Ch]@2
	void *v8; // [sp+8h] [bp-8h]@4
	void *v9; // [sp+Ch] [bp-4h]@1

	v9 = j__new(0x9Cu, "x:\\prj\\tech\\libsrc\\inputbnd\\inputbnd.cpp", 44);
	if (v9)
	{
		cIBVariableManager::cIBVariableManager((cIBVariableManager *)v9);
		v7 = v3;
	}
	else
	{
		v7 = 0;
	}
	this->m_IB_variable_manager = v7;
	memset(this->m_IB_input_mappers, 0, 0x80u);
	v8 = j__new(0xB5u, "x:\\prj\\tech\\libsrc\\inputbnd\\inputbnd.cpp", 46);
	if (v8)
	{
		cIBInputMapper::cIBInputMapper((cIBInputMapper *)v8);
		v6 = v4;
	}
	else
	{
		v6 = 0;
	}
	this->m_IB_input_mappers[0] = v6;
	this->m_IB_input_mappers[0]->m_context = 1;
	this->m_cur_context_idx = 0;
	if (p_vars)
		((void(__stdcall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.vfptr[7].QueryInterface)(
		this,
		p_vars);
	if (p_bnd_filename)
		((void(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.vfptr[6].AddRef)(
		this,
		p_bnd_filename,
		0,
		0);
	return 0;
}

//----- (008D5460) --------------------------------------------------------
char *__stdcall cInputBinder::Term(cInputBinder *this)
{
	cIBVariableManager *v2; // [sp+Ch] [bp-10h]@7
	cIBInputMapper *v3; // [sp+14h] [bp-8h]@4
	signed int i; // [sp+18h] [bp-4h]@1

	for (i = 0; i < 32; ++i)
	{
		if (this->m_IB_input_mappers[i])
		{
			v3 = this->m_IB_input_mappers[i];
			if (v3)
				cIBInputMapper::_scalar_deleting_destructor_(v3, 1u);
		}
	}
	v2 = this->m_IB_variable_manager;
	if (v2)
		cIBVariableManager::_scalar_deleting_destructor_(v2, 1u);
	cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>::SetSize(&this->m_BndCtxtArray.baseclass_0.baseclass_0, 0);
	return 0;
}

//----- (008D5500) --------------------------------------------------------
void __stdcall cInputBinder::GetHandler(cInputBinder *this, char(__cdecl **ppHandler)(_ui_event *, _Region *, void *))
{
	cInputBinder::SetGlobObjs(this);
	*ppHandler = cIBInputMapper::InputBindingHandler;
}

//----- (008D5520) --------------------------------------------------------
void __stdcall cInputBinder::SetValidEvents(cInputBinder *this, unsigned int events)
{
	cInputBinder::SetGlobObjs(this);
	g_IB_input_mapper->m_valid_events = events;
}

//----- (008D5540) --------------------------------------------------------
unsigned int __stdcall cInputBinder::GetValidEvents(cInputBinder *this)
{
	cInputBinder::SetGlobObjs(this);
	return g_IB_input_mapper->m_valid_events;
}

//----- (008D5560) --------------------------------------------------------
int __stdcall cInputBinder::Bind(cInputBinder *this, char *pControl, char *pCmd)
{
	char pBuf[256]; // [sp+4h] [bp-100h]@1

	sprintf(pBuf, "bind %s %s", pControl, pCmd);
	return ((int(__stdcall *)(cInputBinder *, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.vfptr[4].QueryInterface)(
		this,
		pBuf) == 0;
}

//----- (008D55B0) --------------------------------------------------------
int __stdcall cInputBinder::Unbind(cInputBinder *this, char *pControl)
{
	char pBuf[256]; // [sp+4h] [bp-100h]@1

	sprintf(pBuf, "unbind %s", pControl);
	return ((int(__stdcall *)(cInputBinder *, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.vfptr[4].QueryInterface)(
		this,
		pBuf) == 0;
}

//----- (008D5600) --------------------------------------------------------
void __stdcall cInputBinder::QueryBind(cInputBinder *this, char *pControl, char *pCmdBuf, int iBufLen)
{
	const char *v4; // ST0C_4@1
	char pBuf[256]; // [sp+4h] [bp-100h]@1

	sprintf(pBuf, "bind %s", pControl);
	v4 = (const char *)((int(__stdcall *)(cInputBinder *, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.vfptr[4].QueryInterface)(
		this,
		pBuf);
	strncpy(pCmdBuf, v4, iBufLen);
}

//----- (008D5660) --------------------------------------------------------
void __stdcall cInputBinder::GetVarValue(cInputBinder *this, char *pVarStr, char *pValBuf, int iBufLen)
{
	const char *v4; // ST0C_4@1
	char pBuf[256]; // [sp+4h] [bp-100h]@1

	sprintf(pBuf, "echo $%s", pVarStr);
	v4 = (const char *)((int(__stdcall *)(cInputBinder *, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.vfptr[4].QueryInterface)(
		this,
		pBuf);
	strncpy(pValBuf, v4, iBufLen);
}

//----- (008D56C0) --------------------------------------------------------
char *__stdcall cInputBinder::ProcessCmd(cInputBinder *this, char *p_cmd)
{
	cInputBinder::SetGlobObjs(this);
	return cIBVariableManager::Cmd(this->m_IB_variable_manager, p_cmd, 0);
}

//----- (008D56E0) --------------------------------------------------------
void __stdcall cInputBinder::TrapBind(cInputBinder *this, char *p_cmd, int(__cdecl *filter_cb)(char *, char *, void *), void(__cdecl *post_cb)(int), void *data)
{
	cInputBinder::SetGlobObjs(this);
	cIBInputMapper::TrapBind(g_IB_input_mapper, p_cmd, filter_cb, post_cb, data);
}

//----- (008D5710) --------------------------------------------------------
char *__stdcall cInputBinder::Update(cInputBinder *this)
{
	cInputBinder::SetGlobObjs(this);
	return 0;
}

//----- (008D5730) --------------------------------------------------------
void __stdcall cInputBinder::PollAllKeys(cInputBinder *this)
{
	cInputBinder::SetGlobObjs(this);
	cIBInputMapper::PollAllKeys(g_IB_input_mapper);
}

//----- (008D5750) --------------------------------------------------------
void __stdcall cInputBinder::RegisterJoyProcObj(cInputBinder *this, void *joyproc)
{
	cInputBinder::SetGlobObjs(this);
	g_IB_input_mapper->m_joyproc = (cIBJoyAxisProcess *)joyproc;
}

//----- (008D5770) --------------------------------------------------------
void __stdcall cInputBinder::LoadBndContexted(cInputBinder *this, char *pBndFname)
{
	unsigned int v2; // ST08_4@1
	_sBindContext *v3; // eax@1

	v2 = cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>::Size(&this->m_BndCtxtArray.baseclass_0.baseclass_0);
	v3 = cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>::operator _sBindContext__(&this->m_BndCtxtArray.baseclass_0.baseclass_0);
	cIBVariableManager::LoadBndContexted(this->m_IB_variable_manager, pBndFname, v3, v2, this->m_IB_input_mappers);
	cInputBinder::SetGlobObjs(this);
}

//----- (008D57C0) --------------------------------------------------------
void __stdcall cInputBinder::ContextAssociate(cInputBinder *this, _sBindContext *pBindContext)
{
	int i; // [sp+4h] [bp-28h]@1
	_sBindContext ctxtNull; // [sp+8h] [bp-24h]@1

	ctxtNull.aszStr[0] = byte_B5ADD0;
	memset(&ctxtNull.aszStr[1], 0, 0x1Cu);
	*(_WORD *)&ctxtNull.aszStr[29] = 0;
	ctxtNull.aszStr[31] = 0;
	ctxtNull.iContext = 0;
	cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>::SetSize(&this->m_BndCtxtArray.baseclass_0.baseclass_0, 0);
	for (i = 0; memcmp(&pBindContext[i], &ctxtNull, 0x24u); ++i)
		cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>::Append(
		&this->m_BndCtxtArray.baseclass_0.baseclass_0,
		&pBindContext[i]);
}

//----- (008D5850) --------------------------------------------------------
char *__stdcall cInputBinder::LoadBndFile(cInputBinder *this, char *p_bnd_filename, unsigned int context, char *prefix)
{
	char *result; // eax@8
	int bit; // [sp+0h] [bp-88h]@2
	signed int old_context; // [sp+4h] [bp-84h]@2
	char str[128]; // [sp+8h] [bp-80h]@1

	strcpy(str, "loadbnd ");
	strcat(str, p_bnd_filename);
	cInputBinder::SetGlobObjs(this);
	if (context)
	{
		old_context = 1 << this->m_cur_context_idx;
		bit = 0;
		while (context)
		{
			if (context & 1)
			{
				if (this->m_IB_input_mappers[bit])
				{
					((void(__stdcall *)(cInputBinder *, signed int, signed int))this->baseclass_0.baseclass_0.baseclass_0.vfptr[8].Release)(
						this,
						1 << bit,
						1);
					cIBVariableManager::LoadBnd(this->m_IB_variable_manager, p_bnd_filename, prefix);
				}
			}
			++bit;
			context >>= 1;
		}
		((void(__stdcall *)(cInputBinder *, signed int, signed int))this->baseclass_0.baseclass_0.baseclass_0.vfptr[8].Release)(
			this,
			old_context,
			1);
		result = 0;
	}
	else
	{
		result = cIBVariableManager::Cmd(this->m_IB_variable_manager, str, 0);
	}
	return result;
}

//----- (008D5950) --------------------------------------------------------
char *__stdcall cInputBinder::SaveBndFile(cInputBinder *this, char *p_bnd_filename, char *p_header)
{
	cInputBinder::SetGlobObjs(this);
	cIBInputMapper::SaveBnd(g_IB_input_mapper, p_bnd_filename, p_header);
	return 0;
}

//----- (008D5980) --------------------------------------------------------
int __stdcall cInputBinder::VarSet(cInputBinder *this, _IB_var *p_vars)
{
	cInputBinder::SetGlobObjs(this);
	return cIBVariableManager::VarSet(this->m_IB_variable_manager, p_vars, 0);
}

//----- (008D59A0) --------------------------------------------------------
int __stdcall cInputBinder::VarSetn(cInputBinder *this, _IB_var *p_vars, int num)
{
	cInputBinder::SetGlobObjs(this);
	return cIBVariableManager::VarSet(this->m_IB_variable_manager, p_vars, num, 1);
}

//----- (008D59D0) --------------------------------------------------------
char *__stdcall cInputBinder::VarUnset(cInputBinder *this, char **pp_var_names, int user)
{
	cInputBinder::SetGlobObjs(this);
	return cIBVariableManager::VarUnset(this->m_IB_variable_manager, pp_var_names, user);
}

//----- (008D5A00) --------------------------------------------------------
char *__stdcall cInputBinder::VarUnsetn(cInputBinder *this, char **pp_var_names, int num, int user)
{
	cInputBinder::SetGlobObjs(this);
	return cIBVariableManager::VarUnset(this->m_IB_variable_manager, pp_var_names, num, user);
}

//----- (008D5A30) --------------------------------------------------------
char *__stdcall cInputBinder::VarUnsetAll(cInputBinder *this)
{
	return cIBVariableManager::VarUnsetAll(this->m_IB_variable_manager);
}

//----- (008D5A50) --------------------------------------------------------
int __stdcall cInputBinder::SetContext(cInputBinder *this, unsigned int context, int poll)
{
	int result; // eax@2
	cIBInputMapper *v4; // eax@14
	cIBInputMapper *v5; // [sp+0h] [bp-Ch]@14
	void *v6; // [sp+4h] [bp-8h]@13
	unsigned int bit; // [sp+8h] [bp-4h]@6

	if (this->m_IB_input_mappers[this->m_cur_context_idx]->m_context == context)
	{
		result = 1;
	}
	else
	{
		if (context && (context & -context) == context)
		{
			bit = 0;
			while (!(context & 1))
			{
				++bit;
				context >>= 1;
			}
			this->m_cur_context_idx = bit;
			if (this->m_IB_input_mappers[this->m_cur_context_idx])
			{
				this->m_IB_input_mappers[this->m_cur_context_idx]->m_mod_states = 0;
				cInputBinder::SetGlobObjs(this);
				if (poll)
					((void(__stdcall *)(_DWORD))this->baseclass_0.baseclass_0.baseclass_0.vfptr[5].QueryInterface)(this);
				result = 1;
			}
			else
			{
				v6 = j__new(0xB5u, "x:\\prj\\tech\\libsrc\\inputbnd\\inputbnd.cpp", 379);
				if (v6)
				{
					cIBInputMapper::cIBInputMapper((cIBInputMapper *)v6);
					v5 = v4;
				}
				else
				{
					v5 = 0;
				}
				this->m_IB_input_mappers[this->m_cur_context_idx] = v5;
				this->m_IB_input_mappers[this->m_cur_context_idx]->m_context = 1 << bit;
				cInputBinder::SetGlobObjs(this);
				result = 1;
			}
		}
		else
		{
			result = 0;
		}
	}
	return result;
}

//----- (008D5B90) --------------------------------------------------------
void __stdcall cInputBinder::GetContext(cInputBinder *this, unsigned int *p_context)
{
	*p_context = this->m_IB_input_mappers[this->m_cur_context_idx]->m_context;
}

//----- (008D5BC0) --------------------------------------------------------
void __stdcall cInputBinder::SetMasterAggregation(cInputBinder *this, int(__cdecl *func)(_intrnl_var_channel **, int, char *))
{
	cInputBinder::SetGlobObjs(this);
	cIBVariableManager::SetMasterAggregation(this->m_IB_variable_manager, func);
}

//----- (008D5BE0) --------------------------------------------------------
void __stdcall cInputBinder::SetMasterProcessCallback(cInputBinder *this, char *(__cdecl *func)(char *, char *, int))
{
	cInputBinder::SetGlobObjs(this);
	cIBVariableManager::SetMasterProcessCallback(this->m_IB_variable_manager, func);
}

//----- (008D5C00) --------------------------------------------------------
char *__stdcall cInputBinder::GetControlFromCmdStart(cInputBinder *this, char *cmd, char *control_buf)
{
	cInputBinder::SetGlobObjs(this);
	return cIBInputMapper::GetControlFromCmdStart(this->m_IB_input_mappers[this->m_cur_context_idx], cmd, control_buf);
}

//----- (008D5C30) --------------------------------------------------------
char *__stdcall cInputBinder::GetControlFromCmdNext(cInputBinder *this, char *control_buf)
{
	cInputBinder::SetGlobObjs(this);
	return cIBInputMapper::GetControlFromCmdNext(this->m_IB_input_mappers[this->m_cur_context_idx], control_buf);
}

//----- (008D5C60) --------------------------------------------------------
void __stdcall cInputBinder::SetResPath(cInputBinder *this, char *p_path)
{
	cInputBinder::SetGlobObjs(this);
	cIBVariableManager::SetBndSearchPath(this->m_IB_variable_manager, p_path);
}

//----- (008D5C80) --------------------------------------------------------
char *__stdcall cInputBinder::DecomposeControl(cInputBinder *this, char *control_str, char(*controls)[32], int *num_controls)
{
	cInputBinder::SetGlobObjs(this);
	return cIBInputMapper::DecomposeControl(
		this->m_IB_input_mappers[this->m_cur_context_idx],
		control_str,
		controls,
		num_controls);
}

//----- (008D5CB0) --------------------------------------------------------
void __stdcall cInputBinder::Reset(cInputBinder *this)
{
	cIBInputMapper *v1; // eax@5
	cIBInputMapper *v2; // [sp+0h] [bp-14h]@5
	void *v3; // [sp+8h] [bp-Ch]@4
	cIBInputMapper *v4; // [sp+10h] [bp-4h]@2

	if (this->m_IB_input_mappers[this->m_cur_context_idx])
	{
		v4 = this->m_IB_input_mappers[this->m_cur_context_idx];
		if (v4)
			cIBInputMapper::_scalar_deleting_destructor_(v4, 1u);
		v3 = j__new(0xB5u, "x:\\prj\\tech\\libsrc\\inputbnd\\inputbnd.cpp", 481);
		if (v3)
		{
			cIBInputMapper::cIBInputMapper((cIBInputMapper *)v3);
			v2 = v1;
		}
		else
		{
			v2 = 0;
		}
		this->m_IB_input_mappers[this->m_cur_context_idx] = v2;
		this->m_IB_input_mappers[this->m_cur_context_idx]->m_context = 1 << this->m_cur_context_idx;
		cInputBinder::SetGlobObjs(this);
	}
}

//----- (008D5D80) --------------------------------------------------------
void *__thiscall cInputBinder::_scalar_deleting_destructor_(cInputBinder *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cInputBinder::_cInputBinder(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008D5DB0) --------------------------------------------------------
void *__thiscall cIBInputMapper::_scalar_deleting_destructor_(cIBInputMapper *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cIBInputMapper::_cIBInputMapper(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008D5DE0) --------------------------------------------------------
void *__thiscall cIBVariableManager::_scalar_deleting_destructor_(cIBVariableManager *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cIBVariableManager::_cIBVariableManager(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008D5E10) --------------------------------------------------------
void __thiscall cInputBinder::_cInputBinder(cInputBinder *this)
{
	cCTAggregateMemberControl<0> *v1; // [sp+0h] [bp-8h]@2
	cCTDelegating<IInputBinder> *thisa; // [sp+4h] [bp-4h]@1

	thisa = (cCTDelegating<IInputBinder> *)this;
	cDynArray<_sBindContext>::_cDynArray<_sBindContext>(&this->m_BndCtxtArray);
	if (thisa)
		v1 = (cCTAggregateMemberControl<0> *)&thisa[1];
	else
		v1 = 0;
	cCTAggregateMemberControl<0>::_cCTAggregateMemberControl<0>(v1);
	cCTDelegating<IInputBinder>::_cCTDelegating<IInputBinder>(thisa);
}

//----- (008D5E60) --------------------------------------------------------
void __thiscall cDynArray<_sBindContext>::_cDynArray<_sBindContext>(cDynArray<_sBindContext> *this)
{
	cDynArray_<_sBindContext_4>::_cDynArray_<_sBindContext_4>(&this->baseclass_0);
}

//----- (008D5E80) --------------------------------------------------------
void __thiscall cDynArray_<_sBindContext_4>::_cDynArray_<_sBindContext_4>(cDynArray_<_sBindContext, 4> *this)
{
	cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>::_cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>(&this->baseclass_0);
}

//----- (008D5EA0) --------------------------------------------------------
void __thiscall cCTDelegating<IInputBinder>::cCTDelegating<IInputBinder>(cCTDelegating<IInputBinder> *this)
{
	cCTDelegating<IInputBinder> *v1; // ST00_4@1

	v1 = this;
	IInputBinder::IInputBinder(&this->baseclass_0);
	v1->__m_pOuterUnknown = 0;
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTDelegating<IInputBinder>::_vftable_;
}
// 9A79D0: using guessed type int (__stdcall *cCTDelegating_IInputBinder____vftable_)(int this, int id, int ppI);

//----- (008D5ED0) --------------------------------------------------------
void __thiscall cCTDelegating<IInputBinder>::_cCTDelegating<IInputBinder>(cCTDelegating<IInputBinder> *this)
{
	this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTDelegating<IInputBinder>::_vftable_;
}
// 9A79D0: using guessed type int (__stdcall *cCTDelegating_IInputBinder____vftable_)(int this, int id, int ppI);

//----- (008D5EF0) --------------------------------------------------------
void __thiscall cCTDelegating<IInputBinder>::InitDelegation(cCTDelegating<IInputBinder> *this, IUnknown *pOuterUnknown)
{
	this->__m_pOuterUnknown = pOuterUnknown;
}

//----- (008D5F10) --------------------------------------------------------
int __stdcall cCTDelegating<IInputBinder>::QueryInterface(cCTDelegating<IInputBinder> *this, _GUID *id, void **ppI)
{
	return (**(int(__stdcall ***)(_DWORD, _DWORD, _DWORD))this->__m_pOuterUnknown)(this->__m_pOuterUnknown, id, ppI);
}

//----- (008D5F30) --------------------------------------------------------
unsigned int __stdcall cCTDelegating<IInputBinder>::AddRef(cCTDelegating<IInputBinder> *this)
{
	return this->__m_pOuterUnknown->vfptr->AddRef(this->__m_pOuterUnknown);
}

//----- (008D5F50) --------------------------------------------------------
unsigned int __stdcall cCTDelegating<IInputBinder>::Release(cCTDelegating<IInputBinder> *this)
{
	return this->__m_pOuterUnknown->vfptr->Release(this->__m_pOuterUnknown);
}

//----- (008D5F70) --------------------------------------------------------
void __thiscall cDynArray<_sBindContext>::cDynArray<_sBindContext>(cDynArray<_sBindContext> *this)
{
	cDynArray_<_sBindContext_4>::cDynArray_<_sBindContext_4>(&this->baseclass_0);
}

//----- (008D5F90) --------------------------------------------------------
_sBindContext *__thiscall cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>::operator _sBindContext__(cDABase<_sBindContext, 4, cDARawSrvFns<_sBindContext> > *this)
{
	return this->m_pItems;
}

//----- (008D5FA0) --------------------------------------------------------
void *__thiscall cCTDelegating<IInputBinder>::_vector_deleting_destructor_(cCTDelegating<IInputBinder> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cCTDelegating<IInputBinder>::_cCTDelegating<IInputBinder>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008D5FD0) --------------------------------------------------------
void __thiscall IInputBinder::IInputBinder(IInputBinder *this)
{
	IInputBinder *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)IInputBinder::_vftable_;
}
// 9A7A60: using guessed type int (*IInputBinder___vftable_[35])();

//----- (008D5FF0) --------------------------------------------------------
void __thiscall cDynArray_<_sBindContext_4>::cDynArray_<_sBindContext_4>(cDynArray_<_sBindContext, 4> *this)
{
	cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>::cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>(&this->baseclass_0);
}

//----- (008D6010) --------------------------------------------------------
void __thiscall cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>::cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>(cDABase<_sBindContext, 4, cDARawSrvFns<_sBindContext> > *this)
{
	this->m_pItems = 0;
	this->m_nItems = 0;
	cDABaseSrvFns::TrackCreate(0x24u);
}

//----- (008D6040) --------------------------------------------------------
void __thiscall cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>::_cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>(cDABase<_sBindContext, 4, cDARawSrvFns<_sBindContext> > *this)
{
	cDABase<_sBindContext, 4, cDARawSrvFns<_sBindContext> > *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cDABaseSrvFns::TrackDestroy();
	if (thisa->m_pItems)
	{
		cDARawSrvFns<_sBindContext>::PreSetSize(thisa->m_pItems, thisa->m_nItems, 0);
		cDABaseSrvFns::DoResize((void **)&thisa->m_pItems, 0x24u, 0);
	}
}

//----- (008D6080) --------------------------------------------------------
unsigned int __thiscall cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>::Append(cDABase<_sBindContext, 4, cDARawSrvFns<_sBindContext> > *this, _sBindContext *item)
{
	cDABase<_sBindContext, 4, cDARawSrvFns<_sBindContext> > *v2; // ST08_4@1
	unsigned int v3; // ST0C_4@1

	v2 = this;
	cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>::Resize(this, this->m_nItems + 1);
	v3 = v2->m_nItems++;
	cDARawSrvFns<_sBindContext>::ConstructItem(&v2->m_pItems[v3], item);
	return cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>::Size(v2) - 1;
}

//----- (008D60E0) --------------------------------------------------------
unsigned int __thiscall cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>::Size(cDABase<_sBindContext, 4, cDARawSrvFns<_sBindContext> > *this)
{
	return this->m_nItems;
}

//----- (008D6100) --------------------------------------------------------
int __thiscall cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>::SetSize(cDABase<_sBindContext, 4, cDARawSrvFns<_sBindContext> > *this, unsigned int newSize)
{
	int result; // eax@2
	cDABase<_sBindContext, 4, cDARawSrvFns<_sBindContext> > *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (this->m_nItems == newSize)
	{
		result = 0;
	}
	else
	{
		cDARawSrvFns<_sBindContext>::PreSetSize(this->m_pItems, this->m_nItems, newSize);
		cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>::Resize(thisa, newSize);
		cDARawSrvFns<_sBindContext>::PostSetSize(thisa->m_pItems, thisa->m_nItems, newSize);
		thisa->m_nItems = newSize;
		result = 1;
	}
	return result;
}

//----- (008D6170) --------------------------------------------------------
void __cdecl cDARawSrvFns<_sBindContext>::PreSetSize(_sBindContext *__formal, unsigned int a2, unsigned int a3)
{
	;
}

//----- (008D6180) --------------------------------------------------------
void __cdecl cDARawSrvFns<_sBindContext>::PostSetSize(_sBindContext *__formal, unsigned int a2, unsigned int a3)
{
	;
}

//----- (008D6190) --------------------------------------------------------
void __cdecl cDARawSrvFns<_sBindContext>::ConstructItem(_sBindContext *pItem, _sBindContext *pFrom)
{
	memcpy(pItem, pFrom, 0x24u);
}

//----- (008D61B0) --------------------------------------------------------
int __thiscall cDABase<_sBindContext_4_cDARawSrvFns<_sBindContext>>::Resize(cDABase<_sBindContext, 4, cDARawSrvFns<_sBindContext> > *this, unsigned int newSlotCount)
{
	int result; // eax@2
	unsigned int evenSlots; // [sp+8h] [bp-4h]@1

	evenSlots = (newSlotCount + 3) & 0xFFFFFFFC;
	if (((this->m_nItems + 3) & 0xFFFFFFFC) == evenSlots)
		result = 1;
	else
		result = cDABaseSrvFns::DoResize((void **)&this->m_pItems, 0x24u, evenSlots);
	return result;
}

//----- (008D6200) --------------------------------------------------------
void *__thiscall cInputBinder::_vector_deleting_destructor_(cInputBinder *this, unsigned int a2)
{
	return cInputBinder::_scalar_deleting_destructor_((cInputBinder *)((char *)this - 8), a2);
}

*/