#include <Windows.h>
#include <lg.h>
#include <comtools.h>

#include "tagfile.h"
#include "vernum.h"
#include "tagfile_.h"

#include <malloc.h>
#include <types.h>

#ifndef NO_DB_MEM
// Must be last header
#include <memall.h>
#include <dbmem.h>
#endif




tHashSetKey TagFileTable::GetKey(tHashSetNode node) const
{
	return (tHashSetKey)node;
}


void TagFileTable::Write(FILE* file)
{
	TagTableEntry *e;
	unsigned int items;
	tHashSetHandle idx;

	items = cHashSetBase::GetCount();

	if (fwrite(&items, 4u, 1u, file) != 1)
		_CriticalMsg("fwrite(&(items),sizeof(items),1,file) == 1", "x:\\prj\\tech\\libsrc\\tagfile\\tagfile.cpp", 0x39u);

	for (e = cHashSet::GetFirst(idx); e; e = cHashSet::GetNext(idx))
	{
		if (fwrite(e, 0x14u, 1u, file) != 1)
			_CriticalMsg("fwrite(&(*e),sizeof(*e),1,file) == 1", "x:\\prj\\tech\\libsrc\\tagfile\\tagfile.cpp", 0x3Cu);
	}

}



void TagFileTable::Read(FILE* file)
{
	TagTableEntry *node;
	void *ptr;
	TagTableEntry e;
	unsigned int i;
	unsigned int items;

	if (fread(&items, 4u, 1u, file) != 1)
		_CriticalMsg("fread(&(items),sizeof(items),1,file) == 1", "x:\\prj\\tech\\libsrc\\tagfile\\tagfile.cpp", 0x54u);

	for (i = 0; i < items; ++i)
	{
		TagTableEntry::TagTableEntry(e);
		if (fread(&e, 0x14u, 1u, file) != 1)
			_CriticalMsg("fread(&(e),sizeof(e),1,file) == 1", "x:\\prj\\tech\\libsrc\\tagfile\\tagfile.cpp", 0x58u);

		ptr = malloc(0x14u);

		if (ptr)
		{
			memcpy(ptr, &e, 0x14u);
			node = (TagTableEntry *)ptr;
		}
		else
		{
			node = 0;
		}
		cHashSet::Insert(node);

	}

}



TagFileTable::~TagFileTable()
{
	tHashSetHandle handle;
	void *e;

	for (e = cHashSet::GetFirst(handle); e; e = cHashSet::GetNext(handle))
		operator delete(e);

	cHashSet::~cHashSet();
};


//TagFileBase













