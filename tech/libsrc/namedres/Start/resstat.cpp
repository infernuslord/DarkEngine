//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>



//----- (008E3B50) --------------------------------------------------------
void __thiscall cNamedStatsData::cNamedStatsData(cNamedStatsData *this, const char *pName)
{
	size_t v2; // eax@2
	cNamedStatsData *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (pName)
	{
		v2 = strlen(pName);
		thisa->m_pObjName = (char *)MallocSpew(v2 + 1, "x:\\prj\\tech\\libsrc\\namedres\\resstat.cpp", 25);
		strcpy(thisa->m_pObjName, pName);
	}
	else
	{
		this->m_pObjName = 0;
	}
	memset(thisa->m_Stats, 0, 0x30u);
}

//----- (008E3BBA) --------------------------------------------------------
void __thiscall cNamedStatsData::_cNamedStatsData(cNamedStatsData *this)
{
	cNamedStatsData *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (this->m_pObjName)
	{
		FreeSpew(this->m_pObjName, "x:\\prj\\tech\\libsrc\\namedres\\resstat.cpp", 39);
		thisa->m_pObjName = 0;
	}
}

//----- (008E3BEB) --------------------------------------------------------
void __thiscall cNamedStatsHash::cNamedStatsHash(cNamedStatsHash *this)
{
	cNamedStatsHash *v1; // ST04_4@1

	v1 = this;
	cStrIHashSet<cNamedStatsData__>::cStrIHashSet<cNamedStatsData__>(&this->baseclass_0, 0x1F4u);
	v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cNamedStatsHash::_vftable_;
}
// 9A8290: using guessed type int (__stdcall *cNamedStatsHash___vftable_)(int __flags);

//----- (008E3C0F) --------------------------------------------------------
void __thiscall cNamedStatsHash::_cNamedStatsHash(cNamedStatsHash *this)
{
	cStrIHashSet<cNamedStatsData *> *v1; // ST00_4@1

	v1 = (cStrIHashSet<cNamedStatsData *> *)this;
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cNamedStatsHash::_vftable_;
	cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::DestroyAll(&this->baseclass_0.baseclass_0);
	cStrIHashSet<cNamedStatsData__>::_cStrIHashSet<cNamedStatsData__>(v1);
}
// 9A8290: using guessed type int (__stdcall *cNamedStatsHash___vftable_)(int __flags);

//----- (008E3C33) --------------------------------------------------------
tHashSetKey__ *__thiscall cNamedStatsHash::GetKey(cNamedStatsHash *this, tHashSetNode__ *node)
{
	return (tHashSetKey__ *)node->unused;
}

//----- (008E3C45) --------------------------------------------------------
void __thiscall cResStats::cResStats(cResStats *this)
{
	cResStats *thisa; // [sp+0h] [bp-8h]@1
	signed int i; // [sp+4h] [bp-4h]@1

	thisa = this;
	this->m_pResStats = 0;
	this->m_pTypeStats = 0;
	this->m_pPathStats = 0;
	memset(this->m_Stats, 0, 0x30u);
	for (i = 0; i < 6; ++i)
		thisa->m_StatMode[i] = 0;
}

//----- (008E3CAD) --------------------------------------------------------
void __thiscall cResStats::_cResStats(cResStats *this)
{
	cResStats *thisa; // [sp+Ch] [bp-1Ch]@1
	cNamedStatsHash *v2; // [sp+14h] [bp-14h]@10
	cNamedStatsHash *v3; // [sp+1Ch] [bp-Ch]@6

	thisa = this;
	if (this->m_pResStats)
	{
		if (this->m_pResStats)
			this->m_pResStats->baseclass_0.baseclass_0.baseclass_0.vfptr->__vecDelDtor((cHashSetBase *)this->m_pResStats, 1u);
		thisa->m_pResStats = 0;
	}
	if (thisa->m_pTypeStats)
	{
		v3 = thisa->m_pTypeStats;
		if (v3)
			v3->baseclass_0.baseclass_0.baseclass_0.vfptr->__vecDelDtor((cHashSetBase *)v3, 1u);
		thisa->m_pTypeStats = 0;
	}
	if (thisa->m_pPathStats)
	{
		v2 = thisa->m_pPathStats;
		if (v2)
			v2->baseclass_0.baseclass_0.baseclass_0.vfptr->__vecDelDtor((cHashSetBase *)v2, 1u);
		thisa->m_pPathStats = 0;
	}
}

