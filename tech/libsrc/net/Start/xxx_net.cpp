
//----- (008F8AC0) --------------------------------------------------------
int __cdecl CreateServiceProviderAddress(IDirectPlayLobby3 *pIDirectPlayLobby3A, void **ppDPlayAddress, unsigned int *puDPlayAddressSize, char *IPAddress)
{
	int result; // eax@5
	void *pAddress; // [sp+0h] [bp-A0h]@6
	signed int uElementCount; // [sp+4h] [bp-9Ch]@1
	char szIPAddressString[50]; // [sp+8h] [bp-98h]@1
	int hr; // [sp+3Ch] [bp-64h]@4
	DPCOMPOUNDADDRESSELEMENT addressElements[3]; // [sp+40h] [bp-60h]@1
	unsigned __int16 wPort; // [sp+88h] [bp-18h]@1
	_GUID guidServiceProvider; // [sp+8Ch] [bp-14h]@1
	unsigned int uAddressSize; // [sp+9Ch] [bp-4h]@1

	uAddressSize = 0;
	wPort = 0;
	guidServiceProvider.x = DPSPGUID_TCPIP;
	*(_DWORD *)&guidServiceProvider.s1 = dword_9A4E6C;
	*(_DWORD *)&guidServiceProvider.c[0] = dword_9A4E70;
	*(_DWORD *)&guidServiceProvider.c[4] = dword_9A4E74;
	addressElements[0].guidDataType.x = DPAID_ServiceProvider;
	*(_DWORD *)&addressElements[0].guidDataType.s1 = dword_9A4F6C;
	*(_DWORD *)&addressElements[0].guidDataType.c[0] = dword_9A4F70;
	*(_DWORD *)&addressElements[0].guidDataType.c[4] = dword_9A4F74;
	addressElements[0].dwDataSize = 16;
	addressElements[0].lpData = &DPSPGUID_TCPIP;
	lstrcpyA(szIPAddressString, IPAddress);
	addressElements[1].guidDataType.x = DPAID_INet.x;
	*(_DWORD *)&addressElements[1].guidDataType.s1 = *(_DWORD *)&DPAID_INet.s1;
	*(_DWORD *)&addressElements[1].guidDataType.c[0] = *(_DWORD *)&DPAID_INet.c[0];
	*(_DWORD *)&addressElements[1].guidDataType.c[4] = *(_DWORD *)&DPAID_INet.c[4];
	addressElements[1].dwDataSize = lstrlenA(szIPAddressString) + 1;
	addressElements[1].lpData = szIPAddressString;
	uElementCount = 2;
	if (config_get_single_value("net_port", 1, &wPort) && (signed int)wPort > 0)
	{
		addressElements[2].guidDataType.x = DPAID_INetPort;
		*(_DWORD *)&addressElements[2].guidDataType.s1 = dword_9A4FEC;
		*(_DWORD *)&addressElements[2].guidDataType.c[0] = dword_9A4FF0;
		*(_DWORD *)&addressElements[2].guidDataType.c[4] = dword_9A4FF4;
		addressElements[2].dwDataSize = 2;
		addressElements[2].lpData = &wPort;
		uElementCount = 3;
	}
	hr = ((int(__stdcall *)(IDirectPlayLobby3 *, _DWORD, signed int, _DWORD, unsigned int *))pIDirectPlayLobby3A->baseclass_0.baseclass_0.vfptr[4].Release)(
		pIDirectPlayLobby3A,
		addressElements,
		uElementCount,
		0,
		&uAddressSize);
	if (hr == -2005467106)
	{
		pAddress = MallocSpew(uAddressSize, "x:\\prj\\tech\\libsrc\\net\\net.cpp", 122);
		if (pAddress)
		{
			hr = ((int(__stdcall *)(IDirectPlayLobby3 *, _DWORD, signed int, void *, unsigned int *))pIDirectPlayLobby3A->baseclass_0.baseclass_0.vfptr[4].Release)(
				pIDirectPlayLobby3A,
				addressElements,
				uElementCount,
				pAddress,
				&uAddressSize);
			if (hr >= 0)
			{
				*ppDPlayAddress = pAddress;
				*puDPlayAddressSize = uAddressSize;
				result = 0;
			}
			else
			{
				result = hr;
			}
		}
		else
		{
			result = -2147024882;
		}
	}
	else
	{
		result = hr;
	}
	return result;
}
// 9A4E68: using guessed type int DPSPGUID_TCPIP;
// 9A4E6C: using guessed type int dword_9A4E6C;
// 9A4E70: using guessed type int dword_9A4E70;
// 9A4E74: using guessed type int dword_9A4E74;
// 9A4F68: using guessed type int DPAID_ServiceProvider;
// 9A4F6C: using guessed type int dword_9A4F6C;
// 9A4F70: using guessed type int dword_9A4F70;
// 9A4F74: using guessed type int dword_9A4F74;
// 9A4FE8: using guessed type int DPAID_INetPort;
// 9A4FEC: using guessed type int dword_9A4FEC;
// 9A4FF0: using guessed type int dword_9A4FF0;
// 9A4FF4: using guessed type int dword_9A4FF4;

//----- (008F8D0F) --------------------------------------------------------


void __cdecl NetCreate()
{
    void *this; // [sp+4h] [bp-Ch]@1
    IUnknown *outer; // [sp+8h] [bp-8h]@1

    outer = _AppGetAggregated(&IID_IUnknown);
    this = j__new(0x15u, "x:\\prj\\tech\\libsrc\\net\\net.cpp", 1206);
    if(this)
        cNet::cNet((cNet *)this, outer);
}


