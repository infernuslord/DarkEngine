
//----- (008CDD70) --------------------------------------------------------
int __thiscall cHashTable<char_const___sStructDesc_const___cHashFunctions>::HasKey(cHashTable<char const *, sStructDesc const *, cHashFunctions> *this, const char *const *key)
{
	void *val; // [sp+4h] [bp-4h]@1

	return cHashTable<char_const___sStructDesc_const___cHashFunctions>::Lookup(this, key, (sStructDesc **)&val);
}

//----- (008CDD90) --------------------------------------------------------
int __thiscall cHashTable<char_const___sStructDesc_const___cHashFunctions>::Lookup(cHashTable<char const *, sStructDesc const *, cHashFunctions> *this, const char *const *key, sStructDesc **value)
{
	int result; // eax@2
	cHashTable<char const *, sStructDesc const *, cHashFunctions> *thisa; // [sp+0h] [bp-8h]@1
	int i; // [sp+4h] [bp-4h]@1

	thisa = this;
	if (cHashTable<char_const___sStructDesc_const___cHashFunctions>::find_elem(this, key, &i))
	{
		*value = thisa->vec[i].value;
		result = 1;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008CDDD0) --------------------------------------------------------
void __thiscall cHashTable<char_const___sStructDesc_const___cHashFunctions>::cHashTable<char_const___sStructDesc_const___cHashFunctions>(cHashTable<char const *, sStructDesc const *, cHashFunctions> *this, int vecsize)
{
	cHashTable<char const *, sStructDesc const *, cHashFunctions> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	this->fullness = 0;
	this->tombstones = 0;
	this->vfptr = (cHashTable<char const *, sStructDesc const *, cHashFunctions>Vtbl *)&cHashTable<char_const___sStructDesc_const___cHashFunctions>::_vftable_;
	while (!cHashHelperFunctions::is_prime(vecsize))
		++vecsize;
	*(_DWORD *)&thisa->___u1.baseclass_4.dummy[0] = vecsize;
	cHashTable<char_const___sStructDesc_const___cHashFunctions>::Init(thisa);
}
// 9A7818: using guessed type int (__stdcall *cHashTable_char const __sStructDesc const __cHashFunctions____vftable_)(int __flags);

//----- (008CDE30) --------------------------------------------------------
void __thiscall cHashTable<char_const___sStructDesc_const___cHashFunctions>::_cHashTable<char_const___sStructDesc_const___cHashFunctions>(cHashTable<char const *, sStructDesc const *, cHashFunctions> *this)
{
	cHashTable<char const *, sStructDesc const *, cHashFunctions> *v1; // ST04_4@1

	v1 = this;
	this->vfptr = (cHashTable<char const *, sStructDesc const *, cHashFunctions>Vtbl *)&cHashTable<char_const___sStructDesc_const___cHashFunctions>::_vftable_;
	*(_DWORD *)&this->___u1.baseclass_4.dummy[0] = 0;
	this->fullness = 0;
	operator delete(this->statvec);
	operator delete(v1->vec);
}
// 9A7818: using guessed type int (__stdcall *cHashTable_char const __sStructDesc const __cHashFunctions____vftable_)(int __flags);

//----- (008CDE90) --------------------------------------------------------
int __thiscall cHashTable<char_const___sStructDesc_const___cHashFunctions>::Set(cHashTable<char const *, sStructDesc const *, cHashFunctions> *this, const char *const *key, sStructDesc *const *value)
{
	int result; // eax@2
	cHashTable<char const *, sStructDesc const *, cHashFunctions> *thisa; // [sp+0h] [bp-8h]@1
	int i; // [sp+4h] [bp-4h]@1

	thisa = this;
	if (cHashTable<char_const___sStructDesc_const___cHashFunctions>::find_elem(this, key, &i))
	{
		thisa->vec[i].key = *key;
		thisa->vec[i].value = *value;
		thisa->statvec[i] = 2;
		result = 1;
	}
	else
	{
		cHashTable<char_const___sStructDesc_const___cHashFunctions>::Insert(thisa, key, value);
		result = 0;
	}
	return result;
}

//----- (008CDF00) --------------------------------------------------------
sStructDesc *const *__thiscall cHashTable<char_const___sStructDesc_const___cHashFunctions>::Search(cHashTable<char const *, sStructDesc const *, cHashFunctions> *this, const char *const *key)
{
	sStructDesc *const *result; // eax@2
	cHashTable<char const *, sStructDesc const *, cHashFunctions> *thisa; // [sp+0h] [bp-8h]@1
	int i; // [sp+4h] [bp-4h]@1

	thisa = this;
	if (cHashTable<char_const___sStructDesc_const___cHashFunctions>::find_elem(this, key, &i))
		result = &thisa->vec[i].value;
	else
		result = cHashTable<char_const___sStructDesc_const___cHashFunctions>::SomeValue();
	return result;
}

//----- (008CDF40) --------------------------------------------------------
void __thiscall cHashTable<char_const___sStructDesc_const___cHashFunctions>::Clear(cHashTable<char const *, sStructDesc const *, cHashFunctions> *this, int newsize)
{
	cHashTable<char const *, sStructDesc const *, cHashFunctions> *thisa; // [sp+0h] [bp-Ch]@1

	thisa = this;
	while (!cHashHelperFunctions::is_prime(newsize))
		++newsize;
	operator delete(thisa->statvec);
	operator delete(thisa->vec);
	*(_DWORD *)&thisa->___u1.baseclass_4.dummy[0] = newsize;
	thisa->fullness = 0;
	cHashTable<char_const___sStructDesc_const___cHashFunctions>::Init(thisa);
}

//----- (008CDFC0) --------------------------------------------------------
void *__thiscall cHashTable<char_const___sStructDesc_const___cHashFunctions>::_scalar_deleting_destructor_(cHashTable<char const *, sStructDesc const *, cHashFunctions> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cHashTable<char_const___sStructDesc_const___cHashFunctions>::_cHashTable<char_const___sStructDesc_const___cHashFunctions>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008CDFF0) --------------------------------------------------------
int __thiscall cHashTable<char_const___sStructDesc_const___cHashFunctions>::find_elem(cHashTable<char const *, sStructDesc const *, cHashFunctions> *this, const char *const *key, int *idx)
{
	cHashTable<char const *, sStructDesc const *, cHashFunctions> *thisa; // [sp+0h] [bp-1Ch]@1
	unsigned int hash; // [sp+8h] [bp-14h]@1
	int found; // [sp+Ch] [bp-10h]@1
	int index; // [sp+10h] [bp-Ch]@1
	signed int delta; // [sp+14h] [bp-8h]@1
	int j; // [sp+18h] [bp-4h]@1

	thisa = this;
	found = 0;
	hash = cHashFunctions::Hash(*key);
	index = hash % *(_DWORD *)&thisa->___u1.baseclass_4.dummy[0];
	delta = 0;
	for (j = 0; j < *(_DWORD *)&thisa->___u1.baseclass_4.dummy[0] && thisa->statvec[index]; ++j)
	{
		if (thisa->statvec[index] == 2 && cHashFunctions::IsEqual(*key, thisa->vec[index].key))
		{
			found = 1;
			break;
		}
		if (!delta)
			delta = 1 << hash % thisa->sizelog2;
		for (index += delta;
			index >= *(_DWORD *)&thisa->___u1.baseclass_4.dummy[0];
			index -= *(_DWORD *)&thisa->___u1.baseclass_4.dummy[0])
			;
	}
	*idx = index;
	return found;
}

//----- (008CE100) --------------------------------------------------------
void __thiscall cHashTable<char_const___sStructDesc_const___cHashFunctions>::Init(cHashTable<char const *, sStructDesc const *, cHashFunctions> *this)
{
	cHashTable<char const *, sStructDesc const *, cHashFunctions> *thisa; // [sp+0h] [bp-10h]@1
	int i; // [sp+Ch] [bp-4h]@3

	thisa = this;
	this->sizelog2 = cHashHelperFunctions::hashlog2(*(_DWORD *)&this->___u1.baseclass_4.dummy[0]);
	thisa->statvec = (char *)j__new(*(_DWORD *)&thisa->___u1.baseclass_4.dummy[0], "x:\\prj\\tech\\h\\hshpptem.h", 44);
	if (!thisa->statvec)
		DbgReportWarning("Assert in %s at line %d in %s\n");
	for (i = 0; i < *(_DWORD *)&thisa->___u1.baseclass_4.dummy[0]; ++i)
		thisa->statvec[i] = 0;
	thisa->vec = (cHashTable<char const *, sStructDesc const *, cHashFunctions>::Elem *)j__new(
		8
		* *(_DWORD *)&thisa->___u1.baseclass_4.dummy[0],
		"x:\\prj\\tech\\h\\hshpptem.h",
		47);
	if (!thisa->vec)
		DbgReportWarning("Assert in %s at line %d in %s\n");
}

//----- (008CE1E0) --------------------------------------------------------
sStructDesc **__cdecl cHashTable<char_const___sStructDesc_const___cHashFunctions>::SomeValue()
{
	return &value;
}

//----- (008CE1F0) --------------------------------------------------------
__int16 __thiscall cHashTable<char_const___sStructDesc_const___cHashFunctions>::Insert(cHashTable<char const *, sStructDesc const *, cHashFunctions> *this, const char *const *key, sStructDesc *const *value)
{
	cHashTable<char const *, sStructDesc const *, cHashFunctions> *thisa; // [sp+0h] [bp-8h]@1
	int i; // [sp+4h] [bp-4h]@5

	thisa = this;
	if (100 * (this->tombstones + this->fullness) > 80 * *(_DWORD *)&this->___u1.baseclass_4.dummy[0])
	{
		if (this->tombstones < this->fullness)
			cHashTable<char_const___sStructDesc_const___cHashFunctions>::Grow(
			this,
			100 * this->fullness / 80 + *(_DWORD *)&this->___u1.baseclass_4.dummy[0]);
		else
			cHashTable<char_const___sStructDesc_const___cHashFunctions>::Grow(
			this,
			*(_DWORD *)&this->___u1.baseclass_4.dummy[0]);
	}
	i = cHashTable<char_const___sStructDesc_const___cHashFunctions>::find_index(thisa, key);
	thisa->vec[i].key = *key;
	thisa->vec[i].value = *value;
	if (thisa->statvec[i] == 1)
		--thisa->tombstones;
	thisa->statvec[i] = 2;
	++thisa->fullness;
	return 0;
}

//----- (008CE2D0) --------------------------------------------------------
int __thiscall cHashTable<char_const___sStructDesc_const___cHashFunctions>::find_index(cHashTable<char const *, sStructDesc const *, cHashFunctions> *this, const char *const *key)
{
	cHashTable<char const *, sStructDesc const *, cHashFunctions> *thisa; // [sp+0h] [bp-14h]@1
	int j; // [sp+8h] [bp-Ch]@2
	unsigned int hash; // [sp+Ch] [bp-8h]@1
	signed int index; // [sp+10h] [bp-4h]@1

	thisa = this;
	hash = cHashFunctions::Hash(*key);
	index = hash % *(_DWORD *)&thisa->___u1.baseclass_4.dummy[0];
	if (thisa->statvec[index] == 2)
	{
		for (j = 0; j < *(_DWORD *)&thisa->___u1.baseclass_4.dummy[0] && thisa->statvec[index] == 2; ++j)
		{
			for (index += 1 << hash % thisa->sizelog2;
				index >= *(_DWORD *)&thisa->___u1.baseclass_4.dummy[0];
				index -= *(_DWORD *)&thisa->___u1.baseclass_4.dummy[0])
				;
		}
		if (j >= *(_DWORD *)&thisa->___u1.baseclass_4.dummy[0])
		{
			DbgReportWarning("Hash table index not found!\n");
			index = -1;
		}
	}
	return index;
}

//----- (008CE3B0) --------------------------------------------------------
__int16 __thiscall cHashTable<char_const___sStructDesc_const___cHashFunctions>::Grow(cHashTable<char const *, sStructDesc const *, cHashFunctions> *this, int newsize)
{
	__int16 result; // ax@5
	cHashTable<char const *, sStructDesc const *, cHashFunctions> *thisa; // [sp+0h] [bp-30h]@1
	void *newvec; // [sp+18h] [bp-18h]@4
	int i; // [sp+1Ch] [bp-14h]@8
	int ia; // [sp+1Ch] [bp-14h]@11
	void *newstat; // [sp+20h] [bp-10h]@6
	int oldsize; // [sp+24h] [bp-Ch]@1
	void *oldstat; // [sp+28h] [bp-8h]@1
	void *oldvec; // [sp+2Ch] [bp-4h]@1

	thisa = this;
	oldvec = this->vec;
	oldstat = this->statvec;
	oldsize = *(_DWORD *)&this->___u1.baseclass_4.dummy[0];
	while (!cHashHelperFunctions::is_prime(newsize))
		++newsize;
	newvec = j__new(8 * newsize, "x:\\prj\\tech\\h\\hshpptem.h", 143);
	if (newvec)
	{
		newstat = j__new(newsize, "x:\\prj\\tech\\h\\hshpptem.h", 146);
		if (newstat)
		{
			thisa->vec = (cHashTable<char const *, sStructDesc const *, cHashFunctions>::Elem *)newvec;
			thisa->statvec = (char *)newstat;
			*(_DWORD *)&thisa->___u1.baseclass_4.dummy[0] = newsize;
			thisa->sizelog2 = cHashHelperFunctions::hashlog2(newsize);
			thisa->fullness = 0;
			thisa->tombstones = 0;
			for (i = 0; i < newsize; ++i)
				*((_BYTE *)newstat + i) = 0;
			for (ia = 0; ia < oldsize; ++ia)
			{
				if (*((_BYTE *)oldstat + ia) == 2)
					cHashTable<char_const___sStructDesc_const___cHashFunctions>::Insert(
					thisa,
					(const char *const *)oldvec + 2 * ia,
					(sStructDesc *const *)oldvec + 2 * ia + 1);
			}
			operator delete(oldvec);
			operator delete(oldstat);
			result = 0;
		}
		else
		{
			operator delete(newvec);
			result = 7;
		}
	}
	else
	{
		result = 7;
	}
	return result;
}
