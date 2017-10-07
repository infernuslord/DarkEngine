//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>


//----- (008F00C0) --------------------------------------------------------
char __cdecl PcxReadHeader(IStoreStream *pStream, PCXHEAD *phead)
{
	char result; // al@2

	((void(__stdcall *)(_DWORD, _DWORD))pStream->baseclass_0.vfptr[2].AddRef)(pStream, 0);
	((void(__stdcall *)(_DWORD, _DWORD, _DWORD))pStream->baseclass_0.vfptr[3].Release)(pStream, 128, phead);
	if (phead->version == 5)
	{
		if (phead->encoding == 1)
		{
			if (phead->xmin || phead->ymin)
			{
				DbgReportWarning("Bad PCX header: picture not at 0,0\n");
				result = 0;
			}
			else
			{
				if (phead->bits_per_pixel == 8)
				{
					result = 1;
				}
				else
				{
					DbgReportWarning("PCX file must have 8 bits per pixel\n");
					result = 0;
				}
			}
		}
		else
		{
			DbgReportWarning("Bad PCX header: not compressed\n");
			result = 0;
		}
	}
	else
	{
		DbgReportWarning("Bad PCX header: not version 3.0\n");
		result = 0;
	}
	return result;
}

//----- (008F0168) --------------------------------------------------------
char __cdecl PcxReadRow(IStoreStream *pStream, char *p, __int16 npixels)
{
	const char *v3; // eax@10
	unsigned int pend; // [sp+0h] [bp-10h]@1
	unsigned __int8 count; // [sp+4h] [bp-Ch]@7
	char value; // [sp+8h] [bp-8h]@5
	char valuea; // [sp+8h] [bp-8h]@9

	pend = (unsigned int)&p[npixels];
	while ((unsigned int)p < pend)
	{
		if (readBuffIndex >= 4096)
		{
			((void(__stdcall *)(_DWORD, _DWORD, _DWORD))pStream->baseclass_0.vfptr[3].Release)(pStream, 4096, readBuff);
			readBuffIndex = 0;
		}
		value = readBuff[readBuffIndex++];
		if ((value & 0xC0) == 192)
		{
			count = value & 0x3F;
			if (readBuffIndex >= 4096)
			{
				((void(__stdcall *)(_DWORD, _DWORD, _DWORD))pStream->baseclass_0.vfptr[3].Release)(pStream, 4096, readBuff);
				readBuffIndex = 0;
			}
			valuea = readBuff[readBuffIndex++];
			if ((unsigned int)&p[count] > pend)
			{
				v3 = _LogFmt("PCX decompression error, xpixel: %d\n");
				_CriticalMsg(v3, "x:\\prj\\tech\\libsrc\\namedres\\pcx.cpp", 0x85u);
			}
			memset(p, (unsigned __int8)valuea, count);
			p += count;
		}
		else
		{
			*p++ = value;
		}
	}
	return 1;
}

//----- (008F02E8) --------------------------------------------------------
char __cdecl PcxReadBody(IStoreStream *pStream, char *bits, char type, __int16 w, __int16 h, unsigned __int16 row, unsigned __int16 bpl)
{
	char result; // al@3
	int v8; // ST14_4@17
	signed int plane; // [sp+0h] [bp-18h]@10
	void *buff24; // [sp+4h] [bp-14h]@0
	int pd; // [sp+8h] [bp-10h]@15
	signed int y; // [sp+Ch] [bp-Ch]@4
	signed int i; // [sp+10h] [bp-8h]@15
	char *p; // [sp+14h] [bp-4h]@4

	((void(__stdcall *)(_DWORD, _DWORD))pStream->baseclass_0.vfptr[2].AddRef)(pStream, 128);
	if (type != 5 || (buff24 = (void *)f_malloc_db(3 * bpl, "x:\\prj\\tech\\libsrc\\namedres\\pcx.cpp", 163)) != 0)
	{
		p = bits;
		for (y = 0; y < h; ++y)
		{
			if (type == 2)
			{
				if (!PcxReadRow(pStream, p, bpl))
				{
					DbgReportWarning("PCX decompression error on line: %d\n");
					return 0;
				}
			}
			else
			{
				for (plane = 0; plane < 3; ++plane)
				{
					if (!PcxReadRow(pStream, (char *)buff24 + w * plane, bpl))
					{
						DbgReportWarning("PCX decompression error on line: %d\n");
						return 0;
					}
				}
				i = 0;
				pd = (int)p;
				while (i < w)
				{
					*(_BYTE *)pd = *((_BYTE *)buff24 + i);
					v8 = pd + 1;
					*(_BYTE *)v8++ = *((_BYTE *)buff24 + i + w);
					*(_BYTE *)v8 = *((_BYTE *)buff24 + 2 * w + i);
					pd = v8 + 1;
					++i;
				}
			}
			p += row;
		}
		if (type == 5)
			j__free(buff24);
		result = 1;
	}
	else
	{
		DbgReportWarning("PCX reader can't alloc memory\n");
		result = 0;
	}
	return result;
}
// B19510: using guessed type int (__cdecl *f_malloc_db)(_DWORD, _DWORD, _DWORD);