//----- (008F8D70) --------------------------------------------------------
void __thiscall cNet::cNet(cNet *this, IUnknown *pOuter)
{
	IUnknown *v2; // [sp+0h] [bp-24h]@3
	cNet *thisa; // [sp+4h] [bp-20h]@1
	sAggAddInfo aAggAddInfo; // [sp+Ch] [bp-18h]@2

	thisa = this;
	cCTDelegating<INet>::cCTDelegating<INet>(&this->baseclass_0);
	cCTAggregateMemberControl<0>::cCTAggregateMemberControl<0>(&thisa->baseclass_8);
	thisa->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cNet::_vftable_;
	thisa->baseclass_8.baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cNet::_vftable_;
	cCTDelegating<INet>::InitDelegation(&thisa->baseclass_0, pOuter);
	if (pOuter)
	{
		aAggAddInfo.pID = &IID_INet;
		aAggAddInfo.pszName = "IID_INet";
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
// 9A8FE0: using guessed type int (__stdcall *cNet___vftable_)(int, int, int);
// 9A9008: using guessed type int (__stdcall *cNet___vftable_)(int this, int id, int ppI);

//----- (008F8E60) --------------------------------------------------------
int __stdcall cNet::Init(cNet *this)
{
	int result; // eax@2
	int hr; // [sp+0h] [bp-4h]@1
	int hra; // [sp+0h] [bp-4h]@3

	hr = CoInitialize(0);
	if (hr >= 0)
	{
		hra = CoCreateInstance(&CLSID_DirectPlay, 0, 1u, &IID_IDirectPlay4A, &cNet::gDP);
		if (hra >= 0)
		{
			*(IUnknownVtbl **)((char *)&this->baseclass_8.baseclass_0.baseclass_0.baseclass_0.vfptr + 1) = 0;
			cMessageDelayQueue::Init((cMessageDelayQueue *)&this->baseclass_8);
			result = 0;
		}
		else
		{
			MessageBoxA(0, "Direct play 4a failed to load", 0, 0);
			result = hra;
		}
	}
	else
	{
		MessageBoxA(0, "Failed to initialize COM", 0, 0);
		result = hr;
	}
	return result;
}

//----- (008F8EE0) --------------------------------------------------------
int __stdcall cNet::End(cNet *this)
{
	int v1; // ecx@0

	if ((*(int(__stdcall **)(LPVOID, int))(*(_DWORD *)cNet::gDP + 8))(cNet::gDP, v1) > 0)
		mprintf("There are %d refs to DirectPlay left over!\n");
	CoUninitialize();
	return 0;
}

//----- (008F8F20) --------------------------------------------------------
int __stdcall cNet::JoinOrCreate(cNet *this, char *conn, char *sessionName, int *created, void *__formal)
{
	int result; // eax@5
	int hr; // [sp+0h] [bp-Ch]@2
	int hra; // [sp+0h] [bp-Ch]@7
	cNet::SessCon sc; // [sp+4h] [bp-8h]@1

	((void(__stdcall *)(cNet *, _DWORD, int(__stdcall *)(_GUID *, void *, unsigned int, DPNAME *, unsigned int, void *), char *, signed int))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[11].Release)(
		this,
		0,
		cNet::ConnCallback,
		conn,
		1);
	memset(&cNet::Session, 0, 0x50u);
	cNet::Session = 80;
	dword_EAC8A8 = GUID_NULL.x;
	dword_EAC8AC = *(_DWORD *)&GUID_NULL.s1;
	dword_EAC8B0 = *(_DWORD *)&GUID_NULL.c[0];
	dword_EAC8B4 = *(_DWORD *)&GUID_NULL.c[4];
	sc.none = 0;
	sc.name = sessionName;
	((void(__stdcall *)(cNet *, int *, _DWORD, int(__stdcall *)(DPSESSIONDESC2 *, unsigned int *, unsigned int, void *), cNet::SessCon *, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[4].AddRef)(
		this,
		&cNet::Session,
		0,
		cNet::SessionCallback,
		&sc,
		0);
	if (sc.none)
	{
		cNet::Session = 80;
		dword_EAC894 = 4;
		dword_EAC8A8 = GUID_NULL.x;
		dword_EAC8AC = *(_DWORD *)&GUID_NULL.s1;
		dword_EAC8B0 = *(_DWORD *)&GUID_NULL.c[0];
		dword_EAC8B4 = *(_DWORD *)&GUID_NULL.c[4];
		dword_EAC8B8 = 100;
		dword_EAC8BC = 0;
		dword_EAC8C0 = (int)sessionName;
		dword_EAC8D0 = 666;
		dword_EAC8D4 = 667;
		hr = this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[8].QueryInterface(
			(IUnknown *)this,
			(_GUID *)&cNet::Session,
			(void **)2);
		if (created)
			*created = 1;
		if (hr < 0)
		{
			mprintf("failed to create %s\n");
			result = 0;
		}
		else
		{
			mprintf("successfully created %s\n");
			result = 1;
		}
	}
	else
	{
		hra = this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[8].QueryInterface(
			(IUnknown *)this,
			(_GUID *)&cNet::Session,
			(void **)1);
		if (created)
			*created = 0;
		if (hra < 0)
		{
			((void(__stdcall *)(cNet *, int))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[22].Release)(
				this,
				hra);
			mprintf("failed to join %s with %s [%x]\n");
			result = 0;
		}
		else
		{
			mprintf("successfully joined %s\n");
			result = 1;
		}
	}
	return result;
}
// EAC890: using guessed type int cNet__Session;
// EAC894: using guessed type int dword_EAC894;
// EAC8A8: using guessed type int dword_EAC8A8;
// EAC8AC: using guessed type int dword_EAC8AC;
// EAC8B0: using guessed type int dword_EAC8B0;
// EAC8B4: using guessed type int dword_EAC8B4;
// EAC8B8: using guessed type int dword_EAC8B8;
// EAC8BC: using guessed type int dword_EAC8BC;
// EAC8C0: using guessed type int dword_EAC8C0;
// EAC8D0: using guessed type int dword_EAC8D0;
// EAC8D4: using guessed type int dword_EAC8D4;

//----- (008F9110) --------------------------------------------------------
int __stdcall cNet::ConnCallback(_GUID *__formal, void *lpConnection, unsigned int dwSize, DPNAME *lpName, unsigned int a5, void *lpContext)
{
	size_t v6; // eax@1
	char errMsg[256]; // [sp+4h] [bp-10Ch]@14
	void *conn; // [sp+104h] [bp-Ch]@1
	void *lpConnBuff; // [sp+108h] [bp-8h]@3
	int hr; // [sp+10Ch] [bp-4h]@3

	conn = lpContext;
	v6 = strlen((const char *)lpContext);
	if (strnicmp((const char *)lpContext, (const char *)lpName->___u2.lpszShortName, v6))
		return 1;
	lpConnBuff = MallocSpew(dwSize, "x:\\prj\\tech\\libsrc\\net\\net.cpp", 219);
	memcpy(lpConnBuff, lpConnection, dwSize);
	hr = (*(int(__stdcall **)(LPVOID, void *, _DWORD))(*(_DWORD *)cNet::gDP + 152))(cNet::gDP, lpConnBuff, 0);
	if (hr > -2005467016)
	{
		if (hr == -2005466886)
		{
			sprintf(errMsg, "You do not have the right hardware & drivers to use %s", conn);
			MessageBoxA(0, errMsg, 0, 0);
			mprintf("Status DPERR_UNAVAILABLE!\n");
		}
		else
		{
			if (hr)
			{
			LABEL_15:
				mprintf("Direct play InitializeConnection returned an unknown failure [%x]!\n");
				return 1;
			}
			mprintf("Status OK!\n");
		}
	}
	else
	{
		if (hr == -2005467016)
		{
			mprintf("Status DPERR_INVALIDFLAGS!\n");
		}
		else
		{
			if (hr == -2147024809)
			{
				mprintf("Status DPERR_INVALIDPARAMS!\n");
			}
			else
			{
				if (hr != -2005467131)
					goto LABEL_15;
				mprintf("Status DPERR_ALREADYINITIALIZED!\n");
			}
		}
	}
	return 1;
}

//----- (008F9280) --------------------------------------------------------
int __stdcall cNet::SessionCallback(DPSESSIONDESC2 *lpThisSD, unsigned int *__formal, unsigned int a3, void *lpContext)
{
	int result; // eax@2

	if (lpThisSD)
	{
		if (*(_DWORD *)((char *)lpContext + 1)
			&& _strcmpi(*(const char **)((char *)lpContext + 1), (const char *)lpThisSD->___u6.lpszSessionName))
		{
			result = 1;
		}
		else
		{
			*(_BYTE *)lpContext = 0;
			memcpy(&cNet::Session, lpThisSD, lpThisSD->dwSize);
			strcpy(cNet::session_buffer, (const char *)lpThisSD->___u6.lpszSessionName);
			dword_EAC8C0 = (int)cNet::session_buffer;
			result = 0;
		}
	}
	else
	{
		*(_BYTE *)lpContext = 1;
		result = 0;
	}
	return result;
}
// EAC890: using guessed type int cNet__Session;
// EAC8C0: using guessed type int dword_EAC8C0;

//----- (008F9310) --------------------------------------------------------
int __stdcall cNet::Host(cNet *this, char *conn, char *sessionName)
{
	int result; // eax@2
	void *pDPlayAddress; // [sp+0h] [bp-10h]@3
	IDirectPlayLobby3 *pIDirectPlayLobby3A; // [sp+4h] [bp-Ch]@1
	int hr; // [sp+8h] [bp-8h]@1
	int uDPlayAddressSize; // [sp+Ch] [bp-4h]@3

	hr = CoCreateInstance(&CLSID_DirectPlayLobby, 0, 1u, &IID_IDirectPlayLobby3A, (LPVOID *)&pIDirectPlayLobby3A);
	if (hr >= 0)
	{
		hr = CreateServiceProviderAddress(
			pIDirectPlayLobby3A,
			&pDPlayAddress,
			(unsigned int *)&uDPlayAddressSize,
			&byte_B5ADD0);
		if (hr >= 0)
		{
			if (pIDirectPlayLobby3A)
				pIDirectPlayLobby3A->baseclass_0.baseclass_0.vfptr->Release((IUnknown *)pIDirectPlayLobby3A);
			pIDirectPlayLobby3A = 0;
			hr = (*(int(__stdcall **)(LPVOID, void *, _DWORD))(*(_DWORD *)cNet::gDP + 152))(cNet::gDP, pDPlayAddress, 0);
			FreeSpew(pDPlayAddress, "x:\\prj\\tech\\libsrc\\net\\net.cpp", 450);
			if (hr >= 0 || hr == -2005467131)
			{
				cNet::Session = 80;
				dword_EAC894 = 40960;
				if (!config_get_raw("net_no_keepalive", 0, 0))
					dword_EAC894 |= 0x40u;
				dword_EAC8A8 = GUID_NULL.x;
				dword_EAC8AC = *(_DWORD *)&GUID_NULL.s1;
				dword_EAC8B0 = *(_DWORD *)&GUID_NULL.c[0];
				dword_EAC8B4 = *(_DWORD *)&GUID_NULL.c[4];
				dword_EAC8B8 = 100;
				dword_EAC8BC = 0;
				dword_EAC8C0 = (int)sessionName;
				dword_EAC8D0 = 666;
				dword_EAC8D4 = 667;
				hr = this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[8].QueryInterface(
					(IUnknown *)this,
					(_GUID *)&cNet::Session,
					(void **)2);
				if (hr < 0)
				{
					mprintf("failed to create %s\n");
					result = 0;
				}
				else
				{
					mprintf("successfully created %s\n");
					result = 1;
				}
			}
			else
			{
				((void(__stdcall *)(cNet *, int))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[22].Release)(
					this,
					hr);
				mprintf("Couldn't initialize connection - %s\n");
				result = 0;
			}
		}
		else
		{
			mprintf("Couldn't create host address!\n");
			result = 0;
		}
	}
	else
	{
		((void(__stdcall *)(cNet *, int))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[22].Release)(
			this,
			hr);
		mprintf("Couldn't create Lobby Interface - %s\n");
		result = 0;
	}
	return result;
}
// EAC890: using guessed type int cNet__Session;
// EAC894: using guessed type int dword_EAC894;
// EAC8A8: using guessed type int dword_EAC8A8;
// EAC8AC: using guessed type int dword_EAC8AC;
// EAC8B0: using guessed type int dword_EAC8B0;
// EAC8B4: using guessed type int dword_EAC8B4;
// EAC8B8: using guessed type int dword_EAC8B8;
// EAC8BC: using guessed type int dword_EAC8BC;
// EAC8C0: using guessed type int dword_EAC8C0;
// EAC8D0: using guessed type int dword_EAC8D0;
// EAC8D4: using guessed type int dword_EAC8D4;

//----- (008F9500) --------------------------------------------------------
int __stdcall cNet::Join(cNet *this, char *conn, char *sessionName, char *IPAddress)
{
	int result; // eax@2
	int uCSAddressSize; // [sp+0h] [bp-18h]@3
	void *pCSAddress; // [sp+4h] [bp-14h]@1
	IDirectPlayLobby3 *pIDirectPlayLobby3A; // [sp+8h] [bp-10h]@1
	int hr; // [sp+Ch] [bp-Ch]@1
	cNet::SessCon sc; // [sp+10h] [bp-8h]@12

	pCSAddress = 0;
	hr = CoCreateInstance(&CLSID_DirectPlayLobby, 0, 1u, &IID_IDirectPlayLobby3A, (LPVOID *)&pIDirectPlayLobby3A);
	if (hr >= 0)
	{
		hr = CreateServiceProviderAddress(pIDirectPlayLobby3A, &pCSAddress, (unsigned int *)&uCSAddressSize, IPAddress);
		if (hr >= 0)
		{
			if (pIDirectPlayLobby3A)
				pIDirectPlayLobby3A->baseclass_0.baseclass_0.vfptr->Release((IUnknown *)pIDirectPlayLobby3A);
			pIDirectPlayLobby3A = 0;
			hr = (*(int(__stdcall **)(LPVOID, void *, _DWORD))(*(_DWORD *)cNet::gDP + 152))(cNet::gDP, pCSAddress, 0);
			FreeSpew(pCSAddress, "x:\\prj\\tech\\libsrc\\net\\net.cpp", 527);
			if (hr >= 0 || hr == -2005467131)
			{
				memset(&cNet::Session, 0, 0x50u);
				cNet::Session = 80;
				dword_EAC8A8 = GUID_NULL.x;
				dword_EAC8AC = *(_DWORD *)&GUID_NULL.s1;
				dword_EAC8B0 = *(_DWORD *)&GUID_NULL.c[0];
				dword_EAC8B4 = *(_DWORD *)&GUID_NULL.c[4];
				sc.none = 0;
				sc.name = sessionName;
				hr = ((int(__stdcall *)(cNet *, int *, _DWORD, int(__stdcall *)(DPSESSIONDESC2 *, unsigned int *, unsigned int, void *), cNet::SessCon *, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[4].AddRef)(
					this,
					&cNet::Session,
					0,
					cNet::SessionCallback,
					&sc,
					0);
				if (sc.none)
				{
					mprintf("session %s not found (sc.none is TRUE)\n");
					result = 0;
				}
				else
				{
					hr = this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[8].QueryInterface(
						(IUnknown *)this,
						(_GUID *)&cNet::Session,
						(void **)1);
					if (hr < 0)
					{
						((void(__stdcall *)(cNet *, int))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[22].Release)(
							this,
							hr);
						mprintf("failed to join %s with %s [%x]\n");
						result = 0;
					}
					else
					{
						mprintf("successfully joined %s\n");
						result = 1;
					}
				}
			}
			else
			{
				((void(__stdcall *)(cNet *, int))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[22].Release)(
					this,
					hr);
				mprintf("Couldn't initialize connection - %s\n");
				result = 0;
			}
		}
		else
		{
			((void(__stdcall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[22].Release)(
				this,
				hr);
			mprintf("Error creating CSAddress - %s\n");
			if (pIDirectPlayLobby3A)
				pIDirectPlayLobby3A->baseclass_0.baseclass_0.vfptr->Release((IUnknown *)pIDirectPlayLobby3A);
			pIDirectPlayLobby3A = 0;
			result = 0;
		}
	}
	else
	{
		((void(__stdcall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[22].Release)(
			this,
			hr);
		mprintf("Couldn't create Lobby Interface - %s\n");
		result = 0;
	}
	return result;
}
// EAC890: using guessed type int cNet__Session;
// EAC8A8: using guessed type int dword_EAC8A8;
// EAC8AC: using guessed type int dword_EAC8AC;
// EAC8B0: using guessed type int dword_EAC8B0;
// EAC8B4: using guessed type int dword_EAC8B4;

//----- (008F9740) --------------------------------------------------------
int __stdcall cNet::GetPlayerAddress(cNet *this, unsigned int player, char *pAddress, int addrSize)
{
	int result; // eax@2
	int bufSize; // [sp+0h] [bp-1Ch]@1
	void *pInternalAddress; // [sp+4h] [bp-18h]@3
	sAddrBuf addrBuf; // [sp+8h] [bp-14h]@7
	void *pIDirectPlayLobby3A; // [sp+10h] [bp-Ch]@5
	int hr; // [sp+14h] [bp-8h]@5
	int ret; // [sp+18h] [bp-4h]@1

	bufSize = 0;
	ret = ((int(__stdcall *)(cNet *, unsigned int, _DWORD, int *))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[6].QueryInterface)(
		this,
		player,
		0,
		&bufSize);
	if (bufSize)
	{
		pInternalAddress = (void *)f_malloc_db(bufSize, "x:\\prj\\tech\\libsrc\\net\\net.cpp", 592);
		if (((int(__stdcall *)(cNet *, unsigned int, void *, int *))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[6].QueryInterface)(
			this,
			player,
			pInternalAddress,
			&bufSize) >= 0)
		{
			hr = CoCreateInstance(&CLSID_DirectPlayLobby, 0, 1u, &IID_IDirectPlayLobby3A, &pIDirectPlayLobby3A);
			if (hr >= 0)
			{
				addrBuf.buffer = pAddress;
				addrBuf.size = addrSize;
				hr = (*(int(__stdcall **)(void *, int(__stdcall *)(_GUID *, unsigned int, const void *, void *), void *, int, sAddrBuf *))(*(_DWORD *)pIDirectPlayLobby3A + 20))(
					pIDirectPlayLobby3A,
					cNet::addressCallback,
					pInternalAddress,
					bufSize,
					&addrBuf);
				j__free(pInternalAddress);
				if (hr >= 0)
				{
					if (pIDirectPlayLobby3A)
						(*(void(__stdcall **)(void *))(*(_DWORD *)pIDirectPlayLobby3A + 8))(pIDirectPlayLobby3A);
					result = 0;
				}
				else
				{
					((void(__stdcall *)(cNet *, int))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[22].Release)(
						this,
						hr);
					mprintf("Couldn't get player address - %s\n");
					result = -2147467259;
				}
			}
			else
			{
				((void(__stdcall *)(cNet *, int))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[22].Release)(
					this,
					hr);
				mprintf("Couldn't create Lobby Interface - %s\n");
				result = -2147467259;
			}
		}
		else
		{
			j__free(pInternalAddress);
			result = -2147467259;
		}
	}
	else
	{
		result = -2147467259;
	}
	return result;
}
// B19510: using guessed type int (__cdecl *f_malloc_db)(_DWORD, _DWORD, _DWORD);

//----- (008F98A0) --------------------------------------------------------
int __stdcall cNet::addressCallback(_GUID *guid, unsigned int dataSize, const void *data, void *context)
{
	int result; // eax@5
	unsigned int v5; // [sp+0h] [bp-Ch]@3

	if (IsEqualGUID(guid, &DPAID_INet))
	{
		if (*((_DWORD *)context + 1) >= dataSize)
			v5 = dataSize;
		else
			v5 = *((_DWORD *)context + 1);
		memcpy(*(void **)context, data, v5);
		result = 0;
	}
	else
	{
		result = 1;
	}
	return result;
}

//----- (008F9910) --------------------------------------------------------
unsigned int __stdcall cNet::SimpleCreatePlayer(cNet *this, char *name)
{
	DPCAPS caps; // [sp+0h] [bp-40h]@2
	_GUID *my_id; // [sp+28h] [bp-18h]@1
	int hr; // [sp+2Ch] [bp-14h]@1
	DPNAME my_name; // [sp+30h] [bp-10h]@1

	my_id = 0;
	my_name.dwSize = 16;
	my_name.dwFlags = 0;
	my_name.___u2.lpszShortName = (unsigned __int16 *)name;
	my_name.___u3.lpszLongName = (unsigned __int16 *)name;
	hr = ((int(__stdcall *)(cNet *, _GUID **, DPNAME *, _DWORD, _DWORD, _DWORD, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[2].QueryInterface)(
		this,
		&my_id,
		&my_name,
		0,
		0,
		0,
		0);
	if (hr)
	{
		mprintf("Couldn't create %s, exiting\n");
	}
	else
	{
		this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[21].QueryInterface(
			(IUnknown *)this,
			my_id,
			0);
		mprintf("created %s okay\n");
		caps.dwSize = 40;
		hr = ((int(__stdcall *)(cNet *, DPCAPS *, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[4].Release)(
			this,
			&caps,
			0);
	}
	return (unsigned int)my_id;
}

//----- (008F99C0) --------------------------------------------------------
unsigned int __stdcall cNet::IdForName(cNet *this, char *name)
{
	cNet::PlayCon pc; // [sp+0h] [bp-8h]@1

	pc.name = name;
	pc.id = 0;
	((void(__stdcall *)(cNet *, _DWORD, int(__stdcall *)(unsigned int, unsigned int, DPNAME *, unsigned int, void *), cNet::PlayCon *, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[4].QueryInterface)(
		this,
		0,
		cNet::PlayerCallback,
		&pc,
		0);
	return pc.id;
}

//----- (008F9A00) --------------------------------------------------------
int __stdcall cNet::PlayerCallback(unsigned int dpId, unsigned int __formal, DPNAME *lpName, unsigned int a4, void *lpContext)
{
	int result; // eax@2

	if (_strcmpi((const char *)lpName->___u2.lpszShortName, *((const char **)lpContext + 1)))
	{
		result = 1;
	}
	else
	{
		*(_DWORD *)lpContext = dpId;
		result = 0;
	}
	return result;
}

//----- (008F9A40) --------------------------------------------------------
void __stdcall cNet::UseInternetSimulation(cNet *this, int value)
{
	this->m_SimulateInternet = value;
}

//----- (008F9A50) --------------------------------------------------------
int __stdcall cNet::IsSimulatingInternet(cNet *this)
{
	return this->m_SimulateInternet;
}

//----- (008F9A60) --------------------------------------------------------
void __stdcall cNet::SetFullInternetParameters(cNet *this, long double minLatency, long double aveLatency, long double maxLatency, unsigned int lossPercent, unsigned int spikePercent, unsigned int spikeLatency)
{
	cMessageDelayQueue::SetFullInternetParameters(
		&this->m_MessageDelayQueue,
		lossPercent,
		(signed __int64)minLatency,
		(signed __int64)aveLatency,
		(signed __int64)maxLatency,
		spikePercent,
		spikeLatency);
}

//----- (008F9AA0) --------------------------------------------------------
void __stdcall cNet::SetInternetParameters(cNet *this, long double minLatency, long double aveLatency, long double maxLatency, unsigned int lossPercent)
{
	cMessageDelayQueue::SetInternetParameters(
		&this->m_MessageDelayQueue,
		lossPercent,
		(signed __int64)minLatency,
		(signed __int64)aveLatency,
		(signed __int64)maxLatency);
}

//----- (008F9AE0) --------------------------------------------------------
void __stdcall cNet::ResetPlayerData(cNet *this, unsigned int player, void *user_data)
{
	void *v3; // ST18_4@1
	sLocalData ldata; // [sp+8h] [bp-Ch]@1
	int lsize; // [sp+10h] [bp-4h]@1

	v3 = j__new(0x38u, "x:\\prj\\tech\\libsrc\\net\\net.cpp", 780);
	ldata.hostData = (sHostData *)v3;
	ldata.userData = user_data;
	lsize = 8;
	memset(v3, 0, 0x38u);
	*(_DWORD *)v3 = 0;
	*((_DWORD *)v3 + 1) = 1072693248;
	(*(void(__stdcall **)(LPVOID, unsigned int, sLocalData *, signed int, signed int))(*(_DWORD *)cNet::gDP + 116))(
		cNet::gDP,
		player,
		&ldata,
		8,
		1);
}

//----- (008F9B60) --------------------------------------------------------
long double __stdcall cNet::ToThisGameTime(cNet *this, long double player_time, unsigned int player)
{
	long double result; // st7@2
	sHostData *h; // [sp+0h] [bp-4h]@1

	h = cNet::GetHostData(this, player);
	if (h)
		result = (player_time - h->delta) / h->scale;
	else
		result = player_time;
	return result;
}

//----- (008F9BA0) --------------------------------------------------------
sHostData *__thiscall cNet::GetHostData(cNet *this, unsigned int player)
{
	sHostData *result; // eax@2
	sLocalData ldata; // [sp+4h] [bp-8h]@1

	if (cNet::GetLocalPlayerData(this, player, &ldata) < 0)
		result = 0;
	else
		result = ldata.hostData;
	return result;
}

//----- (008F9BD0) --------------------------------------------------------
int __thiscall cNet::GetLocalPlayerData(cNet *this, unsigned int player, sLocalData *ldata)
{
	cNet *thisa; // [sp+0h] [bp-Ch]@1
	int hr; // [sp+4h] [bp-8h]@1
	int lsize; // [sp+8h] [bp-4h]@1

	thisa = this;
	lsize = 8;
	hr = (*(int(__stdcall **)(LPVOID, unsigned int, sLocalData *, int *, signed int))(*(_DWORD *)cNet::gDP + 80))(
		cNet::gDP,
		player,
		ldata,
		&lsize,
		1);
	if (hr >= 0)
	{
		if (!lsize)
		{
			thisa->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[21].QueryInterface(
				(IUnknown *)thisa,
				(_GUID *)player,
				0);
			lsize = 8;
			hr = (*(int(__stdcall **)(LPVOID, unsigned int, sLocalData *, int *, signed int))(*(_DWORD *)cNet::gDP + 80))(
				cNet::gDP,
				player,
				ldata,
				&lsize,
				1);
		}
		if (lsize != 8)
			_CriticalMsg("Corrupt local player data", "x:\\prj\\tech\\libsrc\\net\\net.cpp", 0xBFu);
	}
	return hr;
}

//----- (008F9C80) --------------------------------------------------------
long double __stdcall cNet::PlayerTimeScale(cNet *this, unsigned int player)
{
	double v3; // [sp+0h] [bp-Ch]@2
	sHostData *h; // [sp+8h] [bp-4h]@1

	h = cNet::GetHostData(this, player);
	if (h)
		v3 = h->scale;
	else
		v3 = 1.0;
	return v3;
}

//----- (008F9CD0) --------------------------------------------------------
long double __stdcall cNet::PlayerTimeDelta(cNet *this, unsigned int player)
{
	double v3; // [sp+0h] [bp-Ch]@2
	sHostData *h; // [sp+8h] [bp-4h]@1

	h = cNet::GetHostData(this, player);
	if (h)
		v3 = h->delta;
	else
		v3 = 0.0;
	return v3;
}

//----- (008F9D20) --------------------------------------------------------
void __stdcall cNet::UpdatePlayerTime(cNet *this, long double game_time, long double player_time, unsigned int player)
{
	double delta; // [sp+0h] [bp-Ch]@1
	sHostData *h; // [sp+8h] [bp-4h]@1

	h = cNet::GetHostData(this, player);
	delta = player_time - game_time;
	if (h)
	{
		if (h->time_of_delta2 == 0.0 || game_time - h->time_of_delta2 >= 5.0 || delta > h->delta2)
		{
			h->delta2 = delta;
			h->time_of_delta2 = game_time;
		}
		if (h->time_of_delta != 0.0 && delta <= h->delta)
		{
			if (game_time - h->time_of_delta > 10.0)
			{
				LODWORD(h->delta) = LODWORD(h->delta2);
				HIDWORD(h->delta) = HIDWORD(h->delta2);
				LODWORD(h->time_of_delta) = LODWORD(h->time_of_delta2);
				HIDWORD(h->time_of_delta) = HIDWORD(h->time_of_delta2);
			}
		}
		else
		{
			h->delta = delta;
			h->time_of_delta = game_time;
		}
		LODWORD(h->scale) = 0;
		HIDWORD(h->scale) = 1072693248;
	}
}

//----- (008F9E40) --------------------------------------------------------
int __stdcall cNet::Send(cNet *this, unsigned int from, unsigned int to, unsigned int flags, void *data, unsigned int size)
{
	const char *v6; // eax@2
	int result; // eax@4
	void *v8; // ST1C_4@5

	if (!size)
	{
		v6 = _LogFmt("Nonpositive send size %d");
		_CriticalMsg(v6, "x:\\prj\\tech\\libsrc\\net\\net.cpp", 0x369u);
	}
	if (this->m_SimulateInternet)
	{
		v8 = j__new(size, "x:\\prj\\tech\\libsrc\\net\\net.cpp", 882);
		memcpy(v8, data, size);
		cMessageDelayQueue::DelayMessage(&this->m_MessageDelayQueue, from, to, flags, v8, size);
		result = 0;
	}
	else
	{
		result = (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 104))(
			cNet::gDP,
			from,
			to,
			flags,
			data,
			size);
	}
	return result;
}

//----- (008F9F00) --------------------------------------------------------
int __stdcall cNet::SendEx(cNet *this, unsigned int from, unsigned int to, unsigned int flags, void *data, unsigned int size, unsigned int priority, unsigned int timeout, void *pMsgId, unsigned int *pContext)
{
	int result; // eax@2
	void *v11; // ST2C_4@3

	if (this->m_SimulateInternet)
	{
		v11 = j__new(size, "x:\\prj\\tech\\libsrc\\net\\net.cpp", 904);
		memcpy(v11, data, size);
		cMessageDelayQueue::DelayMessage(&this->m_MessageDelayQueue, from, to, flags, v11, size);
		result = 0;
	}
	else
	{
		result = (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 196))(
			cNet::gDP,
			from,
			to,
			flags,
			data,
			size,
			priority,
			timeout,
			pMsgId,
			pContext);
	}
	return result;
}

//----- (008F9FB0) --------------------------------------------------------
int __stdcall cNet::Receive(cNet *this, unsigned int *from, unsigned int *to, unsigned int flags, void *data, unsigned int *size)
{
	int ldata; // [sp+Ch] [bp-24h]@7
	int msg_to; // [sp+14h] [bp-1Ch]@2
	int msg_from; // [sp+18h] [bp-18h]@2
	int msg_size; // [sp+1Ch] [bp-14h]@2
	void *msg_data; // [sp+20h] [bp-10h]@2
	int msg_flags; // [sp+24h] [bp-Ch]@2
	int hr; // [sp+28h] [bp-8h]@3
	int result; // [sp+2Ch] [bp-4h]@1

	result = (*(int(__stdcall **)(LPVOID, unsigned int *, unsigned int *, unsigned int, void *, unsigned int *))(*(_DWORD *)cNet::gDP + 100))(
		cNet::gDP,
		from,
		to,
		flags,
		data,
		size);
	if (this->m_SimulateInternet)
	{
		do
		{
			cMessageDelayQueue::NextReadyMessage(
				&this->m_MessageDelayQueue,
				(unsigned int *)&msg_from,
				(unsigned int *)&msg_to,
				(unsigned int *)&msg_flags,
				&msg_data,
				(unsigned int *)&msg_size);
			if (!msg_data)
				break;
			hr = (*(int(__stdcall **)(LPVOID, int, int, int, void *, int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 196))(
				cNet::gDP,
				msg_from,
				msg_to,
				msg_flags,
				msg_data,
				msg_size,
				0,
				0,
				0,
				0);
			operator delete(msg_data);
		} while (hr >= 0);
	}
	if (!result)
	{
		if (!*from)
		{
			if (*(_DWORD *)data == 5)
			{
				ldata = *((_DWORD *)data + 3);
				if (ldata)
				{
					*((_DWORD *)data + 3) = *(_DWORD *)(ldata + 4);
					*((_DWORD *)data + 4) = 4;
				}
			}
		}
	}
	return result;
}

//----- (008FA0C0) --------------------------------------------------------
int __stdcall cNet::Open(cNet *this, DPSESSIONDESC2 *session, unsigned int flags)
{
	int v3; // ecx@0
	int hr; // [sp+0h] [bp-4h]@1

	hr = (*(int(__stdcall **)(LPVOID, DPSESSIONDESC2 *, unsigned int, int))(*(_DWORD *)cNet::gDP + 96))(
		cNet::gDP,
		session,
		flags,
		v3);
	if (hr >= 0)
		((void(__stdcall *)(cNet *, _DWORD, int(__stdcall *)(unsigned int, unsigned int, DPNAME *, unsigned int, void *), cNet *, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[4].QueryInterface)(
		this,
		0,
		cNet::InitExistingPlayer,
		this,
		0);
	return hr;
}

//----- (008FA110) --------------------------------------------------------
int __stdcall cNet::InitExistingPlayer(unsigned int dpId, unsigned int __formal, DPNAME *a3, unsigned int a4, void *lpContext)
{
	(*(void(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)lpContext + 252))(lpContext, dpId, 0);
	return 1;
}

//----- (008FA140) --------------------------------------------------------
int __stdcall cNet::CreatePlayer(cNet *this, unsigned int *pPlayer, DPNAME *pName, void *hEvent, void *pData, unsigned int size, unsigned int flags)
{
	int v7; // ecx@0
	int hr; // [sp+0h] [bp-4h]@1
	int hra; // [sp+0h] [bp-4h]@2

	hr = (*(int(__stdcall **)(LPVOID, unsigned int *, DPNAME *, void *, void *, unsigned int, unsigned int, int))(*(_DWORD *)cNet::gDP + 24))(
		cNet::gDP,
		pPlayer,
		pName,
		hEvent,
		pData,
		size,
		flags,
		v7);
	if (hr < 0)
	{
		hra = ((int(__stdcall *)(cNet *, int))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[22].Release)(
			this,
			hr);
		DbgReportWarning("Couldn't create player: %s\n");
	}
	else
	{
		this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[21].QueryInterface(
			(IUnknown *)this,
			(_GUID *)*pPlayer,
			0);
	}
	return hra;
}

//----- (008FA1C0) --------------------------------------------------------
int __stdcall cNet::SetPlayerData(cNet *this, unsigned int player, void *data, unsigned int size, unsigned int flags)
{
	int result; // eax@2
	int hr; // [sp+0h] [bp-Ch]@5
	sLocalData ldata; // [sp+4h] [bp-8h]@5

	if (flags & 1)
	{
		if (size != 4)
			_CriticalMsg(
			"SetPlayerData for local data can only take a size of 4 bytes",
			"x:\\prj\\tech\\libsrc\\net\\net.cpp",
			0x3E4u);
		hr = cNet::GetLocalPlayerData(this, player, &ldata);
		if (hr < 0)
		{
			result = hr;
		}
		else
		{
			ldata.userData = *(void **)data;
			result = (*(int(__stdcall **)(LPVOID, unsigned int, sLocalData *, signed int, signed int))(*(_DWORD *)cNet::gDP
				+ 116))(
				cNet::gDP,
				player,
				&ldata,
				8,
				1);
		}
	}
	else
	{
		result = (*(int(__stdcall **)(LPVOID, unsigned int, void *, unsigned int, unsigned int))(*(_DWORD *)cNet::gDP + 116))(
			cNet::gDP,
			player,
			data,
			size,
			flags);
	}
	return result;
}

//----- (008FA260) --------------------------------------------------------
int __stdcall cNet::GetPlayerData(cNet *this, unsigned int player, void *data, unsigned int *size, unsigned int flags)
{
	int result; // eax@2
	int hr; // [sp+0h] [bp-Ch]@5
	sLocalData ldata; // [sp+4h] [bp-8h]@5

	if (flags & 1)
	{
		if (*size != 4)
			_CriticalMsg(
			"SetPlayerData for local data can only take a size of 4 bytes",
			"x:\\prj\\tech\\libsrc\\net\\net.cpp",
			0x3F7u);
		hr = cNet::GetLocalPlayerData(this, player, &ldata);
		if (hr >= 0)
			*(_DWORD *)data = ldata.userData;
		result = hr;
	}
	else
	{
		result = (*(int(__stdcall **)(LPVOID, unsigned int, void *, unsigned int *, unsigned int))(*(_DWORD *)cNet::gDP + 80))(
			cNet::gDP,
			player,
			data,
			size,
			flags);
	}
	return result;
}

//----- (008FA2F0) --------------------------------------------------------
const char *__stdcall cNet::DPlayErrorAsString(cNet *this, int hr)
{
	return "Dplay Error";
}

//----- (008FA300) --------------------------------------------------------
int __stdcall cNet::AddPlayerToGroup(cNet *this, unsigned int a, unsigned int b)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 12))(cNet::gDP, a, b);
}

//----- (008FA330) --------------------------------------------------------
int __stdcall cNet::Close(cNet *this)
{
	return (*(int(__stdcall **)(_DWORD))(*(_DWORD *)cNet::gDP + 16))(cNet::gDP);
}

//----- (008FA350) --------------------------------------------------------
int __stdcall cNet::CreateGroup(cNet *this, unsigned int *a, DPNAME *b, void *c, unsigned int d, unsigned int e)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 20))(
		cNet::gDP,
		a,
		b,
		c,
		d,
		e);
}

//----- (008FA380) --------------------------------------------------------
int __stdcall cNet::DeletePlayerFromGroup(cNet *this, unsigned int a, unsigned int b)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 28))(cNet::gDP, a, b);
}

//----- (008FA3B0) --------------------------------------------------------
int __stdcall cNet::DestroyGroup(cNet *this, unsigned int a)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 32))(cNet::gDP, a);
}

//----- (008FA3D0) --------------------------------------------------------
int __stdcall cNet::DestroyPlayer(cNet *this, unsigned int a)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 36))(cNet::gDP, a);
}

//----- (008FA3F0) --------------------------------------------------------
int __stdcall cNet::EnumGroupPlayers(cNet *this, unsigned int a, _GUID *b, int(__stdcall *c)(unsigned int, unsigned int, DPNAME *, unsigned int, void *), void *d, unsigned int e)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 40))(
		cNet::gDP,
		a,
		b,
		c,
		d,
		e);
}

