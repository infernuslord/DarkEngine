//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>






//----- (008EB6B0) --------------------------------------------------------
void __thiscall cImageResource::cImageResource(cImageResource *this, IStore *pStore, const char *pName, IResType *pType, eImgKind Kind)
{
	cImageResource *v5; // ST0C_4@1

	v5 = this;
	cResourceBase<IRes___GUID_const_IID_IRes>::cResourceBase<IRes___GUID_const_IID_IRes>(
		&this->baseclass_0,
		pStore,
		pName,
		pType);
	v5->m_Kind = Kind;
	v5->baseclass_0.baseclass_0.lpVtbl = (IResHackVtbl *)&cImageResource::_vftable_;
	v5->baseclass_0.baseclass_4.baseclass_0.vfptr = (IUnknownVtbl *)&cImageResource::_vftable_;
	v5->baseclass_0.baseclass_8.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cImageResource::_vftable_;
}
// 9A88C4: using guessed type int (__stdcall *cImageResource___vftable_)(int this, int, int);
// 9A8938: using guessed type int (__stdcall *cImageResource___vftable_)(int this, int, int);
// 9A8970: using guessed type int (__stdcall *cImageResource___vftable_)(int this, int id, int ppI);

//----- (008EB6FA) --------------------------------------------------------
void *__stdcall cImageResource::LoadData(cImageResource *this, unsigned int *pSize, unsigned int *pTimestamp, IResMemOverride *pResMem)
{
	void *result; // eax@2
	const char *v5; // eax@4
	grs_bitmap *bm; // [sp+10h] [bp-Ch]@3
	cAutoResThreadLock __AutoResThreadLock__; // [sp+14h] [bp-8h]@3
	IStoreStream *pStream; // [sp+18h] [bp-4h]@3

	if (pResMem)
	{
		cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
		bm = 0;
		pStream = (IStoreStream *)this->baseclass_0.baseclass_0.lpVtbl[1].HasSetData((IResHack *)this);
		if (!pStream)
		{
			this->baseclass_0.baseclass_4.baseclass_0.vfptr[2].AddRef((IUnknown *)&this->baseclass_0.baseclass_4);
			v5 = _LogFmt("Unable to open stream: %s");
			_CriticalMsg(v5, "x:\\prj\\tech\\libsrc\\namedres\\resimage.cpp", 0x58u);
		}
		if (pStream)
		{
			switch (this->baseclass_0.__m_ulRefs.ul)
			{
			case 0u:
				bm = ResBmpReadImage(pStream, pResMem);
				break;
			case 1u:
				bm = ResCelReadImage(pStream, pResMem);
				break;
			case 2u:
				bm = ResGifReadImage(pStream, pResMem);
				break;
			case 3u:
				bm = ResPcxReadImage(pStream, pResMem);
				break;
			case 4u:
				bm = ResTgaReadImage(pStream, pResMem);
				break;
			default:
				break;
			}
			if (pTimestamp)
				*pTimestamp = pStream->baseclass_0.vfptr[4].Release((IUnknown *)pStream);
			pStream->baseclass_0.vfptr[1].Release((IUnknown *)pStream);
			pStream->baseclass_0.vfptr->Release((IUnknown *)pStream);
			if (bm)
			{
				ImageHackRemap16Bit(bm, 0);
				ImageHackAutoSetTransparency(bm, 0);
				if (pSize)
					*pSize = ((int(__stdcall *)(IResMemOverride *, grs_bitmap *))pResMem->baseclass_0.vfptr[1].Release)(
					pResMem,
					bm);
				cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
				result = bm;
			}
			else
			{
				cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
				result = 0;
			}
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

//----- (008EB8AC) --------------------------------------------------------
int __stdcall cImageResource::FreeData(cImageResource *this, void *pData, unsigned int __formal, IResMemOverride *pResMem)
{
	__int16 v4; // cx@4
	cAutoResThreadLock __AutoResThreadLock__; // [sp+8h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (!pData)
		_CriticalMsg("FreeData: nothing to free!", "x:\\prj\\tech\\libsrc\\namedres\\resimage.cpp", 0x91u);
	if (!this->baseclass_0.m_pStream)
	{
		v4 = *((_WORD *)pData + 3);
		if (v4 & 0x40)
		{
			if (g_tmgr)
				(*(void(__cdecl **)(void *))(g_tmgr + 20))(pData);
		}
	}
	((void(__stdcall *)(IResMemOverride *, void *))pResMem->baseclass_0.vfptr[1].AddRef)(pResMem, pData);
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return 1;
}
// EA67B4: using guessed type int g_tmgr;

//----- (008EB93B) --------------------------------------------------------
int __stdcall cImageResource::ExtractPartial(cImageResource *this, const int nStart, const int nEnd, void *pBuf)
{
	cImageResource *v5; // [sp+0h] [bp-2Ch]@22
	cImageResource *v6; // [sp+4h] [bp-28h]@13
	cImageResource *v7; // [sp+8h] [bp-24h]@9
	cImageResource *v8; // [sp+Ch] [bp-20h]@4
	int nNumToRead; // [sp+18h] [bp-14h]@18
	char bLocked; // [sp+1Ch] [bp-10h]@1
	cAutoResThreadLock __AutoResThreadLock__; // [sp+20h] [bp-Ch]@3
	int pData; // [sp+24h] [bp-8h]@6
	int nSize; // [sp+28h] [bp-4h]@6

	bLocked = 0;
	if (!pBuf)
		return 0;
	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this == (cImageResource *)8)
		v8 = 0;
	else
		v8 = this;
	pData = (*(int(__stdcall **)(unsigned int, cImageResource *, int *))(*(_DWORD *)this->baseclass_0.m_ulRefs + 20))(
		this->baseclass_0.m_ulRefs,
		v8,
		&nSize);
	if (!pData || !nSize)
	{
		if (this == (cImageResource *)8)
			v7 = 0;
		else
			v7 = this;
		pData = (*(int(__stdcall **)(unsigned int, cImageResource *))(*(_DWORD *)this->baseclass_0.m_ulRefs + 12))(
			this->baseclass_0.m_ulRefs,
			v7);
		if (!pData)
		{
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
			return 0;
		}
		bLocked = 1;
		if (this == (cImageResource *)8)
			v6 = 0;
		else
			v6 = this;
		nSize = (*(int(__stdcall **)(unsigned int, cImageResource *))(*(_DWORD *)this->baseclass_0.m_ulRefs + 36))(
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
		if (this == (cImageResource *)8)
			v5 = 0;
		else
			v5 = this;
		(*(void(__stdcall **)(unsigned int, cImageResource *))(*(_DWORD *)this->baseclass_0.m_ulRefs + 24))(
			this->baseclass_0.m_ulRefs,
			v5);
	}
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return nNumToRead;
}

//----- (008EBAB0) --------------------------------------------------------
void __stdcall cImageResource::ExtractBlocks(cImageResource *this, void *pBuf, const int nSize, int(__cdecl *Callback)(IRes *, void *, int, int, void *), void *pClientData)
{
	int v5; // ST0C_4@22
	cImageResource *v6; // [sp+0h] [bp-30h]@25
	IRes *v7; // [sp+8h] [bp-28h]@20
	cImageResource *v8; // [sp+Ch] [bp-24h]@11
	cImageResource *v9; // [sp+10h] [bp-20h]@7
	cImageResource *v10; // [sp+14h] [bp-1Ch]@2
	char bLocked; // [sp+18h] [bp-18h]@1
	const int nMove; // [sp+1Ch] [bp-14h]@17
	cAutoResThreadLock __AutoResThreadLock__; // [sp+20h] [bp-10h]@1
	int nRemain; // [sp+24h] [bp-Ch]@4
	const void *pData; // [sp+28h] [bp-8h]@4
	int nIx; // [sp+2Ch] [bp-4h]@1

	bLocked = 0;
	nIx = 0;
	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this == (cImageResource *)8)
		v10 = 0;
	else
		v10 = this;
	pData = (const void *)(*(int(__stdcall **)(unsigned int, cImageResource *, int *))(*(_DWORD *)this->baseclass_0.m_ulRefs
		+ 20))(
		this->baseclass_0.m_ulRefs,
		v10,
		&nRemain);
	if (!pData || !nSize)
	{
		if (this == (cImageResource *)8)
			v9 = 0;
		else
			v9 = this;
		pData = (const void *)(*(int(__stdcall **)(unsigned int, cImageResource *))(*(_DWORD *)this->baseclass_0.m_ulRefs
			+ 12))(
			this->baseclass_0.m_ulRefs,
			v9);
		if (!pData)
		{
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
			return;
		}
		bLocked = 1;
		if (this == (cImageResource *)8)
			v8 = 0;
		else
			v8 = this;
		nRemain = (*(int(__stdcall **)(unsigned int, cImageResource *))(*(_DWORD *)this->baseclass_0.m_ulRefs + 36))(
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
		if (this == (cImageResource *)8)
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
		if (this == (cImageResource *)8)
			v6 = 0;
		else
			v6 = this;
		(*(void(__stdcall **)(unsigned int, cImageResource *))(*(_DWORD *)this->baseclass_0.m_ulRefs + 24))(
			this->baseclass_0.m_ulRefs,
			v6);
	}
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
}

//----- (008EBC60) --------------------------------------------------------
void *__thiscall cImageResource::_scalar_deleting_destructor_(cImageResource *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cImageResource::_cImageResource(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008EBC90) --------------------------------------------------------
void __thiscall cImageResource::_cImageResource(cImageResource *this)
{
	cResourceBase<IRes___GUID_const_IID_IRes>::_cResourceBase<IRes___GUID_const_IID_IRes>(&this->baseclass_0);
}

