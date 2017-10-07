#include <Windows.h>
#include <lg.h>
#include <comtools.h>

#include "memtfil_.h"

#ifndef NO_DB_MEM
void *MallocSpew(size_t size, const char *file, int line);
#define Malloc(size) MallocSpew(size,__FILE__,__LINE__)
#endif





class cMemTagTable
{
public:
	/*
	tHashSetKey GetKey(tHashSetNode node) const
	{
		//return (tHashSetKey)node;
	}
	*/

	sMemTagEntry* AddTag(const TagFileTag* tag, const TagVersion* version)
	{
		cHashSet<sMemTagEntry*, char const*, cHashFunctions> *v3;
		void *v4;
		void *v5;
		unsigned int v6;

		v3 = (cHashSet<sMemTagEntry *, char const *, cHashFunctions> *)this;
		v4 = MallocSpew(0x20u, "x:\\prj\\tech\\libsrc\\tagfile\\memtfile.cpp", 32);
		v5 = v4;
		*(_DWORD *)v4 = *(_DWORD *)&tag->label[0];
		*((_DWORD *)v4 + 1) = *(_DWORD *)&tag->label[4];
		*((_DWORD *)v4 + 2) = *(_DWORD *)&tag->label[8];
		v6 = version->minor;
		*((_DWORD *)v4 + 3) = version->major;
		*((_DWORD *)v4 + 4) = v6;
		*((_DWORD *)v4 + 6) = 1024;
		*((_DWORD *)v4 + 7) = MallocSpew(*((_DWORD *)v4 + 6), "x:\\prj\\tech\\libsrc\\tagfile\\memtfile.cpp", 36);
		*((_DWORD *)v5 + 5) = 0;
		cHashSet<sMemTagEntry___char_const___cHashFunctions>::Insert(v3, (sMemTagEntry *)v5);
		return (sMemTagEntry *)v5;



	}

	//----- (008FD2A0)
	~cMemTagTable()
	{
		cHashSet<sMemTagEntry*, char const *, cHashFunctions> *thisa; // [sp+0h] [bp-18h]@1
		tHashSetHandle handle; // [sp+8h] [bp-10h]@1
		sMemTagEntry *e; // [sp+14h] [bp-4h]@1

		thisa = (cHashSet<sMemTagEntry *, char const *, cHashFunctions> *)this;
		this->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cMemTagTable::_vftable_;
		for (e = cHashSet<sMemTagEntry___char_const___cHashFunctions>::GetFirst(&this->baseclass_0.baseclass_0, &handle);
			e;
			e = cHashSet<sMemTagEntry___char_const___cHashFunctions>::GetNext(thisa, &handle))
		{
			if (e->buf)
				FreeSpew(e->buf, "x:\\prj\\tech\\libsrc\\tagfile\\memtfile.cpp", 25);
			operator delete(e);
		}
		cStrHashSet<sMemTagEntry__>::_cStrHashSet<sMemTagEntry__>((cStrHashSet<sMemTagEntry *> *)thisa);
	}

private:

};




class cMemFile
{
public:
	ulong BlockSize(const TagFileTag* tag)
	{
		unsigned int v3; // [sp+0h] [bp-8h]@2
		sMemTagEntry *e; // [sp+4h] [bp-4h]@1

		e = cHashSet<sMemTagEntry___char_const___cHashFunctions>::Search(&this->mpTable->baseclass_0.baseclass_0, tag->label);
		if (e)
			v3 = e->block_size;
		else
			v3 = 0;
		return v3;
	}

	const TagFileTag* CurrentBlock()
	{
		_TagFileTag *v2; // [sp+0h] [bp-4h]@2

		if (this->mpCurBlock)
			v2 = (_TagFileTag *)this->mpCurBlock;
		else
			v2 = 0;
		return v2;
	}

	int Seek(ulong offset, TagFileSeekMode from)
	{
		int result; // eax@2
		unsigned int origin; // [sp+0h] [bp-4h]@3

		if (this->mpCurBlock)
		{
			origin = 0;
			if (from == 1)
			{
				origin = this->mCursor;
			}
			else
			{
				if (from == 2)
					origin = this->mpCurBlock->block_size;
			}
			this->mCursor = offset + origin;
			result = 0;
		}
		else
		{
			result = -2147467259;
		}
		return result;
	}

	ulong Tell()
	{
		return this->mCursor;
	}

	//----- (008FD466) --------------------------------------------------------
	ulong TellFromEnd()
	{
		return this->mpCurBlock->block_size - this->mCursor;
	}

	//----- (008FD47C) --------------------------------------------------------
	ITagFileIter* Iterate()
	{
		ITagFileIter *v1; // eax@2
		ITagFileIter *v3; // [sp+0h] [bp-8h]@2
		void *v4; // [sp+4h] [bp-4h]@1

		v4 = j__new(0x1Cu, "x:\\prj\\tech\\libsrc\\tagfile\\memtfile.cpp", 126);
		if (v4)
		{
			cMemFileIter::cMemFileIter((cMemFileIter *)v4, this->mpTable);
			v3 = v1;
		}
		else
		{
			v3 = 0;
		}
		return v3;
	}

};




class cMemFileReadWrite
{
public:

	int OpenBlock(const TagFileTag* tag, VersionNum *version)
	{
		unsigned int v4; // edx@7
		sMemTagEntry *e; // [sp+0h] [bp-4h]@1

		e = cHashSet<sMemTagEntry___char_const___cHashFunctions>::Search(
			&this->baseclass_0.mpTable->baseclass_0.baseclass_0,
			tag->label);
		if (this->mMode == 1)
		{
			if (e)
				return -2147467259;
			e = cMemTagTable::AddTag(this->baseclass_0.mpTable, tag, version);
		}
		else
		{
			if (!e)
				return -2147467259;
			v4 = e->version.minor;
			version->major = e->version.major;
			version->minor = v4;
		}
		this->baseclass_0.mpCurBlock = e;
		this->baseclass_0.mCursor = 0;
		return 0;
	}

	int CloseBlock()
	{
		int result; // eax@2

		if (this->baseclass_0.mpCurBlock)
		{
			this->baseclass_0.mpCurBlock = 0;
			result = 0;
		}
		else
		{
			result = -2147467259;
		}
		return result;
	}