//----- (008FA420) --------------------------------------------------------
int __stdcall cNet::EnumGroups(cNet *this, _GUID *a, int(__stdcall *b)(unsigned int, unsigned int, DPNAME *, unsigned int, void *), void *c, unsigned int d)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 44))(
		cNet::gDP,
		a,
		b,
		c,
		d);
}

//----- (008FA450) --------------------------------------------------------
int __stdcall cNet::EnumPlayers(cNet *this, _GUID *a, int(__stdcall *b)(unsigned int, unsigned int, DPNAME *, unsigned int, void *), void *c, unsigned int d)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 48))(
		cNet::gDP,
		a,
		b,
		c,
		d);
}

//----- (008FA480) --------------------------------------------------------
int __stdcall cNet::EnumSessions(cNet *this, DPSESSIONDESC2 *a, unsigned int b, int(__stdcall *c)(DPSESSIONDESC2 *, unsigned int *, unsigned int, void *), void *d, unsigned int e)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 52))(
		cNet::gDP,
		a,
		b,
		c,
		d,
		e);
}

//----- (008FA4B0) --------------------------------------------------------
int __stdcall cNet::GetCaps(cNet *this, DPCAPS *a, unsigned int b)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 56))(cNet::gDP, a, b);
}

//----- (008FA4E0) --------------------------------------------------------
int __stdcall cNet::GetGroupData(cNet *this, unsigned int a, void *b, unsigned int *c, unsigned int d)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 60))(
		cNet::gDP,
		a,
		b,
		c,
		d);
}

