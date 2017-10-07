//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>


//----- (008E8EE0) --------------------------------------------------------
void __thiscall cStringResEntry::cStringResEntry(cStringResEntry *this, const char *pName, int nIndex)
{
	size_t v3; // eax@2
	char **thisa; // [sp+0h] [bp-4h]@1

	thisa = (char **)this;
	this->m_pName = 0;
	this->m_nIndex = nIndex;
	if (pName)
	{
		v3 = strlen(pName);
		*thisa = (char *)f_malloc_db(v3 + 1, "x:\\prj\\tech\\libsrc\\namedres\\resstr.cpp", 38);
		strcpy(*thisa, pName);
	}
	else
	{
		DbgReportWarning("cStringResEntry created with no name!\n");
	}
}
// B19510: using guessed type int (__cdecl *f_malloc_db)(_DWORD, _DWORD, _DWORD);

//----- (008E8F4E) --------------------------------------------------------
void __thiscall cStringResEntry::_cStringResEntry(cStringResEntry *this)
{
	cStringResEntry *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (this->m_pName)
	{
		j__free(this->m_pName);
		thisa->m_pName = 0;
	}
}

//----- (008E8F78) --------------------------------------------------------
void __thiscall cStringResIndexHash::cStringResIndexHash(cStringResIndexHash *this)
{
	cStringResIndexHash *v1; // ST04_4@1

	v1 = this;
	cStrIHashSet<cStringResEntry__>::cStrIHashSet<cStringResEntry__>(&this->baseclass_0, 0x65u);
	v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStringResIndexHash::_vftable_;
}
// 9A8670: using guessed type int (__stdcall *cStringResIndexHash___vftable_)(int __flags);

//----- (008E8F99) --------------------------------------------------------
void __thiscall cStringResIndexHash::_cStringResIndexHash(cStringResIndexHash *this)
{
	cStrIHashSet<cStringResEntry *> *v1; // ST00_4@1

	v1 = (cStrIHashSet<cStringResEntry *> *)this;
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStringResIndexHash::_vftable_;
	cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>::DestroyAll(&this->baseclass_0.baseclass_0);
	cStrIHashSet<cStringResEntry__>::_cStrIHashSet<cStringResEntry__>(v1);
}
// 9A8670: using guessed type int (__stdcall *cStringResIndexHash___vftable_)(int __flags);

//----- (008E8FBD) --------------------------------------------------------
tHashSetKey__ *__thiscall cStringResIndexHash::GetKey(cStringResIndexHash *this, tHashSetNode__ *node)
{
	return (tHashSetKey__ *)node->unused;
}

