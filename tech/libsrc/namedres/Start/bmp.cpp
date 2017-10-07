//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>


//----- (008F21B0) --------------------------------------------------------
char __cdecl ResBmpReadHeader(IStoreStream *pStream, BmpHead *pBmpHead, BmpInfo *pBmpInfo)
{
	char result; // al@2

	((void(__stdcall *)(_DWORD, _DWORD, _DWORD))pStream->baseclass_0.vfptr[3].Release)(pStream, 14, pBmpHead);
	if (pBmpHead->bfType == 19778)
	{
		((void(__stdcall *)(_DWORD, _DWORD, _DWORD))pStream->baseclass_0.vfptr[3].Release)(pStream, 40, pBmpInfo);
		if (pBmpInfo->biSize == 40 && pBmpInfo->biPlanes == 1)
		{
			if (pBmpInfo->biBitCount == 4 || pBmpInfo->biBitCount == 8)
			{
				if (pBmpInfo->biCompression)
				{
					DbgReportWarning("BmpRead: can't do compressed bmp yet\n");
					result = 0;
				}
				else
				{
					result = 1;
				}
			}
			else
			{
				DbgReportWarning("BmpRead: can't read file with %d bits per pixel\n");
				result = 0;
			}
		}
		else
		{
			DbgReportWarning("BmpRead: bad bitmap info struct\n");
			result = 0;
		}
	}
	else
	{
		DbgReportWarning("BmpRead: not a Windows 3.x bitmap file\n");
		result = 0;
	}
	return result;
}

//----- (008F2277) --------------------------------------------------------
grs_bitmap *__cdecl ResBmpReadImage(IStoreStream *pStream, IResMemOverride *pResMem)
{
	grs_bitmap *result; // eax@2
	BmpHead bmpHead; // [sp+0h] [bp-454h]@1
	void *pImg; // [sp+10h] [bp-444h]@7
	unsigned int y; // [sp+14h] [bp-440h]@8
	unsigned int x; // [sp+18h] [bp-43Ch]@10
	void *pbits; // [sp+1Ch] [bp-438h]@8
	char buff[1024]; // [sp+20h] [bp-434h]@10
	BmpInfo bmpInfo; // [sp+420h] [bp-34h]@1
	int pbm; // [sp+448h] [bp-Ch]@5
	int widthBytes; // [sp+44Ch] [bp-8h]@8
	void *p; // [sp+450h] [bp-4h]@10

	if (ResBmpReadHeader(pStream, &bmpHead, &bmpInfo))
	{
		((void(__stdcall *)(IStoreStream *, unsigned int))pStream->baseclass_0.vfptr[2].AddRef)(pStream, bmpHead.bmOffBits);
		if (g_pMalloc)
			(*(void(__stdcall **)(int, _DWORD, signed int))(*(_DWORD *)g_pMalloc + 72))(
			g_pMalloc,
			"x:\\prj\\tech\\libsrc\\namedres\\bmp.cpp",
			110);
		pbm = ((int(__stdcall *)(IResMemOverride *, unsigned int))pResMem->baseclass_0.vfptr[1].QueryInterface)(
			pResMem,
			bmpInfo.biHeight * bmpInfo.biWidth + 16);
		if (g_pMalloc)
			(*(void(__stdcall **)(int))(*(_DWORD *)g_pMalloc + 76))(g_pMalloc);
		pImg = (void *)(pbm + 16);
		if (bmpInfo.biBitCount == 4)
		{
			widthBytes = ((unsigned __int16)((bmpInfo.biWidth + 1) >> 1) + 3) & 0xFFFC;
			y = 0;
			pbits = pImg;
			while (y < bmpInfo.biHeight)
			{
				((void(__stdcall *)(IStoreStream *, int, _DWORD))pStream->baseclass_0.vfptr[3].Release)(
					pStream,
					widthBytes,
					buff);
				x = 0;
				p = pbits;
				while (x < bmpInfo.biWidth)
				{
					if (x & 1)
					{
						*(_BYTE *)p = buff[(signed int)x >> 1] & 0xF;
						p = (char *)p + 1;
					}
					else
					{
						*(_BYTE *)p = (signed int)(unsigned __int8)buff[(signed int)x >> 1] >> 4;
						p = (char *)p + 1;
					}
					++x;
				}
				pbits = (char *)pbits + bmpInfo.biWidth;
				++y;
			}
		}
		else
		{
			widthBytes = (LOWORD(bmpInfo.biWidth) + 3) & 0xFFFC;
			y = 0;
			pbits = (char *)pImg + (bmpInfo.biHeight - 1) * bmpInfo.biWidth;
			while (y < bmpInfo.biHeight)
			{
				((void(__stdcall *)(IStoreStream *, unsigned int, void *))pStream->baseclass_0.vfptr[3].Release)(
					pStream,
					bmpInfo.biWidth,
					pbits);
				if (widthBytes != bmpInfo.biWidth)
					((void(__stdcall *)(IStoreStream *, unsigned int, _DWORD))pStream->baseclass_0.vfptr[3].Release)(
					pStream,
					widthBytes - bmpInfo.biWidth,
					buff);
				pbits = (char *)pbits - bmpInfo.biWidth;
				++y;
			}
		}
		gr_init_bitmap((grs_bitmap *)pbm, (char *)pImg, 2u, 0, bmpInfo.biWidth, bmpInfo.biHeight);
		result = (grs_bitmap *)pbm;
	}
	else
	{
		result = 0;
	}
	return result;
}
// E81640: using guessed type int g_pMalloc;