//----- (008FA510) --------------------------------------------------------
int __stdcall cNet::GetGroupName(cNet *this, unsigned int a, void *b, unsigned int *c)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 64))(cNet::gDP, a, b, c);
}

//----- (008FA540) --------------------------------------------------------
int __stdcall cNet::GetMessageCount(cNet *this, unsigned int a, unsigned int *b)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 68))(cNet::gDP, a, b);
}

//----- (008FA570) --------------------------------------------------------
int __stdcall cNet::GetPlayerAddress(cNet *this, unsigned int a, void *b, unsigned int *c)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 72))(cNet::gDP, a, b, c);
}

//----- (008FA5A0) --------------------------------------------------------
int __stdcall cNet::GetPlayerCaps(cNet *this, unsigned int a, DPCAPS *b, unsigned int c)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 76))(cNet::gDP, a, b, c);
}

//----- (008FA5D0) --------------------------------------------------------
int __stdcall cNet::GetPlayerName(cNet *this, unsigned int a, void *b, unsigned int *c)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 84))(cNet::gDP, a, b, c);
}

//----- (008FA600) --------------------------------------------------------
int __stdcall cNet::GetSessionDesc(cNet *this, void *a, unsigned int *b)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 88))(cNet::gDP, a, b);
}

//----- (008FA630) --------------------------------------------------------
int __stdcall cNet::Initialize(cNet *this, _GUID *a)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 92))(cNet::gDP, a);
}

