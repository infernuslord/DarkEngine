
//----- (008DE420) --------------------------------------------------------
void __thiscall cDefResMem::cDefResMem(cDefResMem *this)
{
	cDefResMem *v1; // ST00_4@1

	v1 = this;
	IResMemOverride::IResMemOverride(&this->baseclass_0);
	cDefResMem::cRefCount::cRefCount(&v1->__m_ulRefs);
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cDefResMem::_vftable_;
}
// 9A7D68: using guessed type int (__stdcall *cDefResMem___vftable_)(int this, int id, int ppI);

//----- (008DE450) --------------------------------------------------------
void __thiscall cDefResMem::cRefCount::cRefCount(cDefResMem::cRefCount *this)
{
	this->ul = 1;
}

//----- (008DE470) --------------------------------------------------------
void __thiscall IResMemOverride::IResMemOverride(IResMemOverride *this)
{
	IResMemOverride *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)IResMemOverride::_vftable_;
}
// 9A7D80: using guessed type int (*IResMemOverride___vftable_[6])();

//----- (008DE490) --------------------------------------------------------
const char *__thiscall cResourceTypeData::GetName(cResourceTypeData *this)
{
	return this->m_pResourceData->m_pNameData->m_pName;
}

//----- (008DE4B0) --------------------------------------------------------
void *__thiscall cResStats::_scalar_deleting_destructor_(cResStats *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cResStats::_cResStats(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DE4E0) --------------------------------------------------------
void *__thiscall cNamedResType::_scalar_deleting_destructor_(cNamedResType *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cNamedResType::_cNamedResType(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DE510) --------------------------------------------------------
void *__thiscall cResourceTypeData::_scalar_deleting_destructor_(cResourceTypeData *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cResourceTypeData::_cResourceTypeData(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DE540) --------------------------------------------------------
void __thiscall cStrIHashSet<cNamedStatsData__>::cStrIHashSet<cNamedStatsData__>(cStrIHashSet<cNamedStatsData *> *this, unsigned int n)
{
	cStrIHashSet<cNamedStatsData *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		n);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<cNamedStatsData__>::_vftable_;
}
// 9A7D98: using guessed type int (__stdcall *cStrIHashSet_cNamedStatsData _____vftable_)(int __flags);

//----- (008DE570) --------------------------------------------------------
void __thiscall cStrIHashSet<cNamedStatsData__>::cStrIHashSet<cNamedStatsData__>(cStrIHashSet<cNamedStatsData *> *this, cHashSet<cNamedStatsData *, char const *, cCaselessStringHashFuncs> *__formal)
{
	cStrIHashSet<cNamedStatsData *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		&this->baseclass_0);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<cNamedStatsData__>::_vftable_;
}
// 9A7D98: using guessed type int (__stdcall *cStrIHashSet_cNamedStatsData _____vftable_)(int __flags);

//----- (008DE5A0) --------------------------------------------------------
void __thiscall cStrIHashSet<cResourceTypeData__>::cStrIHashSet<cResourceTypeData__>(cStrIHashSet<cResourceTypeData *> *this, unsigned int n)
{
	cStrIHashSet<cResourceTypeData *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		n);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<cResourceTypeData__>::_vftable_;
}
// 9A7DB8: using guessed type int (__stdcall *cStrIHashSet_cResourceTypeData _____vftable_)(int __flags);

//----- (008DE5D0) --------------------------------------------------------
void __thiscall cStrIHashSet<cResourceTypeData__>::cStrIHashSet<cResourceTypeData__>(cStrIHashSet<cResourceTypeData *> *this, cHashSet<cResourceTypeData *, char const *, cCaselessStringHashFuncs> *__formal)
{
	cStrIHashSet<cResourceTypeData *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		&this->baseclass_0);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<cResourceTypeData__>::_vftable_;
}
// 9A7DB8: using guessed type int (__stdcall *cStrIHashSet_cResourceTypeData _____vftable_)(int __flags);

//----- (008DE600) --------------------------------------------------------
void __thiscall cStrIHashSet<cResourceName__>::cStrIHashSet<cResourceName__>(cStrIHashSet<cResourceName *> *this, unsigned int n)
{
	cStrIHashSet<cResourceName *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		n);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<cResourceName__>::_vftable_;
}
// 9A7DD8: using guessed type int (__stdcall *cStrIHashSet_cResourceName _____vftable_)(int __flags);

//----- (008DE630) --------------------------------------------------------
void __thiscall cStrIHashSet<cResourceName__>::cStrIHashSet<cResourceName__>(cStrIHashSet<cResourceName *> *this, cHashSet<cResourceName *, char const *, cCaselessStringHashFuncs> *__formal)
{
	cStrIHashSet<cResourceName *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		&this->baseclass_0);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<cResourceName__>::_vftable_;
}
// 9A7DD8: using guessed type int (__stdcall *cStrIHashSet_cResourceName _____vftable_)(int __flags);

//----- (008DE660) --------------------------------------------------------
void __thiscall cStrIHashSet<cResTypeData__>::cStrIHashSet<cResTypeData__>(cStrIHashSet<cResTypeData *> *this, unsigned int n)
{
	cStrIHashSet<cResTypeData *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		n);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<cResTypeData__>::_vftable_;
}
// 9A7DF8: using guessed type int (__stdcall *cStrIHashSet_cResTypeData _____vftable_)(int __flags);

//----- (008DE690) --------------------------------------------------------
void __thiscall cStrIHashSet<cResTypeData__>::cStrIHashSet<cResTypeData__>(cStrIHashSet<cResTypeData *> *this, cHashSet<cResTypeData *, char const *, cCaselessStringHashFuncs> *__formal)
{
	cStrIHashSet<cResTypeData *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		&this->baseclass_0);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<cResTypeData__>::_vftable_;
}
// 9A7DF8: using guessed type int (__stdcall *cStrIHashSet_cResTypeData _____vftable_)(int __flags);

//----- (008DE6C0) --------------------------------------------------------
void __thiscall cStrIHashSet<cNamedResType__>::cStrIHashSet<cNamedResType__>(cStrIHashSet<cNamedResType *> *this, unsigned int n)
{
	cStrIHashSet<cNamedResType *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		n);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<cNamedResType__>::_vftable_;
}
// 9A7E18: using guessed type int (__stdcall *cStrIHashSet_cNamedResType _____vftable_)(int __flags);

//----- (008DE6F0) --------------------------------------------------------
void __thiscall cStrIHashSet<cNamedResType__>::cStrIHashSet<cNamedResType__>(cStrIHashSet<cNamedResType *> *this, cHashSet<cNamedResType *, char const *, cCaselessStringHashFuncs> *__formal)
{
	cStrIHashSet<cNamedResType *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		&this->baseclass_0);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<cNamedResType__>::_vftable_;
}
// 9A7E18: using guessed type int (__stdcall *cStrIHashSet_cNamedResType _____vftable_)(int __flags);

//----- (008DE720) --------------------------------------------------------
void __thiscall cCTDelegating<IResMan>::cCTDelegating<IResMan>(cCTDelegating<IResMan> *this)
{
	cCTDelegating<IResMan> *v1; // ST00_4@1

	v1 = this;
	IResMan::IResMan(&this->baseclass_0);
	v1->__m_pOuterUnknown = 0;
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTDelegating<IResMan>::_vftable_;
}
// 9A7E38: using guessed type int (__stdcall *cCTDelegating_IResMan____vftable_)(int this, int id, int ppI);

//----- (008DE750) --------------------------------------------------------
void __thiscall cCTDelegating<IResMan>::_cCTDelegating<IResMan>(cCTDelegating<IResMan> *this)
{
	this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTDelegating<IResMan>::_vftable_;
}
// 9A7E38: using guessed type int (__stdcall *cCTDelegating_IResMan____vftable_)(int this, int id, int ppI);

//----- (008DE770) --------------------------------------------------------
void __thiscall cCTDelegating<IResMan>::InitDelegation(cCTDelegating<IResMan> *this, IUnknown *pOuterUnknown)
{
	this->__m_pOuterUnknown = pOuterUnknown;
}

//----- (008DE790) --------------------------------------------------------
int __stdcall cCTDelegating<IResMan>::QueryInterface(cCTDelegating<IResMan> *this, _GUID *id, void **ppI)
{
	return (**(int(__stdcall ***)(_DWORD, _DWORD, _DWORD))this->__m_pOuterUnknown)(this->__m_pOuterUnknown, id, ppI);
}

//----- (008DE7B0) --------------------------------------------------------
unsigned int __stdcall cCTDelegating<IResMan>::AddRef(cCTDelegating<IResMan> *this)
{
	return this->__m_pOuterUnknown->vfptr->AddRef(this->__m_pOuterUnknown);
}

//----- (008DE7D0) --------------------------------------------------------
unsigned int __stdcall cCTDelegating<IResMan>::Release(cCTDelegating<IResMan> *this)
{
	return this->__m_pOuterUnknown->vfptr->Release(this->__m_pOuterUnknown);
}

//----- (008DE7F0) --------------------------------------------------------
void __thiscall cCTDelegating<IResStats>::cCTDelegating<IResStats>(cCTDelegating<IResStats> *this)
{
	cCTDelegating<IResStats> *v1; // ST00_4@1

	v1 = this;
	IResStats::IResStats(&this->baseclass_0);
	v1->__m_pOuterUnknown = 0;
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTDelegating<IResStats>::_vftable_;
}
// 9A7E84: using guessed type int (__stdcall *cCTDelegating_IResStats____vftable_)(int this, int id, int ppI);

//----- (008DE820) --------------------------------------------------------
void __thiscall cCTDelegating<IResStats>::_cCTDelegating<IResStats>(cCTDelegating<IResStats> *this)
{
	this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTDelegating<IResStats>::_vftable_;
}
// 9A7E84: using guessed type int (__stdcall *cCTDelegating_IResStats____vftable_)(int this, int id, int ppI);

//----- (008DE840) --------------------------------------------------------
void __thiscall cCTDelegating<IResStats>::InitDelegation(cCTDelegating<IResStats> *this, IUnknown *pOuterUnknown)
{
	this->__m_pOuterUnknown = pOuterUnknown;
}

//----- (008DE860) --------------------------------------------------------
int __stdcall cCTDelegating<IResStats>::QueryInterface(cCTDelegating<IResStats> *this, _GUID *id, void **ppI)
{
	return (**(int(__stdcall ***)(_DWORD, _DWORD, _DWORD))this->__m_pOuterUnknown)(this->__m_pOuterUnknown, id, ppI);
}

//----- (008DE880) --------------------------------------------------------
unsigned int __stdcall cCTDelegating<IResStats>::AddRef(cCTDelegating<IResStats> *this)
{
	return this->__m_pOuterUnknown->vfptr->AddRef(this->__m_pOuterUnknown);
}

//----- (008DE8A0) --------------------------------------------------------
unsigned int __stdcall cCTDelegating<IResStats>::Release(cCTDelegating<IResStats> *this)
{
	return this->__m_pOuterUnknown->vfptr->Release(this->__m_pOuterUnknown);
}

//----- (008DE8C0) --------------------------------------------------------
void __thiscall cCTDelegating<IResMem>::cCTDelegating<IResMem>(cCTDelegating<IResMem> *this)
{
	cCTDelegating<IResMem> *v1; // ST00_4@1

	v1 = this;
	IResMem::IResMem(&this->baseclass_0);
	v1->__m_pOuterUnknown = 0;
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTDelegating<IResMem>::_vftable_;
}
// 9A7EA0: using guessed type int (__stdcall *cCTDelegating_IResMem____vftable_)(int this, int id, int ppI);

//----- (008DE8F0) --------------------------------------------------------
void __thiscall cCTDelegating<IResMem>::_cCTDelegating<IResMem>(cCTDelegating<IResMem> *this)
{
	this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTDelegating<IResMem>::_vftable_;
}
// 9A7EA0: using guessed type int (__stdcall *cCTDelegating_IResMem____vftable_)(int this, int id, int ppI);

//----- (008DE910) --------------------------------------------------------
void __thiscall cCTDelegating<IResMem>::InitDelegation(cCTDelegating<IResMem> *this, IUnknown *pOuterUnknown)
{
	this->__m_pOuterUnknown = pOuterUnknown;
}

//----- (008DE930) --------------------------------------------------------
int __stdcall cCTDelegating<IResMem>::QueryInterface(cCTDelegating<IResMem> *this, _GUID *id, void **ppI)
{
	return (**(int(__stdcall ***)(_DWORD, _DWORD, _DWORD))this->__m_pOuterUnknown)(this->__m_pOuterUnknown, id, ppI);
}

//----- (008DE950) --------------------------------------------------------
unsigned int __stdcall cCTDelegating<IResMem>::AddRef(cCTDelegating<IResMem> *this)
{
	return this->__m_pOuterUnknown->vfptr->AddRef(this->__m_pOuterUnknown);
}

//----- (008DE970) --------------------------------------------------------
unsigned int __stdcall cCTDelegating<IResMem>::Release(cCTDelegating<IResMem> *this)
{
	return this->__m_pOuterUnknown->vfptr->Release(this->__m_pOuterUnknown);
}

//----- (008DE990) --------------------------------------------------------
void __thiscall cCTDelegating<IResManHelper>::cCTDelegating<IResManHelper>(cCTDelegating<IResManHelper> *this)
{
	cCTDelegating<IResManHelper> *v1; // ST00_4@1

	v1 = this;
	IResManHelper::IResManHelper(&this->baseclass_0);
	v1->__m_pOuterUnknown = 0;
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTDelegating<IResManHelper>::_vftable_;
}
// 9A7EB8: using guessed type int (__stdcall *cCTDelegating_IResManHelper____vftable_)(int this, int id, int ppI);

//----- (008DE9C0) --------------------------------------------------------
void __thiscall cCTDelegating<IResManHelper>::_cCTDelegating<IResManHelper>(cCTDelegating<IResManHelper> *this)
{
	this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTDelegating<IResManHelper>::_vftable_;
}
// 9A7EB8: using guessed type int (__stdcall *cCTDelegating_IResManHelper____vftable_)(int this, int id, int ppI);

//----- (008DE9E0) --------------------------------------------------------
void __thiscall cCTDelegating<IResManHelper>::InitDelegation(cCTDelegating<IResManHelper> *this, IUnknown *pOuterUnknown)
{
	this->__m_pOuterUnknown = pOuterUnknown;
}

//----- (008DEA00) --------------------------------------------------------
int __stdcall cCTDelegating<IResManHelper>::QueryInterface(cCTDelegating<IResManHelper> *this, _GUID *id, void **ppI)
{
	return (**(int(__stdcall ***)(_DWORD, _DWORD, _DWORD))this->__m_pOuterUnknown)(this->__m_pOuterUnknown, id, ppI);
}

//----- (008DEA20) --------------------------------------------------------
unsigned int __stdcall cCTDelegating<IResManHelper>::AddRef(cCTDelegating<IResManHelper> *this)
{
	return this->__m_pOuterUnknown->vfptr->AddRef(this->__m_pOuterUnknown);
}

//----- (008DEA40) --------------------------------------------------------
unsigned int __stdcall cCTDelegating<IResManHelper>::Release(cCTDelegating<IResManHelper> *this)
{
	return this->__m_pOuterUnknown->vfptr->Release(this->__m_pOuterUnknown);
}

//----- (008DEA60) --------------------------------------------------------
void __thiscall cStrHashSet<cFactoryEntry__>::cStrHashSet<cFactoryEntry__>(cStrHashSet<cFactoryEntry *> *this, unsigned int n)
{
	cStrHashSet<cFactoryEntry *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cFactoryEntry___char_const___cHashFunctions>::cHashSet<cFactoryEntry___char_const___cHashFunctions>(
		&this->baseclass_0,
		n);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrHashSet<cFactoryEntry__>::_vftable_;
}
// 9A7F00: using guessed type int (__stdcall *cStrHashSet_cFactoryEntry _____vftable_)(int __flags);

//----- (008DEA90) --------------------------------------------------------
void __thiscall cStrHashSet<cFactoryEntry__>::cStrHashSet<cFactoryEntry__>(cStrHashSet<cFactoryEntry *> *this, cHashSet<cFactoryEntry *, char const *, cHashFunctions> *__formal)
{
	cStrHashSet<cFactoryEntry *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cFactoryEntry___char_const___cHashFunctions>::cHashSet<cFactoryEntry___char_const___cHashFunctions>(
		&this->baseclass_0,
		&this->baseclass_0);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrHashSet<cFactoryEntry__>::_vftable_;
}
// 9A7F00: using guessed type int (__stdcall *cStrHashSet_cFactoryEntry _____vftable_)(int __flags);

//----- (008DEAC0) --------------------------------------------------------
void *__thiscall cStrIHashSet<cNamedStatsData__>::_scalar_deleting_destructor_(cStrIHashSet<cNamedStatsData *> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStrIHashSet<cNamedStatsData__>::_cStrIHashSet<cNamedStatsData__>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DEAF0) --------------------------------------------------------
void *__thiscall cStrIHashSet<cResourceTypeData__>::_scalar_deleting_destructor_(cStrIHashSet<cResourceTypeData *> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStrIHashSet<cResourceTypeData__>::_cStrIHashSet<cResourceTypeData__>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DEB20) --------------------------------------------------------
void *__thiscall cStrIHashSet<cResourceName__>::_vector_deleting_destructor_(cStrIHashSet<cResourceName *> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStrIHashSet<cResourceName__>::_cStrIHashSet<cResourceName__>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DEB50) --------------------------------------------------------
void *__thiscall cStrIHashSet<cResTypeData__>::_vector_deleting_destructor_(cStrIHashSet<cResTypeData *> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStrIHashSet<cResTypeData__>::_cStrIHashSet<cResTypeData__>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DEB80) --------------------------------------------------------
void *__thiscall cStrIHashSet<cNamedResType__>::_vector_deleting_destructor_(cStrIHashSet<cNamedResType *> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStrIHashSet<cNamedResType__>::_cStrIHashSet<cNamedResType__>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DEBB0) --------------------------------------------------------
void *__thiscall cCTDelegating<IResMan>::_vector_deleting_destructor_(cCTDelegating<IResMan> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cCTDelegating<IResMan>::_cCTDelegating<IResMan>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DEBE0) --------------------------------------------------------
void __thiscall IResMan::IResMan(IResMan *this)
{
	IResMan *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)IResMan::_vftable_;
}
// 9A7F20: using guessed type int (*IResMan___vftable_[46])();

//----- (008DEC00) --------------------------------------------------------
void *__thiscall cCTDelegating<IResStats>::_scalar_deleting_destructor_(cCTDelegating<IResStats> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cCTDelegating<IResStats>::_cCTDelegating<IResStats>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DEC30) --------------------------------------------------------
void __thiscall IResStats::IResStats(IResStats *this)
{
	IResStats *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)IResStats::_vftable_;
}
// 9A7F68: using guessed type int (*IResStats___vftable_[28])();

//----- (008DEC50) --------------------------------------------------------
void *__thiscall cCTDelegating<IResMem>::_scalar_deleting_destructor_(cCTDelegating<IResMem> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cCTDelegating<IResMem>::_cCTDelegating<IResMem>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DEC80) --------------------------------------------------------
void __thiscall IResMem::IResMem(IResMem *this)
{
	IResMem *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)IResMem::_vftable_;
}
// 9A7F80: using guessed type int (*IResMem___vftable_[22])();

//----- (008DECA0) --------------------------------------------------------
void *__thiscall cCTDelegating<IResManHelper>::_vector_deleting_destructor_(cCTDelegating<IResManHelper> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cCTDelegating<IResManHelper>::_cCTDelegating<IResManHelper>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DECD0) --------------------------------------------------------
void __thiscall IResManHelper::IResManHelper(IResManHelper *this)
{
	IResManHelper *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)IResManHelper::_vftable_;
}
// 9A7F94: using guessed type int (*IResManHelper___vftable_[17])();

//----- (008DECF0) --------------------------------------------------------
void *__thiscall cStrHashSet<cFactoryEntry__>::_vector_deleting_destructor_(cStrHashSet<cFactoryEntry *> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStrHashSet<cFactoryEntry__>::_cStrHashSet<cFactoryEntry__>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DED20) --------------------------------------------------------
void __thiscall cStrIHashSet<cNamedStatsData__>::_cStrIHashSet<cNamedStatsData__>(cStrIHashSet<cNamedStatsData *> *this)
{
	cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::_cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>(&this->baseclass_0);
}

//----- (008DED40) --------------------------------------------------------
void __thiscall cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::_cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>(cHashSet<cNamedStatsData *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSetBase::_cHashSetBase(&this->baseclass_0);
}

//----- (008DED60) --------------------------------------------------------
void __thiscall cStrIHashSet<cResourceTypeData__>::_cStrIHashSet<cResourceTypeData__>(cStrIHashSet<cResourceTypeData *> *this)
{
	cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::_cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>(&this->baseclass_0);
}

//----- (008DED80) --------------------------------------------------------
void __thiscall cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::_cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>(cHashSet<cResourceTypeData *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSetBase::_cHashSetBase(&this->baseclass_0);
}

//----- (008DEDA0) --------------------------------------------------------
void __thiscall cStrIHashSet<cResourceName__>::_cStrIHashSet<cResourceName__>(cStrIHashSet<cResourceName *> *this)
{
	cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::_cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>(&this->baseclass_0);
}

//----- (008DEDC0) --------------------------------------------------------
void __thiscall cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::_cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>(cHashSet<cResourceName *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSetBase::_cHashSetBase(&this->baseclass_0);
}

//----- (008DEDE0) --------------------------------------------------------
void __thiscall cStrIHashSet<cResTypeData__>::_cStrIHashSet<cResTypeData__>(cStrIHashSet<cResTypeData *> *this)
{
	cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::_cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>(&this->baseclass_0);
}

//----- (008DEE00) --------------------------------------------------------
void __thiscall cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::_cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>(cHashSet<cResTypeData *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSetBase::_cHashSetBase(&this->baseclass_0);
}

//----- (008DEE20) --------------------------------------------------------
void __thiscall cStrIHashSet<cNamedResType__>::_cStrIHashSet<cNamedResType__>(cStrIHashSet<cNamedResType *> *this)
{
	cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::_cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>(&this->baseclass_0);
}

//----- (008DEE40) --------------------------------------------------------
void __thiscall cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::_cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>(cHashSet<cNamedResType *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSetBase::_cHashSetBase(&this->baseclass_0);
}

//----- (008DEE60) --------------------------------------------------------
void __thiscall cStrHashSet<cFactoryEntry__>::_cStrHashSet<cFactoryEntry__>(cStrHashSet<cFactoryEntry *> *this)
{
	cHashSet<cFactoryEntry___char_const___cHashFunctions>::_cHashSet<cFactoryEntry___char_const___cHashFunctions>(&this->baseclass_0);
}

//----- (008DEE80) --------------------------------------------------------
void __thiscall cHashSet<cFactoryEntry___char_const___cHashFunctions>::_cHashSet<cFactoryEntry___char_const___cHashFunctions>(cHashSet<cFactoryEntry *, char const *, cHashFunctions> *this)
{
	cHashSetBase::_cHashSetBase(&this->baseclass_0);
}