//----- (008E3D77) --------------------------------------------------------
void __thiscall cResStats::SetMode(cResStats *this, eResStatMode ResStatMode, int bTurnOn)
{
	cNamedStatsHash *v3; // eax@12
	cNamedStatsHash *v4; // eax@18
	cNamedStatsHash *v5; // eax@25
	cNamedStatsHash *v6; // [sp+0h] [bp-20h]@25
	cNamedStatsHash *v7; // [sp+4h] [bp-1Ch]@18
	cNamedStatsHash *v8; // [sp+8h] [bp-18h]@12
	cResStats *thisa; // [sp+Ch] [bp-14h]@1
	void *v10; // [sp+10h] [bp-10h]@24
	void *v11; // [sp+14h] [bp-Ch]@17
	void *v12; // [sp+18h] [bp-8h]@11
	signed int i; // [sp+1Ch] [bp-4h]@4

	thisa = this;
	if ((signed int)ResStatMode >= 6)
		_CriticalMsg("Unknown Stat Mode!", "x:\\prj\\tech\\libsrc\\namedres\\resstat.cpp", 0x61u);
	if (ResStatMode)
	{
		thisa->m_StatMode[ResStatMode] = bTurnOn;
	}
	else
	{
		for (i = 0; i < 6; ++i)
			thisa->m_StatMode[i] = bTurnOn;
	}
	if (thisa->m_StatMode[2] && !thisa->m_pTypeStats)
	{
		v12 = j__new(0x14u, "x:\\prj\\tech\\libsrc\\namedres\\resstat.cpp", 112);
		if (v12)
		{
			cNamedStatsHash::cNamedStatsHash((cNamedStatsHash *)v12);
			v8 = v3;
		}
		else
		{
			v8 = 0;
		}
		thisa->m_pTypeStats = v8;
	}
	if (thisa->m_StatMode[3] && !thisa->m_pPathStats)
	{
		v11 = j__new(0x14u, "x:\\prj\\tech\\libsrc\\namedres\\resstat.cpp", 115);
		if (v11)
		{
			cNamedStatsHash::cNamedStatsHash((cNamedStatsHash *)v11);
			v7 = v4;
		}
		else
		{
			v7 = 0;
		}
		thisa->m_pPathStats = v7;
	}
	if ((thisa->m_StatMode[4] || thisa->m_StatMode[5]) && !thisa->m_pResStats)
	{
		v10 = j__new(0x14u, "x:\\prj\\tech\\libsrc\\namedres\\resstat.cpp", 120);
		if (v10)
		{
			cNamedStatsHash::cNamedStatsHash((cNamedStatsHash *)v10);
			v6 = v5;
		}
		else
		{
			v6 = 0;
		}
		thisa->m_pResStats = v6;
	}
}

//----- (008E3EC3) --------------------------------------------------------
void __thiscall cResStats::DumpItem(cResStats *this, _iobuf *fp, unsigned int *m_Stats)
{
	signed int i; // [sp+4h] [bp-4h]@1

	for (i = 0; i < 12; ++i)
	{
		if (fp)
			fprintf(fp, "    %s: %d\n", pStatNames[i], m_Stats[i]);
		else
			mprintf("    %s: %d\n");
	}
}

//----- (008E3F3C) --------------------------------------------------------
void __thiscall cResStats::DumpTable(cResStats *this, _iobuf *fp, cNamedStatsHash *pTable)
{
	cResStats *thisa; // [sp+0h] [bp-14h]@1
	tHashSetHandle hs; // [sp+4h] [bp-10h]@2
	unsigned int *pNode; // [sp+10h] [bp-4h]@2

	thisa = this;
	if (pTable)
	{
		for (pNode = (unsigned int *)cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::GetFirst(
			&pTable->baseclass_0.baseclass_0,
			&hs);
		pNode;
		pNode = (unsigned int *)cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::GetNext(
			&pTable->baseclass_0.baseclass_0,
			&hs))
		{
			if (fp)
				fprintf(fp, "  %s:\n", *pNode);
			else
				mprintf("  %s:\n");
			cResStats::DumpItem(thisa, fp, pNode + 1);
		}
	}
}