//----- (008FA650) --------------------------------------------------------
int __stdcall cNet::SetGroupData(cNet *this, unsigned int a, void *b, unsigned int c, unsigned int d)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 108))(
		cNet::gDP,
		a,
		b,
		c,
		d);
}

//----- (008FA680) --------------------------------------------------------
int __stdcall cNet::SetGroupName(cNet *this, unsigned int a, DPNAME *b, unsigned int c)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 112))(cNet::gDP, a, b, c);
}

//----- (008FA6B0) --------------------------------------------------------
int __stdcall cNet::SetPlayerName(cNet *this, unsigned int a, DPNAME *b, unsigned int c)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 120))(cNet::gDP, a, b, c);
}

//----- (008FA6E0) --------------------------------------------------------
int __stdcall cNet::SetSessionDesc(cNet *this, DPSESSIONDESC2 *a, unsigned int b)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 124))(cNet::gDP, a, b);
}

//----- (008FA710) --------------------------------------------------------
int __stdcall cNet::AddGroupToGroup(cNet *this, unsigned int a, unsigned int b)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 128))(cNet::gDP, a, b);
}

//----- (008FA740) --------------------------------------------------------
int __stdcall cNet::CreateGroupInGroup(cNet *this, unsigned int a, unsigned int *b, DPNAME *c, void *d, unsigned int e, unsigned int f)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 132))(
		cNet::gDP,
		a,
		b,
		c,
		d,
		e,
		f);
}