//----- (008F24F7) --------------------------------------------------------
void *__cdecl ResBmpReadPalette(IStoreStream *pStream, IResMemOverride *pResMem)
{
	void *result; // eax@2
	BmpHead bmpHead; // [sp+0h] [bp-44Ch]@1
	unsigned int i; // [sp+10h] [bp-43Ch]@11
	void *pPall; // [sp+14h] [bp-438h]@5
	char pall[1024]; // [sp+18h] [bp-434h]@11
	void *dpall; // [sp+418h] [bp-34h]@11
	BmpInfo bmpInfo; // [sp+41Ch] [bp-30h]@1
	void *spall; // [sp+444h] [bp-8h]@11
	unsigned int numPall; // [sp+448h] [bp-4h]@9

	if (ResBmpReadHeader(pStream, &bmpHead, &bmpInfo))
	{
		if (g_pMalloc)
			(*(void(__stdcall **)(int, _DWORD, signed int))(*(_DWORD *)g_pMalloc + 72))(
			g_pMalloc,
			"x:\\prj\\tech\\libsrc\\namedres\\bmp.cpp",
			187);
		pPall = (void *)((int(__stdcall *)(IResMemOverride *, signed int))pResMem->baseclass_0.vfptr[1].QueryInterface)(
			pResMem,
			768);
		if (g_pMalloc)
			(*(void(__stdcall **)(int))(*(_DWORD *)g_pMalloc + 76))(g_pMalloc);
		if (pPall)
		{
			memset(pPall, 0, 0x300u);
			numPall = bmpInfo.biClrUsed;
			if (!bmpInfo.biClrUsed)
				numPall = bmpInfo.biBitCount != 4 ? 256 : 16;
			((void(__stdcall *)(IStoreStream *, unsigned int, _DWORD))pStream->baseclass_0.vfptr[3].Release)(
				pStream,
				4 * numPall,
				pall);
			i = 0;
			dpall = pPall;
			spall = pall;
			while ((signed int)i < (signed int)numPall)
			{
				*(_BYTE *)dpall = *((_BYTE *)spall + 2);
				dpall = (char *)dpall + 1;
				*(_BYTE *)dpall = *((_BYTE *)spall + 1);
				dpall = (char *)dpall + 1;
				*(_BYTE *)dpall = *(_BYTE *)spall;
				dpall = (char *)dpall + 1;
				++i;
				spall = (char *)spall + 4;
			}
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
