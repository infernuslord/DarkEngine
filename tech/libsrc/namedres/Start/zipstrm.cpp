//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>


//----- (008F2680) --------------------------------------------------------
void __thiscall __cDynFunc__PkExplode::__cDynFunc__PkExplode(__cDynFunc__PkExplode *this)
{
	cDynFunc::cDynFunc(&this->baseclass_0, _pcszDynFuncPkExplode_Lib, _pcszDynFuncPkExplode_Sig, PkFail_1);
}

//----- (008F26A8) --------------------------------------------------------
void __cdecl PkFail_1()
{
	_CriticalMsg("Failed to locate and load implode.dll!", "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 0x3Fu);
	exit(1);
}

//----- (008F26C8) --------------------------------------------------------
int __cdecl _E9_71()
{
	_E5_40();
	return _E8_65();
}

//----- (008F26D7) --------------------------------------------------------
void __cdecl _E5_40()
{
	__cDynFunc__PkExplode::__cDynFunc__PkExplode(&__cDynFunc__PkExplode::__DynFunc__PkExplode);
}

//----- (008F26E6) --------------------------------------------------------
int __cdecl _E8_65()
{
	return atexit(_E6_57);
}

//----- (008F26F8) --------------------------------------------------------
void __cdecl _E6_57()
{
	if (!(_S7_15 & 1))
	{
		_S7_15 |= 1u;
		__cDynFunc__PkExplode::___cDynFunc__PkExplode(&__cDynFunc__PkExplode::__DynFunc__PkExplode);
	}
}

//----- (008F2724) --------------------------------------------------------
unsigned int __cdecl PkExplodeReader(char *buf, unsigned int *size, void *param)
{
	unsigned int result; // eax@3
	int v4; // ST1C_4@12
	unsigned int v5; // [sp+0h] [bp-1Ch]@15
	int v6; // [sp+4h] [bp-18h]@6
	signed int targetReadSize; // [sp+Ch] [bp-10h]@8

	if (param && !*((_DWORD *)param + 7))
	{
		if (*((_DWORD *)param + 1) >= *((_DWORD *)param + 2))
		{
			if (*((_DWORD *)param + 5))
				v6 = *((_DWORD *)param + 5);
			else
				v6 = *((_DWORD *)param + 4) - *((_DWORD *)param + 3);
			targetReadSize = v6;
			if ((unsigned int)v6 <= 0x10000)
			{
				if ((unsigned int)v6 < 1)
					targetReadSize = 1;
			}
			else
			{
				targetReadSize = 65536;
			}
			v4 = (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)param + 44))(
				*(_DWORD *)param,
				targetReadSize,
				*((_DWORD *)param + 6));
			*((_DWORD *)param + 1) = *((_DWORD *)param + 6);
			*((_DWORD *)param + 2) = v4 + *((_DWORD *)param + 1);
		}
		if (*((_DWORD *)param + 2) == *((_DWORD *)param + 1))
		{
			result = 0;
		}
		else
		{
			if (*((_DWORD *)param + 2) - *((_DWORD *)param + 1) <= *size)
				v5 = *((_DWORD *)param + 2) - *((_DWORD *)param + 1);
			else
				v5 = *size;
			memcpy(buf, *((const void **)param + 1), v5);
			*((_DWORD *)param + 1) += v5;
			*size = v5;
			result = v5;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008F2847) --------------------------------------------------------
void __cdecl PkExplodeWriter(char *buf, unsigned int *size, void *param)
{
	unsigned int actualSize; // [sp+0h] [bp-8h]@1

	actualSize = *size;
	if (*((_DWORD *)param + 5))
	{
		if (*((_DWORD *)param + 5) > actualSize)
		{
			*((_DWORD *)param + 5) -= actualSize;
			return;
		}
		actualSize -= *((_DWORD *)param + 5);
		buf += *((_DWORD *)param + 5);
		*((_DWORD *)param + 5) = 0;
	}
	if (actualSize + *((_DWORD *)param + 3) > *((_DWORD *)param + 4))
		actualSize = *((_DWORD *)param + 4) - *((_DWORD *)param + 3);
	memcpy(*((void **)param + 3), buf, actualSize);
	*((_DWORD *)param + 3) += actualSize;
	if (*((_DWORD *)param + 3) > *((_DWORD *)param + 4))
		*((_DWORD *)param + 7) = 1;
}

//----- (008F2907) --------------------------------------------------------
int __cdecl PkExplodeStreamToMem(IStoreStream *pSourceStream, void *pDest, int skip, int destMax)
{
	unsigned int(__cdecl *v4)(unsigned int(__cdecl *)(char *, unsigned int *, void *), void(__cdecl *)(char *, unsigned int *, void *), char *, void *); // eax@5
	int v5; // eax@9
	const char *v6; // eax@10
	void *pWorkBuf; // [sp+0h] [bp-28h]@3
	sPkExplodeInfo explodeInfo; // [sp+4h] [bp-24h]@5
	unsigned int result; // [sp+24h] [bp-4h]@5

	if (!pPkBuffer)
		pPkBuffer = MallocSpew(0x13134u, "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 219);
	pWorkBuf = pPkBuffer;
	if (!destMax)
		destMax = 134217728;
	explodeInfo.pSourceStream = pSourceStream;
	explodeInfo.pReadBuf = (char *)pPkBuffer + 12596;
	explodeInfo.pSource = (char *)pPkBuffer + 12596;
	explodeInfo.pSourceLimit = (char *)pPkBuffer + 12596;
	explodeInfo.pDest = (char *)pDest;
	explodeInfo.pDestLimit = (char *)pDest + destMax;
	explodeInfo.skip = skip;
	explodeInfo.fComplete = 0;
	v4 = __cDynFunc__PkExplode::GetProcAddress(&__cDynFunc__PkExplode::__DynFunc__PkExplode);
	result = v4(PkExplodeReader, PkExplodeWriter, (char *)pWorkBuf, &explodeInfo);
	if (result && (result != 4 || !explodeInfo.fComplete) || explodeInfo.pDest > (char *)explodeInfo.pDestLimit)
	{
		v6 = _LogFmt("Expansion failed (%d)!");
		_CriticalMsg(v6, "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 0xF9u);
		v5 = 0;
	}
	else
	{
		v5 = explodeInfo.pDest - (char *)pDest;
	}
	return v5;
}
// EAC81C: using guessed type void *pPkBuffer;

//----- (008F29F1) --------------------------------------------------------
void *__cdecl ZAllocInterface(void *__formal, unsigned int items, unsigned int size)
{
	return MallocSpew(size * items, "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 274);
}

//----- (008F2A10) --------------------------------------------------------
void __cdecl ZFreeInterface(void *__formal, void *addr)
{
	FreeSpew(addr, "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 278);
}

//----- (008F2A2B) --------------------------------------------------------
int __cdecl ZInflateStreamToMem(IStoreStream *pStream, int nStreamSize, void *pData, int nSize)
{
	int result; // eax@2
	const char *v5; // eax@13
	const char *v6; // eax@26
	int v7; // [sp+0h] [bp-5Ch]@17
	int v8; // [sp+4h] [bp-58h]@4
	int fFlush; // [sp+8h] [bp-54h]@3
	int totalReadSize; // [sp+Ch] [bp-50h]@10
	z_stream_s zBlock; // [sp+10h] [bp-4Ch]@12
	void *inputBuffer; // [sp+48h] [bp-14h]@3
	int ret; // [sp+4Ch] [bp-10h]@12
	unsigned int actualReadSize; // [sp+50h] [bp-Ch]@6
	int actualRead; // [sp+54h] [bp-8h]@28
	int finished; // [sp+58h] [bp-4h]@3

	if (nStreamSize)
	{
		inputBuffer = MallocSpew(0x10000u, "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 307);
		fFlush = 0;
		finished = 0;
		if (nStreamSize >= 65536)
			v8 = 65536;
		else
			v8 = nStreamSize;
		actualReadSize = ((int(__stdcall *)(IStoreStream *, int, void *))pStream->baseclass_0.vfptr[3].Release)(
			pStream,
			v8,
			inputBuffer);
		if (!actualReadSize)
			_CriticalMsg("Inflating empty file!", "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 0x144u);
		if (actualReadSize)
		{
			totalReadSize = actualReadSize;
			if (actualReadSize == nStreamSize)
				fFlush = 4;
			zBlock.next_in = (char *)inputBuffer;
			zBlock.avail_in = actualReadSize;
			zBlock.next_out = (char *)pData;
			zBlock.avail_out = nSize;
			zBlock.zalloc = ZAllocInterface;
			zBlock.zfree = ZFreeInterface;
			zBlock.opaque = 0;
			ret = inflateInit2_(&zBlock, -15, "1.1.2", 56);
			if (ret)
			{
				v5 = _LogFmt("zlib inflateInit failed with %d\n");
				_CriticalMsg(v5, "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 0x15Du);
			}
			do
			{
				if (!zBlock.avail_in && totalReadSize < nStreamSize)
				{
					if (nStreamSize - totalReadSize >= 65536)
						v7 = 65536;
					else
						v7 = nStreamSize - totalReadSize;
					actualReadSize = ((int(__stdcall *)(IStoreStream *, int, void *))pStream->baseclass_0.vfptr[3].Release)(
						pStream,
						v7,
						inputBuffer);
					zBlock.next_in = (char *)inputBuffer;
					zBlock.avail_in = actualReadSize;
					totalReadSize += actualReadSize;
				}
				ret = inflate(&zBlock, fFlush);
				if (ret == 1)
				{
					finished = 1;
				}
				else
				{
					if (ret)
					{
						v6 = _LogFmt("zlib inflate returned %d!\n");
						_CriticalMsg(v6, "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 0x174u);
						FreeSpew(inputBuffer, "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 373);
						return -1;
					}
					if (!zBlock.avail_out)
						_CriticalMsg(
						"zlib inflate: buffer full before end!",
						"x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp",
						0x171u);
				}
			} while (!finished);
			actualRead = nSize - zBlock.avail_out;
			inflateEnd(&zBlock);
			FreeSpew(inputBuffer, "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 382);
			result = actualRead;
		}
		else
		{
			FreeSpew(inputBuffer, "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 326);
			result = 0;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008F2C80) --------------------------------------------------------
int __stdcall cZipStream::QueryInterface(cZipStream *this, _GUID *id, void **ppI)
{
	int result; // eax@5

	if (id != &IID_IStoreStream
		&& id != &IID_IUnknown
		&& memcmp(id, &IID_IStoreStream, 0x10u)
		&& memcmp(id, &IID_IUnknown, 0x10u))
	{
		*ppI = 0;
		result = -2147467262;
	}
	else
	{
		*ppI = this;
		this->baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)this);
		result = 0;
	}
	return result;
}

//----- (008F2CED) --------------------------------------------------------
unsigned int __stdcall cZipStream::AddRef(cZipStream *this)
{
	return cZipStream::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008F2CFF) --------------------------------------------------------
unsigned int __stdcall cZipStream::Release(cZipStream *this)
{
	unsigned int result; // eax@2

	if (cZipStream::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cZipStream::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cZipStream::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (008F2D2C) --------------------------------------------------------
void __thiscall cZipStream::cZipStream(cZipStream *this, IStore *pStore, cZipStorage *pMaster, cNamedZipStream *pInfo)
{
	cZipStream *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	IStoreStream::IStoreStream(&this->baseclass_0);
	cZipStream::cRefCount::cRefCount(&thisa->__m_ulRefs);
	thisa->m_pStorage = pStore;
	thisa->m_pMaster = pMaster;
	thisa->m_pInfo = pInfo;
	thisa->m_pFileSpec = 0;
	thisa->m_nLastPos = 0;
	thisa->m_pData = 0;
	thisa->m_nOpenCount = 0;
	thisa->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cZipStream::_vftable_;
	if (!thisa->m_pStorage)
		_CriticalMsg("Creating Zip stream without a storage.", "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 0x193u);
	if (!thisa->m_pMaster)
		_CriticalMsg("Creating Zip stream without a master.", "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 0x194u);
	if (!thisa->m_pInfo)
		_CriticalMsg("Creating Zip stream without info.", "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 0x195u);
	thisa->m_pStorage->baseclass_0.vfptr->AddRef((IUnknown *)thisa->m_pStorage);
	thisa->m_pMaster->baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr->AddRef((IUnknown *)thisa->m_pMaster);
}
// 9A8CAC: using guessed type int (__stdcall *cZipStream___vftable_)(int this, int id, int ppI);

//----- (008F2E2E) --------------------------------------------------------
void __thiscall cZipStream::_cZipStream(cZipStream *this)
{
	cZipStream *thisa; // [sp+4h] [bp-10h]@1
	cFileSpec *v2; // [sp+Ch] [bp-8h]@8
	void *pName; // [sp+10h] [bp-4h]@2

	thisa = this;
	this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cZipStream::_vftable_;
	if (this->m_nOpenCount > 0)
	{
		cZipStream::GetName(this, (char **)&pName);
		DbgReportWarning("cZipStream: %s deleted without being fully Closed!\n");
		FreeSpew(pName, "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 419);
		FreeSpew(thisa->m_pData, "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 420);
		thisa->m_nOpenCount = 0;
		thisa->m_pData = 0;
	}
	if (thisa->m_pStorage)
	{
		thisa->m_pStorage->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pStorage);
		thisa->m_pStorage = 0;
	}
	if (thisa->m_pMaster)
	{
		thisa->m_pMaster->baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr->Release((IUnknown *)thisa->m_pMaster);
		thisa->m_pMaster = 0;
	}
	if (thisa->m_pFileSpec)
	{
		v2 = thisa->m_pFileSpec;
		if (v2)
			cFileSpec::_scalar_deleting_destructor_(v2, 1u);
		thisa->m_pFileSpec = 0;
	}
}
// 9A8CAC: using guessed type int (__stdcall *cZipStream___vftable_)(int this, int id, int ppI);

//----- (008F2F36) --------------------------------------------------------
void __stdcall cZipStream::SetName(cZipStream *this, const char *pName)
{
	cFileSpec *v2; // eax@9
	const char *v3; // eax@12
	cFileSpec *v4; // eax@13
	cFileSpec *v5; // [sp+0h] [bp-28h]@13
	cFileSpec *v6; // [sp+4h] [bp-24h]@9
	void *v7; // [sp+Ch] [bp-1Ch]@12
	void *v8; // [sp+10h] [bp-18h]@8
	cFileSpec *v9; // [sp+18h] [bp-10h]@4
	cFilePath StorePath; // [sp+1Ch] [bp-Ch]@12

	if (!pName)
		_CriticalMsg("Setting Zip stream name to null", "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 0x1BEu);
	if (this->m_pFileSpec)
	{
		v9 = this->m_pFileSpec;
		if (v9)
			cFileSpec::_scalar_deleting_destructor_(v9, 1u);
		this->m_pFileSpec = 0;
	}
	if (this->m_pStorage)
	{
		v3 = (const char *)this->m_pStorage->baseclass_0.vfptr[1].AddRef((IUnknown *)this->m_pStorage);
		cFilePath::cFilePath(&StorePath, v3);
		v7 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 461);
		if (v7)
		{
			cFileSpec::cFileSpec((cFileSpec *)v7, &StorePath, pName);
			v5 = v4;
		}
		else
		{
			v5 = 0;
		}
		this->m_pFileSpec = v5;
		cFilePath::_cFilePath(&StorePath);
	}
	else
	{
		v8 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 456);
		if (v8)
		{
			cFileSpec::cFileSpec((cFileSpec *)v8, pName);
			v6 = v2;
		}
		else
		{
			v6 = 0;
		}
		this->m_pFileSpec = v6;
	}
}

//----- (008F3050) --------------------------------------------------------
int __stdcall cZipStream::Open(cZipStream *this)
{
	const char *v2; // eax@18
	int nRealSize; // [sp+0h] [bp-8h]@0
	IStoreStream *pRealStream; // [sp+4h] [bp-4h]@4
	IStoreStream *pRealStreama; // [sp+4h] [bp-4h]@11

	if (this->m_pInfo->m_nCompressionMethod)
	{
		if (this->m_pData)
		{
			++this->m_nOpenCount;
			return 1;
		}
		this->m_pData = (char *)MallocSpew(
			this->m_pInfo->m_nUncompressedSize,
			"x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp",
			500);
		if (!this->m_pData)
			return 0;
		pRealStreama = cZipStorage::ReadyStreamAt(this->m_pMaster, this->m_pInfo->m_nHeaderOffset);
		if (!pRealStreama)
			_CriticalMsg("Opening zip stream with no real stream!", "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 0x1FBu);
		if (this->m_pInfo->m_nCompressionMethod == 8)
		{
			nRealSize = ZInflateStreamToMem(
				pRealStreama,
				this->m_pInfo->m_nCompressedSize,
				this->m_pData,
				this->m_pInfo->m_nUncompressedSize);
		}
		else
		{
			if (this->m_pInfo->m_nCompressionMethod == 10)
				nRealSize = PkExplodeStreamToMem(pRealStreama, this->m_pData, 0, this->m_pInfo->m_nUncompressedSize);
		}
		if (nRealSize != this->m_pInfo->m_nUncompressedSize)
		{
			v2 = _LogFmt("Zip stream: expected size of %ld, got %ld");
			_CriticalMsg(v2, "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 0x20Fu);
		}
		pRealStreama->baseclass_0.vfptr->Release((IUnknown *)pRealStreama);
		this->m_nLastPos = 0;
		++this->m_nOpenCount;
	}
	else
	{
		if (this->m_nOpenCount > 0)
		{
			++this->m_nOpenCount;
			return 1;
		}
		pRealStream = cZipStorage::ReadyStreamAt(this->m_pMaster, this->m_pInfo->m_nHeaderOffset);
		if (!pRealStream)
			_CriticalMsg("Opening zip stream with no real stream!", "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 0x1E5u);
		pRealStream->baseclass_0.vfptr->Release((IUnknown *)pRealStream);
		this->m_nLastPos = 0;
		++this->m_nOpenCount;
	}
	return 1;
}

//----- (008F325F) --------------------------------------------------------
void __stdcall cZipStream::Close(cZipStream *this)
{
	if (!this->m_nOpenCount)
		_CriticalMsg("cZipStream closed more than opened", "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 0x21Au);
	if (this->m_pInfo->m_nCompressionMethod)
	{
		--this->m_nOpenCount;
		if (!this->m_nOpenCount)
		{
			FreeSpew(this->m_pData, "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 548);
			this->m_pData = 0;
		}
	}
	else
	{
		--this->m_nOpenCount;
	}
}

//----- (008F32E7) --------------------------------------------------------
void __stdcall cZipStream::GetName(cZipStream *this, char **ppName)
{
	cAnsiStr Name; // [sp+0h] [bp-Ch]@1

	cAnsiStr::cAnsiStr(&Name);
	cFileSpec::GetNameString(this->m_pFileSpec, &Name, 0);
	*ppName = cAnsiStr::Detach(&Name);
	cAnsiStr::_cAnsiStr(&Name);
}

//----- (008F3321) --------------------------------------------------------
int __stdcall cZipStream::SetPos(cZipStream *this, int nPos)
{
	int result; // eax@2

	if (this->m_nOpenCount)
	{
		if (nPos >= this->m_pInfo->m_nUncompressedSize)
		{
			result = 0;
		}
		else
		{
			this->m_nLastPos = nPos;
			result = 1;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008F3355) --------------------------------------------------------
int __stdcall cZipStream::GetPos(cZipStream *this)
{
	int result; // eax@2

	if (this->m_nOpenCount)
		result = this->m_nLastPos;
	else
		result = -1;
	return result;
}

//----- (008F3370) --------------------------------------------------------
int __stdcall cZipStream::ReadAbs(cZipStream *this, int nStartPos, int nEndPos, char *pBuf)
{
	int result; // eax@2

	if (this->m_nOpenCount)
	{
		if (((int(__stdcall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[2].AddRef)(this, nStartPos))
			result = ((int(__stdcall *)(_DWORD, _DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[3].Release)(
			this,
			nEndPos - nStartPos,
			pBuf);
		else
			result = -1;
	}
	else
	{
		result = -1;
	}
	return result;
}

//----- (008F33B5) --------------------------------------------------------
int __stdcall cZipStream::GetSize(cZipStream *this)
{
	return this->m_pInfo->m_nUncompressedSize;
}

//----- (008F33C5) --------------------------------------------------------
int __stdcall cZipStream::Read(cZipStream *this, int nNumBytes, char *pBuf)
{
	int v4; // eax@12
	int v5; // ST0C_4@12
	int nBytesLeft; // [sp+4h] [bp-8h]@5
	IStoreStream *pRealStream; // [sp+8h] [bp-4h]@10

	if (!this->m_nOpenCount)
		return -1;
	if (nNumBytes < 1)
		return -1;
	nBytesLeft = this->m_pInfo->m_nUncompressedSize - this->m_nLastPos;
	if (nBytesLeft <= 0)
		return -1;
	if (nNumBytes > nBytesLeft)
		nNumBytes = this->m_pInfo->m_nUncompressedSize - this->m_nLastPos;
	if (this->m_pInfo->m_nCompressionMethod)
	{
		if (!this->m_pData)
			return -1;
		memmove(pBuf, &this->m_pData[this->m_nLastPos], nNumBytes);
	}
	else
	{
		pRealStream = cZipStorage::ReadyStreamAt(this->m_pMaster, this->m_pInfo->m_nHeaderOffset);
		if (!pRealStream)
			_CriticalMsg("Opening zip stream with no real stream!", "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 0x273u);
		v4 = pRealStream->baseclass_0.vfptr[2].Release((IUnknown *)pRealStream);
		((void(__stdcall *)(_DWORD, _DWORD))pRealStream->baseclass_0.vfptr[2].AddRef)(pRealStream, this->m_nLastPos + v4);
		v5 = ((int(__stdcall *)(_DWORD, _DWORD, _DWORD))pRealStream->baseclass_0.vfptr[3].Release)(
			pRealStream,
			nNumBytes,
			pBuf);
		pRealStream->baseclass_0.vfptr->Release((IUnknown *)pRealStream);
		if (v5 != nNumBytes)
			_CriticalMsg(
			"Read failed to get the right number of bytes.",
			"x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp",
			0x277u);
	}
	this->m_nLastPos += nNumBytes;
	return nNumBytes;
}

//----- (008F3511) --------------------------------------------------------
__int16 __stdcall cZipStream::Getc(cZipStream *this)
{
	__int16 result; // ax@3
	char v2; // ST0C_1@12
	unsigned __int8 c; // [sp+4h] [bp-4h]@4

	if (this->m_pInfo->m_nCompressionMethod)
	{
		if (this->m_pData && this->m_nOpenCount)
		{
			if (this->m_nLastPos < this->m_pInfo->m_nUncompressedSize)
			{
				v2 = this->m_pData[this->m_nLastPos++];
				result = (unsigned __int8)v2;
			}
			else
			{
				result = -1;
			}
		}
		else
		{
			result = -1;
		}
	}
	else
	{
		if (this->m_nOpenCount)
		{
			if (((int(__stdcall *)(_DWORD, _DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[3].Release)(this, 1, &c) == 1)
				result = c;
			else
				result = -1;
		}
		else
		{
			result = -1;
		}
	}
	return result;
}

//----- (008F35B5) --------------------------------------------------------
void __stdcall cZipStream::ReadBlocks(cZipStream *this, void *pBuf, int nSize, int(__cdecl *Callback)(void *, int, int, void *), void *pCallbackData)
{
	int nRead; // [sp+0h] [bp-14h]@6
	unsigned int pEnd; // [sp+4h] [bp-10h]@1
	int nBlockIx; // [sp+Ch] [bp-8h]@1
	const void *p; // [sp+10h] [bp-4h]@1

	_CriticalMsg("cZipStream::ReadBlocks Not implemented.", "x:\\prj\\tech\\libsrc\\namedres\\zipstrm.cpp", 0x2AAu);
	nBlockIx = 0;
	p = &this->m_pData[this->m_nLastPos];
	pEnd = (unsigned int)&this->m_pData[this->m_pInfo->m_nUncompressedSize];
	if (this->m_pData && this->m_nOpenCount && Callback)
	{
		while ((unsigned int)p < pEnd)
		{
			nRead = (unsigned int)((char *)p + nSize) < pEnd ? nSize : pEnd - (_DWORD)p;
			memmove(pBuf, p, nRead);
			p = (char *)p + nRead;
			nSize = Callback(pBuf, nRead, nBlockIx, pCallbackData);
			if (nSize < 1)
				break;
			++nBlockIx;
		}
		this->m_nLastPos = p - this->m_pData;
	}
}

//----- (008F36B2) --------------------------------------------------------
unsigned int __stdcall cZipStream::LastModified(cZipStream *this)
{
	return cZipStorage::LastModified(this->m_pMaster);
}

//----- (008F36D0) --------------------------------------------------------
void __thiscall __cDynFunc__PkExplode::___cDynFunc__PkExplode(__cDynFunc__PkExplode *this)
{
	cDynFunc::_cDynFunc(&this->baseclass_0);
}

//----- (008F36F0) --------------------------------------------------------
unsigned int(__cdecl *__thiscall __cDynFunc__PkExplode::GetProcAddress(__cDynFunc__PkExplode *this))(unsigned int(__cdecl *)(char *, unsigned int *, void *), void(__cdecl *)(char *, unsigned int *, void *), char *, void *)
{
	return (unsigned int(__cdecl *)(unsigned int(__cdecl *)(char *, unsigned int *, void *), void(__cdecl *)(char *, unsigned int *, void *), char *, void *))cDynFunc::GetFunc(&this->baseclass_0);
}

//----- (008F3710) --------------------------------------------------------
unsigned int __thiscall cZipStream::cRefCount::AddRef(cZipStream::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008F3730) --------------------------------------------------------
unsigned int __thiscall cZipStream::cRefCount::Release(cZipStream::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008F3750) --------------------------------------------------------
unsigned int __thiscall cZipStream::cRefCount::operator unsigned_long(cZipStream::cRefCount *this)
{
	return this->ul;
}

//----- (008F3760) --------------------------------------------------------
void __thiscall cZipStream::OnFinalRelease(cZipStream *this)
{
	if (this)
		((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[5].QueryInterface)(this, 1);
}

//----- (008F37A0) --------------------------------------------------------
void __thiscall cZipStream::cRefCount::cRefCount(cZipStream::cRefCount *this)
{
	this->ul = 1;
}

//----- (008F37C0) --------------------------------------------------------
void *__thiscall cZipStream::_scalar_deleting_destructor_(cZipStream *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cZipStream::_cZipStream(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}