//----- (008FA780) --------------------------------------------------------
int __stdcall cNet::DeleteGroupFromGroup(cNet *this, unsigned int a, unsigned int b)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 136))(cNet::gDP, a, b);
}

//----- (008FA7B0) --------------------------------------------------------
int __stdcall cNet::EnumConnections(cNet *this, _GUID *a, int(__stdcall *b)(_GUID *, void *, unsigned int, DPNAME *, unsigned int, void *), void *c, unsigned int d)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 140))(
		cNet::gDP,
		a,
		b,
		c,
		d);
}

//----- (008FA7E0) --------------------------------------------------------
int __stdcall cNet::EnumGroupsInGroup(cNet *this, unsigned int a, _GUID *b, int(__stdcall *c)(unsigned int, unsigned int, DPNAME *, unsigned int, void *), void *d, unsigned int e)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 144))(
		cNet::gDP,
		a,
		b,
		c,
		d,
		e);
}

//----- (008FA810) --------------------------------------------------------
int __stdcall cNet::GetGroupConnectionSettings(cNet *this, unsigned int a, unsigned int b, void *c, unsigned int *d)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 148))(
		cNet::gDP,
		a,
		b,
		c,
		d);
}

//----- (008FA840) --------------------------------------------------------
int __stdcall cNet::InitializeConnection(cNet *this, void *a, unsigned int b)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 152))(cNet::gDP, a, b);
}

//----- (008FA870) --------------------------------------------------------
int __stdcall cNet::SecureOpen(cNet *this, DPSESSIONDESC2 *a, unsigned int b, DPSECURITYDESC *c, DPCREDENTIALS *d)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 156))(
		cNet::gDP,
		a,
		b,
		c,
		d);
}

//----- (008FA8A0) --------------------------------------------------------
int __stdcall cNet::SendChatMessage(cNet *this, unsigned int a, unsigned int b, unsigned int c, DPCHAT *d)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 160))(
		cNet::gDP,
		a,
		b,
		c,
		d);
}

//----- (008FA8D0) --------------------------------------------------------
int __stdcall cNet::SetGroupConnectionSettings(cNet *this, unsigned int a, unsigned int b, DPLCONNECTION *c)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 164))(cNet::gDP, a, b, c);
}

//----- (008FA900) --------------------------------------------------------
int __stdcall cNet::StartSession(cNet *this, unsigned int a, unsigned int b)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 168))(cNet::gDP, a, b);
}