//----- (008DEEA0) --------------------------------------------------------
void __thiscall cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>(cHashSet<cNamedStatsData *, char const *, cCaselessStringHashFuncs> *this, unsigned int n)
{
	cHashSet<cNamedStatsData *, char const *, cCaselessStringHashFuncs> *v2; // ST14_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, n);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A7FD8: using guessed type int (__stdcall *cHashSet_cNamedStatsData __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008DEF10) --------------------------------------------------------
void __thiscall cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>(cHashSet<cNamedStatsData *, char const *, cCaselessStringHashFuncs> *this, cHashSet<cNamedStatsData *, char const *, cCaselessStringHashFuncs> *__formal)
{
	cHashSet<cNamedStatsData *, char const *, cCaselessStringHashFuncs> *v2; // ST04_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, &this->baseclass_0);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A7FD8: using guessed type int (__stdcall *cHashSet_cNamedStatsData __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008DEF40) --------------------------------------------------------
void __thiscall cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>(cHashSet<cResourceTypeData *, char const *, cCaselessStringHashFuncs> *this, unsigned int n)
{
	cHashSet<cResourceTypeData *, char const *, cCaselessStringHashFuncs> *v2; // ST14_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, n);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A7FF8: using guessed type int (__stdcall *cHashSet_cResourceTypeData __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008DEFB0) --------------------------------------------------------
void __thiscall cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>(cHashSet<cResourceTypeData *, char const *, cCaselessStringHashFuncs> *this, cHashSet<cResourceTypeData *, char const *, cCaselessStringHashFuncs> *__formal)
{
	cHashSet<cResourceTypeData *, char const *, cCaselessStringHashFuncs> *v2; // ST04_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, &this->baseclass_0);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A7FF8: using guessed type int (__stdcall *cHashSet_cResourceTypeData __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008DEFE0) --------------------------------------------------------
void __thiscall cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>(cHashSet<cResourceName *, char const *, cCaselessStringHashFuncs> *this, unsigned int n)
{
	cHashSet<cResourceName *, char const *, cCaselessStringHashFuncs> *v2; // ST14_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, n);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A8018: using guessed type int (__stdcall *cHashSet_cResourceName __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008DF050) --------------------------------------------------------
void __thiscall cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>(cHashSet<cResourceName *, char const *, cCaselessStringHashFuncs> *this, cHashSet<cResourceName *, char const *, cCaselessStringHashFuncs> *__formal)
{
	cHashSet<cResourceName *, char const *, cCaselessStringHashFuncs> *v2; // ST04_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, &this->baseclass_0);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A8018: using guessed type int (__stdcall *cHashSet_cResourceName __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008DF080) --------------------------------------------------------
void __thiscall cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>(cHashSet<cResTypeData *, char const *, cCaselessStringHashFuncs> *this, unsigned int n)
{
	cHashSet<cResTypeData *, char const *, cCaselessStringHashFuncs> *v2; // ST14_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, n);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A8038: using guessed type int (__stdcall *cHashSet_cResTypeData __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008DF0F0) --------------------------------------------------------
void __thiscall cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>(cHashSet<cResTypeData *, char const *, cCaselessStringHashFuncs> *this, cHashSet<cResTypeData *, char const *, cCaselessStringHashFuncs> *__formal)
{
	cHashSet<cResTypeData *, char const *, cCaselessStringHashFuncs> *v2; // ST04_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, &this->baseclass_0);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A8038: using guessed type int (__stdcall *cHashSet_cResTypeData __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008DF120) --------------------------------------------------------
void __thiscall cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>(cHashSet<cNamedResType *, char const *, cCaselessStringHashFuncs> *this, unsigned int n)
{
	cHashSet<cNamedResType *, char const *, cCaselessStringHashFuncs> *v2; // ST14_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, n);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A8058: using guessed type int (__stdcall *cHashSet_cNamedResType __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008DF190) --------------------------------------------------------
void __thiscall cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>(cHashSet<cNamedResType *, char const *, cCaselessStringHashFuncs> *this, cHashSet<cNamedResType *, char const *, cCaselessStringHashFuncs> *__formal)
{
	cHashSet<cNamedResType *, char const *, cCaselessStringHashFuncs> *v2; // ST04_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, &this->baseclass_0);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A8058: using guessed type int (__stdcall *cHashSet_cNamedResType __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008DF1C0) --------------------------------------------------------
void __thiscall cHashSet<cFactoryEntry___char_const___cHashFunctions>::cHashSet<cFactoryEntry___char_const___cHashFunctions>(cHashSet<cFactoryEntry *, char const *, cHashFunctions> *this, unsigned int n)
{
	cHashSet<cFactoryEntry *, char const *, cHashFunctions> *v2; // ST14_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, n);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cFactoryEntry___char_const___cHashFunctions>::_vftable_;
}
// 9A8078: using guessed type int (__stdcall *cHashSet_cFactoryEntry __char const __cHashFunctions____vftable_)(int __flags);

//----- (008DF230) --------------------------------------------------------
void __thiscall cHashSet<cFactoryEntry___char_const___cHashFunctions>::cHashSet<cFactoryEntry___char_const___cHashFunctions>(cHashSet<cFactoryEntry *, char const *, cHashFunctions> *this, cHashSet<cFactoryEntry *, char const *, cHashFunctions> *__formal)
{
	cHashSet<cFactoryEntry *, char const *, cHashFunctions> *v2; // ST04_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, &this->baseclass_0);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cFactoryEntry___char_const___cHashFunctions>::_vftable_;
}
// 9A8078: using guessed type int (__stdcall *cHashSet_cFactoryEntry __char const __cHashFunctions____vftable_)(int __flags);

//----- (008DF260) --------------------------------------------------------
void *__thiscall cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::_vector_deleting_destructor_(cHashSet<cNamedStatsData *, char const *, cCaselessStringHashFuncs> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::_cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DF290) --------------------------------------------------------
void *__thiscall cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::_scalar_deleting_destructor_(cHashSet<cResourceTypeData *, char const *, cCaselessStringHashFuncs> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::_cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DF2C0) --------------------------------------------------------
void *__thiscall cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::_vector_deleting_destructor_(cHashSet<cResourceName *, char const *, cCaselessStringHashFuncs> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::_cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DF2F0) --------------------------------------------------------
void *__thiscall cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::_vector_deleting_destructor_(cHashSet<cResTypeData *, char const *, cCaselessStringHashFuncs> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::_cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DF320) --------------------------------------------------------
void *__thiscall cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::_vector_deleting_destructor_(cHashSet<cNamedResType *, char const *, cCaselessStringHashFuncs> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::_cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DF350) --------------------------------------------------------
void *__thiscall cHashSet<cFactoryEntry___char_const___cHashFunctions>::_vector_deleting_destructor_(cHashSet<cFactoryEntry *, char const *, cHashFunctions> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cHashSet<cFactoryEntry___char_const___cHashFunctions>::_cHashSet<cFactoryEntry___char_const___cHashFunctions>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008DF380) --------------------------------------------------------
int __thiscall cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::IsEqual(cHashSet<cNamedStatsData *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k1, tHashSetKey__ *k2)
{
	return cCaselessStringHashFuncs::IsEqual((const char *)k1, (const char *)k2);
}

//----- (008DF3A0) --------------------------------------------------------
unsigned int __thiscall cHashSet<cNamedStatsData___char_const___cCaselessStringHashFuncs>::Hash(cHashSet<cNamedStatsData *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k)
{
	return cCaselessStringHashFuncs::Hash((const char *)k);
}

//----- (008DF3C0) --------------------------------------------------------
cResourceTypeData *__thiscall cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::Search(cHashSet<cResourceTypeData *, char const *, cCaselessStringHashFuncs> *this, const char *key)
{
	return (cResourceTypeData *)cHashSetBase::Search(&this->baseclass_0, (tHashSetKey__ *)key);
}

//----- (008DF3E0) --------------------------------------------------------
cResourceTypeData *__thiscall cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::Remove(cHashSet<cResourceTypeData *, char const *, cCaselessStringHashFuncs> *this, cResourceTypeData *node)
{
	return (cResourceTypeData *)cHashSetBase::Remove(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008DF400) --------------------------------------------------------
cResourceTypeData *__thiscall cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::GetFirst(cHashSet<cResourceTypeData *, char const *, cCaselessStringHashFuncs> *this, tHashSetHandle *Handle)
{
	return (cResourceTypeData *)cHashSetBase::GetFirst(&this->baseclass_0, Handle);
}

//----- (008DF420) --------------------------------------------------------
cResourceTypeData *__thiscall cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::GetNext(cHashSet<cResourceTypeData *, char const *, cCaselessStringHashFuncs> *this, tHashSetHandle *Handle)
{
	return (cResourceTypeData *)cHashSetBase::GetNext(&this->baseclass_0, Handle);
}

//----- (008DF440) --------------------------------------------------------
int __thiscall cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::IsEqual(cHashSet<cResourceTypeData *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k1, tHashSetKey__ *k2)
{
	return cCaselessStringHashFuncs::IsEqual((const char *)k1, (const char *)k2);
}

//----- (008DF460) --------------------------------------------------------
unsigned int __thiscall cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::Hash(cHashSet<cResourceTypeData *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k)
{
	return cCaselessStringHashFuncs::Hash((const char *)k);
}

//----- (008DF480) --------------------------------------------------------
cResourceName *__thiscall cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::Search(cHashSet<cResourceName *, char const *, cCaselessStringHashFuncs> *this, const char *key)
{
	return (cResourceName *)cHashSetBase::Search(&this->baseclass_0, (tHashSetKey__ *)key);
}

//----- (008DF4A0) --------------------------------------------------------
cResourceName *__thiscall cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::GetFirst(cHashSet<cResourceName *, char const *, cCaselessStringHashFuncs> *this, tHashSetHandle *Handle)
{
	return (cResourceName *)cHashSetBase::GetFirst(&this->baseclass_0, Handle);
}

//----- (008DF4C0) --------------------------------------------------------
cResourceName *__thiscall cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::GetNext(cHashSet<cResourceName *, char const *, cCaselessStringHashFuncs> *this, tHashSetHandle *Handle)
{
	return (cResourceName *)cHashSetBase::GetNext(&this->baseclass_0, Handle);
}

//----- (008DF4E0) --------------------------------------------------------
int __thiscall cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::IsEqual(cHashSet<cResourceName *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k1, tHashSetKey__ *k2)
{
	return cCaselessStringHashFuncs::IsEqual((const char *)k1, (const char *)k2);
}

//----- (008DF500) --------------------------------------------------------
unsigned int __thiscall cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::Hash(cHashSet<cResourceName *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k)
{
	return cCaselessStringHashFuncs::Hash((const char *)k);
}

//----- (008DF520) --------------------------------------------------------
int __thiscall cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::IsEqual(cHashSet<cResTypeData *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k1, tHashSetKey__ *k2)
{
	return cCaselessStringHashFuncs::IsEqual((const char *)k1, (const char *)k2);
}

//----- (008DF540) --------------------------------------------------------
unsigned int __thiscall cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::Hash(cHashSet<cResTypeData *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k)
{
	return cCaselessStringHashFuncs::Hash((const char *)k);
}

//----- (008DF560) --------------------------------------------------------
cNamedResType *__thiscall cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::Insert(cHashSet<cNamedResType *, char const *, cCaselessStringHashFuncs> *this, cNamedResType *node)
{
	return (cNamedResType *)cHashSetBase::Insert(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008DF580) --------------------------------------------------------
cNamedResType *__thiscall cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::Search(cHashSet<cNamedResType *, char const *, cCaselessStringHashFuncs> *this, const char *key)
{
	return (cNamedResType *)cHashSetBase::Search(&this->baseclass_0, (tHashSetKey__ *)key);
}

//----- (008DF5A0) --------------------------------------------------------
cNamedResType *__thiscall cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::Remove(cHashSet<cNamedResType *, char const *, cCaselessStringHashFuncs> *this, cNamedResType *node)
{
	return (cNamedResType *)cHashSetBase::Remove(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008DF5C0) --------------------------------------------------------
int __thiscall cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::IsEqual(cHashSet<cNamedResType *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k1, tHashSetKey__ *k2)
{
	return cCaselessStringHashFuncs::IsEqual((const char *)k1, (const char *)k2);
}

//----- (008DF5E0) --------------------------------------------------------
unsigned int __thiscall cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::Hash(cHashSet<cNamedResType *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k)
{
	return cCaselessStringHashFuncs::Hash((const char *)k);
}

//----- (008DF600) --------------------------------------------------------
int __thiscall cHashSet<cFactoryEntry___char_const___cHashFunctions>::IsEqual(cHashSet<cFactoryEntry *, char const *, cHashFunctions> *this, tHashSetKey__ *k1, tHashSetKey__ *k2)
{
	return cHashFunctions::IsEqual((const char *)k1, (const char *)k2);
}

//----- (008DF620) --------------------------------------------------------
unsigned int __thiscall cHashSet<cFactoryEntry___char_const___cHashFunctions>::Hash(cHashSet<cFactoryEntry *, char const *, cHashFunctions> *this, tHashSetKey__ *k)
{
	return cHashFunctions::Hash((const char *)k);
}

//----- (008DF640) --------------------------------------------------------
char **__thiscall cDABase<char___4_cDARawSrvFns<char__>>::operator__(cDABase<char *, 4, cDARawSrvFns<char *> > *this, int index)
{
	const char *v2; // eax@2
	cDABase<char *, 4, cDARawSrvFns<char *> > *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (index >= this->m_nItems)
	{
		v2 = _LogFmt("Index %d out of range");
		_CriticalMsg(v2, "x:\\prj\\tech\\h\\dynarray.h", 0x17Bu);
	}
	return &thisa->m_pItems[index];
}

//----- (008DF690) --------------------------------------------------------
unsigned int __thiscall cDABase<char___4_cDARawSrvFns<char__>>::Size(cDABase<char *, 4, cDARawSrvFns<char *> > *this)
{
	return this->m_nItems;
}


















//----- (008E0930) --------------------------------------------------------
void __cdecl ImageHackAutoSetTransparency(grs_bitmap *pBm, char mip)
{
	char v2; // [sp+0h] [bp-18h]@1
	char *v3; // [sp+8h] [bp-10h]@10
	char *pBits; // [sp+10h] [bp-8h]@4
	int flag; // [sp+14h] [bp-4h]@1

	flag = 0;
	v2 = pBm->type;
	if (v2 == 2)
	{
		pBits = &pBm->bits[pBm->h * pBm->w];
		while (1)
		{
			--pBits;
			if (pBits < pBm->bits)
				break;
			if (!*pBits)
			{
				flag = 1;
				break;
			}
		}
	}
	else
	{
		if (v2 == 3)
		{
			v3 = &pBm->bits[2 * pBm->h * pBm->w];
			while (1)
			{
				v3 -= 2;
				if (v3 < pBm->bits)
					break;
				if (*(_WORD *)v3 == gResImageChromaKey)
				{
					flag = 1;
					break;
				}
			}
		}
	}
	if (flag)
	{
		if (mip)
			FlagsOrMip(pBm, flag);
		else
			pBm->flags |= flag;
	}
}
// EAC7C8: using guessed type unsigned __int16 gResImageChromaKey;

//----- (008E0A32) --------------------------------------------------------
void __cdecl FlagsOrMip(grs_bitmap *pBm, int flag)
{
	while (1)
	{
		pBm->flags |= flag;
		if (pBm->w == 1)
		{
			if (pBm->h == 1)
				break;
		}
		++pBm;
	}
}

//----- (008E0A77) --------------------------------------------------------
void __cdecl ImageHackRemap16Bit(grs_bitmap *pBm, char mip)
{
	char *pStart; // [sp+0h] [bp-Ch]@8
	signed int format16; // [sp+4h] [bp-8h]@2
	int pBits; // [sp+8h] [bp-4h]@8

	if (pBm->type == 3)
	{
		format16 = gResImageFlat16Format;
		if (!gResImageFlat16Format && (signed int)(unsigned __int8)byte_B1CC48[12 * grd_mode] > 8)
			format16 = byte_B1CC48[12 * grd_mode] != 15 ? 1024 : 768;
		if (format16 && !(pBm->flags & (unsigned __int16)format16 & 0x700))
		{
			pStart = pBm->bits;
			pBits = (int)&pBm->bits[2 * pBm->h * pBm->w];
			if (mip)
				pBits = (int)&pStart[md_sizeof_mipmap_bits(pBm)];
			if (pBm->flags & 0x400)
			{
				while (1)
				{
					pBits -= 2;
					if (pBits < (unsigned int)pStart)
						break;
					*(_WORD *)pBits = *(_WORD *)pBits & 0x1F | *(_WORD *)pBits & 0xFFE0;
					*(_WORD *)pBits = ((unsigned __int8)(*(_WORD *)pBits >> 8) >> 3 << 10) | *(_WORD *)pBits & 0x83FF;
					*(_WORD *)pBits = 32 * ((((*(_WORD *)pBits >> 5) & 0x3F) >> 1) & 0x1F) | *(_WORD *)pBits & 0xFC1F;
				}
			}
			else
			{
				while (1)
				{
					pBits -= 2;
					if (pBits < (unsigned int)pStart)
						break;
					*(_WORD *)pBits = *(_WORD *)pBits & 0x1F | *(_WORD *)pBits & 0xFFE0;
					*(_WORD *)pBits = (((*(_WORD *)pBits >> 10) & 0x1F) << 11) | *(_WORD *)pBits & 0x7FF;
					*(_WORD *)pBits = 32 * (63 * ((*(_WORD *)pBits >> 5) & 0x1F) / 31 & 0x3F) | *(_WORD *)pBits & 0xF81F;
				}
			}
			if (mip)
				FlagsXorMip(pBm, 1792);
			else
				pBm->flags ^= 0x700u;
		}
	}
}
// B1C7D0: using guessed type int grd_mode;
// EAC7CC: using guessed type unsigned __int32 gResImageFlat16Format;

//----- (008E0CC4) --------------------------------------------------------
void __cdecl FlagsXorMip(grs_bitmap *pBm, int flag)
{
	while (1)
	{
		pBm->flags ^= flag;
		if (pBm->w == 1)
		{
			if (pBm->h == 1)
				break;
		}
		++pBm;
	}
}

//----- (008E16C5) --------------------------------------------------------
void __thiscall cInstalledResTypeByName::cInstalledResTypeByName(cInstalledResTypeByName *this)
{
	cInstalledResTypeByName *v1; // ST04_4@1

	v1 = this;
	cStrIHashSet<cNamedResType__>::cStrIHashSet<cNamedResType__>(&this->baseclass_0, 0x65u);
	v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cInstalledResTypeByName::_vftable_;
}
// 9A81FC: using guessed type int (__stdcall *cInstalledResTypeByName___vftable_)(int __flags);

//----- (008E16E6) --------------------------------------------------------
void __thiscall cInstalledResTypeByName::_cInstalledResTypeByName(cInstalledResTypeByName *this)
{
	cStrIHashSet<cNamedResType *> *v1; // ST00_4@1

	v1 = (cStrIHashSet<cNamedResType *> *)this;
	this->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cInstalledResTypeByName::_vftable_;
	cHashSet<cNamedResType___char_const___cCaselessStringHashFuncs>::DestroyAll(&this->baseclass_0.baseclass_0);
	cStrIHashSet<cNamedResType__>::_cStrIHashSet<cNamedResType__>(v1);
}
// 9A81FC: using guessed type int (__stdcall *cInstalledResTypeByName___vftable_)(int __flags);

//----- (008E170A) --------------------------------------------------------
tHashSetKey__ *__thiscall cInstalledResTypeByName::GetKey(cInstalledResTypeByName *this, tHashSetNode__ *node)
{
	return (tHashSetKey__ *)(*(int(__stdcall **)(_DWORD))(*(_DWORD *)node->unused + 12))(node->unused);
}

//----- (008E1730) --------------------------------------------------------
void *__thiscall cHashByResourceType::_scalar_deleting_destructor_(cHashByResourceType *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cHashByResourceType::_cHashByResourceType(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E1760) --------------------------------------------------------
void *__thiscall cDynArray<char__>::_scalar_deleting_destructor_(cDynArray<char *> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cDynArray<char__>::_cDynArray<char__>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E1790) --------------------------------------------------------
void *__thiscall cResourceData::_scalar_deleting_destructor_(cResourceData *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cResourceData::_cResourceData(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E17C0) --------------------------------------------------------
void __thiscall cDynArray<char__>::_cDynArray<char__>(cDynArray<char *> *this)
{
	cDynArray_<char___4>::_cDynArray_<char___4>(&this->baseclass_0);
}

//----- (008E17E0) --------------------------------------------------------
void __thiscall cDynArray_<char___4>::_cDynArray_<char___4>(cDynArray_<char *, 4> *this)
{
	cDABase<char___4_cDARawSrvFns<char__>>::_cDABase<char___4_cDARawSrvFns<char__>>(&this->baseclass_0);
}

//----- (008E1800) --------------------------------------------------------
void *__thiscall cHashByResName::_vector_deleting_destructor_(cHashByResName *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cHashByResName::_cHashByResName(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E1830) --------------------------------------------------------
void *__thiscall cInstalledResTypeHash::_scalar_deleting_destructor_(cInstalledResTypeHash *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cInstalledResTypeHash::_cInstalledResTypeHash(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E1860) --------------------------------------------------------
void *__thiscall cInstalledResTypeByName::_scalar_deleting_destructor_(cInstalledResTypeByName *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cInstalledResTypeByName::_cInstalledResTypeByName(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E1890) --------------------------------------------------------
void __thiscall cDynArray<char__>::cDynArray<char__>(cDynArray<char *> *this)
{
	cDynArray_<char___4>::cDynArray_<char___4>(&this->baseclass_0);
}

//----- (008E18B0) --------------------------------------------------------
void __thiscall cDynArray_<char___4>::cDynArray_<char___4>(cDynArray_<char *, 4> *this)
{
	cDABase<char___4_cDARawSrvFns<char__>>::cDABase<char___4_cDARawSrvFns<char__>>(&this->baseclass_0);
}

//----- (008E18D0) --------------------------------------------------------
cResourceName *__thiscall cHashSet<cResourceName___char_const___cCaselessStringHashFuncs>::Insert(cHashSet<cResourceName *, char const *, cCaselessStringHashFuncs> *this, cResourceName *node)
{
	return (cResourceName *)cHashSetBase::Insert(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008E18F0) --------------------------------------------------------
void __thiscall cDABase<char___4_cDARawSrvFns<char__>>::cDABase<char___4_cDARawSrvFns<char__>>(cDABase<char *, 4, cDARawSrvFns<char *> > *this)
{
	this->m_pItems = 0;
	this->m_nItems = 0;
	cDABaseSrvFns::TrackCreate(4u);
}

//----- (008E1920) --------------------------------------------------------
void __thiscall cDABase<char___4_cDARawSrvFns<char__>>::_cDABase<char___4_cDARawSrvFns<char__>>(cDABase<char *, 4, cDARawSrvFns<char *> > *this)
{
	cDABase<char *, 4, cDARawSrvFns<char *> > *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cDABaseSrvFns::TrackDestroy();
	if (thisa->m_pItems)
	{
		cDARawSrvFns<char__>::PreSetSize(thisa->m_pItems, thisa->m_nItems, 0);
		cDABaseSrvFns::DoResize((void **)&thisa->m_pItems, 4u, 0);
	}
}

//----- (008E1960) --------------------------------------------------------
unsigned int __thiscall cDABase<char___4_cDARawSrvFns<char__>>::Append(cDABase<char *, 4, cDARawSrvFns<char *> > *this, char *const *item)
{
	cDABase<char *, 4, cDARawSrvFns<char *> > *v2; // ST08_4@1
	unsigned int v3; // ST0C_4@1

	v2 = this;
	cDABase<char___4_cDARawSrvFns<char__>>::Resize(this, this->m_nItems + 1);
	v3 = v2->m_nItems++;
	cDARawSrvFns<char__>::ConstructItem(&v2->m_pItems[v3], item);
	return cDABase<char___4_cDARawSrvFns<char__>>::Size(v2) - 1;
}

//----- (008E19C0) --------------------------------------------------------
void __cdecl cDARawSrvFns<char__>::PreSetSize(char **__formal, unsigned int a2, unsigned int a3)
{
	;
}

//----- (008E19D0) --------------------------------------------------------
void __cdecl cDARawSrvFns<char__>::ConstructItem(char **pItem, char *const *pFrom)
{
	memcpy(pItem, pFrom, 4u);
}

//----- (008E19F0) --------------------------------------------------------
int __thiscall cDABase<char___4_cDARawSrvFns<char__>>::Resize(cDABase<char *, 4, cDARawSrvFns<char *> > *this, unsigned int newSlotCount)
{
	int result; // eax@2
	unsigned int evenSlots; // [sp+8h] [bp-4h]@1

	evenSlots = (newSlotCount + 3) & 0xFFFFFFFC;
	if (((this->m_nItems + 3) & 0xFFFFFFFC) == evenSlots)
		result = 1;
	else
		result = cDABaseSrvFns::DoResize((void **)&this->m_pItems, 4u, evenSlots);
	return result;
}




//----- (008E2550) --------------------------------------------------------
cResourceTypeData *__thiscall cHashSet<cResourceTypeData___char_const___cCaselessStringHashFuncs>::Insert(cHashSet<cResourceTypeData *, char const *, cCaselessStringHashFuncs> *this, cResourceTypeData *node)
{
	return (cResourceTypeData *)cHashSetBase::Insert(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008E2570) --------------------------------------------------------
cResTypeData *__thiscall cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::Insert(cHashSet<cResTypeData *, char const *, cCaselessStringHashFuncs> *this, cResTypeData *node)
{
	return (cResTypeData *)cHashSetBase::Insert(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008E2590) --------------------------------------------------------
cResTypeData *__thiscall cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::Search(cHashSet<cResTypeData *, char const *, cCaselessStringHashFuncs> *this, const char *key)
{
	return (cResTypeData *)cHashSetBase::Search(&this->baseclass_0, (tHashSetKey__ *)key);
}

//----- (008E25B0) --------------------------------------------------------
cResTypeData *__thiscall cHashSet<cResTypeData___char_const___cCaselessStringHashFuncs>::Remove(cHashSet<cResTypeData *, char const *, cCaselessStringHashFuncs> *this, cResTypeData *node)
{
	return (cResTypeData *)cHashSetBase::Remove(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008E25D0) --------------------------------------------------------
int __cdecl _E6_56()
{
	_E3_50();
	return _E5_39();
}


//----- (008E3AB0) --------------------------------------------------------
unsigned int __cdecl cHashFunctions::Hash(const void *p)
{
	return HashPtr(p);
}

//----- (008E3AC0) --------------------------------------------------------
void *__thiscall cNamedStatsData::_scalar_deleting_destructor_(cNamedStatsData *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cNamedStatsData::_cNamedStatsData(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E3AF0) --------------------------------------------------------
void *__thiscall cResourceName::_scalar_deleting_destructor_(cResourceName *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cResourceName::_cResourceName(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E3B20) --------------------------------------------------------
void *__thiscall cResTypeData::_scalar_deleting_destructor_(cResTypeData *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cResTypeData::_cResTypeData(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}



//----- (008E4790) --------------------------------------------------------
void __thiscall IStoreFactory::IStoreFactory(IStoreFactory *this)
{
	IStoreFactory *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)IStoreFactory::_vftable_;
}
// 9A82C4: using guessed type int (*IStoreFactory___vftable_[5])();

//----- (008E47B0) --------------------------------------------------------
void __thiscall cStrIHashSet<cNamedStorage__>::cStrIHashSet<cNamedStorage__>(cStrIHashSet<cNamedStorage *> *this, unsigned int n)
{
	cStrIHashSet<cNamedStorage *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		n);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<cNamedStorage__>::_vftable_;
}
// 9A82D8: using guessed type int (__stdcall *cStrIHashSet_cNamedStorage _____vftable_)(int __flags);

//----- (008E47E0) --------------------------------------------------------
void __thiscall cStrIHashSet<cNamedStorage__>::cStrIHashSet<cNamedStorage__>(cStrIHashSet<cNamedStorage *> *this, cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *__formal)
{
	cStrIHashSet<cNamedStorage *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		&this->baseclass_0);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<cNamedStorage__>::_vftable_;
}
// 9A82D8: using guessed type int (__stdcall *cStrIHashSet_cNamedStorage _____vftable_)(int __flags);

//----- (008E4810) --------------------------------------------------------
void __thiscall cStrIHashSet<cNamedStream__>::cStrIHashSet<cNamedStream__>(cStrIHashSet<cNamedStream *> *this, unsigned int n)
{
	cStrIHashSet<cNamedStream *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		n);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<cNamedStream__>::_vftable_;
}
// 9A82F8: using guessed type int (__stdcall *cStrIHashSet_cNamedStream _____vftable_)(int __flags);

//----- (008E4840) --------------------------------------------------------
void __thiscall cStrIHashSet<cNamedStream__>::cStrIHashSet<cNamedStream__>(cStrIHashSet<cNamedStream *> *this, cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> *__formal)
{
	cStrIHashSet<cNamedStream *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		&this->baseclass_0);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<cNamedStream__>::_vftable_;
}
// 9A82F8: using guessed type int (__stdcall *cStrIHashSet_cNamedStream _____vftable_)(int __flags);

//----- (008E4870) --------------------------------------------------------
void *__thiscall cStrIHashSet<cNamedStorage__>::_scalar_deleting_destructor_(cStrIHashSet<cNamedStorage *> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStrIHashSet<cNamedStorage__>::_cStrIHashSet<cNamedStorage__>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E48A0) --------------------------------------------------------
void *__thiscall cStrIHashSet<cNamedStream__>::_scalar_deleting_destructor_(cStrIHashSet<cNamedStream *> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStrIHashSet<cNamedStream__>::_cStrIHashSet<cNamedStream__>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E48D0) --------------------------------------------------------
void __thiscall cStrIHashSet<cNamedStorage__>::_cStrIHashSet<cNamedStorage__>(cStrIHashSet<cNamedStorage *> *this)
{
	cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::_cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>(&this->baseclass_0);
}

//----- (008E48F0) --------------------------------------------------------
void __thiscall cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::_cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSetBase::_cHashSetBase(&this->baseclass_0);
}

//----- (008E4910) --------------------------------------------------------
void __thiscall cStrIHashSet<cNamedStream__>::_cStrIHashSet<cNamedStream__>(cStrIHashSet<cNamedStream *> *this)
{
	cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::_cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>(&this->baseclass_0);
}

//----- (008E4930) --------------------------------------------------------
void __thiscall cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::_cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>(cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSetBase::_cHashSetBase(&this->baseclass_0);
}

//----- (008E4950) --------------------------------------------------------
void __thiscall cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *this, unsigned int n)
{
	cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *v2; // ST14_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, n);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A8318: using guessed type int (__stdcall *cHashSet_cNamedStorage __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008E49C0) --------------------------------------------------------
void __thiscall cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *this, cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *__formal)
{
	cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *v2; // ST04_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, &this->baseclass_0);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A8318: using guessed type int (__stdcall *cHashSet_cNamedStorage __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008E49F0) --------------------------------------------------------
void __thiscall cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>(cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> *this, unsigned int n)
{
	cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> *v2; // ST14_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, n);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A8338: using guessed type int (__stdcall *cHashSet_cNamedStream __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008E4A60) --------------------------------------------------------
void __thiscall cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>(cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> *this, cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> *__formal)
{
	cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> *v2; // ST04_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, &this->baseclass_0);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A8338: using guessed type int (__stdcall *cHashSet_cNamedStream __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008E4A90) --------------------------------------------------------
void *__thiscall cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::_scalar_deleting_destructor_(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::_cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E4AC0) --------------------------------------------------------
void *__thiscall cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::_scalar_deleting_destructor_(cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::_cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E4AF0) --------------------------------------------------------
int __thiscall cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::IsEqual(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k1, tHashSetKey__ *k2)
{
	return cCaselessStringHashFuncs::IsEqual((const char *)k1, (const char *)k2);
}

//----- (008E4B10) --------------------------------------------------------
unsigned int __thiscall cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::Hash(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k)
{
	return cCaselessStringHashFuncs::Hash((const char *)k);
}

//----- (008E4B30) --------------------------------------------------------
int __thiscall cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::IsEqual(cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k1, tHashSetKey__ *k2)
{
	return cCaselessStringHashFuncs::IsEqual((const char *)k1, (const char *)k2);
}

//----- (008E4B50) --------------------------------------------------------
unsigned int __thiscall cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::Hash(cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k)
{
	return cCaselessStringHashFuncs::Hash((const char *)k);
}


//----- (008E5630) --------------------------------------------------------
void *__thiscall cFactoryEntry::_scalar_deleting_destructor_(cFactoryEntry *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cFactoryEntry::_cFactoryEntry(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E5660) --------------------------------------------------------
void __thiscall cStrIHashSet<cFoundStream__>::cStrIHashSet<cFoundStream__>(cStrIHashSet<cFoundStream *> *this, unsigned int n)
{
	cStrIHashSet<cFoundStream *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>::cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		n);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<cFoundStream__>::_vftable_;
}
// 9A83E8: using guessed type int (__stdcall *cStrIHashSet_cFoundStream _____vftable_)(int __flags);

//----- (008E5690) --------------------------------------------------------
void __thiscall cStrIHashSet<cFoundStream__>::cStrIHashSet<cFoundStream__>(cStrIHashSet<cFoundStream *> *this, cHashSet<cFoundStream *, char const *, cCaselessStringHashFuncs> *__formal)
{
	cStrIHashSet<cFoundStream *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>::cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		&this->baseclass_0);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<cFoundStream__>::_vftable_;
}
// 9A83E8: using guessed type int (__stdcall *cStrIHashSet_cFoundStream _____vftable_)(int __flags);

//----- (008E56C0) --------------------------------------------------------
void *__thiscall cStrIHashSet<cFoundStream__>::_scalar_deleting_destructor_(cStrIHashSet<cFoundStream *> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStrIHashSet<cFoundStream__>::_cStrIHashSet<cFoundStream__>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E56F0) --------------------------------------------------------
void __thiscall cStrIHashSet<cFoundStream__>::_cStrIHashSet<cFoundStream__>(cStrIHashSet<cFoundStream *> *this)
{
	cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>::_cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>(&this->baseclass_0);
}

//----- (008E5710) --------------------------------------------------------
void __thiscall cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>::_cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>(cHashSet<cFoundStream *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSetBase::_cHashSetBase(&this->baseclass_0);
}

//----- (008E5730) --------------------------------------------------------
void __thiscall cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>::cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>(cHashSet<cFoundStream *, char const *, cCaselessStringHashFuncs> *this, unsigned int n)
{
	cHashSet<cFoundStream *, char const *, cCaselessStringHashFuncs> *v2; // ST14_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, n);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A8408: using guessed type int (__stdcall *cHashSet_cFoundStream __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008E57A0) --------------------------------------------------------
void __thiscall cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>::cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>(cHashSet<cFoundStream *, char const *, cCaselessStringHashFuncs> *this, cHashSet<cFoundStream *, char const *, cCaselessStringHashFuncs> *__formal)
{
	cHashSet<cFoundStream *, char const *, cCaselessStringHashFuncs> *v2; // ST04_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, &this->baseclass_0);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A8408: using guessed type int (__stdcall *cHashSet_cFoundStream __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008E57D0) --------------------------------------------------------
void *__thiscall cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>::_scalar_deleting_destructor_(cHashSet<cFoundStream *, char const *, cCaselessStringHashFuncs> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>::_cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E5800) --------------------------------------------------------
cFactoryEntry *__thiscall cHashSet<cFactoryEntry___char_const___cHashFunctions>::Insert(cHashSet<cFactoryEntry *, char const *, cHashFunctions> *this, cFactoryEntry *node)
{
	return (cFactoryEntry *)cHashSetBase::Insert(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008E5820) --------------------------------------------------------
cFactoryEntry *__thiscall cHashSet<cFactoryEntry___char_const___cHashFunctions>::Search(cHashSet<cFactoryEntry *, char const *, cHashFunctions> *this, const char *key)
{
	return (cFactoryEntry *)cHashSetBase::Search(&this->baseclass_0, (tHashSetKey__ *)key);
}

//----- (008E5840) --------------------------------------------------------
cFactoryEntry *__thiscall cHashSet<cFactoryEntry___char_const___cHashFunctions>::Remove(cHashSet<cFactoryEntry *, char const *, cHashFunctions> *this, cFactoryEntry *node)
{
	return (cFactoryEntry *)cHashSetBase::Remove(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008E5860) --------------------------------------------------------
cFactoryEntry *__thiscall cHashSet<cFactoryEntry___char_const___cHashFunctions>::GetFirst(cHashSet<cFactoryEntry *, char const *, cHashFunctions> *this, tHashSetHandle *Handle)
{
	return (cFactoryEntry *)cHashSetBase::GetFirst(&this->baseclass_0, Handle);
}

//----- (008E5880) --------------------------------------------------------
cFactoryEntry *__thiscall cHashSet<cFactoryEntry___char_const___cHashFunctions>::GetNext(cHashSet<cFactoryEntry *, char const *, cHashFunctions> *this, tHashSetHandle *Handle)
{
	return (cFactoryEntry *)cHashSetBase::GetNext(&this->baseclass_0, Handle);
}

//----- (008E58A0) --------------------------------------------------------
int __thiscall cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>::IsEqual(cHashSet<cFoundStream *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k1, tHashSetKey__ *k2)
{
	return cCaselessStringHashFuncs::IsEqual((const char *)k1, (const char *)k2);
}

//----- (008E58C0) --------------------------------------------------------
unsigned int __thiscall cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>::Hash(cHashSet<cFoundStream *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k)
{
	return cCaselessStringHashFuncs::Hash((const char *)k);
}




//----- (008E70E0) --------------------------------------------------------
void __thiscall cHashSet<cFactoryEntry___char_const___cHashFunctions>::DestroyAll(cHashSet<cFactoryEntry *, char const *, cHashFunctions> *this)
{
	cHashSet<cFactoryEntry *, char const *, cHashFunctions> *thisa; // [sp+4h] [bp-1Ch]@1
	sHashSetChunk *pNext; // [sp+14h] [bp-Ch]@6
	sHashSetChunk *p; // [sp+18h] [bp-8h]@4
	unsigned int i; // [sp+1Ch] [bp-4h]@2

	thisa = this;
	if (this->baseclass_0.m_nItems)
	{
		for (i = 0; i < thisa->baseclass_0.m_nPts; ++i)
		{
			for (p = thisa->baseclass_0.m_Table[i]; p; p = pNext)
			{
				pNext = p->pNext;
				if (p->node)
					cFactoryEntry::_scalar_deleting_destructor_((cFactoryEntry *)p->node, 1u);
				sHashSetChunk::operator delete(p, 8u);
			}
			thisa->baseclass_0.m_Table[i] = 0;
		}
		thisa->baseclass_0.m_nItems = 0;
	}
}

//----- (008E71A0) --------------------------------------------------------
void __thiscall cHashSet<cFoundStream___char_const___cCaselessStringHashFuncs>::DestroyAll(cHashSet<cFoundStream *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSet<cFoundStream *, char const *, cCaselessStringHashFuncs> *thisa; // [sp+4h] [bp-1Ch]@1
	sHashSetChunk *pNext; // [sp+14h] [bp-Ch]@6
	sHashSetChunk *p; // [sp+18h] [bp-8h]@4
	unsigned int i; // [sp+1Ch] [bp-4h]@2

	thisa = this;
	if (this->baseclass_0.m_nItems)
	{
		for (i = 0; i < thisa->baseclass_0.m_nPts; ++i)
		{
			for (p = thisa->baseclass_0.m_Table[i]; p; p = pNext)
			{
				pNext = p->pNext;
				if (p->node)
					cFoundStream::_scalar_deleting_destructor_((cFoundStream *)p->node, 1u);
				sHashSetChunk::operator delete(p, 8u);
			}
			thisa->baseclass_0.m_Table[i] = 0;
		}
		thisa->baseclass_0.m_nItems = 0;
	}
}

//----- (008E7260) --------------------------------------------------------
void __thiscall cHashSet<cNamedStorage___char_const___cCaselessStringHashFuncs>::DestroyAll(cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSet<cNamedStorage *, char const *, cCaselessStringHashFuncs> *thisa; // [sp+4h] [bp-1Ch]@1
	sHashSetChunk *pNext; // [sp+14h] [bp-Ch]@6
	sHashSetChunk *p; // [sp+18h] [bp-8h]@4
	unsigned int i; // [sp+1Ch] [bp-4h]@2

	thisa = this;
	if (this->baseclass_0.m_nItems)
	{
		for (i = 0; i < thisa->baseclass_0.m_nPts; ++i)
		{
			for (p = thisa->baseclass_0.m_Table[i]; p; p = pNext)
			{
				pNext = p->pNext;
				if (p->node)
					cNamedStorage::_scalar_deleting_destructor_((cNamedStorage *)p->node, 1u);
				sHashSetChunk::operator delete(p, 8u);
			}
			thisa->baseclass_0.m_Table[i] = 0;
		}
		thisa->baseclass_0.m_nItems = 0;
	}
}

//----- (008E7320) --------------------------------------------------------
cNamedStream *__thiscall cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::Insert(cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> *this, cNamedStream *node)
{
	return (cNamedStream *)cHashSetBase::Insert(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008E7340) --------------------------------------------------------
cNamedStream *__thiscall cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::Search(cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> *this, const char *key)
{
	return (cNamedStream *)cHashSetBase::Search(&this->baseclass_0, (tHashSetKey__ *)key);
}

//----- (008E7360) --------------------------------------------------------
void __thiscall cHashSet<cNamedStream___char_const___cCaselessStringHashFuncs>::DestroyAll(cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSet<cNamedStream *, char const *, cCaselessStringHashFuncs> *thisa; // [sp+4h] [bp-1Ch]@1
	sHashSetChunk *pNext; // [sp+14h] [bp-Ch]@6
	sHashSetChunk *p; // [sp+18h] [bp-8h]@4
	unsigned int i; // [sp+1Ch] [bp-4h]@2

	thisa = this;
	if (this->baseclass_0.m_nItems)
	{
		for (i = 0; i < thisa->baseclass_0.m_nPts; ++i)
		{
			for (p = thisa->baseclass_0.m_Table[i]; p; p = pNext)
			{
				pNext = p->pNext;
				if (p->node)
					cNamedStream::_scalar_deleting_destructor_((cNamedStream *)p->node, 1u);
				sHashSetChunk::operator delete(p, 8u);
			}
			thisa->baseclass_0.m_Table[i] = 0;
		}
		thisa->baseclass_0.m_nItems = 0;
	}
}

//----- (008E7420) --------------------------------------------------------
void __thiscall cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>(cDABase<sSearchPathElement, 4, cDARawSrvFns<sSearchPathElement> > *this)
{
	this->m_pItems = 0;
	this->m_nItems = 0;
	cDABaseSrvFns::TrackCreate(8u);
}

//----- (008E7450) --------------------------------------------------------
void __thiscall cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::_cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>(cDABase<sSearchPathElement, 4, cDARawSrvFns<sSearchPathElement> > *this)
{
	cDABase<sSearchPathElement, 4, cDARawSrvFns<sSearchPathElement> > *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cDABaseSrvFns::TrackDestroy();
	if (thisa->m_pItems)
	{
		cDARawSrvFns<sSearchPathElement>::PreSetSize(thisa->m_pItems, thisa->m_nItems, 0);
		cDABaseSrvFns::DoResize((void **)&thisa->m_pItems, 8u, 0);
	}
}

//----- (008E7490) --------------------------------------------------------
sSearchPathElement *__thiscall cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::operator__(cDABase<sSearchPathElement, 4, cDARawSrvFns<sSearchPathElement> > *this, int index)
{
	const char *v2; // eax@2
	cDABase<sSearchPathElement, 4, cDARawSrvFns<sSearchPathElement> > *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (index >= this->m_nItems)
	{
		v2 = _LogFmt("Index %d out of range");
		_CriticalMsg(v2, "x:\\prj\\tech\\h\\dynarray.h", 0x17Bu);
	}
	return &thisa->m_pItems[index];
}

//----- (008E74E0) --------------------------------------------------------
unsigned int __thiscall cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::Append(cDABase<sSearchPathElement, 4, cDARawSrvFns<sSearchPathElement> > *this, sSearchPathElement *item)
{
	cDABase<sSearchPathElement, 4, cDARawSrvFns<sSearchPathElement> > *v2; // ST08_4@1
	unsigned int v3; // ST0C_4@1

	v2 = this;
	cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::Resize(this, this->m_nItems + 1);
	v3 = v2->m_nItems++;
	cDARawSrvFns<sSearchPathElement>::ConstructItem(&v2->m_pItems[v3], item);
	return cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::Size(v2) - 1;
}

//----- (008E7540) --------------------------------------------------------
unsigned int __thiscall cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::Size(cDABase<sSearchPathElement, 4, cDARawSrvFns<sSearchPathElement> > *this)
{
	return this->m_nItems;
}

//----- (008E7560) --------------------------------------------------------
void *__thiscall cFoundStream::_scalar_deleting_destructor_(cFoundStream *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cFoundStream::_cFoundStream(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E7590) --------------------------------------------------------
void *__thiscall cNamedStorage::_scalar_deleting_destructor_(cNamedStorage *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cNamedStorage::_cNamedStorage(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E75C0) --------------------------------------------------------
void *__thiscall cNamedStream::_scalar_deleting_destructor_(cNamedStream *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cNamedStream::_cNamedStream(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E75F0) --------------------------------------------------------
void __cdecl cDARawSrvFns<sSearchPathElement>::PreSetSize(sSearchPathElement *__formal, unsigned int a2, unsigned int a3)
{
	;
}

//----- (008E7600) --------------------------------------------------------
void __cdecl cDARawSrvFns<sSearchPathElement>::ConstructItem(sSearchPathElement *pItem, sSearchPathElement *pFrom)
{
	memcpy(pItem, pFrom, 8u);
}

//----- (008E7620) --------------------------------------------------------
int __thiscall cDABase<sSearchPathElement_4_cDARawSrvFns<sSearchPathElement>>::Resize(cDABase<sSearchPathElement, 4, cDARawSrvFns<sSearchPathElement> > *this, unsigned int newSlotCount)
{
	int result; // eax@2
	unsigned int evenSlots; // [sp+8h] [bp-4h]@1

	evenSlots = (newSlotCount + 3) & 0xFFFFFFFC;
	if (((this->m_nItems + 3) & 0xFFFFFFFC) == evenSlots)
		result = 1;
	else
		result = cDABaseSrvFns::DoResize((void **)&this->m_pItems, 8u, evenSlots);
	return result;
}

//----- (008E7670) --------------------------------------------------------
void __thiscall cResourceBase<IRes___GUID_const_IID_IRes>::OnFinalRelease(cResourceBase<IRes, &IID_IRes> *this)
{
	;
}

//----- (008E7680) --------------------------------------------------------
unsigned int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::AddRef(cResourceBase<IRes, &IID_IRes> *this)
{
	return cCTRefCount::AddRef(&this->__m_ulRefs);
}

//----- (008E76A0) --------------------------------------------------------
unsigned int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::Release(cResourceBase<IRes, &IID_IRes> *this)
{
	unsigned int result; // eax@2

	if (cCTRefCount::Release(&this->__m_ulRefs))
	{
		result = cCTRefCount::operator unsigned_long(&this->__m_ulRefs);
	}
	else
	{
		((void(__thiscall *)(_DWORD))this->baseclass_0.lpVtbl[1].AddRef)(this);
		if (this)
			((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.lpVtbl[1].QueryInterface)(this, 1);
		result = 0;
	}
	return result;
}

//----- (008E7700) --------------------------------------------------------
void __thiscall cResourceBase<IRes___GUID_const_IID_IRes>::cResourceBase<IRes___GUID_const_IID_IRes>(cResourceBase<IRes, &IID_IRes> *this, IStore *pStore, const char *pName, IResType *pType)
{
	cResourceBase<IRes, &IID_IRes> *thisa; // [sp+0h] [bp-8h]@1
	IUnknown *pResMan; // [sp+4h] [bp-4h]@1

	thisa = this;
	IResHack::IResHack(&this->baseclass_0);
	IResControl::IResControl(&thisa->baseclass_4);
	IRes::IRes(&thisa->baseclass_8);
	thisa->m_ulRefs = 1;
	thisa->m_bAllowStorageReset = 1;
	thisa->m_pStore = 0;
	thisa->m_pCanonStore = 0;
	thisa->m_bDoingAsynch = 0;
	thisa->m_pName = 0;
	thisa->m_pExt = 0;
	thisa->m_pType = 0;
	thisa->m_AppData = -1;
	thisa->m_ManData = -1;
	thisa->m_pStream = 0;
	thisa->m_pAssignedData = 0;
	thisa->m_nAssignedCount = 0;
	cCTRefCount::cCTRefCount(&thisa->__m_ulRefs);
	thisa->baseclass_0.lpVtbl = (IResHackVtbl *)&cResourceBase<IRes___GUID_const_IID_IRes>::_vftable_;
	thisa->baseclass_4.baseclass_0.vfptr = (IUnknownVtbl *)&cResourceBase<IRes___GUID_const_IID_IRes>::_vftable_;
	thisa->baseclass_8.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cResourceBase<IRes___GUID_const_IID_IRes>::_vftable_;
	pResMan = _AppGetAggregated(&IID_IResMan);
	if (!pResMan)
		_CriticalMsg("No Resource Manager for a resource!", "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 0x7Cu);
	if (pResMan->vfptr->QueryInterface(pResMan, &IID_IResManHelper, (void **)&thisa->m_pResMan) < 0)
		_CriticalMsg(
		"Resource Manager does not implement IResManHelper!",
		"x:\\prj\\tech\\libsrc\\namedres\\resbastm.h",
		0x7Fu);
	pResMan->vfptr->Release(pResMan);
	if (pStore)
		cResourceBase<IRes___GUID_const_IID_IRes>::SetStore((cResourceBase<IRes, &IID_IRes> *)((char *)thisa + 4), pStore);
	if (pName)
		cResourceBase<IRes___GUID_const_IID_IRes>::SetName((cResourceBase<IRes, &IID_IRes> *)((char *)thisa + 4), pName);
	if (pType)
	{
		thisa->m_pType = pType;
		pType->baseclass_0.vfptr->AddRef((IUnknown *)pType);
	}
}
// 9A84E8: using guessed type int (__stdcall *cResourceBase_IRes___GUID const IID_IRes____vftable_)(int this, int, int);
// 9A855C: using guessed type int (__stdcall *cResourceBase_IRes___GUID const IID_IRes____vftable_)(int this, int, int);
// 9A8594: using guessed type int (__stdcall *cResourceBase_IRes___GUID const IID_IRes____vftable_)(int this, int id, int ppI);

//----- (008E7890) --------------------------------------------------------
void __thiscall cResourceBase<IRes___GUID_const_IID_IRes>::_cResourceBase<IRes___GUID_const_IID_IRes>(cResourceBase<IRes, &IID_IRes> *this)
{
	char *v1; // [sp+0h] [bp-8h]@2
	cResourceBase<IRes, &IID_IRes> *thisa; // [sp+4h] [bp-4h]@1

	thisa = this;
	this->baseclass_0.lpVtbl = (IResHackVtbl *)&cResourceBase<IRes___GUID_const_IID_IRes>::_vftable_;
	this->baseclass_4.baseclass_0.vfptr = (IUnknownVtbl *)&cResourceBase<IRes___GUID_const_IID_IRes>::_vftable_;
	this->baseclass_8.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cResourceBase<IRes___GUID_const_IID_IRes>::_vftable_;
	if (this)
		v1 = (char *)&this->baseclass_8;
	else
		v1 = 0;
	((void(__stdcall *)(_DWORD, _DWORD, _DWORD))this->m_pResMan->baseclass_0.vfptr[3].AddRef)(
		this->m_pResMan,
		v1,
		this->m_ManData);
	thisa->m_pResMan->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pResMan);
	thisa->m_pResMan = 0;
	if (thisa->m_pStream)
	{
		thisa->m_pStream->baseclass_0.vfptr[1].Release((IUnknown *)thisa->m_pStream);
		thisa->m_pStream->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pStream);
		thisa->m_pStream = 0;
	}
	if (thisa->m_pStore)
	{
		thisa->m_pStore->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pStore);
		thisa->m_pStore = 0;
	}
	if (thisa->m_pType)
	{
		thisa->m_pType->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pType);
		thisa->m_pType = 0;
	}
	if (thisa->m_pName)
	{
		j__free(thisa->m_pName);
		thisa->m_pName = 0;
	}
	if (thisa->m_pExt)
	{
		j__free(thisa->m_pExt);
		thisa->m_pExt = 0;
	}
	if (thisa->m_pCanonStore)
		thisa->m_pCanonStore->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pCanonStore);
	thisa->m_pCanonStore = 0;
}
// 9A84E8: using guessed type int (__stdcall *cResourceBase_IRes___GUID const IID_IRes____vftable_)(int this, int, int);
// 9A855C: using guessed type int (__stdcall *cResourceBase_IRes___GUID const IID_IRes____vftable_)(int this, int, int);
// 9A8594: using guessed type int (__stdcall *cResourceBase_IRes___GUID const IID_IRes____vftable_)(int this, int id, int ppI);

//----- (008E7A00) --------------------------------------------------------
int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::QueryInterface(cResourceBase<IRes, &IID_IRes> *this, _GUID *id, void **ppI)
{
	int result; // eax@5
	void *v4; // [sp+0h] [bp-2Ch]@20
	void *v5; // [sp+4h] [bp-28h]@15
	void *v6; // [sp+8h] [bp-24h]@8
	void *v7; // [sp+Ch] [bp-20h]@3
	cAutoResThreadLock __AutoResThreadLock__; // [sp+28h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	*ppI = 0;
	if (IsEqualGUID(id, &IID_IRes))
	{
		this->baseclass_0.lpVtbl->AddRef((IResHack *)this);
		if (this)
			v7 = &this->baseclass_8;
		else
			v7 = 0;
		*ppI = v7;
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = 0;
	}
	else
	{
		if (IsEqualGUID(id, &IID_IResControl))
		{
			this->baseclass_0.lpVtbl->AddRef((IResHack *)this);
			if (this)
				v6 = &this->baseclass_4;
			else
				v6 = 0;
			*ppI = v6;
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
			result = 0;
		}
		else
		{
			if (IsEqualGUID(id, &IID_IResHack))
			{
				this->baseclass_0.lpVtbl->AddRef((IResHack *)this);
				*ppI = this;
				cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
				result = 0;
			}
			else
			{
				if (IsEqualGUID(id, &IID_IDataSource))
				{
					this->baseclass_0.lpVtbl->AddRef((IResHack *)this);
					if (this)
						v5 = &this->baseclass_8;
					else
						v5 = 0;
					*ppI = v5;
					cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
					result = 0;
				}
				else
				{
					if (IsEqualGUID(id, &IID_IRes))
					{
						this->baseclass_0.lpVtbl->AddRef((IResHack *)this);
						if (this)
							v4 = &this->baseclass_8;
						else
							v4 = 0;
						*ppI = v4;
						cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
						result = 0;
					}
					else
					{
						cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
						result = -2147467262;
					}
				}
			}
		}
	}
	return result;
}

//----- (008E7BD0) --------------------------------------------------------
void *__stdcall cResourceBase<IRes___GUID_const_IID_IRes>::Lock(cResourceBase<IRes, &IID_IRes> *this)
{
	void *v1; // ST10_4@2
	void *result; // eax@2
	void *v3; // ST0C_4@6
	cResourceBase<IRes, &IID_IRes> *v4; // [sp+0h] [bp-10h]@4
	cAutoResThreadLock __AutoResThreadLock__; // [sp+Ch] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_ManData)
	{
		++this->m_pStream;
		v1 = (void *)this->m_ManData;
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = v1;
	}
	else
	{
		if (this == (cResourceBase<IRes, &IID_IRes> *)8)
			v4 = 0;
		else
			v4 = this;
		v3 = (void *)(*(int(__stdcall **)(unsigned int, cResourceBase<IRes, &IID_IRes> *))(*(_DWORD *)this->m_ulRefs + 12))(
			this->m_ulRefs,
			v4);
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = v3;
	}
	return result;
}

//----- (008E7C50) --------------------------------------------------------
void __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::Unlock(cResourceBase<IRes, &IID_IRes> *this)
{
	cResourceBase<IRes, &IID_IRes> *v1; // [sp+0h] [bp-8h]@4
	cAutoResThreadLock __AutoResThreadLock__; // [sp+4h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_ManData)
	{
		--this->m_pStream;
	}
	else
	{
		if (this == (cResourceBase<IRes, &IID_IRes> *)8)
			v1 = 0;
		else
			v1 = this;
		(*(void(__stdcall **)(unsigned int, cResourceBase<IRes, &IID_IRes> *))(*(_DWORD *)this->m_ulRefs + 24))(
			this->m_ulRefs,
			v1);
	}
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
}

//----- (008E7CC0) --------------------------------------------------------
unsigned int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::GetLockCount(cResourceBase<IRes, &IID_IRes> *this)
{
	IStoreStream *v1; // ST10_4@2
	unsigned int result; // eax@2
	unsigned int v3; // ST0C_4@6
	cResourceBase<IRes, &IID_IRes> *v4; // [sp+0h] [bp-10h]@4
	cAutoResThreadLock __AutoResThreadLock__; // [sp+Ch] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_ManData)
	{
		v1 = this->m_pStream;
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = (unsigned int)v1;
	}
	else
	{
		if (this == (cResourceBase<IRes, &IID_IRes> *)8)
			v4 = 0;
		else
			v4 = this;
		v3 = (*(int(__stdcall **)(unsigned int, cResourceBase<IRes, &IID_IRes> *))(*(_DWORD *)this->m_ulRefs + 28))(
			this->m_ulRefs,
			v4);
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = v3;
	}
	return result;
}

//----- (008E7D30) --------------------------------------------------------
IResType *__stdcall cResourceBase<IRes___GUID_const_IID_IRes>::GetType(cResourceBase<IRes, &IID_IRes> *this)
{
	char *v1; // ST04_4@1
	cAutoResThreadLock __AutoResThreadLock__; // [sp+4h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	(*(void(__stdcall **)(char *))(*(_DWORD *)this->m_pName + 4))(this->m_pName);
	v1 = this->m_pName;
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return (IResType *)v1;
}

//----- (008E7D70) --------------------------------------------------------
const char *__stdcall cResourceBase<IRes___GUID_const_IID_IRes>::GetName(cResourceBase<IRes, &IID_IRes> *this)
{
	const char *v2; // [sp+0h] [bp-Ch]@2
	cAutoResThreadLock __AutoResThreadLock__; // [sp+8h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_pCanonStore)
		v2 = (const char *)this->m_pCanonStore;
	else
		v2 = &byte_B5ADD0;
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return v2;
}

//----- (008E7DB0) --------------------------------------------------------
void __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::GetCanonPath(cResourceBase<IRes, &IID_IRes> *this, char **ppPath)
{
	int v2; // ecx@0
	int __AutoResThreadLock__; // [sp+0h] [bp-4h]@1

	__AutoResThreadLock__ = v2;
	cAutoResThreadLock::cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	if (this->m_pResMan)
		((void(__stdcall *)(IResManHelper *, char **, int))this->m_pResMan->baseclass_0.vfptr[5].AddRef)(
		this->m_pResMan,
		ppPath,
		__AutoResThreadLock__);
	else
		(*(void(__stdcall **)(int, char **, int))(*(_DWORD *)this->m_bAllowStorageReset + 64))(
		this->m_bAllowStorageReset,
		ppPath,
		__AutoResThreadLock__);
	cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
}

//----- (008E7E10) --------------------------------------------------------
void __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::GetCanonPathName(cResourceBase<IRes, &IID_IRes> *this, char **ppPathname)
{
	size_t v2; // esi@9
	size_t v3; // eax@9
	const char *pCanonPath; // [sp+8h] [bp-8h]@5
	cAutoResThreadLock __AutoResThreadLock__; // [sp+Ch] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	*ppPathname = 0;
	if (this->m_pCanonStore && this->m_bAllowStorageReset)
	{
		if (this->m_pResMan)
			((void(__stdcall *)(IResManHelper *, const char **))this->m_pResMan->baseclass_0.vfptr[5].AddRef)(
			this->m_pResMan,
			&pCanonPath);
		else
			(*(void(__stdcall **)(int, const char **))(*(_DWORD *)this->m_bAllowStorageReset + 64))(
			this->m_bAllowStorageReset,
			&pCanonPath);
		if (pCanonPath)
		{
			v2 = strlen(pCanonPath);
			v3 = strlen((const char *)this->m_pCanonStore);
			*ppPathname = (char *)f_malloc_db(v2 + v3 + 1, "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 698);
			strcpy(*ppPathname, pCanonPath);
			strcat(*ppPathname, (const char *)this->m_pCanonStore);
			j__free((void *)pCanonPath);
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		}
		else
		{
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		}
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	}
}
// B19510: using guessed type int (__cdecl *f_malloc_db)(_DWORD, _DWORD, _DWORD);

//----- (008E7F10) --------------------------------------------------------
IStore *__stdcall cResourceBase<IRes___GUID_const_IID_IRes>::GetCanonStore(cResourceBase<IRes, &IID_IRes> *this)
{
	IStore *v1; // ST04_4@1
	cAutoResThreadLock __AutoResThreadLock__; // [sp+4h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	this->m_pResMan->baseclass_0.vfptr->AddRef((IUnknown *)this->m_pResMan);
	v1 = (IStore *)this->m_pResMan;
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return v1;
}

//----- (008E7F50) --------------------------------------------------------
void __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::GetVariant(cResourceBase<IRes, &IID_IRes> *this, char **ppVariantPath)
{
	int v2; // ecx@0
	int v3; // ST08_4@4
	int v4; // eax@4
	const char *v5; // eax@4
	int __AutoResThreadLock__; // [sp+0h] [bp-4h]@1

	__AutoResThreadLock__ = v2;
	cAutoResThreadLock::cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	if (this->m_bAllowStorageReset && this->m_pResMan)
	{
		v3 = this->m_bAllowStorageReset;
		v4 = (*(int(**)(void))(*(_DWORD *)this->m_bAllowStorageReset + 16))();
		v5 = (const char *)((int(__stdcall *)(IResManHelper *, int))this->m_pResMan->baseclass_0.vfptr[1].AddRef)(
			this->m_pResMan,
			v4);
		ComputeAnchoredPath(v5, (const char *)v3, ppVariantPath);
	}
	else
	{
		*ppVariantPath = (char *)f_malloc_db(1, "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 660);
		**ppVariantPath = 0;
	}
	cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
}
// B19510: using guessed type int (__cdecl *f_malloc_db)(_DWORD, _DWORD, _DWORD);

//----- (008E7FD0) --------------------------------------------------------
void __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::GetStreamName(cResourceBase<IRes, &IID_IRes> *this, int bFullpath, char **ppPathname)
{
	size_t v3; // esi@7
	unsigned int v4; // esi@7
	unsigned int v5; // ST10_4@7
	const char *pStorePath; // [sp+8h] [bp-8h]@5
	cAutoResThreadLock __AutoResThreadLock__; // [sp+Ch] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_bAllowStorageReset && this->m_pCanonStore)
	{
		if (bFullpath)
			pStorePath = (const char *)(*(int(__stdcall **)(int))(*(_DWORD *)this->m_bAllowStorageReset + 16))(this->m_bAllowStorageReset);
		else
			pStorePath = &byte_B5ADD0;
		v3 = strlen(pStorePath);
		v4 = strlen((const char *)this->m_pCanonStore) + v3;
		v5 = v4 + strlen((const char *)this->m_bDoingAsynch) + 1;
		*ppPathname = (char *)f_malloc_db(v5, "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 611);
		strcpy(*ppPathname, pStorePath);
		strcat(*ppPathname, (const char *)this->m_pCanonStore);
		strcat(*ppPathname, (const char *)this->m_bDoingAsynch);
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	}
	else
	{
		*ppPathname = 0;
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	}
}
// B19510: using guessed type int (__cdecl *f_malloc_db)(_DWORD, _DWORD, _DWORD);

//----- (008E80D0) --------------------------------------------------------
void *__stdcall cResourceBase<IRes___GUID_const_IID_IRes>::DataPeek(cResourceBase<IRes, &IID_IRes> *this)
{
	void *v1; // ST14_4@2
	void *result; // eax@2
	void *v3; // ST10_4@6
	cResourceBase<IRes, &IID_IRes> *v4; // [sp+0h] [bp-14h]@4
	cAutoResThreadLock __AutoResThreadLock__; // [sp+Ch] [bp-8h]@1
	int dummy; // [sp+10h] [bp-4h]@6

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_ManData)
	{
		v1 = (void *)this->m_ManData;
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = v1;
	}
	else
	{
		if (this == (cResourceBase<IRes, &IID_IRes> *)8)
			v4 = 0;
		else
			v4 = this;
		v3 = (void *)(*(int(__stdcall **)(unsigned int, cResourceBase<IRes, &IID_IRes> *, int *))(*(_DWORD *)this->m_ulRefs
			+ 20))(
			this->m_ulRefs,
			v4,
			&dummy);
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = v3;
	}
	return result;
}

//----- (008E8150) --------------------------------------------------------
int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::Drop(cResourceBase<IRes, &IID_IRes> *this)
{
	int v1; // ST10_4@2
	int result; // eax@2
	int v3; // ST0C_4@6
	cResourceBase<IRes, &IID_IRes> *v4; // [sp+0h] [bp-10h]@4
	cAutoResThreadLock __AutoResThreadLock__; // [sp+Ch] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_ManData)
	{
		v1 = this->m_pStream == 0;
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = v1;
	}
	else
	{
		if (this == (cResourceBase<IRes, &IID_IRes> *)8)
			v4 = 0;
		else
			v4 = this;
		v3 = (*(int(__stdcall **)(unsigned int, cResourceBase<IRes, &IID_IRes> *))(*(_DWORD *)this->m_ulRefs + 32))(
			this->m_ulRefs,
			v4);
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = v3;
	}
	return result;
}

//----- (008E81D0) --------------------------------------------------------
int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::GetSize(cResourceBase<IRes, &IID_IRes> *this)
{
	int v1; // ST10_4@6
	cResourceBase<IRes, &IID_IRes> *v3; // [sp+0h] [bp-Ch]@4
	cAutoResThreadLock __AutoResThreadLock__; // [sp+8h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_ManData)
		_CriticalMsg("Can't GetSize for an assigned resource!", "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 0x10Au);
	if (this == (cResourceBase<IRes, &IID_IRes> *)8)
		v3 = 0;
	else
		v3 = this;
	v1 = (*(int(__stdcall **)(unsigned int, cResourceBase<IRes, &IID_IRes> *))(*(_DWORD *)this->m_ulRefs + 36))(
		this->m_ulRefs,
		v3);
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return v1;
}

//----- (008E8250) --------------------------------------------------------
void *__stdcall cResourceBase<IRes___GUID_const_IID_IRes>::Extract(cResourceBase<IRes, &IID_IRes> *this, void *pBuf)
{
	void *v2; // ST10_4@6
	cResourceBase<IRes, &IID_IRes> *v4; // [sp+0h] [bp-Ch]@4
	cAutoResThreadLock __AutoResThreadLock__; // [sp+8h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_ManData)
		_CriticalMsg("Can't Extract an assigned resource!", "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 0x114u);
	if (this == (cResourceBase<IRes, &IID_IRes> *)8)
		v4 = 0;
	else
		v4 = this;
	v2 = (void *)(*(int(__stdcall **)(unsigned int, cResourceBase<IRes, &IID_IRes> *, void *))(*(_DWORD *)this->m_ulRefs
		+ 16))(
		this->m_ulRefs,
		v4,
		pBuf);
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return v2;
}

//----- (008E82D0) --------------------------------------------------------
void *__stdcall cResourceBase<IRes___GUID_const_IID_IRes>::PreLoad(cResourceBase<IRes, &IID_IRes> *this)
{
	void *v1; // ST10_4@7
	cResourceBase<IRes, &IID_IRes> *v3; // [sp+0h] [bp-14h]@5
	cResourceBase<IRes, &IID_IRes> *v4; // [sp+4h] [bp-10h]@2
	cAutoResThreadLock __AutoResThreadLock__; // [sp+Ch] [bp-8h]@1
	int pData; // [sp+10h] [bp-4h]@4

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this == (cResourceBase<IRes, &IID_IRes> *)8)
		v4 = 0;
	else
		v4 = this;
	pData = (*(int(__stdcall **)(unsigned int, cResourceBase<IRes, &IID_IRes> *))(*(_DWORD *)this->m_ulRefs + 12))(
		this->m_ulRefs,
		v4);
	if (this == (cResourceBase<IRes, &IID_IRes> *)8)
		v3 = 0;
	else
		v3 = this;
	(*(void(__stdcall **)(unsigned int, cResourceBase<IRes, &IID_IRes> *))(*(_DWORD *)this->m_ulRefs + 24))(
		this->m_ulRefs,
		v3);
	v1 = (void *)pData;
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return v1;
}

//----- (008E8360) --------------------------------------------------------
int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::ExtractPartial(cResourceBase<IRes, &IID_IRes> *this, const int nStart, const int nEnd, void *pBuf)
{
	int result; // eax@2
	const char *v5; // eax@14
	int v6; // ST14_4@19
	cResourceBase<IRes, &IID_IRes> *v7; // [sp+0h] [bp-20h]@4
	int nNumToRead; // [sp+10h] [bp-10h]@9
	cAutoResThreadLock __AutoResThreadLock__; // [sp+14h] [bp-Ch]@3
	char *pData; // [sp+18h] [bp-8h]@6
	int nSize; // [sp+1Ch] [bp-4h]@6

	if (pBuf)
	{
		cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
		if (this == (cResourceBase<IRes, &IID_IRes> *)8)
			v7 = 0;
		else
			v7 = this;
		pData = (char *)(*(int(__stdcall **)(unsigned int, cResourceBase<IRes, &IID_IRes> *, int *))(*(_DWORD *)this->m_ulRefs
			+ 20))(
			this->m_ulRefs,
			v7,
			&nSize);
		if (pData && nSize)
		{
			if (nEnd < nSize)
				nNumToRead = nEnd - nStart + 1;
			else
				nNumToRead = nSize - nStart;
			memmove(pBuf, &pData[nStart], nNumToRead);
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
			result = nNumToRead;
		}
		else
		{
			if (this->m_AppData)
				goto LABEL_22;
			this->m_AppData = (*(int(__stdcall **)(char *))(*((_DWORD *)this - 1) + 36))((char *)this - 4);
			if (!this->m_AppData)
			{
				this->baseclass_0.lpVtbl[1].Release((IResHack *)this);
				v5 = _LogFmt("Unable to open stream: %s");
				_CriticalMsg(v5, "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 0x1B5u);
			}
			if (this->m_AppData)
			{
			LABEL_22:
				if (nStart != (*(int(__stdcall **)(unsigned int))(*(_DWORD *)this->m_AppData + 32))(this->m_AppData))
					(*(void(__stdcall **)(unsigned int, const int))(*(_DWORD *)this->m_AppData + 28))(this->m_AppData, nStart);
				v6 = (*(int(__stdcall **)(unsigned int, int, void *))(*(_DWORD *)this->m_AppData + 44))(
					this->m_AppData,
					nEnd - nStart + 1,
					pBuf);
				cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
				result = v6;
			}
			else
			{
				cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
				result = 0;
			}
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008E84F0) --------------------------------------------------------
void __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::ExtractBlocks(cResourceBase<IRes, &IID_IRes> *this, void *pBuf, const int nSize, int(__cdecl *Callback)(IRes *, void *, int, int, void *), void *pCallbackData)
{
	const char *v5; // eax@3
	IRes *v6; // [sp+0h] [bp-18h]@7
	int pStream; // [sp+4h] [bp-14h]@2
	cAutoResThreadLock __AutoResThreadLock__; // [sp+8h] [bp-10h]@2
	sExtractData ExtractData; // [sp+Ch] [bp-Ch]@9

	if (Callback)
	{
		cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
		pStream = (*(int(__stdcall **)(char *))(*((_DWORD *)this - 1) + 36))((char *)this - 4);
		if (!pStream)
		{
			this->baseclass_0.lpVtbl[1].Release((IResHack *)this);
			v5 = _LogFmt("Unable to open stream: %s");
			_CriticalMsg(v5, "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 0x1D5u);
		}
		if (pStream)
		{
			if (this == (cResourceBase<IRes, &IID_IRes> *)8)
				v6 = 0;
			else
				v6 = (IRes *)this;
			ExtractData.pResource = v6;
			ExtractData.Callback = Callback;
			ExtractData.pCallbackData = pCallbackData;
			(*(void(__stdcall **)(int, void *, const int, int(__cdecl *)(void *, int, int, void *), sExtractData *))(*(_DWORD *)pStream + 52))(
				pStream,
				pBuf,
				nSize,
				ResBaseExtractCallback,
				&ExtractData);
			(*(void(__stdcall **)(int))(*(_DWORD *)pStream + 20))(pStream);
			(*(void(__stdcall **)(int))(*(_DWORD *)pStream + 8))(pStream);
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		}
		else
		{
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		}
	}
}

//----- (008E85E0) --------------------------------------------------------
int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::AsyncLock(cResourceBase<IRes, &IID_IRes> *this, const int nPriority)
{
	cResourceBase<IRes, &IID_IRes> *v3; // [sp+0h] [bp-4h]@2

	if (this == (cResourceBase<IRes, &IID_IRes> *)8)
		v3 = 0;
	else
		v3 = this;
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this->m_ulRefs + 44))(
		this->m_ulRefs,
		v3,
		nPriority,
		v3);
}

//----- (008E8620) --------------------------------------------------------
int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::AsyncExtract(cResourceBase<IRes, &IID_IRes> *this, const int nPriority, void *pBuf, const int bufSize)
{
	cResourceBase<IRes, &IID_IRes> *v5; // [sp+0h] [bp-4h]@2

	if (this == (cResourceBase<IRes, &IID_IRes> *)8)
		v5 = 0;
	else
		v5 = this;
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this->m_ulRefs + 48))(
		this->m_ulRefs,
		v5,
		nPriority,
		pBuf,
		bufSize,
		v5);
}

//----- (008E8670) --------------------------------------------------------
int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::AsyncPreload(cResourceBase<IRes, &IID_IRes> *this)
{
	cResourceBase<IRes, &IID_IRes> *v2; // [sp+0h] [bp-4h]@2

	if (this == (cResourceBase<IRes, &IID_IRes> *)8)
		v2 = 0;
	else
		v2 = this;
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)this->m_ulRefs + 52))(this->m_ulRefs, v2, v2);
}

//----- (008E86B0) --------------------------------------------------------
int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::IsAsyncFulfilled(cResourceBase<IRes, &IID_IRes> *this)
{
	cResourceBase<IRes, &IID_IRes> *v2; // [sp+0h] [bp-4h]@2

	if (this == (cResourceBase<IRes, &IID_IRes> *)8)
		v2 = 0;
	else
		v2 = this;
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)this->m_ulRefs + 56))(this->m_ulRefs, v2, v2);
}

//----- (008E86F0) --------------------------------------------------------
int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::AsyncKill(cResourceBase<IRes, &IID_IRes> *this)
{
	cResourceBase<IRes, &IID_IRes> *v2; // [sp+0h] [bp-4h]@2

	if (this == (cResourceBase<IRes, &IID_IRes> *)8)
		v2 = 0;
	else
		v2 = this;
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)this->m_ulRefs + 60))(this->m_ulRefs, v2, v2);
}

//----- (008E8730) --------------------------------------------------------
int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::GetAsyncResult(cResourceBase<IRes, &IID_IRes> *this, void **ppResult)
{
	cResourceBase<IRes, &IID_IRes> *v3; // [sp+0h] [bp-4h]@2

	if (this == (cResourceBase<IRes, &IID_IRes> *)8)
		v3 = 0;
	else
		v3 = this;
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this->m_ulRefs + 64))(
		this->m_ulRefs,
		v3,
		ppResult,
		v3);
}

//----- (008E8770) --------------------------------------------------------
void __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::SetAppData(cResourceBase<IRes, &IID_IRes> *this, unsigned int AppData)
{
	int v2; // ecx@0
	int __AutoResThreadLock__; // [sp+0h] [bp-4h]@1

	__AutoResThreadLock__ = v2;
	cAutoResThreadLock::cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	this->m_pExt = (char *)AppData;
	cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
}

//----- (008E87A0) --------------------------------------------------------
unsigned int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::GetAppData(cResourceBase<IRes, &IID_IRes> *this)
{
	char *v1; // ST00_4@1
	cAutoResThreadLock __AutoResThreadLock__; // [sp+4h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	v1 = this->m_pExt;
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return (unsigned int)v1;
}

//----- (008E87D0) --------------------------------------------------------
void __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::SetData(cResourceBase<IRes, &IID_IRes> *this, void *pNewData)
{
	int v2; // ecx@0
	int __AutoResThreadLock__; // [sp+0h] [bp-4h]@1

	__AutoResThreadLock__ = v2;
	cAutoResThreadLock::cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	if (((int(__stdcall *)(IRes *, int))this->baseclass_8.baseclass_0.baseclass_0.vfptr[5].QueryInterface)(
		&this->baseclass_8,
		__AutoResThreadLock__))
	{
		this->m_pAssignedData = pNewData;
		cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	}
	else
	{
		_CriticalMsg("Trying to SetData on a Locked Resource!", "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 0x32Fu);
		cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	}
}

//----- (008E8830) --------------------------------------------------------
int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::HasSetData(cResourceBase<IRes, &IID_IRes> *this)
{
	int result; // eax@2
	cAutoResThreadLock __AutoResThreadLock__; // [sp+8h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_pAssignedData)
	{
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = 1;
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = 0;
	}
	return result;
}

//----- (008E8880) --------------------------------------------------------
int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::SetStore(cResourceBase<IRes, &IID_IRes> *this, IStore *pNewStorage)
{
	int result; // eax@7
	cAutoResThreadLock __AutoResThreadLock__; // [sp+8h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_pResMan && !this->m_ulRefs)
	{
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = 0;
	}
	else
	{
		if (this->m_pResMan)
			this->m_pResMan->baseclass_0.vfptr->Release((IUnknown *)this->m_pResMan);
		this->m_pResMan = (IResManHelper *)pNewStorage;
		if (this->m_pResMan)
			this->m_pResMan->baseclass_0.vfptr->AddRef((IUnknown *)this->m_pResMan);
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = 1;
	}
	return result;
}

//----- (008E8910) --------------------------------------------------------
IStore *__stdcall cResourceBase<IRes___GUID_const_IID_IRes>::GetStore(cResourceBase<IRes, &IID_IRes> *this)
{
	int v1; // ST08_4@2
	IStore *result; // eax@2
	cAutoResThreadLock __AutoResThreadLock__; // [sp+8h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_bAllowStorageReset)
	{
		(*(void(__stdcall **)(int))(*(_DWORD *)this->m_bAllowStorageReset + 4))(this->m_bAllowStorageReset);
		v1 = this->m_bAllowStorageReset;
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = (IStore *)v1;
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = 0;
	}
	return result;
}

//----- (008E8970) --------------------------------------------------------
void __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::SetName(cResourceBase<IRes, &IID_IRes> *this, const char *pNewName)
{
	const char *v2; // eax@4
	size_t v3; // eax@4
	const char *v4; // eax@4
	const char *v5; // eax@4
	size_t v6; // eax@4
	const char *v7; // eax@4
	cAnsiStr Ext; // [sp+0h] [bp-24h]@4
	cAutoResThreadLock __AutoResThreadLock__; // [sp+Ch] [bp-18h]@1
	cFileSpec fileSpec; // [sp+10h] [bp-14h]@4
	cAnsiStr Root; // [sp+18h] [bp-Ch]@4

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (pNewName && !this->m_bDoingAsynch)
	{
		cAnsiStr::cAnsiStr(&Root);
		cAnsiStr::cAnsiStr(&Ext);
		cFileSpec::cFileSpec(&fileSpec, pNewName);
		cFileSpec::GetFileExtension(&fileSpec, &Ext);
		v2 = cAnsiStr::operator char_const__(&Ext);
		v3 = strlen(v2);
		this->m_pName = (char *)f_malloc_db(v3 + 1, "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 570);
		v4 = cAnsiStr::operator char_const__(&Ext);
		strcpy(this->m_pName, v4);
		cFileSpec::GetFileRoot(&fileSpec, &Root);
		v5 = cAnsiStr::operator char_const__(&Root);
		v6 = strlen(v5);
		this->m_bDoingAsynch = f_malloc_db(v6 + 1, "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 573);
		v7 = cAnsiStr::operator char_const__(&Root);
		strcpy((char *)this->m_bDoingAsynch, v7);
		cFileSpec::_cFileSpec(&fileSpec);
		cAnsiStr::_cAnsiStr(&Ext);
		cAnsiStr::_cAnsiStr(&Root);
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	}
}
// B19510: using guessed type int (__cdecl *f_malloc_db)(_DWORD, _DWORD, _DWORD);

//----- (008E8A80) --------------------------------------------------------
void __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::AllowStorageReset(cResourceBase<IRes, &IID_IRes> *this, int bAllow)
{
	int v2; // ecx@0
	int __AutoResThreadLock__; // [sp+0h] [bp-4h]@1

	__AutoResThreadLock__ = v2;
	cAutoResThreadLock::cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	this->m_ulRefs = bAllow;
	cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
}

//----- (008E8AB0) --------------------------------------------------------
void __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::SetCanonStore(cResourceBase<IRes, &IID_IRes> *this, IStore *pCanonStore)
{
	int v2; // ecx@0
	int __AutoResThreadLock__; // [sp+0h] [bp-4h]@1

	__AutoResThreadLock__ = v2;
	cAutoResThreadLock::cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	if (this->m_pStore)
		this->m_pStore->baseclass_0.vfptr->Release((IUnknown *)this->m_pStore);
	this->m_pStore = 0;
	this->m_pStore = pCanonStore;
	if (pCanonStore)
		pCanonStore->baseclass_0.vfptr->AddRef((IUnknown *)pCanonStore);
	cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
}

//----- (008E8B10) --------------------------------------------------------
void *__stdcall cResourceBase<IRes___GUID_const_IID_IRes>::LoadData(cResourceBase<IRes, &IID_IRes> *this, unsigned int *pSize, unsigned int *pTimestamp, IResMemOverride *pResMem)
{
	void *result; // eax@2
	const char *v5; // eax@6
	void *v6; // ST10_4@17
	cAutoResThreadLock __AutoResThreadLock__; // [sp+8h] [bp-10h]@3
	void *pStream; // [sp+Ch] [bp-Ch]@5
	int pData; // [sp+10h] [bp-8h]@15
	unsigned int nSize; // [sp+14h] [bp-4h]@9

	if (pResMem)
	{
		cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
		if (this->m_pStream)
			_CriticalMsg("Can't load into an assigned resource!", "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 0x124u);
		pStream = (void *)this->baseclass_0.lpVtbl[1].HasSetData((IResHack *)this);
		if (!pStream)
		{
			this->baseclass_4.baseclass_0.vfptr[2].AddRef((IUnknown *)&this->baseclass_4);
			v5 = _LogFmt("Unable to open stream: %s");
			_CriticalMsg(v5, "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 0x12Au);
		}
		if (pStream)
		{
			nSize = (*(int(__stdcall **)(void *))(*(_DWORD *)pStream + 40))(pStream);
			if (pSize)
				*pSize = nSize;
			if (pTimestamp)
				*pTimestamp = (*(int(__stdcall **)(void *))(*(_DWORD *)pStream + 56))(pStream);
			if (g_pMalloc)
				(*(void(__stdcall **)(int, _DWORD, signed int))(*(_DWORD *)g_pMalloc + 72))(
				g_pMalloc,
				"x:\\prj\\tech\\libsrc\\namedres\\resbastm.h",
				309);
			pData = ((int(__stdcall *)(IResMemOverride *, unsigned int))pResMem->baseclass_0.vfptr[1].QueryInterface)(
				pResMem,
				nSize);
			if (g_pMalloc)
				(*(void(__stdcall **)(int))(*(_DWORD *)g_pMalloc + 76))(g_pMalloc);
			(*(void(__stdcall **)(void *, unsigned int, int))(*(_DWORD *)pStream + 44))(pStream, nSize, pData);
			(*(void(__stdcall **)(void *))(*(_DWORD *)pStream + 20))(pStream);
			(*(void(__stdcall **)(void *))(*(_DWORD *)pStream + 8))(pStream);
			v6 = (void *)pData;
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
			result = v6;
		}
		else
		{
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
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

//----- (008E8C90) --------------------------------------------------------
int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::FreeData(cResourceBase<IRes, &IID_IRes> *this, void *pData, unsigned int __formal, IResMemOverride *pResMem)
{
	cAutoResThreadLock __AutoResThreadLock__; // [sp+4h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	((void(__stdcall *)(IResMemOverride *, void *))pResMem->baseclass_0.vfptr[1].AddRef)(pResMem, pData);
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return 1;
}

//----- (008E8CD0) --------------------------------------------------------
IStoreStream *__stdcall cResourceBase<IRes___GUID_const_IID_IRes>::OpenStream(cResourceBase<IRes, &IID_IRes> *this)
{
	IStoreStream *result; // eax@2
	IStoreStream *v2; // ST0C_4@3
	char pFullName[32]; // [sp+8h] [bp-24h]@3
	cAutoResThreadLock __AutoResThreadLock__; // [sp+28h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_pResMan)
	{
		strcpy(pFullName, (const char *)this->m_bDoingAsynch);
		strcat(pFullName, this->m_pName);
		v2 = (IStoreStream *)this->m_pResMan->baseclass_0.vfptr[4].QueryInterface(
			(IUnknown *)this->m_pResMan,
			(_GUID *)pFullName,
			0);
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = v2;
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = 0;
	}
	return result;
}

//----- (008E8D50) --------------------------------------------------------
char **__stdcall cResourceBase<IRes___GUID_const_IID_IRes>::GetTranslatableTypes(cResourceBase<IRes, &IID_IRes> *this, int *pnTypes)
{
	*pnTypes = 0;
	return 0;
}

//----- (008E8D70) --------------------------------------------------------
void *__stdcall cResourceBase<IRes___GUID_const_IID_IRes>::LoadTranslation(cResourceBase<IRes, &IID_IRes> *this, void *__formal, int a3, const char *a4, int *a5, unsigned int *a6, IResMemOverride *a7)
{
	_CriticalMsg("StandardResource::LoadTranslation called!", "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 0x15Bu);
	return 0;
}

//----- (008E8D90) --------------------------------------------------------
void __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::SetManData(cResourceBase<IRes, &IID_IRes> *this, unsigned int ManData)
{
	int v2; // ecx@0
	int __AutoResThreadLock__; // [sp+0h] [bp-4h]@1

	__AutoResThreadLock__ = v2;
	cAutoResThreadLock::cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	this->m_AppData = ManData;
	cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
}

//----- (008E8DC0) --------------------------------------------------------
unsigned int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::GetManData(cResourceBase<IRes, &IID_IRes> *this)
{
	unsigned int v1; // ST00_4@1
	cAutoResThreadLock __AutoResThreadLock__; // [sp+4h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	v1 = this->m_AppData;
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return v1;
}

//----- (008E8DF0) --------------------------------------------------------
void *__thiscall cResourceBase<IRes___GUID_const_IID_IRes>::_vector_deleting_destructor_(cResourceBase<IRes, &IID_IRes> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cResourceBase<IRes___GUID_const_IID_IRes>::_cResourceBase<IRes___GUID_const_IID_IRes>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008E8E20) --------------------------------------------------------
void __thiscall IResHack::IResHack(IResHack *this)
{
	IResHack *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown((IUnknown *)this);
	v1->lpVtbl = (IResHackVtbl *)IResHack::_vftable_;
}
// 9A85B0: using guessed type int (*IResHack___vftable_[48])();

//----- (008E8E40) --------------------------------------------------------
void __thiscall IResControl::IResControl(IResControl *this)
{
	IResControl *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)IResControl::_vftable_;
}
// 9A85C4: using guessed type int (*IResControl___vftable_[43])();

//----- (008E8E60) --------------------------------------------------------
void __thiscall IRes::IRes(IRes *this)
{
	IRes *v1; // ST00_4@1

	v1 = this;
	IDataSource::IDataSource(&this->baseclass_0);
	v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)IRes::_vftable_;
}
// 9A85FC: using guessed type int (*IRes___vftable_[29])();

//----- (008E8E80) --------------------------------------------------------
int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::QueryInterface(cResourceBase<IRes, &IID_IRes> *this, _GUID *a2, void **a3)
{
	return cResourceBase<IRes___GUID_const_IID_IRes>::QueryInterface(
		(cResourceBase<IRes, &IID_IRes> *)((char *)this - 4),
		a2,
		a3);
}

//----- (008E8E90) --------------------------------------------------------
unsigned int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::AddRef(cResourceBase<IRes, &IID_IRes> *this)
{
	return cResourceBase<IRes___GUID_const_IID_IRes>::AddRef((cResourceBase<IRes, &IID_IRes> *)((char *)this - 4));
}

//----- (008E8EA0) --------------------------------------------------------
unsigned int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::Release(cResourceBase<IRes, &IID_IRes> *this)
{
	return cResourceBase<IRes___GUID_const_IID_IRes>::Release((cResourceBase<IRes, &IID_IRes> *)((char *)this - 4));
}

//----- (008E8EB0) --------------------------------------------------------
int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::QueryInterface(cResourceBase<IRes, &IID_IRes> *this, _GUID *a2, void **a3)
{
	return cResourceBase<IRes___GUID_const_IID_IRes>::QueryInterface(
		(cResourceBase<IRes, &IID_IRes> *)((char *)this - 8),
		a2,
		a3);
}

//----- (008E8EC0) --------------------------------------------------------
unsigned int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::AddRef(cResourceBase<IRes, &IID_IRes> *this)
{
	return cResourceBase<IRes___GUID_const_IID_IRes>::AddRef((cResourceBase<IRes, &IID_IRes> *)((char *)this - 8));
}

//----- (008E8ED0) --------------------------------------------------------
unsigned int __stdcall cResourceBase<IRes___GUID_const_IID_IRes>::Release(cResourceBase<IRes, &IID_IRes> *this)
{
	return cResourceBase<IRes___GUID_const_IID_IRes>::Release((cResourceBase<IRes, &IID_IRes> *)((char *)this - 8));
}






























//----- (008E9FB0) --------------------------------------------------------
void __thiscall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::_cResourceBase<IStringRes___GUID_const_IID_IStringRes>(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	char *v1; // [sp+0h] [bp-8h]@2
	cResourceBase<IStringRes, &IID_IStringRes> *thisa; // [sp+4h] [bp-4h]@1

	thisa = this;
	this->baseclass_0.lpVtbl = (IResHackVtbl *)&cResourceBase<IStringRes___GUID_const_IID_IStringRes>::_vftable_;
	this->baseclass_4.baseclass_0.vfptr = (IUnknownVtbl *)&cResourceBase<IStringRes___GUID_const_IID_IStringRes>::_vftable_;
	this->baseclass_8.baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cResourceBase<IStringRes___GUID_const_IID_IStringRes>::_vftable_;
	if (this)
		v1 = (char *)&this->baseclass_8;
	else
		v1 = 0;
	((void(__stdcall *)(_DWORD, _DWORD, _DWORD))this->m_pResMan->baseclass_0.vfptr[3].AddRef)(
		this->m_pResMan,
		v1,
		this->m_ManData);
	thisa->m_pResMan->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pResMan);
	thisa->m_pResMan = 0;
	if (thisa->m_pStream)
	{
		thisa->m_pStream->baseclass_0.vfptr[1].Release((IUnknown *)thisa->m_pStream);
		thisa->m_pStream->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pStream);
		thisa->m_pStream = 0;
	}
	if (thisa->m_pStore)
	{
		thisa->m_pStore->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pStore);
		thisa->m_pStore = 0;
	}
	if (thisa->m_pType)
	{
		thisa->m_pType->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pType);
		thisa->m_pType = 0;
	}
	if (thisa->m_pName)
	{
		j__free(thisa->m_pName);
		thisa->m_pName = 0;
	}
	if (thisa->m_pExt)
	{
		j__free(thisa->m_pExt);
		thisa->m_pExt = 0;
	}
	if (thisa->m_pCanonStore)
		thisa->m_pCanonStore->baseclass_0.vfptr->Release((IUnknown *)thisa->m_pCanonStore);
	thisa->m_pCanonStore = 0;
}
// 9A8768: using guessed type int (__stdcall *cResourceBase_IStringRes___GUID const IID_IStringRes____vftable_)(int this, int, int);
// 9A87EC: using guessed type int (__stdcall *cResourceBase_IStringRes___GUID const IID_IStringRes____vftable_)(int this, int, int);
// 9A8824: using guessed type int (__stdcall *cResourceBase_IStringRes___GUID const IID_IStringRes____vftable_)(int this, int id, int ppI);

//----- (008EA120) --------------------------------------------------------
int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::QueryInterface(cResourceBase<IStringRes, &IID_IStringRes> *this, _GUID *id, void **ppI)
{
	int result; // eax@5
	void *v4; // [sp+0h] [bp-2Ch]@20
	void *v5; // [sp+4h] [bp-28h]@15
	void *v6; // [sp+8h] [bp-24h]@8
	void *v7; // [sp+Ch] [bp-20h]@3
	cAutoResThreadLock __AutoResThreadLock__; // [sp+28h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	*ppI = 0;
	if (IsEqualGUID(id, &IID_IRes))
	{
		this->baseclass_0.lpVtbl->AddRef((IResHack *)this);
		if (this)
			v7 = &this->baseclass_8;
		else
			v7 = 0;
		*ppI = v7;
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = 0;
	}
	else
	{
		if (IsEqualGUID(id, &IID_IResControl))
		{
			this->baseclass_0.lpVtbl->AddRef((IResHack *)this);
			if (this)
				v6 = &this->baseclass_4;
			else
				v6 = 0;
			*ppI = v6;
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
			result = 0;
		}
		else
		{
			if (IsEqualGUID(id, &IID_IResHack))
			{
				this->baseclass_0.lpVtbl->AddRef((IResHack *)this);
				*ppI = this;
				cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
				result = 0;
			}
			else
			{
				if (IsEqualGUID(id, &IID_IDataSource))
				{
					this->baseclass_0.lpVtbl->AddRef((IResHack *)this);
					if (this)
						v5 = &this->baseclass_8;
					else
						v5 = 0;
					*ppI = v5;
					cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
					result = 0;
				}
				else
				{
					if (IsEqualGUID(id, &IID_IStringRes))
					{
						this->baseclass_0.lpVtbl->AddRef((IResHack *)this);
						if (this)
							v4 = &this->baseclass_8;
						else
							v4 = 0;
						*ppI = v4;
						cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
						result = 0;
					}
					else
					{
						cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
						result = -2147467262;
					}
				}
			}
		}
	}
	return result;
}

//----- (008EA2F0) --------------------------------------------------------
void *__stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::Lock(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	void *v1; // ST10_4@2
	void *result; // eax@2
	void *v3; // ST0C_4@6
	cResourceBase<IStringRes, &IID_IStringRes> *v4; // [sp+0h] [bp-10h]@4
	cAutoResThreadLock __AutoResThreadLock__; // [sp+Ch] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_ManData)
	{
		++this->m_pStream;
		v1 = (void *)this->m_ManData;
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = v1;
	}
	else
	{
		if (this == (cResourceBase<IStringRes, &IID_IStringRes> *)8)
			v4 = 0;
		else
			v4 = this;
		v3 = (void *)(*(int(__stdcall **)(unsigned int, cResourceBase<IStringRes, &IID_IStringRes> *))(*(_DWORD *)this->m_ulRefs
			+ 12))(
			this->m_ulRefs,
			v4);
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = v3;
	}
	return result;
}

//----- (008EA370) --------------------------------------------------------
void __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::Unlock(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	cResourceBase<IStringRes, &IID_IStringRes> *v1; // [sp+0h] [bp-8h]@4
	cAutoResThreadLock __AutoResThreadLock__; // [sp+4h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_ManData)
	{
		--this->m_pStream;
	}
	else
	{
		if (this == (cResourceBase<IStringRes, &IID_IStringRes> *)8)
			v1 = 0;
		else
			v1 = this;
		(*(void(__stdcall **)(unsigned int, cResourceBase<IStringRes, &IID_IStringRes> *))(*(_DWORD *)this->m_ulRefs + 24))(
			this->m_ulRefs,
			v1);
	}
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
}

//----- (008EA3E0) --------------------------------------------------------
unsigned int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::GetLockCount(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	IStoreStream *v1; // ST10_4@2
	unsigned int result; // eax@2
	unsigned int v3; // ST0C_4@6
	cResourceBase<IStringRes, &IID_IStringRes> *v4; // [sp+0h] [bp-10h]@4
	cAutoResThreadLock __AutoResThreadLock__; // [sp+Ch] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_ManData)
	{
		v1 = this->m_pStream;
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = (unsigned int)v1;
	}
	else
	{
		if (this == (cResourceBase<IStringRes, &IID_IStringRes> *)8)
			v4 = 0;
		else
			v4 = this;
		v3 = (*(int(__stdcall **)(unsigned int, cResourceBase<IStringRes, &IID_IStringRes> *))(*(_DWORD *)this->m_ulRefs + 28))(
			this->m_ulRefs,
			v4);
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = v3;
	}
	return result;
}

//----- (008EA450) --------------------------------------------------------
IResType *__stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::GetType(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	char *v1; // ST04_4@1
	cAutoResThreadLock __AutoResThreadLock__; // [sp+4h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	(*(void(__stdcall **)(char *))(*(_DWORD *)this->m_pName + 4))(this->m_pName);
	v1 = this->m_pName;
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return (IResType *)v1;
}

//----- (008EA490) --------------------------------------------------------
const char *__stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::GetName(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	const char *v2; // [sp+0h] [bp-Ch]@2
	cAutoResThreadLock __AutoResThreadLock__; // [sp+8h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_pCanonStore)
		v2 = (const char *)this->m_pCanonStore;
	else
		v2 = &byte_B5ADD0;
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return v2;
}

//----- (008EA4D0) --------------------------------------------------------
void __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::GetCanonPath(cResourceBase<IStringRes, &IID_IStringRes> *this, char **ppPath)
{
	int v2; // ecx@0
	int __AutoResThreadLock__; // [sp+0h] [bp-4h]@1

	__AutoResThreadLock__ = v2;
	cAutoResThreadLock::cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	if (this->m_pResMan)
		((void(__stdcall *)(IResManHelper *, char **, int))this->m_pResMan->baseclass_0.vfptr[5].AddRef)(
		this->m_pResMan,
		ppPath,
		__AutoResThreadLock__);
	else
		(*(void(__stdcall **)(int, char **, int))(*(_DWORD *)this->m_bAllowStorageReset + 64))(
		this->m_bAllowStorageReset,
		ppPath,
		__AutoResThreadLock__);
	cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
}

//----- (008EA530) --------------------------------------------------------
void __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::GetCanonPathName(cResourceBase<IStringRes, &IID_IStringRes> *this, char **ppPathname)
{
	size_t v2; // esi@9
	size_t v3; // eax@9
	const char *pCanonPath; // [sp+8h] [bp-8h]@5
	cAutoResThreadLock __AutoResThreadLock__; // [sp+Ch] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	*ppPathname = 0;
	if (this->m_pCanonStore && this->m_bAllowStorageReset)
	{
		if (this->m_pResMan)
			((void(__stdcall *)(IResManHelper *, const char **))this->m_pResMan->baseclass_0.vfptr[5].AddRef)(
			this->m_pResMan,
			&pCanonPath);
		else
			(*(void(__stdcall **)(int, const char **))(*(_DWORD *)this->m_bAllowStorageReset + 64))(
			this->m_bAllowStorageReset,
			&pCanonPath);
		if (pCanonPath)
		{
			v2 = strlen(pCanonPath);
			v3 = strlen((const char *)this->m_pCanonStore);
			*ppPathname = (char *)f_malloc_db(v2 + v3 + 1, "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 698);
			strcpy(*ppPathname, pCanonPath);
			strcat(*ppPathname, (const char *)this->m_pCanonStore);
			j__free((void *)pCanonPath);
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		}
		else
		{
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		}
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	}
}
// B19510: using guessed type int (__cdecl *f_malloc_db)(_DWORD, _DWORD, _DWORD);

//----- (008EA630) --------------------------------------------------------
IStore *__stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::GetCanonStore(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	IStore *v1; // ST04_4@1
	cAutoResThreadLock __AutoResThreadLock__; // [sp+4h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	this->m_pResMan->baseclass_0.vfptr->AddRef((IUnknown *)this->m_pResMan);
	v1 = (IStore *)this->m_pResMan;
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return v1;
}

//----- (008EA670) --------------------------------------------------------
void __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::GetVariant(cResourceBase<IStringRes, &IID_IStringRes> *this, char **ppVariantPath)
{
	int v2; // ecx@0
	int v3; // ST08_4@4
	int v4; // eax@4
	const char *v5; // eax@4
	int __AutoResThreadLock__; // [sp+0h] [bp-4h]@1

	__AutoResThreadLock__ = v2;
	cAutoResThreadLock::cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	if (this->m_bAllowStorageReset && this->m_pResMan)
	{
		v3 = this->m_bAllowStorageReset;
		v4 = (*(int(**)(void))(*(_DWORD *)this->m_bAllowStorageReset + 16))();
		v5 = (const char *)((int(__stdcall *)(IResManHelper *, int))this->m_pResMan->baseclass_0.vfptr[1].AddRef)(
			this->m_pResMan,
			v4);
		ComputeAnchoredPath(v5, (const char *)v3, ppVariantPath);
	}
	else
	{
		*ppVariantPath = (char *)f_malloc_db(1, "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 660);
		**ppVariantPath = 0;
	}
	cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
}
// B19510: using guessed type int (__cdecl *f_malloc_db)(_DWORD, _DWORD, _DWORD);

//----- (008EA6F0) --------------------------------------------------------
void __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::GetStreamName(cResourceBase<IStringRes, &IID_IStringRes> *this, int bFullpath, char **ppPathname)
{
	size_t v3; // esi@7
	unsigned int v4; // esi@7
	unsigned int v5; // ST10_4@7
	const char *pStorePath; // [sp+8h] [bp-8h]@5
	cAutoResThreadLock __AutoResThreadLock__; // [sp+Ch] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_bAllowStorageReset && this->m_pCanonStore)
	{
		if (bFullpath)
			pStorePath = (const char *)(*(int(__stdcall **)(int))(*(_DWORD *)this->m_bAllowStorageReset + 16))(this->m_bAllowStorageReset);
		else
			pStorePath = &byte_B5ADD0;
		v3 = strlen(pStorePath);
		v4 = strlen((const char *)this->m_pCanonStore) + v3;
		v5 = v4 + strlen((const char *)this->m_bDoingAsynch) + 1;
		*ppPathname = (char *)f_malloc_db(v5, "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 611);
		strcpy(*ppPathname, pStorePath);
		strcat(*ppPathname, (const char *)this->m_pCanonStore);
		strcat(*ppPathname, (const char *)this->m_bDoingAsynch);
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	}
	else
	{
		*ppPathname = 0;
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	}
}
// B19510: using guessed type int (__cdecl *f_malloc_db)(_DWORD, _DWORD, _DWORD);

//----- (008EA7F0) --------------------------------------------------------
void *__stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::DataPeek(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	void *v1; // ST14_4@2
	void *result; // eax@2
	void *v3; // ST10_4@6
	cResourceBase<IStringRes, &IID_IStringRes> *v4; // [sp+0h] [bp-14h]@4
	cAutoResThreadLock __AutoResThreadLock__; // [sp+Ch] [bp-8h]@1
	int dummy; // [sp+10h] [bp-4h]@6

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_ManData)
	{
		v1 = (void *)this->m_ManData;
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = v1;
	}
	else
	{
		if (this == (cResourceBase<IStringRes, &IID_IStringRes> *)8)
			v4 = 0;
		else
			v4 = this;
		v3 = (void *)(*(int(__stdcall **)(unsigned int, cResourceBase<IStringRes, &IID_IStringRes> *, int *))(*(_DWORD *)this->m_ulRefs + 20))(
			this->m_ulRefs,
			v4,
			&dummy);
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = v3;
	}
	return result;
}

//----- (008EA870) --------------------------------------------------------
int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::Drop(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	int v1; // ST10_4@2
	int result; // eax@2
	int v3; // ST0C_4@6
	cResourceBase<IStringRes, &IID_IStringRes> *v4; // [sp+0h] [bp-10h]@4
	cAutoResThreadLock __AutoResThreadLock__; // [sp+Ch] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_ManData)
	{
		v1 = this->m_pStream == 0;
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = v1;
	}
	else
	{
		if (this == (cResourceBase<IStringRes, &IID_IStringRes> *)8)
			v4 = 0;
		else
			v4 = this;
		v3 = (*(int(__stdcall **)(unsigned int, cResourceBase<IStringRes, &IID_IStringRes> *))(*(_DWORD *)this->m_ulRefs + 32))(
			this->m_ulRefs,
			v4);
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = v3;
	}
	return result;
}

//----- (008EA8F0) --------------------------------------------------------
int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::GetSize(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	int v1; // ST10_4@6
	cResourceBase<IStringRes, &IID_IStringRes> *v3; // [sp+0h] [bp-Ch]@4
	cAutoResThreadLock __AutoResThreadLock__; // [sp+8h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_ManData)
		_CriticalMsg("Can't GetSize for an assigned resource!", "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 0x10Au);
	if (this == (cResourceBase<IStringRes, &IID_IStringRes> *)8)
		v3 = 0;
	else
		v3 = this;
	v1 = (*(int(__stdcall **)(unsigned int, cResourceBase<IStringRes, &IID_IStringRes> *))(*(_DWORD *)this->m_ulRefs + 36))(
		this->m_ulRefs,
		v3);
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return v1;
}

//----- (008EA970) --------------------------------------------------------
void *__stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::Extract(cResourceBase<IStringRes, &IID_IStringRes> *this, void *pBuf)
{
	void *v2; // ST10_4@6
	cResourceBase<IStringRes, &IID_IStringRes> *v4; // [sp+0h] [bp-Ch]@4
	cAutoResThreadLock __AutoResThreadLock__; // [sp+8h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_ManData)
		_CriticalMsg("Can't Extract an assigned resource!", "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 0x114u);
	if (this == (cResourceBase<IStringRes, &IID_IStringRes> *)8)
		v4 = 0;
	else
		v4 = this;
	v2 = (void *)(*(int(__stdcall **)(unsigned int, cResourceBase<IStringRes, &IID_IStringRes> *, void *))(*(_DWORD *)this->m_ulRefs + 16))(
		this->m_ulRefs,
		v4,
		pBuf);
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return v2;
}

//----- (008EA9F0) --------------------------------------------------------
void *__stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::PreLoad(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	void *v1; // ST10_4@7
	cResourceBase<IStringRes, &IID_IStringRes> *v3; // [sp+0h] [bp-14h]@5
	cResourceBase<IStringRes, &IID_IStringRes> *v4; // [sp+4h] [bp-10h]@2
	cAutoResThreadLock __AutoResThreadLock__; // [sp+Ch] [bp-8h]@1
	int pData; // [sp+10h] [bp-4h]@4

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this == (cResourceBase<IStringRes, &IID_IStringRes> *)8)
		v4 = 0;
	else
		v4 = this;
	pData = (*(int(__stdcall **)(unsigned int, cResourceBase<IStringRes, &IID_IStringRes> *))(*(_DWORD *)this->m_ulRefs
		+ 12))(
		this->m_ulRefs,
		v4);
	if (this == (cResourceBase<IStringRes, &IID_IStringRes> *)8)
		v3 = 0;
	else
		v3 = this;
	(*(void(__stdcall **)(unsigned int, cResourceBase<IStringRes, &IID_IStringRes> *))(*(_DWORD *)this->m_ulRefs + 24))(
		this->m_ulRefs,
		v3);
	v1 = (void *)pData;
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return v1;
}

//----- (008EAA80) --------------------------------------------------------
int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::ExtractPartial(cResourceBase<IStringRes, &IID_IStringRes> *this, const int nStart, const int nEnd, void *pBuf)
{
	int result; // eax@2
	const char *v5; // eax@14
	int v6; // ST14_4@19
	cResourceBase<IStringRes, &IID_IStringRes> *v7; // [sp+0h] [bp-20h]@4
	int nNumToRead; // [sp+10h] [bp-10h]@9
	cAutoResThreadLock __AutoResThreadLock__; // [sp+14h] [bp-Ch]@3
	char *pData; // [sp+18h] [bp-8h]@6
	int nSize; // [sp+1Ch] [bp-4h]@6

	if (pBuf)
	{
		cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
		if (this == (cResourceBase<IStringRes, &IID_IStringRes> *)8)
			v7 = 0;
		else
			v7 = this;
		pData = (char *)(*(int(__stdcall **)(unsigned int, cResourceBase<IStringRes, &IID_IStringRes> *, int *))(*(_DWORD *)this->m_ulRefs + 20))(
			this->m_ulRefs,
			v7,
			&nSize);
		if (pData && nSize)
		{
			if (nEnd < nSize)
				nNumToRead = nEnd - nStart + 1;
			else
				nNumToRead = nSize - nStart;
			memmove(pBuf, &pData[nStart], nNumToRead);
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
			result = nNumToRead;
		}
		else
		{
			if (this->m_AppData)
				goto LABEL_22;
			this->m_AppData = (*(int(__stdcall **)(char *))(*((_DWORD *)this - 1) + 36))((char *)this - 4);
			if (!this->m_AppData)
			{
				this->baseclass_0.lpVtbl[1].Release((IResHack *)this);
				v5 = _LogFmt("Unable to open stream: %s");
				_CriticalMsg(v5, "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 0x1B5u);
			}
			if (this->m_AppData)
			{
			LABEL_22:
				if (nStart != (*(int(__stdcall **)(unsigned int))(*(_DWORD *)this->m_AppData + 32))(this->m_AppData))
					(*(void(__stdcall **)(unsigned int, const int))(*(_DWORD *)this->m_AppData + 28))(this->m_AppData, nStart);
				v6 = (*(int(__stdcall **)(unsigned int, int, void *))(*(_DWORD *)this->m_AppData + 44))(
					this->m_AppData,
					nEnd - nStart + 1,
					pBuf);
				cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
				result = v6;
			}
			else
			{
				cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
				result = 0;
			}
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (008EAC10) --------------------------------------------------------
void __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::ExtractBlocks(cResourceBase<IStringRes, &IID_IStringRes> *this, void *pBuf, const int nSize, int(__cdecl *Callback)(IRes *, void *, int, int, void *), void *pCallbackData)
{
	const char *v5; // eax@3
	IRes *v6; // [sp+0h] [bp-18h]@7
	int pStream; // [sp+4h] [bp-14h]@2
	cAutoResThreadLock __AutoResThreadLock__; // [sp+8h] [bp-10h]@2
	sExtractData ExtractData; // [sp+Ch] [bp-Ch]@9

	if (Callback)
	{
		cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
		pStream = (*(int(__stdcall **)(char *))(*((_DWORD *)this - 1) + 36))((char *)this - 4);
		if (!pStream)
		{
			this->baseclass_0.lpVtbl[1].Release((IResHack *)this);
			v5 = _LogFmt("Unable to open stream: %s");
			_CriticalMsg(v5, "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 0x1D5u);
		}
		if (pStream)
		{
			if (this == (cResourceBase<IStringRes, &IID_IStringRes> *)8)
				v6 = 0;
			else
				v6 = (IRes *)this;
			ExtractData.pResource = v6;
			ExtractData.Callback = Callback;
			ExtractData.pCallbackData = pCallbackData;
			(*(void(__stdcall **)(int, void *, const int, int(__cdecl *)(void *, int, int, void *), sExtractData *))(*(_DWORD *)pStream + 52))(
				pStream,
				pBuf,
				nSize,
				ResBaseExtractCallback,
				&ExtractData);
			(*(void(__stdcall **)(int))(*(_DWORD *)pStream + 20))(pStream);
			(*(void(__stdcall **)(int))(*(_DWORD *)pStream + 8))(pStream);
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		}
		else
		{
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		}
	}
}

//----- (008EAD00) --------------------------------------------------------
int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::AsyncLock(cResourceBase<IStringRes, &IID_IStringRes> *this, const int nPriority)
{
	cResourceBase<IStringRes, &IID_IStringRes> *v3; // [sp+0h] [bp-4h]@2

	if (this == (cResourceBase<IStringRes, &IID_IStringRes> *)8)
		v3 = 0;
	else
		v3 = this;
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this->m_ulRefs + 44))(
		this->m_ulRefs,
		v3,
		nPriority,
		v3);
}

//----- (008EAD40) --------------------------------------------------------
int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::AsyncExtract(cResourceBase<IStringRes, &IID_IStringRes> *this, const int nPriority, void *pBuf, const int bufSize)
{
	cResourceBase<IStringRes, &IID_IStringRes> *v5; // [sp+0h] [bp-4h]@2

	if (this == (cResourceBase<IStringRes, &IID_IStringRes> *)8)
		v5 = 0;
	else
		v5 = this;
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this->m_ulRefs + 48))(
		this->m_ulRefs,
		v5,
		nPriority,
		pBuf,
		bufSize,
		v5);
}

//----- (008EAD90) --------------------------------------------------------
int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::AsyncPreload(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	cResourceBase<IStringRes, &IID_IStringRes> *v2; // [sp+0h] [bp-4h]@2

	if (this == (cResourceBase<IStringRes, &IID_IStringRes> *)8)
		v2 = 0;
	else
		v2 = this;
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)this->m_ulRefs + 52))(this->m_ulRefs, v2, v2);
}

//----- (008EADD0) --------------------------------------------------------
int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::IsAsyncFulfilled(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	cResourceBase<IStringRes, &IID_IStringRes> *v2; // [sp+0h] [bp-4h]@2

	if (this == (cResourceBase<IStringRes, &IID_IStringRes> *)8)
		v2 = 0;
	else
		v2 = this;
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)this->m_ulRefs + 56))(this->m_ulRefs, v2, v2);
}

//----- (008EAE10) --------------------------------------------------------
int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::AsyncKill(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	cResourceBase<IStringRes, &IID_IStringRes> *v2; // [sp+0h] [bp-4h]@2

	if (this == (cResourceBase<IStringRes, &IID_IStringRes> *)8)
		v2 = 0;
	else
		v2 = this;
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)this->m_ulRefs + 60))(this->m_ulRefs, v2, v2);
}

//----- (008EAE50) --------------------------------------------------------
int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::GetAsyncResult(cResourceBase<IStringRes, &IID_IStringRes> *this, void **ppResult)
{
	cResourceBase<IStringRes, &IID_IStringRes> *v3; // [sp+0h] [bp-4h]@2

	if (this == (cResourceBase<IStringRes, &IID_IStringRes> *)8)
		v3 = 0;
	else
		v3 = this;
	return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this->m_ulRefs + 64))(
		this->m_ulRefs,
		v3,
		ppResult,
		v3);
}

//----- (008EAE90) --------------------------------------------------------
void __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::SetAppData(cResourceBase<IStringRes, &IID_IStringRes> *this, unsigned int AppData)
{
	int v2; // ecx@0
	int __AutoResThreadLock__; // [sp+0h] [bp-4h]@1

	__AutoResThreadLock__ = v2;
	cAutoResThreadLock::cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	this->m_pExt = (char *)AppData;
	cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
}

//----- (008EAEC0) --------------------------------------------------------
unsigned int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::GetAppData(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	char *v1; // ST00_4@1
	cAutoResThreadLock __AutoResThreadLock__; // [sp+4h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	v1 = this->m_pExt;
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return (unsigned int)v1;
}

//----- (008EAEF0) --------------------------------------------------------
void __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::SetData(cResourceBase<IStringRes, &IID_IStringRes> *this, void *pNewData)
{
	int v2; // ecx@0
	int __AutoResThreadLock__; // [sp+0h] [bp-4h]@1

	__AutoResThreadLock__ = v2;
	cAutoResThreadLock::cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	if (((int(__stdcall *)(IStringRes *, int))this->baseclass_8.baseclass_0.baseclass_0.baseclass_0.vfptr[5].QueryInterface)(
		&this->baseclass_8,
		__AutoResThreadLock__))
	{
		this->m_pAssignedData = pNewData;
		cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	}
	else
	{
		_CriticalMsg("Trying to SetData on a Locked Resource!", "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 0x32Fu);
		cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	}
}

//----- (008EAF50) --------------------------------------------------------
int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::HasSetData(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	int result; // eax@2
	cAutoResThreadLock __AutoResThreadLock__; // [sp+8h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_pAssignedData)
	{
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = 1;
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = 0;
	}
	return result;
}

//----- (008EAFA0) --------------------------------------------------------
int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::SetStore(cResourceBase<IStringRes, &IID_IStringRes> *this, IStore *pNewStorage)
{
	int result; // eax@7
	cAutoResThreadLock __AutoResThreadLock__; // [sp+8h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_pResMan && !this->m_ulRefs)
	{
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = 0;
	}
	else
	{
		if (this->m_pResMan)
			this->m_pResMan->baseclass_0.vfptr->Release((IUnknown *)this->m_pResMan);
		this->m_pResMan = (IResManHelper *)pNewStorage;
		if (this->m_pResMan)
			this->m_pResMan->baseclass_0.vfptr->AddRef((IUnknown *)this->m_pResMan);
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = 1;
	}
	return result;
}

//----- (008EB030) --------------------------------------------------------
IStore *__stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::GetStore(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	int v1; // ST08_4@2
	IStore *result; // eax@2
	cAutoResThreadLock __AutoResThreadLock__; // [sp+8h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_bAllowStorageReset)
	{
		(*(void(__stdcall **)(int))(*(_DWORD *)this->m_bAllowStorageReset + 4))(this->m_bAllowStorageReset);
		v1 = this->m_bAllowStorageReset;
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = (IStore *)v1;
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = 0;
	}
	return result;
}

//----- (008EB090) --------------------------------------------------------
void __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::SetName(cResourceBase<IStringRes, &IID_IStringRes> *this, const char *pNewName)
{
	const char *v2; // eax@4
	size_t v3; // eax@4
	const char *v4; // eax@4
	const char *v5; // eax@4
	size_t v6; // eax@4
	const char *v7; // eax@4
	cAnsiStr Ext; // [sp+0h] [bp-24h]@4
	cAutoResThreadLock __AutoResThreadLock__; // [sp+Ch] [bp-18h]@1
	cFileSpec fileSpec; // [sp+10h] [bp-14h]@4
	cAnsiStr Root; // [sp+18h] [bp-Ch]@4

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (pNewName && !this->m_bDoingAsynch)
	{
		cAnsiStr::cAnsiStr(&Root);
		cAnsiStr::cAnsiStr(&Ext);
		cFileSpec::cFileSpec(&fileSpec, pNewName);
		cFileSpec::GetFileExtension(&fileSpec, &Ext);
		v2 = cAnsiStr::operator char_const__(&Ext);
		v3 = strlen(v2);
		this->m_pName = (char *)f_malloc_db(v3 + 1, "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 570);
		v4 = cAnsiStr::operator char_const__(&Ext);
		strcpy(this->m_pName, v4);
		cFileSpec::GetFileRoot(&fileSpec, &Root);
		v5 = cAnsiStr::operator char_const__(&Root);
		v6 = strlen(v5);
		this->m_bDoingAsynch = f_malloc_db(v6 + 1, "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 573);
		v7 = cAnsiStr::operator char_const__(&Root);
		strcpy((char *)this->m_bDoingAsynch, v7);
		cFileSpec::_cFileSpec(&fileSpec);
		cAnsiStr::_cAnsiStr(&Ext);
		cAnsiStr::_cAnsiStr(&Root);
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	}
}
// B19510: using guessed type int (__cdecl *f_malloc_db)(_DWORD, _DWORD, _DWORD);

//----- (008EB1A0) --------------------------------------------------------
void __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::AllowStorageReset(cResourceBase<IStringRes, &IID_IStringRes> *this, int bAllow)
{
	int v2; // ecx@0
	int __AutoResThreadLock__; // [sp+0h] [bp-4h]@1

	__AutoResThreadLock__ = v2;
	cAutoResThreadLock::cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	this->m_ulRefs = bAllow;
	cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
}

//----- (008EB1D0) --------------------------------------------------------
void __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::SetCanonStore(cResourceBase<IStringRes, &IID_IStringRes> *this, IStore *pCanonStore)
{
	int v2; // ecx@0
	int __AutoResThreadLock__; // [sp+0h] [bp-4h]@1

	__AutoResThreadLock__ = v2;
	cAutoResThreadLock::cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	if (this->m_pStore)
		this->m_pStore->baseclass_0.vfptr->Release((IUnknown *)this->m_pStore);
	this->m_pStore = 0;
	this->m_pStore = pCanonStore;
	if (pCanonStore)
		pCanonStore->baseclass_0.vfptr->AddRef((IUnknown *)pCanonStore);
	cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
}

//----- (008EB230) --------------------------------------------------------
void *__stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::LoadData(cResourceBase<IStringRes, &IID_IStringRes> *this, unsigned int *pSize, unsigned int *pTimestamp, IResMemOverride *pResMem)
{
	void *result; // eax@2
	const char *v5; // eax@6
	void *v6; // ST10_4@17
	cAutoResThreadLock __AutoResThreadLock__; // [sp+8h] [bp-10h]@3
	void *pStream; // [sp+Ch] [bp-Ch]@5
	int pData; // [sp+10h] [bp-8h]@15
	unsigned int nSize; // [sp+14h] [bp-4h]@9

	if (pResMem)
	{
		cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
		if (this->m_pStream)
			_CriticalMsg("Can't load into an assigned resource!", "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 0x124u);
		pStream = (void *)this->baseclass_0.lpVtbl[1].HasSetData((IResHack *)this);
		if (!pStream)
		{
			this->baseclass_4.baseclass_0.vfptr[2].AddRef((IUnknown *)&this->baseclass_4);
			v5 = _LogFmt("Unable to open stream: %s");
			_CriticalMsg(v5, "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 0x12Au);
		}
		if (pStream)
		{
			nSize = (*(int(__stdcall **)(void *))(*(_DWORD *)pStream + 40))(pStream);
			if (pSize)
				*pSize = nSize;
			if (pTimestamp)
				*pTimestamp = (*(int(__stdcall **)(void *))(*(_DWORD *)pStream + 56))(pStream);
			if (g_pMalloc)
				(*(void(__stdcall **)(int, _DWORD, signed int))(*(_DWORD *)g_pMalloc + 72))(
				g_pMalloc,
				"x:\\prj\\tech\\libsrc\\namedres\\resbastm.h",
				309);
			pData = ((int(__stdcall *)(IResMemOverride *, unsigned int))pResMem->baseclass_0.vfptr[1].QueryInterface)(
				pResMem,
				nSize);
			if (g_pMalloc)
				(*(void(__stdcall **)(int))(*(_DWORD *)g_pMalloc + 76))(g_pMalloc);
			(*(void(__stdcall **)(void *, unsigned int, int))(*(_DWORD *)pStream + 44))(pStream, nSize, pData);
			(*(void(__stdcall **)(void *))(*(_DWORD *)pStream + 20))(pStream);
			(*(void(__stdcall **)(void *))(*(_DWORD *)pStream + 8))(pStream);
			v6 = (void *)pData;
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
			result = v6;
		}
		else
		{
			cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
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

//----- (008EB3B0) --------------------------------------------------------
int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::FreeData(cResourceBase<IStringRes, &IID_IStringRes> *this, void *pData, unsigned int __formal, IResMemOverride *pResMem)
{
	cAutoResThreadLock __AutoResThreadLock__; // [sp+4h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	((void(__stdcall *)(IResMemOverride *, void *))pResMem->baseclass_0.vfptr[1].AddRef)(pResMem, pData);
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return 1;
}

//----- (008EB3F0) --------------------------------------------------------
IStoreStream *__stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::OpenStream(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	IStoreStream *result; // eax@2
	IStoreStream *v2; // ST0C_4@3
	char pFullName[32]; // [sp+8h] [bp-24h]@3
	cAutoResThreadLock __AutoResThreadLock__; // [sp+28h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	if (this->m_pResMan)
	{
		strcpy(pFullName, (const char *)this->m_bDoingAsynch);
		strcat(pFullName, this->m_pName);
		v2 = (IStoreStream *)this->m_pResMan->baseclass_0.vfptr[4].QueryInterface(
			(IUnknown *)this->m_pResMan,
			(_GUID *)pFullName,
			0);
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = v2;
	}
	else
	{
		cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
		result = 0;
	}
	return result;
}

//----- (008EB470) --------------------------------------------------------
char **__stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::GetTranslatableTypes(cResourceBase<IStringRes, &IID_IStringRes> *this, int *pnTypes)
{
	*pnTypes = 0;
	return 0;
}

//----- (008EB490) --------------------------------------------------------
void *__stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::LoadTranslation(cResourceBase<IStringRes, &IID_IStringRes> *this, void *__formal, int a3, const char *a4, int *a5, unsigned int *a6, IResMemOverride *a7)
{
	_CriticalMsg("StandardResource::LoadTranslation called!", "x:\\prj\\tech\\libsrc\\namedres\\resbastm.h", 0x15Bu);
	return 0;
}

//----- (008EB4B0) --------------------------------------------------------
void __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::SetManData(cResourceBase<IStringRes, &IID_IStringRes> *this, unsigned int ManData)
{
	int v2; // ecx@0
	int __AutoResThreadLock__; // [sp+0h] [bp-4h]@1

	__AutoResThreadLock__ = v2;
	cAutoResThreadLock::cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
	this->m_AppData = ManData;
	cAutoResThreadLock::_cAutoResThreadLock((cAutoResThreadLock *)&__AutoResThreadLock__);
}

//----- (008EB4E0) --------------------------------------------------------
unsigned int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::GetManData(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	unsigned int v1; // ST00_4@1
	cAutoResThreadLock __AutoResThreadLock__; // [sp+4h] [bp-4h]@1

	cAutoResThreadLock::cAutoResThreadLock(&__AutoResThreadLock__);
	v1 = this->m_AppData;
	cAutoResThreadLock::_cAutoResThreadLock(&__AutoResThreadLock__);
	return v1;
}

//----- (008EB510) --------------------------------------------------------
void *__thiscall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::_scalar_deleting_destructor_(cResourceBase<IStringRes, &IID_IStringRes> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cResourceBase<IStringRes___GUID_const_IID_IStringRes>::_cResourceBase<IStringRes___GUID_const_IID_IStringRes>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008EB540) --------------------------------------------------------
void __thiscall IStringRes::IStringRes(IStringRes *this)
{
	IStringRes *v1; // ST00_4@1

	v1 = this;
	IRes::IRes(&this->baseclass_0);
	v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)IStringRes::_vftable_;
}
// 9A8840: using guessed type int (*IStringRes___vftable_[33])();

//----- (008EB560) --------------------------------------------------------
int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::QueryInterface(cResourceBase<IStringRes, &IID_IStringRes> *this, _GUID *a2, void **a3)
{
	return cResourceBase<IStringRes___GUID_const_IID_IStringRes>::QueryInterface(
		(cResourceBase<IStringRes, &IID_IStringRes> *)((char *)this - 4),
		a2,
		a3);
}

//----- (008EB570) --------------------------------------------------------
unsigned int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::AddRef(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	return cResourceBase<IStringRes___GUID_const_IID_IStringRes>::AddRef((cResourceBase<IStringRes, &IID_IStringRes> *)((char *)this - 4));
}

//----- (008EB580) --------------------------------------------------------
unsigned int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::Release(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	return cResourceBase<IStringRes___GUID_const_IID_IStringRes>::Release((cResourceBase<IStringRes, &IID_IStringRes> *)((char *)this - 4));
}

//----- (008EB590) --------------------------------------------------------
int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::QueryInterface(cResourceBase<IStringRes, &IID_IStringRes> *this, _GUID *a2, void **a3)
{
	return cResourceBase<IStringRes___GUID_const_IID_IStringRes>::QueryInterface(
		(cResourceBase<IStringRes, &IID_IStringRes> *)((char *)this - 8),
		a2,
		a3);
}

//----- (008EB5A0) --------------------------------------------------------
unsigned int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::AddRef(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	return cResourceBase<IStringRes___GUID_const_IID_IStringRes>::AddRef((cResourceBase<IStringRes, &IID_IStringRes> *)((char *)this - 8));
}

//----- (008EB5B0) --------------------------------------------------------
unsigned int __stdcall cResourceBase<IStringRes___GUID_const_IID_IStringRes>::Release(cResourceBase<IStringRes, &IID_IStringRes> *this)
{
	return cResourceBase<IStringRes___GUID_const_IID_IStringRes>::Release((cResourceBase<IStringRes, &IID_IStringRes> *)((char *)this - 8));
}

//----- (008EB5C0) --------------------------------------------------------
void __thiscall cHashSet<cStringResEntry___char_const___cCaselessStringHashFuncs>::DestroyAll(cHashSet<cStringResEntry *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSet<cStringResEntry *, char const *, cCaselessStringHashFuncs> *thisa; // [sp+4h] [bp-1Ch]@1
	sHashSetChunk *pNext; // [sp+14h] [bp-Ch]@6
	sHashSetChunk *p; // [sp+18h] [bp-8h]@4
	unsigned int i; // [sp+1Ch] [bp-4h]@2

	thisa = this;
	if (this->baseclass_0.m_nItems)
	{
		for (i = 0; i < thisa->baseclass_0.m_nPts; ++i)
		{
			for (p = thisa->baseclass_0.m_Table[i]; p; p = pNext)
			{
				pNext = p->pNext;
				if (p->node)
					cStringResEntry::_scalar_deleting_destructor_((cStringResEntry *)p->node, 1u);
				sHashSetChunk::operator delete(p, 8u);
			}
			thisa->baseclass_0.m_Table[i] = 0;
		}
		thisa->baseclass_0.m_nItems = 0;
	}
}

//----- (008EB680) --------------------------------------------------------
void *__thiscall cStringResEntry::_scalar_deleting_destructor_(cStringResEntry *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStringResEntry::_cStringResEntry(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}













//----- (008EF8A0) --------------------------------------------------------
int __cdecl ResBaseExtractCallback(void *pBuf, int nNumBytes, int nIx, void *pData)
{
	return (*((int(__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))pData + 1))(
		*(_DWORD *)pData,
		pBuf,
		nNumBytes,
		nIx,
		*((_DWORD *)pData + 2));
}

//----- (008EF8D0) --------------------------------------------------------
void __cdecl CanonicalizePathname(char *pPathname)
{
	char *p; // [sp+0h] [bp-4h]@1

	for (p = pPathname; *p; ++p)
	{
		if (*p == 92)
			*p = 47;
	}
}














//----- (008F37F0) --------------------------------------------------------
void __thiscall IStoreStream::IStoreStream(IStoreStream *this)
{
	IStoreStream *v1; // ST00_4@1

	v1 = this;
	IUnknown::IUnknown(&this->baseclass_0);
	v1->baseclass_0.vfptr = (IUnknownVtbl *)IStoreStream::_vftable_;
}
// 9A8CEC: using guessed type int (*IStoreStream___vftable_[15])();

//----- (008F3810) --------------------------------------------------------
void *__thiscall cFileSpec::_scalar_deleting_destructor_(cFileSpec *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cFileSpec::_cFileSpec(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}


















//----- (008F3FE0) --------------------------------------------------------
int __cdecl inflateReset(z_stream_s *z)
{
	int result; // eax@3

	if (z && z->state)
	{
		z->total_out = 0;
		z->total_in = 0;
		z->msg = 0;
		z->state->dummy = z->state[3].dummy != 0 ? 7 : 0;
		inflate_blocks_reset((inflate_blocks_state *)z->state[5].dummy, z, 0);
		if (z_verbose > 0)
			fprintf(&File, "inflate: reset\n");
		result = 0;
	}
	else
	{
		result = -2;
	}
	return result;
}
// EAC820: using guessed type int z_verbose;

//----- (008F4066) --------------------------------------------------------
int __cdecl inflateEnd(z_stream_s *z)
{
	int result; // eax@4

	if (z && z->state && z->zfree)
	{
		if (z->state[5].dummy)
			inflate_blocks_free((inflate_blocks_state *)z->state[5].dummy, z);
		z->zfree(z->opaque, z->state);
		z->state = 0;
		if (z_verbose > 0)
			fprintf(&File, "inflate: end\n");
		result = 0;
	}
	else
	{
		result = -2;
	}
	return result;
}
// EAC820: using guessed type int z_verbose;

//----- (008F40EA) --------------------------------------------------------
int __cdecl inflateInit2_(z_stream_s *z, int w, const char *version, int stream_size)
{
	int result; // eax@4

	if (version && *version == byte_B45624 && stream_size == 56)
	{
		if (z)
		{
			z->msg = 0;
			if (!z->zalloc)
			{
				z->zalloc = zcalloc;
				z->opaque = 0;
			}
			if (!z->zfree)
				z->zfree = zcfree;
			z->state = (internal_state *)z->zalloc(z->opaque, 1u, 24u);
			if (z->state)
			{
				z->state[5].dummy = 0;
				z->state[3].dummy = 0;
				if (w < 0)
				{
					w = -w;
					z->state[3].dummy = 1;
				}
				if (w >= 8 && w <= 15)
				{
					z->state[4].dummy = w;
					z->state[5].dummy = (int)inflate_blocks_new(
						z,
						(unsigned int(__cdecl *)(unsigned int, const char *, unsigned int))(z->state[3].dummy == 0 ? (int)adler32 : 0),
						1 << w);
					if (z->state[5].dummy)
					{
						if (z_verbose > 0)
							fprintf(&File, "inflate: allocated\n");
						inflateReset(z);
						result = 0;
					}
					else
					{
						inflateEnd(z);
						result = -4;
					}
				}
				else
				{
					inflateEnd(z);
					result = -2;
				}
			}
			else
			{
				result = -4;
			}
		}
		else
		{
			result = -2;
		}
	}
	else
	{
		result = -6;
	}
	return result;
}
// B45624: using guessed type char byte_B45624;
// EAC820: using guessed type int z_verbose;

//----- (008F426E) --------------------------------------------------------
int __cdecl inflateInit_(z_stream_s *z, const char *version, int stream_size)
{
	return inflateInit2_(z, 15, version, stream_size);
}

//----- (008F4289) --------------------------------------------------------
int __cdecl inflate(z_stream_s *z, int f)
{
	int result; // eax@4
	int v3; // eax@5
	int v4; // ecx@9
	int realf; // [sp+4h] [bp-Ch]@1
	signed int r; // [sp+8h] [bp-8h]@5
	int b; // [sp+Ch] [bp-4h]@16
	int fa; // [sp+1Ch] [bp+Ch]@5

	realf = f;
	if (z && z->state && z->next_in)
	{
		v3 = (f != 4) - 1;
		LOBYTE(v3) = v3 & 0xFB;
		fa = v3;
		r = -5;
		while (2)
		{
			switch (z->state->dummy)
			{
			case 0:
				if (z->avail_in)
				{
					r = fa;
					--z->avail_in;
					++z->total_in;
					z->state[1].dummy = *z->next_in;
					v4 = z->state[1].dummy & 0xF;
					++z->next_in;
					if (v4 != 8)
					{
						z->state->dummy = 13;
						z->msg = "unknown compression method";
						z->state[1].dummy = 5;
						continue;
					}
					if (((unsigned int)z->state[1].dummy >> 4) + 8 > z->state[4].dummy)
					{
						z->state->dummy = 13;
						z->msg = "invalid window size";
						z->state[1].dummy = 5;
						continue;
					}
					z->state->dummy = 1;
					goto $L1386_1;
				}
				result = r;
				break;
			case 1:
			$L1386_1 :
				if (z->avail_in)
				{
				r = fa;
				--z->avail_in;
				++z->total_in;
				b = *z->next_in++;
				if ((b + (z->state[1].dummy << 8)) % 0x1Fu)
				{
					z->state->dummy = 13;
					z->msg = "incorrect header check";
					z->state[1].dummy = 5;
					continue;
				}
				if (z_verbose > 0)
					fprintf(&File, "inflate: zlib header ok\n");
				if (!(b & 0x20))
				{
					z->state->dummy = 7;
					continue;
				}
				z->state->dummy = 2;
				goto $L1394;
				}
					 result = r;
					 break;
			case 2:
			$L1394 :
				if (z->avail_in)
				{
				r = fa;
				--z->avail_in;
				++z->total_in;
				z->state[2].dummy = *z->next_in++ << 24;
				z->state->dummy = 3;
				goto $L1397;
				}
				   result = r;
				   break;
			case 3:
			$L1397 :
				if (z->avail_in)
				{
				r = fa;
				--z->avail_in;
				++z->total_in;
				z->state[2].dummy += *z->next_in++ << 16;
				z->state->dummy = 4;
				goto $L1400;
				}
				   result = r;
				   break;
			case 4:
			$L1400 :
				if (z->avail_in)
				{
				r = fa;
				--z->avail_in;
				++z->total_in;
				z->state[2].dummy += *z->next_in++ << 8;
				z->state->dummy = 5;
				goto $L1403_1;
				}
				   result = r;
				   break;
			case 5:
			$L1403_1 :
				if (z->avail_in)
				{
				--z->avail_in;
				++z->total_in;
				z->state[2].dummy += *z->next_in++;
				z->adler = z->state[2].dummy;
				z->state->dummy = 6;
				result = 2;
				}
				else
				{
					result = r;
				}
					 break;
			case 6:
				z->state->dummy = 13;
				z->msg = "need dictionary";
				z->state[1].dummy = 0;
				result = -2;
				break;
			case 7:
				r = inflate_blocks((inflate_blocks_state *)z->state[5].dummy, z, r);
				if (r == -3)
				{
					z->state->dummy = 13;
					z->state[1].dummy = 0;
					continue;
				}
				if (r || z->avail_in || z->avail_out || realf != 4)
				{
					if (!r)
						r = fa;
				}
				else
				{
					r = 1;
				}
				if (r == 1)
				{
					r = fa;
					inflate_blocks_reset((inflate_blocks_state *)z->state[5].dummy, z, (unsigned int *)&z->state[1]);
					if (z->state[3].dummy)
					{
						z->state->dummy = 12;
						continue;
					}
					z->state->dummy = 8;
					goto $L1416_0;
				}
				result = r;
				break;
			case 8:
			$L1416_0 :
				if (z->avail_in)
				{
				r = fa;
				--z->avail_in;
				++z->total_in;
				z->state[2].dummy = *z->next_in++ << 24;
				z->state->dummy = 9;
				goto $L1419_0;
				}
					 result = r;
					 break;
			case 9:
			$L1419_0 :
				if (z->avail_in)
				{
				r = fa;
				--z->avail_in;
				++z->total_in;
				z->state[2].dummy += *z->next_in++ << 16;
				z->state->dummy = 10;
				goto $L1422_1;
				}
					 result = r;
					 break;
			case 0xA:
			$L1422_1 :
				if (z->avail_in)
				{
				r = fa;
				--z->avail_in;
				++z->total_in;
				z->state[2].dummy += *z->next_in++ << 8;
				z->state->dummy = 11;
				goto $L1425;
				}
					 result = r;
					 break;
			case 0xB:
			$L1425 :
				if (z->avail_in)
				{
				r = fa;
				--z->avail_in;
				++z->total_in;
				z->state[2].dummy += *z->next_in++;
				if (z->state[1].dummy != z->state[2].dummy)
				{
					z->state->dummy = 13;
					z->msg = "incorrect data check";
					z->state[1].dummy = 5;
					continue;
				}
				if (z_verbose > 0)
					fprintf(&File, "inflate: zlib check ok\n");
				z->state->dummy = 12;
				goto $L1433;
				}
				   result = r;
				   break;
			case 0xC:
			$L1433 :
				result = 1;
				   break;
			case 0xD:
				result = -3;
				break;
			default:
				result = -2;
				break;
			}
			break;
		}
	}
	else
	{
		result = -2;
	}
	return result;
}
// EAC820: using guessed type int z_verbose;

//----- (008F49BC) --------------------------------------------------------
int __cdecl inflateSetDictionary(z_stream_s *z, const char *dictionary, unsigned int dictLength)
{
	int result; // eax@4
	unsigned int length; // [sp+0h] [bp-4h]@1

	length = dictLength;
	if (z && z->state && z->state->dummy == 6)
	{
		if (adler32(1u, dictionary, dictLength) == z->adler)
		{
			z->adler = 1;
			if (dictLength >= 1 << z->state[4].dummy)
			{
				length = (1 << z->state[4].dummy) - 1;
				dictionary += dictLength - length;
			}
			inflate_set_dictionary((inflate_blocks_state *)z->state[5].dummy, dictionary, length);
			z->state->dummy = 7;
			result = 0;
		}
		else
		{
			result = -3;
		}
	}
	else
	{
		result = -2;
	}
	return result;
}

//----- (008F4A7A) --------------------------------------------------------
int __cdecl inflateSync(z_stream_s *z)
{
	int result; // eax@3
	unsigned int v2; // ST10_4@19
	unsigned int v3; // ST0C_4@19
	unsigned int n; // [sp+0h] [bp-14h]@6
	int m; // [sp+4h] [bp-10h]@8
	char *p; // [sp+10h] [bp-4h]@8

	if (z && z->state)
	{
		if (z->state->dummy != 13)
		{
			z->state->dummy = 13;
			z->state[1].dummy = 0;
		}
		n = z->avail_in;
		if (n)
		{
			p = z->next_in;
			m = z->state[1].dummy;
			while (n && (unsigned int)m < 4)
			{
				if (*p == mark[m])
				{
					++m;
				}
				else
				{
					if (*p)
						m = 0;
					else
						m = 4 - m;
				}
				++p;
				--n;
			}
			z->total_in += p - z->next_in;
			z->next_in = p;
			z->avail_in = n;
			z->state[1].dummy = m;
			if (m == 4)
			{
				v2 = z->total_in;
				v3 = z->total_out;
				inflateReset(z);
				z->total_in = v2;
				z->total_out = v3;
				z->state->dummy = 7;
				result = 0;
			}
			else
			{
				result = -3;
			}
		}
		else
		{
			result = -5;
		}
	}
	else
	{
		result = -2;
	}
	return result;
}

//----- (008F4BCC) --------------------------------------------------------
int __cdecl inflateSyncPoint(z_stream_s *z)
{
	int result; // eax@4

	if (z && z->state && z->state[5].dummy)
		result = inflate_blocks_sync_point((inflate_blocks_state *)z->state[5].dummy);
	else
		result = -2;
	return result;
}

//----- (008F4C10) --------------------------------------------------------
const char *__cdecl zlibVersion()
{
	return "1.1.2";
}

//----- (008F4C1A) --------------------------------------------------------
void __cdecl z_error(char *m)
{
	fprintf(&File, "%s\n", m);
	exit(1);
}

//----- (008F4C3F) --------------------------------------------------------
const char *__cdecl zError(int err)
{
	return z_errmsg[2 - err];
}
// B456E4: using guessed type char *z_errmsg[2];

//----- (008F4C53) --------------------------------------------------------
void *__cdecl zcalloc(void *opaque, unsigned int items, unsigned int size)
{
	return j__calloc(items, size);
}

//----- (008F4C7C) --------------------------------------------------------
void __cdecl zcfree(void *opaque, void *ptr)
{
	j__free(ptr);
}

//----- (008F4C90) --------------------------------------------------------
void __cdecl inflate_blocks_reset(inflate_blocks_state *s, z_stream_s *z, unsigned int *c)
{
	if (c)
		*c = s->check;
	if (s->mode == 4 || s->mode == 5)
		z->zfree(z->opaque, s->sub.trees.blens);
	if (s->mode == 6)
		inflate_codes_free((inflate_codes_state *)s->sub.left, z);
	s->mode = 0;
	s->bitk = 0;
	s->bitb = 0;
	s->write = s->window;
	s->read = s->write;
	if (s->checkfn)
	{
		s->check = s->checkfn(0, 0, 0);
		z->adler = s->check;
	}
	if (z_verbose > 0)
		fprintf(&File, "inflate:   blocks reset\n");
}
// EAC820: using guessed type int z_verbose;

//----- (008F4D62) --------------------------------------------------------
inflate_blocks_state *__cdecl inflate_blocks_new(z_stream_s *z, unsigned int(__cdecl *c)(unsigned int, const char *, unsigned int), unsigned int w)
{
	inflate_blocks_state *result; // eax@2
	inflate_blocks_state *v4; // ST0C_4@9
	int s; // [sp+0h] [bp-4h]@0
	int sa; // [sp+0h] [bp-4h]@3
	int sb; // [sp+0h] [bp-4h]@5

	if (((int(__stdcall *)(void *))z->zalloc)(z->opaque))
	{
		*(_DWORD *)(s + 36) = z->zalloc(z->opaque, 8u, 1440u);
		if (*(_DWORD *)(sa + 36))
		{
			*(_DWORD *)(sa + 40) = z->zalloc(z->opaque, 1u, w);
			if (*(_DWORD *)(sb + 40))
			{
				*(_DWORD *)(sb + 44) = w + *(_DWORD *)(sb + 40);
				*(_DWORD *)(sb + 56) = c;
				*(_DWORD *)sb = 0;
				if (z_verbose > 0)
					fprintf(&File, "inflate:   blocks allocated\n");
				inflate_blocks_reset(0, z, 0);
				result = v4;
			}
			else
			{
				z->zfree(z->opaque, *(void **)(sb + 36));
				((void(__cdecl *)(void *))z->zfree)(z->opaque);
				result = 0;
			}
		}
		else
		{
			((void(__cdecl *)(void *))z->zfree)(z->opaque);
			result = 0;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}
// EAC820: using guessed type int z_verbose;

//----- (008F4E75) --------------------------------------------------------
int __cdecl inflate_blocks(inflate_blocks_state *s, z_stream_s *z, int r)
{
	int result; // eax@9
	char *v4; // [sp+0h] [bp-90h]@158
	unsigned int v5; // [sp+4h] [bp-8Ch]@147
	char *v6; // [sp+8h] [bp-88h]@143
	unsigned int v7; // [sp+Ch] [bp-84h]@125
	int v8; // [sp+10h] [bp-80h]@113
	unsigned int v9; // [sp+14h] [bp-7Ch]@73
	char *v10; // [sp+18h] [bp-78h]@61
	char *v11; // [sp+1Ch] [bp-74h]@56
	char *v12; // [sp+20h] [bp-70h]@51
	int v13; // [sp+24h] [bp-6Ch]@42
	int *v14; // [sp+28h] [bp-68h]@27
	int *v15; // [sp+2Ch] [bp-64h]@19
	int *v16; // [sp+30h] [bp-60h]@13
	char *v17; // [sp+3Ch] [bp-54h]@2
	inflate_huft_s *v18; // [sp+40h] [bp-50h]@131
	unsigned int v19; // [sp+44h] [bp-4Ch]@131
	inflate_huft_s *v20; // [sp+48h] [bp-48h]@131
	inflate_codes_state *v21; // [sp+4Ch] [bp-44h]@137
	unsigned int v22; // [sp+50h] [bp-40h]@131
	int j; // [sp+54h] [bp-3Ch]@115
	unsigned int i; // [sp+58h] [bp-38h]@115
	inflate_huft_s *h; // [sp+5Ch] [bp-34h]@110
	unsigned int c; // [sp+60h] [bp-30h]@110
	inflate_huft_s *td; // [sp+64h] [bp-2Ch]@22
	unsigned int v28; // [sp+68h] [bp-28h]@22
	inflate_huft_s *tl; // [sp+6Ch] [bp-24h]@22
	unsigned int bd; // [sp+70h] [bp-20h]@22
	unsigned int n; // [sp+74h] [bp-1Ch]@1
	unsigned int m; // [sp+78h] [bp-18h]@4
	unsigned int k; // [sp+7Ch] [bp-14h]@1
	size_t t; // [sp+80h] [bp-10h]@10
	unsigned int b; // [sp+84h] [bp-Ch]@1
	char *q; // [sp+88h] [bp-8h]@1
	char *p; // [sp+8Ch] [bp-4h]@1
	int ra; // [sp+A0h] [bp+10h]@55
	int rb; // [sp+A0h] [bp+10h]@98
	int re; // [sp+A0h] [bp+10h]@134
	int rc; // [sp+A0h] [bp+10h]@140
	int rd; // [sp+A0h] [bp+10h]@157

	p = z->next_in;
	n = z->avail_in;
	b = s->bitb;
	k = s->bitk;
	q = s->write;
	if (q >= s->read)
		v17 = (char *)(s->end - q);
	else
		v17 = s->read + -(unsigned int)q - 1;
	m = (unsigned int)v17;
	while (2)
	{
		switch (s->mode)
		{
		case 0:
			while (2)
			{
				if (k < 3)
				{
					if (n)
					{
						r = 0;
						--n;
						b |= (unsigned __int8)*p++ << k;
						k += 8;
						continue;
					}
					s->bitb = b;
					s->bitk = k;
					z->avail_in = n;
					z->total_in += p - z->next_in;
					z->next_in = p;
					s->write = q;
					return inflate_flush(s, z, r);
				}
				break;
			}
			t = b & 7;
			s->last = b & 1;
			switch (t >> 1)
			{
			case 0u:
				if (z_verbose > 0)
				{
					if (s->last)
						v16 = (int *)" (last)";
					else
						v16 = &dword_EAC82C;
					fprintf(&File, "inflate:     stored block%s\n", v16);
				}
				b >>= 3;
				k -= 3;
				t = k & 7;
				b >>= k & 7;
				k -= t;
				s->mode = 1;
				continue;
			case 1u:
				if (z_verbose > 0)
				{
					if (s->last)
						v15 = (int *)" (last)";
					else
						v15 = &dword_EAC830;
					fprintf(&File, "inflate:     fixed codes block%s\n", v15);
				}
				inflate_trees_fixed(&v28, &bd, &tl, &td, z);
				s->sub.left = (unsigned int)inflate_codes_new(v28, bd, tl, td, z);
				if (!s->sub.left)
				{
					s->bitb = b;
					s->bitk = k;
					z->avail_in = n;
					z->total_in += p - z->next_in;
					z->next_in = p;
					s->write = q;
					return inflate_flush(s, z, -4);
				}
				b >>= 3;
				k -= 3;
				s->mode = 6;
				break;
			case 2u:
				if (z_verbose > 0)
				{
					if (s->last)
						v14 = (int *)" (last)";
					else
						v14 = &dword_EAC834;
					fprintf(&File, "inflate:     dynamic codes block%s\n", v14);
				}
				b >>= 3;
				k -= 3;
				s->mode = 3;
				continue;
			case 3u:
				b >>= 3;
				k -= 3;
				s->mode = 9;
				z->msg = "invalid block type";
				s->bitb = b;
				s->bitk = k;
				z->avail_in = n;
				z->total_in += p - z->next_in;
				z->next_in = p;
				s->write = q;
				return inflate_flush(s, z, -3);
			default:
				continue;
			}
			continue;
		case 1:
			while (2)
			{
				if (k < 0x20)
				{
					if (n)
					{
						r = 0;
						--n;
						b |= (unsigned __int8)*p++ << k;
						k += 8;
						continue;
					}
					s->bitb = b;
					s->bitk = k;
					z->avail_in = n;
					z->total_in += p - z->next_in;
					z->next_in = p;
					s->write = q;
					return inflate_flush(s, z, r);
				}
				break;
			}
			if ((unsigned __int16)(~b >> 16) >> 8 != (unsigned __int16)b)
			{
				s->mode = 9;
				z->msg = "invalid stored block lengths";
				s->bitb = b;
				s->bitk = k;
				z->avail_in = n;
				z->total_in += p - z->next_in;
				z->next_in = p;
				s->write = q;
				return inflate_flush(s, z, -3);
			}
			s->sub.left = (unsigned __int16)b;
			k = 0;
			b = 0;
			if (z_verbose > 0)
				fprintf(&File, "inflate:       stored length %u\n", s->sub.left);
			if (s->sub.left)
				v13 = 2;
			else
				v13 = s->last != 0 ? 7 : 0;
			s->mode = v13;
			continue;
		case 2:
			if (!n)
			{
				s->bitb = b;
				s->bitk = k;
				z->avail_in = n;
				z->total_in += p - z->next_in;
				z->next_in = p;
				s->write = q;
				return inflate_flush(s, z, r);
			}
			if (!m)
			{
				if (q == s->end && s->read != s->window)
				{
					q = s->window;
					if (q >= s->read)
						v12 = (char *)(s->end - q);
					else
						v12 = s->read + -(unsigned int)q - 1;
					m = (unsigned int)v12;
				}
				if (!m)
				{
					s->write = q;
					ra = inflate_flush(s, z, r);
					q = s->write;
					if (q >= s->read)
						v11 = (char *)(s->end - q);
					else
						v11 = s->read + -(unsigned int)q - 1;
					m = (unsigned int)v11;
					if (q == s->end && s->read != s->window)
					{
						q = s->window;
						if (q >= s->read)
							v10 = (char *)(s->end - q);
						else
							v10 = s->read + -(unsigned int)q - 1;
						m = (unsigned int)v10;
					}
					if (!m)
					{
						s->bitb = b;
						s->bitk = k;
						z->avail_in = n;
						z->total_in += p - z->next_in;
						z->next_in = p;
						s->write = q;
						return inflate_flush(s, z, ra);
					}
				}
			}
			r = 0;
			t = s->sub.left;
			if (t > n)
				t = n;
			if (t > m)
				t = m;
			memcpy(q, p, t);
			p += t;
			n -= t;
			q += t;
			m -= t;
			s->sub.left -= t;
			if (!s->sub.left)
			{
				if (z_verbose > 0)
				{
					if (q < s->read)
						v9 = q - s->window + s->end - s->read;
					else
						v9 = q - s->read;
					fprintf(&File, "inflate:       stored end, %lu total out\n", v9 + z->total_out);
				}
				s->mode = s->last != 0 ? 7 : 0;
			}
			continue;
		case 3:
		$L1501_1 :
			if (k >= 0xE)
			{
			t = b & 0x3FFF;
			s->sub.left = b & 0x3FFF;
			if ((t & 0x1F) > 0x1D || ((t >> 5) & 0x1F) > 0x1D)
			{
				s->mode = 9;
				z->msg = "too many length or distance symbols";
				s->bitb = b;
				s->bitk = k;
				z->avail_in = n;
				z->total_in += p - z->next_in;
				z->next_in = p;
				s->write = q;
				return inflate_flush(s, z, -3);
			}
			t = (t & 0x1F) + ((t >> 5) & 0x1F) + 258;
			s->sub.trees.blens = (unsigned int *)z->zalloc(z->opaque, t, 4u);
			if (!s->sub.trees.blens)
			{
				s->bitb = b;
				s->bitk = k;
				z->avail_in = n;
				z->total_in += p - z->next_in;
				z->next_in = p;
				s->write = q;
				return inflate_flush(s, z, -4);
			}
			b >>= 14;
			k -= 14;
			s->sub.trees.index = 0;
			if (z_verbose > 0)
				fprintf(&File, "inflate:       table sizes ok\n");
			s->mode = 4;
		$L1518:
			while (s->sub.trees.index < (s->sub.left >> 10) + 4)
			{
				while (k < 3)
				{
					if (!n)
					{
						s->bitb = b;
						s->bitk = k;
						z->avail_in = n;
						z->total_in += p - z->next_in;
						z->next_in = p;
						s->write = q;
						return inflate_flush(s, z, r);
					}
					r = 0;
					--n;
					b |= (unsigned __int8)*p++ << k;
					k += 8;
				}
				s->sub.trees.blens[border[s->sub.trees.index++]] = b & 7;
				b >>= 3;
				k -= 3;
			}
			while (s->sub.trees.index < 0x13)
				s->sub.trees.blens[border[s->sub.trees.index++]] = 0;
			s->sub.trees.bb = 7;
			t = inflate_trees_bits(s->sub.trees.blens, &s->sub.trees.bb, &s->sub.trees.tb, s->hufts, z);
			if (t)
			{
				z->zfree(z->opaque, s->sub.trees.blens);
				rb = t;
				if (t == -3)
					s->mode = 9;
				s->bitb = b;
				s->bitk = k;
				z->avail_in = n;
				z->total_in += p - z->next_in;
				z->next_in = p;
				s->write = q;
				return inflate_flush(s, z, rb);
			}
			s->sub.trees.index = 0;
			if (z_verbose > 0)
				fprintf(&File, "inflate:       bits tree ok\n");
			s->mode = 5;
		$L1537_1:
			while (1)
			{
				t = s->sub.left;
				if (s->sub.trees.index >= (t & 0x1F) + ((t >> 5) & 0x1F) + 258)
					break;
				t = s->sub.trees.bb;
				while (k < t)
				{
					if (!n)
					{
						s->bitb = b;
						s->bitk = k;
						z->avail_in = n;
						z->total_in += p - z->next_in;
						z->next_in = p;
						s->write = q;
						return inflate_flush(s, z, r);
					}
					r = 0;
					--n;
					b |= (unsigned __int8)*p++ << k;
					k += 8;
				}
				h = &s->sub.trees.tb[inflate_mask[t] & b];
				t = h->word.what.Bits;
				c = h->base;
				if (c >= 0x10)
				{
					if (c == 18)
						v8 = 7;
					else
						v8 = c - 14;
					i = v8;
					j = c != 18 ? 3 : 11;
					while (k < i + t)
					{
						if (!n)
						{
							s->bitb = b;
							s->bitk = k;
							z->avail_in = n;
							z->total_in += p - z->next_in;
							z->next_in = p;
							s->write = q;
							return inflate_flush(s, z, r);
						}
						r = 0;
						--n;
						b |= (unsigned __int8)*p++ << k;
						k += 8;
					}
					b >>= t;
					k -= t;
					j += inflate_mask[i] & b;
					b >>= i;
					k -= i;
					i = s->sub.trees.index;
					t = s->sub.left;
					if (j + i > (t & 0x1F) + ((t >> 5) & 0x1F) + 258 || c == 16 && i < 1)
					{
						z->zfree(z->opaque, s->sub.trees.blens);
						s->mode = 9;
						z->msg = "invalid bit length repeat";
						s->bitb = b;
						s->bitk = k;
						z->avail_in = n;
						z->total_in += p - z->next_in;
						z->next_in = p;
						s->write = q;
						return inflate_flush(s, z, -3);
					}
					if (c == 16)
						v7 = s->sub.trees.blens[i - 1];
					else
						v7 = 0;
					c = v7;
					do
					{
						s->sub.trees.blens[i++] = c;
						--j;
					} while (j);
					s->sub.trees.index = i;
				}
				else
				{
					b >>= t;
					k -= t;
					s->sub.trees.blens[s->sub.trees.index++] = c;
				}
			}
			s->sub.trees.tb = 0;
			v19 = 9;
			v22 = 6;
			t = s->sub.left;
			t = inflate_trees_dynamic(
				(t & 0x1F) + 257,
				((t >> 5) & 0x1F) + 1,
				s->sub.trees.blens,
				&v19,
				&v22,
				&v20,
				&v18,
				s->hufts,
				z);
			z->zfree(z->opaque, s->sub.trees.blens);
			if (t)
			{
				if (t == -3)
					s->mode = 9;
				re = t;
				s->bitb = b;
				s->bitk = k;
				z->avail_in = n;
				z->total_in += p - z->next_in;
				z->next_in = p;
				s->write = q;
				return inflate_flush(s, z, re);
			}
			if (z_verbose > 0)
				fprintf(&File, "inflate:       trees ok\n");
			v21 = inflate_codes_new(v19, v22, v20, v18, z);
			if (!v21)
			{
				s->bitb = b;
				s->bitk = k;
				z->avail_in = n;
				z->total_in += p - z->next_in;
				z->next_in = p;
				s->write = q;
				return inflate_flush(s, z, -4);
			}
			s->sub.left = (unsigned int)v21;
			s->mode = 6;
		$L1581_1:
			s->bitb = b;
			s->bitk = k;
			z->avail_in = n;
			z->total_in += p - z->next_in;
			z->next_in = p;
			s->write = q;
			rc = inflate_codes(s, z, r);
			if (rc != 1)
				return inflate_flush(s, z, rc);
			r = 0;
			inflate_codes_free((inflate_codes_state *)s->sub.left, z);
			p = z->next_in;
			n = z->avail_in;
			b = s->bitb;
			k = s->bitk;
			q = s->write;
			if (q >= s->read)
				v6 = (char *)(s->end - q);
			else
				v6 = s->read + -(unsigned int)q - 1;
			m = (unsigned int)v6;
			if (z_verbose > 0)
			{
				if (q < s->read)
					v5 = q - s->window + s->end - s->read;
				else
					v5 = q - s->read;
				fprintf(&File, "inflate:       codes end, %lu total out\n", v5 + z->total_out);
			}
			if (s->last)
			{
				if (k > 7)
				{
					if (k >= 0x10)
						z_error("inflate_codes grabbed too many bytes");
					k -= 8;
					++n;
					--p;
				}
				s->mode = 7;
			$L1591_1:
				s->write = q;
				rd = inflate_flush(s, z, r);
				q = s->write;
				if (q >= s->read)
					v4 = (char *)(s->end - q);
				else
					v4 = s->read + -(unsigned int)q - 1;
				m = (unsigned int)v4;
				if (s->read == s->write)
				{
					s->mode = 8;
				$L1595_1:
					s->bitb = b;
					s->bitk = k;
					z->avail_in = n;
					z->total_in += p - z->next_in;
					z->next_in = p;
					s->write = q;
					result = inflate_flush(s, z, 1);
				}
				else
				{
					s->bitb = b;
					s->bitk = k;
					z->avail_in = n;
					z->total_in += p - z->next_in;
					z->next_in = p;
					s->write = q;
					result = inflate_flush(s, z, rd);
				}
				return result;
			}
			s->mode = 0;
			continue;
			}
				 if (n)
				 {
					 r = 0;
					 --n;
					 b |= (unsigned __int8)*p++ << k;
					 k += 8;
					 goto $L1501_1;
				 }
				 s->bitb = b;
				 s->bitk = k;
				 z->avail_in = n;
				 z->total_in += p - z->next_in;
				 z->next_in = p;
				 s->write = q;
				 return inflate_flush(s, z, r);
		case 4:
			goto $L1518;
		case 5:
			goto $L1537_1;
		case 6:
			goto $L1581_1;
		case 7:
			goto $L1591_1;
		case 8:
			goto $L1595_1;
		case 9:
			s->bitb = b;
			s->bitk = k;
			z->avail_in = n;
			z->total_in += p - z->next_in;
			z->next_in = p;
			s->write = q;
			return inflate_flush(s, z, -3);
		default:
			s->bitb = b;
			s->bitk = k;
			z->avail_in = n;
			z->total_in += p - z->next_in;
			z->next_in = p;
			s->write = q;
			return inflate_flush(s, z, -2);
		}
	}
}
// B46CE8: using guessed type int inflate_mask[];
// EAC820: using guessed type int z_verbose;
// EAC82C: using guessed type int dword_EAC82C;
// EAC830: using guessed type int dword_EAC830;
// EAC834: using guessed type int dword_EAC834;

//----- (008F640E) --------------------------------------------------------
int __cdecl inflate_blocks_free(inflate_blocks_state *s, z_stream_s *z)
{
	inflate_blocks_reset(s, z, 0);
	z->zfree(z->opaque, s->window);
	z->zfree(z->opaque, s->hufts);
	z->zfree(z->opaque, s);
	if (z_verbose > 0)
		fprintf(&File, "inflate:   blocks freed\n");
	return 0;
}
// EAC820: using guessed type int z_verbose;

//----- (008F6484) --------------------------------------------------------
void __cdecl inflate_set_dictionary(inflate_blocks_state *s, const char *d, unsigned int n)
{
	memcpy(s->window, d, n);
	s->write = &s->window[n];
	s->read = s->write;
}

//----- (008F64BB) --------------------------------------------------------
int __cdecl inflate_blocks_sync_point(inflate_blocks_state *s)
{
	return s->mode == 1;
}

//----- (008F64D0) --------------------------------------------------------
unsigned int __cdecl adler32(unsigned int adler, const char *buf, unsigned int len)
{
	unsigned int result; // eax@2
	int v4; // ST0C_4@9
	int v5; // ST08_4@9
	int v6; // ST0C_4@9
	int v7; // ST08_4@9
	int v8; // ST0C_4@9
	int v9; // ST08_4@9
	int v10; // ST0C_4@9
	int v11; // ST08_4@9
	int v12; // ST0C_4@9
	int v13; // ST08_4@9
	int v14; // ST0C_4@9
	int v15; // ST08_4@9
	int v16; // ST0C_4@9
	int v17; // ST08_4@9
	int v18; // ST0C_4@9
	int v19; // ST08_4@9
	int v20; // ST0C_4@9
	int v21; // ST08_4@9
	int v22; // ST0C_4@9
	int v23; // ST08_4@9
	int v24; // ST0C_4@9
	int v25; // ST08_4@9
	int v26; // ST0C_4@9
	int v27; // ST08_4@9
	int v28; // ST0C_4@9
	int v29; // ST08_4@9
	int v30; // ST0C_4@9
	int v31; // ST08_4@9
	int v32; // ST0C_4@9
	int v33; // ST08_4@9
	unsigned int v34; // [sp+0h] [bp-10h]@5
	signed int k; // [sp+4h] [bp-Ch]@7
	unsigned int s2; // [sp+8h] [bp-8h]@1
	unsigned int s1; // [sp+Ch] [bp-4h]@1

	s1 = (unsigned __int16)adler;
	s2 = adler >> 16;
	if (buf)
	{
		while (len)
		{
			if (len >= 0x15B0)
				v34 = 5552;
			else
				v34 = len;
			k = v34;
			len -= v34;
			while (k >= 16)
			{
				v4 = (unsigned __int8)*buf + s1;
				v5 = v4 + s2;
				v6 = (unsigned __int8)buf[1] + v4;
				v7 = v6 + v5;
				v8 = (unsigned __int8)buf[2] + v6;
				v9 = v8 + v7;
				v10 = (unsigned __int8)buf[3] + v8;
				v11 = v10 + v9;
				v12 = (unsigned __int8)buf[4] + v10;
				v13 = v12 + v11;
				v14 = (unsigned __int8)buf[5] + v12;
				v15 = v14 + v13;
				v16 = (unsigned __int8)buf[6] + v14;
				v17 = v16 + v15;
				v18 = (unsigned __int8)buf[7] + v16;
				v19 = v18 + v17;
				v20 = (unsigned __int8)buf[8] + v18;
				v21 = v20 + v19;
				v22 = (unsigned __int8)buf[9] + v20;
				v23 = v22 + v21;
				v24 = (unsigned __int8)buf[10] + v22;
				v25 = v24 + v23;
				v26 = (unsigned __int8)buf[11] + v24;
				v27 = v26 + v25;
				v28 = (unsigned __int8)buf[12] + v26;
				v29 = v28 + v27;
				v30 = (unsigned __int8)buf[13] + v28;
				v31 = v30 + v29;
				v32 = (unsigned __int8)buf[14] + v30;
				v33 = v32 + v31;
				s1 = (unsigned __int8)buf[15] + v32;
				s2 = s1 + v33;
				buf += 16;
				k -= 16;
			}
			for (; k; --k)
			{
				s1 += (unsigned __int8)*buf++;
				s2 += s1;
			}
			s1 %= 0xFFF1u;
			s2 %= 0xFFF1u;
		}
		result = s1 | (s2 << 16);
	}
	else
	{
		result = 1;
	}
	return result;
}

//----- (008F6750) --------------------------------------------------------
inflate_codes_state *__cdecl inflate_codes_new(unsigned int bl, unsigned int bd, inflate_huft_s *tl, inflate_huft_s *td, z_stream_s *z)
{
	int c; // [sp+0h] [bp-4h]@1

	c = ((int(__stdcall *)(_DWORD))z->zalloc)(z->opaque);
	if (c)
	{
		*(_DWORD *)c = 0;
		*(_BYTE *)(c + 16) = bl;
		*(_BYTE *)(c + 17) = bd;
		*(_DWORD *)(c + 18) = tl;
		*(_DWORD *)(c + 22) = td;
		if (z_verbose > 0)
			fprintf(&File, "inflate:       codes new\n");
	}
	return (inflate_codes_state *)c;
}
// EAC820: using guessed type int z_verbose;

//----- (008F67C0) --------------------------------------------------------
int __cdecl inflate_codes(inflate_blocks_state *s, z_stream_s *z, int r)
{
	int result; // eax@18
	char *v4; // [sp+4h] [bp-58h]@104
	char *v5; // [sp+8h] [bp-54h]@99
	char *v6; // [sp+Ch] [bp-50h]@94
	char *v7; // [sp+10h] [bp-4Ch]@81
	char *v8; // [sp+14h] [bp-48h]@76
	char *v9; // [sp+18h] [bp-44h]@71
	int v10; // [sp+1Ch] [bp-40h]@63
	const char *Format; // [sp+20h] [bp-3Ch]@23
	char *v12; // [sp+24h] [bp-38h]@9
	char *v13; // [sp+2Ch] [bp-30h]@2
	unsigned int n; // [sp+30h] [bp-2Ch]@1
	unsigned int m; // [sp+34h] [bp-28h]@4
	unsigned int k; // [sp+38h] [bp-24h]@1
	unsigned int j; // [sp+3Ch] [bp-20h]@14
	unsigned int ja; // [sp+3Ch] [bp-20h]@36
	unsigned int jb; // [sp+3Ch] [bp-20h]@44
	int jc; // [sp+3Ch] [bp-20h]@54
	char *f; // [sp+40h] [bp-1Ch]@65
	int e; // [sp+44h] [bp-18h]@19
	int ea; // [sp+44h] [bp-18h]@49
	int t; // [sp+48h] [bp-14h]@19
	int ta; // [sp+48h] [bp-14h]@49
	unsigned int c; // [sp+4Ch] [bp-10h]@1
	unsigned int b; // [sp+50h] [bp-Ch]@1
	char *q; // [sp+54h] [bp-8h]@1
	char *p; // [sp+58h] [bp-4h]@1
	int ra; // [sp+6Ch] [bp+10h]@75
	int rb; // [sp+6Ch] [bp+10h]@98
	int rc; // [sp+6Ch] [bp+10h]@110

	c = s->sub.left;
	p = z->next_in;
	n = z->avail_in;
	b = s->bitb;
	k = s->bitk;
	q = s->write;
	if (q >= s->read)
		v13 = (char *)(s->end - q);
	else
		v13 = s->read + -(unsigned int)q - 1;
	m = (unsigned int)v13;
	while (2)
	{
		switch (*(_DWORD *)c)
		{
		case 0:
			if (m >= 0x102 && n >= 0xA)
			{
				s->bitb = b;
				s->bitk = k;
				z->avail_in = n;
				z->total_in += p - z->next_in;
				z->next_in = p;
				s->write = q;
				r = inflate_fast(
					*(_BYTE *)(c + 16),
					*(_BYTE *)(c + 17),
					*(inflate_huft_s **)(c + 18),
					*(inflate_huft_s **)(c + 22),
					s,
					z);
				p = z->next_in;
				n = z->avail_in;
				b = s->bitb;
				k = s->bitk;
				q = s->write;
				v12 = (char *)(q >= s->read ? s->end - q : s->read + -(unsigned int)q - 1);
				m = (unsigned int)v12;
				if (r)
				{
					*(_DWORD *)c = r != 1 ? 9 : 7;
					continue;
				}
			}
			*(_DWORD *)(c + 12) = *(_BYTE *)(c + 16);
			*(_DWORD *)(c + 8) = *(_DWORD *)(c + 18);
			*(_DWORD *)c = 1;
			goto $L1461;
		case 1:
		$L1461 :
			j = *(_DWORD *)(c + 12);
			   while (2)
			   {
				   if (k < j)
				   {
					   if (n)
					   {
						   r = 0;
						   --n;
						   b |= (unsigned __int8)*p++ << k;
						   k += 8;
						   continue;
					   }
					   s->bitb = b;
					   s->bitk = k;
					   z->avail_in = 0;
					   z->total_in += p - z->next_in;
					   z->next_in = p;
					   s->write = q;
					   return inflate_flush(s, z, r);
				   }
				   break;
			   }
			   t = *(_DWORD *)(c + 8) + 8 * (inflate_mask[j] & b);
			   b >>= *(_BYTE *)(t + 1);
			   k -= *(_BYTE *)(t + 1);
			   e = *(_BYTE *)t;
			   if (*(_BYTE *)t)
			   {
				   if (e & 0x10)
				   {
					   *(_DWORD *)(c + 8) = e & 0xF;
					   *(_DWORD *)(c + 4) = *(_DWORD *)(t + 4);
					   *(_DWORD *)c = 2;
				   }
				   else
				   {
					   if (e & 0x40)
					   {
						   if (!(e & 0x20))
						   {
							   *(_DWORD *)c = 9;
							   z->msg = "invalid literal/length code";
							   s->bitb = b;
							   s->bitk = k;
							   z->avail_in = n;
							   z->total_in += p - z->next_in;
							   z->next_in = p;
							   s->write = q;
							   return inflate_flush(s, z, -3);
						   }
						   if (z_verbose > 1)
							   fprintf(&File, "inflate:         end of block\n");
						   *(_DWORD *)c = 7;
					   }
					   else
					   {
						   *(_DWORD *)(c + 12) = e;
						   *(_DWORD *)(c + 8) = t + 8 * *(_DWORD *)(t + 4);
					   }
				   }
			   }
			   else
			   {
				   *(_DWORD *)(c + 8) = *(_DWORD *)(t + 4);
				   if (z_verbose > 1)
				   {
					   if (*(_DWORD *)(t + 4) < 0x20u || *(_DWORD *)(t + 4) >= 0x7Fu)
						   Format = "inflate:         literal 0x%02x\n";
					   else
						   Format = "inflate:         literal '%c'\n";
					   fprintf(&File, Format, *(_DWORD *)(t + 4));
				   }
				   *(_DWORD *)c = 6;
			   }
			   continue;
		case 2:
			ja = *(_DWORD *)(c + 8);
			while (2)
			{
				if (k < ja)
				{
					if (n)
					{
						r = 0;
						--n;
						b |= (unsigned __int8)*p++ << k;
						k += 8;
						continue;
					}
					s->bitb = b;
					s->bitk = k;
					z->avail_in = 0;
					z->total_in += p - z->next_in;
					z->next_in = p;
					s->write = q;
					return inflate_flush(s, z, r);
				}
				break;
			}
			*(_DWORD *)(c + 4) += inflate_mask[ja] & b;
			b >>= ja;
			k -= ja;
			*(_DWORD *)(c + 12) = *(_BYTE *)(c + 17);
			*(_DWORD *)(c + 8) = *(_DWORD *)(c + 22);
			if (z_verbose > 1)
				fprintf(&File, "inflate:         length %u\n", *(_DWORD *)(c + 4));
			*(_DWORD *)c = 3;
		$L1491:
			jb = *(_DWORD *)(c + 12);
			while (k < jb)
			{
				if (!n)
				{
					s->bitb = b;
					s->bitk = k;
					z->avail_in = 0;
					z->total_in += p - z->next_in;
					z->next_in = p;
					s->write = q;
					return inflate_flush(s, z, r);
				}
				r = 0;
				--n;
				b |= (unsigned __int8)*p++ << k;
				k += 8;
			}
			ta = *(_DWORD *)(c + 8) + 8 * (inflate_mask[jb] & b);
			b >>= *(_BYTE *)(ta + 1);
			k -= *(_BYTE *)(ta + 1);
			ea = *(_BYTE *)ta;
			if (ea & 0x10)
			{
				*(_DWORD *)(c + 8) = ea & 0xF;
				*(_DWORD *)(c + 12) = *(_DWORD *)(ta + 4);
				*(_DWORD *)c = 4;
			}
			else
			{
				if (ea & 0x40)
				{
					*(_DWORD *)c = 9;
					z->msg = "invalid distance code";
					s->bitb = b;
					s->bitk = k;
					z->avail_in = n;
					z->total_in += p - z->next_in;
					z->next_in = p;
					s->write = q;
					return inflate_flush(s, z, -3);
				}
				*(_DWORD *)(c + 12) = ea;
				*(_DWORD *)(c + 8) = ta + 8 * *(_DWORD *)(ta + 4);
			}
			continue;
		case 3:
			goto $L1491;
		case 4:
			jc = *(_DWORD *)(c + 8);
		LABEL_55:
			if (k >= jc)
			{
				*(_DWORD *)(c + 12) += inflate_mask[jc] & b;
				b >>= jc;
				k -= jc;
				if (z_verbose > 1)
					fprintf(&File, "inflate:         distance %u\n", *(_DWORD *)(c + 12));
				*(_DWORD *)c = 5;
			$L1514:
				if (q - s->window >= *(_DWORD *)(c + 12))
					v10 = (int)&q[-*(_DWORD *)(c + 12)];
				else
					v10 = (int)&s->end[-(*(_DWORD *)(c + 12) - (q - s->window))];
				f = (char *)v10;
				while (*(_DWORD *)(c + 4))
				{
					if (!m)
					{
						if (q == s->end && s->read != s->window)
						{
							q = s->window;
							if (q >= s->read)
								v9 = (char *)(s->end - q);
							else
								v9 = s->read + -(unsigned int)q - 1;
							m = (unsigned int)v9;
						}
						if (!m)
						{
							s->write = q;
							ra = inflate_flush(s, z, r);
							q = s->write;
							if (q >= s->read)
								v8 = (char *)(s->end - q);
							else
								v8 = s->read + -(unsigned int)q - 1;
							m = (unsigned int)v8;
							if (q == s->end && s->read != s->window)
							{
								q = s->window;
								if (q >= s->read)
									v7 = (char *)(s->end - q);
								else
									v7 = s->read + -(unsigned int)q - 1;
								m = (unsigned int)v7;
							}
							if (!m)
							{
								s->bitb = b;
								s->bitk = k;
								z->avail_in = n;
								z->total_in += p - z->next_in;
								z->next_in = p;
								s->write = q;
								return inflate_flush(s, z, ra);
							}
						}
					}
					r = 0;
					*q++ = *f++;
					--m;
					if (f == s->end)
						f = s->window;
					--*(_DWORD *)(c + 4);
				}
				*(_DWORD *)c = 0;
				continue;
			}
			if (n)
			{
				r = 0;
				--n;
				b |= (unsigned __int8)*p++ << k;
				k += 8;
				goto LABEL_55;
			}
			s->bitb = b;
			s->bitk = k;
			z->avail_in = 0;
			z->total_in += p - z->next_in;
			z->next_in = p;
			s->write = q;
			return inflate_flush(s, z, r);
		case 5:
			goto $L1514;
		case 6:
			if (!m)
			{
				if (q == s->end && s->read != s->window)
				{
					q = s->window;
					if (q >= s->read)
						v6 = (char *)(s->end - q);
					else
						v6 = s->read + -(unsigned int)q - 1;
					m = (unsigned int)v6;
				}
				if (!m)
				{
					s->write = q;
					rb = inflate_flush(s, z, r);
					q = s->write;
					if (q >= s->read)
						v5 = (char *)(s->end - q);
					else
						v5 = s->read + -(unsigned int)q - 1;
					m = (unsigned int)v5;
					if (q == s->end && s->read != s->window)
					{
						q = s->window;
						if (q >= s->read)
							v4 = (char *)(s->end - q);
						else
							v4 = s->read + -(unsigned int)q - 1;
						m = (unsigned int)v4;
					}
					if (!m)
					{
						s->bitb = b;
						s->bitk = k;
						z->avail_in = n;
						z->total_in += p - z->next_in;
						z->next_in = p;
						s->write = q;
						return inflate_flush(s, z, rb);
					}
				}
			}
			r = 0;
			*q++ = *(_BYTE *)(c + 8);
			--m;
			*(_DWORD *)c = 0;
			continue;
		case 7:
			s->write = q;
			rc = inflate_flush(s, z, r);
			q = s->write;
			if (s->read == s->write)
			{
				*(_DWORD *)c = 8;
			$L1549_1:
				s->bitb = b;
				s->bitk = k;
				z->avail_in = n;
				z->total_in += p - z->next_in;
				z->next_in = p;
				s->write = q;
				result = inflate_flush(s, z, 1);
			}
			else
			{
				s->bitb = b;
				s->bitk = k;
				z->avail_in = n;
				z->total_in += p - z->next_in;
				z->next_in = p;
				s->write = q;
				result = inflate_flush(s, z, rc);
			}
			return result;
		case 8:
			goto $L1549_1;
		case 9:
			s->bitb = b;
			s->bitk = k;
			z->avail_in = n;
			z->total_in += p - z->next_in;
			z->next_in = p;
			s->write = q;
			return inflate_flush(s, z, -3);
		default:
			s->bitb = b;
			s->bitk = k;
			z->avail_in = n;
			z->total_in += p - z->next_in;
			z->next_in = p;
			s->write = q;
			return inflate_flush(s, z, -2);
		}
	}
}
// B46CE8: using guessed type int inflate_mask[];
// EAC820: using guessed type int z_verbose;

//----- (008F75A7) --------------------------------------------------------
void __cdecl inflate_codes_free(inflate_codes_state *c, z_stream_s *z)
{
	z->zfree(z->opaque, c);
	if (z_verbose > 0)
		fprintf(&File, "inflate:       codes free\n");
}
// EAC820: using guessed type int z_verbose;

//----- (008F75E0) --------------------------------------------------------
int __cdecl inflate_trees_bits(unsigned int *c, unsigned int *bb, inflate_huft_s **tb, inflate_huft_s *hp, z_stream_s *z)
{
	int result; // eax@2
	unsigned int *v; // [sp+0h] [bp-Ch]@1
	int hn; // [sp+4h] [bp-8h]@1
	int r; // [sp+8h] [bp-4h]@3

	hn = 0;
	v = (unsigned int *)z->zalloc(z->opaque, 19u, 4u);
	if (v)
	{
		r = huft_build(c, 0x13u, 0x13u, 0, 0, tb, bb, hp, (unsigned int *)&hn, v);
		if (r == -3)
		{
			z->msg = "oversubscribed dynamic bit lengths tree";
		}
		else
		{
			if (r == -5 || !*bb)
			{
				z->msg = "incomplete dynamic bit lengths tree";
				r = -3;
			}
		}
		z->zfree(z->opaque, v);
		result = r;
	}
	else
	{
		result = -4;
	}
	return result;
}

//----- (008F7688) --------------------------------------------------------
int __cdecl huft_build(unsigned int *b, unsigned int n, unsigned int s, const unsigned int *d, const unsigned int *e, inflate_huft_s **t, unsigned int *m, inflate_huft_s *hp, unsigned int *hn, unsigned int *v)
{
	int result; // eax@4
	int v11; // ecx@34
	int v12; // eax@47
	unsigned int v13; // ecx@47
	void *v14; // ecx@57
	int v15; // [sp+0h] [bp-108h]@68
	int v16; // [sp+4h] [bp-104h]@37
	unsigned int l; // [sp+8h] [bp-100h]@5
	int k; // [sp+Ch] [bp-FCh]@9
	int mask; // [sp+10h] [bp-F8h]@61
	signed int j; // [sp+14h] [bp-F4h]@5
	int ja; // [sp+14h] [bp-F4h]@24
	unsigned int jb; // [sp+14h] [bp-F4h]@28
	int jc; // [sp+14h] [bp-F4h]@39
	unsigned int jd; // [sp+14h] [bp-F4h]@55
	unsigned int je; // [sp+14h] [bp-F4h]@58
	signed int z; // [sp+18h] [bp-F0h]@31
	unsigned int i; // [sp+1Ch] [bp-ECh]@1
	signed int ia; // [sp+1Ch] [bp-ECh]@11
	unsigned int ib; // [sp+1Ch] [bp-ECh]@27
	unsigned int ic; // [sp+1Ch] [bp-ECh]@31
	signed int y; // [sp+20h] [bp-E8h]@17
	int ya; // [sp+20h] [bp-E8h]@19
	int yb; // [sp+20h] [bp-E8h]@22
	signed int h; // [sp+24h] [bp-E4h]@31
	int x[16]; // [sp+28h] [bp-E0h]@24
	int g; // [sp+68h] [bp-A0h]@15
	int w; // [sp+6Ch] [bp-9Ch]@31
	int *xp; // [sp+70h] [bp-98h]@24
	int f; // [sp+74h] [bp-94h]@39
	void *u[15]; // [sp+78h] [bp-90h]@31
	int c[16]; // [sp+B4h] [bp-54h]@1
	inflate_huft_s r; // [sp+F4h] [bp-14h]@47
	int a; // [sp+FCh] [bp-Ch]@33
	void *q; // [sp+100h] [bp-8h]@31
	unsigned int *p; // [sp+104h] [bp-4h]@1
	int na; // [sp+114h] [bp+Ch]@31

	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	c[3] = 0;
	c[4] = 0;
	c[5] = 0;
	c[6] = 0;
	c[7] = 0;
	c[8] = 0;
	c[9] = 0;
	c[10] = 0;
	c[11] = 0;
	c[12] = 0;
	c[13] = 0;
	c[14] = 0;
	c[15] = 0;
	p = b;
	i = n;
	do
	{
		++c[*p];
		++p;
		--i;
	} while (i);
	if (c[0] == n)
	{
		*t = 0;
		*m = 0;
		result = 0;
	}
	else
	{
		l = *m;
		for (j = 1; (unsigned int)j <= 0xF && !c[j]; ++j)
			;
		k = j;
		if (l < j)
			l = j;
		for (ia = 15; ia && !c[ia]; --ia)
			;
		g = ia;
		if (l > ia)
			l = ia;
		*m = l;
		y = 1 << j;
		while (j < (unsigned int)ia)
		{
			ya = y - c[j];
			if (ya < 0)
				return -3;
			++j;
			y = 2 * ya;
		}
		yb = y - c[ia];
		if (yb >= 0)
		{
			c[ia] += yb;
			ja = 0;
			x[1] = 0;
			p = (unsigned int *)&c[1];
			xp = &x[2];
			while (1)
			{
				--ia;
				if (!ia)
					break;
				ja += *p;
				*xp = ja;
				++xp;
				++p;
			}
			p = b;
			ib = 0;
			do
			{
				jb = *p;
				++p;
				if (jb)
					v[x[jb]++] = ib;
				++ib;
			} while (ib < n);
			na = x[g];
			ic = 0;
			x[0] = 0;
			p = v;
			h = -1;
			w = -l;
			u[0] = 0;
			q = 0;
			z = 0;
			while (k <= g)
			{
				a = c[k];
				while (1)
				{
					v11 = a--;
					if (!v11)
						break;
					while (k > (signed int)(l + w))
					{
						++h;
						w += l;
						if (g - w <= l)
							v16 = g - w;
						else
							v16 = l;
						jc = k - w;
						f = 1 << (k - w);
						if (f > (unsigned int)(a + 1))
						{
							f -= a + 1;
							xp = &c[k];
							if (jc < (unsigned int)v16)
							{
								while (1)
								{
									++jc;
									if (jc >= (unsigned int)v16)
										break;
									f *= 2;
									++xp;
									if (f <= (unsigned int)*xp)
										break;
									f -= *xp;
								}
							}
						}
						z = 1 << jc;
						if ((1 << jc) + *hn > 0x5A0)
							return -4;
						q = &hp[*hn];
						u[h] = q;
						*hn += z;
						if (h)
						{
							x[h] = ic;
							r.word.what.Bits = l;
							r.word.what.Exop = jc;
							r.base = ((signed int)((char *)q - *(&f + h)) >> 3) - (ic >> (w - l));
							v12 = *(&f + h);
							v13 = ic >> (w - l);
							*(_DWORD *)(v12 + 8 * v13) = *(_DWORD *)&r;
							*(_DWORD *)(v12 + 8 * v13 + 4) = r.base;
						}
						else
						{
							*t = (inflate_huft_s *)q;
						}
					}
					r.word.what.Bits = k - w;
					if (p < &v[na])
					{
						if (*p >= s)
						{
							r.word.what.Exop = e[*p - s] + 80;
							r.base = d[*p - s];
							++p;
						}
						else
						{
							r.word.what.Exop = *p < 0x100 ? 0 : 96;
							r.base = *p;
							++p;
						}
					}
					else
					{
						r.word.what.Exop = -64;
					}
					f = 1 << (k - w);
					for (jd = ic >> w; jd < z; jd += f)
					{
						v14 = q;
						*((_DWORD *)q + 2 * jd) = *(_DWORD *)&r;
						*((_DWORD *)v14 + 2 * jd + 1) = r.base;
					}
					for (je = 1 << (k - 1); je & ic; je >>= 1)
						ic ^= je;
					ic ^= je;
					for (mask = (1 << w) - 1; (mask & ic) != x[h]; mask = (1 << w) - 1)
					{
						--h;
						w -= l;
					}
				}
				++k;
			}
			if (yb && g != 1)
				v15 = -5;
			else
				v15 = 0;
			result = v15;
		}
		else
		{
			result = -3;
		}
	}
	return result;
}

//----- (008F7F56) --------------------------------------------------------
int __cdecl inflate_trees_dynamic(unsigned int nl, unsigned int nd, unsigned int *c, unsigned int *bl, unsigned int *bd, inflate_huft_s **tl, inflate_huft_s **td, inflate_huft_s *hp, z_stream_s *z)
{
	int result; // eax@2
	unsigned int *v; // [sp+0h] [bp-Ch]@1
	int hn; // [sp+4h] [bp-8h]@1
	int r; // [sp+8h] [bp-4h]@3

	hn = 0;
	v = (unsigned int *)z->zalloc(z->opaque, 288u, 4u);
	if (v)
	{
		r = huft_build(c, nl, 0x101u, cplens, cplext, tl, bl, hp, (unsigned int *)&hn, v);
		if (!r && *bl)
		{
			r = huft_build(&c[nl], nd, 0, cpdist, cpdext, td, bd, hp, (unsigned int *)&hn, v);
			if (!r && (*bd || nl <= 0x101))
			{
				z->zfree(z->opaque, v);
				result = 0;
			}
			else
			{
				if (r == -3)
				{
					z->msg = "oversubscribed distance tree";
				}
				else
				{
					if (r == -5)
					{
						z->msg = "incomplete distance tree";
						r = -3;
					}
					else
					{
						if (r != -4)
						{
							z->msg = "empty distance tree with lengths";
							r = -3;
						}
					}
				}
				z->zfree(z->opaque, v);
				result = r;
			}
		}
		else
		{
			if (r == -3)
			{
				z->msg = "oversubscribed literal/length tree";
			}
			else
			{
				if (r != -4)
				{
					z->msg = "incomplete literal/length tree";
					r = -3;
				}
			}
			z->zfree(z->opaque, v);
			result = r;
		}
	}
	else
	{
		result = -4;
	}
	return result;
}

//----- (008F80DB) --------------------------------------------------------
int __cdecl inflate_trees_fixed(unsigned int *bl, unsigned int *bd, inflate_huft_s **tl, inflate_huft_s **td, z_stream_s *z)
{
	*bl = fixed_bl;
	*bd = fixed_bd;
	*tl = fixed_tl;
	*td = fixed_td;
	return 0;
}

//----- (008F8110) --------------------------------------------------------
int __cdecl inflate_flush(inflate_blocks_state *s, z_stream_s *z, int r)
{
	char *v4; // [sp+0h] [bp-10h]@2
	unsigned int n; // [sp+4h] [bp-Ch]@4
	unsigned int na; // [sp+4h] [bp-Ch]@14
	char *q; // [sp+8h] [bp-8h]@1
	int qa; // [sp+8h] [bp-8h]@11
	char *qb; // [sp+8h] [bp-8h]@12
	void *p; // [sp+Ch] [bp-4h]@1
	void *pa; // [sp+Ch] [bp-4h]@11

	p = z->next_out;
	q = s->read;
	if (q > s->write)
		v4 = s->end;
	else
		v4 = s->write;
	n = v4 - q;
	if (v4 - q > z->avail_out)
		n = z->avail_out;
	if (n && r == -5)
		r = 0;
	z->avail_out -= n;
	z->total_out += n;
	if (s->checkfn)
	{
		s->check = s->checkfn(s->check, q, n);
		z->adler = s->check;
	}
	memcpy(p, q, n);
	pa = (char *)p + n;
	qa = (int)&q[n];
	if ((char *)qa == s->end)
	{
		qb = s->window;
		if (s->write == s->end)
			s->write = s->window;
		na = s->write - qb;
		if (na > z->avail_out)
			na = z->avail_out;
		if (na && r == -5)
			r = 0;
		z->avail_out -= na;
		z->total_out += na;
		if (s->checkfn)
		{
			s->check = s->checkfn(s->check, qb, na);
			z->adler = s->check;
		}
		memcpy(pa, qb, na);
		pa = (char *)pa + na;
		qa = (int)&qb[na];
	}
	z->next_out = (char *)pa;
	s->read = (char *)qa;
	return r;
}

//----- (008F82F0) --------------------------------------------------------
int __cdecl inflate_fast(unsigned int bl, unsigned int bd, inflate_huft_s *tl, inflate_huft_s *td, inflate_blocks_state *s, z_stream_s *z)
{
	int v6; // ST3C_4@16
	int v7; // ST50_4@28
	int v8; // ST54_4@28
	char *v9; // ST58_4@40
	int result; // eax@40
	char *v11; // ST58_4@57
	char *v12; // ST58_4@61
	char *v13; // ST58_4@67
	unsigned int v14; // [sp+0h] [bp-50h]@65
	unsigned int v15; // [sp+4h] [bp-4Ch]@59
	unsigned int v16; // [sp+8h] [bp-48h]@55
	const char *v17; // [sp+Ch] [bp-44h]@46
	unsigned int v18; // [sp+10h] [bp-40h]@38
	const char *Format; // [sp+14h] [bp-3Ch]@11
	char *v20; // [sp+18h] [bp-38h]@2
	unsigned int n; // [sp+1Ch] [bp-34h]@1
	int md; // [sp+20h] [bp-30h]@4
	unsigned int m; // [sp+24h] [bp-2Ch]@4
	unsigned int k; // [sp+28h] [bp-28h]@1
	unsigned int ka; // [sp+28h] [bp-28h]@16
	int ml; // [sp+2Ch] [bp-24h]@4
	int e; // [sp+30h] [bp-20h]@7
	int ea; // [sp+30h] [bp-20h]@20
	int eb; // [sp+30h] [bp-20h]@22
	unsigned int ec; // [sp+30h] [bp-20h]@29
	inflate_huft_s *t; // [sp+34h] [bp-1Ch]@7
	inflate_huft_s *ta; // [sp+34h] [bp-1Ch]@20
	int d; // [sp+38h] [bp-18h]@25
	int c; // [sp+3Ch] [bp-14h]@16
	unsigned int b; // [sp+40h] [bp-10h]@1
	unsigned int ba; // [sp+40h] [bp-10h]@16
	char *r; // [sp+44h] [bp-Ch]@28
	char *q; // [sp+48h] [bp-8h]@1
	char *p; // [sp+4Ch] [bp-4h]@1

	p = z->next_in;
	n = z->avail_in;
	b = s->bitb;
	k = s->bitk;
	q = s->write;
	if (q >= s->read)
		v20 = (char *)(s->end - q);
	else
		v20 = s->read + -(unsigned int)q - 1;
	m = (unsigned int)v20;
	ml = inflate_mask[bl];
	md = inflate_mask[bd];
	do
	{
		while (k < 0x14)
		{
			--n;
			b |= (unsigned __int8)*p++ << k;
			k += 8;
		}
		t = &tl[ml & b];
		e = tl[ml & b].word.what.Exop;
		if (tl[ml & b].word.what.Exop)
		{
			while (1)
			{
				b >>= t->word.what.Bits;
				k -= t->word.what.Bits;
				if (e & 0x10)
					break;
				if (e & 0x40)
				{
					if (e & 0x20)
					{
						if (z_verbose > 1)
							fprintf(&File, "inflate:         * end of block\n");
						if (k >> 3 >= z->avail_in - n)
							v16 = z->avail_in - n;
						else
							v16 = k >> 3;
						v11 = &p[-v16];
						s->bitb = b;
						s->bitk = k - 8 * v16;
						z->avail_in = v16 + n;
						z->total_in += v11 - z->next_in;
						z->next_in = v11;
						s->write = q;
						result = 1;
					}
					else
					{
						z->msg = "invalid literal/length code";
						if (k >> 3 >= z->avail_in - n)
							v15 = z->avail_in - n;
						else
							v15 = k >> 3;
						v12 = &p[-v15];
						s->bitb = b;
						s->bitk = k - 8 * v15;
						z->avail_in = v15 + n;
						z->total_in += v12 - z->next_in;
						z->next_in = v12;
						s->write = q;
						result = -3;
					}
					return result;
				}
				t += t->base + (inflate_mask[e] & b);
				e = t->word.what.Exop;
				if (!t->word.what.Exop)
				{
					b >>= t->word.what.Bits;
					k -= t->word.what.Bits;
					if (z_verbose > 1)
					{
						if (t->base < 0x20 || t->base >= 0x7F)
							v17 = "inflate:         * literal 0x%02x\n";
						else
							v17 = "inflate:         * literal '%c'\n";
						fprintf(&File, v17, t->base);
					}
					*q++ = LOBYTE(t->base);
					--m;
					goto LABEL_62;
				}
			}
			v6 = e & 0xF;
			c = (inflate_mask[v6] & b) + t->base;
			ba = b >> v6;
			ka = k - v6;
			if (z_verbose > 1)
				fprintf(&File, "inflate:         * length %u\n", c);
			while (ka < 0xF)
			{
				--n;
				ba |= (unsigned __int8)*p++ << ka;
				ka += 8;
			}
			ta = &td[md & ba];
			for (ea = td[md & ba].word.what.Exop;; ea = ta->word.what.Exop)
			{
				ba >>= ta->word.what.Bits;
				ka -= ta->word.what.Bits;
				if (ea & 0x10)
					break;
				if (ea & 0x40)
				{
					z->msg = "invalid distance code";
					if (ka >> 3 >= z->avail_in - n)
						v18 = z->avail_in - n;
					else
						v18 = ka >> 3;
					v9 = &p[-v18];
					s->bitb = ba;
					s->bitk = ka - 8 * v18;
					z->avail_in = v18 + n;
					z->total_in += v9 - z->next_in;
					z->next_in = v9;
					s->write = q;
					return -3;
				}
				ta += ta->base + (inflate_mask[ea] & ba);
			}
			eb = ea & 0xF;
			while (ka < eb)
			{
				--n;
				ba |= (unsigned __int8)*p++ << ka;
				ka += 8;
			}
			d = (inflate_mask[eb] & ba) + ta->base;
			b = ba >> eb;
			k = ka - eb;
			if (z_verbose > 1)
				fprintf(&File, "inflate:         * distance %u\n", d);
			m -= c;
			if (q - s->window < d)
			{
				ec = d - (q - s->window);
				r = &s->end[-ec];
				if (c > ec)
				{
					c -= ec;
					do
					{
						*q++ = *r++;
						--ec;
					} while (ec);
					r = s->window;
				}
			}
			else
			{
				v7 = (int)&q[-d];
				*q = q[-d];
				v8 = (int)(q + 1);
				++v7;
				*(_BYTE *)v8 = *(_BYTE *)v7;
				q = (char *)(v8 + 1);
				r = (char *)(v7 + 1);
				c -= 2;
			}
			do
			{
				*q++ = *r++;
				--c;
			} while (c);
		}
		else
		{
			b >>= t->word.what.Bits;
			k -= t->word.what.Bits;
			if (z_verbose > 1)
			{
				if (t->base < 0x20 || t->base >= 0x7F)
					Format = "inflate:         * literal 0x%02x\n";
				else
					Format = "inflate:         * literal '%c'\n";
				fprintf(&File, Format, t->base);
			}
			*q++ = LOBYTE(t->base);
			--m;
		}
	LABEL_62:
		;
	} while (m >= 0x102 && n >= 0xA);
	if (k >> 3 >= z->avail_in - n)
		v14 = z->avail_in - n;
	else
		v14 = k >> 3;
	v13 = &p[-v14];
	s->bitb = b;
	s->bitk = k - 8 * v14;
	z->avail_in = v14 + n;
	z->total_in += v13 - z->next_in;
	z->next_in = v13;
	s->write = q;
	return 0;
}
// B46CE8: using guessed type int inflate_mask[];
// EAC820: using guessed type int z_verbose;