//----- (008E3FBE) --------------------------------------------------------
void __thiscall cResStats::Dump(cResStats *this, const char *pFile)
{
	cResStats *thisa; // [sp+0h] [bp-8h]@1
	FILE *fp; // [sp+4h] [bp-4h]@1

	thisa = this;
	fp = 0;
	if (pFile)
		fp = fopen(pFile, "a+");
	if (thisa->m_StatMode[1])
	{
		if (fp)
			fprintf(fp, "\nResource Manager Stats:\n");
		else
			mprintf("\nResource Manager Stats:\n");
		cResStats::DumpItem(thisa, fp, thisa->m_Stats);
	}
	if (thisa->m_StatMode[2])
	{
		if (fp)
			fprintf(fp, "\nStats Broken down by Type:\n");
		else
			mprintf("\nStats Broken down by Type:\n");
		cResStats::DumpTable(thisa, fp, thisa->m_pTypeStats);
	}
	if (thisa->m_StatMode[3])
	{
		if (fp)
			fprintf(fp, "\nStats Broken down by Canonical Path:\n");
		else
			mprintf("\nStats Broken down by Canonical Path:\n");
		cResStats::DumpTable(thisa, fp, thisa->m_pPathStats);
	}
	if (thisa->m_StatMode[4])
	{
		if (fp)
			fprintf(fp, "\nStats Broken down by Resource:\n");
		else
			mprintf("\nStats Broken down by Resource:\n");
		cResStats::DumpTable(thisa, fp, thisa->m_pResStats);
	}
	if (fp)
		fclose(fp);
}

//----- (008E4107) --------------------------------------------------------
void __thiscall cResStats::LogStat(cResStats *this, IRes *pRes, unsigned int *m_Stats, eResourceStats StatType)
{
	unsigned int v4; // eax@2
	unsigned int v5; // eax@6

	if (StatType == 8)
	{
		v4 = pRes->baseclass_0.baseclass_0.vfptr[5].AddRef((IUnknown *)pRes);
		m_Stats[8] += v4;
		m_Stats[10] += v4;
		if (m_Stats[10] > m_Stats[11])
			m_Stats[11] = m_Stats[10];
	}
	else
	{
		if (StatType == 9)
		{
			v5 = pRes->baseclass_0.baseclass_0.vfptr[5].AddRef((IUnknown *)pRes);
			m_Stats[9] += v5;
			m_Stats[10] -= v5;
		}
		else
		{
			++m_Stats[StatType];
		}
	}
}

//----- (008E41AF) --------------------------------------------------------
void __thiscall cResStats::LogStatTable(cResStats *this, IRes *pRes, cNamedStatsHash *pTable, const char *pName, eResourceStats StatType)
{
	cNamedStatsData *v5; // eax@6
	cNamedStatsData *v6; // [sp+0h] [bp-10h]@6
	cResStats *thisa; // [sp+4h] [bp-Ch]@1
	void *v8; // [sp+8h] [bp-8h]@5
	cNamedStatsData *pData; // [sp+Ch] [bp-4h]@4

	thisa = this;
	if (!pTable)
		_CriticalMsg(
		"cResStat: LogStatTable called without a table!",
		"x:\\prj\\tech\\libsrc\\namedres\\resstat.cpp",
		0xFEu);
	if (pName)
	{
		pData = cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::Search(
			&pTable->baseclass_0.baseclass_0,
			pName);
		if (!pData)
		{
			v8 = j__new(0x34u, "x:\\prj\\tech\\libsrc\\namedres\\resstat.cpp", 262);
			if (v8)
			{
				cNamedStatsData::cNamedStatsData((cNamedStatsData *)v8, pName);
				v6 = v5;
			}
			else
			{
				v6 = 0;
			}
			pData = v6;
			cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::Insert(&pTable->baseclass_0.baseclass_0, v6);
		}
		cResStats::LogStat(thisa, pRes, pData->m_Stats, StatType);
	}
}

