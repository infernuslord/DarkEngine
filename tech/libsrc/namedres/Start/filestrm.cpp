//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>




//----- (008F3840) --------------------------------------------------------
int __stdcall cFileStream::QueryInterface(cFileStream *this, _GUID *id, void **ppI)
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

//----- (008F38AD) --------------------------------------------------------
unsigned int __stdcall cFileStream::AddRef(cFileStream *this)
{
	return cFileStream::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008F38BF) --------------------------------------------------------
unsigned int __stdcall cFileStream::Release(cFileStream *this)
{
	unsigned int result; // eax@2

	if (cFileStream::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cFileStream::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cFileStream::OnFinalRelease(this);
		result = 0;
	}
	return result;
}

//----- (008F38EC) --------------------------------------------------------
void __thiscall cFileStream::cFileStream(cFileStream *this, IStore *pStore)
{
	cFileStream *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	IStoreStream::IStoreStream(&this->baseclass_0);
	cFileStream::cRefCount::cRefCount(&thisa->__m_ulRefs);
	thisa->m_pStorage = pStore;
	thisa->m_pFile = 0;
	thisa->m_pFileSpec = 0;
	thisa->m_nLastPos = 0;
	thisa->m_nOpenCount = 0;
	thisa->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cFileStream::_vftable_;
	if (thisa->m_pStorage)
		thisa->m_pStorage->baseclass_0.vfptr->AddRef((IUnknown *)thisa->m_pStorage);
}
// 9A8D28: using guessed type int (__stdcall *cFileStream___vftable_)(int this, int id, int ppI);

//----- (008F3964) --------------------------------------------------------
void __thiscall cFileStream::_cFileStream(cFileStream *this)
{
	const char *v1; // eax@2
	cFileStream *thisa; // [sp+4h] [bp-10h]@1
	cFileSpec *v3; // [sp+Ch] [bp-8h]@6
	void *pName; // [sp+10h] [bp-4h]@2

	thisa = this;
	this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cFileStream::_vftable_;
	if (this->m_pFile)
	{
		cFileStream::GetName(this, (char **)&pName);
		v1 = _LogFmt("Destroying stream %s that was not fully closed!");
		_CriticalMsg(v1, "x:\\prj\\tech\\libsrc\\namedres\\filestrm.cpp", 0x37u);
		FreeSpew(pName, "x:\\prj\\tech\\libsrc\\namedres\\filestrm.cpp", 56);
		fclose(thisa->m_pFile);
		thisa->m_pFile = 0;
	}
	if (thisa->m_pStorage)
	{
		thisa->m_pStorage->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pStorage);
		thisa->m_pStorage = 0;
	}
	if (thisa->m_pFileSpec)
	{
		v3 = thisa->m_pFileSpec;
		if (v3)
			cFileSpec::_scalar_deleting_destructor_(v3, 1u);
		thisa->m_pFileSpec = 0;
	}
}
// 9A8D28: using guessed type int (__stdcall *cFileStream___vftable_)(int this, int id, int ppI);

