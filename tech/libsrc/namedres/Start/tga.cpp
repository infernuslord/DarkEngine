//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>

//----- (008EF910) --------------------------------------------------------
grs_bitmap *__cdecl ResTgaReadImage(IStoreStream *pStream, IResMemOverride *pResMem)
{
	unsigned int v2; // eax@12
	grs_bitmap *result; // eax@9
	int v4; // [sp+0h] [bp-88h]@33
	const void *v5; // [sp+10h] [bp-78h]@55
	char Dst; // [sp+14h] [bp-74h]@57
	void *Src; // [sp+18h] [bp-70h]@54
	size_t Size; // [sp+1Ch] [bp-6Ch]@48
	unsigned int row; // [sp+20h] [bp-68h]@48
	__int16 v10; // [sp+24h] [bp-64h]@37
	char *pSrc; // [sp+28h] [bp-60h]@35
	char *pDst; // [sp+2Ch] [bp-5Ch]@35
	int i; // [sp+30h] [bp-58h]@35
	char *start_buff; // [sp+34h] [bp-54h]@32
	int bmrow; // [sp+38h] [bp-50h]@25
	int readrow; // [sp+3Ch] [bp-4Ch]@25
	int Bpp; // [sp+40h] [bp-48h]@25
	char *p; // [sp+44h] [bp-44h]@29
	void *read_buff; // [sp+48h] [bp-40h]@29
	char *other; // [sp+4Ch] [bp-3Ch]@19
	char tmp; // [sp+50h] [bp-38h]@21
	char *buff; // [sp+54h] [bp-34h]@18
	int j; // [sp+58h] [bp-30h]@16
	int jend; // [sp+5Ch] [bp-2Ch]@5
	sTgaHeader tga; // [sp+60h] [bp-28h]@1
	int idel; // [sp+74h] [bp-14h]@2
	char *pBits; // [sp+78h] [bp-10h]@16
	int pbm; // [sp+7Ch] [bp-Ch]@14
	int jstart; // [sp+80h] [bp-8h]@5
	int jdel; // [sp+84h] [bp-4h]@5

	((void(__stdcall *)(IStoreStream *, signed int, sTgaHeader *))pStream->baseclass_0.vfptr[3].Release)(
		pStream,
		18,
		&tga);
	if (tga.image_descriptor_bits & 0x10)
		idel = -1;
	else
		idel = 1;
	if (tga.image_descriptor_bits & 0x20)
	{
		jstart = 0;
		jend = tga.height;
		jdel = 1;
	}
	else
	{
		jstart = tga.height - 1;
		jend = -1;
		jdel = -1;
	}
	if (tga.image_type == 1)
	{
		if (tga.bits_per_pixel == 8)
		{
			v2 = pStream->baseclass_0.vfptr[2].Release((IUnknown *)pStream);
			((void(__stdcall *)(IStoreStream *, unsigned int))pStream->baseclass_0.vfptr[2].AddRef)(
				pStream,
				3 * tga.color_map_length + v2);
			if (g_pMalloc)
				(*(void(__stdcall **)(int, _DWORD, signed int))(*(_DWORD *)g_pMalloc + 72))(
				g_pMalloc,
				"x:\\prj\\tech\\libsrc\\namedres\\tga.cpp",
				93);
			pbm = ((int(__stdcall *)(IResMemOverride *, int))pResMem->baseclass_0.vfptr[1].QueryInterface)(
				pResMem,
				tga.height * tga.width + 16);
			if (g_pMalloc)
				(*(void(__stdcall **)(int))(*(_DWORD *)g_pMalloc + 76))(g_pMalloc);
			pBits = (char *)(pbm + 16);
			for (j = jstart; j != jend; j += jdel)
			{
				buff = &pBits[tga.width * j];
				((void(__stdcall *)(IStoreStream *, _DWORD, char *))pStream->baseclass_0.vfptr[3].Release)(
					pStream,
					tga.width,
					&pBits[tga.width * j]);
				if (idel == -1)
				{
					other = &buff[tga.width - 1];
					while (other > buff)
					{
						tmp = *buff;
						*buff = *other;
						*other-- = tmp;
						++buff;
					}
				}
			}
			gr_init_bitmap((grs_bitmap *)pbm, pBits, 2u, 0, tga.width, tga.height);
			result = (grs_bitmap *)pbm;
		}
		else
		{
			result = 0;
		}
	}
	else
	{
		if (tga.image_type != 2)
			return 0;
		if (tga.bits_per_pixel == 32)
		{
			Bpp = (signed int)(unsigned __int8)tga.bits_per_pixel >> 3;
			readrow = Bpp * tga.width;
			bmrow = (gResImageConvert8888to4444 != 0 ? 2 : 4) * tga.width;
			if (g_pMalloc)
				(*(void(__stdcall **)(int, _DWORD, signed int))(*(_DWORD *)g_pMalloc + 72))(
				g_pMalloc,
				"x:\\prj\\tech\\libsrc\\namedres\\tga.cpp",
				134);
			pbm = ((int(__stdcall *)(IResMemOverride *, int))pResMem->baseclass_0.vfptr[1].QueryInterface)(
				pResMem,
				tga.height * bmrow + 16);
			if (g_pMalloc)
				(*(void(__stdcall **)(int))(*(_DWORD *)g_pMalloc + 76))(g_pMalloc);
			p = (char *)(pbm + 16);
			read_buff = j__new(4 * tga.width, "x:\\prj\\tech\\libsrc\\namedres\\tga.cpp", 139);
			for (j = jstart; j != jend; j += jdel)
			{
				if (gResImageConvert8888to4444)
				{
					start_buff = (char *)read_buff;
					if (idel == -1)
						v4 = tga.width - 1;
					else
						v4 = 0;
					start_buff += 4 * v4;
					((void(__stdcall *)(IStoreStream *, int, void *))pStream->baseclass_0.vfptr[3].Release)(
						pStream,
						readrow,
						read_buff);
					pSrc = start_buff;
					pDst = &p[2 * tga.width * j];
					for (i = 0; i < tga.width; ++i)
					{
						v10 = (*(_DWORD *)pSrc >> 16) & 0xF000 | (*(_DWORD *)pSrc >> 12) & 0xF00 | (*(_DWORD *)pSrc >> 8) & 0xF0 | (*(_DWORD *)pSrc >> 4) & 0xF;
						*(_WORD *)pDst = v10;
						pDst += 2;
						pSrc += 4 * idel;
					}
				}
				else
				{
					((void(__stdcall *)(IStoreStream *, int, char *))pStream->baseclass_0.vfptr[3].Release)(
						pStream,
						bmrow,
						&p[4 * tga.width * j]);
				}
			}
			operator delete(read_buff);
			if (gResImageConvert8888to4444)
				gr_init_bitmap((grs_bitmap *)pbm, p, 3u, 0x700u, tga.width, tga.height);
			else
				gr_init_bitmap((grs_bitmap *)pbm, p, 0xAu, 0x600u, tga.width, tga.height);
		}
		else
		{
			if (tga.bits_per_pixel != 24 && tga.bits_per_pixel != 16)
				return 0;
			Size = (signed int)(unsigned __int8)tga.bits_per_pixel >> 3;
			row = Size * tga.width;
			if (g_pMalloc)
				(*(void(__stdcall **)(_DWORD, _DWORD, signed int))(*(_DWORD *)g_pMalloc + 72))(
				g_pMalloc,
				"x:\\prj\\tech\\libsrc\\namedres\\tga.cpp",
				180);
			pbm = ((int(__stdcall *)(IResMemOverride *, unsigned int))pResMem->baseclass_0.vfptr[1].QueryInterface)(
				pResMem,
				tga.height * row + 16);
			if (g_pMalloc)
				(*(void(__stdcall **)(_DWORD))(*(_DWORD *)g_pMalloc + 76))(g_pMalloc);
			pBits = (char *)(pbm + 16);
			for (j = jstart; j != jend; j += jdel)
			{
				Src = &pBits[j * row];
				((void(__stdcall *)(IStoreStream *, unsigned int, char *))pStream->baseclass_0.vfptr[3].Release)(
					pStream,
					row,
					&pBits[j * row]);
				if (idel == -1)
				{
					v5 = (char *)Src + (tga.width - 1) * Size;
					while (v5 > Src)
					{
						memcpy(&Dst, Src, Size);
						memcpy(Src, v5, Size);
						memcpy((void *)v5, &Dst, Size);
						v5 = (char *)v5 - Size;
						Src = (char *)Src + Size;
					}
				}
			}
			gr_init_bitmap((grs_bitmap *)pbm, pBits, Size != 2 ? 5 : 3, Size != 2 ? 1280 : 768, tga.width, tga.height);
		}
		result = (grs_bitmap *)pbm;
	}
	return result;
}
// B41684: using guessed type int gResImageConvert8888to4444;
// E81640: using guessed type int g_pMalloc;

