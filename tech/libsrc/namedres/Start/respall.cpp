//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>





//----- (008EBCB0) --------------------------------------------------------
void __thiscall cPaletteResource::cPaletteResource(cPaletteResource *this, IStore *pStore, const char *pName, IResType *pType, ePalKind Kind)
{
	cPaletteResource *v5; // ST0C_4@1

	v5 = this;
	cResourceBase<IRes___GUID_const_IID_IRes>::cResourceBase<IRes___GUID_const_IID_IRes>(
		&this->baseclass_0,
		pStore,
		pName,
		pType);
	v5->m_Kind = Kind;
	v5->baseclass_0.baseclass_0.lpVtbl = (IResHackVtbl *)&cPaletteResource::_vftable_;
	v5->baseclass_0.baseclass_4.baseclass_0.vfptr = (IUnknownVtbl *)&cPaletteResource::_vftable_;
	v5->baseclass_0.baseclass_8.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cPaletteResource::_vftable_;
}
// 9A898C: using guessed type int (__stdcall *cPaletteResource___vftable_)(int this, int, int);
// 9A8A00: using guessed type int (__stdcall *cPaletteResource___vftable_)(int this, int, int);
// 9A8A38: using guessed type int (__stdcall *cPaletteResource___vftable_)(int this, int id, int ppI);

