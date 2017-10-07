//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>


//----- (008F1520) --------------------------------------------------------
void __cdecl CelExpandBrun(char *ps, char *bits, __int16 w, __int16 h)
{
	char *pd; // [sp+0h] [bp-14h]@1
	__int16 y; // [sp+4h] [bp-10h]@1
	__int16 i; // [sp+8h] [bp-Ch]@6
	__int16 ia; // [sp+8h] [bp-Ch]@10
	char npix; // [sp+Ch] [bp-8h]@5
	__int16 pixels; // [sp+10h] [bp-4h]@3

	pd = bits;
	for (y = 0; y < h; ++y)
	{
		++ps;
		for (pixels = 0; pixels < w; pixels += npix)
		{
			npix = *ps++;
			if (npix >= 0)
			{
				for (ia = 0; ia < npix; ++ia)
					*pd++ = *ps;
				++ps;
			}
			else
			{
				npix = -npix;
				for (i = 0; i < npix; ++i)
					*pd++ = *ps++;
			}
		}
		if (pixels > w)
		{
			DbgReportWarning("CelExpandBrun: decompress error\n");
			return;
		}
	}
}

//----- (008F1648) --------------------------------------------------------
void __cdecl CelExpandByteDelta(char *ps, char *bits, __int16 w)
{
	__int16 numPackets; // [sp+0h] [bp-24h]@9
	__int16 nskip; // [sp+4h] [bp-20h]@1
	__int16 nskipa; // [sp+4h] [bp-20h]@11
	char *pd; // [sp+8h] [bp-1Ch]@1
	__int16 y; // [sp+Ch] [bp-18h]@1
	__int16 ya; // [sp+Ch] [bp-18h]@7
	__int16 i; // [sp+10h] [bp-14h]@3
	__int16 ia; // [sp+10h] [bp-14h]@11
	__int16 ib; // [sp+10h] [bp-14h]@15
	__int16 ic; // [sp+10h] [bp-14h]@19
	__int16 id; // [sp+10h] [bp-14h]@26
	char npix; // [sp+14h] [bp-10h]@14
	__int16 nlines; // [sp+18h] [bp-Ch]@7
	__int16 ipacket; // [sp+1Ch] [bp-8h]@9
	__int16 xpos; // [sp+20h] [bp-4h]@9
	__int16 xposa; // [sp+20h] [bp-4h]@14
	char *psa; // [sp+2Ch] [bp+8h]@1
	int psb; // [sp+2Ch] [bp+8h]@7
	int psc; // [sp+2Ch] [bp+8h]@11

	pd = bits;
	nskip = *(_WORD *)ps;
	psa = ps + 2;
	for (y = 0; y < nskip; ++y)
	{
		for (i = 0; i < w; ++i)
			*pd++ = 0;
	}
	nlines = *(_WORD *)psa;
	psb = (int)(psa + 2);
	for (ya = 0; ya < nlines; ++ya)
	{
		numPackets = *(_BYTE *)psb++;
		xpos = 0;
		for (ipacket = 0; ipacket < numPackets; ++ipacket)
		{
			nskipa = *(_BYTE *)psb;
			psc = psb + 1;
			for (ia = 0; ia < nskipa; ++ia)
				*pd++ = 0;
			xposa = nskipa + xpos;
			npix = *(_BYTE *)psc;
			psb = psc + 1;
			if (npix >= 0)
			{
				for (ic = 0; ic < npix; ++ic)
					*pd++ = *(_BYTE *)psb++;
			}
			else
			{
				npix = -npix;
				for (ib = 0; ib < npix; ++ib)
					*pd++ = *(_BYTE *)psb;
				++psb;
			}
			xpos = npix + xposa;
		}
		if (xpos > w)
		{
			DbgReportWarning("CelExpandByteDelta: decompress error\n");
			return;
		}
		if (xpos < w)
		{
			for (id = xpos; id < w; ++id)
				*pd++ = 0;
		}
	}
}