	//----- (008FD560) --------------------------------------------------------
	int Read(char* buf, int buflen)
	{
		int result; // eax@4

		if (this->mMode)
			_CriticalMsg("mMode == kTagOpenRead", "x:\\prj\\tech\\libsrc\\tagfile\\memtfile.cpp", 0xA6u);
		if (this->baseclass_0.mpCurBlock)
		{
			if (this->baseclass_0.mCursor + buflen > this->baseclass_0.mpCurBlock->block_size)
				buflen = this->baseclass_0.mpCurBlock->block_size - this->baseclass_0.mCursor;
			memcpy(buf, &this->baseclass_0.mpCurBlock->buf[this->baseclass_0.mCursor], buflen);
			this->baseclass_0.mCursor += buflen;
			result = buflen;
		}
		else
		{
			result = 0;
		}
		return result;
	}

	//----- (008FD5F1) --------------------------------------------------------
	int Write(const char* buf, int buflen)
	{
		int result; // eax@4

		if (this->mMode != 1)
			_CriticalMsg("mMode == kTagOpenWrite", "x:\\prj\\tech\\libsrc\\tagfile\\memtfile.cpp", 0xB3u);
		if (this->baseclass_0.mpCurBlock)
		{
			if (this->baseclass_0.mCursor + buflen > this->baseclass_0.mpCurBlock->buf_size)
			{
				while (this->baseclass_0.mCursor + buflen > this->baseclass_0.mpCurBlock->buf_size)
					this->baseclass_0.mpCurBlock->buf_size *= 2;
				this->baseclass_0.mpCurBlock->buf = (char *)ReallocSpew(
					this->baseclass_0.mpCurBlock->buf,
					this->baseclass_0.mpCurBlock->buf_size,
					"x:\\prj\\tech\\libsrc\\tagfile\\memtfile.cpp",
					186);
			}
			memcpy(&this->baseclass_0.mpCurBlock->buf[this->baseclass_0.mCursor], buf, buflen);
			this->baseclass_0.mCursor += buflen;
			if (this->baseclass_0.mCursor > this->baseclass_0.mpCurBlock->block_size)
				this->baseclass_0.mpCurBlock->block_size = this->baseclass_0.mCursor;
			result = buflen;
		}
		else
		{
			result = 0;
		}
		return result;
	}