//----- (008F3A3D) --------------------------------------------------------
void __stdcall cFileStream::SetName(cFileStream *this, const char *pName)
{
	cFileSpec *v2; // eax@8
	const char *v3; // eax@11
	cFileSpec *v4; // eax@12
	cFileSpec *v5; // [sp+0h] [bp-28h]@12
	cFileSpec *v6; // [sp+4h] [bp-24h]@8
	void *v7; // [sp+Ch] [bp-1Ch]@11
	void *v8; // [sp+10h] [bp-18h]@7
	cFileSpec *v9; // [sp+18h] [bp-10h]@3
	cFilePath StorePath; // [sp+1Ch] [bp-Ch]@11

	if (pName)
	{
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
			v7 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\filestrm.cpp", 92);
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
			v8 = j__new(8u, "x:\\prj\\tech\\libsrc\\namedres\\filestrm.cpp", 87);
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
}

//----- (008F3B3A) --------------------------------------------------------
int __stdcall cFileStream::Open(cFileStream *this)
{
	void *v1; // ecx@0
	int result; // eax@2
	const char *pFileName; // [sp+0h] [bp-4h]@1

	pFileName = (const char *)v1;
	if (this->m_pFile)
	{
		++this->m_nOpenCount;
		result = 1;
	}
	else
	{
		if (this->m_pFileSpec)
		{
			((void(__stdcall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[2].QueryInterface)(this, &pFileName);
			this->m_pFile = fopen(pFileName, "rb");
			FreeSpew((void *)pFileName, "x:\\prj\\tech\\libsrc\\namedres\\filestrm.cpp", 111);
			if (this->m_pFile)
			{
				this->m_nLastPos = 0;
				++this->m_nOpenCount;
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
	}
	return result;
}

//----- (008F3BD5) --------------------------------------------------------
void __stdcall cFileStream::Close(cFileStream *this)
{
	if (this->m_pFile)
	{
		--this->m_nOpenCount;
		if (!this->m_nOpenCount)
		{
			fclose(this->m_pFile);
			this->m_pFile = 0;
		}
	}
}

//----- (008F3C18) --------------------------------------------------------
void __stdcall cFileStream::GetName(cFileStream *this, char **ppName)
{
	cAnsiStr Name; // [sp+0h] [bp-Ch]@1

	cAnsiStr::cAnsiStr(&Name);
	cFileSpec::GetNameString(this->m_pFileSpec, &Name, 0);
	*ppName = cAnsiStr::Detach(&Name);
	cAnsiStr::_cAnsiStr(&Name);
}

//----- (008F3C52) --------------------------------------------------------
int __stdcall cFileStream::SetPos(cFileStream *this, int nPos)
{
	int result; // eax@2

	if (this->m_pFile)
	{
		this->m_nLastPos = nPos;
		result = fseek(this->m_pFile, nPos, 0) == 0;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008F3C89) --------------------------------------------------------
int __stdcall cFileStream::GetPos(cFileStream *this)
{
	int result; // eax@2

	if (this->m_pFile)
		result = this->m_nLastPos;
	else
		result = 0;
	return result;
}

//----- (008F3CA3) --------------------------------------------------------
int __stdcall cFileStream::ReadAbs(cFileStream *this, int nStartPos, int nEndPos, char *pBuf)
{
	int result; // eax@2

	if (this->m_pFile)
	{
		if (this->m_nLastPos != nStartPos && fseek(this->m_pFile, nStartPos, 0))
		{
			result = -1;
		}
		else
		{
			result = fread(pBuf, 1u, nEndPos - nStartPos + 1, this->m_pFile);
			this->m_nLastPos = result + nStartPos;
		}
	}
	else
	{
		result = -1;
	}
	return result;
}

//----- (008F3D15) --------------------------------------------------------
int __stdcall cFileStream::GetSize(cFileStream *this)
{
	int v1; // eax@2
	int result; // eax@2
	int v3; // eax@6
	const char *pFileName; // [sp+0h] [bp-8h]@4
	int nSize; // [sp+4h] [bp-4h]@6

	if (this->m_pFile)
	{
		v1 = fileno(this->m_pFile);
		result = filelength(v1);
	}
	else
	{
		if (this->m_pFileSpec)
		{
			((void(__stdcall *)(cFileStream *, const char **))this->baseclass_0.baseclass_0.vfptr[2].QueryInterface)(
				this,
				&pFileName);
			this->m_pFile = fopen(pFileName, "rb");
			FreeSpew((void *)pFileName, "x:\\prj\\tech\\libsrc\\namedres\\filestrm.cpp", 185);
			if (this->m_pFile)
			{
				v3 = fileno(this->m_pFile);
				nSize = filelength(v3);
				fclose(this->m_pFile);
				result = nSize;
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
	return result;
}

//----- (008F3DCD) --------------------------------------------------------
int __stdcall cFileStream::Read(cFileStream *this, int nNumBytes, char *pBuf)
{
	int result; // eax@3

	if (this->m_pFile && nNumBytes >= 1)
	{
		result = fread(pBuf, 1u, nNumBytes, this->m_pFile);
		this->m_nLastPos += result;
	}
	else
	{
		result = -1;
	}
	return result;
}

//----- (008F3E19) --------------------------------------------------------
__int16 __stdcall cFileStream::Getc(cFileStream *this)
{
	__int16 result; // ax@2

	if (this->m_pFile)
	{
		++this->m_nLastPos;
		result = fgetc(this->m_pFile);
	}
	else
	{
		result = -1;
	}
	return result;
}

//----- (008F3E4D) --------------------------------------------------------
void __stdcall cFileStream::ReadBlocks(cFileStream *this, void *pBuf, int nSize, int(__cdecl *Callback)(void *, int, int, void *), void *pCallbackData)
{
	size_t nRead; // [sp+0h] [bp-Ch]@2
	signed int bDone; // [sp+4h] [bp-8h]@1
	int nBlockIx; // [sp+8h] [bp-4h]@1

	bDone = 0;
	nBlockIx = 0;
	if (this->m_pFile)
	{
		do
		{
			nRead = fread(pBuf, 1u, nSize, this->m_pFile);
			if ((signed int)nRead < nSize)
				bDone = 1;
			if (Callback)
			{
				nSize = Callback(pBuf, nRead, nBlockIx, pCallbackData);
				if (nSize < 1)
					bDone = 1;
			}
			++nBlockIx;
		} while (!bDone);
		this->m_nLastPos += nRead;
	}
}

//----- (008F3EE7) --------------------------------------------------------
unsigned int __stdcall cFileStream::LastModified(cFileStream *this)
{
	return cFileSpec::GetModificationTime(this->m_pFileSpec);
}

//----- (008F3F00) --------------------------------------------------------
unsigned int __thiscall cFileStream::cRefCount::AddRef(cFileStream::cRefCount *this)
{
	++this->ul;
	return this->ul;
}

//----- (008F3F20) --------------------------------------------------------
unsigned int __thiscall cFileStream::cRefCount::Release(cFileStream::cRefCount *this)
{
	--this->ul;
	return this->ul;
}

//----- (008F3F40) --------------------------------------------------------
unsigned int __thiscall cFileStream::cRefCount::operator unsigned_long(cFileStream::cRefCount *this)
{
	return this->ul;
}

//----- (008F3F50) --------------------------------------------------------
void __thiscall cFileStream::OnFinalRelease(cFileStream *this)
{
	if (this)
		((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[5].QueryInterface)(this, 1);
}

//----- (008F3F90) --------------------------------------------------------
void __thiscall cFileStream::cRefCount::cRefCount(cFileStream::cRefCount *this)
{
	this->ul = 1;
}

//----- (008F3FB0) --------------------------------------------------------
void *__thiscall cFileStream::_scalar_deleting_destructor_(cFileStream *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cFileStream::_cFileStream(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}