//----- (008E425B) --------------------------------------------------------
void __thiscall cResStats::LogStatRes(cResStats *this, IRes *pRes, eResourceStats StatType)
{
	cResStats *thisa; // [sp+0h] [bp-14h]@1
	const char *pFullPathName; // [sp+4h] [bp-10h]@12
	const char *pCanonPath; // [sp+8h] [bp-Ch]@9
	const char *pTypename; // [sp+Ch] [bp-8h]@7
	void *pType; // [sp+10h] [bp-4h]@7

	thisa = this;
	if (pRes)
	{
		if ((signed int)StatType >= 12)
			_CriticalMsg("Unknown Stat type!", "x:\\prj\\tech\\libsrc\\namedres\\resstat.cpp", 0x113u);
		if (thisa->m_StatMode[1])
			cResStats::LogStat(thisa, pRes, thisa->m_Stats, StatType);
		if (thisa->m_StatMode[2])
		{
			pType = (void *)((int(__stdcall *)(IRes *))pRes->baseclass_0.baseclass_0.vfptr[2].QueryInterface)(pRes);
			pTypename = (const char *)(*(int(__stdcall **)(void *))(*(_DWORD *)pType + 12))(pType);
			cResStats::LogStatTable(thisa, pRes, thisa->m_pTypeStats, pTypename, StatType);
			(*(void(__stdcall **)(void *))(*(_DWORD *)pType + 8))(pType);
		}
		if (thisa->m_StatMode[3])
		{
			((void(__stdcall *)(IRes *, const char **))pRes->baseclass_0.baseclass_0.vfptr[2].Release)(pRes, &pCanonPath);
			cResStats::LogStatTable(thisa, pRes, thisa->m_pPathStats, pCanonPath, StatType);
			FreeSpew((void *)pCanonPath, "x:\\prj\\tech\\libsrc\\namedres\\resstat.cpp", 291);
		}
		if (thisa->m_StatMode[4] || thisa->m_StatMode[5])
		{
			((void(__stdcall *)(IRes *, signed int, const char **))pRes->baseclass_0.baseclass_0.vfptr[4].AddRef)(
				pRes,
				1,
				&pFullPathName);
			cResStats::LogStatTable(thisa, pRes, thisa->m_pResStats, pFullPathName, StatType);
			FreeSpew((void *)pFullPathName, "x:\\prj\\tech\\libsrc\\namedres\\resstat.cpp", 299);
		}
	}
}

//----- (008E43B0) --------------------------------------------------------
void *__thiscall cNamedStatsHash::_scalar_deleting_destructor_(cNamedStatsHash *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cNamedStatsHash::_cNamedStatsHash(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E43E0) --------------------------------------------------------
cNamedStatsData *__thiscall cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::Insert(cHashSet<cNamedStatsData *, char const *, cCaselessStringHashFuncs> *this, cNamedStatsData *node)
{
	return (cNamedStatsData *)cHashSetBase::Insert(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008E4400) --------------------------------------------------------
cNamedStatsData *__thiscall cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::Search(cHashSet<cNamedStatsData *, char const *, cCaselessStringHashFuncs> *this, const char *key)
{
	return (cNamedStatsData *)cHashSetBase::Search(&this->baseclass_0, (tHashSetKey__ *)key);
}

//----- (008E4420) --------------------------------------------------------
cNamedStatsData *__thiscall cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::GetFirst(cHashSet<cNamedStatsData *, char const *, cCaselessStringHashFuncs> *this, tHashSetHandle *Handle)
{
	return (cNamedStatsData *)cHashSetBase::GetFirst(&this->baseclass_0, Handle);
}

//----- (008E4440) --------------------------------------------------------
cNamedStatsData *__thiscall cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::GetNext(cHashSet<cNamedStatsData *, char const *, cCaselessStringHashFuncs> *this, tHashSetHandle *Handle)
{
	return (cNamedStatsData *)cHashSetBase::GetNext(&this->baseclass_0, Handle);
}