//----- (008FA930) --------------------------------------------------------
int __stdcall cNet::GetGroupFlags(cNet *this, unsigned int a, unsigned int *b)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 172))(cNet::gDP, a, b);
}

//----- (008FA960) --------------------------------------------------------
int __stdcall cNet::GetGroupParent(cNet *this, unsigned int a, unsigned int *b)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 176))(cNet::gDP, a, b);
}

//----- (008FA990) --------------------------------------------------------
int __stdcall cNet::GetPlayerAccount(cNet *this, unsigned int a, unsigned int b, void *c, unsigned int *d)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 180))(
		cNet::gDP,
		a,
		b,
		c,
		d);
}

//----- (008FA9C0) --------------------------------------------------------
int __stdcall cNet::GetPlayerFlags(cNet *this, unsigned int a, unsigned int *b)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 184))(cNet::gDP, a, b);
}

//----- (008FA9F0) --------------------------------------------------------
int __stdcall cNet::GetGroupOwner(cNet *this, unsigned int a, unsigned int *b)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 188))(cNet::gDP, a, b);
}

//----- (008FAA20) --------------------------------------------------------
int __stdcall cNet::SetGroupOwner(cNet *this, unsigned int a, unsigned int b)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 192))(cNet::gDP, a, b);
}

//----- (008FAA50) --------------------------------------------------------
int __stdcall cNet::GetMessageQueue(cNet *this, unsigned int a, unsigned int b, unsigned int c, unsigned int *d, unsigned int *e)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 200))(
		cNet::gDP,
		a,
		b,
		c,
		d,
		e);
}

//----- (008FAA80) --------------------------------------------------------
int __stdcall cNet::CancelMessage(cNet *this, unsigned int a, unsigned int b)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 204))(cNet::gDP, a, b);
}

//----- (008FAAB0) --------------------------------------------------------
int __stdcall cNet::CancelPriority(cNet *this, unsigned int a, unsigned int b, unsigned int c)
{
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)cNet::gDP + 208))(cNet::gDP, a, b, c);
}

//----- (008FAAE0) --------------------------------------------------------
void *__thiscall cNet::_scalar_deleting_destructor_(cNet *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cNet::_cNet(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FAB10) --------------------------------------------------------
void __thiscall cNet::_cNet(cNet *this)
{
	cCTAggregateMemberControl<0> *v1; // [sp+0h] [bp-8h]@2
	cCTDelegating<INet> *thisa; // [sp+4h] [bp-4h]@1

	thisa = (cCTDelegating<INet> *)this;
	if (this)
		v1 = &this->baseclass_8;
	else
		v1 = 0;
	cCTAggregateMemberControl<0>::_cCTAggregateMemberControl<0>(v1);
	cCTDelegating<INet>::_cCTDelegating<INet>(thisa);
}

//----- (008FAB50) --------------------------------------------------------
void __thiscall cCTDelegating<INet>::cCTDelegating<INet>(cCTDelegating<INet> *this)
{
	cCTDelegating<INet> *v1; // ST00_4@1

	v1 = this;
	INet::INet(&this->baseclass_0);
	v1->__m_pOuterUnknown = 0;
	v1->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTDelegating<INet>::_vftable_;
}
// 9A9120: using guessed type int (__stdcall *cCTDelegating_INet____vftable_)(int this, int id, int ppI);

//----- (008FAB80) --------------------------------------------------------
void __thiscall cCTDelegating<INet>::_cCTDelegating<INet>(cCTDelegating<INet> *this)
{
	this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTDelegating<INet>::_vftable_;
}
// 9A9120: using guessed type int (__stdcall *cCTDelegating_INet____vftable_)(int this, int id, int ppI);

//----- (008FABA0) --------------------------------------------------------
void __thiscall cCTDelegating<INet>::InitDelegation(cCTDelegating<INet> *this, IUnknown *pOuterUnknown)
{
	this->__m_pOuterUnknown = pOuterUnknown;
}

//----- (008FABC0) --------------------------------------------------------
int __stdcall cCTDelegating<INet>::QueryInterface(cCTDelegating<INet> *this, _GUID *id, void **ppI)
{
	return (**(int(__stdcall ***)(_DWORD, _DWORD, _DWORD))this->__m_pOuterUnknown)(this->__m_pOuterUnknown, id, ppI);
}

//----- (008FABE0) --------------------------------------------------------
unsigned int __stdcall cCTDelegating<INet>::AddRef(cCTDelegating<INet> *this)
{
	return this->__m_pOuterUnknown->vfptr->AddRef(this->__m_pOuterUnknown);
}

//----- (008FAC00) --------------------------------------------------------
unsigned int __stdcall cCTDelegating<INet>::Release(cCTDelegating<INet> *this)
{
	return this->__m_pOuterUnknown->vfptr->Release(this->__m_pOuterUnknown);
}

//----- (008FAC20) --------------------------------------------------------
void *__thiscall cCTDelegating<INet>::_vector_deleting_destructor_(cCTDelegating<INet> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cCTDelegating<INet>::_cCTDelegating<INet>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FAC50) --------------------------------------------------------
void __thiscall INet::INet(INet *this)
{
	INet *v1; // ST00_4@1

	v1 = this;
	IDirectPlay4::IDirectPlay4(&this->baseclass_0);
	v1->baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)INet::_vftable_;
}
// 9A9238: using guessed type int (*INet___vftable_[201])();

//----- (008FAC70) --------------------------------------------------------
void __thiscall IDirectPlay4::IDirectPlay4(IDirectPlay4 *this)
{
	IDirectPlay4 *v1; // ST00_4@1

	v1 = this;
	IDirectPlay3::IDirectPlay3(&this->baseclass_0);
	v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)IDirectPlay4::_vftable_;
}
// 9A934C: using guessed type int (*IDirectPlay4___vftable_[132])();

//----- (008FAC90) --------------------------------------------------------
void __thiscall IDirectPlay3::IDirectPlay3(IDirectPlay3 *this)
{
	IDirectPlay3 *v1; // ST00_4@1

	v1 = this;
	IDirectPlay2::IDirectPlay2(&this->baseclass_0);
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)IDirectPlay3::_vftable_;
}
// 9A9420: using guessed type int (*IDirectPlay3___vftable_[79])();

//----- (008FACB0) --------------------------------------------------------
void __thiscall IDirectPlay2::IDirectPlay2(IDirectPlay2 *this)
{
	IDirectPlay2 *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)IDirectPlay2::_vftable_;
}
// 9A94DC: using guessed type int (*IDirectPlay2___vftable_[32])();

//----- (008FACD0) --------------------------------------------------------
void *__thiscall cNet::_vector_deleting_destructor_(cNet *this, unsigned int a2)
{
	return cNet::_scalar_deleting_destructor_((cNet *)((char *)this - 8), a2);
}

//----- (008FACE0) --------------------------------------------------------
void __cdecl _E2_46()
{
	_E1_28();
}

//----- (008FACEA) --------------------------------------------------------
void __cdecl _E1_28()
{
	cDList<cMessage_1>::cDList<cMessage_1>(&g_MessageQueue);
}

//----- (008FACF9) --------------------------------------------------------
long double __cdecl OldCurvedRand(long double shape)
{
	return (1.0 / ((1.0 - shape) * RNG::GetFloat(gRNGFibonacci) + shape) - 1.0) / (1.0 / shape - 1.0);
}

//----- (008FAD49) --------------------------------------------------------
long double __cdecl CurvedRand(long double shape)
{
	signed int v1; // eax@2
	signed int i; // [sp+0h] [bp-Ch]@1
	double result; // [sp+4h] [bp-8h]@1

	result = 0.0;
	i = 5;
	while (1)
	{
		v1 = i--;
		if (!v1)
			break;
		result = OldCurvedRand(shape) + result;
	}
	return result / 5.0;
}

//----- (008FAD99) --------------------------------------------------------
long double __cdecl AverageForShape(long double s)
{
	double v1; // st7@0

	log(SLODWORD(s), SLOBYTE(s));
	return (s - v1 - 1.0) / (1.0 - s) * s / (1.0 - s);
}

//----- (008FADD0) --------------------------------------------------------
int __cdecl ComputeShapeForAverageTable()
{
	int result; // eax@4
	double shape; // [sp+8h] [bp-20h]@1
	double delta; // [sp+10h] [bp-18h]@1
	signed int i; // [sp+18h] [bp-10h]@1

	shape = 0.0;
	delta = 0.0001;
	for (i = 1; i < 50; ++i)
	{
		do
		{
			shape = shape + delta;
			delta = delta + 0.0001;
		} while (AverageForShape(shape) < (double)i / 100.0);
		LODWORD(g_ShapeForAverage[i]) = LODWORD(shape);
		HIDWORD(g_ShapeForAverage[i]) = HIDWORD(shape);
		result = i + 1;
	}
	return result;
}