//----- (008F1898) --------------------------------------------------------
void __cdecl CelExpandWordDelta(char *ps, char *bits, __int16 w)
{
	int v3; // ST18_4@25
	int v4; // ST18_4@29
	__int16 word; // [sp+0h] [bp-30h]@3
	__int16 numPackets; // [sp+4h] [bp-2Ch]@12
	char nwords; // [sp+8h] [bp-28h]@22
	__int16 nskip; // [sp+Ch] [bp-24h]@19
	int pd; // [sp+10h] [bp-20h]@1
	__int16 j; // [sp+14h] [bp-1Ch]@6
	__int16 y; // [sp+18h] [bp-18h]@1
	__int16 i; // [sp+1Ch] [bp-14h]@4
	__int16 ia; // [sp+1Ch] [bp-14h]@19
	__int16 ib; // [sp+1Ch] [bp-14h]@23
	__int16 ic; // [sp+1Ch] [bp-14h]@27
	__int16 id; // [sp+1Ch] [bp-14h]@34
	__int16 nlines; // [sp+20h] [bp-10h]@1
	__int16 ipacket; // [sp+24h] [bp-Ch]@17
	__int16 xpos; // [sp+28h] [bp-8h]@17
	__int16 xposa; // [sp+28h] [bp-8h]@22
	__int16 lastByte; // [sp+2Ch] [bp-4h]@0
	int psa; // [sp+38h] [bp+8h]@1
	int psb; // [sp+38h] [bp+8h]@19
	int psc; // [sp+38h] [bp+8h]@29

	pd = (int)bits;
	nlines = *(_WORD *)ps;
	psa = (int)(ps + 2);
	for (y = 0; y < nlines; ++y)
	{
		while (1)
		{
			while (1)
			{
				word = *(_WORD *)psa;
				psa += 2;
				if ((word & 0xC000) != 49152)
					break;
				for (i = 0; i < -word; ++i)
				{
					for (j = 0; j < w; ++j)
						*(_BYTE *)pd++ = 0;
				}
			}
			if ((word & 0xC000) == 32768)
			{
				lastByte = (unsigned __int8)word;
				numPackets = *(_WORD *)psa;
				psa += 2;
				goto LABEL_17;
			}
			if ((word & 0xC000) != 16384)
				break;
			DbgReportError(1, "CelExpandWordDelta: 0x4000 case illegal\n");
		}
		numPackets = word;
	LABEL_17:
		xpos = 0;
		for (ipacket = 0; ipacket < numPackets; ++ipacket)
		{
			nskip = *(_BYTE *)psa;
			psb = psa + 1;
			for (ia = 0; ia < nskip; ++ia)
				*(_BYTE *)pd++ = 0;
			xposa = nskip + xpos;
			nwords = *(_BYTE *)psb;
			psa = psb + 1;
			if (nwords >= 0)
			{
				for (ic = 0; ic < nwords; ++ic)
				{
					*(_BYTE *)pd = *(_BYTE *)psa;
					v4 = pd + 1;
					psc = psa + 1;
					*(_BYTE *)v4 = *(_BYTE *)psc;
					pd = v4 + 1;
					psa = psc + 1;
				}
			}
			else
			{
				nwords = -nwords;
				for (ib = 0; ib < nwords; ++ib)
				{
					*(_BYTE *)pd = *(_BYTE *)psa;
					v3 = pd + 1;
					*(_BYTE *)v3 = *(_BYTE *)(psa + 1);
					pd = v3 + 1;
				}
				psa += 2;
			}
			xpos = 2 * nwords + xposa;
		}
		if (xpos > w)
		{
			DbgReportWarning("CelExpandWordDelta: decompress error\n");
			return;
		}
		if (xpos < w)
		{
			for (id = xpos; id < w; ++id)
				*(_BYTE *)pd++ = 0;
		}
		if (lastByte >= 0)
			*(_BYTE *)(pd - 1) = lastByte;
	}
}

//----- (008F1B9F) --------------------------------------------------------
void __cdecl CelGetPall(char *pPall, char *buff, int shifter)
{
	__int16 numPackets; // [sp+0h] [bp-18h]@1
	__int16 index; // [sp+4h] [bp-14h]@1
	char *pd; // [sp+8h] [bp-10h]@1
	__int16 i; // [sp+Ch] [bp-Ch]@8
	signed __int16 count; // [sp+10h] [bp-8h]@3
	__int16 ipacket; // [sp+14h] [bp-4h]@1
	int buffa; // [sp+24h] [bp+Ch]@1
	int buffb; // [sp+24h] [bp+Ch]@3

	pd = pPall;
	index = 0;
	numPackets = *(_WORD *)buff;
	buffa = (int)(buff + 2);
	for (ipacket = 0; ipacket < numPackets; ++ipacket)
	{
		index += *(_BYTE *)buffa;
		buffb = buffa + 1;
		count = *(_BYTE *)buffb;
		buffa = buffb + 1;
		if (!count)
			count = 256;
		if (index || count != 256)
			DbgReportWarning("CelGetPall: can't handle partial pallettes\n");
		for (i = 0; i < 3 * count; ++i)
			*pd++ = *(_BYTE *)buffa++ << shifter;
	}
}