	//----- (008FD6EC) --------------------------------------------------------
	int Move(char* buf, int buflen)
	{
		int result; // eax@2

		if (this->mMode == 1)
			result = ((int(__stdcall *)(_DWORD, _DWORD, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[4].Release)(
			this,
			buf,
			buflen);
		else
			result = ((int(__stdcall *)(_DWORD, _DWORD, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[4].AddRef)(
			this,
			buf,
			buflen);
		return result;
	}


};



class MyClass
{
public:

};



//----- (008FD726) --------------------------------------------------------
cTagFileFactory *__cdecl CreateMemoryTagFileFactory()
{
	cTagFileFactory *v0; // eax@2
	cTagFileFactory *v2; // [sp+0h] [bp-8h]@2
	void *this; // [sp+4h] [bp-4h]@1

	this = j__new(0x18u, "x:\\prj\\tech\\libsrc\\tagfile\\memtfile.cpp", 224);
	if (this)
	{
		cMemFileFactory::cMemFileFactory((cMemFileFactory *)this);
		v2 = v0;
	}
	else
	{
		v2 = 0;
	}
	return v2;
}



class cMemFileIter
{
public:
	//----- (008FD800) --------------------------------------------------------
	void __thiscall cMemFileIter::cMemFileIter(cMemFileIter *this, cMemTagTable *table)
	{
		cMemFileIter *v2; // ST00_4@1

		v2 = this;
		cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>(&this->baseclass_0);
		v2->mpTable = table;
		v2->mpEntry = 0;
		v2->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cMemFileIter::_vftable_;
	}
	// 9A96EC: using guessed type int (__stdcall *cMemFileIter___vftable_)(int this, int id, int ppI);

	//----- (008FD840) --------------------------------------------------------
	int __stdcall cMemFileIter::Start(cMemFileIter *this)
	{
		this->mpEntry = cHashSet<sMemTagEntry___char_const___cHashFunctions>::GetFirst(
			&this->mpTable->baseclass_0.baseclass_0,
			&this->mHandle);
		return 0;
	}

	//----- (008FD870) --------------------------------------------------------
	int __stdcall cMemFileIter::Done(cMemFileIter *this)
	{
		return this->mpEntry == 0;
	}

	//----- (008FD890) --------------------------------------------------------
	int __stdcall cMemFileIter::Next(cMemFileIter *this)
	{
		if (this->mpEntry)
			this->mpEntry = cHashSet<sMemTagEntry___char_const___cHashFunctions>::GetNext(
			&this->mpTable->baseclass_0.baseclass_0,
			&this->mHandle);
		return 0;
	}

	//----- (008FD8C0) --------------------------------------------------------
	_TagFileTag *__stdcall cMemFileIter::Tag(cMemFileIter *this)
	{
		_TagFileTag *v2; // [sp+0h] [bp-4h]@2

		if (this->mpEntry)
			v2 = (_TagFileTag *)this->mpEntry;
		else
			v2 = 0;
		return v2;
	}

	//----- (008FD8F0) --------------------------------------------------------
	void *__thiscall cMemFileIter::_scalar_deleting_destructor_(cMemFileIter *this, unsigned int __flags)
	{
		void *thisa; // [sp+0h] [bp-4h]@1

		thisa = this;
		cMemFileIter::_cMemFileIter(this);
		if (__flags & 1)
			operator delete(thisa);
		return thisa;
	}

	//----- (008FD920) --------------------------------------------------------
	void __thiscall cMemFileIter::_cMemFileIter(cMemFileIter *this)
	{
		this->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cMemFileIter::_vftable_;
		this->mpEntry = 0;
		cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::_cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>(&this->baseclass_0);
	}
	// 9A96EC: using guessed type int (__stdcall *cMemFileIter___vftable_)(int this, int id, int ppI);


private:

};




//----- (008FD790) --------------------------------------------------------
void *__thiscall cMemTagTable::_scalar_deleting_destructor_(cMemTagTable *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cMemTagTable::_cMemTagTable(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FD7C0) --------------------------------------------------------
void __thiscall cStrHashSet<sMemTagEntry__>::_cStrHashSet<sMemTagEntry__>(cStrHashSet<sMemTagEntry *> *this)
{
	cHashSet<sMemTagEntry___char_const___cHashFunctions>::_cHashSet<sMemTagEntry___char_const___cHashFunctions>(&this->baseclass_0);
}

//----- (008FD7E0) --------------------------------------------------------
void __thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::_cHashSet<sMemTagEntry___char_const___cHashFunctions>(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this)
{
	cHashSetBase::_cHashSetBase(&this->baseclass_0);
}


//----- (008FD950) --------------------------------------------------------
void __thiscall cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>(cCTUnaggregated<ITagFileIter, &IID_ITagFileIter, 0> *this)
{
	cCTUnaggregated<ITagFileIter, &IID_ITagFileIter, 0> *v1; // ST00_4@1

	v1 = this;
	ITagFileIter::ITagFileIter(&this->baseclass_0);
	cCTRefCount::cCTRefCount(&v1->__m_ulRefs);
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::_vftable_;
}
// 9A9710: using guessed type int (__stdcall *cCTUnaggregated_ITagFileIter___GUID const IID_ITagFileIter_0____vftable_)(int this, int id, int ppI);

//----- (008FD980) --------------------------------------------------------
void *__thiscall cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::_vector_deleting_destructor_(cCTUnaggregated<ITagFileIter, &IID_ITagFileIter, 0> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::_cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FD9B0) --------------------------------------------------------
void __thiscall cMemFileFactory::cMemFileFactory(cMemFileFactory *this)
{
	cMemFileFactory *v1; // ST00_4@1

	v1 = this;
	cTagFileFactory::cTagFileFactory(&this->baseclass_0);
	cMemTagTable::cMemTagTable(&v1->mTable);
	v1->baseclass_0.vfptr = (cTagFileFactoryVtbl *)&cMemFileFactory::_vftable_;
}
// 9A9734: using guessed type int (__stdcall *cMemFileFactory___vftable_)(int __flags);

//----- (008FD9E0) --------------------------------------------------------
ITagFile *__thiscall cMemFileFactory::Open(cMemFileFactory *this, const char *__formal, TagFileOpenMode mode)
{
	ITagFile *v3; // eax@2
	ITagFile *v5; // [sp+0h] [bp-Ch]@2
	cMemFileFactory *thisa; // [sp+4h] [bp-8h]@1
	void *v7; // [sp+8h] [bp-4h]@1

	thisa = this;
	v7 = j__new(0x18u, "x:\\prj\\tech\\libsrc\\tagfile\\memtfile.cpp", 217);
	if (v7)
	{
		cMemFileReadWrite::cMemFileReadWrite((cMemFileReadWrite *)v7, &thisa->mTable, mode);
		v5 = v3;
	}
	else
	{
		v5 = 0;
	}
	return v5;
}

//----- (008FDA30) --------------------------------------------------------
void __thiscall cMemFileReadWrite::cMemFileReadWrite(cMemFileReadWrite *this, cMemTagTable *table, TagFileOpenMode mode)
{
	cMemFileReadWrite *v3; // ST04_4@1

	v3 = this;
	cMemFile::cMemFile(&this->baseclass_0, table);
	v3->mMode = mode;
	v3->baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cMemFileReadWrite::_vftable_;
}
// 9A973C: using guessed type int (__stdcall *cMemFileReadWrite___vftable_)(int, int, int);

//----- (008FDA60) --------------------------------------------------------
void __thiscall cMemFile::cMemFile(cMemFile *this, cMemTagTable *table)
{
	cMemFile *v2; // ST00_4@1

	v2 = this;
	cCTUnaggregated<ITagFile___GUID_const_IID_ITagFile_0>::cCTUnaggregated<ITagFile___GUID_const_IID_ITagFile_0>(&this->baseclass_0);
	v2->mpTable = table;
	v2->mpCurBlock = 0;
	v2->mCursor = 0;
	v2->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cMemFile::_vftable_;
}
// 9A9784: using guessed type int (__stdcall *cMemFile___vftable_)(int, int, int);

//----- (008FDAA0) --------------------------------------------------------
VersionNum *__stdcall cMemFile::GetVersion(cMemFile *this)
{
	return (VersionNum *)cMemFile::Version;
}
// B47B38: using guessed type int cMemFile__Version[2];

//----- (008FDAB0) --------------------------------------------------------
void *__thiscall cMemFile::_vector_deleting_destructor_(cMemFile *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cMemFile::_cMemFile(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FDAE0) --------------------------------------------------------
void __thiscall cMemFile::_cMemFile(cMemFile *this)
{
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cMemFile::_vftable_;
	cCTUnaggregated<ITagFile___GUID_const_IID_ITagFile_0>::_cCTUnaggregated<ITagFile___GUID_const_IID_ITagFile_0>(&this->baseclass_0);
}
// 9A9784: using guessed type int (__stdcall *cMemFile___vftable_)(int, int, int);

//----- (008FDB00) --------------------------------------------------------
TagFileOpenMode __stdcall cMemFileReadWrite::OpenMode(cMemFileReadWrite *this)
{
	return this->mMode;
}

//----- (008FDB10) --------------------------------------------------------
void *__thiscall cMemFileReadWrite::_vector_deleting_destructor_(cMemFileReadWrite *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cMemFileReadWrite::_cMemFileReadWrite(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FDB40) --------------------------------------------------------
void __thiscall cMemFileReadWrite::_cMemFileReadWrite(cMemFileReadWrite *this)
{
	this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cMemFileReadWrite::_vftable_;
	cMemFile::_cMemFile(&this->baseclass_0);
}
// 9A973C: using guessed type int (__stdcall *cMemFileReadWrite___vftable_)(int, int, int);

//----- (008FDB60) --------------------------------------------------------
void *__thiscall cMemFileFactory::_scalar_deleting_destructor_(cMemFileFactory *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cMemFileFactory::_cMemFileFactory(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}


//----- (008FDB90) --------------------------------------------------------
void __thiscall cTagFileFactory::cTagFileFactory(cTagFileFactory *this)
{
	this->vfptr = (cTagFileFactoryVtbl *)&cTagFileFactory::_vftable_;
}
// 9A97CC: using guessed type int (__stdcall *cTagFileFactory___vftable_)(int __flags);

//----- (008FDBB0) --------------------------------------------------------
void *__thiscall cTagFileFactory::_vector_deleting_destructor_(cTagFileFactory *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cTagFileFactory::_cTagFileFactory(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FDBE0) --------------------------------------------------------
void __thiscall cTagFileFactory::_cTagFileFactory(cTagFileFactory *this)
{
	this->vfptr = (cTagFileFactoryVtbl *)&cTagFileFactory::_vftable_;
}
// 9A97CC: using guessed type int (__stdcall *cTagFileFactory___vftable_)(int __flags);

//----- (008FDC00) --------------------------------------------------------
void __thiscall cMemTagTable::cMemTagTable(cMemTagTable *this)
{
	cMemTagTable *v1; // ST04_4@1

	v1 = this;
	cStrHashSet<sMemTagEntry__>::cStrHashSet<sMemTagEntry__>(&this->baseclass_0, 0x65u);
	v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cMemTagTable::_vftable_;
}
// 9A96CC: using guessed type int (__stdcall *cMemTagTable___vftable_)(int __flags);

//----- (008FDC30) --------------------------------------------------------
void __thiscall cMemFileFactory::_cMemFileFactory(cMemFileFactory *this)
{
	cTagFileFactory *v1; // ST00_4@1

	v1 = (cTagFileFactory *)this;
	cMemTagTable::_cMemTagTable(&this->mTable);
	cTagFileFactory::_cTagFileFactory(v1);
}







//----- (008FDC50) --------------------------------------------------------
void __thiscall cStrHashSet<sMemTagEntry__>::cStrHashSet<sMemTagEntry__>(cStrHashSet<sMemTagEntry *> *this, unsigned int n)
{
	cStrHashSet<sMemTagEntry *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<sMemTagEntry___char_const___cHashFunctions>::cHashSet<sMemTagEntry___char_const___cHashFunctions>(
		&this->baseclass_0,
		n);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrHashSet<sMemTagEntry__>::_vftable_;
}
// 9A97D4: using guessed type int (__stdcall *cStrHashSet_sMemTagEntry _____vftable_)(int __flags);

//----- (008FDC80) --------------------------------------------------------
void __thiscall cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::_cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>(cCTUnaggregated<ITagFileIter, &IID_ITagFileIter, 0> *this)
{
	this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::_vftable_;
}
// 9A9710: using guessed type int (__stdcall *cCTUnaggregated_ITagFileIter___GUID const IID_ITagFileIter_0____vftable_)(int this, int id, int ppI);

//----- (008FDCA0) --------------------------------------------------------
void __thiscall cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::OnFinalRelease(cCTUnaggregated<ITagFileIter, &IID_ITagFileIter, 0> *this)
{
	;
}

//----- (008FDCB0) --------------------------------------------------------
int __stdcall cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::QueryInterface(cCTUnaggregated<ITagFileIter, &IID_ITagFileIter, 0> *this, _GUID *id, void **ppI)
{
	int result; // eax@5

	if (id != &IID_ITagFileIter
		&& id != &IID_IUnknown
		&& memcmp(id, &IID_ITagFileIter, 0x10u)
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

//----- (008FDD20) --------------------------------------------------------
unsigned int __stdcall cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::AddRef(cCTUnaggregated<ITagFileIter, &IID_ITagFileIter, 0> *this)
{
	return cCTRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008FDD40) --------------------------------------------------------
unsigned int __stdcall cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::Release(cCTUnaggregated<ITagFileIter, &IID_ITagFileIter, 0> *this)
{
	unsigned int result; // eax@2

	if (cCTRefCount::Release(&this->__m_ulRefs))
	{
		result = cCTRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		((void(__thiscall *)(_DWORD))this->baseclass_0.baseclass_0.vfptr[2].Release)(this);
		if (this)
			((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[2].AddRef)(this, 1);
		result = 0;
	}
	return result;
}

//----- (008FDDB0) --------------------------------------------------------
void *__thiscall cStrHashSet<sMemTagEntry__>::_vector_deleting_destructor_(cStrHashSet<sMemTagEntry *> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStrHashSet<sMemTagEntry__>::_cStrHashSet<sMemTagEntry__>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FDDE0) --------------------------------------------------------
void __thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::cHashSet<sMemTagEntry___char_const___cHashFunctions>(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this, unsigned int n)
{
	cHashSet<sMemTagEntry *, char const *, cHashFunctions> *v2; // ST14_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, n);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<sMemTagEntry___char_const___cHashFunctions>::_vftable_;
}
// 9A97F4: using guessed type int (__stdcall *cHashSet_sMemTagEntry __char const __cHashFunctions____vftable_)(int __flags);

//----- (008FDE50) --------------------------------------------------------
void *__thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::_vector_deleting_destructor_(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cHashSet<sMemTagEntry___char_const___cHashFunctions>::_cHashSet<sMemTagEntry___char_const___cHashFunctions>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FDE80) --------------------------------------------------------
sMemTagEntry *__thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::Insert(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this, sMemTagEntry *node)
{
	return (sMemTagEntry *)cHashSetBase::Insert(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008FDEA0) --------------------------------------------------------
sMemTagEntry *__thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::Search(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this, const char *key)
{
	return (sMemTagEntry *)cHashSetBase::Search(&this->baseclass_0, (tHashSetKey__ *)key);
}

//----- (008FDEC0) --------------------------------------------------------
void __thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::DestroyAll(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this)
{
	sHashSetChunk *v1; // ST14_4@6
	cHashSet<sMemTagEntry *, char const *, cHashFunctions> *thisa; // [sp+0h] [bp-18h]@1
	sHashSetChunk *p; // [sp+10h] [bp-8h]@4
	unsigned int i; // [sp+14h] [bp-4h]@2

	thisa = this;
	if (this->baseclass_0.m_nItems)
	{
		for (i = 0; i < thisa->baseclass_0.m_nPts; ++i)
		{
			for (p = thisa->baseclass_0.m_Table[i]; p; p = v1)
			{
				v1 = p->pNext;
				operator delete(p->node);
				sHashSetChunk::operator delete(p, 8u);
			}
			thisa->baseclass_0.m_Table[i] = 0;
		}
		thisa->baseclass_0.m_nItems = 0;
	}
}

//----- (008FDF70) --------------------------------------------------------
sMemTagEntry *__thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::GetFirst(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this, tHashSetHandle *Handle)
{
	return (sMemTagEntry *)cHashSetBase::GetFirst(&this->baseclass_0, Handle);
}

//----- (008FDF90) --------------------------------------------------------
sMemTagEntry *__thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::GetNext(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this, tHashSetHandle *Handle)
{
	return (sMemTagEntry *)cHashSetBase::GetNext(&this->baseclass_0, Handle);
}

//----- (008FDFB0) --------------------------------------------------------
int __thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::IsEqual(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this, tHashSetKey__ *k1, tHashSetKey__ *k2)
{
	return cHashFunctions::IsEqual((const char *)k1, (const char *)k2);
}

//----- (008FDFD0) --------------------------------------------------------
unsigned int __thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::Hash(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this, tHashSetKey__ *k)
{
	return cHashFunctions::Hash((const char *)k);
}

/*

//----- (008FD2A0) --------------------------------------------------------
void __thiscall cMemTagTable::_cMemTagTable(cMemTagTable *this)
{
	cHashSet<sMemTagEntry *, char const *, cHashFunctions> *thisa; // [sp+0h] [bp-18h]@1
	tHashSetHandle handle; // [sp+8h] [bp-10h]@1
	sMemTagEntry *e; // [sp+14h] [bp-4h]@1

	thisa = (cHashSet<sMemTagEntry *, char const *, cHashFunctions> *)this;
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cMemTagTable::_vftable_;
	for (e = cHashSet<sMemTagEntry___char_const___cHashFunctions>::GetFirst(&this->baseclass_0.baseclass_0, &handle);
		e;
		e = cHashSet<sMemTagEntry___char_const___cHashFunctions>::GetNext(thisa, &handle))
	{
		if (e->buf)
			FreeSpew(e->buf, "x:\\prj\\tech\\libsrc\\tagfile\\memtfile.cpp", 25);
		operator delete(e);
	}
	cStrHashSet<sMemTagEntry__>::_cStrHashSet<sMemTagEntry__>((cStrHashSet<sMemTagEntry *> *)thisa);
}
// 9A96CC: using guessed type int (__stdcall *cMemTagTable___vftable_)(int __flags);

//----- (008FD317) --------------------------------------------------------
sMemTagEntry *__thiscall cMemTagTable::AddTag(cMemTagTable *this, _TagFileTag *tag, VersionNum *version)
{
	cHashSet<sMemTagEntry *, char const *, cHashFunctions> *v3; // ST0C_4@1
	void *v4; // eax@1
	void *v5; // ST14_4@1
	unsigned int v6; // ecx@1

	v3 = (cHashSet<sMemTagEntry *, char const *, cHashFunctions> *)this;
	v4 = j__new(0x20u, "x:\\prj\\tech\\libsrc\\tagfile\\memtfile.cpp", 32);
	v5 = v4;
	*(_DWORD *)v4 = *(_DWORD *)&tag->label[0];
	*((_DWORD *)v4 + 1) = *(_DWORD *)&tag->label[4];
	*((_DWORD *)v4 + 2) = *(_DWORD *)&tag->label[8];
	v6 = version->minor;
	*((_DWORD *)v4 + 3) = version->major;
	*((_DWORD *)v4 + 4) = v6;
	*((_DWORD *)v4 + 6) = 1024;
	*((_DWORD *)v4 + 7) = MallocSpew(*((_DWORD *)v4 + 6), "x:\\prj\\tech\\libsrc\\tagfile\\memtfile.cpp", 36);
	*((_DWORD *)v5 + 5) = 0;
	cHashSet<sMemTagEntry___char_const___cHashFunctions>::Insert(v3, (sMemTagEntry *)v5);
	return (sMemTagEntry *)v5;
}

//----- (008FD3A6) --------------------------------------------------------
unsigned int __stdcall cMemFile::BlockSize(cMemFile *this, _TagFileTag *tag)
{
	unsigned int v3; // [sp+0h] [bp-8h]@2
	sMemTagEntry *e; // [sp+4h] [bp-4h]@1

	e = cHashSet<sMemTagEntry___char_const___cHashFunctions>::Search(&this->mpTable->baseclass_0.baseclass_0, tag->label);
	if (e)
		v3 = e->block_size;
	else
		v3 = 0;
	return v3;
}

//----- (008FD3DF) --------------------------------------------------------
_TagFileTag *__stdcall cMemFile::CurrentBlock(cMemFile *this)
{
	_TagFileTag *v2; // [sp+0h] [bp-4h]@2

	if (this->mpCurBlock)
		v2 = (_TagFileTag *)this->mpCurBlock;
	else
		v2 = 0;
	return v2;
}

//----- (008FD407) --------------------------------------------------------
int __stdcall cMemFile::Seek(cMemFile *this, unsigned int offset, TagFileSeekMode from)
{
	int result; // eax@2
	unsigned int origin; // [sp+0h] [bp-4h]@3

	if (this->mpCurBlock)
	{
		origin = 0;
		if (from == 1)
		{
			origin = this->mCursor;
		}
		else
		{
			if (from == 2)
				origin = this->mpCurBlock->block_size;
		}
		this->mCursor = offset + origin;
		result = 0;
	}
	else
	{
		result = -2147467259;
	}
	return result;
}

//----- (008FD459) --------------------------------------------------------
unsigned int __stdcall cMemFile::Tell(cMemFile *this)
{
	return this->mCursor;
}

//----- (008FD466) --------------------------------------------------------
unsigned int __stdcall cMemFile::TellFromEnd(cMemFile *this)
{
	return this->mpCurBlock->block_size - this->mCursor;
}

//----- (008FD47C) --------------------------------------------------------
ITagFileIter *__stdcall cMemFile::Iterate(cMemFile *this)
{
	ITagFileIter *v1; // eax@2
	ITagFileIter *v3; // [sp+0h] [bp-8h]@2
	void *v4; // [sp+4h] [bp-4h]@1

	v4 = j__new(0x1Cu, "x:\\prj\\tech\\libsrc\\tagfile\\memtfile.cpp", 126);
	if (v4)
	{
		cMemFileIter::cMemFileIter((cMemFileIter *)v4, this->mpTable);
		v3 = v1;
	}
	else
	{
		v3 = 0;
	}
	return v3;
}

//----- (008FD4C0) --------------------------------------------------------
int __stdcall cMemFileReadWrite::OpenBlock(cMemFileReadWrite *this, _TagFileTag *tag, VersionNum *version)
{
	unsigned int v4; // edx@7
	sMemTagEntry *e; // [sp+0h] [bp-4h]@1

	e = cHashSet<sMemTagEntry___char_const___cHashFunctions>::Search(
		&this->baseclass_0.mpTable->baseclass_0.baseclass_0,
		tag->label);
	if (this->mMode == 1)
	{
		if (e)
			return -2147467259;
		e = cMemTagTable::AddTag(this->baseclass_0.mpTable, tag, version);
	}
	else
	{
		if (!e)
			return -2147467259;
		v4 = e->version.minor;
		version->major = e->version.major;
		version->minor = v4;
	}
	this->baseclass_0.mpCurBlock = e;
	this->baseclass_0.mCursor = 0;
	return 0;
}

//----- (008FD53D) --------------------------------------------------------
int __stdcall cMemFileReadWrite::CloseBlock(cMemFileReadWrite *this)
{
	int result; // eax@2

	if (this->baseclass_0.mpCurBlock)
	{
		this->baseclass_0.mpCurBlock = 0;
		result = 0;
	}
	else
	{
		result = -2147467259;
	}
	return result;
}

//----- (008FD560) --------------------------------------------------------
int __stdcall cMemFileReadWrite::Read(cMemFileReadWrite *this, char *buf, int buflen)
{
	int result; // eax@4

	if (this->mMode)
		_CriticalMsg("mMode == kTagOpenRead", "x:\\prj\\tech\\libsrc\\tagfile\\memtfile.cpp", 0xA6u);
	if (this->baseclass_0.mpCurBlock)
	{
		if (this->baseclass_0.mCursor + buflen > this->baseclass_0.mpCurBlock->block_size)
			buflen = this->baseclass_0.mpCurBlock->block_size - this->baseclass_0.mCursor;
		memcpy(buf, &this->baseclass_0.mpCurBlock->buf[this->baseclass_0.mCursor], buflen);
		this->baseclass_0.mCursor += buflen;
		result = buflen;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008FD5F1) --------------------------------------------------------
int __stdcall cMemFileReadWrite::Write(cMemFileReadWrite *this, const char *buf, int buflen)
{
	int result; // eax@4

	if (this->mMode != 1)
		_CriticalMsg("mMode == kTagOpenWrite", "x:\\prj\\tech\\libsrc\\tagfile\\memtfile.cpp", 0xB3u);
	if (this->baseclass_0.mpCurBlock)
	{
		if (this->baseclass_0.mCursor + buflen > this->baseclass_0.mpCurBlock->buf_size)
		{
			while (this->baseclass_0.mCursor + buflen > this->baseclass_0.mpCurBlock->buf_size)
				this->baseclass_0.mpCurBlock->buf_size *= 2;
			this->baseclass_0.mpCurBlock->buf = (char *)ReallocSpew(
				this->baseclass_0.mpCurBlock->buf,
				this->baseclass_0.mpCurBlock->buf_size,
				"x:\\prj\\tech\\libsrc\\tagfile\\memtfile.cpp",
				186);
		}
		memcpy(&this->baseclass_0.mpCurBlock->buf[this->baseclass_0.mCursor], buf, buflen);
		this->baseclass_0.mCursor += buflen;
		if (this->baseclass_0.mCursor > this->baseclass_0.mpCurBlock->block_size)
			this->baseclass_0.mpCurBlock->block_size = this->baseclass_0.mCursor;
		result = buflen;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008FD6EC) --------------------------------------------------------
int __stdcall cMemFileReadWrite::Move(cMemFileReadWrite *this, char *buf, int buflen)
{
	int result; // eax@2

	if (this->mMode == 1)
		result = ((int(__stdcall *)(_DWORD, _DWORD, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[4].Release)(
		this,
		buf,
		buflen);
	else
		result = ((int(__stdcall *)(_DWORD, _DWORD, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr[4].AddRef)(
		this,
		buf,
		buflen);
	return result;
}

//----- (008FD726) --------------------------------------------------------
cTagFileFactory *__cdecl CreateMemoryTagFileFactory()
{
	cTagFileFactory *v0; // eax@2
	cTagFileFactory *v2; // [sp+0h] [bp-8h]@2
	void *this; // [sp+4h] [bp-4h]@1

	this = j__new(0x18u, "x:\\prj\\tech\\libsrc\\tagfile\\memtfile.cpp", 224);
	if (this)
	{
		cMemFileFactory::cMemFileFactory((cMemFileFactory *)this);
		v2 = v0;
	}
	else
	{
		v2 = 0;
	}
	return v2;
}

//----- (008FD770) --------------------------------------------------------
tHashSetKey__ *__thiscall cMemTagTable::GetKey(cMemTagTable *this, tHashSetNode__ *node)
{
	return (tHashSetKey__ *)node;
}

//----- (008FD790) --------------------------------------------------------
void *__thiscall cMemTagTable::_scalar_deleting_destructor_(cMemTagTable *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cMemTagTable::_cMemTagTable(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FD7C0) --------------------------------------------------------
void __thiscall cStrHashSet<sMemTagEntry__>::_cStrHashSet<sMemTagEntry__>(cStrHashSet<sMemTagEntry *> *this)
{
	cHashSet<sMemTagEntry___char_const___cHashFunctions>::_cHashSet<sMemTagEntry___char_const___cHashFunctions>(&this->baseclass_0);
}

//----- (008FD7E0) --------------------------------------------------------
void __thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::_cHashSet<sMemTagEntry___char_const___cHashFunctions>(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this)
{
	cHashSetBase::_cHashSetBase(&this->baseclass_0);
}

//----- (008FD800) --------------------------------------------------------
void __thiscall cMemFileIter::cMemFileIter(cMemFileIter *this, cMemTagTable *table)
{
	cMemFileIter *v2; // ST00_4@1

	v2 = this;
	cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>(&this->baseclass_0);
	v2->mpTable = table;
	v2->mpEntry = 0;
	v2->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cMemFileIter::_vftable_;
}
// 9A96EC: using guessed type int (__stdcall *cMemFileIter___vftable_)(int this, int id, int ppI);

//----- (008FD840) --------------------------------------------------------
int __stdcall cMemFileIter::Start(cMemFileIter *this)
{
	this->mpEntry = cHashSet<sMemTagEntry___char_const___cHashFunctions>::GetFirst(
		&this->mpTable->baseclass_0.baseclass_0,
		&this->mHandle);
	return 0;
}

//----- (008FD870) --------------------------------------------------------
int __stdcall cMemFileIter::Done(cMemFileIter *this)
{
	return this->mpEntry == 0;
}

//----- (008FD890) --------------------------------------------------------
int __stdcall cMemFileIter::Next(cMemFileIter *this)
{
	if (this->mpEntry)
		this->mpEntry = cHashSet<sMemTagEntry___char_const___cHashFunctions>::GetNext(
		&this->mpTable->baseclass_0.baseclass_0,
		&this->mHandle);
	return 0;
}

//----- (008FD8C0) --------------------------------------------------------
_TagFileTag *__stdcall cMemFileIter::Tag(cMemFileIter *this)
{
	_TagFileTag *v2; // [sp+0h] [bp-4h]@2

	if (this->mpEntry)
		v2 = (_TagFileTag *)this->mpEntry;
	else
		v2 = 0;
	return v2;
}

//----- (008FD8F0) --------------------------------------------------------
void *__thiscall cMemFileIter::_scalar_deleting_destructor_(cMemFileIter *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cMemFileIter::_cMemFileIter(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FD920) --------------------------------------------------------
void __thiscall cMemFileIter::_cMemFileIter(cMemFileIter *this)
{
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cMemFileIter::_vftable_;
	this->mpEntry = 0;
	cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::_cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>(&this->baseclass_0);
}
// 9A96EC: using guessed type int (__stdcall *cMemFileIter___vftable_)(int this, int id, int ppI);

//----- (008FD950) --------------------------------------------------------
void __thiscall cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>(cCTUnaggregated<ITagFileIter, &IID_ITagFileIter, 0> *this)
{
	cCTUnaggregated<ITagFileIter, &IID_ITagFileIter, 0> *v1; // ST00_4@1

	v1 = this;
	ITagFileIter::ITagFileIter(&this->baseclass_0);
	cCTRefCount::cCTRefCount(&v1->__m_ulRefs);
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::_vftable_;
}
// 9A9710: using guessed type int (__stdcall *cCTUnaggregated_ITagFileIter___GUID const IID_ITagFileIter_0____vftable_)(int this, int id, int ppI);

//----- (008FD980) --------------------------------------------------------
void *__thiscall cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::_vector_deleting_destructor_(cCTUnaggregated<ITagFileIter, &IID_ITagFileIter, 0> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::_cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FD9B0) --------------------------------------------------------
void __thiscall cMemFileFactory::cMemFileFactory(cMemFileFactory *this)
{
	cMemFileFactory *v1; // ST00_4@1

	v1 = this;
	cTagFileFactory::cTagFileFactory(&this->baseclass_0);
	cMemTagTable::cMemTagTable(&v1->mTable);
	v1->baseclass_0.vfptr = (cTagFileFactoryVtbl *)&cMemFileFactory::_vftable_;
}
// 9A9734: using guessed type int (__stdcall *cMemFileFactory___vftable_)(int __flags);

//----- (008FD9E0) --------------------------------------------------------
ITagFile *__thiscall cMemFileFactory::Open(cMemFileFactory *this, const char *__formal, TagFileOpenMode mode)
{
	ITagFile *v3; // eax@2
	ITagFile *v5; // [sp+0h] [bp-Ch]@2
	cMemFileFactory *thisa; // [sp+4h] [bp-8h]@1
	void *v7; // [sp+8h] [bp-4h]@1

	thisa = this;
	v7 = j__new(0x18u, "x:\\prj\\tech\\libsrc\\tagfile\\memtfile.cpp", 217);
	if (v7)
	{
		cMemFileReadWrite::cMemFileReadWrite((cMemFileReadWrite *)v7, &thisa->mTable, mode);
		v5 = v3;
	}
	else
	{
		v5 = 0;
	}
	return v5;
}

//----- (008FDA30) --------------------------------------------------------
void __thiscall cMemFileReadWrite::cMemFileReadWrite(cMemFileReadWrite *this, cMemTagTable *table, TagFileOpenMode mode)
{
	cMemFileReadWrite *v3; // ST04_4@1

	v3 = this;
	cMemFile::cMemFile(&this->baseclass_0, table);
	v3->mMode = mode;
	v3->baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cMemFileReadWrite::_vftable_;
}
// 9A973C: using guessed type int (__stdcall *cMemFileReadWrite___vftable_)(int, int, int);

//----- (008FDA60) --------------------------------------------------------
void __thiscall cMemFile::cMemFile(cMemFile *this, cMemTagTable *table)
{
	cMemFile *v2; // ST00_4@1

	v2 = this;
	cCTUnaggregated<ITagFile___GUID_const_IID_ITagFile_0>::cCTUnaggregated<ITagFile___GUID_const_IID_ITagFile_0>(&this->baseclass_0);
	v2->mpTable = table;
	v2->mpCurBlock = 0;
	v2->mCursor = 0;
	v2->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cMemFile::_vftable_;
}
// 9A9784: using guessed type int (__stdcall *cMemFile___vftable_)(int, int, int);

//----- (008FDAA0) --------------------------------------------------------
VersionNum *__stdcall cMemFile::GetVersion(cMemFile *this)
{
	return (VersionNum *)cMemFile::Version;
}
// B47B38: using guessed type int cMemFile__Version[2];

//----- (008FDAB0) --------------------------------------------------------
void *__thiscall cMemFile::_vector_deleting_destructor_(cMemFile *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cMemFile::_cMemFile(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FDAE0) --------------------------------------------------------
void __thiscall cMemFile::_cMemFile(cMemFile *this)
{
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cMemFile::_vftable_;
	cCTUnaggregated<ITagFile___GUID_const_IID_ITagFile_0>::_cCTUnaggregated<ITagFile___GUID_const_IID_ITagFile_0>(&this->baseclass_0);
}
// 9A9784: using guessed type int (__stdcall *cMemFile___vftable_)(int, int, int);

//----- (008FDB00) --------------------------------------------------------
TagFileOpenMode __stdcall cMemFileReadWrite::OpenMode(cMemFileReadWrite *this)
{
	return this->mMode;
}

//----- (008FDB10) --------------------------------------------------------
void *__thiscall cMemFileReadWrite::_vector_deleting_destructor_(cMemFileReadWrite *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cMemFileReadWrite::_cMemFileReadWrite(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FDB40) --------------------------------------------------------
void __thiscall cMemFileReadWrite::_cMemFileReadWrite(cMemFileReadWrite *this)
{
	this->baseclass_0.baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cMemFileReadWrite::_vftable_;
	cMemFile::_cMemFile(&this->baseclass_0);
}
// 9A973C: using guessed type int (__stdcall *cMemFileReadWrite___vftable_)(int, int, int);

//----- (008FDB60) --------------------------------------------------------
void *__thiscall cMemFileFactory::_scalar_deleting_destructor_(cMemFileFactory *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cMemFileFactory::_cMemFileFactory(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}


//----- (008FDB90) --------------------------------------------------------
void __thiscall cTagFileFactory::cTagFileFactory(cTagFileFactory *this)
{
	this->vfptr = (cTagFileFactoryVtbl *)&cTagFileFactory::_vftable_;
}
// 9A97CC: using guessed type int (__stdcall *cTagFileFactory___vftable_)(int __flags);

//----- (008FDBB0) --------------------------------------------------------
void *__thiscall cTagFileFactory::_vector_deleting_destructor_(cTagFileFactory *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cTagFileFactory::_cTagFileFactory(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FDBE0) --------------------------------------------------------
void __thiscall cTagFileFactory::_cTagFileFactory(cTagFileFactory *this)
{
	this->vfptr = (cTagFileFactoryVtbl *)&cTagFileFactory::_vftable_;
}
// 9A97CC: using guessed type int (__stdcall *cTagFileFactory___vftable_)(int __flags);

//----- (008FDC00) --------------------------------------------------------
void __thiscall cMemTagTable::cMemTagTable(cMemTagTable *this)
{
	cMemTagTable *v1; // ST04_4@1

	v1 = this;
	cStrHashSet<sMemTagEntry__>::cStrHashSet<sMemTagEntry__>(&this->baseclass_0, 0x65u);
	v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cMemTagTable::_vftable_;
}
// 9A96CC: using guessed type int (__stdcall *cMemTagTable___vftable_)(int __flags);

//----- (008FDC30) --------------------------------------------------------
void __thiscall cMemFileFactory::_cMemFileFactory(cMemFileFactory *this)
{
	cTagFileFactory *v1; // ST00_4@1

	v1 = (cTagFileFactory *)this;
	cMemTagTable::_cMemTagTable(&this->mTable);
	cTagFileFactory::_cTagFileFactory(v1);
}

//----- (008FDC50) --------------------------------------------------------
void __thiscall cStrHashSet<sMemTagEntry__>::cStrHashSet<sMemTagEntry__>(cStrHashSet<sMemTagEntry *> *this, unsigned int n)
{
	cStrHashSet<sMemTagEntry *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<sMemTagEntry___char_const___cHashFunctions>::cHashSet<sMemTagEntry___char_const___cHashFunctions>(
		&this->baseclass_0,
		n);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrHashSet<sMemTagEntry__>::_vftable_;
}
// 9A97D4: using guessed type int (__stdcall *cStrHashSet_sMemTagEntry _____vftable_)(int __flags);

//----- (008FDC80) --------------------------------------------------------
void __thiscall cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::_cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>(cCTUnaggregated<ITagFileIter, &IID_ITagFileIter, 0> *this)
{
	this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::_vftable_;
}
// 9A9710: using guessed type int (__stdcall *cCTUnaggregated_ITagFileIter___GUID const IID_ITagFileIter_0____vftable_)(int this, int id, int ppI);

//----- (008FDCA0) --------------------------------------------------------
void __thiscall cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::OnFinalRelease(cCTUnaggregated<ITagFileIter, &IID_ITagFileIter, 0> *this)
{
	;
}

//----- (008FDCB0) --------------------------------------------------------
int __stdcall cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::QueryInterface(cCTUnaggregated<ITagFileIter, &IID_ITagFileIter, 0> *this, _GUID *id, void **ppI)
{
	int result; // eax@5

	if (id != &IID_ITagFileIter
		&& id != &IID_IUnknown
		&& memcmp(id, &IID_ITagFileIter, 0x10u)
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

//----- (008FDD20) --------------------------------------------------------
unsigned int __stdcall cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::AddRef(cCTUnaggregated<ITagFileIter, &IID_ITagFileIter, 0> *this)
{
	return cCTRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008FDD40) --------------------------------------------------------
unsigned int __stdcall cCTUnaggregated<ITagFileIter___GUID_const_IID_ITagFileIter_0>::Release(cCTUnaggregated<ITagFileIter, &IID_ITagFileIter, 0> *this)
{
	unsigned int result; // eax@2

	if (cCTRefCount::Release(&this->__m_ulRefs))
	{
		result = cCTRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		((void(__thiscall *)(_DWORD))this->baseclass_0.baseclass_0.vfptr[2].Release)(this);
		if (this)
			((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[2].AddRef)(this, 1);
		result = 0;
	}
	return result;
}

//----- (008FDDB0) --------------------------------------------------------
void *__thiscall cStrHashSet<sMemTagEntry__>::_vector_deleting_destructor_(cStrHashSet<sMemTagEntry *> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStrHashSet<sMemTagEntry__>::_cStrHashSet<sMemTagEntry__>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FDDE0) --------------------------------------------------------
void __thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::cHashSet<sMemTagEntry___char_const___cHashFunctions>(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this, unsigned int n)
{
	cHashSet<sMemTagEntry *, char const *, cHashFunctions> *v2; // ST14_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, n);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<sMemTagEntry___char_const___cHashFunctions>::_vftable_;
}
// 9A97F4: using guessed type int (__stdcall *cHashSet_sMemTagEntry __char const __cHashFunctions____vftable_)(int __flags);

//----- (008FDE50) --------------------------------------------------------
void *__thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::_vector_deleting_destructor_(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cHashSet<sMemTagEntry___char_const___cHashFunctions>::_cHashSet<sMemTagEntry___char_const___cHashFunctions>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FDE80) --------------------------------------------------------
sMemTagEntry *__thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::Insert(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this, sMemTagEntry *node)
{
	return (sMemTagEntry *)cHashSetBase::Insert(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008FDEA0) --------------------------------------------------------
sMemTagEntry *__thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::Search(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this, const char *key)
{
	return (sMemTagEntry *)cHashSetBase::Search(&this->baseclass_0, (tHashSetKey__ *)key);
}

//----- (008FDEC0) --------------------------------------------------------
void __thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::DestroyAll(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this)
{
	sHashSetChunk *v1; // ST14_4@6
	cHashSet<sMemTagEntry *, char const *, cHashFunctions> *thisa; // [sp+0h] [bp-18h]@1
	sHashSetChunk *p; // [sp+10h] [bp-8h]@4
	unsigned int i; // [sp+14h] [bp-4h]@2

	thisa = this;
	if (this->baseclass_0.m_nItems)
	{
		for (i = 0; i < thisa->baseclass_0.m_nPts; ++i)
		{
			for (p = thisa->baseclass_0.m_Table[i]; p; p = v1)
			{
				v1 = p->pNext;
				operator delete(p->node);
				sHashSetChunk::operator delete(p, 8u);
			}
			thisa->baseclass_0.m_Table[i] = 0;
		}
		thisa->baseclass_0.m_nItems = 0;
	}
}

//----- (008FDF70) --------------------------------------------------------
sMemTagEntry *__thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::GetFirst(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this, tHashSetHandle *Handle)
{
	return (sMemTagEntry *)cHashSetBase::GetFirst(&this->baseclass_0, Handle);
}

//----- (008FDF90) --------------------------------------------------------
sMemTagEntry *__thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::GetNext(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this, tHashSetHandle *Handle)
{
	return (sMemTagEntry *)cHashSetBase::GetNext(&this->baseclass_0, Handle);
}

//----- (008FDFB0) --------------------------------------------------------
int __thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::IsEqual(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this, tHashSetKey__ *k1, tHashSetKey__ *k2)
{
	return cHashFunctions::IsEqual((const char *)k1, (const char *)k2);
}

//----- (008FDFD0) --------------------------------------------------------
unsigned int __thiscall cHashSet<sMemTagEntry___char_const___cHashFunctions>::Hash(cHashSet<sMemTagEntry *, char const *, cHashFunctions> *this, tHashSetKey__ *k)
{
	return cHashFunctions::Hash((const char *)k);
}

*/
