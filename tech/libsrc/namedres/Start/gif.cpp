//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>



//----- (008F0860) --------------------------------------------------------
char __cdecl ResUnpackImage(IStoreStream *pStream, int bits, char *buffer, ImageBlock *pImageBlock)
{
	char result; // al@3
	int v5; // eax@9
	int v6; // eax@16
	int v7; // eax@22
	__int16 codesize2; // [sp+0h] [bp-150h]@4
	__int16 thiscode; // [sp+4h] [bp-14Ch]@12
	__int16 thiscodea; // [sp+4h] [bp-14Ch]@25
	__int16 blocksize; // [sp+8h] [bp-148h]@8
	__int16 blocksizea; // [sp+8h] [bp-148h]@15
	__int16 blocksizeb; // [sp+8h] [bp-148h]@21
	signed __int16 oldcode; // [sp+Ch] [bp-144h]@4
	void *linebuffer; // [sp+10h] [bp-140h]@4
	void *codestack; // [sp+14h] [bp-13Ch]@1
	__int16 nextcode; // [sp+18h] [bp-138h]@4
	__int16 pass; // [sp+1Ch] [bp-134h]@1
	__int16 currentcode; // [sp+20h] [bp-130h]@12
	__int16 currentcodea; // [sp+20h] [bp-130h]@25
	void *firstcodestack; // [sp+24h] [bp-12Ch]@1
	signed __int16 bitsleft; // [sp+28h] [bp-128h]@1
	int u; // [sp+2Ch] [bp-124h]@30
	__int16 codesize; // [sp+30h] [bp-120h]@4
	char b[255]; // [sp+34h] [bp-11Ch]@1
	__int16 bits2; // [sp+134h] [bp-1Ch]@4
	__int16 oldtoken; // [sp+138h] [bp-18h]@4
	__int16 line; // [sp+13Ch] [bp-14h]@1
	char *q; // [sp+140h] [bp-10h]@1
	int lastcodestack; // [sp+144h] [bp-Ch]@1
	__int16 byte; // [sp+148h] [bp-8h]@1
	char *p; // [sp+14Ch] [bp-4h]@1

	line = 0;
	byte = 0;
	pass = 0;
	firstcodestack = (void *)f_malloc_db(4096, "x:\\prj\\tech\\libsrc\\namedres\\gif.cpp", 92);
	lastcodestack = f_malloc_db(4096, "x:\\prj\\tech\\libsrc\\namedres\\gif.cpp", 93);
	codestack = (void *)f_malloc_db(8192, "x:\\prj\\tech\\libsrc\\namedres\\gif.cpp", 94);
	q = b;
	p = b;
	bitsleft = 8;
	if (bits >= 2 && bits <= 8)
	{
		bits2 = 1 << bits;
		nextcode = (1 << bits) + 2;
		codesize = bits + 1;
		codesize2 = 1 << (bits + 1);
		oldtoken = -1;
		oldcode = -1;
		linebuffer = (void *)f_malloc_db(pImageBlock->width, "x:\\prj\\tech\\libsrc\\namedres\\gif.cpp", 105);
		if (linebuffer)
		{
			while (1)
			{
				if (bitsleft == 8)
				{
					++p;
					if (p >= q)
					{
						blocksize = ((int(__stdcall *)(IStoreStream *))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
						if (blocksize < 1
							|| (p = b,
							v5 = ((int(__stdcall *)(IStoreStream *, _DWORD, _DWORD))pStream->baseclass_0.vfptr[3].Release)(
							pStream,
							blocksize,
							b),
							q = &p[v5],
							&p[v5] < &b[blocksize]))
						{
							j__free(linebuffer);
							return 0;
						}
					}
					bitsleft = 0;
				}
				thiscode = (unsigned __int8)*p;
				currentcode = bitsleft + codesize;
				if ((signed __int16)(bitsleft + codesize) > 8)
				{
					++p;
					if (p >= q)
					{
						blocksizea = ((int(__stdcall *)(IStoreStream *))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
						if (blocksizea < 1
							|| (p = b,
							v6 = ((int(__stdcall *)(IStoreStream *, _DWORD, _DWORD))pStream->baseclass_0.vfptr[3].Release)(
							pStream,
							blocksizea,
							b),
							q = &p[v6],
							&p[v6] < &b[blocksizea]))
						{
							j__free(linebuffer);
							return 0;
						}
					}
					thiscode |= (unsigned __int8)*p << (8 - bitsleft);
					if (currentcode > 16)
					{
						++p;
						if (p >= q)
						{
							blocksizeb = ((int(__stdcall *)(_DWORD))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
							if (blocksizeb < 1
								|| (p = b,
								v7 = ((int(__stdcall *)(_DWORD, _DWORD, _DWORD))pStream->baseclass_0.vfptr[3].Release)(
								pStream,
								blocksizeb,
								b),
								q = &p[v7],
								&p[v7] < &b[blocksizeb]))
							{
								j__free(linebuffer);
								return 0;
							}
						}
						thiscode |= (unsigned __int8)*p << (16 - bitsleft);
						bitsleft = currentcode - 16;
						*p = (unsigned __int8)*p >> (currentcode - 16);
					}
					else
					{
						bitsleft = currentcode - 8;
						*p = (unsigned __int8)*p >> (currentcode - 8);
					}
				}
				else
				{
					*p = (unsigned __int8)*p >> codesize;
					bitsleft += codesize;
				}
				thiscodea = wordmasktable[codesize] & thiscode;
				currentcodea = thiscodea;
				if (thiscodea == bits2 + 1)
					break;
				if (thiscodea > nextcode)
				{
					j__free(linebuffer);
					return 0;
				}
				if (thiscodea == bits2)
				{
					nextcode = bits2 + 2;
					codesize = bits + 1;
					codesize2 = 1 << (bits + 1);
					oldcode = -1;
					oldtoken = -1;
				}
				else
				{
					u = (int)firstcodestack;
					if (thiscodea == nextcode)
					{
						if (oldcode == -1)
						{
							j__free(linebuffer);
							return 0;
						}
						*(_BYTE *)firstcodestack = oldtoken;
						u = (int)((char *)firstcodestack + 1);
						thiscodea = oldcode;
					}
					while (thiscodea >= bits2)
					{
						*(_BYTE *)u++ = *(_BYTE *)(lastcodestack + thiscodea);
						thiscodea = *((_WORD *)codestack + thiscodea);
					}
					oldtoken = thiscodea;
					while (1)
					{
						*((_BYTE *)linebuffer + byte++) = thiscodea;
						if (byte >= (signed int)pImageBlock->width)
						{
							if (line < (signed int)pImageBlock->depth)
								memcpy(&buffer[pImageBlock->width * line], linebuffer, pImageBlock->width);
							byte = 0;
							if (pImageBlock->flags & 0x40)
							{
								line += LOWORD(inctable[pass]);
								if (line >= (signed int)pImageBlock->depth)
								{
									++pass;
									line = LOWORD(startable[pass]);
								}
							}
							else
							{
								++line;
							}
						}
						if (u <= (unsigned int)firstcodestack)
							break;
						--u;
						LOBYTE(thiscodea) = *(_BYTE *)u;
					}
					if (nextcode < 4096)
					{
						if (oldcode != -1)
						{
							*((_WORD *)codestack + nextcode) = oldcode;
							*(_BYTE *)(lastcodestack + nextcode++) = oldtoken;
							if (nextcode >= codesize2)
							{
								if (codesize < 12)
								{
									++codesize;
									codesize2 = 1 << codesize;
								}
							}
						}
					}
					oldcode = currentcodea;
				}
			}
			j__free(linebuffer);
			j__free(firstcodestack);
			j__free((void *)lastcodestack);
			j__free(codestack);
			result = 1;
		}
		else
		{
			result = 0;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}
// B19510: using guessed type int (__cdecl *f_malloc_db)(_DWORD, _DWORD, _DWORD);

//----- (008F0FBF) --------------------------------------------------------
void __cdecl ResPutExtension(IStoreStream *pStream)
{
	int v1; // ST0C_4@6
	unsigned int v2; // eax@6
	unsigned int v3; // eax@7
	unsigned int v4; // eax@8
	int n; // [sp+4h] [bp-Ch]@8
	signed int header_size; // [sp+8h] [bp-8h]@2
	signed int tail; // [sp+Ch] [bp-4h]@2

	switch ((signed __int16)((int(__stdcall *)(IStoreStream *))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream))
	{
	case 1:
		header_size = 13;
		tail = 1;
		break;
	case 249:
		header_size = 6;
		tail = 0;
		break;
	case 254:
		header_size = 0;
		tail = 1;
		break;
	case 255:
		header_size = 12;
		tail = 1;
		break;
	default:
		header_size = 0;
		tail = 0;
		v1 = (signed __int16)((int(__stdcall *)(IStoreStream *))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
		v2 = pStream->baseclass_0.vfptr[2].Release((IUnknown *)pStream);
		((void(__stdcall *)(IStoreStream *, unsigned int))pStream->baseclass_0.vfptr[2].AddRef)(pStream, v1 + v2);
		break;
	}
	v3 = pStream->baseclass_0.vfptr[2].Release((IUnknown *)pStream);
	((void(__stdcall *)(IStoreStream *, unsigned int))pStream->baseclass_0.vfptr[2].AddRef)(pStream, header_size + v3);
	if (tail == 1)
	{
		do
		{
			n = (signed __int16)((int(__stdcall *)(_DWORD))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
			v4 = pStream->baseclass_0.vfptr[2].Release((IUnknown *)pStream);
			((void(__stdcall *)(_DWORD, unsigned int))pStream->baseclass_0.vfptr[2].AddRef)(pStream, n + v4);
		} while (n > 0 && n != -1);
	}
}



//----- (008F11EA) --------------------------------------------------------
grs_bitmap *__cdecl ResGifReadImage(IStoreStream *pStream, IResMemOverride *pResMem)
{
	grs_bitmap *result; // eax@2
	signed int v3; // ST20_4@4
	unsigned int v4; // eax@4
	unsigned int v5; // eax@12
	int pbm; // [sp+4h] [bp-28h]@17
	int c; // [sp+Ch] [bp-20h]@5
	int ca; // [sp+Ch] [bp-20h]@13
	GifHeader gifHeader; // [sp+10h] [bp-1Ch]@1
	ImageBlock imageBlock; // [sp+20h] [bp-Ch]@11

	((void(__stdcall *)(IStoreStream *, signed int, GifHeader *))pStream->baseclass_0.vfptr[3].Release)(
		pStream,
		13,
		&gifHeader);
	if (memcmp(&gifHeader, "GIF", 3u))
	{
		result = 0;
	}
	else
	{
		if (gifHeader.flags & 0x80)
		{
			v3 = 1 << ((gifHeader.flags & 7) + 1);
			v4 = pStream->baseclass_0.vfptr[2].Release((IUnknown *)pStream);
			((void(__stdcall *)(IStoreStream *, unsigned int))pStream->baseclass_0.vfptr[2].AddRef)(pStream, 3 * v3 + v4);
		}
		for (c = (signed __int16)((int(__stdcall *)(IStoreStream *))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
			;
			c = (signed __int16)((int(__stdcall *)(IStoreStream *))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream))
		{
			if (c == -1 || c != 44 && c != 33 && c)
				return 0;
			if (c == 44)
				break;
			if (c == 33)
				ResPutExtension(pStream);
		}
		((void(__stdcall *)(IStoreStream *, signed int, ImageBlock *))pStream->baseclass_0.vfptr[3].Release)(
			pStream,
			9,
			&imageBlock);
		if (imageBlock.flags & 0x80)
		{
			v5 = pStream->baseclass_0.vfptr[2].Release((IUnknown *)pStream);
			((void(__stdcall *)(IStoreStream *, unsigned int))pStream->baseclass_0.vfptr[2].AddRef)(pStream, v5 + 768);
		}
		ca = (signed __int16)((int(__stdcall *)(_DWORD))pStream->baseclass_0.vfptr[4].QueryInterface)(pStream);
		if (ca == -1)
		{
			result = 0;
		}
		else
		{
			if (g_pMalloc)
				(*(void(__stdcall **)(int, _DWORD, signed int))(*(_DWORD *)g_pMalloc + 72))(
				g_pMalloc,
				"x:\\prj\\tech\\libsrc\\namedres\\gif.cpp",
				331);
			pbm = ((int(__stdcall *)(IResMemOverride *, int))pResMem->baseclass_0.vfptr[1].QueryInterface)(
				pResMem,
				imageBlock.depth * imageBlock.width + 16);
			if (g_pMalloc)
				(*(void(__stdcall **)(int))(*(_DWORD *)g_pMalloc + 76))(g_pMalloc);
			if (ResUnpackImage(pStream, ca, (char *)(pbm + 16), &imageBlock))
			{
				gr_init_bitmap((grs_bitmap *)pbm, (char *)(pbm + 16), 2u, 0, imageBlock.width, imageBlock.depth);
				result = (grs_bitmap *)pbm;
			}
			else
			{
				((void(__stdcall *)(IResMemOverride *, int))pResMem->baseclass_0.vfptr[1].AddRef)(pResMem, pbm);
				result = 0;
			}
		}
	}
	return result;
}
// E81640: using guessed type int g_pMalloc;

//----- (008F1417) --------------------------------------------------------
void *__cdecl ResGifReadPalette(IStoreStream *pStream, IResMemOverride *pResMem)
{
	void *result; // eax@2
	signed int sizePall; // [sp+0h] [bp-18h]@4
	void *pPall; // [sp+4h] [bp-14h]@6
	GifHeader gifHeader; // [sp+8h] [bp-10h]@1

	((void(__stdcall *)(IStoreStream *, signed int, GifHeader *))pStream->baseclass_0.vfptr[3].Release)(
		pStream,
		13,
		&gifHeader);
	if (memcmp(&gifHeader, "GIF", 3u))
	{
		result = 0;
	}
	else
	{
		if (gifHeader.flags & 0x80)
		{
			sizePall = 1 << ((gifHeader.flags & 7) + 1);
			if (g_pMalloc)
				(*(void(__stdcall **)(int, _DWORD, signed int))(*(_DWORD *)g_pMalloc + 72))(
				g_pMalloc,
				"x:\\prj\\tech\\libsrc\\namedres\\gif.cpp",
				379);
			pPall = (void *)((int(__stdcall *)(IResMemOverride *, signed int))pResMem->baseclass_0.vfptr[1].QueryInterface)(
				pResMem,
				768);
			if (g_pMalloc)
				(*(void(__stdcall **)(int))(*(_DWORD *)g_pMalloc + 76))(g_pMalloc);
			memset(pPall, 0, 0x300u);
			((void(__stdcall *)(IStoreStream *, int, void *))pStream->baseclass_0.vfptr[3].Release)(
				pStream,
				3 * sizePall,
				pPall);
			result = pPall;
		}
		else
		{
			result = 0;
		}
	}
	return result;
}
// E81640: using guessed type int g_pMalloc;