//----- (008F1C97) --------------------------------------------------------
char __cdecl CelReadFrame(IStoreStream *pStream, char *bits, __int16 w, __int16 h, char bGetPall)
{
	char result; // al@4
	unsigned int v6; // eax@12
	unsigned int v7; // eax@15
	char frameDone; // [sp+4h] [bp-2Ch]@13
	chunk_id chunk; // [sp+8h] [bp-28h]@15
	unsigned int nextOffset; // [sp+10h] [bp-20h]@15
	fli_frame frameInfo; // [sp+14h] [bp-1Ch]@2
	int ichunk; // [sp+24h] [bp-Ch]@13
	void *buff; // [sp+28h] [bp-8h]@1
	unsigned int fullLen; // [sp+2Ch] [bp-4h]@6

	buff = 0;
	while (1)
	{
		((void(__stdcall *)(IStoreStream *, signed int, fli_frame *))pStream->baseclass_0.vfptr[3].Release)(
			pStream,
			16,
			&frameInfo);
		if (frameInfo.type != 61946)
		{
			DbgReportWarning("CelReadFrame: missing frame chunk\n");
			if (buff)
			{
				FreeSpew(buff, "x:\\prj\\tech\\libsrc\\namedres\\cel.cpp", 342);
				return 0;
			}
		}
		if (!buff)
		{
			fullLen = h * w;
			buff = h * w >= frameInfo.size ? MallocSpew(frameInfo.size, "x:\\prj\\tech\\libsrc\\namedres\\cel.cpp", 354) : MallocSpew(fullLen, "x:\\prj\\tech\\libsrc\\namedres\\cel.cpp", 352);
			if (!buff)
				return 0;
		}
		if (frameInfo.chunks)
			break;
		v6 = pStream->baseclass_0.vfptr[2].Release((IUnknown *)pStream);
		((void(__stdcall *)(IStoreStream *, unsigned int))pStream->baseclass_0.vfptr[2].AddRef)(
			pStream,
			v6 + frameInfo.size - 16);
	}
	frameDone = 0;
	for (ichunk = 0; ichunk < frameInfo.chunks; ++ichunk)
	{
		((void(__stdcall *)(IStoreStream *, signed int, chunk_id *))pStream->baseclass_0.vfptr[3].Release)(
			pStream,
			6,
			&chunk);
		v7 = pStream->baseclass_0.vfptr[2].Release((IUnknown *)pStream);
		nextOffset = v7 + chunk.size - 6;
		switch (chunk.type)
		{
		case 4u:
			((void(__stdcall *)(IStoreStream *, int, void *))pStream->baseclass_0.vfptr[3].Release)(
				pStream,
				chunk.size - 6,
				buff);
			if (!bGetPall)
				break;
			CelGetPall(bits, (char *)buff, 0);
			return 1;
		case 7u:
			((void(__stdcall *)(IStoreStream *, int, void *))pStream->baseclass_0.vfptr[3].Release)(
				pStream,
				chunk.size - 6,
				buff);
			CelExpandWordDelta((char *)buff, bits, w);
			frameDone = 1;
			break;
		case 0xBu:
			((void(__stdcall *)(_DWORD, _DWORD, _DWORD))pStream->baseclass_0.vfptr[3].Release)(
				pStream,
				chunk.size - 6,
				buff);
			if (!bGetPall)
				break;
			CelGetPall(bits, (char *)buff, 2);
			return 1;
		case 0xCu:
			((void(__stdcall *)(_DWORD, _DWORD, _DWORD))pStream->baseclass_0.vfptr[3].Release)(
				pStream,
				chunk.size - 6,
				buff);
			CelExpandByteDelta((char *)buff, bits, w);
			frameDone = 1;
			break;
		case 0xDu:
			memset(bits, 0, fullLen);
			frameDone = 1;
			break;
		case 0xFu:
			((void(__stdcall *)(_DWORD, _DWORD, _DWORD))pStream->baseclass_0.vfptr[3].Release)(
				pStream,
				chunk.size - 6,
				buff);
			CelExpandBrun((char *)buff, bits, w, h);
			frameDone = 1;
			break;
		case 0x10u:
			((void(__stdcall *)(IStoreStream *, unsigned int, char *))pStream->baseclass_0.vfptr[3].Release)(
				pStream,
				fullLen,
				bits);
			frameDone = 1;
			break;
		default:
			break;
		}
		((void(__stdcall *)(IStoreStream *, unsigned int))pStream->baseclass_0.vfptr[2].AddRef)(pStream, nextOffset);
	}
	FreeSpew(buff, "x:\\prj\\tech\\libsrc\\namedres\\cel.cpp", 441);
	buff = 0;
	if (!frameDone || bGetPall)
	{
		DbgReportWarning("CelReadFrame: no frame data!\n");
		result = 0;
	}
	else
	{
		result = 1;
	}
	return result;
}