//----- (008EBCFA) --------------------------------------------------------
void *__stdcall cPaletteResource::LoadData(cPaletteResource *this, unsigned int *pSize, unsigned int *pTimestamp, IResMemOverride *pResMem)
{
	void *result; // eax@2
	const char *v5; // eax@4
	void *v6; // ST14_4@17
	cAutoResThreadLock __AutoResThreadLock__; // [sp+Ch] [bp-Ch]@3
	IStoreStream *pStream; // [sp+10h] [bp-8h]@3
	void *pData; // [sp+14h] [bp-4h]@8

	if (pResMem)
	{
		cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
		pStream = (IStoreStream *)this->baseclass_0.baseclass_0.lpVtbl[1].HasSetData((IResHack *)this);
		if (!pStream)
		{
			this->baseclass_0.baseclass_4.baseclass_0.vfptr[2].AddRef((IUnknown *)&this->baseclass_0.baseclass_4);
			v5 = _LogFmt("Unable to open stream: %s");
			_CriticalMsg(v5, "x:\\prj\\tech\\libsrc\\namedres\\respall.cpp", 0x3Eu);
		}
		if (pStream)
		{
			switch (this->baseclass_0.__m_ulRefs.ul)
			{
			case 0u:
				pData = ResBmpReadPalette(pStream, pResMem);
				break;
			case 1u:
				pData = ResCelReadPalette(pStream, pResMem);
				break;
			case 2u:
				pData = ResGifReadPalette(pStream, pResMem);
				break;
			case 3u:
				pData = ResPcxReadPalette(pStream, pResMem);
				break;
			case 4u:
				pData = ResTgaReadPalette(pStream, pResMem);
				break;
			default:
				break;
			}
			if (pTimestamp)
				*pTimestamp = pStream->baseclass_0.vfptr[4].Release((IUnknown *)pStream);
			pStream->baseclass_0.vfptr[1].Release((IUnknown *)pStream);
			pStream->baseclass_0.vfptr->Release((IUnknown *)pStream);
			if (pSize)
				*pSize = ((int(__stdcall *)(IResMemOverride *, void *))pResMem->baseclass_0.vfptr[1].Release)(pResMem, pData);
			v6 = pData;
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
			result = v6;
		}
		else
		{
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
			result = 0;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008EBE6F) --------------------------------------------------------
int __stdcall cPaletteResource::ExtractPartial(cPaletteResource *this, const int nStart, const int nEnd, void *pBuf)
{
	cPaletteResource *v5; // [sp+0h] [bp-2Ch]@22
	cPaletteResource *v6; // [sp+4h] [bp-28h]@13
	cPaletteResource *v7; // [sp+8h] [bp-24h]@9
	cPaletteResource *v8; // [sp+Ch] [bp-20h]@4
	int nNumToRead; // [sp+18h] [bp-14h]@18
	char bLocked; // [sp+1Ch] [bp-10h]@1
	cAutoResThreadLock __AutoResThreadLock__; // [sp+20h] [bp-Ch]@3
	int pData; // [sp+24h] [bp-8h]@6
	int nSize; // [sp+28h] [bp-4h]@6

	bLocked = 0;
	if (!pBuf)
		return 0;
	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this == (cPaletteResource *)8)
		v8 = 0;
	else
		v8 = this;
	pData = (*(int(__stdcall **)(unsigned int, cPaletteResource *, int *))(*(_DWORD *)this->baseclass_0.m_ulRefs + 20))(
		this->baseclass_0.m_ulRefs,
		v8,
		&nSize);
	if (!pData || !nSize)
	{
		if (this == (cPaletteResource *)8)
			v7 = 0;
		else
			v7 = this;
		pData = (*(int(__stdcall **)(unsigned int, cPaletteResource *))(*(_DWORD *)this->baseclass_0.m_ulRefs + 12))(
			this->baseclass_0.m_ulRefs,
			v7);
		if (!pData)
		{
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
			return 0;
		}
		bLocked = 1;
		if (this == (cPaletteResource *)8)
			v6 = 0;
		else
			v6 = this;
		nSize = (*(int(__stdcall **)(unsigned int, cPaletteResource *))(*(_DWORD *)this->baseclass_0.m_ulRefs + 36))(
			this->baseclass_0.m_ulRefs,
			v6);
	}
	if (nEnd < nSize)
		nNumToRead = nEnd - nStart + 1;
	else
		nNumToRead = nSize - nStart;
	memmove(pBuf, (const void *)(nStart + pData), nNumToRead);
	if (bLocked)
	{
		if (this == (cPaletteResource *)8)
			v5 = 0;
		else
			v5 = this;
		(*(void(__stdcall **)(unsigned int, cPaletteResource *))(*(_DWORD *)this->baseclass_0.m_ulRefs + 24))(
			this->baseclass_0.m_ulRefs,
			v5);
	}
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return nNumToRead;
}

//----- (008EBFE4) --------------------------------------------------------
void __stdcall cPaletteResource::ExtractBlocks(cPaletteResource *this, void *pBuf, const int nSize, int(__cdecl *Callback)(IRes *, void *, int, int, void *), void *pClientData)
{
	int v5; // ST0C_4@22
	cPaletteResource *v6; // [sp+0h] [bp-30h]@25
	IRes *v7; // [sp+8h] [bp-28h]@20
	cPaletteResource *v8; // [sp+Ch] [bp-24h]@11
	cPaletteResource *v9; // [sp+10h] [bp-20h]@7
	cPaletteResource *v10; // [sp+14h] [bp-1Ch]@2
	char bLocked; // [sp+18h] [bp-18h]@1
	const int nMove; // [sp+1Ch] [bp-14h]@17
	cAutoResThreadLock __AutoResThreadLock__; // [sp+20h] [bp-10h]@1
	int nRemain; // [sp+24h] [bp-Ch]@4
	const void *pData; // [sp+28h] [bp-8h]@4
	int nIx; // [sp+2Ch] [bp-4h]@1

	bLocked = 0;
	nIx = 0;
	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this == (cPaletteResource *)8)
		v10 = 0;
	else
		v10 = this;
	pData = (const void *)(*(int(__stdcall **)(unsigned int, cPaletteResource *, int *))(*(_DWORD *)this->baseclass_0.m_ulRefs
		+ 20))(
		this->baseclass_0.m_ulRefs,
		v10,
		&nRemain);
	if (!pData || !nSize)
	{
		if (this == (cPaletteResource *)8)
			v9 = 0;
		else
			v9 = this;
		pData = (const void *)(*(int(__stdcall **)(unsigned int, cPaletteResource *))(*(_DWORD *)this->baseclass_0.m_ulRefs
			+ 12))(
			this->baseclass_0.m_ulRefs,
			v9);
		if (!pData)
		{
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
			return;
		}
		bLocked = 1;
		if (this == (cPaletteResource *)8)
			v8 = 0;
		else
			v8 = this;
		nRemain = (*(int(__stdcall **)(unsigned int, cPaletteResource *))(*(_DWORD *)this->baseclass_0.m_ulRefs + 36))(
			this->baseclass_0.m_ulRefs,
			v8);
	}
	while (nRemain > 0)
	{
		if (nRemain >= nSize)
			nMove = nSize;
		else
			nMove = nRemain;
		memmove(pBuf, pData, nMove);
		if (this == (cPaletteResource *)8)
			v7 = 0;
		else
			v7 = (IRes *)this;
		v5 = nIx++;
		Callback(v7, pBuf, nMove, v5, pClientData);
		pData = (char *)pData + nMove;
		nRemain -= nMove;
	}
	if (bLocked)
	{
		if (this == (cPaletteResource *)8)
			v6 = 0;
		else
			v6 = this;
		(*(void(__stdcall **)(unsigned int, cPaletteResource *))(*(_DWORD *)this->baseclass_0.m_ulRefs + 24))(
			this->baseclass_0.m_ulRefs,
			v6);
	}
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
}

//----- (008EC1A0) --------------------------------------------------------
void *__thiscall cPaletteResource::_vector_deleting_destructor_(cPaletteResource *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cPaletteResource::_cPaletteResource(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008EC1D0) --------------------------------------------------------
void __thiscall cPaletteResource::_cPaletteResource(cPaletteResource *this)
{
	cResourceBase<IRes___GUID_const_IID_IRes>::_cResourceBase<IRes___GUID_const_IID_IRes>(&this->baseclass_0);
}