//----- (008FAE6F) --------------------------------------------------------
unsigned int __cdecl NextMessageLatency()
{
	signed __int64 v0; // qax@2
	const char *v1; // eax@7
	long double v2; // ST34_8@8
	unsigned int averageAsPercent; // [sp+20h] [bp-Ch]@3

	if (g_MaxLatency == g_MinLatency)
	{
		LODWORD(v0) = g_MinLatency;
	}
	else
	{
		averageAsPercent = 100 * (g_AveLatency - g_MinLatency) / (g_MaxLatency - g_MinLatency);
		if ((signed int)averageAsPercent >= 1)
		{
			if ((signed int)averageAsPercent < 1 || (signed int)averageAsPercent > 49)
			{
				v1 = _LogFmt("Bad average latency");
				_CriticalMsg(v1, "x:\\prj\\tech\\libsrc\\net\\msgdelay.cpp", 0x83u);
			}
			LODWORD(v2) = LODWORD(g_ShapeForAverage[averageAsPercent]);
			HIDWORD(v2) = HIDWORD(g_ShapeForAverage[averageAsPercent]);
			v0 = (signed __int64)(CurvedRand(v2) * (double)g_MaxLatency + (double)g_MinLatency);
		}
		else
		{
			LODWORD(v0) = g_MinLatency;
		}
	}
	return v0;
}

//----- (008FAF54) --------------------------------------------------------
void __thiscall cMessageDelayQueue::DelayMessage(cMessageDelayQueue *this, unsigned int from, unsigned int to, unsigned int flags, void *data, unsigned int size)
{
	cMessage *v6; // eax@9
	cMessage *v7; // [sp+0h] [bp-24h]@9
	void *v8; // [sp+10h] [bp-14h]@8
	unsigned int timeSent; // [sp+14h] [bp-10h]@8
	__int64 lossFreqInt; // [sp+18h] [bp-Ch]@1
	unsigned int lossFreqInt_4; // [sp+1Ch] [bp-8h]@8

	lossFreqInt = (unsigned int)(signed __int64)((double)g_LossPercent / 100.0 * 32767.0);
	if (rand() < (signed int)lossFreqInt)
	{
		if (!(flags & 1))
		{
			if (config_spew_on)
			{
				if (CfgSpewTest("net_delay_spew"))
					CfgDoSpew("NET DELAY: Dropping packet\n");
			}
			return;
		}
		HIDWORD(lossFreqInt) += NextMessageLatency();
		HIDWORD(lossFreqInt) += NextMessageLatency();
	}
	lossFreqInt_4 = NextMessageLatency() + HIDWORD(lossFreqInt);
	timeSent = timeGetTime();
	v8 = operator new(0x24u);
	if (v8)
	{
		cMessage::cMessage((cMessage *)v8, from, to, flags, data, size, timeSent, lossFreqInt_4);
		v7 = v6;
	}
	else
	{
		v7 = 0;
	}
	cDList<cMessage_1>::Append(&g_MessageQueue, v7);
}
// B21A90: using guessed type char config_spew_on;

//----- (008FB065) --------------------------------------------------------
void __thiscall cMessageDelayQueue::NextReadyMessage(cMessageDelayQueue *this, unsigned int *from, unsigned int *to, unsigned int *flags, void **data, unsigned int *size)
{
	cMessage *pMsg; // [sp+8h] [bp-8h]@1
	DWORD currentTime; // [sp+Ch] [bp-4h]@1

	pMsg = cDList<cMessage_1>::GetFirst(&g_MessageQueue);
	*data = 0;
	currentTime = timeGetTime();
	if (pMsg && pMsg->m_Delay + pMsg->m_TimeSent < currentTime)
	{
		if (config_spew_on)
		{
			if (CfgSpewTest("net_delay_spew"))
				CfgDoSpew("NET DELAY: Packet delayed %d, wanted %d\n");
		}
		cDList<cMessage_1>::Remove(&g_MessageQueue, pMsg);
		*from = pMsg->m_From;
		*to = pMsg->m_To;
		*flags = pMsg->m_Flags;
		*data = pMsg->m_Data;
		*size = pMsg->m_Size;
		operator delete(pMsg);
	}
}
// B21A90: using guessed type char config_spew_on;

//----- (008FB14F) --------------------------------------------------------
void __thiscall cMessageDelayQueue::Init(cMessageDelayQueue *this)
{
	RandInit(3);
	ComputeShapeForAverageTable();
}

//----- (008FB169) --------------------------------------------------------
void __thiscall cMessageDelayQueue::SetFullInternetParameters(cMessageDelayQueue *this, unsigned int lossPercent, unsigned int minLatency, unsigned int aveLatency, unsigned int maxLatency, unsigned int spikePercent, unsigned int spikeLatency)
{
	g_MinLatency = minLatency;
	g_AveLatency = aveLatency;
	g_MaxLatency = maxLatency;
	g_SpikeLatency = spikeLatency;
	g_SpikePercent = spikePercent;
	g_LossPercent = lossPercent;
}

//----- (008FB1AA) --------------------------------------------------------
void __thiscall cMessageDelayQueue::GetFullInternetParameters(cMessageDelayQueue *this, unsigned int *lossPercent, unsigned int *minLatency, unsigned int *aveLatency, unsigned int *maxLatency, unsigned int *spikePercent, unsigned int *spikeLatency)
{
	*minLatency = g_MinLatency;
	*aveLatency = g_AveLatency;
	*maxLatency = g_MaxLatency;
	*spikeLatency = g_SpikeLatency;
	*spikePercent = g_SpikePercent;
	*lossPercent = g_LossPercent;
}

//----- (008FB1F7) --------------------------------------------------------
void __thiscall cMessageDelayQueue::SetInternetParameters(cMessageDelayQueue *this, unsigned int lossPercent, unsigned int minLatency, unsigned int aveLatency, unsigned int maxLatency)
{
	g_MinLatency = minLatency;
	g_AveLatency = aveLatency;
	g_MaxLatency = maxLatency;
	g_LossPercent = lossPercent;
	g_SpikePercent = 0;
	g_SpikeLatency = 0;
}

//----- (008FB23A) --------------------------------------------------------
void __thiscall cMessageDelayQueue::GetInternetParameters(cMessageDelayQueue *this, unsigned int *lossPercent, unsigned int *minLatency, unsigned int *aveLatency, unsigned int *maxLatency)
{
	*minLatency = g_MinLatency;
	*aveLatency = g_AveLatency;
	*maxLatency = g_MaxLatency;
	*lossPercent = g_LossPercent;
}

//----- (008FB280) --------------------------------------------------------
void __thiscall cDList<cMessage_1>::cDList<cMessage_1>(cDList<cMessage, 1> *this)
{
	cDListBase::cDListBase(&this->baseclass_0);
}

//----- (008FB2A0) --------------------------------------------------------
void __thiscall cMessage::cMessage(cMessage *this, unsigned int from, unsigned int to, unsigned int flags, void *data, unsigned int size, unsigned int timeSent, unsigned int delay)
{
	cMessage *v8; // ST00_4@1

	v8 = this;
	cDListNode<cMessage_1>::cDListNode<cMessage_1>(&this->baseclass_0);
	v8->m_From = from;
	v8->m_To = to;
	v8->m_Flags = flags;
	v8->m_Data = data;
	v8->m_Size = size;
	v8->m_TimeSent = timeSent;
	v8->m_Delay = delay;
}

//----- (008FB300) --------------------------------------------------------
void __thiscall cDListNode<cMessage_1>::cDListNode<cMessage_1>(cDListNode<cMessage, 1> *this)
{
	cDListNodeBase::cDListNodeBase(&this->baseclass_0);
}

//----- (008FB320) --------------------------------------------------------
void __thiscall cDList<cMessage_1>::Append(cDList<cMessage, 1> *this, cMessage *Node)
{
	cDListBase::Append(&this->baseclass_0, &Node->baseclass_0.baseclass_0);
}

//----- (008FB340) --------------------------------------------------------
cMessage *__thiscall cDList<cMessage_1>::Remove(cDList<cMessage, 1> *this, cMessage *Node)
{
	return (cMessage *)cDListBase::Remove(&this->baseclass_0, &Node->baseclass_0.baseclass_0);
}

//----- (008FB360) --------------------------------------------------------
cMessage *__thiscall cDList<cMessage_1>::GetFirst(cDList<cMessage, 1> *this)
{
	return (cMessage *)cDListBase::GetFirst(&this->baseclass_0);
}