//----- (008F1FDB) --------------------------------------------------------
grs_bitmap *__cdecl ResCelReadImage(IStoreStream *pStream, IResMemOverride *pResMem)
{
	grs_bitmap *result; // eax@3
	char *pImg; // [sp+0h] [bp-88h]@4
	fli_head celHead; // [sp+4h] [bp-84h]@1
	char *pbm; // [sp+84h] [bp-4h]@4

	((void(__stdcall *)(IStoreStream *, signed int, fli_head *))pStream->baseclass_0.vfptr[3].Release)(
		pStream,
		128,
		&celHead);
	if (celHead.type == 44818 || celHead.type == 44817)
	{
		pbm = (char *)((int(__stdcall *)(IResMemOverride *, int))pResMem->baseclass_0.vfptr[1].QueryInterface)(
			pResMem,
			celHead.height * celHead.width + 16);
		pImg = pbm + 16;
		((void(__stdcall *)(IStoreStream *, int))pStream->baseclass_0.vfptr[2].AddRef)(pStream, celHead.frame1_oset);
		if (CelReadFrame(pStream, pImg, celHead.width, celHead.height, 0))
		{
			gr_init_bitmap((grs_bitmap *)pbm, pImg, 2u, 0, celHead.width, celHead.height);
			result = (grs_bitmap *)pbm;
		}
		else
		{
			((void(__stdcall *)(IResMemOverride *, char *))pResMem->baseclass_0.vfptr[1].AddRef)(pResMem, pbm);
			result = 0;
		}
	}
	else
	{
		DbgReportWarning("CelRead: invalid CEL/FLC/FLI magic type: %d\n");
		result = 0;
	}
	return result;
}

//----- (008F20ED) --------------------------------------------------------
void *__cdecl ResCelReadPalette(IStoreStream *pStream, IResMemOverride *pResMem)
{
	void *result; // eax@3
	fli_head celHead; // [sp+0h] [bp-84h]@1
	void *pPall; // [sp+80h] [bp-4h]@4

	((void(__stdcall *)(IStoreStream *, signed int, fli_head *))pStream->baseclass_0.vfptr[3].Release)(
		pStream,
		128,
		&celHead);
	if (celHead.type == 44818 || celHead.type == 44817)
	{
		pPall = (void *)((int(__stdcall *)(IResMemOverride *, signed int))pResMem->baseclass_0.vfptr[1].QueryInterface)(
			pResMem,
			768);
		((void(__stdcall *)(IStoreStream *, int))pStream->baseclass_0.vfptr[2].AddRef)(pStream, celHead.frame1_oset);
		if (CelReadFrame(pStream, (char *)pPall, celHead.width, celHead.height, 1))
		{
			result = pPall;
		}
		else
		{
			((void(__stdcall *)(IResMemOverride *, void *))pResMem->baseclass_0.vfptr[1].AddRef)(pResMem, pPall);
			result = 0;
		}
	}
	else
	{
		DbgReportWarning("CelRead: invalid CEL/FLC/FLI magic type: %d\n");
		result = 0;
	}
	return result;
}