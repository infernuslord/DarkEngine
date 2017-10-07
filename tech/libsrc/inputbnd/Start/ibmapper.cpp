//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>






/*
//----- (008D6337) --------------------------------------------------------
void __thiscall cIBInputMapper::cIBInputMapper(cIBInputMapper *this)
{
	size_t v1; // eax@7
	size_t v2; // eax@8
	size_t v3; // eax@10
	size_t v4; // eax@11
	cIBInputMapper *thisa; // [sp+0h] [bp-30h]@1
	char **cur_control; // [sp+Ch] [bp-24h]@2
	void *code; // [sp+10h] [bp-20h]@4
	char code_str[16]; // [sp+14h] [bp-1Ch]@7
	void *control_name; // [sp+24h] [bp-Ch]@7
	int j; // [sp+28h] [bp-8h]@15
	int i; // [sp+2Ch] [bp-4h]@13

	thisa = this;
	aatree<char>::aatree<char>(&this->m_control_binds);
	thisa->m_mod_states = 0;
	thisa->m_trapping = 0;
	thisa->m_valid_events = -1;
	thisa->m_pCtrlIterNode = 0;
	thisa->m_joyproc = 0;
	uiSetMouseMotionPolling(1);
	if (!aatree<short>::GetNumNodes(&g_input_codes))
	{
		for (cur_control = (char **)g_valid_input_controls; *cur_control; cur_control = (char **)((char *)cur_control + 6))
		{
			code = j__new(2u, "x:\\prj\\tech\\libsrc\\inputbnd\\ibmapper.cpp", 227);
			if (*((_WORD *)cur_control + 2))
				*(_WORD *)code = *((_WORD *)cur_control + 2);
			else
				*(_WORD *)code = (unsigned __int8)**cur_control;
			aatree<short>::Add(&g_input_codes, *cur_control, (__int16 *)code, 1);
			v1 = strlen(*cur_control);
			control_name = j__new(v1 + 2, "x:\\prj\\tech\\libsrc\\inputbnd\\ibmapper.cpp", 234);
			strcpy((char *)control_name, *cur_control);
			sprintf(code_str, "%d", *(_WORD *)code);
			if (strncmp("mouse", (const char *)control_name, 5u))
			{
				if (strncmp("joy", (const char *)control_name, 3u))
				{
					v4 = strlen((const char *)control_name);
					aatree<char>::Add(&g_input_controls, code_str, (char *)control_name, v4 + 1);
				}
				else
				{
					v3 = strlen((const char *)control_name);
					aatree<char>::Add(&stru_EAC710, (char *)control_name, (char *)control_name, v3 + 1);
				}
			}
			else
			{
				v2 = strlen((const char *)control_name);
				aatree<char>::Add(&stru_EAC700, code_str, (char *)control_name, v2 + 1);
			}
		}
	}
	for (i = 0; i < 224; ++i)
	{
		g_shift_to_scan[i] = 0;
		for (j = 0; j < 224; ++j)
		{
			if ((char)i == LOBYTE(word_B25882[3 * j]))
			{
				g_shift_to_scan[i] = j;
				break;
			}
		}
	}
	g_IB_input_mapper = thisa;
}
// B25882: using guessed type __int16 word_B25882[];

//----- (008D658A) --------------------------------------------------------
void __thiscall cIBInputMapper::_cIBInputMapper(cIBInputMapper *this)
{
	aatree<char>::_aatree<char>(&this->m_control_binds);
}

//----- (008D659D) --------------------------------------------------------
char *__thiscall cIBInputMapper::Bind(cIBInputMapper *this, char **tokens)
{
	char *result; // eax@2
	size_t v3; // eax@3
	void *v4; // ST2C_4@4
	void *v5; // eax@8
	int v6; // eax@12
	size_t v7; // esi@14
	unsigned int v8; // esi@14
	size_t v9; // eax@14
	size_t v10; // eax@14
	int v11; // [sp+4h] [bp-C0h]@12
	void *v12; // [sp+8h] [bp-BCh]@8
	cIBInputMapper *thisa; // [sp+Ch] [bp-B8h]@1
	void *v14; // [sp+14h] [bp-B0h]@11
	void *v15; // [sp+18h] [bp-ACh]@7
	char controls[128]; // [sp+30h] [bp-94h]@1
	char *cmd; // [sp+B0h] [bp-14h]@3
	char *ret_val; // [sp+B4h] [bp-10h]@1
	cContDListNode<cAnsiStr, 0> *pNode; // [sp+B8h] [bp-Ch]@14
	sCmdCtrlEntry *pCmdCtrlEntry; // [sp+BCh] [bp-8h]@6
	int num_controls; // [sp+C0h] [bp-4h]@1

	thisa = this;
	ret_val = cIBInputMapper::DecomposeControl(this, *tokens, (char(*)[32])controls, &num_controls);
	if (ret_val)
	{
		result = ret_val;
	}
	else
	{
		cIBInputMapper::RecomposeControl(thisa, thisa->m_misc_str, (char(*)[32])controls, num_controls);
		operator delete(*tokens);
		v3 = strlen(thisa->m_misc_str);
		*tokens = (char *)j__new(v3 + 1, "x:\\prj\\tech\\libsrc\\inputbnd\\ibmapper.cpp", 309);
		strcpy(*tokens, thisa->m_misc_str);
		cmd = aatree<char>::Find(&thisa->m_control_binds, thisa->m_misc_str);
		if (cmd)
		{
			operator delete(cmd);
		}
		else
		{
			aatree<char>::Add(&thisa->m_control_binds, thisa->m_misc_str, 0, 1);
			v4 = j__new(1u, "x:\\prj\\tech\\libsrc\\inputbnd\\ibmapper.cpp", 317);
			*(_BYTE *)v4 = 0;
			aatree<unsigned_char>::Add(&g_input_down, thisa->m_misc_str, (char *)v4, 1);
		}
		cmd = tokens[1];
		pCmdCtrlEntry = cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>::Search(
			&g_CmdCtrlHash.baseclass_0.baseclass_0,
			cmd);
		if (!pCmdCtrlEntry)
		{
			v15 = j__new(0x14u, "x:\\prj\\tech\\libsrc\\inputbnd\\ibmapper.cpp", 330);
			if (v15)
			{
				sCmdCtrlEntry::sCmdCtrlEntry((sCmdCtrlEntry *)v15);
				v12 = v5;
			}
			else
			{
				v12 = 0;
			}
			pCmdCtrlEntry = (sCmdCtrlEntry *)v12;
			cAnsiStr::operator_((cAnsiStr *)v12, cmd);
			cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>::Insert(
				&g_CmdCtrlHash.baseclass_0.baseclass_0,
				pCmdCtrlEntry);
		}
		RemoveCmdCtrlNode(&pCmdCtrlEntry->ctrlList, thisa->m_misc_str);
		v14 = j__new(0x14u, "x:\\prj\\tech\\libsrc\\inputbnd\\ibmapper.cpp", 336);
		if (v14)
		{
			cContDListNode<cAnsiStr_0>::cContDListNode<cAnsiStr_0>((cContDListNode<cAnsiStr, 0> *)v14);
			v11 = v6;
		}
		else
		{
			v11 = 0;
		}
		pNode = (cContDListNode<cAnsiStr, 0> *)v11;
		cAnsiStr::operator_((cAnsiStr *)(v11 + 8), thisa->m_misc_str);
		cDList<cContDListNode<cAnsiStr_0>_0>::Append(&pCmdCtrlEntry->ctrlList.baseclass_0, pNode);
		v7 = strlen(tokens[1]);
		v8 = strlen(" control: ") + v7;
		v9 = strlen(thisa->m_misc_str);
		cmd = (char *)j__new(v8 + v9 + 1, "x:\\prj\\tech\\libsrc\\inputbnd\\ibmapper.cpp", 342);
		strcpy(cmd, tokens[1]);
		strcat(cmd, " control: ");
		strcat(cmd, thisa->m_misc_str);
		v10 = strlen(cmd);
		aatree<char>::ChangeInfo(&thisa->m_control_binds, thisa->m_misc_str, cmd, v10 + 1);
		result = 0;
	}
	return result;
}

//----- (008D68CF) --------------------------------------------------------
void __cdecl RemoveCmdCtrlNode(cContainerDList<cAnsiStr, 0> *pList, const char *pszCtrl)
{
	cContDListNode<cAnsiStr, 0> *this; // [sp+8h] [bp-8h]@6
	cContDListNode<cAnsiStr, 0> *pNode; // [sp+Ch] [bp-4h]@1

	for (pNode = cDList<cContDListNode<cAnsiStr_0>_0>::GetFirst(&pList->baseclass_0);
		pNode && operator__(&pNode->item, pszCtrl);
		pNode = cDListNode<cContDListNode<cAnsiStr_0>_0>::GetNext(&pNode->baseclass_0))
		;
	if (pNode)
	{
		this = cDList<cContDListNode<cAnsiStr_0>_0>::Remove(&pList->baseclass_0, pNode);
		if (this)
			cContDListNode<cAnsiStr_0>::_scalar_deleting_destructor_(this, 1u);
	}
}

//----- (008D6945) --------------------------------------------------------
char *__thiscall cIBInputMapper::Unbind(cIBInputMapper *this, char *control, char **var_name)
{
	char *result; // eax@2
	void *v4; // eax@8
	int v5; // [sp+0h] [bp-1ACh]@12
	cIBInputMapper *thisa; // [sp+4h] [bp-1A8h]@1
	sCmdCtrlEntry *pCmdCtrlEntry; // [sp+8h] [bp-1A4h]@6
	char controls[128]; // [sp+Ch] [bp-1A0h]@1
	char *cmd; // [sp+8Ch] [bp-120h]@3
	char pszCmd[256]; // [sp+90h] [bp-11Ch]@5
	char v11; // [sp+190h] [bp-1Ch]@10
	char *ret_val; // [sp+194h] [bp-18h]@1
	char **tokens; // [sp+198h] [bp-14h]@10
	char *pStr; // [sp+19Ch] [bp-10h]@5
	int num_tokens; // [sp+1A0h] [bp-Ch]@8
	int active_toggle; // [sp+1A4h] [bp-8h]@14
	int num_controls; // [sp+1A8h] [bp-4h]@1

	thisa = this;
	**var_name = 0;
	ret_val = cIBInputMapper::DecomposeControl(this, control, (char(*)[32])controls, &num_controls);
	if (ret_val)
	{
		result = ret_val;
	}
	else
	{
		cIBInputMapper::RecomposeControl(thisa, thisa->m_misc_str, (char(*)[32])controls, num_controls);
		cmd = aatree<char>::Find(&thisa->m_control_binds, thisa->m_misc_str);
		if (cmd)
		{
			strcpy(pszCmd, cmd);
			pStr = strstr(pszCmd, " control: ");
			if (pStr)
			{
				*pStr = 0;
				pCmdCtrlEntry = cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>::Search(
					&g_CmdCtrlHash.baseclass_0.baseclass_0,
					pszCmd);
				if (pCmdCtrlEntry)
					RemoveCmdCtrlNode(&pCmdCtrlEntry->ctrlList, thisa->m_misc_str);
				v4 = cIBVariableManager::Tokenize(g_IB_variable_manager, cmd, &num_tokens, 1);
				tokens = (char **)v4;
				v11 = **(_BYTE **)v4;
				v5 = v11 == 43 || v11 == 61;
				active_toggle = v5;
				strcpy(*var_name, &(*tokens)[v5]);
				aatree<char>::Delete(&thisa->m_control_binds, thisa->m_misc_str, 1, 0);
				aatree<unsigned_char>::Delete(&g_input_down, thisa->m_misc_str, 1, 0);
				cIBVariableManager::FreeTokens(g_IB_variable_manager, tokens, num_tokens);
				result = 0;
			}
			else
			{
				result = g_err_msg_1[5];
			}
		}
		else
		{
			result = 0;
		}
	}
	return result;
}

//----- (008D6B0C) --------------------------------------------------------
char *__thiscall cIBInputMapper::PeekBind(cIBInputMapper *this, char *control, int strip_control)
{
	char *result; // eax@2
	cIBInputMapper *thisa; // [sp+0h] [bp-90h]@1
	char controls[128]; // [sp+4h] [bp-8Ch]@1
	char *cmd; // [sp+84h] [bp-Ch]@3
	char *ret_val; // [sp+88h] [bp-8h]@1
	int num_controls; // [sp+8Ch] [bp-4h]@1

	thisa = this;
	ret_val = cIBInputMapper::DecomposeControl(this, control, (char(*)[32])controls, &num_controls);
	if (ret_val)
	{
		result = ret_val;
	}
	else
	{
		cIBInputMapper::RecomposeControl(thisa, thisa->m_misc_str, (char(*)[32])controls, num_controls);
		cmd = aatree<char>::Find(&thisa->m_control_binds, thisa->m_misc_str);
		if (cmd)
		{
			if (strip_control)
				cIBInputMapper::StripControl(thisa, thisa->m_misc_str, cmd);
			result = thisa->m_misc_str;
		}
		else
		{
			result = 0;
		}
	}
	return result;
}

//----- (008D6BB3) --------------------------------------------------------
void __thiscall cIBInputMapper::TrapBind(cIBInputMapper *this, char *p_cmd, int(__cdecl *filter_cb)(char *, char *, void *), void(__cdecl *post_cb)(int), void *data)
{
	cIBInputMapper *thisa; // [sp+0h] [bp-10h]@1
	_Region **slab; // [sp+4h] [bp-Ch]@2
	Rect rect; // [sp+8h] [bp-8h]@2

	thisa = this;
	if (!this->m_trapping)
	{
		this->m_trapping = 1;
		rect.ul.x = 0;
		rect.ul.y = 0;
		rect.lr.x = grd_canvas->bm.w;
		rect.lr.y = grd_canvas->bm.h;
		mouse_get_xy(&g_prev_mousex, &g_prev_mousey);
		uiHideMouse(&rect);
		uiGetCurrentSlab((_ui_slab **)&slab);
		uiInstallRegionHandler(*slab, 0x1Du, cIBInputMapper::StaticTrapHandler, 0, &g_id);
		thisa->m_bind_cmd = p_cmd;
		thisa->m_filter_cb = filter_cb;
		thisa->m_post_cb = post_cb;
		thisa->m_filter_data = data;
		thisa->m_mod_states = 0;
	}
}

//----- (008D6C8A) --------------------------------------------------------
char __cdecl cIBInputMapper::StaticTrapHandler(_ui_event *p_event, _Region *p_reg, void *state)
{
	return cIBInputMapper::TrapHandler(g_IB_input_mapper, p_event);
}

//----- (008D6C9E) --------------------------------------------------------
char __thiscall cIBInputMapper::TrapHandler(cIBInputMapper *this, _ui_event *p_event)
{
	char result; // al@12
	int v3; // [sp+4h] [bp-188h]@4
	cIBInputMapper *thisa; // [sp+Ch] [bp-180h]@1
	char cmd[128]; // [sp+10h] [bp-17Ch]@58
	char **tokens; // [sp+90h] [bp-FCh]@58
	int num_tokens; // [sp+94h] [bp-F8h]@58
	char str[32]; // [sp+98h] [bp-F4h]@42
	char *v9; // [sp+B8h] [bp-D4h]@42
	_ui_event *event; // [sp+BCh] [bp-D0h]@41
	char butt_str[32]; // [sp+C0h] [bp-CCh]@36
	__int16 action; // [sp+E0h] [bp-ACh]@31
	_ui_event *mouse_event; // [sp+E4h] [bp-A8h]@31
	char *Source; // [sp+E8h] [bp-A4h]@36
	_ui_event *key_event; // [sp+ECh] [bp-A0h]@2
	int mask; // [sp+F0h] [bp-9Ch]@2
	int strip_shift; // [sp+F4h] [bp-98h]@6
	char *control; // [sp+F8h] [bp-94h]@6
	int bound; // [sp+FCh] [bp-90h]@56
	char bind_control[128]; // [sp+100h] [bp-8Ch]@17
	_Region **slab; // [sp+180h] [bp-Ch]@62
	Rect rect; // [sp+184h] [bp-8h]@62

	thisa = this;
	switch (p_event->type)
	{
	case 1u:
		key_event = p_event;
		mask = 0;
		v3 = this->m_mod_states & 8 || this->m_mod_states & 0x10;
		control = cIBInputMapper::GetRawControl(
			this,
			key_event->subtype,
			(this->m_mod_states & 4) != 0 ^ v3,
			&strip_shift);
		switch (key_event->subtype)
		{
		case 42:
		case 54:
			mask = 24;
			break;
		case 56:
		case 184:
			mask = 384;
			break;
		case 29:
		case 157:
			mask = 96;
			break;
		default:
			break;
		}
		if (control || mask)
		{
			if (!key_event->data[0])
			{
				if (mask)
				{
					if (thisa->m_mod_states & 0x80)
					{
						strcpy(bind_control, "alt");
					}
					else
					{
						if (thisa->m_mod_states & 0x20)
						{
							strcpy(bind_control, "ctrl");
						}
						else
						{
							if (thisa->m_mod_states & 8)
								strcpy(bind_control, "shift");
						}
					}
				}
				else
				{
					strcpy(bind_control, control);
					if (thisa->m_mod_states & 0x80)
						strcat(bind_control, "+alt");
					if (thisa->m_mod_states & 0x20)
						strcat(bind_control, "+ctrl");
					if (thisa->m_mod_states & 8 && !strip_shift)
						strcat(bind_control, "+shift");
				}
				goto LABEL_56;
			}
			thisa->m_mod_states |= mask;
			result = 1;
		}
		else
		{
			result = 1;
		}
		break;
	case 4u:
		mouse_event = p_event;
		action = p_event->subtype & 0xFF;
		if (action)
		{
			if (mouse_event->data[5] && action == 128)
			{
				strcpy(bind_control, "mouse_wheel");
				goto LABEL_56;
			}
			sprintf(butt_str, "%d", action);
			Source = aatree<char>::Find(&stru_EAC700, butt_str);
			if (Source)
			{
				strcpy(bind_control, Source);
				goto LABEL_56;
			}
			result = 1;
		}
		else
		{
			result = 1;
		}
		break;
	case 8u:
		result = 1;
		break;
	case 0x10u:
		event = p_event;
		if (p_event->subtype == 3)
		{
			sprintf(str, "joy%d", event->data[0] + 1);
			v9 = aatree<char>::Find(&stru_EAC710, str);
			if (v9)
			{
				strcpy(bind_control, v9);
				goto LABEL_56;
			}
			result = 1;
		}
		else
		{
			if (event->data[0] == 2)
			{
				if (*(_WORD *)&event->data[3] == 1)
				{
					strcpy(bind_control, "joy_hatup");
				}
				else
				{
					if (*(_WORD *)&event->data[3] == -1)
					{
						strcpy(bind_control, "joy_hatdn");
					}
					else
					{
						if (*(_WORD *)&event->data[1] == -1)
						{
							strcpy(bind_control, "joy_hatlt");
						}
						else
						{
							if (*(_WORD *)&event->data[1] == 1)
								strcpy(bind_control, "joy_hatrt");
						}
					}
				}
				goto LABEL_56;
			}
			result = 1;
		}
		break;
	default:
	LABEL_56 :
		bound = 0;
			 if (!thisa->m_filter_cb || thisa->m_filter_cb(bind_control, thisa->m_bind_cmd, thisa->m_filter_data))
			 {
				 bound = 1;
				 strcpy(cmd, "bind ");
				 strcat(cmd, bind_control);
				 strcat(cmd, " ");
				 tokens = cIBVariableManager::Tokenize(g_IB_variable_manager, thisa->m_bind_cmd, &num_tokens, 0);
				 cIBVariableManager::FreeTokens(g_IB_variable_manager, tokens, num_tokens);
				 if (num_tokens <= 1)
				 {
					 strcat(cmd, thisa->m_bind_cmd);
				 }
				 else
				 {
					 strcat(cmd, "\"");
					 strcat(cmd, thisa->m_bind_cmd);
					 strcat(cmd, "\"");
				 }
				 cIBVariableManager::Cmd(g_IB_variable_manager, cmd, 0);
			 }
			 thisa->m_trapping = 0;
			 rect.ul.x = 0;
			 rect.ul.y = 0;
			 rect.lr.x = grd_canvas->bm.w;
			 rect.lr.y = grd_canvas->bm.h;
			 uiShowMouse(&rect);
			 mouse_put_xy(g_prev_mousex, g_prev_mousey);
			 uiGetCurrentSlab((_ui_slab **)&slab);
			 uiRemoveRegionHandler(*slab, g_id);
			 thisa->m_mod_states = 0;
			 if (thisa->m_post_cb)
				 thisa->m_post_cb(bound);
			 result = 1;
			 break;
	}
	return result;
}

//----- (008D7424) --------------------------------------------------------
char *__thiscall cIBInputMapper::GetControlFromCmdStart(cIBInputMapper *this, char *pszCmd, char *pszCtrlBuf)
{
	const char *v3; // eax@3
	cIBInputMapper *thisa; // [sp+0h] [bp-8h]@1
	sCmdCtrlEntry *pCmdCtrlEntry; // [sp+4h] [bp-4h]@1

	thisa = this;
	*pszCtrlBuf = 0;
	pCmdCtrlEntry = cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>::Search(
		&g_CmdCtrlHash.baseclass_0.baseclass_0,
		pszCmd);
	if (pCmdCtrlEntry)
	{
		thisa->m_pCtrlIterNode = cDList<cContDListNode<cAnsiStr_0>_0>::GetFirst(&pCmdCtrlEntry->ctrlList.baseclass_0);
		if (thisa->m_pCtrlIterNode)
		{
			v3 = cAnsiStr::operator char_const__(&thisa->m_pCtrlIterNode->item);
			strcpy(pszCtrlBuf, v3);
			thisa->m_pCtrlIterNode = cDListNode<cContDListNode<cAnsiStr_0>_0>::GetNext(&thisa->m_pCtrlIterNode->baseclass_0);
		}
	}
	return pszCtrlBuf;
}

//----- (008D74A8) --------------------------------------------------------
char *__thiscall cIBInputMapper::GetControlFromCmdNext(cIBInputMapper *this, char *pszCtrlBuf)
{
	const char *v2; // eax@2
	cIBInputMapper *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	*pszCtrlBuf = 0;
	if (this->m_pCtrlIterNode)
	{
		v2 = cAnsiStr::operator char_const__(&this->m_pCtrlIterNode->item);
		strcpy(pszCtrlBuf, v2);
		thisa->m_pCtrlIterNode = cDListNode<cContDListNode<cAnsiStr_0>_0>::GetNext(&thisa->m_pCtrlIterNode->baseclass_0);
	}
	return pszCtrlBuf;
}

//----- (008D74FF) --------------------------------------------------------
char *__thiscall cIBInputMapper::SaveBnd(cIBInputMapper *this, char *filename, char *header)
{
	char *result; // eax@2
	char **v4; // ST1C_4@8
	cIBInputMapper *thisa; // [sp+0h] [bp-54h]@1
	char *cmd; // [sp+4h] [bp-50h]@6
	FILE *fp; // [sp+8h] [bp-4Ch]@1
	char control_name[64]; // [sp+10h] [bp-44h]@6
	int num_tokens; // [sp+50h] [bp-4h]@8

	thisa = this;
	fp = fopen(filename, "wt");
	if (fp)
	{
		if (header)
			fprintf(fp, "%s\n\n", header);
		aatree<char>::ResetVisited(&thisa->m_control_binds, 0);
		while (1)
		{
			cmd = aatree<char>::GetNextInOrder(&thisa->m_control_binds, control_name);
			if (!cmd)
				break;
			if (*cmd)
			{
				cIBInputMapper::StripControl(thisa, thisa->m_misc_str, cmd);
				v4 = cIBVariableManager::Tokenize(g_IB_variable_manager, thisa->m_misc_str, &num_tokens, 0);
				cIBVariableManager::FreeTokens(g_IB_variable_manager, v4, num_tokens);
				if (num_tokens <= 1)
					fprintf(fp, "bind %s %s\r\n", control_name, thisa->m_misc_str);
				else
					fprintf(fp, "bind %s \"%s\"\r\n", control_name, thisa->m_misc_str);
			}
		}
		fclose(fp);
		result = 0;
	}
	else
	{
		result = g_err_msg_1[4];
	}
	return result;
}

//----- (008D7620) --------------------------------------------------------
void __thiscall cIBInputMapper::PollAllKeys(cIBInputMapper *this)
{
	char v1; // al@3
	cIBInputMapper *thisa; // [sp+0h] [bp-14h]@1
	signed int i; // [sp+4h] [bp-10h]@1
	kbs_event keycode; // [sp+8h] [bp-Ch]@1
	__int16 cooked; // [sp+Ch] [bp-8h]@3
	char results; // [sp+10h] [bp-4h]@3

	thisa = this;
	cIBInputMapper::FlushKeys(this);
	keycode.state = 0;
	for (i = 0; i < 224; ++i)
	{
		keycode.code = i;
		kb_cook_real(keycode, (unsigned __int16 *)&cooked, &results, 0);
		v1 = kb_state(cooked);
		cIBInputMapper::ProcessRawKey(thisa, i, v1, 1);
	}
	kbd_modifier_state = 0;
}
// EA2980: using guessed type int kbd_modifier_state;

//----- (008D7699) --------------------------------------------------------
void __thiscall cIBInputMapper::FlushKeys(cIBInputMapper *this)
{
	char *down; // [sp+4h] [bp-4h]@2

	kb_flush(this);
	aatree<unsigned_char>::ResetVisited(&g_input_down, 0);
	do
	{
		down = aatree<unsigned_char>::GetNextInOrder(&g_input_down, 0);
		if (down)
			*down = 0;
	} while (down);
}

//----- (008D76D8) --------------------------------------------------------
char __cdecl cIBInputMapper::InputBindingHandler(_ui_event *p_event, _Region *p_reg, void *state)
{
	char ret_val; // [sp+Ch] [bp-8h]@1
	unsigned int valid_events; // [sp+10h] [bp-4h]@1

	ret_val = 0;
	valid_events = g_IB_input_mapper->m_valid_events;
	switch (p_event->type)
	{
	case 2u:
		if (valid_events & 2)
			ret_val = cIBInputMapper::ProcessCookedKey(g_IB_input_mapper, p_event->subtype);
		break;
	case 1u:
		if (valid_events & 1)
			ret_val = cIBInputMapper::ProcessRawKey(g_IB_input_mapper, p_event->subtype, p_event->data[0], 0);
		break;
	case 4u:
		if (valid_events & 4)
			ret_val = cIBInputMapper::ProcessMouseButton(g_IB_input_mapper, (_ui_mouse_event *)p_event);
		break;
	case 8u:
		if (valid_events & 8)
			ret_val = cIBInputMapper::ProcessMouseMove(g_IB_input_mapper, (_ui_mouse_event *)p_event);
		break;
	case 0x10u:
		if (valid_events & 0x10)
			ret_val = cIBInputMapper::ProcessJoystick(g_IB_input_mapper, (_ui_joy_event *)p_event);
		break;
	default:
		return ret_val;
	}
	return ret_val;
}

//----- (008D7801) --------------------------------------------------------
cContDListNode<sControlDown, 0> *__cdecl GetControlDownNode(char *pControl)
{
	cContDListNode<sControlDown, 0> *pNode; // [sp+0h] [bp-4h]@1

	for (pNode = cDList<cContDListNode<sControlDown_0>_0>::GetFirst(&g_ctrldown_list.baseclass_0);
		pNode && operator__(&pNode->item.control, pControl);
		pNode = cDListNode<cContDListNode<sControlDown_0>_0>::GetNext(&pNode->baseclass_0))
		;
	return pNode;
}

//----- (008D7845) --------------------------------------------------------
int __thiscall cIBInputMapper::SendButtonCmd(cIBInputMapper *this, char *control, int down, int mod)
{
	int v4; // eax@5
	int v6; // [sp+4h] [bp-30h]@5
	cIBInputMapper *thisa; // [sp+8h] [bp-2Ch]@1
	cContDListNode<sControlDown, 0> *v8; // [sp+10h] [bp-24h]@16
	void *v9; // [sp+14h] [bp-20h]@4
	signed int mask; // [sp+18h] [bp-1Ch]@26
	char *v11; // [sp+1Ch] [bp-18h]@15
	cContDListNode<sControlDown, 0> *Node; // [sp+20h] [bp-14h]@15
	char *cmd; // [sp+28h] [bp-Ch]@2
	int *already_down; // [sp+2Ch] [bp-8h]@1
	int ret_val; // [sp+30h] [bp-4h]@1

	thisa = this;
	ret_val = 1;
	already_down = (int *)aatree<unsigned_char>::Find(&g_input_down, control);
	if (down)
	{
		cmd = aatree<char>::Find(&thisa->m_control_binds, control);
		if (cmd)
		{
			if (!GetControlDownNode(control))
			{
				v9 = j__new(0x18u, "x:\\prj\\tech\\libsrc\\inputbnd\\ibmapper.cpp", 893);
				if (v9)
				{
					cContDListNode<sControlDown_0>::cContDListNode<sControlDown_0>((cContDListNode<sControlDown, 0> *)v9);
					v6 = v4;
				}
				else
				{
					v6 = 0;
				}
				cAnsiStr::operator_((cAnsiStr *)(v6 + 8), control);
				*(_DWORD *)(v6 + 20) = cmd;
				cDList<cContDListNode<sControlDown_0>_0>::Prepend(
					&g_ctrldown_list.baseclass_0,
					(cContDListNode<sControlDown, 0> *)v6);
			}
			cIBVariableManager::Cmd(g_IB_variable_manager, cmd, *(_BYTE *)already_down);
		}
		else
		{
			ret_val = 0;
		}
		if (already_down)
			*(_BYTE *)already_down = 1;
	}
	else
	{
		if (already_down)
			*(_BYTE *)already_down = 0;
		Node = GetControlDownNode(control);
		v11 = 0;
		if (Node)
		{
			v11 = Node->item.pCmd;
			v8 = cDList<cContDListNode<sControlDown_0>_0>::Remove(&g_ctrldown_list.baseclass_0, Node);
			if (v8)
				cContDListNode<sControlDown_0>::_scalar_deleting_destructor_(v8, 1u);
		}
		if (v11)
		{
			if (*v11 == 43)
			{
				*v11 = 45;
				cIBVariableManager::Cmd(g_IB_variable_manager, v11, *(_BYTE *)already_down);
				*v11 = 43;
			}
			else
			{
				if (*v11 == 45)
				{
					*v11 = 43;
					cIBVariableManager::Cmd(g_IB_variable_manager, v11, *(_BYTE *)already_down);
					*v11 = 45;
				}
			}
		}
		else
		{
			ret_val = 0;
		}
	}
	if (mod)
	{
		mask = 0;
		if (strcmp("shift", control))
		{
			if (strcmp("lshift", control))
			{
				if (strcmp("rshift", control))
				{
					if (strcmp("alt", control))
					{
						if (strcmp("lalt", control))
						{
							if (strcmp("ralt", control))
							{
								if (strcmp("ctrl", control))
								{
									if (strcmp("lctrl", control))
									{
										if (!strcmp("caps_lock", control))
										{
											thisa->m_mod_states ^= 4u;
											cIBInputMapper::SendButtonCmd(thisa, "shift", (thisa->m_mod_states & 4) != 0, 0);
										}
									}
									else
									{
										mask = 32;
									}
								}
								else
								{
									mask = 96;
								}
							}
							else
							{
								mask = 256;
							}
						}
						else
						{
							mask = 128;
						}
					}
					else
					{
						mask = 384;
					}
				}
				else
				{
					mask = 16;
				}
			}
			else
			{
				mask = 8;
			}
		}
		else
		{
			mask = 24;
		}
		if (down)
			thisa->m_mod_states |= mask;
		else
			thisa->m_mod_states &= ~mask;
	}
	return ret_val;
}

//----- (008D7B9B) --------------------------------------------------------
int __thiscall cIBInputMapper::ProcessRawKey(cIBInputMapper *this, __int16 scancode, char action, int polling)
{
	int result; // eax@3
	int v5; // [sp+0h] [bp-18h]@39
	cIBInputMapper *thisa; // [sp+8h] [bp-10h]@1
	int strip_shift; // [sp+Ch] [bp-Ch]@41
	char *down; // [sp+10h] [bp-8h]@43
	char *control; // [sp+14h] [bp-4h]@41

	thisa = this;
	switch (scancode)
	{
	case 42:
		if (this->m_mod_states & 4)
		{
			result = 0;
		}
		else
		{
			if (this->m_mod_states & 8 && action)
				result = 0;
			else
				result = cIBInputMapper::ProcessRawMod(this, "lshift", action, 0);
		}
		break;
	case 54:
		if (this->m_mod_states & 4)
		{
			result = 0;
		}
		else
		{
			if (this->m_mod_states & 0x10 && action)
				result = 0;
			else
				result = cIBInputMapper::ProcessRawMod(this, "rshift", action, 0);
		}
		break;
	case 29:
		if (this->m_mod_states & 0x20 && action)
			result = 0;
		else
			result = cIBInputMapper::ProcessRawMod(this, "lctrl", action, 0);
		break;
	case 157:
		if (this->m_mod_states & 0x40 && action)
			result = 0;
		else
			result = cIBInputMapper::ProcessRawMod(this, "rctrl", action, 0);
		break;
	case 56:
		if (this->m_mod_states & 0x80 && action)
			result = 0;
		else
			result = cIBInputMapper::ProcessRawMod(this, "lalt", action, 0);
		break;
	case 184:
		if (this->m_mod_states & 0x100 && action)
			result = 0;
		else
			result = cIBInputMapper::ProcessRawMod(this, "ralt", action, 0);
		break;
	case 58:
		if (this->m_mod_states & 0x10 || this->m_mod_states & 8)
		{
			result = 0;
		}
		else
		{
			if (action || polling)
				result = 0;
			else
				result = cIBInputMapper::ProcessRawMod(this, "caps_lock", 0, 1);
		}
		break;
	default:
		v5 = this->m_mod_states & 8 || this->m_mod_states & 0x10;
		control = cIBInputMapper::GetRawControl(this, scancode, (this->m_mod_states & 4) != 0 ^ v5, &strip_shift);
		if (control)
		{
			down = aatree<unsigned_char>::Find(&g_input_down, control);
			if (down)
			{
				if (*down)
					*down = 0;
				else
					*down = action;
			}
			result = cIBInputMapper::AttachMods(thisa, control, action, strip_shift);
		}
		else
		{
			result = 0;
		}
		break;
	}
	return result;
}

//----- (008D7F33) --------------------------------------------------------
char *__thiscall cIBInputMapper::GetRawControl(cIBInputMapper *this, __int16 scancode, int shifted, int *strip_shift)
{
	__int16 v5; // [sp+2h] [bp-32h]@2
	__int16 cnv; // [sp+Ch] [bp-28h]@4
	unsigned __int16 cnva; // [sp+Ch] [bp-28h]@14
	char key_str[32]; // [sp+10h] [bp-24h]@16
	__int16 unshifted_key; // [sp+30h] [bp-4h]@1

	unshifted_key = kb_cnv_table[3 * scancode];
	if (shifted)
		v5 = word_B25882[3 * scancode];
	else
		v5 = unshifted_key;
	cnv = v5;
	*strip_shift = 0;
	if (shifted)
	{
		if (v5 & 0x800 || (signed int)(unsigned __int8)v5 < 65 || (signed int)(unsigned __int8)v5 > 90)
		{
			if (v5 != unshifted_key && !(v5 & 0x4000) && (unsigned __int8)v5 != 9)
				*strip_shift = 1;
		}
		else
		{
			cnv = v5 + 32;
		}
	}
	if (cnv & 0x4000)
		cnva = scancode | 0x800;
	else
		cnva = cnv & 0x28FF;
	sprintf(key_str, "%d", cnva);
	return aatree<char>::Find(&g_input_controls, key_str);
}
// B25880: using guessed type __int16 kb_cnv_table[];
// B25882: using guessed type __int16 word_B25882[];

//----- (008D8079) --------------------------------------------------------
int __thiscall cIBInputMapper::AttachMods(cIBInputMapper *this, char *control, char action, int strip_shift)
{
	signed int v5; // [sp+0h] [bp-5Ch]@36
	int v6; // [sp+4h] [bp-58h]@23
	int v7; // [sp+8h] [bp-54h]@19
	int v8; // [sp+Ch] [bp-50h]@15
	int v9; // [sp+10h] [bp-4Ch]@11
	int v10; // [sp+14h] [bp-48h]@7
	int v11; // [sp+18h] [bp-44h]@3
	cIBInputMapper *thisa; // [sp+1Ch] [bp-40h]@1
	char *ret; // [sp+20h] [bp-3Ch]@68
	int dummy; // [sp+24h] [bp-38h]@68
	__int16 *key; // [sp+28h] [bp-34h]@68
	char *down; // [sp+2Ch] [bp-30h]@56
	int j; // [sp+30h] [bp-2Ch]@63
	char mod_mask; // [sp+34h] [bp-28h]@25
	char cur_mask; // [sp+38h] [bp-24h]@49
	int i; // [sp+3Ch] [bp-20h]@25
	int ret_val; // [sp+40h] [bp-1Ch]@28
	int mod_loop_num[3]; // [sp+44h] [bp-18h]@30
	int s; // [sp+50h] [bp-Ch]@43
	int c; // [sp+54h] [bp-8h]@45
	int a; // [sp+58h] [bp-4h]@47

	thisa = this;
	v11 = this->m_mod_states & 8 || this->m_mod_states & 0x10;
	v10 = ((this->m_mod_states & 4) != 0) != v11 && !strip_shift;
	valid_mod_fields[0][0] = v10;
	v9 = ((this->m_mod_states & 4) != 0) != ((this->m_mod_states & 8) != 0) && !strip_shift;
	valid_mod_fields[0][1] = v9;
	v8 = ((this->m_mod_states & 4) != 0) != ((this->m_mod_states & 0x10) != 0) && !strip_shift;
	valid_mod_fields[0][2] = v8;
	v7 = this->m_mod_states & 0x20 || this->m_mod_states & 0x40;
	valid_mod_fields[1][0] = v7;
	valid_mod_fields[1][1] = (this->m_mod_states & 0x20) != 0;
	valid_mod_fields[1][2] = (this->m_mod_states & 0x40) != 0;
	v6 = this->m_mod_states & 0x80 || this->m_mod_states & 0x100;
	valid_mod_fields[2][0] = v6;
	valid_mod_fields[2][1] = (this->m_mod_states & 0x80) != 0;
	valid_mod_fields[2][2] = (this->m_mod_states & 0x100) != 0;
	mod_mask = 0;
	for (i = 0; i < 3; ++i)
		mod_mask |= valid_mod_fields[i][0] << i;
	ret_val = 0;
	for (i = 0; i < 3; ++i)
		mod_loop_num[i] = valid_mod_fields[i][0] != 0 ? 3 : 1;
	for (i = 0;; ++i)
	{
		if (i < 3)
		{
			if (!i)
			{
				v5 = this->m_mod_states & 8 || this->m_mod_states & 0x10 ? 1 : 0;
				if (((this->m_mod_states & 4) != 0) == v5)
					continue;
			}
			if (i && !valid_mod_fields[i][0])
				continue;
		}
		break;
	}
	while (i < 3)
	{
		for (s = 0; s < mod_loop_num[0]; ++s)
		{
			for (c = 0; c < mod_loop_num[1]; ++c)
			{
				for (a = 0; a < mod_loop_num[2]; ++a)
				{
					cur_mask = LOBYTE(valid_mod_fields[0][s]);
					cur_mask |= 2 * valid_mod_fields[1][c];
					cur_mask |= 4 * valid_mod_fields[2][a];
					if (cur_mask == mod_mask)
					{
						strcpy(final_control, control);
						if (valid_mod_fields[2][a])
							strcat(final_control, g_mods[2][a]);
						if (valid_mod_fields[1][c])
							strcat(final_control, g_mods[1][c]);
						if (valid_mod_fields[0][s])
							strcat(final_control, (const char *)g_mods + 8 * s);
						down = aatree<unsigned_char>::Find(&g_input_down, final_control);
						if (!action || down)
						{
							ret_val = cIBInputMapper::SendButtonCmd(thisa, final_control, (unsigned __int8)action, 0);
							if (action)
								return ret_val;
						}
					}
				}
			}
		}
		for (j = 0; j < 3; ++j)
			valid_mod_fields[i][j] = 0;
		if (strip_shift)
		{
			if (!i)
			{
				key = aatree<short>::Find(&g_input_codes, control);
				ret = cIBInputMapper::GetRawControl(thisa, g_shift_to_scan[*key], 0, &dummy);
				if (ret)
					control = ret;
			}
		}
		++i;
		while (i < 3 && !valid_mod_fields[i][0])
			++i;
		++i;
	}
	return cIBInputMapper::SendButtonCmd(thisa, control, (unsigned __int8)action, 0);
}

//----- (008D85B3) --------------------------------------------------------
int __thiscall cIBInputMapper::ProcessRawMod(cIBInputMapper *this, char *mod, char action, int general)
{
	int result; // eax@7
	cIBInputMapper *thisa; // [sp+0h] [bp-D8h]@1
	char *v6; // [sp+4h] [bp-D4h]@2
	char controls[128]; // [sp+8h] [bp-D0h]@12
	int i; // [sp+88h] [bp-50h]@12
	char *ret; // [sp+8Ch] [bp-4Ch]@9
	char *down; // [sp+90h] [bp-48h]@10
	char control[64]; // [sp+94h] [bp-44h]@9
	int num_controls; // [sp+D4h] [bp-4h]@12

	thisa = this;
	if (!general)
	{
		*mod = *mod != 114 ? 114 : 108;
		v6 = aatree<unsigned_char>::Find(&g_input_down, mod);
		if (!v6 || !*v6)
			cIBInputMapper::ProcessRawMod(thisa, mod + 1, action, 1);
		*mod = *mod != 114 ? 114 : 108;
	}
	cIBInputMapper::SendButtonCmd(thisa, mod, (unsigned __int8)action, 1);
	if (strcmp(mod, "caps_lock"))
	{
		aatree<char>::ResetVisited(&thisa->m_control_binds, 0);
		if (!action)
		{
		LABEL_9:
			while (1)
			{
				ret = aatree<char>::GetNextInOrder(&thisa->m_control_binds, control);
				if (!ret)
					break;
				down = aatree<unsigned_char>::Find(&g_input_down, control);
				if (down && *down)
				{
					cIBInputMapper::DecomposeControl(thisa, control, (char(*)[32])controls, &num_controls);
					for (i = 0; i < num_controls; ++i)
					{
						if (!strcmp(&controls[32 * i], mod))
						{
							cIBInputMapper::SendButtonCmd(thisa, control, 0, 0);
							goto LABEL_9;
						}
					}
				}
			}
		}
		result = 0;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008D874D) --------------------------------------------------------
char __thiscall cIBInputMapper::GetControlMask(cIBInputMapper *this, char(*controls)[32], int num_controls)
{
	char mask; // [sp+4h] [bp-8h]@1
	int i; // [sp+8h] [bp-4h]@1

	mask = 0;
	for (i = 1; i < num_controls; ++i)
	{
		if (strcmp(&(*controls)[32 * i], "shift")
			&& strcmp(&(*controls)[32 * i], "lshift")
			&& strcmp(&(*controls)[32 * i], "rshift"))
		{
			if (strcmp(&(*controls)[32 * i], "ctrl")
				&& strcmp(&(*controls)[32 * i], "lctrl")
				&& strcmp(&(*controls)[32 * i], "rctrl"))
			{
				if (!strcmp(&(*controls)[32 * i], "alt")
					|| !strcmp(&(*controls)[32 * i], "lalt")
					|| !strcmp(&(*controls)[32 * i], "ralt"))
					mask |= 4u;
			}
			else
			{
				mask |= 2u;
			}
		}
		else
		{
			mask |= 1u;
		}
	}
	return mask;
}

//----- (008D88AC) --------------------------------------------------------
char __thiscall cIBInputMapper::GetStateMask(cIBInputMapper *this)
{
	char mask; // [sp+4h] [bp-4h]@1

	mask = 0;
	if (this->m_mod_states & 8 || this->m_mod_states & 0x10)
		mask = 1;
	if (this->m_mod_states & 0x80 || this->m_mod_states & 0x100)
		mask |= 2u;
	if (this->m_mod_states & 0x20 || this->m_mod_states & 0x40)
		mask |= 4u;
	return mask;
}

//----- (008D893F) --------------------------------------------------------
int __thiscall cIBInputMapper::ProcessCookedKey(cIBInputMapper *this, __int16 code)
{
	int result; // eax@5
	cIBInputMapper *thisa; // [sp+0h] [bp-34h]@1
	signed int letter_upp; // [sp+4h] [bp-30h]@1
	unsigned __int16 key; // [sp+8h] [bp-2Ch]@1
	char key_str[33]; // [sp+Ch] [bp-28h]@4
	char *control; // [sp+30h] [bp-4h]@4

	thisa = this;
	key = code & 0xE8FF;
	letter_upp = 0;
	if ((code & 0xE8FF) >= 65 && (code & 0xE8FF) <= 90)
	{
		key += 32;
		letter_upp = 1;
	}
	sprintf(key_str, "%d", key);
	control = aatree<char>::Find(&g_input_controls, key_str);
	if (control)
	{
		strcpy(key_str, control);
		if ((code & 0x400) == 1024)
			strcat(key_str, "+alt");
		if ((code & 0x200) == 512)
			strcat(key_str, "+ctrl");
		if ((code & 0x1000) == 4096 || letter_upp)
			strcat(key_str, "+shift");
		result = cIBInputMapper::SendButtonCmd(thisa, key_str, (code & 0x100) != 0, 0);
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008D8A6C) --------------------------------------------------------
int __thiscall cIBInputMapper::ProcessMouseButton(cIBInputMapper *this, _ui_mouse_event *event)
{
	int result; // eax@2
	int v3; // [sp+0h] [bp-80h]@22
	cIBInputMapper *thisa; // [sp+4h] [bp-7Ch]@1
	char final[64]; // [sp+8h] [bp-78h]@20
	int action_bit; // [sp+48h] [bp-38h]@9
	int i; // [sp+4Ch] [bp-34h]@6
	char butt_str[32]; // [sp+50h] [bp-30h]@10
	__int16 action; // [sp+70h] [bp-10h]@1
	int down; // [sp+74h] [bp-Ch]@3
	int isMouseWheel; // [sp+78h] [bp-8h]@3
	char *control; // [sp+7Ch] [bp-4h]@10

	thisa = this;
	action = event->action;
	if (action)
	{
		isMouseWheel = 0;
		down = 1;
		if (event->wheel && action & 0x80)
		{
			action &= 0x7Fu;
			isMouseWheel = 1;
		}
		for (i = 0; i < 16; ++i)
		{
			action_bit = 1 << i;
			if (action & (1 << i))
			{
				sprintf(butt_str, "%d", action_bit);
				control = aatree<char>::Find(&stru_EAC700, butt_str);
				if (control)
				{
					down = 1;
					if (cIBInputMapper::SendButtonCmd(thisa, control, 1, 0))
						return 1;
				}
				else
				{
					down = 0;
					sprintf(butt_str, "%d", action_bit >> 1);
					control = aatree<char>::Find(&stru_EAC700, butt_str);
					if (control && cIBInputMapper::SendButtonCmd(thisa, control, down, 0))
						return 1;
				}
			}
		}
		if (isMouseWheel && (control = aatree<char>::Find(&thisa->m_control_binds, "mouse_wheel")) != 0)
		{
			cIBInputMapper::StripControl(thisa, final, control);
			sprintf(butt_str, " %d", event->wheel);
			strcat(final, butt_str);
			cIBVariableManager::Cmd(g_IB_variable_manager, final, 0);
			result = 1;
		}
		else
		{
			if (control)
				v3 = cIBInputMapper::SendButtonCmd(thisa, control, down, 0);
			else
				v3 = 0;
			result = v3;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008D8C4B) --------------------------------------------------------
int __thiscall cIBInputMapper::ProcessMouseMove(cIBInputMapper *this, _ui_mouse_event *event)
{
	char v2; // ST24_1@1
	float v3; // ST20_4@10
	float v4; // ST40_4@12
	aatree<char> *thisa; // [sp+10h] [bp-2Ch]@1
	char *cmd; // [sp+14h] [bp-28h]@9
	char *cmda; // [sp+14h] [bp-28h]@11
	__int16 y; // [sp+20h] [bp-1Ch]@1
	__int16 x; // [sp+24h] [bp-18h]@1
	__int16 res_y; // [sp+30h] [bp-Ch]@1
	__int16 res_x; // [sp+34h] [bp-8h]@1

	thisa = (aatree<char> *)this;
	res_x = grd_canvas->bm.w;
	res_y = grd_canvas->bm.h;
	v2 = mouseMask;
	mouseMask &= 0xFEu;
	mouse_put_xy(res_x >> 1, res_y >> 1);
	mouseMask = v2;
	x = event->pos.x;
	y = event->pos.y;
	if (event->pos.x >= 0)
	{
		if (x > res_x)
			x = res_x;
	}
	else
	{
		x = 0;
	}
	if (y >= 0)
	{
		if (y > res_y)
			y = res_y;
	}
	else
	{
		y = 0;
	}
	cmd = aatree<char>::Find(thisa, "mouse_axisx");
	if (cmd)
	{
		cIBInputMapper::StripControl((cIBInputMapper *)thisa, final, cmd);
		v3 = (double)((signed int)x - (signed int)(signed __int16)(res_x >> 1));
		sprintf(str_1, " %8.8f", v3);
		strcat(final, str_1);
		cIBVariableManager::Cmd(g_IB_variable_manager, final, 0);
	}
	cmda = aatree<char>::Find(thisa, "mouse_axisy");
	if (cmda)
	{
		cIBInputMapper::StripControl((cIBInputMapper *)thisa, final, cmda);
		v4 = (double)((signed int)y - (signed int)(signed __int16)(res_y >> 1));
		sprintf(str_1, " %8.8f", -v4);
		strcat(final, str_1);
		cIBVariableManager::Cmd(g_IB_variable_manager, final, 0);
	}
	return 0;
}
// B254D9: using guessed type char mouseMask;

//----- (008D8E0E) --------------------------------------------------------
void __thiscall cIBInputMapper::StripSendDoubleCmd(cIBInputMapper *this, char *control, long double a)
{
	cIBInputMapper *thisa; // [sp+0h] [bp-8h]@1
	char *cmd; // [sp+4h] [bp-4h]@1

	thisa = this;
	cmd = aatree<char>::Find(&this->m_control_binds, control);
	if (cmd)
	{
		sprintf(str_0, " %8.8f", *(_QWORD *)&a);
		cIBInputMapper::StripControl(thisa, final_1, cmd);
		strcat(final_1, str_0);
		cIBVariableManager::Cmd(g_IB_variable_manager, final_1, 0);
	}
}

//----- (008D8E81) --------------------------------------------------------
int __thiscall cIBInputMapper::ProcessJoystick(cIBInputMapper *this, _ui_joy_event *event)
{
	int result; // eax@4
	cIBInputMapper *thisa; // [sp+0h] [bp-48h]@1
	long double z; // [sp+4h] [bp-44h]@12
	long double r; // [sp+Ch] [bp-3Ch]@12
	long double y; // [sp+14h] [bp-34h]@8
	long double x; // [sp+1Ch] [bp-2Ch]@8
	char str[32]; // [sp+24h] [bp-24h]@3
	char *control; // [sp+44h] [bp-4h]@3

	thisa = this;
	if (event->action != 1 && event->action != 3)
	{
		if (!event->action)
		{
			if (event->joynum)
			{
				if (event->joynum == 1)
				{
					r = ShortScaleDouble(event->joypos.x);
					z = ShortScaleDouble(event->joypos.y);
					if (thisa->m_joyproc)
						thisa->m_joyproc->vfptr->ProcessZR(thisa->m_joyproc, &z, &r);
					cIBInputMapper::StripSendDoubleCmd(thisa, "joy_axisz", z);
					cIBInputMapper::StripSendDoubleCmd(thisa, "joy_axisr", r);
				}
				else
				{
					if (event->joynum == 2)
					{
						if (event->joypos.y == 1)
						{
							cIBInputMapper::SendButtonCmd(this, "joy_hatup", 1, 0);
						}
						else
						{
							if (event->joypos.y == -1)
							{
								cIBInputMapper::SendButtonCmd(this, "joy_hatdn", 1, 0);
							}
							else
							{
								cIBInputMapper::SendButtonCmd(this, "joy_hatup", 0, 0);
								cIBInputMapper::SendButtonCmd(thisa, "joy_hatdn", 0, 0);
							}
						}
						if (event->joypos.x == -1)
						{
							cIBInputMapper::SendButtonCmd(thisa, "joy_hatlt", 1, 0);
						}
						else
						{
							if (event->joypos.x == 1)
							{
								cIBInputMapper::SendButtonCmd(thisa, "joy_hatrt", 1, 0);
							}
							else
							{
								cIBInputMapper::SendButtonCmd(thisa, "joy_hatlt", 0, 0);
								cIBInputMapper::SendButtonCmd(thisa, "joy_hatrt", 0, 0);
							}
						}
					}
				}
			}
			else
			{
				x = ShortScaleDouble(event->joypos.x);
				y = ShortScaleDouble(event->joypos.y);
				if (thisa->m_joyproc)
					(**(void(__thiscall ***)(cIBJoyAxisProcess *, long double *, long double *))thisa->m_joyproc)(
					thisa->m_joyproc,
					&x,
					&y);
				cIBInputMapper::StripSendDoubleCmd(thisa, "joy_axisx", x);
				cIBInputMapper::StripSendDoubleCmd(thisa, "joy_axisy", y);
			}
		}
		result = 1;
	}
	else
	{
		sprintf(str, "joy%d", event->joynum + 1);
		control = aatree<char>::Find(&stru_EAC710, str);
		if (control)
			result = cIBInputMapper::SendButtonCmd(thisa, control, event->action == 3, 0);
		else
			result = 0;
	}
	return result;
}

//----- (008D9107) --------------------------------------------------------
long double __cdecl ShortScaleDouble(__int16 a)
{
	return (double)((signed int)a - 32767) * m + 1.0;
}

//----- (008D912A) --------------------------------------------------------
char *__thiscall cIBInputMapper::DecomposeControl(cIBInputMapper *this, char *control_str, char(*controls)[32], int *num_controls)
{
	int v4; // ST44_4@18
	int v5; // ST44_4@36
	int num; // [sp+1Ch] [bp-20h]@1
	int cmp; // [sp+20h] [bp-1Ch]@35
	int j; // [sp+24h] [bp-18h]@27
	char v10; // [sp+28h] [bp-14h]@5
	void *tmp_controls; // [sp+2Ch] [bp-10h]@1
	signed int i; // [sp+30h] [bp-Ch]@1
	int ia; // [sp+30h] [bp-Ch]@4
	int ib; // [sp+30h] [bp-Ch]@12
	signed int ic; // [sp+30h] [bp-Ch]@24
	int id; // [sp+30h] [bp-Ch]@47
	signed int ie; // [sp+30h] [bp-Ch]@51
	int if; // [sp+30h] [bp-Ch]@54
	char *ret_val; // [sp+34h] [bp-8h]@1

	num = 0;
	ret_val = 0;
	tmp_controls = j__new(0x10u, "x:\\prj\\tech\\libsrc\\inputbnd\\ibmapper.cpp", 1674);
	for (i = 0; i < 4; ++i)
		*((_DWORD *)tmp_controls + i) = j__new(0x20u, "x:\\prj\\tech\\libsrc\\inputbnd\\ibmapper.cpp", 1676);
	ia = 0;
	while (1)
	{
		v10 = *control_str;
		if (!*control_str)
			break;
		if (v10 == 43 && ia)
		{
			*(_BYTE *)(*((_DWORD *)tmp_controls + num++) + ia) = 0;
			if (num == 4)
				goto LABEL_12;
			ia = 0;
			++control_str;
			v10 = *control_str;
		}
		*(_BYTE *)(*((_DWORD *)tmp_controls + num) + ia++) = v10;
		++control_str;
	}
	*(_BYTE *)(*((_DWORD *)tmp_controls + num++) + ia) = 0;
LABEL_12:
	*num_controls = num;
	for (ib = 0; ib < num; ++ib)
	{
		if (strcmp(*((const char **)tmp_controls + ib), "alt")
			&& strcmp(*((const char **)tmp_controls + ib), "ctrl")
			&& strcmp(*((const char **)tmp_controls + ib), "shift"))
		{
			if (ib)
			{
				v4 = *(_DWORD *)tmp_controls;
				*(_DWORD *)tmp_controls = *((_DWORD *)tmp_controls + ib);
				*((_DWORD *)tmp_controls + ib) = v4;
			}
			break;
		}
		if (num != 1 && ib == num - 1)
			ret_val = g_err_msg_1[2];
	}
	for (ic = num; ic > 2 && !ret_val; --ic)
	{
		for (j = 1; j < ic - 1; ++j)
		{
			if (strcmp(*((const char **)tmp_controls + j), "alt")
				&& strcmp(*((const char **)tmp_controls + j), "ctrl")
				&& strcmp(*((const char **)tmp_controls + j), "shift")
				|| strcmp(*((const char **)tmp_controls + j + 1), "alt")
				&& strcmp(*((const char **)tmp_controls + j + 1), "ctrl")
				&& strcmp(*((const char **)tmp_controls + j + 1), "shift"))
			{
				ret_val = g_err_msg_1[1];
				break;
			}
			cmp = strcmp(*((const char **)tmp_controls + j), *((const char **)tmp_controls + j + 1));
			if (cmp <= 0)
			{
				if (!cmp)
				{
					ret_val = g_err_msg_1[3];
					break;
				}
			}
			else
			{
				v5 = *((_DWORD *)tmp_controls + j);
				*((_DWORD *)tmp_controls + j) = *((_DWORD *)tmp_controls + j + 1);
				*((_DWORD *)tmp_controls + j + 1) = v5;
			}
		}
	}
	if (num == 2
		&& strcmp(*((const char **)tmp_controls + 1), "alt")
		&& strcmp(*((const char **)tmp_controls + 1), "ctrl")
		&& strcmp(*((const char **)tmp_controls + 1), "shift"))
		ret_val = g_err_msg_1[1];
	for (id = 0; id < num && !ret_val; ++id)
		strcpy(&(*controls)[32 * id], *((const char **)tmp_controls + id));
	for (ie = 0; ie < 4; ++ie)
		operator delete(*((void **)tmp_controls + ie));
	operator delete(tmp_controls);
	for (if = num - 1; if >= 0 && !ret_val; --if)
	{
		if (!aatree<short>::Find(&g_input_codes, &(*controls)[32 * if]))
			return g_err_msg_1[0];
	}
	return ret_val;
}

//----- (008D95A6) --------------------------------------------------------
void __thiscall cIBInputMapper::RecomposeControl(cIBInputMapper *this, char *control_str, char(*controls)[32], int num_controls)
{
	int i; // [sp+4h] [bp-4h]@1

	*control_str = 0;
	for (i = 0; i < num_controls; ++i)
	{
		if (i)
			strcat(control_str, "+");
		strcat(control_str, &(*controls)[32 * i]);
	}
}


//----- (008D9606) --------------------------------------------------------
void __thiscall cIBInputMapper::StripControl(cIBInputMapper *this, char *dest, char *src)
{
	char **tokens; // [sp+4h] [bp-8h]@2
	int num_tokens; // [sp+8h] [bp-4h]@2

	*dest = 0;
	if (src)
	{
		tokens = cIBVariableManager::Tokenize(g_IB_variable_manager, src, &num_tokens, 0);
		if (num_tokens < 3 || strcmp("control:", tokens[num_tokens - 2]))
		{
			strcpy(dest, src);
			cIBVariableManager::FreeTokens(g_IB_variable_manager, tokens, num_tokens);
		}
		else
		{
			cIBVariableManager::TokensToStr(g_IB_variable_manager, dest, 128, tokens, num_tokens - 2);
			cIBVariableManager::FreeTokens(g_IB_variable_manager, tokens, num_tokens);
		}
	}
}

*/