/*
//----- (008FBD27) --------------------------------------------------------
ulong TagFileBase::AddRef()
{
	return TagFileBase::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008FBD39) --------------------------------------------------------
ulong TagFileBase::Release()
{
	unsigned int result; // eax@2

	if (TagFileBase::cRefCount::Release(&this->__m_ulRefs))
	{
		result = TagFileBase::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		TagFileBase::OnFinalRelease();
		result = 0;
	}
	return result;
}





VersionNum* TagFileBase::GetVersion()
{
	return &MyVersion_2;
}

//----- (008FBDD5) --------------------------------------------------------
ulong TagFileBase::BlockSize(const TagFileTag* tag)
{
	unsigned int result; // eax@2
	TagTableEntry *e; // [sp+0h] [bp-4h]@1

	e = cHashSet<TagTableEntry____TagFileTag_const___TagHashFunctions>::Search(&this->table.baseclass_0, tag);
	if (e)
		result = e->size;
	else
		result = -1;
	return result;
}

//----- (008FBE02) --------------------------------------------------------
const TagFileTag* TagFileBase::CurrentBlock()
{
	_TagFileTag *result; // eax@2

	if (this->block)
		result = (_TagFileTag *)this->block;
	else
		result = 0;
	return result;
}

//----- (008FBE1C) --------------------------------------------------------
void TagFileBase::SetCurBlock(const TagFileTag* tag)
{
	if (tag)
		this->block = cHashSet<TagTableEntry____TagFileTag_const___TagHashFunctions>::Search(&this->table.baseclass_0, tag);
	else
		this->block = 0;
}

//----- (008FBE50) --------------------------------------------------------
int TagFileBase::PrepSeek(unsigned int *offset, TagFileSeekMode mode)
{
	int result; // eax@2
	TagFileBase *thisa; // [sp+8h] [bp-4h]@1

	thisa = this;
	if (this->block)
	{
		if (mode)
		{
			if (mode == 1)
			{
				*offset += ftell(this->file);
			}
			else
			{
				if (mode == 2)
					*offset += TagTableEntry::End(this->block);
			}
		}
		else
		{
			*offset += TagTableEntry::Start(this->block);
		}
		if (*offset >= TagTableEntry::Start(thisa->block))
		{
			if (*offset <= TagTableEntry::End(thisa->block))
				result = 0;
			else
				result = *offset - TagTableEntry::End(thisa->block);
		}
		else
		{
			result = thisa->block->offset - TagTableEntry::Start(thisa->block);
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008FBF2E) --------------------------------------------------------
HRESULT __stdcall TagFileBase::Seek(ulong offset, TagFileSeekMode mode)
{
	int result; // eax@2
	unsigned int v4; // eax@7
	int v5; // [sp+0h] [bp-8h]@9
	int check; // [sp+4h] [bp-4h]@3

	if (this->block)
	{
		check = TagFileBase::PrepSeek(this, &offset, mode);
		if (check >= 0 && (check <= 0 || this->baseclass_0.baseclass_0.vfptr[1].AddRef((IUnknown *)this)))
		{
			fseek(this->file, offset, 0);
			v4 = TagTableEntry::Start(this->block);
			this->blockptr = offset - v4;
			if (this->baseclass_0.baseclass_0.vfptr[1].AddRef((IUnknown *)this) == 1)
			{
				if (this->block->size <= this->blockptr)
					v5 = this->blockptr;
				else
					v5 = this->block->size;
				this->block->size = v5;
			}
			result = 0;
		}
		else
		{
			DbgReportWarning("Seeking outside of tag file block\n");
			result = -2147467259;
		}
	}
	else
	{
		DbgReportWarning("Seeking when no block is open\n");
		result = -2147467259;
	}
	return result;
}

//----- (008FC00F) --------------------------------------------------------
ulong __stdcall TagFileBase::Tell()
{
	unsigned int result; // eax@2

	if (this->block)
		result = this->blockptr;
	else
		result = 0;
	return result;
}

//----- (008FC029) --------------------------------------------------------
ulong __stdcall TagFileBase::TellFromEnd()
{
	unsigned int result; // eax@2

	if (this->block)
		result = this->block->size - this->blockptr;
	else
		result = 0;
	return result;
}

//----- (008FBCBA) --------------------------------------------------------
HRESULT TagFileBase::QueryInterface(REFIID id, void **ppI)
{
	int result;

	if (id != IID_ITagFile && id != IID_IUnknown && memcmp(&id, &IID_ITagFile, 0x10u) && memcmp(&id, &IID_IUnknown, 0x10u))
	{
		*ppI = 0;
		result = -2147467262;
	}
	else
	{
		*ppI = this;
		this->AddRef();
		result = 0;
	}
	return result;
}





















//----- (008FC0FA) --------------------------------------------------------
ITagFileIter* __stdcall TagFileBase::Iterate()
{
	ITagFileIter *v1; // eax@2
	ITagFileIter *v3; // [sp+0h] [bp-8h]@2
	void *v4; // [sp+4h] [bp-4h]@1

	v4 = j__new(0x1Cu, "x:\\prj\\tech\\libsrc\\tagfile\\tagfile.cpp", 260);
	if (v4)
	{
		cTagIter::cTagIter((cTagIter *)v4, &this->table);
		v3 = v1;
	}
	else
	{
		v3 = 0;
	}
	return v3;
}

//----- (008FC141) --------------------------------------------------------
TagFileOpenMode __stdcall TagFileWrite::OpenMode()
{
	return 1;
}

//----- (008FC14D) --------------------------------------------------------
__thiscall TagFileWrite::TagFileWrite(const char *filename)
{
	TagFileWrite *thisa; // [sp+0h] [bp-114h]@1
	TagFileHeader header; // [sp+4h] [bp-110h]@2

	thisa = this;
	TagFileBase::TagFileBase(&this->baseclass_0, filename, "wb");
	thisa->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&TagFileWrite::_vftable_;
	if (thisa->baseclass_0.file)
	{
		TagFileHeader::TagFileHeader(&header);
		if (fwrite(&header, 0x110u, 1u, thisa->baseclass_0.file) != 1)
			_CriticalMsg(
			"fwrite(&(header),sizeof(header),1,file) == 1",
			"x:\\prj\\tech\\libsrc\\tagfile\\tagfile.cpp",
			0x119u);
	}
	else
	{
		DbgReportWarning("TagFileWrite: opening %s for writing failed\n");
	}
}


__thiscall TagFileWrite::~TagFileWrite()
{
	TagFileWrite *thisa; // [sp+0h] [bp-114h]@1
	TagFileHeader header; // [sp+4h] [bp-110h]@2

	thisa = this;
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&TagFileWrite::_vftable_;
	if (this->baseclass_0.file)
	{
		TagFileHeader::TagFileHeader(&header);
		fseek(thisa->baseclass_0.file, 0, 2);
		header.table = ftell(thisa->baseclass_0.file);
		TagFileTable::Write(&thisa->baseclass_0.table, thisa->baseclass_0.file);
		fseek(thisa->baseclass_0.file, 0, 0);
		header.version.major = MyVersion_2.major;
		header.version.minor = MyVersion_2.minor;
		memcpy(header.deadbeef, "??x:\\prj\\tech\\libsrc\\tagfile\\tagfile.cpp", 4u);
		if (fwrite(&header, 0x110u, 1u, thisa->baseclass_0.file) != 1)
			_CriticalMsg(
			"fwrite(&(header),sizeof(header),1,file) == 1",
			"x:\\prj\\tech\\libsrc\\tagfile\\tagfile.cpp",
			0x135u);
	}
	TagFileBase::_TagFileBase(&thisa->baseclass_0);
}



HRESULT __stdcall TagFileWrite::OpenBlock(const TagFileTag *tag, VersionNum *version)
{
	int v3; // eax@2
	const char *v4; // eax@6
	unsigned int v5; // edx@7
	__int32 v6; // eax@8
	TagTableEntry *v7; // eax@8
	TagTableEntry *v8; // [sp+0h] [bp-2Ch]@8
	void *v9; // [sp+4h] [bp-28h]@7
	TagFileBlockHeader header; // [sp+10h] [bp-1Ch]@7
	TagTableEntry *result; // [sp+28h] [bp-4h]@10

	if (this->baseclass_0.file)
	{
		if (this->baseclass_0.block)
		{
			DbgReportWarning("Opening Tag Block with a block already open\n");
			v3 = -2147467259;
		}
		else
		{
			if (cHashSet<TagTableEntry____TagFileTag_const___TagHashFunctions>::Search(
				&this->baseclass_0.table.baseclass_0,
				tag))
			{
				v4 = _LogFmt("TagFileWrite::NewBlock(): tag %s is already in use");
				_CriticalMsg(v4, "x:\\prj\\tech\\libsrc\\tagfile\\tagfile.cpp", 0x148u);
			}
			TagFileBlockHeader::TagFileBlockHeader(&header);
			*(_DWORD *)&header.tag.label[0] = *(_DWORD *)&tag->label[0];
			*(_DWORD *)&header.tag.label[4] = *(_DWORD *)&tag->label[4];
			*(_DWORD *)&header.tag.label[8] = *(_DWORD *)&tag->label[8];
			v5 = version->minor;
			header.version.major = version->major;
			header.version.minor = v5;
			fseek(this->baseclass_0.file, 0, 2);
			v9 = j__new(0x14u, "x:\\prj\\tech\\libsrc\\tagfile\\tagfile.cpp", 339);
			if (v9)
			{
				v6 = ftell(this->baseclass_0.file);
				TagTableEntry::TagTableEntry((TagTableEntry *)v9, tag, v6, 0);
				v8 = v7;
			}
			else
			{
				v8 = 0;
			}
			result = cHashSet<TagTableEntry____TagFileTag_const___TagHashFunctions>::Insert(
				&this->baseclass_0.table.baseclass_0,
				v8);
			if (result)
			{
				TagFileBase::SetCurBlock(&this->baseclass_0, tag);
				if (fwrite(&header, 1u, 0x18u, this->baseclass_0.file) == 24)
				{
					this->baseclass_0.blockptr = 0;
					v3 = 0;
				}
				else
				{
					DbgReportWarning("TagFileWrite::NewBlock(): wrote only %d out of %d bytes\n");
					v3 = -2147467259;
				}
			}
			else
			{
				v3 = -2147467259;
			}
		}
	}
	else
	{
		v3 = -2147467259;
	}
	return v3;
}

//----- (008FC476) --------------------------------------------------------
HRESULT __stdcall TagFileWrite::CloseBlock()
{
	int result; // eax@2

	if (this->baseclass_0.block)
	{
		TagFileBase::SetCurBlock(&this->baseclass_0, 0);
		result = 0;
	}
	else
	{
		DbgReportWarning("TagFileWrite::CloseBlock() No Block to Close\n");
		result = -2147467259;
	}
	return result;
}

//----- (008FC4A6) --------------------------------------------------------
HRESULT __stdcall TagFileWrite::Read(char *__formal, int a3)
{
	DbgReportWarning("Reading a TagFile opened for writing\n");
	return -1;
}

//----- (008FC4BD) --------------------------------------------------------
HRESULT __stdcall TagFileWrite::Write(const char *buf, int buflen)
{
	int result; // eax@4
	int v4; // [sp+0h] [bp-8h]@8
	int len; // [sp+4h] [bp-4h]@7

	if (!this->baseclass_0.block)
		_CriticalMsg(
		"TagFileWrite::Write(): No block has been started\n",
		"x:\\prj\\tech\\libsrc\\tagfile\\tagfile.cpp",
		0x184u);
	if (this->baseclass_0.block)
	{
		if (this->baseclass_0.file)
		{
			len = fwrite(buf, 1u, buflen, this->baseclass_0.file);
			this->baseclass_0.blockptr += len;
			if (this->baseclass_0.blockptr <= this->baseclass_0.block->size)
				v4 = this->baseclass_0.block->size;
			else
				v4 = this->baseclass_0.blockptr;
			this->baseclass_0.block->size = v4;
			result = len;
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
	return result;
}

//----- (008FC56C) --------------------------------------------------------
HRESULT __stdcall TagFileWrite::Move(char *buf, int len)
{
	return ((int(__stdcall *)(_DWORD, _DWORD, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.vfptr[4].Release)(
		this,
		buf,
		len);
}

//----- (008FC587) --------------------------------------------------------
TagFileOpenMode __stdcall TagFileRead::OpenMode()
{
	return 0;
}

//----- (008FC590) --------------------------------------------------------
__thiscall TagFileRead::TagFileRead(const char *filename)
{
	const char *v2; // eax@11
	TagFileRead *thisa; // [sp+0h] [bp-218h]@1
	char buf[256]; // [sp+4h] [bp-214h]@11
	int delta; // [sp+104h] [bp-114h]@10
	TagFileHeader header; // [sp+108h] [bp-110h]@6

	thisa = this;
	TagFileBase::TagFileBase(&this->baseclass_0, filename, "rb");
	thisa->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&TagFileRead::_vftable_;
	if (thisa->baseclass_0.file)
	{
		TagFileHeader::TagFileHeader(&header);
		if (fread(&header, 0x110u, 1u, thisa->baseclass_0.file) != 1)
			_CriticalMsg("fread(&(header),sizeof(header),1,file) == 1", "x:\\prj\\tech\\libsrc\\tagfile\\tagfile.cpp", 0x1AEu);
		if (memcmp(header.deadbeef, "??x:\\prj\\tech\\libsrc\\tagfile\\tagfile.cpp", 4u))
		{
			DbgReportWarning("Tag file %s is corrupt!\n");
			fclose(thisa->baseclass_0.file);
			thisa->baseclass_0.file = 0;
		}
		else
		{
			delta = VersionNumsCompare(&MyVersion_2, &header.version);
			if (delta
				&& (v2 = VersionNum2String(&MyVersion_2),
				strcpy(buf, v2),
				VersionNum2String(&header.version),
				DbgReportWarning("Tag file %s is not current version.\nOld: %s, New: %s\n"),
				delta < 0))
			{
				DbgReportWarning("Version in file is new.  Discarding tag\n");
				fclose(thisa->baseclass_0.file);
				thisa->baseclass_0.file = 0;
			}
			else
			{
				fseek(thisa->baseclass_0.file, header.table, 0);
				TagFileTable::Read(&thisa->baseclass_0.table, thisa->baseclass_0.file);
			}
		}
	}
	else
	{
		if (config_spew_on)
		{
			if (CfgSpewTest("TagFileTrace"))
				CfgDoSpew("TagFileRead: opening %s for reading failed\n");
		}
	}
}


__thiscall TagFileRead::~TagFileRead()
{
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&TagFileRead::_vftable_;
	TagFileBase::_TagFileBase(&this->baseclass_0);
}


HRESULT __stdcall TagFileRead::OpenBlock(const TagFileTag *tag, VersionNum *version)
{
	int result; // eax@2
	const char *v4; // eax@11
	char buf[256]; // [sp+0h] [bp-120h]@11
	size_t len; // [sp+100h] [bp-20h]@8
	int delta; // [sp+104h] [bp-1Ch]@10
	TagFileBlockHeader header; // [sp+108h] [bp-18h]@8

	if (this->baseclass_0.file)
	{
		TagFileBase::SetCurBlock(&this->baseclass_0, tag);
		if (this->baseclass_0.block)
		{
			fseek(this->baseclass_0.file, this->baseclass_0.block->offset, 0);
			TagFileBlockHeader::TagFileBlockHeader(&header);
			len = fread(&header, 1u, 0x18u, this->baseclass_0.file);
			if (len == 24)
			{
				delta = VersionNumsCompare(version, &header.version);
				if (!delta)
					goto LABEL_22;
				v4 = VersionNum2String(version);
				strcpy(buf, v4);
				if (config_spew_on && CfgSpewTest("tagfile_spew"))
				{
					VersionNum2String(&header.version);
					CfgDoSpew("Tag data %s is not current version.\nOld: %s, New: %s\n");
				}
				if (delta < 0)
				{
					if (config_spew_on && CfgSpewTest("tagfile_spew"))
						CfgDoSpew("Version in file is newer.  Discarding tag\n");
					TagFileBase::SetCurBlock(&this->baseclass_0, 0);
					result = -2147467259;
				}
				else
				{
				LABEL_22:
					version->major = header.version.major;
					version->minor = header.version.minor;
					this->baseclass_0.blockptr = 0;
					result = 0;
				}
			}
			else
			{
				DbgReportWarning("TagFileRead::OpenBlock(): read only %d of %d bytes\n");
				TagFileBase::SetCurBlock(&this->baseclass_0, 0);
				result = -2147467259;
			}
		}
		else
		{
			if (config_spew_on)
			{
				if (CfgSpewTest("tagfile_spew"))
					CfgDoSpew("Tag %s not in tag file\n");
			}
			result = -2147467259;
		}
	}
	else
	{
		result = -2147467259;
	}
	return result;
}



HRESULT __stdcall TagFileRead::CloseBlock()
{
	int result; // eax@2

	if (this->baseclass_0.block)
	{
		TagFileBase::SetCurBlock(&this->baseclass_0, 0);
		result = 0;
	}
	else
	{
		DbgReportWarning("TagFileRead::CloseBlock() No Block to Close\n");
		result = -2147467259;
	}
	return result;
}

//----- (008FC998) --------------------------------------------------------
HRESULT __stdcall TagFileRead::Read(char *buf, int buflen)
{
	int result; // eax@2
	unsigned int bytesleft; // [sp+0h] [bp-8h]@5

	if (this->baseclass_0.file)
	{
		if (this->baseclass_0.block)
		{
			bytesleft = this->baseclass_0.block->size - this->baseclass_0.blockptr;
			if (buflen > bytesleft)
				buflen = bytesleft > 0 ? bytesleft : 0;
			result = fread(buf, 1u, buflen, this->baseclass_0.file);
			this->baseclass_0.blockptr += result;
		}
		else
		{
			DbgReportWarning("TagFileRead::Read() called before ::Seek()\n");
			result = -1;
		}
	}
	else
	{
		result = -1;
	}
	return result;
}

//----- (008FCA22) --------------------------------------------------------
HRESULT __stdcall TagFileRead::Write(const char *__formal, int a3)
{
	DbgReportWarning("Writing to a tagfile opened for reading\n");
	return -1;
}

//----- (008FCA39) --------------------------------------------------------
HRESULT __stdcall TagFileRead::Move(char *buf, int buflen)
{
	return ((int(__stdcall *)(_DWORD, _DWORD, _DWORD))this->baseclass_0.baseclass_0.baseclass_0.vfptr[4].AddRef)(
		this,
		buf,
		buflen);
}

//----- (008FCA54) --------------------------------------------------------
ITagFile *__cdecl TagFileBase::Open(const char *filename, TagFileOpenMode mode)
{
	ITagFile *v2; // eax@5
	ITagFile *v3; // eax@9
	ITagFile *v5; // [sp+4h] [bp-20h]@9
	ITagFile *v6; // [sp+8h] [bp-1Ch]@5
	void *v7; // [sp+18h] [bp-Ch]@8
	void *this; // [sp+1Ch] [bp-8h]@4
	ITagFile *result; // [sp+20h] [bp-4h]@7

	if (mode)
	{
		if (mode != 1)
			return 0;
		v7 = j__new(0x28u, "x:\\prj\\tech\\libsrc\\tagfile\\tagfile.cpp", 591);
		if (v7)
		{
			TagFileWrite::TagFileWrite((TagFileWrite *)v7, filename);
			v5 = v3;
		}
		else
		{
			v5 = 0;
		}
		result = v5;
	}
	else
	{
		this = j__new(0x28u, "x:\\prj\\tech\\libsrc\\tagfile\\tagfile.cpp", 588);
		if (this)
		{
			TagFileRead::TagFileRead((TagFileRead *)this, filename);
			v6 = v2;
		}
		else
		{
			v6 = 0;
		}
		result = v6;
	}
	if (!result[6].baseclass_0.vfptr)
	{
		if (result)
			((void(__thiscall *)(_DWORD, _DWORD))result->baseclass_0.vfptr[5].AddRef)(result, 1);
		result = 0;
	}
	return result;
}


ITagFile *__cdecl TagFileOpen(const char *filename, TagFileOpenMode mode)
{
	return TagFileBase::Open(filename, mode);
}
















//----- (008FCB50) --------------------------------------------------------
void *__thiscall TagFileTable::_vector_deleting_destructor_(TagFileTable *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	TagFileTable::_TagFileTable(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FCB80) --------------------------------------------------------
void __thiscall cHashSet<TagTableEntry____TagFileTag_const___TagHashFunctions>::_cHashSet<TagTableEntry____TagFileTag_const___TagHashFunctions>(cHashSet<TagTableEntry *, _TagFileTag const *, TagHashFunctions> *this)
{
	cHashSetBase::_cHashSetBase(&this->baseclass_0);
}

//----- (008FCBA0) --------------------------------------------------------
void __thiscall TagTableEntry::TagTableEntry(TagTableEntry *this)
{
	this->offset = -1;
	this->size = -1;
	this->key.label[0] = 0;
}



//----- (008FCC20) --------------------------------------------------------
void __thiscall TagFileBase::OnFinalRelease(TagFileBase *this)
{
	if (this)
		((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[5].AddRef)(this, 1);
}

//----- (008FCC60) --------------------------------------------------------
void *__thiscall TagFileBase::_vector_deleting_destructor_(TagFileBase *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	TagFileBase::_TagFileBase(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FCC90) --------------------------------------------------------
unsigned int __thiscall TagTableEntry::Start(TagTableEntry *this)
{
	return this->offset + 24;
}

//----- (008FCCB0) --------------------------------------------------------
unsigned int __thiscall TagTableEntry::End(TagTableEntry *this)
{
	return this->size + TagTableEntry::Start(this);
}



//----- (008FC04E) --------------------------------------------------------
int __stdcall cTagIter::QueryInterface(cTagIter *this, _GUID *id, void **ppI)
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

//----- (008FC0BB) --------------------------------------------------------
unsigned int __stdcall cTagIter::AddRef(cTagIter *this)
{
	return cTagIter::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008FC0CD) --------------------------------------------------------
unsigned int __stdcall cTagIter::Release(cTagIter *this)
{
	unsigned int result; // eax@2

	if (cTagIter::cRefCount::Release(&this->__m_ulRefs))
	{
		result = cTagIter::cRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		cTagIter::OnFinalRelease(this);
		result = 0;
	}
	return result;
}


*/