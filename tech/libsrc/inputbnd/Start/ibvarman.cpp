//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>







/*
//----- (008D1800) --------------------------------------------------------
int __cdecl IBMaxActiveAgg(_intrnl_var_channel **chans, int num_chans, char *str)
{
	double max_val; // [sp+0h] [bp-1Ch]@0
	double cur_val; // [sp+8h] [bp-14h]@4
	int ret_val; // [sp+10h] [bp-Ch]@1
	int i; // [sp+14h] [bp-8h]@1
	const char *max_chan; // [sp+18h] [bp-4h]@1

	max_chan = 0;
	ret_val = 0;
	for (i = 0; i < num_chans; ++i)
	{
		if (chans[i]->active)
		{
			cur_val = atof(chans[i]->val);
			if (cur_val > max_val || !ret_val)
			{
				ret_val = 1;
				max_val = cur_val;
				max_chan = (const char *)chans[i];
			}
		}
	}
	if (ret_val)
		strcpy(str, max_chan);
	return ret_val;
}

//----- (008D18A3) --------------------------------------------------------
int __cdecl IBAddActiveAgg(_intrnl_var_channel **chans, int num_chans, char *str)
{
	int ret_val; // [sp+0h] [bp-10h]@1
	int i; // [sp+4h] [bp-Ch]@1
	double sum; // [sp+8h] [bp-8h]@1

	ret_val = 0;
	sum = 0.0;
	for (i = 0; i < num_chans; ++i)
	{
		if (chans[i]->active)
		{
			ret_val = 1;
			sum = atof(chans[i]->val) + sum;
		}
	}
	if (ret_val)
		sprintf(str, "%8.8f", *(_QWORD *)&sum);
	return ret_val;
}

//----- (008D192E) --------------------------------------------------------
int __cdecl IBAveActiveAgg(_intrnl_var_channel **chans, int num_chans, char *str)
{
	double num_active; // [sp+8h] [bp-18h]@1
	int ret_val; // [sp+10h] [bp-10h]@1
	int i; // [sp+14h] [bp-Ch]@1
	double sum; // [sp+18h] [bp-8h]@1

	ret_val = 0;
	sum = 0.0;
	num_active = 0.0;
	for (i = 0; i < num_chans; ++i)
	{
		if (chans[i]->active)
		{
			ret_val = 1;
			num_active = num_active + 1.0;
			sum = atof(chans[i]->val) + sum;
		}
	}
	if (ret_val)
		sprintf(str, "%8.8f", sum / num_active);
	return ret_val;
}

//----- (008D19D7) --------------------------------------------------------
int __cdecl IBMRUActiveAgg(_intrnl_var_channel **chans, int num_chans, char *str)
{
	int result; // eax@2
	int ret_val; // [sp+0h] [bp-Ch]@3
	int i; // [sp+4h] [bp-8h]@3
	signed int mru; // [sp+8h] [bp-4h]@3

	if (num_chans > 0)
	{
		mru = -1;
		ret_val = 0;
		for (i = 0; i < num_chans; ++i)
		{
			if (chans[i]->active && (mru == -1 || chans[i]->stamp > chans[mru]->stamp))
			{
				mru = i;
				ret_val = 1;
			}
		}
		if (ret_val)
			strcpy(str, chans[mru]->val);
		result = ret_val;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008D1A77) --------------------------------------------------------
void __thiscall cIBVariableManager::cIBVariableManager(cIBVariableManager *this)
{
	cIBVariableManager *v1; // ST04_4@1

	v1 = this;
	aatree<intrnl_var>::aatree<intrnl_var>(&this->m_vars);
	cIBVariableManager::Init(v1);
	cIBVariableManager::SetMasterAggregation(v1, IBMaxActiveAgg);
}

//----- (008D1AA2) --------------------------------------------------------
void __thiscall cIBVariableManager::cIBVariableManager(cIBVariableManager *this, _IB_var *var)
{
	cIBVariableManager *v2; // ST08_4@1

	v2 = this;
	aatree<intrnl_var>::aatree<intrnl_var>(&this->m_vars);
	cIBVariableManager::Init(v2);
	cIBVariableManager::VarSet(v2, var, 0);
}

//----- (008D1AD0) --------------------------------------------------------
void __thiscall cIBVariableManager::cIBVariableManager(cIBVariableManager *this, _IB_var *var, int num)
{
	cIBVariableManager *v3; // ST0C_4@1

	v3 = this;
	aatree<intrnl_var>::aatree<intrnl_var>(&this->m_vars);
	cIBVariableManager::Init(v3);
	cIBVariableManager::VarSet(v3, var, num, 1);
}

//----- (008D1B02) --------------------------------------------------------
void __thiscall cIBVariableManager::Init(cIBVariableManager *this)
{
	cIBVariableManager *v1; // ST04_4@1

	v1 = this;
	this->m_glob_cb = 0;
	this->m_bnd_path = 0;
	cIBVariableManager::SetBndSearchPath(this, ".");
	g_IB_variable_manager = v1;
	cIBVariableManager::SetMasterAggregation(v1, IBMaxActiveAgg);
}

//----- (008D1B47) --------------------------------------------------------
void __thiscall cIBVariableManager::_cIBVariableManager(cIBVariableManager *this)
{
	aatree<intrnl_var> *thisa; // [sp+0h] [bp-8h]@1

	thisa = (aatree<intrnl_var> *)this;
	if (this->m_bnd_path)
		operator delete(this->m_bnd_path);
	aatree<intrnl_var>::_aatree<intrnl_var>(thisa);
}

//----- (008D1B80) --------------------------------------------------------
int __thiscall cIBVariableManager::VarSet(cIBVariableManager *this, _IB_var *vars, int alias)
{
	int result; // eax@2
	int v4; // eax@11
	int v5; // eax@14
	int v6; // [sp+0h] [bp-54h]@11
	aatree<intrnl_var> *thisa; // [sp+4h] [bp-50h]@1
	void *v8; // [sp+14h] [bp-40h]@10
	_IB_var *cur_var; // [sp+24h] [bp-30h]@5
	intrnl_var *int_var; // [sp+28h] [bp-2Ch]@8
	char name[32]; // [sp+2Ch] [bp-28h]@8
	void *cmd_line_chan; // [sp+4Ch] [bp-8h]@3
	int ret_val; // [sp+50h] [bp-4h]@3

	thisa = (aatree<intrnl_var> *)this;
	if (vars)
	{
		ret_val = 1;
		cmd_line_chan = j__new(8u, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 276);
		*(_DWORD *)cmd_line_chan = j__new(0x40u, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 277);
		*((_DWORD *)cmd_line_chan + 1) = j__new(0x40u, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 278);
		strcpy(*(char **)cmd_line_chan, "cmd_line");
		while (vars->name[0])
		{
			cur_var = vars;
			++vars;
			if (strlen(cur_var->name) + 1 <= 0x20 && strlen(cur_var->val) + 1 <= 0x20)
			{
				strcpy(name, cur_var->name);
				strlwr(name);
				int_var = aatree<intrnl_var>::Find(thisa, name);
				if (int_var)
				{
					strcpy(int_var->var.val, cur_var->val);
					strlwr(int_var->var.val);
					int_var->var.cb = cur_var->cb;
					int_var->var.agg = cur_var->agg;
				}
				else
				{
					v8 = j__new(0x9Eu, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 304);
					if (v8)
					{
						intrnl_var::intrnl_var((intrnl_var *)v8);
						v6 = v4;
					}
					else
					{
						v6 = 0;
					}
					memcpy((void *)v6, cur_var, 0x8Cu);
					if (alias)
					{
						v5 = *(_DWORD *)(v6 + 96);
						LOBYTE(v5) = v5 | 2;
						*(_DWORD *)(v6 + 96) = v5;
					}
					if (!cur_var->val[0])
						sprintf((char *)(v6 + 32), "%8.8f", 0, 0);
					strcpy((char *)(v6 + 108), (const char *)(v6 + 32));
					strlwr((char *)v6);
					strlwr((char *)(v6 + 32));
					aatree<intrnl_var>::Add(thisa, (char *)v6, (intrnl_var *)v6, 1);
					strcpy(*((char **)cmd_line_chan + 1), name);
					cIBVariableManager::AddChannel((cIBVariableManager *)thisa, (char **)cmd_line_chan);
				}
			}
			else
			{
				ret_val = 0;
			}
		}
		operator delete(*(void **)cmd_line_chan);
		operator delete(*((void **)cmd_line_chan + 1));
		operator delete(cmd_line_chan);
		result = ret_val;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008D1E04) --------------------------------------------------------
int __thiscall cIBVariableManager::VarSet(cIBVariableManager *this, _IB_var *vars, int num, int alias)
{
	cIBVariableManager *v4; // ST0C_4@1
	void *v5; // ST1C_4@1
	int v6; // ST18_4@1

	v4 = this;
	v5 = j__new(140 * (num + 1), "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 343);
	memcpy(v5, vars, 140 * num);
	memset((char *)v5 + 140 * num, 0, 0x8Cu);
	v6 = cIBVariableManager::VarSet(v4, (_IB_var *)v5, alias);
	operator delete(v5);
	return v6;
}

//----- (008D1E9B) --------------------------------------------------------
char *__thiscall cIBVariableManager::VarUnset(cIBVariableManager *this, char **var_names, int user)
{
	aatree<intrnl_var> *thisa; // [sp+0h] [bp-30h]@1
	char **local_names; // [sp+4h] [bp-2Ch]@1
	intrnl_var *int_var; // [sp+8h] [bp-28h]@3
	char name[32]; // [sp+Ch] [bp-24h]@3
	char *ret_val; // [sp+2Ch] [bp-4h]@1

	thisa = (aatree<intrnl_var> *)this;
	local_names = var_names;
	ret_val = 0;
	while (*local_names)
	{
		strcpy(name, *local_names);
		strlwr(name);
		int_var = aatree<intrnl_var>::Find(thisa, name);
		if (int_var)
		{
			if (!user || int_var->var.flags & 1)
			{
				aatree<_intrnl_var_channel>::DeleteAll(&int_var->channels, 1);
				aatree<intrnl_var>::Delete(thisa, name, 1, 0);
			}
			else
			{
				ret_val = g_err_msg[4];
			}
		}
		else
		{
			ret_val = g_err_msg[3];
		}
		++local_names;
	}
	return ret_val;
}

//----- (008D1F4F) --------------------------------------------------------
char *__thiscall cIBVariableManager::VarUnset(cIBVariableManager *this, char **var_names, int num, int user)
{
	size_t v4; // eax@3
	cIBVariableManager *thisa; // [sp+0h] [bp-20h]@1
	char *ret_val; // [sp+14h] [bp-Ch]@4
	int i; // [sp+18h] [bp-8h]@1
	int ia; // [sp+18h] [bp-8h]@4
	void *new_names; // [sp+1Ch] [bp-4h]@1

	thisa = this;
	new_names = j__new(4 * num + 4, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 402);
	for (i = 0; i < num; ++i)
	{
		v4 = strlen(var_names[i]);
		*((_DWORD *)new_names + i) = j__new(v4 + 1, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 404);
		strcpy(*((char **)new_names + i), var_names[i]);
	}
	*((_DWORD *)new_names + num) = 0;
	ret_val = cIBVariableManager::VarUnset(thisa, (char **)new_names, user);
	for (ia = 0; ia < num; ++ia)
	{
		if (*((_DWORD *)new_names + ia))
			operator delete(*((void **)new_names + ia));
	}
	operator delete(new_names);
	return ret_val;
}

//----- (008D2068) --------------------------------------------------------
char *__thiscall cIBVariableManager::VarUnsetAll(cIBVariableManager *this)
{
	aatree<intrnl_var> *thisa; // [sp+0h] [bp-8h]@1
	intrnl_var *int_var; // [sp+4h] [bp-4h]@2

	for (thisa = (aatree<intrnl_var> *)this;; aatree<intrnl_var>::Delete(thisa, int_var->var.name, 1, 0))
	{
		aatree<intrnl_var>::ResetVisited(thisa, 0);
		int_var = aatree<intrnl_var>::GetNextInOrder(thisa, 0);
		if (!int_var)
			break;
		aatree<_intrnl_var_channel>::DeleteAll(&int_var->channels, 1);
	}
	return 0;
}

//----- (008D20C1) --------------------------------------------------------
char *__thiscall cIBVariableManager::Cmd(cIBVariableManager *this, char *cmd, int already_down)
{
	char *result; // eax@3
	size_t v4; // esi@19
	unsigned int v5; // esi@19
	size_t v6; // eax@19
	size_t v7; // esi@22
	size_t v8; // eax@22
	size_t v9; // esi@34
	size_t v10; // eax@34
	cIBVariableManager *thisa; // [sp+4h] [bp-FCh]@1
	_IB_var var; // [sp+28h] [bp-D8h]@53
	int alias; // [sp+B4h] [bp-4Ch]@53
	intrnl_var *int_var; // [sp+B8h] [bp-48h]@49
	char name[32]; // [sp+BCh] [bp-44h]@49
	void *v16; // [sp+DCh] [bp-24h]@34
	char *v17; // [sp+E0h] [bp-20h]@35
	char *Dest; // [sp+E4h] [bp-1Ch]@19
	void *tmp_cmd; // [sp+E8h] [bp-18h]@22
	int loc_num_tokens; // [sp+ECh] [bp-14h]@13
	char **loc_tokens; // [sp+F0h] [bp-10h]@13
	char *ret_str; // [sp+F4h] [bp-Ch]@1
	char **tokens; // [sp+F8h] [bp-8h]@1
	int num_tokens; // [sp+FCh] [bp-4h]@1

	thisa = this;
	ret_str = 0;
	strlwr(cmd);
	tokens = cIBVariableManager::Tokenize(thisa, cmd, &num_tokens, 1);
	if (num_tokens && **tokens != 59)
	{
		if (strcmp("bind", *tokens))
		{
			if (strcmp("unbind", *tokens))
			{
				if (strcmp("ibset", *tokens) && strcmp("alias", *tokens))
				{
					if (strcmp("ibunset", *tokens) && strcmp("alias", *tokens))
					{
						if (strcmp("echo", *tokens))
						{
							if (strcmp("loadbnd", *tokens))
							{
								if (strcmp("savebnd", *tokens))
								{
									if (num_tokens > 0 && **tokens)
										ret_str = cIBVariableManager::ProcessCommand(thisa, tokens, num_tokens, already_down);
								}
								else
								{
									if (num_tokens == 2)
										cIBInputMapper::SaveBnd(g_IB_input_mapper, tokens[1], 0);
									else
										ret_str = g_err_msg[0];
								}
							}
							else
							{
								if (num_tokens == 2)
									ret_str = cIBVariableManager::LoadBnd(thisa, tokens[1], 0);
								else
									ret_str = g_err_msg[0];
							}
						}
						else
						{
							cIBVariableManager::TokensToStr(thisa, thisa->m_misc_str, 128, tokens + 1, num_tokens - 1);
							ret_str = thisa->m_misc_str;
						}
					}
					else
					{
						if (num_tokens == 2)
						{
							if (strlen(tokens[1]) + 1 <= 0x20)
								ret_str = cIBVariableManager::VarUnset(thisa, tokens + 1, 1, 1);
							else
								ret_str = g_err_msg[5];
						}
						else
						{
							ret_str = g_err_msg[0];
						}
					}
				}
				else
				{
					if (num_tokens == 2 || num_tokens == 3)
					{
						if (strlen(tokens[1]) + 1 <= 0x20 && (num_tokens != 3 || strlen(tokens[2]) + 1 <= 0x20))
						{
							strcpy(name, tokens[1]);
							strlwr(name);
							int_var = aatree<intrnl_var>::Find(&thisa->m_vars, name);
							if (int_var)
							{
								if (num_tokens == 3)
								{
									strcpy(int_var->var.val, tokens[2]);
									strlwr(int_var->var.val);
								}
							}
							else
							{
								alias = strcmp("alias", *tokens) == 0;
								strcpy(var.name, name);
								if (num_tokens == 3)
									strcpy(var.val, tokens[2]);
								else
									strcpy(var.val, "0");
								var.flags = 1;
								var.cb = 0;
								var.agg = 0;
								cIBVariableManager::VarSet(thisa, &var, 1, alias);
							}
						}
						else
						{
							ret_str = g_err_msg[5];
						}
					}
					else
					{
						ret_str = g_err_msg[0];
					}
				}
			}
			else
			{
				if (num_tokens == 2)
				{
					if (strlen(tokens[1]) + 1 <= 0x20)
					{
						if (!strcmp(tokens[1], "shift") || !strcmp(tokens[1], "alt") || !strcmp(tokens[1], "ctrl"))
						{
							v9 = strlen("unbind ");
							v10 = strlen(tokens[1]);
							v16 = j__new(v9 + v10 + 2, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 542);
							strcpy((char *)v16, "unbind ");
							strcat((char *)v16, "l");
							strcat((char *)v16, tokens[1]);
							cIBVariableManager::Cmd(thisa, (char *)v16, 0);
							*((_BYTE *)v16 + 7) = 114;
							ret_str = cIBVariableManager::Cmd(thisa, (char *)v16, 0);
							operator delete(v16);
						}
						v17 = (char *)j__new(0x20u, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 553);
						ret_str = cIBInputMapper::Unbind(g_IB_input_mapper, tokens[1], &v17);
						if (!ret_str && *v17)
							cIBVariableManager::SubtractChannel(thisa, v17, tokens[1]);
						operator delete(v17);
					}
					else
					{
						ret_str = g_err_msg[5];
					}
				}
				else
				{
					ret_str = g_err_msg[0];
				}
			}
		}
		else
		{
			if (num_tokens >= 2)
			{
				if (strlen(tokens[1]) + 1 <= 0x20 && (num_tokens != 3 || strlen(tokens[2]) + 1 <= 0x40))
				{
					if (num_tokens == 2)
					{
						ret_str = cIBInputMapper::PeekBind(g_IB_input_mapper, tokens[1], 1);
					}
					else
					{
						loc_tokens = cIBVariableManager::Tokenize(thisa, cmd, &loc_num_tokens, 0);
						if (loc_num_tokens == 2 || loc_num_tokens == 3)
						{
							if (!strcmp(tokens[1], "shift") || !strcmp(tokens[1], "alt") || !strcmp(tokens[1], "ctrl"))
							{
								v4 = strlen("bind ");
								v5 = strlen(loc_tokens[1]) + v4;
								v6 = strlen(loc_tokens[2]);
								Dest = (char *)j__new(v5 + v6 + 3, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 496);
								strcpy(Dest, "bind ");
								strcat(Dest, "l");
								strcat(Dest, loc_tokens[1]);
								if (loc_num_tokens == 3)
								{
									strcat(Dest, " ");
									strcat(Dest, loc_tokens[2]);
								}
								cIBVariableManager::Cmd(thisa, Dest, 0);
								Dest[5] = 114;
								ret_str = cIBVariableManager::Cmd(thisa, Dest, 0);
								operator delete(Dest);
							}
							v7 = strlen("unbind ");
							v8 = strlen(loc_tokens[1]);
							tmp_cmd = j__new(v7 + v8 + 1, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 513);
							strcpy((char *)tmp_cmd, "unbind ");
							strcat((char *)tmp_cmd, loc_tokens[1]);
							cIBVariableManager::Cmd(thisa, (char *)tmp_cmd, 0);
							operator delete(tmp_cmd);
							ret_str = cIBInputMapper::Bind(g_IB_input_mapper, loc_tokens + 1);
							if (!ret_str)
								cIBVariableManager::AddChannel(thisa, tokens + 1);
						}
						else
						{
							ret_str = g_err_msg[0];
						}
						cIBVariableManager::FreeTokens(thisa, loc_tokens, loc_num_tokens);
					}
				}
				else
				{
					ret_str = g_err_msg[5];
				}
			}
			else
			{
				ret_str = g_err_msg[0];
			}
		}
		cIBVariableManager::FreeTokens(thisa, tokens, num_tokens);
		result = ret_str;
	}
	else
	{
		cIBVariableManager::FreeTokens(thisa, tokens, num_tokens);
		result = 0;
	}
	return result;
}

//----- (008D2907) --------------------------------------------------------
void __thiscall cIBVariableManager::SetMasterAggregation(cIBVariableManager *this, int(__cdecl *func)(_intrnl_var_channel **, int, char *))
{
	this->m_glob_agg = func;
}

//----- (008D291D) --------------------------------------------------------
void __thiscall cIBVariableManager::SetMasterProcessCallback(cIBVariableManager *this, char *(__cdecl *func)(char *, char *, int))
{
	this->m_glob_cb = func;
}

//----- (008D2933) --------------------------------------------------------
void __thiscall cIBVariableManager::SetBndSearchPath(cIBVariableManager *this, char *p_path)
{
	size_t v2; // eax@3
	cIBVariableManager *thisa; // [sp+0h] [bp-Ch]@1

	thisa = this;
	if (this->m_bnd_path)
		operator delete(this->m_bnd_path);
	v2 = strlen(p_path);
	thisa->m_bnd_path = (char *)j__new(v2 + 1, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 700);
	strcpy(thisa->m_bnd_path, p_path);
}

//----- (008D29AD) --------------------------------------------------------
char *__thiscall cIBVariableManager::ProcessCommand(cIBVariableManager *this, char **tokens, int num_tokens, int already_down)
{
	char *result; // eax@7
	double v5; // ST14_8@20
	double v6; // st7@20
	double v7; // st7@28
	__int16 v8; // cx@28
	double v9; // st7@28
	double v10; // st7@39
	__int16 v11; // cx@39
	double v12; // st7@39
	int(__cdecl *v13)(_intrnl_var_channel **, int, char *); // [sp+8h] [bp-8Ch]@41
	int v14; // [sp+14h] [bp-80h]@3
	cIBVariableManager *thisa; // [sp+18h] [bp-7Ch]@1
	void *chan_array; // [sp+24h] [bp-70h]@44
	int i; // [sp+28h] [bp-6Ch]@44
	int num_chans; // [sp+2Ch] [bp-68h]@44
	signed int cur_token; // [sp+30h] [bp-64h]@30
	_intrnl_var_channel *channel; // [sp+34h] [bp-60h]@13
	char v21; // [sp+38h] [bp-5Ch]@1
	int ret_val; // [sp+40h] [bp-54h]@1
	intrnl_var *var; // [sp+44h] [bp-50h]@5
	char final_val[32]; // [sp+48h] [bp-4Ch]@47
	int chan_ret; // [sp+68h] [bp-2Ch]@43
	int active_toggle; // [sp+6Ch] [bp-28h]@5
	char control[32]; // [sp+70h] [bp-24h]@1
	char *val; // [sp+90h] [bp-4h]@14

	thisa = this;
	ret_val = 0;
	strcpy(control, "cmd_line");
	v21 = **tokens;
	v14 = v21 == 43 || v21 == 45;
	active_toggle = v14;
	var = aatree<intrnl_var>::Find(&thisa->m_vars, &(*tokens)[v14]);
	if (var)
	{
		if (num_tokens > 2 && !strcmp(tokens[num_tokens - 2], "control:"))
		{
			strcpy(control, tokens[num_tokens - 1]);
			num_tokens -= 2;
		}
		if (active_toggle)
		{
			channel = aatree<_intrnl_var_channel>::Find(&var->channels, control);
			if (!channel)
				return g_err_msg[2];
			channel->active = v21 == 43;
			++var->stamp;
			channel->stamp = var->stamp;
			val = (char *)channel;
		}
		else
		{
			val = var->var.val;
		}
		if (num_tokens <= 1)
		{
			if (active_toggle)
			{
				if (v21 == 43)
					strcpy(val, "1.0");
				else
					strcpy(val, "0.0");
			}
			else
			{
				v10 = atof(val);
				v12 = floor(v11, v10 + 0.5);
				sprintf(val, "%8.8f", 1.0 - v12);
			}
		}
		else
		{
			if (strcmp(tokens[1], g_adj_type[1]))
			{
				if (strcmp(tokens[1], g_adj_type[2]))
				{
					cur_token = 1;
					if (!strcmp(tokens[1], g_adj_type[0]))
						cur_token = 2;
					strcpy(val, tokens[cur_token]);
				}
				else
				{
					if (num_tokens == 3)
					{
						if (atof(val) == 0.0)
							strcpy(val, tokens[2]);
						else
							strcpy(val, "0");
					}
					else
					{
						v7 = atof(val);
						v9 = floor(v8, v7 + 0.5);
						sprintf(val, "%8.8f", 1.0 - v9);
					}
				}
			}
			else
			{
				if (num_tokens > 2)
				{
					v5 = atof(val);
					v6 = atof(tokens[2]);
					sprintf(val, "%8.8f", v6 + v5);
				}
			}
		}
		if (var->var.agg)
			v13 = var->var.agg;
		else
			v13 = thisa->m_glob_agg;
		chan_ret = 0;
		if (v13)
		{
			num_chans = aatree<_intrnl_var_channel>::GetNumNodes(&var->channels);
			chan_array = j__new(4 * num_chans, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 821);
			aatree<_intrnl_var_channel>::ResetVisited(&var->channels, 0);
			for (i = 0; i < num_chans; ++i)
				*((_DWORD *)chan_array + i) = aatree<_intrnl_var_channel>::GetNextInOrder(&var->channels, 0);
			chan_ret = v13((_intrnl_var_channel **)chan_array, num_chans, final_val);
			operator delete(chan_array);
		}
		if (!chan_ret)
			strcpy(final_val, var->var.val);
		if (strcmp(var->var.last_val, final_val))
		{
			if (var->var.cb)
			{
				ret_val = (int)var->var.cb((char *)var, final_val, already_down);
			}
			else
			{
				if (thisa->m_glob_cb)
					ret_val = (int)thisa->m_glob_cb((char *)var, final_val, already_down);
			}
			strcpy(var->var.last_val, final_val);
		}
		result = (char *)ret_val;
	}
	else
	{
		if (thisa->m_glob_cb)
		{
			cIBVariableManager::GlueTokens(thisa, str1, tokens, num_tokens);
			cIBInputMapper::StripControl(g_IB_input_mapper, str2, str1);
			result = thisa->m_glob_cb(str2, 0, already_down);
		}
		else
		{
			result = 0;
		}
	}
	return result;
}

//----- (008D2E59) --------------------------------------------------------
char *__thiscall cIBVariableManager::GetVarVal(cIBVariableManager *this, char *dest, char *val_name)
{
	char *result; // eax@2
	intrnl_var *var; // [sp+4h] [bp-4h]@1

	var = aatree<intrnl_var>::Find(&this->m_vars, val_name);
	if (var)
	{
		strcpy(dest, var->var.val);
		result = 0;
	}
	else
	{
		*dest = 0;
		result = g_err_msg[3];
	}
	return result;
}

//----- (008D2E9F) --------------------------------------------------------
char *__thiscall cIBVariableManager::AddChannel(cIBVariableManager *this, char **control)
{
	char *result; // eax@6
	int v3; // [sp+0h] [bp-24h]@3
	aatree<intrnl_var> *thisa; // [sp+4h] [bp-20h]@1
	void *channel; // [sp+Ch] [bp-18h]@9
	char v6; // [sp+10h] [bp-14h]@1
	signed int cur_token; // [sp+14h] [bp-10h]@1
	char **tokens; // [sp+18h] [bp-Ch]@5
	intrnl_var *var; // [sp+1Ch] [bp-8h]@7
	int num_tokens; // [sp+20h] [bp-4h]@5

	thisa = (aatree<intrnl_var> *)this;
	cur_token = 1;
	v6 = *control[1];
	v3 = v6 == 43 || v6 == 45;
	tokens = cIBVariableManager::Tokenize(this, &control[1][v3], &num_tokens, 0);
	if (num_tokens)
	{
		var = aatree<intrnl_var>::Find(thisa, *tokens);
		if (var)
		{
			channel = j__new(0x2Eu, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 893);
			*((_DWORD *)channel + 9) = 0;
			if (num_tokens <= 1)
			{
				*((_DWORD *)channel + 8) = 2;
				sprintf((char *)channel, "%8.8f", 0, 0);
			}
			else
			{
				*((_DWORD *)channel + 8) = 0;
				if (strcmp(tokens[1], g_adj_type[1]))
				{
					if (!strcmp(tokens[1], g_adj_type[2]))
					{
						*((_DWORD *)channel + 8) = 2;
						cur_token = 2;
					}
				}
				else
				{
					*((_DWORD *)channel + 8) = 1;
					cur_token = 2;
				}
				if (num_tokens <= cur_token)
					sprintf((char *)channel, "%8.8f", 0, 0);
				else
					strcpy((char *)channel, tokens[cur_token]);
			}
			*(_DWORD *)((char *)channel + 42) = g_IB_input_mapper->m_context;
			aatree<_intrnl_var_channel>::Add(&var->channels, *control, (_intrnl_var_channel *)channel, 1);
			cIBVariableManager::FreeTokens((cIBVariableManager *)thisa, tokens, num_tokens);
			result = 0;
		}
		else
		{
			cIBVariableManager::FreeTokens((cIBVariableManager *)thisa, tokens, num_tokens);
			result = g_err_msg[3];
		}
	}
	else
	{
		cIBVariableManager::FreeTokens((cIBVariableManager *)thisa, tokens, 0);
		result = g_err_msg[0];
	}
	return result;
}

//----- (008D3078) --------------------------------------------------------
char *__thiscall cIBVariableManager::SubtractChannel(cIBVariableManager *this, char *var_name, char *control)
{
	char *result; // eax@2
	cIBVariableManager *thisa; // [sp+0h] [bp-Ch]@1
	_intrnl_var_channel *channel; // [sp+4h] [bp-8h]@3
	intrnl_var *var; // [sp+8h] [bp-4h]@1

	thisa = this;
	var = aatree<intrnl_var>::Find(&this->m_vars, var_name);
	if (var)
	{
		channel = cIBVariableManager::FindContextChannel(thisa, var, control);
		if (channel)
		{
			aatree<_intrnl_var_channel>::Delete(&var->channels, control, 1, channel);
			result = 0;
		}
		else
		{
			result = g_err_msg[2];
		}
	}
	else
	{
		result = g_err_msg[3];
	}
	return result;
}

//----- (008D30DD) --------------------------------------------------------
_intrnl_var_channel *__thiscall cIBVariableManager::FindContextChannel(cIBVariableManager *this, intrnl_var *var, char *control)
{
	_intrnl_var_channel *result; // eax@2
	_intrnl_var_channel *channel; // [sp+4h] [bp-84h]@1
	char str[128]; // [sp+8h] [bp-80h]@6

	channel = aatree<_intrnl_var_channel>::Find(&var->channels, control);
	if (channel)
	{
		aatree<_intrnl_var_channel>::ResetVisited(&var->channels, 0);
		aatree<_intrnl_var_channel>::VisitBefore(&var->channels, channel, 0);
		do
		{
			if (channel->context == g_IB_input_mapper->m_context)
				return channel;
			channel = aatree<_intrnl_var_channel>::GetNextInOrder(&var->channels, str);
		} while (channel && !strcmp(control, str));
		result = 0;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008D3193) --------------------------------------------------------
void __thiscall cIBVariableManager::LoadBndContexted(cIBVariableManager *this, char *pFName, _sBindContext *pContexts, unsigned int iNumContexts, cIBInputMapper **m_ppMappers)
{
	cIBInputMapper *v5; // eax@18
	size_t v6; // eax@21
	cIBInputMapper *v7; // [sp+0h] [bp-12Ch]@18
	cIBVariableManager *thisa; // [sp+4h] [bp-128h]@1
	void *v9; // [sp+8h] [bp-124h]@17
	FILE *pFile; // [sp+Ch] [bp-120h]@1
	char aszBuf[256]; // [sp+14h] [bp-118h]@2
	char **ppszTokens; // [sp+114h] [bp-18h]@2
	int iNumTokens; // [sp+118h] [bp-14h]@2
	int j; // [sp+11Ch] [bp-10h]@13
	unsigned int i; // [sp+120h] [bp-Ch]@3
	unsigned int iContext; // [sp+124h] [bp-8h]@13
	const char *pszPrefix; // [sp+128h] [bp-4h]@2

	thisa = this;
	pFile = fopen(pFName, "r");
	if (pFile)
	{
		do
		{
			fgets(aszBuf, 255, pFile);
			ppszTokens = cIBVariableManager::Tokenize(thisa, aszBuf, &iNumTokens, 1);
			pszPrefix = *ppszTokens;
			if (iNumTokens)
			{
				for (i = 0; g_apszBindCmds[i]; ++i)
				{
					if (!_strcmpi(pszPrefix, g_apszBindCmds[i]))
					{
						pszPrefix = (const char *)&dword_EAC40C;
						break;
					}
				}
				for (i = 0; i < iNumContexts && _strcmpi(pszPrefix, pContexts[i].aszStr); ++i)
					;
				if (i < iNumContexts)
				{
					iContext = pContexts[i].iContext;
					for (j = 0; j < 32; ++j)
					{
						if ((iContext >> j) & 1)
						{
							if (!m_ppMappers[j])
							{
								v9 = j__new(0xB5u, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 1021);
								if (v9)
								{
									cIBInputMapper::cIBInputMapper((cIBInputMapper *)v9);
									v7 = v5;
								}
								else
								{
									v7 = 0;
								}
								m_ppMappers[j] = v7;
								m_ppMappers[j]->m_context = 1 << j;
							}
							g_IB_input_mapper = m_ppMappers[j];
							v6 = strlen(pszPrefix);
							cIBVariableManager::Cmd(thisa, &aszBuf[v6], 0);
						}
					}
				}
				cIBVariableManager::FreeTokens(thisa, ppszTokens, iNumTokens);
			}
		} while (!(pFile->_flag & 0x10));
		fclose(pFile);
	}
}
// EAC40C: using guessed type int dword_EAC40C;

//----- (008D33CB) --------------------------------------------------------
char *__thiscall cIBVariableManager::LoadBnd(cIBVariableManager *this, char *bnd_filename, char *prefix)
{
	char *result; // eax@2
	size_t v4; // eax@7
	cIBVariableManager *thisa; // [sp+0h] [bp-90h]@1
	FILE *fp; // [sp+4h] [bp-8Ch]@1
	char **tokens; // [sp+8h] [bp-88h]@5
	char str[128]; // [sp+Ch] [bp-84h]@4
	int num_tokens; // [sp+8Ch] [bp-4h]@5

	thisa = this;
	fp = fopen(bnd_filename, "r");
	if (fp)
	{
		fseek(fp, 0, 0);
		do
		{
			fgets(str, 127, fp);
			if (prefix)
			{
				tokens = cIBVariableManager::Tokenize(thisa, str, &num_tokens, 1);
				if (num_tokens)
				{
					if (!strcmp(*tokens, prefix))
					{
						v4 = strlen(*tokens);
						cIBVariableManager::Cmd(thisa, &str[v4], 0);
					}
				}
				cIBVariableManager::FreeTokens(thisa, tokens, num_tokens);
			}
			else
			{
				cIBVariableManager::Cmd(thisa, str, 0);
			}
		} while (!(fp->_flag & 0x10));
		fclose(fp);
		result = 0;
	}
	else
	{
		result = g_err_msg[6];
	}
	return result;
}

//----- (008D34EF) --------------------------------------------------------
char **__thiscall cIBVariableManager::Tokenize(cIBVariableManager *this, char *cmd, int *num_tokens, int expand_alias)
{
	char **result; // eax@2
	size_t v5; // eax@51
	aatree<intrnl_var> *thisa; // [sp+4h] [bp-58h]@1
	int num_expanded_tokens; // [sp+34h] [bp-28h]@38
	char **expanded_tokens; // [sp+38h] [bp-24h]@38
	int j; // [sp+3Ch] [bp-20h]@38
	intrnl_var *var; // [sp+40h] [bp-1Ch]@34
	int num; // [sp+44h] [bp-18h]@10
	char v12; // [sp+48h] [bp-14h]@16
	int i; // [sp+4Ch] [bp-10h]@7
	int expand_var; // [sp+50h] [bp-Ch]@1
	void *tokens; // [sp+54h] [bp-8h]@6
	void *tmp_tokens; // [sp+58h] [bp-4h]@7

	thisa = (aatree<intrnl_var> *)this;
	expand_var = 0;
	if (cmd)
	{
		if (*cmd && *cmd != 13 && *cmd != 10)
		{
			tmp_tokens = j__new(0x80u, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 1139);
			for (i = 0; i < 32; ++i)
				*((_DWORD *)tmp_tokens + i) = j__new(0x80u, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 1141);
			SkipWhiteSpace(&cmd);
			num = 0;
			for (i = 0; i < 32 && *cmd && *cmd != 13 && *cmd != 10; ++i)
			{
				if (*cmd == 34)
				{
					++cmd;
					v12 = 34;
				}
				else
				{
					if (*cmd == 59)
					{
						if (num < 1)
							break;
						if (num == 1)
						{
							if (strcmp(*(const char **)tmp_tokens, "bind") && strcmp(*(const char **)tmp_tokens, "unbind"))
								break;
						}
						else
						{
							if (strcmp(*((const char **)tmp_tokens + num - 1), "control:"))
								break;
						}
						v12 = 32;
					}
					else
					{
						v12 = 32;
					}
				}
				if (*cmd == 61)
				{
					strcpy(*((char **)tmp_tokens + num), "=");
					++i;
					++num;
					++cmd;
				}
				else
				{
					if (*cmd == 36)
					{
						if (num - 1 >= 0)
						{
							if (strcmp(*((const char **)tmp_tokens + num - 1), "bind")
								&& strcmp(*((const char **)tmp_tokens + num - 1), "unbind"))
								expand_var = 1;
						}
						else
						{
							expand_var = 1;
						}
					}
					GetChunk(*((char **)tmp_tokens + num), &cmd, v12, 0);
					var = aatree<intrnl_var>::Find(thisa, *((char **)tmp_tokens + num));
					if (expand_var || expand_alias && var && var->var.flags & 2)
					{
						cIBVariableManager::GetVarVal(
							(cIBVariableManager *)thisa,
							*((char **)tmp_tokens + num),
							(char *)(expand_var + *((_DWORD *)tmp_tokens + num)));
						expanded_tokens = cIBVariableManager::Tokenize(
							(cIBVariableManager *)thisa,
							*((char **)tmp_tokens + num),
							&num_expanded_tokens,
							1);
						for (j = 0; j < num_expanded_tokens; ++j)
						{
							if (j + num < 32)
							{
								operator delete(*((void **)tmp_tokens + j + num));
								*((_DWORD *)tmp_tokens + j + num) = expanded_tokens[j];
							}
							else
							{
								operator delete(expanded_tokens[j]);
							}
						}
						if (num_expanded_tokens)
							operator delete(expanded_tokens);
						expand_var = 0;
						num = num + num_expanded_tokens - 1;
					}
					++num;
				}
				SkipWhiteSpace(&cmd);
			}
			*num_tokens = num;
			tokens = j__new(4 * num, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 1217);
			for (i = 0; i < num; ++i)
			{
				v5 = strlen(*((const char **)tmp_tokens + i));
				*((_DWORD *)tokens + i) = j__new(v5 + 1, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 1219);
				strcpy(*((char **)tokens + i), *((const char **)tmp_tokens + i));
			}
			for (i = 0; i < 32; ++i)
				operator delete(*((void **)tmp_tokens + i));
			operator delete(tmp_tokens);
			result = (char **)tokens;
		}
		else
		{
			tokens = j__new(4u, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 1130);
			*(_DWORD *)tokens = j__new(1u, "x:\\prj\\tech\\libsrc\\inputbnd\\ibvarman.cpp", 1131);
			**(_BYTE **)tokens = 0;
			*num_tokens = 1;
			result = (char **)tokens;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}


*/