//----- (008EFFD3) --------------------------------------------------------
void *__cdecl ResTgaReadPalette(IStoreStream *pStream, IResMemOverride *pResMem)
{
	void *result; // eax@2
	sTgaHeader tga; // [sp+0h] [bp-18h]@1
	void *pPall; // [sp+14h] [bp-4h]@7

	((void(__stdcall *)(IStoreStream *, signed int, sTgaHeader *))pStream->baseclass_0.vfptr[3].Release)(
		pStream,
		18,
		&tga);
	if (tga.image_type == 1)
	{
		if (tga.bits_per_pixel == 8)
		{
			if (g_pMalloc)
				(*(void(__stdcall **)(int, _DWORD, signed int))(*(_DWORD *)g_pMalloc + 72))(
				g_pMalloc,
				"x:\\prj\\tech\\libsrc\\namedres\\tga.cpp",
				236);
			pPall = (void *)((int(__stdcall *)(IResMemOverride *, signed int))pResMem->baseclass_0.vfptr[1].QueryInterface)(
				pResMem,
				768);
			if (g_pMalloc)
				(*(void(__stdcall **)(int))(*(_DWORD *)g_pMalloc + 76))(g_pMalloc);
			memset(pPall, 0, 0x300u);
			((void(__stdcall *)(IStoreStream *, int, char *))pStream->baseclass_0.vfptr[3].Release)(
				pStream,
				3 * tga.color_map_length,
				(char *)pPall + 3 * tga.first_color_map);
			result = pPall;
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