//----- (008F04BA) --------------------------------------------------------
grs_bitmap *__cdecl ResPcxReadImage(IStoreStream *pStream, IResMemOverride *pResMem)
{
	grs_bitmap *result; // eax@2
	char *pImg; // [sp+0h] [bp-9Ch]@14
	__int16 h; // [sp+4h] [bp-98h]@3
	unsigned __int16 w; // [sp+8h] [bp-94h]@3
	char type; // [sp+Ch] [bp-90h]@4
	PCXHEAD pcxHeader; // [sp+10h] [bp-8Ch]@1
	int extra; // [sp+90h] [bp-Ch]@4
	char *pbm; // [sp+94h] [bp-8h]@10
	unsigned __int16 row; // [sp+98h] [bp-4h]@4

	if (!PcxReadHeader(pStream, &pcxHeader))
		return 0;
	w = pcxHeader.xmax - pcxHeader.xmin + 1;
	h = pcxHeader.ymax - pcxHeader.ymin + 1;
	if (pcxHeader.colour_planes == 1)
	{
		type = 2;
		row = pcxHeader.xmax - pcxHeader.xmin + 1;
		extra = pcxHeader.bytes_per_line - w;
	}
	else
	{
		if (pcxHeader.colour_planes != 3)
		{
			DbgReportWarning("PCX file has %d planes!\n");
			return 0;
		}
		type = 5;
		row = 3 * w;
		extra = 3 * pcxHeader.bytes_per_line - (unsigned __int16)(3 * w);
	}
	if (g_pMalloc)
		(*(void(__stdcall **)(int, _DWORD, signed int))(*(_DWORD *)g_pMalloc + 72))(
		g_pMalloc,
		"x:\\prj\\tech\\libsrc\\namedres\\pcx.cpp",
		249);
	pbm = (char *)((int(__stdcall *)(IResMemOverride *, int))pResMem->baseclass_0.vfptr[1].QueryInterface)(
		pResMem,
		h * row + extra + 16);
	if (g_pMalloc)
		(*(void(__stdcall **)(int))(*(_DWORD *)g_pMalloc + 76))(g_pMalloc);
	if (pbm)
	{
		pImg = pbm + 16;
		readBuff = (char *)f_malloc_db(4096, "x:\\prj\\tech\\libsrc\\namedres\\pcx.cpp", 261);
		if (readBuff)
		{
			readBuffIndex = 4096;
			if (PcxReadBody(pStream, pImg, type, w, h, row, pcxHeader.bytes_per_line))
			{
				j__free(readBuff);
				gr_init_bitmap((grs_bitmap *)pbm, pImg, (unsigned __int8)type, 0, (signed __int16)w, h);
				result = (grs_bitmap *)pbm;
			}
			else
			{
				DbgReportWarning("Unable to read PCX file!\n");
				j__free(readBuff);
				((void(__stdcall *)(IResMemOverride *, char *))pResMem->baseclass_0.vfptr[1].AddRef)(pResMem, pbm);
				result = 0;
			}
		}
		else
		{
			DbgReportWarning("Can't allocate buffer in pcx reader\n");
			((void(__stdcall *)(IResMemOverride *, char *))pResMem->baseclass_0.vfptr[1].AddRef)(pResMem, pbm);
			result = 0;
		}
	}
	else
	{
		DbgReportWarning("Can't allocate bitmap bits in pcx reader\n");
		result = 0;
	}
	return result;
}
// B19510: using guessed type int (__cdecl *f_malloc_db)(_DWORD, _DWORD, _DWORD);
// E81640: using guessed type int g_pMalloc;

//----- (008F0738) --------------------------------------------------------
void *__cdecl ResPcxReadPalette(IStoreStream *pStream, IResMemOverride *pResMem)
{
	void *result; // eax@2
	unsigned int v3; // eax@10
	void *pPall; // [sp+0h] [bp-88h]@6
	PCXHEAD pcxHeader; // [sp+4h] [bp-84h]@1
	char pallPresent; // [sp+84h] [bp-4h]@10

	if (PcxReadHeader(pStream, &pcxHeader))
	{
		if (pcxHeader.colour_planes == 1)
		{
			if (g_pMalloc)
				(*(void(__stdcall **)(int, _DWORD, signed int))(*(_DWORD *)g_pMalloc + 72))(
				g_pMalloc,
				"x:\\prj\\tech\\libsrc\\namedres\\pcx.cpp",
				301);
			pPall = (void *)((int(__stdcall *)(IResMemOverride *, signed int))pResMem->baseclass_0.vfptr[1].QueryInterface)(
				pResMem,
				768);
			if (g_pMalloc)
				(*(void(__stdcall **)(int))(*(_DWORD *)g_pMalloc + 76))(g_pMalloc);
			if (pPall)
			{
				v3 = pStream->baseclass_0.vfptr[3].AddRef((IUnknown *)pStream);
				((void(__stdcall *)(IStoreStream *, unsigned int))pStream->baseclass_0.vfptr[2].AddRef)(pStream, v3 - 769);
				((void(__stdcall *)(IStoreStream *, signed int, char *))pStream->baseclass_0.vfptr[3].Release)(
					pStream,
					1,
					&pallPresent);
				if (pallPresent == 12)
				{
					((void(__stdcall *)(IStoreStream *, signed int, void *))pStream->baseclass_0.vfptr[3].Release)(
						pStream,
						768,
						pPall);
					result = pPall;
				}
				else
				{
					DbgReportWarning("Bad PCX trailer: pallette not found\n");
					result = 0;
				}
			}
			else
			{
				DbgReportWarning("Can't allocate palette in pcx reader\n");
				result = 0;
			}
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
// E81640: using guessed type int g_pMalloc;