//----- (008E8FCF) --------------------------------------------------------
int __thiscall cStringResource::SkipLine(cStringResource *this, IStoreStream *pStream)
{
	int result; // eax@2
	__int16 ci; // [sp+4h] [bp-8h]@1
	__int16 cia; // [sp+4h] [bp-8h]@5
	char c; // [sp+8h] [bp-4h]@3

	ci = ((int(__stdcall *)(IStoreStream *))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
	if (ci == -1)
	{
		result = 0;
	}
	else
	{
		for (c = ci; c != 10; c = cia)
		{
			cia = ((int(__stdcall *)(IStoreStream *))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
			if (cia == -1)
				return 0;
		}
		result = 1;
	}
	return result;
}

//----- (008E9034) --------------------------------------------------------
int __thiscall cStringResource::SkipWhitespace(cStringResource *this, IStoreStream *pStream)
{
	int result; // eax@2
	unsigned int v3; // eax@31
	unsigned int v4; // eax@35
	__int16 ci; // [sp+4h] [bp-Ch]@1
	__int16 cia; // [sp+4h] [bp-Ch]@10
	__int16 cib; // [sp+4h] [bp-Ch]@14
	__int16 cic; // [sp+4h] [bp-Ch]@20
	__int16 cid; // [sp+4h] [bp-Ch]@24
	__int16 cie; // [sp+4h] [bp-Ch]@27
	__int16 cif; // [sp+4h] [bp-Ch]@32
	char c2; // [sp+8h] [bp-8h]@12
	char c; // [sp+Ch] [bp-4h]@3
	char ca; // [sp+Ch] [bp-4h]@22

	ci = ((int(__stdcall *)(IStoreStream *))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
	if (ci == -1)
	{
		result = 0;
	}
	else
	{
		for (c = ci; c == 32 || c == 9 || c == 10 || c == 13 || c == 47; c = cif)
		{
			if (c == 47)
			{
				cia = ((int(__stdcall *)(IStoreStream *))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
				if (cia == -1)
					return 0;
				c2 = cia;
				if ((char)cia == 47)
				{
					while (c != 10)
					{
						cib = ((int(__stdcall *)(_DWORD))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
						if (cib == -1)
							return 0;
						c = cib;
					}
				}
				else
				{
					if ((char)cia != 42)
					{
						v3 = pStream->baseclass_0.vfptr[2].Release((IUnknown *)pStream);
						((void(__stdcall *)(IStoreStream *, unsigned int))pStream->baseclass_0.vfptr[2].AddRef)(pStream, v3 - 2);
						return 1;
					}
					while (c2 != 47)
					{
						cic = ((int(__stdcall *)(_DWORD))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
						if (cic == -1)
							return 0;
						for (ca = cic; ca != 42; ca = cid)
						{
							cid = ((int(__stdcall *)(_DWORD))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
							if (cid == -1)
								return 0;
						}
						cie = ((int(__stdcall *)(_DWORD))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
						if (cie == -1)
							return 0;
						c2 = cie;
					}
				}
			}
			cif = ((int(__stdcall *)(_DWORD))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
			if (cif == -1)
				return 0;
		}
		v4 = pStream->baseclass_0.vfptr[2].Release((IUnknown *)pStream);
		((void(__stdcall *)(IStoreStream *, unsigned int))pStream->baseclass_0.vfptr[2].AddRef)(pStream, v4 - 1);
		result = 1;
	}
	return result;
}

//----- (008E920F) --------------------------------------------------------
int __thiscall cStringResource::GetStrName(cStringResource *this, IStoreStream *pStream, char *buf)
{
	int result; // eax@3
	unsigned int v4; // eax@16
	cStringResource *thisa; // [sp+0h] [bp-10h]@1
	__int16 ci; // [sp+4h] [bp-Ch]@4
	__int16 cia; // [sp+4h] [bp-Ch]@13
	__int16 cib; // [sp+4h] [bp-Ch]@22
	char c; // [sp+8h] [bp-8h]@6
	signed int idx; // [sp+Ch] [bp-4h]@2

	thisa = this;
linestart:
	while (2)
	{
		idx = 0;
		if (cStringResource::SkipWhitespace(thisa, pStream))
		{
			ci = ((int(__stdcall *)(IStoreStream *))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
			if (ci == -1)
			{
				result = 0;
			}
			else
			{
				for (c = ci; isalnum(c) || c == 95; c = cia)
				{
					if (idx >= 64)
					{
						thisa = (cStringResource *)((int(__stdcall *)(IStoreStream *, cStringResource *))pStream->baseclass_0.vfptr[2].Release)(
							pStream,
							thisa);
						((void(__cdecl *)(IStringRes *))thisa->baseclass_0.baseclass_8.baseclass_0.baseclass_0.baseclass_0.vfptr[2].AddRef)(&thisa->baseclass_0.baseclass_8);
						DbgReportWarning("cStringRes: name too long in %s, near char %ld\n");
						if (cStringResource::SkipLine(thisa, pStream))
							goto linestart;
						return 0;
					}
					buf[idx++] = c;
					cia = ((int(__stdcall *)(IStoreStream *))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
					if (cia == -1)
						return 0;
				}
				v4 = pStream->baseclass_0.vfptr[2].Release((IUnknown *)pStream);
				((void(__stdcall *)(IStoreStream *, unsigned int))pStream->baseclass_0.vfptr[2].AddRef)(pStream, v4 - 1);
				if (idx)
				{
					buf[idx] = 0;
					if (!cStringResource::SkipWhitespace(thisa, pStream))
						return 0;
					cib = ((int(__stdcall *)(_DWORD))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
					if (cib == -1)
						return 0;
					if ((char)cib == 58)
					{
						result = 1;
					}
					else
					{
						thisa = (cStringResource *)((int(__stdcall *)(IStoreStream *, cStringResource *))pStream->baseclass_0.vfptr[2].Release)(
							pStream,
							thisa);
						((void(__cdecl *)(IStringRes *))thisa->baseclass_0.baseclass_8.baseclass_0.baseclass_0.baseclass_0.vfptr[2].AddRef)(&thisa->baseclass_0.baseclass_8);
						DbgReportWarning("cStringRes: GetStrName: expected colon in %s, near char %ld\n");
						if (cStringResource::SkipLine(thisa, pStream))
							continue;
						result = 0;
					}
				}
				else
				{
					thisa = (cStringResource *)((int(__stdcall *)(_DWORD, _DWORD))pStream->baseclass_0.vfptr[2].Release)(
						pStream,
						thisa);
					((void(__cdecl *)(_DWORD))thisa->baseclass_0.baseclass_8.baseclass_0.baseclass_0.baseclass_0.vfptr[2].AddRef)(&thisa->baseclass_0.baseclass_8);
					DbgReportWarning("cStringRes: GetStrName: expected name in %s, near char %ld\n");
					if (cStringResource::SkipLine(thisa, pStream))
						continue;
					result = 0;
				}
			}
		}
		else
		{
			result = 0;
		}
		return result;
	}
}

//----- (008E9410) --------------------------------------------------------
void __thiscall cStringResource::cStringResource(cStringResource *this, IStore *pStore, const char *pName, IResType *pType)
{
	cStringResource *v4; // ST0C_4@1

	v4 = this;
	cResourceBase<IStringRes___GUID_const_IID_IStringRes>::cResourceBase<IStringRes___GUID_const_IID_IStringRes>(
		&this->baseclass_0,
		pStore,
		pName,
		pType);
	v4->baseclass_0.baseclass_0.lpVtbl = (IResHackVtbl *)&cStringResource::_vftable_;
	v4->baseclass_0.baseclass_4.baseclass_0.vfptr = (IUnknownVtbl *)&cStringResource::_vftable_;
	v4->baseclass_0.baseclass_8.baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cStringResource::_vftable_;
}
// 9A8690: using guessed type int (__stdcall *cStringResource___vftable_)(int this, int, int);
// 9A8714: using guessed type int (__stdcall *cStringResource___vftable_)(int this, int, int);
// 9A874C: using guessed type int (__stdcall *cStringResource___vftable_)(int this, int id, int ppI);

//----- (008E9451) --------------------------------------------------------
void *__stdcall cStringResource::LoadData(cStringResource *this, unsigned int *pSize, unsigned int *pTimestamp, IResMemOverride *pResMem)
{
	void *result; // eax@2
	const char *v5; // eax@4
	int v6; // eax@12
	void *v7; // eax@46
	size_t v8; // ST0C_4@53
	char *v9; // eax@53
	void *v10; // ST1C_4@57
	void *v11; // [sp+0h] [bp-94h]@0
	int v12; // [sp+8h] [bp-8Ch]@12
	void *v13; // [sp+10h] [bp-84h]@45
	void *v14; // [sp+14h] [bp-80h]@11
	char name[64]; // [sp+20h] [bp-74h]@16
	int finalSize; // [sp+60h] [bp-34h]@49
	__int16 ci; // [sp+64h] [bp-30h]@20
	cGrowingBlock pBlock; // [sp+68h] [bp-2Ch]@1
	void *pEntry; // [sp+78h] [bp-1Ch]@48
	cAutoResThreadLock __AutoResThreadLock__; // [sp+7Ch] [bp-18h]@1
	IStoreStream *pStream; // [sp+80h] [bp-14h]@3
	char c; // [sp+84h] [bp-10h]@22
	int stringStart; // [sp+88h] [bp-Ch]@28
	int pTable; // [sp+8Ch] [bp-8h]@9
	int finished; // [sp+90h] [bp-4h]@14

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	cGrowingBlock::cGrowingBlock(&pBlock);
	if (pResMem)
	{
		pStream = (IStoreStream *)this->baseclass_0.baseclass_0.lpVtbl[1].HasSetData((IResHack *)this);
		if (!pStream)
		{
			this->baseclass_0.baseclass_4.baseclass_0.vfptr[2].AddRef((IUnknown *)&this->baseclass_0.baseclass_4);
			v5 = _LogFmt("Unable to open stream: %s");
			_CriticalMsg(v5, "x:\\prj\\tech\\libsrc\\namedres\\resstr.cpp", 0x133u);
		}
		if (pStream)
		{
			if (g_pMalloc)
				(*(void(__stdcall **)(int, _DWORD, signed int))(*(_DWORD *)g_pMalloc + 72))(
				g_pMalloc,
				"x:\\prj\\tech\\libsrc\\namedres\\resstr.cpp",
				312);
			pTable = ((int(__stdcall *)(IResMemOverride *, signed int))pResMem->baseclass_0.vfptr[1].QueryInterface)(
				pResMem,
				8);
			if (g_pMalloc)
				(*(void(__stdcall **)(int))(*(_DWORD *)g_pMalloc + 76))(g_pMalloc);
			v14 = j__new(0x14u, "x:\\prj\\tech\\libsrc\\namedres\\resstr.cpp", 315);
			if (v14)
			{
				cStringResIndexHash::cStringResIndexHash((cStringResIndexHash *)v14);
				v12 = v6;
			}
			else
			{
				v12 = 0;
			}
			*(_DWORD *)pTable = v12;
			finished = 0;
		parseloop:
			while (!finished)
			{
				if (!cStringResource::GetStrName((cStringResource *)((char *)this - 4), pStream, name))
				{
					finished = 1;
					goto parseloop;
				}
				if (!cStringResource::SkipWhitespace((cStringResource *)((char *)this - 4), pStream))
				{
					finished = 1;
					goto parseloop;
				}
				ci = ((int(__stdcall *)(IStoreStream *))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
				if (ci == -1)
				{
					finished = 1;
					goto parseloop;
				}
				c = ci;
				if ((char)ci == 34)
				{
					ci = ((int(__stdcall *)(IStoreStream *))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
					if (ci == -1)
					{
						finished = 1;
						goto parseloop;
					}
					c = ci;
					stringStart = cGrowingBlock::GetSize(&pBlock);
					while (c != 34)
					{
						if (c == 92)
						{
							ci = ((int(__stdcall *)(_DWORD))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
							if (ci == -1)
							{
								finished = 1;
								goto parseloop;
							}
							c = ci;
							switch ((char)ci)
							{
							case 13:
								ci = ((int(__stdcall *)(_DWORD))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
								if (ci == -1)
								{
									finished = 1;
									goto parseloop;
								}
								c = ci;
								break;
							case 10:
								break;
							case 116:
								cGrowingBlock::Append(&pBlock, 9);
								break;
							case 110:
								cGrowingBlock::Append(&pBlock, 10);
								break;
							default:
								cGrowingBlock::Append(&pBlock, c);
								break;
							}
						}
						else
						{
							cGrowingBlock::Append(&pBlock, c);
						}
						ci = ((int(__stdcall *)(_DWORD))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
						if (ci == -1)
						{
							finished = 1;
							goto parseloop;
						}
						c = ci;
					}
					cGrowingBlock::Append(&pBlock, 0);
					v13 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\resstr.cpp", 394);
					if (v13)
					{
						cStringResEntry::cStringResEntry((cStringResEntry *)v13, name, stringStart);
						v11 = v7;
					}
					else
					{
						v11 = 0;
					}
					pEntry = v11;
					cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>::Insert(
						*(cHashSet<cStringResEntry *, char const *, cCaselessStringHashFuncs> **)pTable,
						(cStringResEntry *)v11);
				}
				else
				{
					v11 = (void *)((int(__stdcall *)(IStoreStream *, void *))pStream->baseclass_0.vfptr[2].Release)(pStream, v11);
					((void(__cdecl *)(IResControl *))this->baseclass_0.baseclass_4.baseclass_0.vfptr[2].AddRef)(&this->baseclass_0.baseclass_4);
					DbgReportWarning("cStringRes: expected quote in %s, near char %ld\n");
					if (!cStringResource::SkipLine((cStringResource *)((char *)this - 4), pStream))
						finished = 1;
				}
			}
			finalSize = cGrowingBlock::GetSize(&pBlock);
			if (g_pMalloc)
				(*(void(__stdcall **)(int, _DWORD, signed int))(*(_DWORD *)g_pMalloc + 72))(
				g_pMalloc,
				"x:\\prj\\tech\\libsrc\\namedres\\resstr.cpp",
				400);
			*(_DWORD *)(pTable + 4) = ((int(__stdcall *)(IResMemOverride *, int))pResMem->baseclass_0.vfptr[1].QueryInterface)(
				pResMem,
				finalSize);
			if (g_pMalloc)
				(*(void(__stdcall **)(int))(*(_DWORD *)g_pMalloc + 76))(g_pMalloc);
			v8 = finalSize;
			v9 = cGrowingBlock::GetBlock(&pBlock);
			memcpy(*(void **)(pTable + 4), v9, v8);
			if (pTimestamp)
				*pTimestamp = pStream->baseclass_0.vfptr[4].Release((IUnknown *)pStream);
			pStream->baseclass_0.vfptr[1].Release((IUnknown *)pStream);
			pStream->baseclass_0.vfptr->Release((IUnknown *)pStream);
			if (pSize)
				*pSize = finalSize;
			v10 = (void *)pTable;
			cGrowingBlock::_cGrowingBlock(&pBlock);
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
			result = v10;
		}
		else
		{
			cGrowingBlock::_cGrowingBlock(&pBlock);
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
			result = 0;
		}
	}
	else
	{
		cGrowingBlock::_cGrowingBlock(&pBlock);
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = 0;
	}
	return result;
}
// E81640: using guessed type int g_pMalloc;

//----- (008E997C) --------------------------------------------------------
int __stdcall cStringResource::FreeData(cStringResource *this, void *pData, unsigned int __formal, IResMemOverride *pResMem)
{
	cAutoResThreadLock __AutoResThreadLock__; // [sp+14h] [bp-8h]@1
	void *pTable; // [sp+18h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	pTable = pData;
	((void(__stdcall *)(IResMemOverride *, _DWORD))pResMem->baseclass_0.vfptr[1].AddRef)(pResMem, *((_DWORD *)pData + 1));
	if (*(_DWORD *)pTable)
		(*(void(__thiscall **)(void(__thiscall ***)(_DWORD, _DWORD), signed int))**(void(__thiscall ****)(_DWORD, _DWORD))pTable)(
		*(void(__thiscall ****)(_DWORD, _DWORD))pTable,
		1);
	operator delete(pTable);
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return 1;
}

//----- (008E99F9) --------------------------------------------------------
void __stdcall cStringResource::StringPreload(cStringResource *this, const char *__formal)
{
	void *v2; // ecx@0
	void *__AutoResThreadLock__; // [sp+0h] [bp-4h]@1

	__AutoResThreadLock__ = v2;
	cAutoResThreadLock::cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	this->baseclass_0.baseclass_0.lpVtbl[3].SetData((IResHack *)this, __AutoResThreadLock__);
	cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
}

//----- (008E9A1F) --------------------------------------------------------
char *__stdcall cStringResource::StringLock(cStringResource *this, const char *pStrName)
{
	char *result; // eax@2
	char *v3; // ST04_4@5
	cStringResEntry *pEntry; // [sp+Ch] [bp-Ch]@3
	cAutoResThreadLock __AutoResThreadLock__; // [sp+10h] [bp-8h]@1
	cHashSet<cStringResEntry *, char const *, cCaselessStringHashFuncs> **pTable; // [sp+14h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	pTable = (cHashSet<cStringResEntry *, char const *, cCaselessStringHashFuncs> **)((int(__stdcall *)(cStringResource *))this->baseclass_0.baseclass_0.lpVtbl->SetData)(this);
	if (pTable)
	{
		pEntry = cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>::Search(*pTable, pStrName);
		if (pEntry)
		{
			v3 = (char *)pTable[1] + pEntry->m_nIndex;
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
			result = v3;
		}
		else
		{
			this->baseclass_0.baseclass_0.lpVtbl->HasSetData((IResHack *)this);
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
			result = 0;
		}
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = 0;
	}
	return result;
}

//----- (008E9AAD) --------------------------------------------------------
void __stdcall cStringResource::StringUnlock(cStringResource *this, const char *__formal)
{
	int v2; // ecx@0
	int __AutoResThreadLock__; // [sp+0h] [bp-4h]@1

	__AutoResThreadLock__ = v2;
	cAutoResThreadLock::cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	((void(__stdcall *)(cStringResource *, int))this->baseclass_0.baseclass_0.lpVtbl->HasSetData)(
		this,
		__AutoResThreadLock__);
	cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
}

//----- (008E9AD3) --------------------------------------------------------
int __stdcall cStringResource::StringExtract(cStringResource *this, const char *pStrName, char *pBuf, int nSize)
{
	int result; // eax@2
	cAutoResThreadLock __AutoResThreadLock__; // [sp+8h] [bp-8h]@1
	const char *pStr; // [sp+Ch] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	pStr = (const char *)((int(__stdcall *)(cStringResource *, const char *))this->baseclass_0.baseclass_0.lpVtbl[6].QueryInterface)(
		this,
		pStrName);
	if (pStr)
	{
		strncpy(pBuf, pStr, nSize - 1);
		pBuf[nSize - 1] = 0;
		((void(__stdcall *)(cStringResource *, const char *))this->baseclass_0.baseclass_0.lpVtbl[6].AddRef)(
			this,
			pStrName);
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = 1;
	}
	else
	{
		*pBuf = 0;
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = 0;
	}
	return result;
}

//----- (008E9B60) --------------------------------------------------------
void *__thiscall cStringResIndexHash::_vector_deleting_destructor_(cStringResIndexHash *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStringResIndexHash::_cStringResIndexHash(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E9B90) --------------------------------------------------------
void *__thiscall cStringResource::_vector_deleting_destructor_(cStringResource *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStringResource::_cStringResource(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E9BC0) --------------------------------------------------------
void __thiscall cStringResource::_cStringResource(cStringResource *this)
{
	cResourceBase<IStringRes___GUID_const_IID_IStringRes>::_cResourceBase<IStringRes___GUID_const_IID_IStringRes>(&this->baseclass_0);
}

//----- (008E9BE0) --------------------------------------------------------
void __thiscall cGrowingBlock::cGrowingBlock(cGrowingBlock *this)
{
	cGrowingBlock *v1; // ST0C_4@1

	v1 = this;
	this->m_numIncs = 0;
	this->m_pTempBlock = 0;
	this->m_curp = 0;
	this->m_blocksize = 0;
	this->m_pTempBlock = (char *)f_malloc_db(65536, "x:\\prj\\tech\\libsrc\\namedres\\resstr.cpp", 90);
	v1->m_blocksize = 65536;
	v1->m_numIncs = 1;
}
// B19510: using guessed type int (__cdecl *f_malloc_db)(_DWORD, _DWORD, _DWORD);

//----- (008E9C50) --------------------------------------------------------
void __thiscall cGrowingBlock::_cGrowingBlock(cGrowingBlock *this)
{
	j__free(this->m_pTempBlock);
}

//----- (008E9C70) --------------------------------------------------------
void __thiscall cGrowingBlock::Append(cGrowingBlock *this, char c)
{
	void *v2; // ST10_4@2
	cGrowingBlock *thisa; // [sp+0h] [bp-8h]@1

	thisa = this;
	if (this->m_curp >= this->m_blocksize)
	{
		this->m_blocksize += 65536;
		v2 = (void *)f_malloc_db(this->m_blocksize, "x:\\prj\\tech\\libsrc\\namedres\\resstr.cpp", 105);
		memcpy(v2, thisa->m_pTempBlock, thisa->m_curp);
		j__free(thisa->m_pTempBlock);
		thisa->m_pTempBlock = (char *)v2;
	}
	thisa->m_pTempBlock[thisa->m_curp++] = c;
}
// B19510: using guessed type int (__cdecl *f_malloc_db)(_DWORD, _DWORD, _DWORD);

//----- (008E9D10) --------------------------------------------------------
int __thiscall cGrowingBlock::GetSize(cGrowingBlock *this)
{
	return this->m_curp;
}

//----- (008E9D30) --------------------------------------------------------
char *__thiscall cGrowingBlock::GetBlock(cGrowingBlock *this)
{
	return this->m_pTempBlock;
}

//----- (008E9D50) --------------------------------------------------------
void __thiscall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::OnFinalRelease(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	;
}

//----- (008E9D60) --------------------------------------------------------
unsigned int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::AddRef(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	return cCTRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008E9D80) --------------------------------------------------------
unsigned int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::Release(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	unsigned int result; // eax@2

	if (cCTRefCount::Release(&this->__m_ulRefs))
	{
		result = cCTRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		((void(__thiscall *)(_DWORD))this->baseclass_0.lpVtbl[1].AddRef)(this);
		if (this)
			((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.lpVtbl[1].QueryInterface)(this, 1);
		result = 0;
	}
	return result;
}

//----- (008E9DE0) --------------------------------------------------------
cStringResEntry *__thiscall cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>::Insert(cHashSet<cStringResEntry *, char const *, cCaselessStringHashFuncs> *this, cStringResEntry *node)
{
	return (cStringResEntry *)cHashSetBase::Insert(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008E9E00) --------------------------------------------------------
cStringResEntry *__thiscall cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>::Search(cHashSet<cStringResEntry *, char const *, cCaselessStringHashFuncs> *this, const char *key)
{
	return (cStringResEntry *)cHashSetBase::Search(&this->baseclass_0, (tHashSetKey__ *)key);
}

//----- (008E9E20) --------------------------------------------------------
void __thiscall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::cResourceBase<IStringRes___GUID_const_IID_IStringRes>(cResourceBase<IStringRes, &IID_IStringRes> *this, IStore *pStore, const char *pName, IResType *pType)
{
	cResourceBase<IStringRes, &IID_IStringRes> *thisa; // [sp+0h] [bp-8h]@1
	IUnknown *pResMan; // [sp+4h] [bp-4h]@1

	thisa = this;
	IResHack::IResHack(&this->baseclass_0);
	IResControl::IResControl(&thisa->baseclass_4);
	IStringRes::IStringRes(&thisa->baseclass_8);
	thisa->m_ulRefs = 1;
	thisa->m_bAllowStorageReset = 1;
	thisa->m_pStore = 0;
	thisa->m_pCanonStore = 0;
	thisa->m_bDoingAsynch = 0;
	thisa->m_pName = 0;
	thisa->m_pExt = 0;
	thisa->m_pType = 0;
	thisa->m_AppData = -1;
	thisa->m_ManData = -1;
	thisa->m_pStream = 0;
	thisa->m_pAssignedData = 0;
	thisa->m_nAssignedCount = 0;
	cCTRefCount::cCTRefCount(&thisa->__m_ulRefs);
	thisa->baseclass_0.lpVtbl = (IResHackVtbl *)&cResourceBase<IStringRes___GUID_const_IID_IStringRes>::_vftable_;
	thisa->baseclass_4.baseclass_0.vfptr = (IUnknownVtbl *)&cResourceBase<IStringRes___GUID_const_IID_IStringRes>::_vftable_;
	thisa->baseclass_8.baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cResourceBase<IStringRes___GUID_const_IID_IStringRes>::_vftable_;
	pResMan = _AppGetAggregated(&IID_IResMan);
	if (!pResMan)
		_CriticalMsg("No Resource Manager for a resource!", "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 0x7Cu);
	if (pResMan->vfptr->QueryInterface(pResMan, &IID_IResManHelper, (void **)&thisa->m_pResMan) < 0)
		_CriticalMsg(
		"Resource Manager does not implement IResManHelper!",
		"x:\\prj\\tech\\libsrc\\namedres\\resbastm.h",
		0x7Fu);
	pResMan->vfptr->Release(pResMan);
	if (pStore)
		cResourceBase<IStringRes___GUID_const_IID_IStringRes>::SetStore(
		(cResourceBase<IStringRes, &IID_IStringRes> *)((char *)thisa + 4),
		pStore);
	if (pName)
		cResourceBase<IStringRes___GUID_const_IID_IStringRes>::SetName(
		(cResourceBase<IStringRes, &IID_IStringRes> *)((char *)thisa + 4),
		pName);
	if (pType)
	{
		thisa->m_pType = pType;
		pType->baseclass_0.vfptr->AddRef((IUnknown *)pType);
	}
}
// 9A8768: using guessed type int (__stdcall *cResourceBase_IStringRes___GUID const IID_IStringRes____vftable_)(int this, int, int);
// 9A87EC: using guessed type int (__stdcall *cResourceBase_IStringRes___GUID const IID_IStringRes____vftable_)(int this, int, int);
// 9A8824: using guessed type int (__stdcall *cResourceBase_IStringRes___GUID const IID_IStringRes____vftable_)(int this, int id, int ppI);









