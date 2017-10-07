
//----- (0089C800) --------------------------------------------------------
ILoopClient *__stdcall CreateSimpleLoopClient(int(__stdcall *pCallback)(void *, int, tLoopMessageData__ *), void *pContext, sLoopClientDesc *pClientDesc)
{
    ILoopClient *v3; // eax@2
    ILoopClient *v5; // [sp+0h] [bp-8h]@2
    void *this; // [sp+4h] [bp-4h]@1

    this = j__new(0x14u, "x:\\prj\\tech\\libsrc\\darkloop\\gloopcli.cpp", 51);
    if(this)
    {
        cGenericLoopClient::cGenericLoopClient((cGenericLoopClient *)this, pCallback, pContext, pClientDesc);
        v5 = v3;
    }
    else
    {
        v5 = 0;
    }
    return v5;
}

//----- (0089C849) --------------------------------------------------------
int __stdcall cGenericLoopClient::QueryInterface(cGenericLoopClient *this, _GUID *id, void **ppI)
{
    int result; // eax@5

    if(id != &IID_ILoopClient
        && id != &IID_IUnknown
        && memcmp(id, &IID_ILoopClient, 0x10u)
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

//----- (0089C8B6) --------------------------------------------------------
unsigned int __stdcall cGenericLoopClient::AddRef(cGenericLoopClient *this)
{
    return cGenericLoopClient::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (0089C8C8) --------------------------------------------------------
unsigned int __stdcall cGenericLoopClient::Release(cGenericLoopClient *this)
{
    unsigned int result; // eax@2

    if(cGenericLoopClient::cRefCount::Release(&this->__m_ulRefs))
    {
        result = cGenericLoopClient::cRefCount::operator unsigned_long(&this->__m_ulRefs);
    }
    else
    {
        cGenericLoopClient::OnFinalRelease(this);
        result = 0;
    }
    return result;
}

//----- (0089C8F5) --------------------------------------------------------
void __thiscall cGenericLoopClient::cGenericLoopClient(cGenericLoopClient *this, int(__stdcall *pCallback)(void *, int, tLoopMessageData__ *), void *pContext, sLoopClientDesc *pClientDesc)
{
    cGenericLoopClient *v4; // ST00_4@1

    v4 = this;
    ILoopClient::ILoopClient(&this->baseclass_0);
    cGenericLoopClient::cRefCount::cRefCount(&v4->__m_ulRefs);
    v4->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cGenericLoopClient::_vftable_;
    v4->m_pCallback = pCallback;
    v4->m_pDesc = pClientDesc;
    v4->m_pContext = pContext;
}
// 9A6918: using guessed type int (__stdcall *cGenericLoopClient___vftable_)(int this, int id, int ppI);

//----- (0089C93C) --------------------------------------------------------
__int16 __stdcall cGenericLoopClient::GetVersion(cGenericLoopClient *this)
{
    return 1;
}

//----- (0089C947) --------------------------------------------------------
sLoopClientDesc *__stdcall cGenericLoopClient::GetDescription(cGenericLoopClient *this)
{
    return this->m_pDesc;
}

//----- (0089C954) --------------------------------------------------------
int __stdcall cGenericLoopClient::ReceiveMessage(cGenericLoopClient *this, int message, tLoopMessageData__ *hData)
{
    return this->m_pCallback(this->m_pContext, message, hData);
}

//----- (0089C970) --------------------------------------------------------
unsigned int __thiscall cGenericLoopClient::cRefCount::AddRef(cGenericLoopClient::cRefCount *this)
{
    ++this->ul;
    return this->ul;
}

//----- (0089C990) --------------------------------------------------------
unsigned int __thiscall cGenericLoopClient::cRefCount::Release(cGenericLoopClient::cRefCount *this)
{
    --this->ul;
    return this->ul;
}

//----- (0089C9B0) --------------------------------------------------------
unsigned int __thiscall cGenericLoopClient::cRefCount::operator unsigned_long(cGenericLoopClient::cRefCount *this)
{
    return this->ul;
}

//----- (0089C9C0) --------------------------------------------------------
void __thiscall cGenericLoopClient::OnFinalRelease(cGenericLoopClient *this)
{
    operator delete(this);
}

//----- (0089C9E0) --------------------------------------------------------
void __thiscall cGenericLoopClient::cRefCount::cRefCount(cGenericLoopClient::cRefCount *this)
{
    this->ul = 1;
}

//----- (0089CA00) --------------------------------------------------------
tHashSetKey__ *__thiscall cLoopClientDescTable::GetKey(cLoopClientDescTable *this, tHashSetNode__ *node)
{
    return (tHashSetKey__ *)node->unused;
}

//----- (0089CA12) --------------------------------------------------------
void __thiscall cLoopClientFactory::cLoopClientFactory(cLoopClientFactory *this)
{
    cLoopClientFactory *v1; // ST00_4@1

    v1 = this;
    cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>(&this->baseclass_0);
    cLoopClientDescTable::cLoopClientDescTable(&v1->m_ClientDescs);
    cDynArray<ILoopClientFactory__>::cDynArray<ILoopClientFactory__>(&v1->m_InnerFactories);
    v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cLoopClientFactory::_vftable_;
}
// 9A6930: using guessed type int (__stdcall *cLoopClientFactory___vftable_)(int this, int id, int ppI);

//----- (0089CA47) --------------------------------------------------------
_GUID **__stdcall cLoopClientFactory::QuerySupport(cLoopClientFactory *this)
{
    _GUID **v1; // ST04_4@4
    _GUID *item; // [sp+4h] [bp-1Ch]@4
    tHashSetHandle h; // [sp+8h] [bp-18h]@1
    sLoopClientDesc *pClientDesc; // [sp+14h] [bp-Ch]@1
    cDynArray<_GUID const *> result; // [sp+18h] [bp-8h]@1

    cDynArray<_GUID_const__>::cDynArray<_GUID_const__>(&result);
    for(pClientDesc = cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::GetFirst(
        &this->m_ClientDescs.baseclass_0.baseclass_0,
        &h);
    pClientDesc;
    pClientDesc = cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::GetNext(
        &this->m_ClientDescs.baseclass_0.baseclass_0,
        &h))
        cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::Append(&result.baseclass_0.baseclass_0, &pClientDesc->pID);
    item = 0;
    cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::Append(&result.baseclass_0.baseclass_0, &item);
    v1 = cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::Detach(&result.baseclass_0.baseclass_0);
    cDynArray<_GUID_const__>::_cDynArray<_GUID_const__>(&result);
    return v1;
}

//----- (0089CABC) --------------------------------------------------------
int __stdcall cLoopClientFactory::DoesSupport(cLoopClientFactory *this, _GUID *pID)
{
    int result; // eax@2

    if(cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::Search(
        &this->m_ClientDescs.baseclass_0.baseclass_0,
        pID))
        result = 1;
    else
        result = 0;
    return result;
}

//----- (0089CADF) --------------------------------------------------------
int __stdcall cLoopClientFactory::GetClient(cLoopClientFactory *this, _GUID *pID, tLoopClientData__ *data, ILoopClient **ppResult)
{
    ILoopClientFactory **v4; // eax@11
    int i; // [sp+8h] [bp-8h]@8
    sLoopClientDesc *pClientDesc; // [sp+Ch] [bp-4h]@1

    pClientDesc = cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::Search(
        &this->m_ClientDescs.baseclass_0.baseclass_0,
        pID);
    *ppResult = 0;
    if(pClientDesc)
    {
        switch(pClientDesc->factoryType)
        {
        case 0:
            return ppResult != 0 ? 0 : -2147467259;
        case 1:
            *ppResult = (ILoopClient *)pClientDesc->___u5.p;
            (*ppResult)->baseclass_0.vfptr->AddRef((IUnknown *)*ppResult);
            break;
        case 2:
            *ppResult = (ILoopClient *)((int(__stdcall *)(_DWORD, _DWORD))pClientDesc->___u5.p)(pClientDesc, data);
            break;
        case 3:
            (*(void(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)pClientDesc->___u5.p + 24))(
                pClientDesc->___u5.p,
                pID,
                data,
                ppResult);
            break;
        default:
            _CriticalMsg("Invalid factory type", "x:\\prj\\tech\\libsrc\\darkloop\\loopfact.cpp", 0x6Bu);
            break;
        }
    }
    else
    {
        for(i = 0;
            !*ppResult
            && i < cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Size(&this->m_InnerFactories.baseclass_0.baseclass_0);
        ++i)
        {
            v4 = cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::operator__(
                &this->m_InnerFactories.baseclass_0.baseclass_0,
                i);
            ((void(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))(*v4)->baseclass_0.vfptr[2].QueryInterface)(
                *v4,
                pID,
                data,
                ppResult);
        }
    }
    return ppResult != 0 ? 0 : -2147467259;
}

//----- (0089CC09) --------------------------------------------------------
int __thiscall cLoopClientFactory::AddInnerFactory(cLoopClientFactory *this, ILoopClientFactory *pFactory)
{
    cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Append(
        &this->m_InnerFactories.baseclass_0.baseclass_0,
        &pFactory);
    pFactory->baseclass_0.vfptr->AddRef((IUnknown *)pFactory);
    return 0;
}

//----- (0089CC33) --------------------------------------------------------
int __thiscall cLoopClientFactory::RemoveInnerFactory(cLoopClientFactory *this, ILoopClientFactory *pFactory)
{
    cLoopClientFactory *thisa; // [sp+0h] [bp-8h]@1
    unsigned int i; // [sp+4h] [bp-4h]@1

    thisa = this;
    for(i = 0;
        i < cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Size(&thisa->m_InnerFactories.baseclass_0.baseclass_0);
        ++i)
    {
        if(*cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::operator__(
            &thisa->m_InnerFactories.baseclass_0.baseclass_0,
            i) == pFactory)
        {
            pFactory->baseclass_0.vfptr->Release((IUnknown *)pFactory);
            cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::FastDeleteItem(
                &thisa->m_InnerFactories.baseclass_0.baseclass_0,
                i);
            return 0;
        }
    }
    return -2147467259;
}

//----- (0089CCA0) --------------------------------------------------------
void __thiscall cLoopClientFactory::ReleaseAll(cLoopClientFactory *this)
{
    ILoopClientFactory **v1; // eax@3
    cLoopClientFactory *thisa; // [sp+4h] [bp-8h]@1
    int i; // [sp+8h] [bp-4h]@1

    thisa = this;
    for(i = 0;
        i < cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Size(&thisa->m_InnerFactories.baseclass_0.baseclass_0);
        ++i)
    {
        v1 = cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::operator__(
            &thisa->m_InnerFactories.baseclass_0.baseclass_0,
            i);
        (*v1)->baseclass_0.vfptr->Release((IUnknown *)*v1);
    }
}

//----- (0089CCF1) --------------------------------------------------------
int __thiscall cLoopClientFactory::AddClient(cLoopClientFactory *this, sLoopClientDesc *pClientDesc)
{
    eLoopClientFactoryType v3; // [sp+0h] [bp-8h]@3
    cLoopClientFactory *thisa; // [sp+4h] [bp-4h]@1

    thisa = this;
    if(cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::Search(
        &this->m_ClientDescs.baseclass_0.baseclass_0,
        pClientDesc->pID))
        _CriticalMsg("Double add of loop client", "x:\\prj\\tech\\libsrc\\darkloop\\loopfact.cpp", 0xA0u);
    cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::Insert(
        &thisa->m_ClientDescs.baseclass_0.baseclass_0,
        pClientDesc);
    v3 = pClientDesc->factoryType;
    if(v3 == 1)
    {
        (*(void(__stdcall **)(_DWORD))(*(_DWORD *)pClientDesc->___u5.p + 4))(pClientDesc->___u5.p);
    }
    else
    {
        if(v3 == 3)
            (*(void(__stdcall **)(_DWORD))(*(_DWORD *)pClientDesc->___u5.p + 4))(pClientDesc->___u5.p);
    }
    return 0;
}

//----- (0089CD7F) --------------------------------------------------------
int __thiscall cLoopClientFactory::AddClients(cLoopClientFactory *this, sLoopClientDesc **ppClientDescs)
{
    cLoopClientFactory *thisa; // [sp+0h] [bp-8h]@1
    int result; // [sp+4h] [bp-4h]@1

    thisa = this;
    result = 0;
    while(*ppClientDescs)
    {
        if(cLoopClientFactory::AddClient(thisa, *ppClientDescs))
            result = -2147467259;
        ++ppClientDescs;
    }
    return result;
}

//----- (0089CDC4) --------------------------------------------------------
int __thiscall cLoopClientFactory::RemoveClient(cLoopClientFactory *this, _GUID *pID)
{
    eLoopClientFactoryType v3; // [sp+0h] [bp-Ch]@4
    sLoopClientDesc *pClientDesc; // [sp+8h] [bp-4h]@1

    pClientDesc = cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::RemoveByKey(
        &this->m_ClientDescs.baseclass_0.baseclass_0,
        pID);
    if(!pClientDesc)
        _CriticalMsg(
        "Client to remove from simple factory is not present",
        "x:\\prj\\tech\\libsrc\\darkloop\\loopfact.cpp",
        0xC7u);
    if(pClientDesc)
    {
        v3 = pClientDesc->factoryType;
        if(v3 == 1)
        {
            (*(void(__stdcall **)(_DWORD))(*(_DWORD *)pClientDesc->___u5.p + 8))(pClientDesc->___u5.p);
        }
        else
        {
            if(v3 == 3)
                (*(void(__stdcall **)(_DWORD))(*(_DWORD *)pClientDesc->___u5.p + 8))(pClientDesc->___u5.p);
        }
    }
    return pClientDesc != 0 ? 0 : -2147467259;
}

//----- (0089CE5B) --------------------------------------------------------
__int16 __stdcall cLoopClientFactory::GetVersion(cLoopClientFactory *this)
{
    return 1;
}

//----- (0089CE66) --------------------------------------------------------
ILoopClientFactory *__stdcall CreateLoopFactory(sLoopClientDesc **descs)
{
    cLoopClientFactory *v1; // eax@2
    cLoopClientFactory *v3; // [sp+0h] [bp-Ch]@2
    void *this; // [sp+4h] [bp-8h]@1

    this = j__new(0x24u, "x:\\prj\\tech\\libsrc\\darkloop\\loopfact.cpp", 230);
    if(this)
    {
        cLoopClientFactory::cLoopClientFactory((cLoopClientFactory *)this);
        v3 = v1;
    }
    else
    {
        v3 = 0;
    }
    cLoopClientFactory::AddClients(v3, descs);
    return (ILoopClientFactory *)v3;
}

//----- (0089CEC0) --------------------------------------------------------
void *__thiscall cLoopClientFactory::_scalar_deleting_destructor_(cLoopClientFactory *this, unsigned int __flags)
{
    void *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    cLoopClientFactory::_cLoopClientFactory(this);
    if(__flags & 1)
        operator delete(thisa);
    return thisa;
}

//----- (0089CEF0) --------------------------------------------------------
void __thiscall cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>(cCTUnaggregated<ILoopClientFactory, &IID_ILoopClientFactory, 0> *this)
{
    cCTUnaggregated<ILoopClientFactory, &IID_ILoopClientFactory, 0> *v1; // ST00_4@1

    v1 = this;
    ILoopClientFactory::ILoopClientFactory(&this->baseclass_0);
    cCTRefCount::cCTRefCount(&v1->__m_ulRefs);
    v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::_vftable_;
}
// 9A6954: using guessed type int (__stdcall *cCTUnaggregated_ILoopClientFactory___GUID const IID_ILoopClientFactory_0____vftable_)(int this, int id, int ppI);

//----- (0089CF20) --------------------------------------------------------
void __thiscall cLoopClientDescTable::cLoopClientDescTable(cLoopClientDescTable *this)
{
    cLoopClientDescTable *v1; // ST00_4@1

    v1 = this;
    cGuidHashSet<sLoopClientDesc_const__>::cGuidHashSet<sLoopClientDesc_const__>(&this->baseclass_0);
    v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cLoopClientDescTable::_vftable_;
}
// 9A6978: using guessed type int (__stdcall *cLoopClientDescTable___vftable_)(int __flags);

//----- (0089CF40) --------------------------------------------------------
void __thiscall cLoopClientFactory::_cLoopClientFactory(cLoopClientFactory *this)
{
    cLoopClientFactory *v1; // ST00_4@1

    v1 = this;
    cDynArray<ILoopClientFactory__>::_cDynArray<ILoopClientFactory__>(&this->m_InnerFactories);
    cLoopClientDescTable::_cLoopClientDescTable(&v1->m_ClientDescs);
    cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::_cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>(&v1->baseclass_0);
}

//----- (0089CF70) --------------------------------------------------------
void __thiscall cLoopClientDescTable::_cLoopClientDescTable(cLoopClientDescTable *this)
{
    cGuidHashSet<sLoopClientDesc_const__>::_cGuidHashSet<sLoopClientDesc_const__>(&this->baseclass_0);
}

//----- (0089CF90) --------------------------------------------------------
void __thiscall cDynArray<ILoopClientFactory__>::_cDynArray<ILoopClientFactory__>(cDynArray<ILoopClientFactory *> *this)
{
    cDynArray_<ILoopClientFactory___4>::_cDynArray_<ILoopClientFactory___4>(&this->baseclass_0);
}

//----- (0089CFB0) --------------------------------------------------------
void *__thiscall cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::_scalar_deleting_destructor_(cCTUnaggregated<ILoopClientFactory, &IID_ILoopClientFactory, 0> *this, unsigned int __flags)
{
    void *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::_cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>(this);
    if(__flags & 1)
        operator delete(thisa);
    return thisa;
}

//----- (0089CFE0) --------------------------------------------------------
void __thiscall ILoopClientFactory::ILoopClientFactory(ILoopClientFactory *this)
{
    ILoopClientFactory *v1; // ST00_4@1

    v1 = this;
    IUnknown::IUnknown(&this->baseclass_0);
    v1->baseclass_0.vfptr = (IUnknownVtbl *)ILoopClientFactory::_vftable_;
}
// 9A6998: using guessed type int (*ILoopClientFactory___vftable_[7])();

//----- (0089D000) --------------------------------------------------------
void *__thiscall cLoopClientDescTable::_vector_deleting_destructor_(cLoopClientDescTable *this, unsigned int __flags)
{
    void *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    cLoopClientDescTable::_cLoopClientDescTable(this);
    if(__flags & 1)
        operator delete(thisa);
    return thisa;
}

//----- (0089D030) --------------------------------------------------------
void __thiscall cGuidHashSet<sLoopClientDesc_const__>::cGuidHashSet<sLoopClientDesc_const__>(cGuidHashSet<sLoopClientDesc const *> *this)
{
    cGuidHashSet<sLoopClientDesc const *> *v1; // ST04_4@1

    v1 = this;
    cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>(
        &this->baseclass_0,
        0x65u);
    v1->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cGuidHashSet<sLoopClientDesc_const__>::_vftable_;
}
// 9A69B4: using guessed type int (__stdcall *cGuidHashSet_sLoopClientDesc const _____vftable_)(int __flags);

//----- (0089D060) --------------------------------------------------------
void __thiscall cGuidHashSet<sLoopClientDesc_const__>::_cGuidHashSet<sLoopClientDesc_const__>(cGuidHashSet<sLoopClientDesc const *> *this)
{
    cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::_cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>(&this->baseclass_0);
}

//----- (0089D080) --------------------------------------------------------
void __thiscall cDynArray_<ILoopClientFactory___4>::_cDynArray_<ILoopClientFactory___4>(cDynArray_<ILoopClientFactory *, 4> *this)
{
    cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::_cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>(&this->baseclass_0);
}

//----- (0089D0A0) --------------------------------------------------------
void *__thiscall cGuidHashSet<sLoopClientDesc_const__>::_vector_deleting_destructor_(cGuidHashSet<sLoopClientDesc const *> *this, unsigned int __flags)
{
    void *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    cGuidHashSet<sLoopClientDesc_const__>::_cGuidHashSet<sLoopClientDesc_const__>(this);
    if(__flags & 1)
        operator delete(thisa);
    return thisa;
}

//----- (0089D0D0) --------------------------------------------------------
void __thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::_cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this)
{
    cHashSetBase::_cHashSetBase(&this->baseclass_0);
}

//----- (0089D0F0) --------------------------------------------------------
void __thiscall cDynArray<_GUID_const__>::_cDynArray<_GUID_const__>(cDynArray<_GUID const *> *this)
{
    cDynArray_<_GUID_const___4>::_cDynArray_<_GUID_const___4>(&this->baseclass_0);
}

//----- (0089D110) --------------------------------------------------------
void __thiscall cDynArray_<_GUID_const___4>::_cDynArray_<_GUID_const___4>(cDynArray_<_GUID const *, 4> *this)
{
    cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::_cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>(&this->baseclass_0);
}

//----- (0089D130) --------------------------------------------------------
void __thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this, unsigned int n)
{
    cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *v2; // ST14_4@1

    v2 = this;
    cHashSetBase::cHashSetBase(&this->baseclass_0, n);
    v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::_vftable_;
}
// 9A69D4: using guessed type int (__stdcall *cHashSet_sLoopClientDesc const ___GUID const __cHashFunctions____vftable_)(int __flags);

//----- (0089D1A0) --------------------------------------------------------
void __thiscall cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::_cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>(cCTUnaggregated<ILoopClientFactory, &IID_ILoopClientFactory, 0> *this)
{
    this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::_vftable_;
}
// 9A6954: using guessed type int (__stdcall *cCTUnaggregated_ILoopClientFactory___GUID const IID_ILoopClientFactory_0____vftable_)(int this, int id, int ppI);

//----- (0089D1C0) --------------------------------------------------------
void __thiscall cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::OnFinalRelease(cCTUnaggregated<ILoopClientFactory, &IID_ILoopClientFactory, 0> *this)
{
    ;
}

//----- (0089D1D0) --------------------------------------------------------
int __stdcall cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::QueryInterface(cCTUnaggregated<ILoopClientFactory, &IID_ILoopClientFactory, 0> *this, _GUID *id, void **ppI)
{
    int result; // eax@5

    if(id != &IID_ILoopClientFactory
        && id != &IID_IUnknown
        && memcmp(id, &IID_ILoopClientFactory, 0x10u)
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

//----- (0089D240) --------------------------------------------------------
unsigned int __stdcall cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::AddRef(cCTUnaggregated<ILoopClientFactory, &IID_ILoopClientFactory, 0> *this)
{
    return cCTRefCount::AddRef(&this->__m_ulRefs);
}

//----- (0089D260) --------------------------------------------------------
unsigned int __stdcall cCTUnaggregated<ILoopClientFactory___GUID_const_IID_ILoopClientFactory_0>::Release(cCTUnaggregated<ILoopClientFactory, &IID_ILoopClientFactory, 0> *this)
{
    unsigned int result; // eax@2

    if(cCTRefCount::Release(&this->__m_ulRefs))
    {
        result = cCTRefCount::operator unsigned_long(&this->__m_ulRefs);
    }
    else
    {
        ((void(__thiscall *)(_DWORD))this->baseclass_0.baseclass_0.vfptr[2].Release)(this);
        if(this)
            ((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[2].AddRef)(this, 1);
        result = 0;
    }
    return result;
}

//----- (0089D2D0) --------------------------------------------------------
void __thiscall cDynArray<ILoopClientFactory__>::cDynArray<ILoopClientFactory__>(cDynArray<ILoopClientFactory *> *this)
{
    cDynArray_<ILoopClientFactory___4>::cDynArray_<ILoopClientFactory___4>(&this->baseclass_0);
}

//----- (0089D2F0) --------------------------------------------------------
void __thiscall cDynArray<_GUID_const__>::cDynArray<_GUID_const__>(cDynArray<_GUID const *> *this)
{
    cDynArray_<_GUID_const___4>::cDynArray_<_GUID_const___4>(&this->baseclass_0);
}

//----- (0089D310) --------------------------------------------------------
void *__thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::_scalar_deleting_destructor_(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this, unsigned int __flags)
{
    void *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::_cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>(this);
    if(__flags & 1)
        operator delete(thisa);
    return thisa;
}

//----- (0089D340) --------------------------------------------------------
void __thiscall cDynArray_<ILoopClientFactory___4>::cDynArray_<ILoopClientFactory___4>(cDynArray_<ILoopClientFactory *, 4> *this)
{
    cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>(&this->baseclass_0);
}

//----- (0089D360) --------------------------------------------------------
void __thiscall cDynArray_<_GUID_const___4>::cDynArray_<_GUID_const___4>(cDynArray_<_GUID const *, 4> *this)
{
    cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>(&this->baseclass_0);
}

//----- (0089D380) --------------------------------------------------------
sLoopClientDesc *__thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::Insert(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this, sLoopClientDesc *node)
{
    return (sLoopClientDesc *)cHashSetBase::Insert(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (0089D3A0) --------------------------------------------------------
sLoopClientDesc *__thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::Search(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this, _GUID *key)
{
    return (sLoopClientDesc *)cHashSetBase::Search(&this->baseclass_0, (tHashSetKey__ *)key);
}

//----- (0089D3C0) --------------------------------------------------------
sLoopClientDesc *__thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::RemoveByKey(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this, _GUID *k)
{
    return (sLoopClientDesc *)cHashSetBase::RemoveByKey(&this->baseclass_0, (tHashSetKey__ *)k);
}

//----- (0089D3E0) --------------------------------------------------------
void __thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::DestroyAll(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this)
{
    sHashSetChunk *v1; // ST10_4@6
    cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *thisa; // [sp+0h] [bp-14h]@1
    sHashSetChunk *p; // [sp+Ch] [bp-8h]@4
    unsigned int i; // [sp+10h] [bp-4h]@2

    thisa = this;
    if(this->baseclass_0.m_nItems)
    {
        for(i = 0; i < thisa->baseclass_0.m_nPts; ++i)
        {
            for(p = thisa->baseclass_0.m_Table[i]; p; p = v1)
            {
                v1 = p->pNext;
                sHashSetChunk::operator delete(p, 8u);
            }
            thisa->baseclass_0.m_Table[i] = 0;
        }
        thisa->baseclass_0.m_nItems = 0;
    }
}

//----- (0089D470) --------------------------------------------------------
sLoopClientDesc *__thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::GetFirst(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this, tHashSetHandle *Handle)
{
    return (sLoopClientDesc *)cHashSetBase::GetFirst(&this->baseclass_0, Handle);
}

//----- (0089D490) --------------------------------------------------------
sLoopClientDesc *__thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::GetNext(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this, tHashSetHandle *Handle)
{
    return (sLoopClientDesc *)cHashSetBase::GetNext(&this->baseclass_0, Handle);
}

//----- (0089D4B0) --------------------------------------------------------
int __thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::IsEqual(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this, tHashSetKey__ *k1, tHashSetKey__ *k2)
{
    return cHashFunctions::IsEqual((_GUID *)k1, (_GUID *)k2);
}

//----- (0089D4D0) --------------------------------------------------------
unsigned int __thiscall cHashSet<sLoopClientDesc_const____GUID_const___cHashFunctions>::Hash(cHashSet<sLoopClientDesc const *, _GUID const *, cHashFunctions> *this, tHashSetKey__ *k)
{
    return cHashFunctions::Hash((_GUID *)k);
}

//----- (0089D4F0) --------------------------------------------------------
void __thiscall cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>(cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *this)
{
    this->m_pItems = 0;
    this->m_nItems = 0;
    cDABaseSrvFns::TrackCreate(4u);
}

//----- (0089D520) --------------------------------------------------------
void __thiscall cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::_cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>(cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *this)
{
    cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    cDABaseSrvFns::TrackDestroy();
    if(thisa->m_pItems)
    {
        cDARawSrvFns<ILoopClientFactory__>::PreSetSize(thisa->m_pItems, thisa->m_nItems, 0);
        cDABaseSrvFns::DoResize((void **)&thisa->m_pItems, 4u, 0);
    }
}

//----- (0089D560) --------------------------------------------------------
ILoopClientFactory **__thiscall cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::operator__(cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *this, int index)
{
    const char *v2; // eax@2
    cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    if(index >= this->m_nItems)
    {
        v2 = _LogFmt("Index %d out of range");
        _CriticalMsg(v2, "x:\\prj\\tech\\h\\dynarray.h", 0x17Bu);
    }
    return &thisa->m_pItems[index];
}

//----- (0089D5B0) --------------------------------------------------------
unsigned int __thiscall cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Append(cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *this, ILoopClientFactory *const *item)
{
    cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *v2; // ST08_4@1
    unsigned int v3; // ST0C_4@1

    v2 = this;
    cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Resize(this, this->m_nItems + 1);
    v3 = v2->m_nItems++;
    cDARawSrvFns<ILoopClientFactory__>::ConstructItem(&v2->m_pItems[v3], item);
    return cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Size(v2) - 1;
}

//----- (0089D610) --------------------------------------------------------
unsigned int __thiscall cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Size(cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *this)
{
    return this->m_nItems;
}

//----- (0089D630) --------------------------------------------------------
void __thiscall cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::FastDeleteItem(cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *this, unsigned int index)
{
    const char *v2; // eax@2
    cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *thisa; // [sp+0h] [bp-8h]@1
    unsigned int last; // [sp+4h] [bp-4h]@3

    thisa = this;
    if(index >= this->m_nItems)
    {
        v2 = _LogFmt("Index %d out of range");
        _CriticalMsg(v2, "x:\\prj\\tech\\h\\dynarray.h", 0x2ACu);
    }
    last = thisa->m_nItems - 1;
    if(index == last)
        cDARawSrvFns<ILoopClientFactory__>::OnDeleteItem(&thisa->m_pItems[last]);
    else
        cDARawSrvFns<ILoopClientFactory__>::SwapDelete(&thisa->m_pItems[index], &thisa->m_pItems[last]);
    cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Resize(thisa, last);
    --thisa->m_nItems;
}

//----- (0089D6E0) --------------------------------------------------------
void __thiscall cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>(cDABase<_GUID const *, 4, cDARawSrvFns<_GUID const *> > *this)
{
    this->m_pItems = 0;
    this->m_nItems = 0;
    cDABaseSrvFns::TrackCreate(4u);
}

//----- (0089D710) --------------------------------------------------------
void __thiscall cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::_cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>(cDABase<_GUID const *, 4, cDARawSrvFns<_GUID const *> > *this)
{
    cDABase<_GUID const *, 4, cDARawSrvFns<_GUID const *> > *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    cDABaseSrvFns::TrackDestroy();
    if(thisa->m_pItems)
    {
        cDARawSrvFns<_GUID_const__>::PreSetSize(thisa->m_pItems, thisa->m_nItems, 0);
        cDABaseSrvFns::DoResize((void **)&thisa->m_pItems, 4u, 0);
    }
}

//----- (0089D750) --------------------------------------------------------
_GUID **__thiscall cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::Detach(cDABase<_GUID const *, 4, cDARawSrvFns<_GUID const *> > *this)
{
    _GUID **v1; // ST04_4@1

    v1 = this->m_pItems;
    this->m_nItems = 0;
    this->m_pItems = 0;
    return v1;
}

//----- (0089D780) --------------------------------------------------------
unsigned int __thiscall cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::Append(cDABase<_GUID const *, 4, cDARawSrvFns<_GUID const *> > *this, _GUID *const *item)
{
    cDABase<_GUID const *, 4, cDARawSrvFns<_GUID const *> > *v2; // ST08_4@1
    unsigned int v3; // ST0C_4@1

    v2 = this;
    cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::Resize(this, this->m_nItems + 1);
    v3 = v2->m_nItems++;
    cDARawSrvFns<_GUID_const__>::ConstructItem(&v2->m_pItems[v3], item);
    return cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::Size(v2) - 1;
}

//----- (0089D7E0) --------------------------------------------------------
void __cdecl cDARawSrvFns<ILoopClientFactory__>::PreSetSize(ILoopClientFactory **__formal, unsigned int a2, unsigned int a3)
{
    ;
}

//----- (0089D7F0) --------------------------------------------------------
void __cdecl cDARawSrvFns<ILoopClientFactory__>::ConstructItem(ILoopClientFactory **pItem, ILoopClientFactory *const *pFrom)
{
    memcpy(pItem, pFrom, 4u);
}

//----- (0089D810) --------------------------------------------------------
void __cdecl cDARawSrvFns<ILoopClientFactory__>::OnDeleteItem(ILoopClientFactory **__formal)
{
    ;
}

//----- (0089D820) --------------------------------------------------------
void __cdecl cDARawSrvFns<ILoopClientFactory__>::SwapDelete(ILoopClientFactory **pItem1, ILoopClientFactory **pItem2)
{
    memcpy(pItem1, pItem2, 4u);
}

//----- (0089D840) --------------------------------------------------------
void __cdecl cDARawSrvFns<_GUID_const__>::PreSetSize(_GUID **__formal, unsigned int a2, unsigned int a3)
{
    ;
}

//----- (0089D850) --------------------------------------------------------
void __cdecl cDARawSrvFns<_GUID_const__>::ConstructItem(_GUID **pItem, _GUID *const *pFrom)
{
    memcpy(pItem, pFrom, 4u);
}

//----- (0089D870) --------------------------------------------------------
int __thiscall cDABase<ILoopClientFactory___4_cDARawSrvFns<ILoopClientFactory__>>::Resize(cDABase<ILoopClientFactory *, 4, cDARawSrvFns<ILoopClientFactory *> > *this, unsigned int newSlotCount)
{
    int result; // eax@2
    unsigned int evenSlots; // [sp+8h] [bp-4h]@1

    evenSlots = (newSlotCount + 3) & 0xFFFFFFFC;
    if(((this->m_nItems + 3) & 0xFFFFFFFC) == evenSlots)
        result = 1;
    else
        result = cDABaseSrvFns::DoResize((void **)&this->m_pItems, 4u, evenSlots);
    return result;
}

//----- (0089D8C0) --------------------------------------------------------
unsigned int __thiscall cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::Size(cDABase<_GUID const *, 4, cDARawSrvFns<_GUID const *> > *this)
{
    return this->m_nItems;
}

//----- (0089D8E0) --------------------------------------------------------
int __thiscall cDABase<_GUID_const___4_cDARawSrvFns<_GUID_const__>>::Resize(cDABase<_GUID const *, 4, cDARawSrvFns<_GUID const *> > *this, unsigned int newSlotCount)
{
    int result; // eax@2
    unsigned int evenSlots; // [sp+8h] [bp-4h]@1

    evenSlots = (newSlotCount + 3) & 0xFFFFFFFC;
    if(((this->m_nItems + 3) & 0xFFFFFFFC) == evenSlots)
        result = 1;
    else
        result = cDABaseSrvFns::DoResize((void **)&this->m_pItems, 4u, evenSlots);
    return result;
}

//----- (0089D930) --------------------------------------------------------
int __stdcall _LoopManagerCreate(_GUID *__formal, ILoopManager **ppLoopManager, IUnknown *pOuterUnknown, unsigned int nMaxModes)
{
    ILoopManager *v4; // eax@2
    ILoopManager *v6; // [sp+0h] [bp-Ch]@2
    void *this; // [sp+4h] [bp-8h]@1

    this = j__new(0x98u, "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 29);
    if(this)
    {
        cLoopManager::cLoopManager((cLoopManager *)this, pOuterUnknown, nMaxModes);
        v6 = v4;
    }
    else
    {
        v6 = 0;
    }
    if(ppLoopManager)
        *ppLoopManager = v6;
    return v6 != 0 ? 0 : -2147467259;
}

//----- (0089D99A) --------------------------------------------------------
const char *__stdcall LoopGetMessageName(int message)
{
    int iMessage; // [sp+0h] [bp-8h]@1
    signed int currentMessage; // [sp+4h] [bp-4h]@1

    currentMessage = 1;
    iMessage = 0;
    while(currentMessage && !(message & currentMessage))
    {
        ++iMessage;
        currentMessage *= 2;
    }
    if(iMessage == 33)
        iMessage = 0;
    return ppszLoopMessageNames[iMessage];
}

//----- (0089D9F2) --------------------------------------------------------
int __stdcall cLoopManager::QueryInterface(cLoopManager *this, _GUID *id, void **ppI)
{
    IUnknown *v3; // eax@1

    v3 = cLoopManager::cOuterPointer::operator_>((cLoopManager::cOuterPointer *)&this->m_Loop);
    return ((int(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))v3->vfptr->QueryInterface)(v3, id, ppI, v3);
}

//----- (0089DA1D) --------------------------------------------------------
unsigned int __stdcall cLoopManager::AddRef(cLoopManager *this)
{
    IUnknown *v1; // eax@1

    v1 = cLoopManager::cOuterPointer::operator_>((cLoopManager::cOuterPointer *)&this->m_Loop);
    return ((int(__stdcall *)(_DWORD, _DWORD))v1->vfptr->AddRef)(v1, v1);
}

//----- (0089DA41) --------------------------------------------------------
unsigned int __stdcall cLoopManager::Release(cLoopManager *this)
{
    IUnknown *v1; // eax@1

    v1 = cLoopManager::cOuterPointer::operator_>((cLoopManager::cOuterPointer *)&this->m_Loop);
    return ((int(__stdcall *)(_DWORD, _DWORD))v1->vfptr->Release)(v1, v1);
}

//----- (0089DA65) --------------------------------------------------------
int __stdcall cLoopManager::cComplexAggregateControl::Connect(cLoopManager::cComplexAggregateControl *this)
{
    int result; // eax@2

    if(this->m_pAggregateMember)
        result = cLoopManager::Connect(this->m_pAggregateMember);
    else
        result = 0;
    return result;
}

//----- (0089DA84) --------------------------------------------------------
int __stdcall cLoopManager::cComplexAggregateControl::PostConnect(cLoopManager::cComplexAggregateControl *this)
{
    int result; // eax@2

    if(this->m_pAggregateMember)
        result = cLoopManager::PostConnect(this->m_pAggregateMember);
    else
        result = 0;
    return result;
}

//----- (0089DAA3) --------------------------------------------------------
int __stdcall cLoopManager::cComplexAggregateControl::Init(cLoopManager::cComplexAggregateControl *this)
{
    int result; // eax@2

    if(this->m_pAggregateMember)
        result = cLoopManager::Init(this->m_pAggregateMember);
    else
        result = 0;
    return result;
}

//----- (0089DAC2) --------------------------------------------------------
int __stdcall cLoopManager::cComplexAggregateControl::End(cLoopManager::cComplexAggregateControl *this)
{
    int result; // eax@2

    if(this->m_pAggregateMember)
        result = cLoopManager::End(this->m_pAggregateMember);
    else
        result = 0;
    return result;
}

//----- (0089DAE1) --------------------------------------------------------
int __stdcall cLoopManager::cComplexAggregateControl::Disconnect(cLoopManager::cComplexAggregateControl *this)
{
    int result; // eax@2

    if(this->m_pAggregateMember)
        result = cLoopManager::Disconnect(this->m_pAggregateMember);
    else
        result = 0;
    return result;
}

//----- (0089DB00) --------------------------------------------------------
int __stdcall cLoopManager::cComplexAggregateControl::QueryInterface(cLoopManager::cComplexAggregateControl *this, _GUID *id, void **ppI)
{
    int result; // eax@5

    if(id != &IID_IAggregateMemberControl
        && id != &IID_IUnknown
        && memcmp(id, &IID_IAggregateMemberControl, 0x10u)
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

//----- (0089DB6D) --------------------------------------------------------
unsigned int __stdcall cLoopManager::cComplexAggregateControl::AddRef(cLoopManager::cComplexAggregateControl *this)
{
    return cLoopManager::cComplexAggregateControl::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (0089DB7F) --------------------------------------------------------
unsigned int __stdcall cLoopManager::cComplexAggregateControl::Release(cLoopManager::cComplexAggregateControl *this)
{
    unsigned int result; // eax@2

    if(cLoopManager::cComplexAggregateControl::cRefCount::Release(&this->__m_ulRefs))
    {
        result = cLoopManager::cComplexAggregateControl::cRefCount::operator unsigned_long(&this->__m_ulRefs);
    }
    else
    {
        cLoopManager::cComplexAggregateControl::OnFinalRelease(this);
        result = 0;
    }
    return result;
}

//----- (0089DBAC) --------------------------------------------------------
void __thiscall cLoopManager::cLoopManager(cLoopManager *this, IUnknown *pOuterUnknown, unsigned int nMaxModes)
{
    cLoopManager *thisa; // [sp+0h] [bp-38h]@1
    sAggAddInfo aAggAddInfo[2]; // [sp+8h] [bp-30h]@2

    thisa = this;
    ILoopManager::ILoopManager(&this->baseclass_0);
    cLoopManager::cOuterPointer::cOuterPointer((cLoopManager::cOuterPointer *)&thisa->m_Loop);
    cLoopManager::cComplexAggregateControl::cComplexAggregateControl((cLoopManager::cComplexAggregateControl *)&thisa->m_Loop.__m_pOuterUnknown);
    cLoopManager::cLoop::cLoop((cLoopManager::cLoop *)((char *)&thisa->m_Loop + 16), pOuterUnknown, thisa);
    thisa->m_Factory.m_ClientDescs.baseclass_0.baseclass_0.baseclass_0.m_Table = (sHashSetChunk **)nMaxModes;
    cLoopClientFactory::cLoopClientFactory((cLoopClientFactory *)((char *)&thisa->m_Factory + 16));
    cInterfaceTable::cInterfaceTable((cInterfaceTable *)((char *)&thisa->m_nLoopModes + 16));
    thisa[1].m_Loop.m_pCurrentDispatch = 0;
    thisa->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cLoopManager::_vftable_;
    cLoopManager::cOuterPointer::Init((cLoopManager::cOuterPointer *)&thisa->m_Loop, pOuterUnknown);
    cLoopManager::cComplexAggregateControl::InitControl(
        (cLoopManager::cComplexAggregateControl *)&thisa->m_Loop.__m_pOuterUnknown,
        thisa);
    if(pOuterUnknown)
    {
        aAggAddInfo[0].pID = &IID_ILoopManager;
        aAggAddInfo[0].pszName = "IID_ILoopManager";
        aAggAddInfo[0].pAggregated = (IUnknown *)thisa;
        aAggAddInfo[0].pControl = (IUnknown *)&thisa->m_Loop.__m_pOuterUnknown;
        aAggAddInfo[0].controlPriority = 4095;
        aAggAddInfo[0].pControlConstraints = 0;
        aAggAddInfo[1].pID = &IID_ILoop;
        aAggAddInfo[1].pszName = "IID_ILoop";
        aAggAddInfo[1].pAggregated = (IUnknown *)&thisa->m_Loop.m_FrameInfo;
        aAggAddInfo[1].pControl = 0;
        aAggAddInfo[1].controlPriority = 0;
        aAggAddInfo[1].pControlConstraints = 0;
        _AddToAggregate(pOuterUnknown, aAggAddInfo, 2u);
    }
    ((void(__stdcall *)(cLoopManager::cLoop::cOuterPointer *))thisa->m_Loop.__m_pOuterUnknown.m_pOuterUnknown[2].vfptr)(&thisa->m_Loop.__m_pOuterUnknown);
}
// 9A69F4: using guessed type int (__stdcall *cLoopManager___vftable_)(int this, int id, int ppI);

//----- (0089DD33) --------------------------------------------------------
void __thiscall cLoopManager::_cLoopManager(cLoopManager *this)
{
    cLoopManager *v1; // ST00_4@1

    v1 = this;
    this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cLoopManager::_vftable_;
    cInterfaceTable::_cInterfaceTable((cInterfaceTable *)((char *)&this->m_nLoopModes + 16));
    cLoopClientFactory::_cLoopClientFactory((cLoopClientFactory *)((char *)&v1->m_Factory + 16));
    cLoopManager::cLoop::_cLoop((cLoopManager::cLoop *)((char *)&v1->m_Loop + 16));
}
// 9A69F4: using guessed type int (__stdcall *cLoopManager___vftable_)(int this, int id, int ppI);

//----- (0089DD6B) --------------------------------------------------------
int __stdcall cLoopManager::AddClient(cLoopManager *this, ILoopClient *pClient, unsigned int *pCookie)
{
    int v3; // ecx@0
    unsigned int *pClientDesc; // [sp+0h] [bp-4h]@1

    pClientDesc = (unsigned int *)((int(__stdcall *)(ILoopClient *, int))pClient->baseclass_0.vfptr[1].AddRef)(
        pClient,
        v3);
    if((*(int(__stdcall **)(unsigned int *, unsigned int))(this->m_Factory.m_ClientDescs.baseclass_0.baseclass_0.baseclass_0.m_nPts
        + 20))(
        &this->m_Factory.m_ClientDescs.baseclass_0.baseclass_0.baseclass_0.m_nPts,
        *pClientDesc))
        _CriticalMsg("Double add of loop client", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0x92u);
    *pCookie = *pClientDesc;
    return cLoopClientFactory::AddClient(
        (cLoopClientFactory *)((char *)&this->m_Factory + 16),
        (sLoopClientDesc *)pClientDesc);
}

//----- (0089DDD3) --------------------------------------------------------
int __stdcall cLoopManager::RemoveClient(cLoopManager *this, unsigned int cookie)
{
    return cLoopClientFactory::RemoveClient((cLoopClientFactory *)((char *)&this->m_Factory + 16), (_GUID *)cookie);
}

//----- (0089DDE9) --------------------------------------------------------
int __stdcall cLoopManager::AddClientFactory(cLoopManager *this, ILoopClientFactory *pFactory, unsigned int *pCookie)
{
    *pCookie = (unsigned int)pFactory;
    return cLoopClientFactory::AddInnerFactory((cLoopClientFactory *)((char *)&this->m_Factory + 16), pFactory);
}

//----- (0089DE07) --------------------------------------------------------
int __stdcall cLoopManager::RemoveClientFactory(cLoopManager *this, unsigned int cookie)
{
    return cLoopClientFactory::RemoveInnerFactory(
        (cLoopClientFactory *)((char *)&this->m_Factory + 16),
        (ILoopClientFactory *)cookie);
}

//----- (0089DE1D) --------------------------------------------------------
int __stdcall cLoopManager::GetClient(cLoopManager *this, _GUID *pID, tLoopClientData__ *data, ILoopClient **ppReturn)
{
    return (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(this->m_Factory.m_ClientDescs.baseclass_0.baseclass_0.baseclass_0.m_nPts
        + 24))(
        &this->m_Factory.m_ClientDescs.baseclass_0.baseclass_0.baseclass_0.m_nPts,
        pID,
        data,
        ppReturn);
}

//----- (0089DE40) --------------------------------------------------------
int __stdcall cLoopManager::AddMode(cLoopManager *this, sLoopModeDesc *pDesc)
{
    int result; // eax@4
    cInterfaceInfo *v3; // eax@6
    cInterfaceInfo *v4; // [sp+0h] [bp-10h]@6
    void *v5; // [sp+4h] [bp-Ch]@5
    IUnknown *pLoopMode; // [sp+8h] [bp-8h]@1

    pLoopMode = (IUnknown *)_LoopModeCreate(pDesc);
    if(!pLoopMode)
        _CriticalMsg("Failed to create loop mode", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0xC9u);
    if(pLoopMode)
    {
        v5 = j__new(0x1Cu, "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 206);
        if(v5)
        {
            cInterfaceInfo::cInterfaceInfo((cInterfaceInfo *)v5, pDesc->name.pID, pLoopMode, 0);
            v4 = v3;
        }
        else
        {
            v4 = 0;
        }
        cHashSet<cInterfaceInfo____GUID_const___cHashFunctions>::Insert(
            (cHashSet<cInterfaceInfo *, _GUID const *, cHashFunctions> *)((char *)&this->m_nLoopModes.baseclass_0.baseclass_0
            + 16),
            v4);
        result = 0;
    }
    else
    {
        result = -2147467259;
    }
    return result;
}

//----- (0089DEDE) --------------------------------------------------------
ILoopMode *__stdcall cLoopManager::GetMode(cLoopManager *this, _GUID *pID)
{
    ILoopMode *result; // eax@2
    ILoopMode *pLoopMode; // [sp+0h] [bp-8h]@2
    cInterfaceInfo *pLoopModeInfo; // [sp+4h] [bp-4h]@1

    pLoopModeInfo = cHashSet<cInterfaceInfo____GUID_const___cHashFunctions>::Search(
        (cHashSet<cInterfaceInfo *, _GUID const *, cHashFunctions> *)((char *)&this->m_nLoopModes.baseclass_0.baseclass_0
        + 16),
        pID);
    if(pLoopModeInfo)
    {
        (**(void(__stdcall ***)(_DWORD, _DWORD, _DWORD))pLoopModeInfo->pUnknown)(
            pLoopModeInfo->pUnknown,
            &IID_ILoopMode,
            &pLoopMode);
        result = pLoopMode;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (0089DF26) --------------------------------------------------------
int __stdcall cLoopManager::RemoveMode(cLoopManager *this, _GUID *pID)
{
    int result; // eax@8
    cInterfaceInfo *pLoopModeInfo; // [sp+Ch] [bp-4h]@1

    pLoopModeInfo = cHashSet<cInterfaceInfo____GUID_const___cHashFunctions>::Search(
        (cHashSet<cInterfaceInfo *, _GUID const *, cHashFunctions> *)((char *)&this->m_nLoopModes.baseclass_0.baseclass_0
        + 16),
        pID);
    if(!pLoopModeInfo)
        _CriticalMsg("Attempted to remove mode that was never added", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0xEDu);
    if(pLoopModeInfo)
    {
        cHashSet<cInterfaceInfo____GUID_const___cHashFunctions>::Remove(
            (cHashSet<cInterfaceInfo *, _GUID const *, cHashFunctions> *)((char *)&this->m_nLoopModes.baseclass_0.baseclass_0
            + 16),
            pLoopModeInfo);
        if(pLoopModeInfo->pUnknown)
            pLoopModeInfo->pUnknown->vfptr->Release(pLoopModeInfo->pUnknown);
        pLoopModeInfo->pUnknown = 0;
        if(pLoopModeInfo)
            cInterfaceInfo::_scalar_deleting_destructor_(pLoopModeInfo, 1u);
        result = 0;
    }
    else
    {
        result = -2147467259;
    }
    return result;
}

//----- (0089DFD7) --------------------------------------------------------
int __stdcall cLoopManager::SetBaseMode(cLoopManager *this, _GUID *pID)
{
    int result; // eax@4
    cInterfaceInfo *pMode; // [sp+0h] [bp-4h]@1

    pMode = cHashSet<cInterfaceInfo____GUID_const___cHashFunctions>::Search(
        (cHashSet<cInterfaceInfo *, _GUID const *, cHashFunctions> *)((char *)&this->m_nLoopModes.baseclass_0.baseclass_0
        + 16),
        pID);
    if(!pMode)
        _CriticalMsg(
        "Attempted to set a base mode that was never added",
        "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp",
        0x102u);
    if(pMode)
    {
        this[1].m_Loop.m_pCurrentDispatch = (ILoopDispatch *)pID;
        result = 0;
    }
    else
    {
        this[1].m_Loop.m_pCurrentDispatch = 0;
        result = -2147467259;
    }
    return result;
}

//----- (0089E040) --------------------------------------------------------
ILoopMode *__stdcall cLoopManager::GetBaseMode(cLoopManager *this)
{
    ILoopMode *result; // eax@2

    if(this[1].m_Loop.m_pCurrentDispatch)
        result = (ILoopMode *)((int(__stdcall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[3].QueryInterface)(
        this,
        this[1].m_Loop.m_pCurrentDispatch);
    else
        result = 0;
    return result;
}

//----- (0089E06D) --------------------------------------------------------
int __thiscall cLoopManager::End(cLoopManager *this)
{
    cLoopManager *v1; // ST04_4@1

    v1 = this;
    cLoopClientFactory::ReleaseAll((cLoopClientFactory *)((char *)&this->m_Factory + 16));
    cInterfaceTable::ReleaseAll((cInterfaceTable *)((char *)&v1->m_nLoopModes + 16), 1);
    return 0;
}

//----- (0089E095) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::QueryInterface(cLoopManager::cLoop *this, _GUID *id, void **ppI)
{
    IUnknown *v3; // eax@1

    v3 = cLoopManager::cLoop::cOuterPointer::operator_>(&this->__m_pOuterUnknown);
    return ((int(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))v3->vfptr->QueryInterface)(v3, id, ppI, v3);
}

//----- (0089E0C0) --------------------------------------------------------
unsigned int __stdcall cLoopManager::cLoop::AddRef(cLoopManager::cLoop *this)
{
    IUnknown *v1; // eax@1

    v1 = cLoopManager::cLoop::cOuterPointer::operator_>(&this->__m_pOuterUnknown);
    return ((int(__stdcall *)(_DWORD, _DWORD))v1->vfptr->AddRef)(v1, v1);
}

//----- (0089E0E4) --------------------------------------------------------
unsigned int __stdcall cLoopManager::cLoop::Release(cLoopManager::cLoop *this)
{
    IUnknown *v1; // eax@1

    v1 = cLoopManager::cLoop::cOuterPointer::operator_>(&this->__m_pOuterUnknown);
    return ((int(__stdcall *)(_DWORD, _DWORD))v1->vfptr->Release)(v1, v1);
}

//----- (0089E108) --------------------------------------------------------
void __thiscall cLoopManager::cLoop::_cLoop(cLoopManager::cLoop *this)
{
    cLoopManager::cLoop *v1; // ST0C_4@1

    v1 = this;
    this->baseclass_0.lpVtbl = (ILoopVtbl *)&cLoopManager::cLoop::_vftable_;
    operator delete(this->m_pLoopStack);
    if(v1->m_pCurrentDispatch)
        _CriticalMsg(
        "Expected exit of loop manager before destruction!",
        "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp",
        0x138u);
}
// 9A6A4C: using guessed type int (__stdcall *cLoopManager__cLoop___vftable_)(int this, int id, int ppI);

//----- (0089E158) --------------------------------------------------------
ILoopMode *__stdcall cLoopManager::cLoop::GetCurrentMode(cLoopManager::cLoop *this)
{
    int v1; // ecx@0
    int v2; // eax@1

    v2 = ((int(__stdcall *)(ILoopDispatch *, _DWORD, int))this->m_pCurrentDispatch->baseclass_0.vfptr[2].Release)(
        this->m_pCurrentDispatch,
        0,
        v1);
    return (ILoopMode *)((int(__stdcall *)(ILoopManager *, _DWORD))this->m_pLoopManager->baseclass_0.vfptr[3].QueryInterface)(
        this->m_pLoopManager,
        *(_DWORD *)v2);
}

//----- (0089E191) --------------------------------------------------------
ILoopDispatch *__stdcall cLoopManager::cLoop::GetCurrentDispatch(cLoopManager::cLoop *this)
{
    return this->m_pCurrentDispatch;
}

//----- (0089E19E) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::Go(cLoopManager::cLoop *this, sLoopInstantiator *loop)
{
    sModeData *v2; // eax@1
    cLoopModeStack *v3; // eax@2
    IUnknownVtbl *v4; // eax@4
    int v5; // eax@7
    int v6; // edx@8
    int v7; // edx@9
    IUnknown *v8; // eax@12
    IUnknownVtbl *v9; // eax@17
    IUnknownVtbl *v10; // edx@18
    IUnknownVtbl *v11; // eax@18
    IUnknownVtbl *v12; // edx@18
    unsigned int v13; // ecx@18
    IUnknownVtbl *v14; // eax@20
    IUnknownVtbl *v15; // edx@22
    IUnknownVtbl *v16; // ecx@23
    IGameShell *v17; // eax@24
    IUnknownVtbl *v18; // eax@24
    IUnknownVtbl *v19; // eax@25
    IUnknownVtbl *v20; // edx@26
    IUnknownVtbl *v21; // eax@27
    IUnknownVtbl *v22; // ecx@27
    IGameShell *v23; // eax@28
    IUnknownVtbl *v24; // eax@28
    unsigned int v25; // eax@33
    unsigned int v26; // eax@33
    IUnknownVtbl *v27; // edx@38
    IUnknownVtbl *v28; // ecx@39
    IUnknownVtbl *v29; // eax@41
    IUnknownVtbl *v30; // edx@41
    IUnknownVtbl *v31; // ecx@41
    IUnknownVtbl *v32; // eax@42
    sModeData *v33; // eax@44
    sModeData v34; // [sp-18h] [bp-C4h]@1
    int v35; // [sp-14h] [bp-C0h]@1
    unsigned int v36; // [sp-10h] [bp-BCh]@1
    signed int v37; // [sp-Ch] [bp-B8h]@1
    int v38; // [sp-8h] [bp-B4h]@1
    void *v39; // [sp-4h] [bp-B0h]@1
    void *v40; // [sp+0h] [bp-ACh]@28
    IGameShell *v41; // [sp+4h] [bp-A8h]@26
    int v42; // [sp+8h] [bp-A4h]@24
    IGameShell *v43; // [sp+Ch] [bp-A0h]@22
    cLoopModeStack *v44; // [sp+10h] [bp-9Ch]@2
    int v45; // [sp+14h] [bp-98h]@44
    sModeData result; // [sp+18h] [bp-94h]@44
    void *p; // [sp+30h] [bp-7Ch]@44
    void *v48; // [sp+34h] [bp-78h]@1
    char v49; // [sp+38h] [bp-74h]@1
    int outmsg; // [sp+54h] [bp-58h]@36
    int inmsg; // [sp+58h] [bp-54h]@15
    int ticks; // [sp+5Ch] [bp-50h]@29
    sModeData old; // [sp+60h] [bp-4Ch]@44
    sLoopTransition trans; // [sp+78h] [bp-34h]@1
    cLoopModeStack *old_stack; // [sp+90h] [bp-1Ch]@1
    int minorMode; // [sp+94h] [bp-18h]@1
    int frameMessage; // [sp+98h] [bp-14h]@12
    _GUID *pID; // [sp+9Ch] [bp-10h]@1
    signed int pMode; // [sp+A0h] [bp-Ch]@4
    sLoopModeInitParm *parmList; // [sp+A4h] [bp-8h]@1
    cAutoIPtr<IGameShell> pGameShell; // [sp+A8h] [bp-4h]@12

    pID = loop->pID;
    minorMode = loop->minorMode;
    parmList = loop->init;
    trans.from.pID = &GUID_NULL;
    trans.to.pID = loop->pID;
    trans.to.minorMode = loop->minorMode;
    trans.to.init = loop->init;
    v39 = (void *)128;
    v35 = this->m_FrameInfo.fMinorMode;
    v36 = this->m_FrameInfo.nCount;
    v37 = this->m_FrameInfo.nTicks;
    v38 = this->m_FrameInfo.dTicks;
    sModeData::sModeData((sModeData *)&v49, this->m_pCurrentDispatch, *(sLoopFrameInfo *)&v35, 0x80u);
    sModeData::sModeData(&v34, v2);
    cLoopModeStack::Push(this->m_pLoopStack, v34);
    old_stack = this->m_pLoopStack;
    v48 = j__new(8u, "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 355);
    if(v48)
    {
        cLoopModeStack::cLoopModeStack((cLoopModeStack *)v48);
        v44 = v3;
    }
    else
    {
        v44 = 0;
    }
    this->m_pLoopStack = v44;
    v39 = (void *)pID;
    v4 = this->m_pLoopManager->baseclass_0.vfptr;
    v38 = (int)this->m_pLoopManager;
    pMode = ((int(__stdcall *)(int, _GUID *))v4[3].QueryInterface)(v38, pID);
    if(!pMode)
        _CriticalMsg(
        "Attempted to \"go\" on mode that was never added",
        "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp",
        0x167u);
    if(pMode)
    {
        v39 = &this->m_pNextDispatch;
        v38 = (int)parmList;
        v6 = *(_DWORD *)pMode;
        v37 = pMode;
        (*(void(__stdcall **)(signed int, sLoopModeInitParm *, ILoopDispatch **))(v6 + 16))(
            pMode,
            parmList,
            &this->m_pNextDispatch);
        if(pMode)
        {
            v7 = *(_DWORD *)pMode;
            v39 = (void *)pMode;
            (*(void(__stdcall **)(signed int))(v7 + 8))(pMode);
        }
        pMode = 0;
        if(!DoneAtExit[0])
        {
            atexit(cLoopManager::cLoop::OnExit);
            DoneAtExit[0] = 1;
        }
        this->m_fNewMinorMode = minorMode;
        this->m_fState |= 0x10u;
        v8 = _AppGetAggregated(&IID_IGameShell);
        cAutoIPtr<IGameShell>::cAutoIPtr<IGameShell>(&pGameShell, (IGameShell *)v8);
        frameMessage = 128;
        this->m_fState |= 0x21u;
        while(this->m_fState & 1)
        {
            if(this->m_fState & 0x20)
            {
                inmsg = 4096;
                if(this->m_fState & 0x80)
                {
                    inmsg = 16384;
                }
                else
                {
                    v9 = this->m_pNextDispatch->baseclass_0.vfptr;
                    v39 = this->m_pNextDispatch;
                    v9[2].AddRef((IUnknown *)v39);
                }
                this->m_pCurrentDispatch = this->m_pNextDispatch;
                this->m_pNextDispatch = 0;
                v39 = (void *)this->m_tempDiagnosticSet;
                v38 = this->m_fTempDiagnostics;
                v10 = this->m_pCurrentDispatch->baseclass_0.vfptr;
                v37 = (signed int)this->m_pCurrentDispatch;
                v10[3].QueryInterface((IUnknown *)v37, (_GUID *)v38, (void **)v39);
                v39 = (void *)this->m_pTempProfileClientId;
                v38 = this->m_TempProfileSet;
                v11 = this->m_pCurrentDispatch->baseclass_0.vfptr;
                v37 = (signed int)this->m_pCurrentDispatch;
                ((void(__stdcall *)(signed int, int, void *))v11[3].Release)(v37, v38, v39);
                v39 = (void *)1;
                v38 = (int)&trans;
                v37 = inmsg;
                v12 = this->m_pCurrentDispatch->baseclass_0.vfptr;
                v36 = (unsigned int)this->m_pCurrentDispatch;
                ((void(__stdcall *)(unsigned int, int, sLoopTransition *, signed int))v12[1].QueryInterface)(
                    v36,
                    inmsg,
                    &trans,
                    1);
                v13 = this->m_fState;
                LOBYTE(v13) = v13 & 0x1F;
                this->m_fState = v13;
                this->m_FrameInfo.nTicks = tm_get_millisec();
                this->m_FrameInfo.dTicks = 0;
            }
            if(this->m_fState & 0x10)
            {
                this->m_FrameInfo.fMinorMode = this->m_fNewMinorMode;
                v39 = (void *)1;
                v38 = this->m_FrameInfo.fMinorMode;
                v37 = 65536;
                v14 = this->m_pCurrentDispatch->baseclass_0.vfptr;
                v36 = (unsigned int)this->m_pCurrentDispatch;
                ((void(__stdcall *)(unsigned int, signed int, int, signed int))v14[1].QueryInterface)(v36, 65536, v38, 1);
                this->m_fState &= 0xFFFFFFEFu;
            }
            if(cIPtr<IGameShell>::operator__(&pGameShell.baseclass_0, 0))
            {
                v43 = cIPtr<IGameShell>::operator_>(&pGameShell.baseclass_0);
                v15 = v43->baseclass_0.vfptr;
                v39 = v43;
                ((void(__stdcall *)(IGameShell *))v15[1].QueryInterface)(v43);
            }
            v39 = (void *)1;
            v38 = (int)&this->m_FrameInfo;
            v37 = 64;
            v16 = this->m_pCurrentDispatch->baseclass_0.vfptr;
            v36 = (unsigned int)this->m_pCurrentDispatch;
            ((void(__stdcall *)(unsigned int, signed int, sLoopFrameInfo *, signed int))v16[1].QueryInterface)(
                v36,
                64,
                &this->m_FrameInfo,
                1);
            if(cIPtr<IGameShell>::operator__(&pGameShell.baseclass_0, 0))
            {
                v39 = 0;
                v17 = cIPtr<IGameShell>::operator_>(&pGameShell.baseclass_0);
                v42 = (int)v17;
                v18 = v17->baseclass_0.vfptr;
                v38 = v42;
                ((void(__stdcall *)(int, void *))v18[2].AddRef)(v42, v39);
            }
            v39 = (void *)1;
            v38 = (int)&this->m_FrameInfo;
            v37 = frameMessage;
            v19 = this->m_pCurrentDispatch->baseclass_0.vfptr;
            v36 = (unsigned int)this->m_pCurrentDispatch;
            ((void(__stdcall *)(unsigned int, int, sLoopFrameInfo *, signed int))v19[1].QueryInterface)(
                v36,
                frameMessage,
                &this->m_FrameInfo,
                1);
            if(cIPtr<IGameShell>::operator__(&pGameShell.baseclass_0, 0))
            {
                v39 = 0;
                v41 = cIPtr<IGameShell>::operator_>(&pGameShell.baseclass_0);
                v20 = v41->baseclass_0.vfptr;
                v38 = (int)v41;
                ((void(__stdcall *)(IGameShell *, void *))v20[2].AddRef)(v41, v39);
            }
            v21 = this->m_pCurrentDispatch->baseclass_0.vfptr;
            v39 = this->m_pCurrentDispatch;
            v21[2].AddRef((IUnknown *)v39);
            v39 = (void *)2;
            v38 = (int)&this->m_FrameInfo;
            v37 = 512;
            v22 = this->m_pCurrentDispatch->baseclass_0.vfptr;
            v36 = (unsigned int)this->m_pCurrentDispatch;
            ((void(__stdcall *)(unsigned int, signed int, sLoopFrameInfo *, signed int))v22[1].QueryInterface)(
                v36,
                512,
                &this->m_FrameInfo,
                2);
            if(cIPtr<IGameShell>::operator__(&pGameShell.baseclass_0, 0))
            {
                v23 = cIPtr<IGameShell>::operator_>(&pGameShell.baseclass_0);
                v40 = v23;
                v24 = v23->baseclass_0.vfptr;
                v39 = v40;
                v24[1].AddRef((IUnknown *)v40);
            }
            ++this->m_FrameInfo.nCount;
            ticks = tm_get_millisec();
            this->m_FrameInfo.dTicks = ticks - this->m_FrameInfo.nTicks;
            this->m_FrameInfo.nTicks = ticks;
            if(this->m_fState & 0xC)
            {
                if(this->m_fState & 4)
                    frameMessage = 256;
                else
                    frameMessage = 128;
                v25 = this->m_fState;
                LOBYTE(v25) = v25 & 0xF3;
                this->m_fState = v25;
                v26 = this->m_fState;
                LOBYTE(v26) = v26 | 2;
                this->m_fState = v26;
            }
            if(this->m_fState & 0x20 || !(this->m_fState & 1))
            {
                outmsg = 32768;
                if(this->m_fState & 0x40)
                    outmsg = 8192;
                v39 = &trans.from.init;
                v27 = this->m_pCurrentDispatch->baseclass_0.vfptr;
                v38 = (int)this->m_pCurrentDispatch;
                trans.from.pID = *(_GUID **)((int(__stdcall *)(int, sLoopModeInitParm **))v27[2].Release)(
                    v38,
                    &trans.from.init);
                trans.from.minorMode = this->m_FrameInfo.fMinorMode;
                if(this->m_pNextDispatch)
                {
                    v39 = &trans.to.init;
                    v28 = this->m_pNextDispatch->baseclass_0.vfptr;
                    v38 = (int)this->m_pNextDispatch;
                    trans.to.pID = *(_GUID **)((int(__stdcall *)(int, sLoopModeInitParm **))v28[2].Release)(v38, &trans.to.init);
                    trans.to.minorMode = this->m_fNewMinorMode;
                }
                else
                {
                    trans.to.pID = &GUID_NULL;
                }
                v39 = (void *)2;
                v38 = (int)&trans;
                v37 = outmsg;
                v29 = this->m_pCurrentDispatch->baseclass_0.vfptr;
                v36 = (unsigned int)this->m_pCurrentDispatch;
                ((void(__stdcall *)(unsigned int, int, sLoopTransition *, signed int))v29[1].QueryInterface)(
                    v36,
                    outmsg,
                    &trans,
                    2);
                v39 = &this->m_tempDiagnosticSet;
                v38 = (int)&this->m_fTempDiagnostics;
                v30 = this->m_pCurrentDispatch->baseclass_0.vfptr;
                v37 = (signed int)this->m_pCurrentDispatch;
                ((void(__stdcall *)(signed int, unsigned int *, unsigned int *))v30[3].AddRef)(
                    v37,
                    &this->m_fTempDiagnostics,
                    &this->m_tempDiagnosticSet);
                v39 = &this->m_pTempProfileClientId;
                v38 = (int)&this->m_TempProfileSet;
                v31 = this->m_pCurrentDispatch->baseclass_0.vfptr;
                v37 = (signed int)this->m_pCurrentDispatch;
                v31[4].QueryInterface((IUnknown *)v37, (_GUID *)&this->m_TempProfileSet, (void **)&this->m_pTempProfileClientId);
                if(!(this->m_fState & 0x40))
                {
                    v32 = this->m_pCurrentDispatch->baseclass_0.vfptr;
                    v39 = this->m_pCurrentDispatch;
                    v32->Release((IUnknown *)v39);
                }
            }
        }
        p = this->m_pLoopStack;
        operator delete(p);
        this->m_pLoopStack = old_stack;
        v33 = cLoopModeStack::Pop(old_stack, &result);
        sModeData::sModeData(&old, v33);
        this->m_pCurrentDispatch = old.dispatch;
        this->m_FrameInfo.fMinorMode = old.frame.fMinorMode;
        this->m_FrameInfo.nCount = old.frame.nCount;
        this->m_FrameInfo.nTicks = old.frame.nTicks;
        this->m_FrameInfo.dTicks = old.frame.dTicks;
        v45 = this->m_fGoReturn;
        cAutoIPtr<IGameShell>::_cAutoIPtr<IGameShell>(&pGameShell);
        v5 = v45;
    }
    else
    {
        v5 = -2147467259;
    }
    return v5;
}

//----- (0089E7AE) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::EndAllModes(cLoopManager::cLoop *this, int goRetVal)
{
    int v2; // eax@2
    sLoopFrameInfo v3; // ST04_16@3
    unsigned int v4; // eax@6
    char v5; // [sp+8h] [bp-70h]@5
    sModeData result; // [sp+20h] [bp-58h]@3
    __int64 v7; // [sp+38h] [bp-40h]@3
    __int64 v8; // [sp+40h] [bp-38h]@3
    sLoopTransition trans; // [sp+48h] [bp-30h]@5
    sModeData mode; // [sp+60h] [bp-18h]@3

    if(this->m_pCurrentDispatch)
    {
        this->m_fGoReturn = goRetVal;
        *(_QWORD *)&v3.fMinorMode = v7;
        *(_QWORD *)&v3.nTicks = v8;
        sModeData::sModeData(&mode, 0, v3, 0x80u);
        memcpy(&mode, cLoopModeStack::Pop(this->m_pLoopStack, &result), sizeof(mode));
        while((_DWORD)mode.dispatch)
        {
            trans.from.pID = *(_GUID **)((int(__stdcall *)(ILoopDispatch *, sLoopModeInitParm **))mode.dispatch->baseclass_0.vfptr[2].Release)(
                mode.dispatch,
                &trans.from.init);
            trans.from.minorMode = mode.frame.fMinorMode;
            trans.to.pID = &GUID_NULL;
            ((void(__stdcall *)(ILoopDispatch *, signed int, sLoopTransition *, signed int))mode.dispatch->baseclass_0.vfptr[1].QueryInterface)(
                mode.dispatch,
                32768,
                &trans,
                2);
            mode.dispatch->baseclass_0.vfptr->Release((IUnknown *)mode.dispatch);
            memcpy(&mode, cLoopModeStack::Pop(this->m_pLoopStack, (sModeData *)&v5), sizeof(mode));
        }
        v4 = this->m_fState;
        LOBYTE(v4) = v4 & 0xFE;
        this->m_fState = v4;
        v2 = 0;
    }
    else
    {
        v2 = 1;
    }
    return v2;
}

//----- (0089E89A) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::Terminate(cLoopManager::cLoop *this)
{
    sLoopTransition trans; // [sp+0h] [bp-18h]@2

    if(this->m_pCurrentDispatch)
    {
        trans.from.pID = *(_GUID **)((int(__stdcall *)(ILoopDispatch *, sLoopModeInitParm **))this->m_pCurrentDispatch->baseclass_0.vfptr[2].Release)(
            this->m_pCurrentDispatch,
            &trans.from.init);
        trans.from.minorMode = this->m_FrameInfo.fMinorMode;
        trans.to.pID = &GUID_NULL;
        ((void(__stdcall *)(ILoopDispatch *, signed int, sLoopTransition *, signed int))this->m_pCurrentDispatch->baseclass_0.vfptr[1].QueryInterface)(
            this->m_pCurrentDispatch,
            32768,
            &trans,
            2);
        if(this->m_pCurrentDispatch)
            this->m_pCurrentDispatch->baseclass_0.vfptr->Release((IUnknown *)this->m_pCurrentDispatch);
        this->m_pCurrentDispatch = 0;
        this->baseclass_0.lpVtbl->EndAllModes((ILoop *)this, 0);
    }
    return 0;
}

//----- (0089E92C) --------------------------------------------------------
sLoopFrameInfo *__stdcall cLoopManager::cLoop::GetFrameInfo(cLoopManager::cLoop *this)
{
    return &this->m_FrameInfo;
}

//----- (0089E939) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::ChangeMode(cLoopManager::cLoop *this, int kind, sLoopInstantiator *loop)
{
    _GUID **v3; // eax@6
    int v4; // eax@7
    sModeData *v5; // eax@13
    unsigned int v6; // eax@15
    int v7; // edx@20
    IUnknownVtbl *v8; // edx@22
    unsigned int v9; // edx@23
    IUnknownVtbl *v10; // ecx@24
    IUnknownVtbl *v11; // ecx@24
    int v12; // ecx@26
    unsigned int v13; // eax@27
    sModeData *v14; // eax@28
    ILoopDispatch *v15; // [sp-18h] [bp-F8h]@13
    int v16; // [sp-14h] [bp-F4h]@13
    int v17; // [sp-10h] [bp-F0h]@13
    unsigned int v18; // [sp-Ch] [bp-ECh]@13
    int v19; // [sp-8h] [bp-E8h]@13
    void *v20; // [sp-4h] [bp-E4h]@13
    char v21; // [sp+8h] [bp-D8h]@28
    char v22; // [sp+24h] [bp-BCh]@24
    char v23; // [sp+3Ch] [bp-A4h]@20
    int v24; // [sp+54h] [bp-8Ch]@20
    int v25; // [sp+58h] [bp-88h]@20
    unsigned int v26; // [sp+5Ch] [bp-84h]@20
    int v27; // [sp+60h] [bp-80h]@20
    sModeData result; // [sp+64h] [bp-7Ch]@15
    char v29; // [sp+7Ch] [bp-64h]@13
    sModeData mode; // [sp+98h] [bp-48h]@20
    sLoopTransition trans; // [sp+B0h] [bp-30h]@20
    sLoopFrameInfo push_info; // [sp+C8h] [bp-18h]@13
    unsigned int next; // [sp+D8h] [bp-8h]@3
    ILoopDispatch *dispatch; // [sp+DCh] [bp-4h]@5

    if(!this->m_pCurrentDispatch)
        _CriticalMsg("Changing modes outside GO", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0x267u);
    next = ((int(__stdcall *)(ILoopManager *, _GUID *))this->m_pLoopManager->baseclass_0.vfptr[3].QueryInterface)(
        this->m_pLoopManager,
        loop->pID);
    if(!next)
        _CriticalMsg("Change to unknown loopmode", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0x26Au);
    dispatch = 0;
    if(this->m_fState & 0x20
        && (v3 = (_GUID **)((int(__stdcall *)(ILoopDispatch *, _DWORD))this->m_pNextDispatch->baseclass_0.vfptr[2].Release)(
        this->m_pNextDispatch,
        0),
        operator__(loop->pID, *v3)))
    {
        v4 = 1;
    }
    else
    {
        if(kind || (this->m_fState & 0xA0) != 160)
        {
            if(this->m_fState & 0x20)
            {
                if(kind)
                {
                    if(this->m_fState & 0x40)
                    {
                        cLoopModeStack::Pop(this->m_pLoopStack, &result);
                        v6 = this->m_fState;
                        LOBYTE(v6) = v6 & 0xBF;
                        this->m_fState = v6;
                    }
                    if(this->m_pNextDispatch)
                        this->m_pNextDispatch->baseclass_0.vfptr->Release((IUnknown *)this->m_pNextDispatch);
                    this->m_pNextDispatch = 0;
                }
                else
                {
                    push_info.fMinorMode = this->m_FrameInfo.fMinorMode;
                    push_info.nCount = this->m_FrameInfo.nCount;
                    push_info.nTicks = this->m_FrameInfo.nTicks;
                    push_info.dTicks = this->m_FrameInfo.dTicks;
                    push_info.fMinorMode = this->m_fNewMinorMode;
                    v20 = 0;
                    v16 = push_info.fMinorMode;
                    v17 = push_info.nCount;
                    v18 = push_info.nTicks;
                    v19 = push_info.dTicks;
                    sModeData::sModeData((sModeData *)&v29, this->m_pNextDispatch, *(sLoopFrameInfo *)&v16, 0);
                    sModeData::sModeData((sModeData *)&v15, v5);
                    cLoopModeStack::Push(this->m_pLoopStack, *(sModeData *)&v15);
                    kind = 1;
                }
            }
            if(kind == 2)
            {
                v16 = v24;
                v17 = v25;
                v18 = v26;
                v19 = v27;
                sModeData::sModeData(&mode, 0, *(sLoopFrameInfo *)&v16, 0x80u);
                v7 = *(_DWORD *)next;
                v20 = (void *)next;
                trans.to.pID = *(_GUID **)(*(int(__stdcall **)(unsigned int))(v7 + 12))(next);
                trans.to.minorMode = 0;
                trans.to.init = 0;
                v20 = &v23;
                memcpy(&mode, cLoopModeStack::Pop(this->m_pLoopStack, (sModeData *)&v23), sizeof(mode));
                while((_DWORD)mode.dispatch)
                {
                    v20 = &trans.from.init;
                    v8 = mode.dispatch->baseclass_0.vfptr;
                    v19 = (signed int)mode.dispatch;
                    trans.from.pID = *(_GUID **)((int(__stdcall *)(ILoopDispatch *, sLoopModeInitParm **))v8[2].Release)(
                        mode.dispatch,
                        &trans.from.init);
                    if(operator__(trans.from.pID, trans.to.pID))
                    {
                        dispatch = mode.dispatch;
                        this->m_fNewMinorMode = mode.frame.fMinorMode;
                        v9 = this->m_fState;
                        LOBYTE(v9) = v9 | 0x80;
                        this->m_fState = v9;
                        break;
                    }
                    trans.from.minorMode = mode.frame.fMinorMode;
                    v20 = (void *)2;
                    v19 = (int)&trans;
                    v18 = 32768;
                    v10 = mode.dispatch->baseclass_0.vfptr;
                    v17 = (signed int)mode.dispatch;
                    ((void(__stdcall *)(ILoopDispatch *, signed int, sLoopTransition *, signed int))v10[1].QueryInterface)(
                        mode.dispatch,
                        32768,
                        &trans,
                        2);
                    v11 = mode.dispatch->baseclass_0.vfptr;
                    v20 = mode.dispatch;
                    v11->Release((IUnknown *)mode.dispatch);
                    v20 = &v22;
                    memcpy(&mode, cLoopModeStack::Pop(this->m_pLoopStack, (sModeData *)&v22), sizeof(mode));
                }
            }
            if(!dispatch)
            {
                v20 = &dispatch;
                v19 = (int)loop->init;
                v12 = *(_DWORD *)next;
                v18 = next;
                (*(void(__stdcall **)(unsigned int, int, ILoopDispatch **))(v12 + 16))(next, v19, &dispatch);
                this->m_fNewMinorMode = loop->minorMode;
            }
            this->m_pNextDispatch = dispatch;
            v13 = this->m_fState;
            LOBYTE(v13) = v13 | 0x38;
            this->m_fState = v13;
            if(!kind)
            {
                v20 = (void *)128;
                v16 = this->m_FrameInfo.fMinorMode;
                v17 = this->m_FrameInfo.nCount;
                v18 = this->m_FrameInfo.nTicks;
                v19 = this->m_FrameInfo.dTicks;
                v15 = this->m_pCurrentDispatch;
                sModeData::sModeData((sModeData *)&v21, v15, *(sLoopFrameInfo *)&v16, 0x80u);
                sModeData::sModeData((sModeData *)&v15, v14);
                cLoopModeStack::Push(this->m_pLoopStack, *(sModeData *)&v15);
                this->m_fState |= 0x40u;
            }
            v4 = 0;
        }
        else
        {
            v4 = -2147467259;
        }
    }
    return v4;
}

//----- (0089ECAE) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::EndMode(cLoopManager::cLoop *this, int goRetVal)
{
    sModeData *v2; // eax@3
    sModeData result; // [sp+0h] [bp-30h]@3
    sModeData next; // [sp+18h] [bp-18h]@3

    if(!this->m_pCurrentDispatch)
        _CriticalMsg("No loop mode to end!", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0x2CFu);
    this->m_fGoReturn = goRetVal;
    v2 = cLoopModeStack::Pop(this->m_pLoopStack, &result);
    sModeData::sModeData(&next, v2);
    if((_DWORD)next.dispatch)
    {
        this->m_pNextDispatch = next.dispatch;
        this->m_fNewMinorMode = next.frame.fMinorMode;
        this->m_fState |= 0x30u;
        this->m_fState |= next.flags;
    }
    else
    {
        this->m_fState &= 0xFFFFFFFEu;
        this->m_fState |= 0x20u;
        this->m_pNextDispatch = 0;
    }
    return 0;
}

//----- (0089ED62) --------------------------------------------------------
void __stdcall cLoopManager::cLoop::Pause(cLoopManager::cLoop *this, int fPause)
{
    unsigned int v2; // eax@3
    unsigned int v3; // eax@6
    unsigned int fPaused; // [sp+0h] [bp-4h]@1

    fPaused = this->m_fState & 2;
    if(!fPause || fPaused)
    {
        if(!fPause)
        {
            if(fPaused)
            {
                v3 = this->m_fState;
                LOBYTE(v3) = v3 | 8;
                this->m_fState = v3;
            }
        }
    }
    else
    {
        v2 = this->m_fState;
        LOBYTE(v2) = v2 | 4;
        this->m_fState = v2;
    }
}

//----- (0089EDAE) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::IsPaused(cLoopManager::cLoop *this)
{
    return (this->m_fState & 2) != 0;
}

//----- (0089EDC4) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::ChangeMinorMode(cLoopManager::cLoop *this, int minorMode)
{
    int result; // eax@2

    if(minorMode == this->m_FrameInfo.fMinorMode)
    {
        result = 1;
    }
    else
    {
        this->m_fNewMinorMode = minorMode;
        this->m_fState |= 0x10u;
        result = 0;
    }
    return result;
}

//----- (0089EDF7) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::GetMinorMode(cLoopManager::cLoop *this)
{
    return this->m_FrameInfo.fMinorMode;
}

//----- (0089EE04) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::SendMessage(cLoopManager::cLoop *this, int message, tLoopMessageData__ *hData, int flags)
{
    int result; // eax@3

    if(!this->m_pCurrentDispatch
        || ((int(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->m_pCurrentDispatch->baseclass_0.vfptr[1].QueryInterface)(
        this->m_pCurrentDispatch,
        message,
        hData,
        flags))
    {
        if(!this->m_pCurrentDispatch)
            _CriticalMsg("Cannot dispatch messages: no loop mode", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0x31Au);
        result = -2147467259;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (0089EE64) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::SendSimpleMessage(cLoopManager::cLoop *this, int message)
{
    int result; // eax@3

    if(!this->m_pCurrentDispatch
        || ((int(__stdcall *)(_DWORD, _DWORD))this->m_pCurrentDispatch->baseclass_0.vfptr[1].AddRef)(
        this->m_pCurrentDispatch,
        message))
    {
        if(!this->m_pCurrentDispatch)
            _CriticalMsg("Cannot dispatch messages: no loop mode", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0x323u);
        result = -2147467259;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (0089EEBC) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::PostMessage(cLoopManager::cLoop *this, int message, tLoopMessageData__ *hData, int flags)
{
    int result; // eax@3

    if(!this->m_pCurrentDispatch
        || ((int(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->m_pCurrentDispatch->baseclass_0.vfptr[1].Release)(
        this->m_pCurrentDispatch,
        message,
        hData,
        flags))
    {
        if(!this->m_pCurrentDispatch)
            _CriticalMsg("Cannot dispatch messages: no loop mode", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0x32Cu);
        result = -2147467259;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (0089EF1C) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::PostSimpleMessage(cLoopManager::cLoop *this, int message)
{
    int result; // eax@3

    if(!this->m_pCurrentDispatch
        || ((int(__stdcall *)(_DWORD, _DWORD))this->m_pCurrentDispatch->baseclass_0.vfptr[2].QueryInterface)(
        this->m_pCurrentDispatch,
        message))
    {
        if(!this->m_pCurrentDispatch)
            _CriticalMsg("Cannot dispatch messages: no loop mode", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0x335u);
        result = -2147467259;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (0089EF74) --------------------------------------------------------
int __stdcall cLoopManager::cLoop::ProcessQueue(cLoopManager::cLoop *this)
{
    int result; // eax@3

    if(!this->m_pCurrentDispatch
        || this->m_pCurrentDispatch->baseclass_0.vfptr[2].AddRef((IUnknown *)this->m_pCurrentDispatch))
    {
        if(!this->m_pCurrentDispatch)
            _CriticalMsg("Cannot dispatch messages: no loop mode", "x:\\prj\\tech\\libsrc\\darkloop\\loopman.cpp", 0x33Eu);
        result = -2147467259;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (0089EFC8) --------------------------------------------------------
void __stdcall cLoopManager::cLoop::SetDiagnostics(cLoopManager::cLoop *this, unsigned int fDiagnostics, unsigned int messages)
{
    if(this->m_pCurrentDispatch)
    {
        this->m_pCurrentDispatch->baseclass_0.vfptr[3].QueryInterface(
            (IUnknown *)this->m_pCurrentDispatch,
            (_GUID *)fDiagnostics,
            (void **)messages);
    }
    else
    {
        this->m_fTempDiagnostics = fDiagnostics;
        this->m_tempDiagnosticSet = messages;
    }
}

//----- (0089F006) --------------------------------------------------------
void __stdcall cLoopManager::cLoop::GetDiagnostics(cLoopManager::cLoop *this, unsigned int *pfDiagnostics, unsigned int *pMessages)
{
    if(this->m_pCurrentDispatch)
    {
        ((void(__stdcall *)(_DWORD, _DWORD, _DWORD))this->m_pCurrentDispatch->baseclass_0.vfptr[3].AddRef)(
            this->m_pCurrentDispatch,
            pfDiagnostics,
            pMessages);
    }
    else
    {
        *pfDiagnostics = this->m_fTempDiagnostics;
        *pMessages = this->m_tempDiagnosticSet;
    }
}

//----- (0089F048) --------------------------------------------------------
void __stdcall cLoopManager::cLoop::SetProfile(cLoopManager::cLoop *this, unsigned int messages, _GUID *pClientId)
{
    if(this->m_pCurrentDispatch)
    {
        ((void(__stdcall *)(_DWORD, _DWORD, _DWORD))this->m_pCurrentDispatch->baseclass_0.vfptr[3].Release)(
            this->m_pCurrentDispatch,
            messages,
            pClientId);
    }
    else
    {
        this->m_TempProfileSet = messages;
        this->m_pTempProfileClientId = pClientId;
    }
}

//----- (0089F086) --------------------------------------------------------
void __stdcall cLoopManager::cLoop::GetProfile(cLoopManager::cLoop *this, unsigned int *pMessages, _GUID **ppClientId)
{
    if(this->m_pCurrentDispatch)
    {
        this->m_pCurrentDispatch->baseclass_0.vfptr[4].QueryInterface(
            (IUnknown *)this->m_pCurrentDispatch,
            (_GUID *)pMessages,
            (void **)ppClientId);
    }
    else
    {
        *pMessages = this->m_TempProfileSet;
        *ppClientId = this->m_pTempProfileClientId;
    }
}

//----- (0089F0C8) --------------------------------------------------------
int __cdecl cLoopManager::cLoop::OnExit()
{
    int result; // eax@2

    if(cLoopManager::cLoop::gm_pLoop)
    {
        result = cLoopManager::cLoop::gm_pLoop;
        if(*(_DWORD *)(cLoopManager::cLoop::gm_pLoop + 8))
        {
            result = (*(int(__stdcall **)(_DWORD))(**(_DWORD **)(cLoopManager::cLoop::gm_pLoop + 8) + 8))(*(_DWORD *)(cLoopManager::cLoop::gm_pLoop + 8));
            *(_DWORD *)(cLoopManager::cLoop::gm_pLoop + 8) = 0;
        }
    }
    return result;
}
// EA66C8: using guessed type int cLoopManager__cLoop__gm_pLoop;

//----- (0089F110) --------------------------------------------------------
IUnknown *__thiscall cLoopManager::cOuterPointer::operator_>(cLoopManager::cOuterPointer *this)
{
    return this->m_pOuterUnknown;
}

//----- (0089F120) --------------------------------------------------------
int __thiscall cLoopManager::Connect(cLoopManager *this)
{
    return 0;
}

//----- (0089F130) --------------------------------------------------------
int __thiscall cLoopManager::PostConnect(cLoopManager *this)
{
    return 0;
}

//----- (0089F140) --------------------------------------------------------
int __thiscall cLoopManager::Init(cLoopManager *this)
{
    return 0;
}

//----- (0089F150) --------------------------------------------------------
int __thiscall cLoopManager::Disconnect(cLoopManager *this)
{
    return 0;
}

//----- (0089F160) --------------------------------------------------------
unsigned int __thiscall cLoopManager::cComplexAggregateControl::cRefCount::AddRef(cLoopManager::cComplexAggregateControl::cRefCount *this)
{
    ++this->ul;
    return this->ul;
}

//----- (0089F180) --------------------------------------------------------
unsigned int __thiscall cLoopManager::cComplexAggregateControl::cRefCount::Release(cLoopManager::cComplexAggregateControl::cRefCount *this)
{
    --this->ul;
    return this->ul;
}

//----- (0089F1A0) --------------------------------------------------------
unsigned int __thiscall cLoopManager::cComplexAggregateControl::cRefCount::operator unsigned_long(cLoopManager::cComplexAggregateControl::cRefCount *this)
{
    return this->ul;
}

//----- (0089F1B0) --------------------------------------------------------
void __thiscall cLoopManager::cComplexAggregateControl::OnFinalRelease(cLoopManager::cComplexAggregateControl *this)
{
    if(this->m_pAggregateMember)
        cLoopManager::OnFinalRelease(this->m_pAggregateMember);
}

//----- (0089F1D0) --------------------------------------------------------
void __thiscall cLoopManager::OnFinalRelease(cLoopManager *this)
{
    if(this)
        ((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[4].AddRef)(this, 1);
}

//----- (0089F210) --------------------------------------------------------
void __thiscall cLoopManager::cOuterPointer::cOuterPointer(cLoopManager::cOuterPointer *this)
{
    this->m_pOuterUnknown = 0;
}

//----- (0089F230) --------------------------------------------------------
void __thiscall cLoopManager::cOuterPointer::Init(cLoopManager::cOuterPointer *this, IUnknown *p)
{
    this->m_pOuterUnknown = p;
}

//----- (0089F250) --------------------------------------------------------
void __thiscall cLoopManager::cComplexAggregateControl::cComplexAggregateControl(cLoopManager::cComplexAggregateControl *this)
{
    cLoopManager::cComplexAggregateControl *v1; // ST00_4@1

    v1 = this;
    IAggregateMemberControl::IAggregateMemberControl(&this->baseclass_0);
    cLoopManager::cComplexAggregateControl::cRefCount::cRefCount(&v1->__m_ulRefs);
    v1->m_pAggregateMember = 0;
    v1->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cLoopManager::cComplexAggregateControl::_vftable_;
}
// 9A6A2C: using guessed type int (__stdcall *cLoopManager__cComplexAggregateControl___vftable_)(int this, int id, int ppI);

//----- (0089F290) --------------------------------------------------------
void __thiscall cLoopManager::cComplexAggregateControl::cRefCount::cRefCount(cLoopManager::cComplexAggregateControl::cRefCount *this)
{
    this->ul = 1;
}

//----- (0089F2B0) --------------------------------------------------------
void __thiscall cLoopManager::cComplexAggregateControl::InitControl(cLoopManager::cComplexAggregateControl *this, cLoopManager *p)
{
    this->m_pAggregateMember = p;
}

//----- (0089F2D0) --------------------------------------------------------
void __thiscall cLoopManager::cLoop::cLoop(cLoopManager::cLoop *this, IUnknown *pOuterUnknown, cLoopManager *pLoopManager)
{
    cLoopModeStack *v3; // eax@2
    cLoopModeStack *v4; // [sp+0h] [bp-Ch]@2
    cLoopManager::cLoop *thisa; // [sp+4h] [bp-8h]@1
    void *v6; // [sp+8h] [bp-4h]@1

    thisa = this;
    ILoop::ILoop(&this->baseclass_0);
    cLoopManager::cLoop::cOuterPointer::cOuterPointer(&thisa->__m_pOuterUnknown);
    thisa->m_pCurrentDispatch = 0;
    thisa->m_fState = 0;
    thisa->m_fGoReturn = 0;
    thisa->m_pLoopManager = (ILoopManager *)pLoopManager;
    v6 = j__new(8u, "x:\\prj\\tech\\libsrc\\darkloop\\loopman.h", 167);
    if(v6)
    {
        cLoopModeStack::cLoopModeStack((cLoopModeStack *)v6);
        v4 = v3;
    }
    else
    {
        v4 = 0;
    }
    thisa->m_pLoopStack = v4;
    thisa->m_pNextDispatch = 0;
    thisa->m_fTempDiagnostics = 0;
    thisa->m_tempDiagnosticSet = 0;
    thisa->m_TempProfileSet = 0;
    thisa->m_pTempProfileClientId = 0;
    thisa->baseclass_0.lpVtbl = (ILoopVtbl *)&cLoopManager::cLoop::_vftable_;
    cLoopManager::cLoop::cOuterPointer::Init(&thisa->__m_pOuterUnknown, pOuterUnknown);
    thisa->m_FrameInfo.nCount = 0;
    thisa->m_FrameInfo.fMinorMode = 0;
    cLoopManager::cLoop::gm_pLoop = (int)thisa;
}
// 9A6A4C: using guessed type int (__stdcall *cLoopManager__cLoop___vftable_)(int this, int id, int ppI);
// EA66C8: using guessed type int cLoopManager__cLoop__gm_pLoop;

//----- (0089F3C0) --------------------------------------------------------
void __thiscall cLoopModeStack::cLoopModeStack(cLoopModeStack *this)
{
    cDList<cLoopModeElem_1>::cDList<cLoopModeElem_1>(&this->baseclass_0);
}

//----- (0089F3E0) --------------------------------------------------------
void __thiscall cDList<cLoopModeElem_1>::cDList<cLoopModeElem_1>(cDList<cLoopModeElem, 1> *this)
{
    cDListBase::cDListBase(&this->baseclass_0);
}

//----- (0089F400) --------------------------------------------------------
void __thiscall cLoopManager::cLoop::cOuterPointer::cOuterPointer(cLoopManager::cLoop::cOuterPointer *this)
{
    this->m_pOuterUnknown = 0;
}

//----- (0089F420) --------------------------------------------------------
void __thiscall cLoopManager::cLoop::cOuterPointer::Init(cLoopManager::cLoop::cOuterPointer *this, IUnknown *p)
{
    this->m_pOuterUnknown = p;
}

//----- (0089F440) --------------------------------------------------------
void *__thiscall cLoopManager::cLoop::_scalar_deleting_destructor_(cLoopManager::cLoop *this, unsigned int __flags)
{
    void *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    cLoopManager::cLoop::_cLoop(this);
    if(__flags & 1)
        operator delete(thisa);
    return thisa;
}

//----- (0089F470) --------------------------------------------------------
void __thiscall ILoop::ILoop(ILoop *this)
{
    ILoop *v1; // ST00_4@1

    v1 = this;
    IUnknown::IUnknown((IUnknown *)this);
    v1->lpVtbl = (ILoopVtbl *)ILoop::_vftable_;
}
// 9A6AB0: using guessed type int (*ILoop___vftable_[37])();

//----- (0089F490) --------------------------------------------------------
void *__thiscall cLoopManager::_vector_deleting_destructor_(cLoopManager *this, unsigned int __flags)
{
    void *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    cLoopManager::_cLoopManager(this);
    if(__flags & 1)
        operator delete(thisa);
    return thisa;
}

//----- (0089F4C0) --------------------------------------------------------
void __thiscall ILoopManager::ILoopManager(ILoopManager *this)
{
    ILoopManager *v1; // ST00_4@1

    v1 = this;
    IUnknown::IUnknown(&this->baseclass_0);
    v1->baseclass_0.vfptr = (IUnknownVtbl *)ILoopManager::_vftable_;
}
// 9A6B10: using guessed type int (*ILoopManager___vftable_[13])();

//----- (0089F4E0) --------------------------------------------------------
IUnknown *__thiscall cLoopManager::cLoop::cOuterPointer::operator_>(cLoopManager::cLoop::cOuterPointer *this)
{
    return this->m_pOuterUnknown;
}

//----- (0089F4F0) --------------------------------------------------------
void __thiscall sModeData::sModeData(sModeData *this, ILoopDispatch *chain, sLoopFrameInfo info, unsigned int f)
{
    this->dispatch = chain;
    this->frame.fMinorMode = info.fMinorMode;
    this->frame.nCount = info.nCount;
    this->frame.nTicks = info.nTicks;
    this->frame.dTicks = info.dTicks;
    this->flags = f;
}

//----- (0089F530) --------------------------------------------------------
void __thiscall sModeData::sModeData(sModeData *this, sModeData *mode)
{
    memcpy(this, mode, 0x18u);
}

//----- (0089F560) --------------------------------------------------------
void __thiscall cLoopModeStack::Push(cLoopModeStack *this, sModeData data)
{
    cLoopModeElem *v2; // eax@2
    cLoopModeElem *v3; // [sp+0h] [bp-10h]@2
    cDList<cLoopModeElem, 1> *thisa; // [sp+4h] [bp-Ch]@1
    void *v5; // [sp+8h] [bp-8h]@1

    thisa = (cDList<cLoopModeElem, 1> *)this;
    v5 = j__new(0x20u, "x:\\prj\\tech\\libsrc\\darkloop\\loopman.h", 81);
    if(v5)
    {
        cLoopModeElem::cLoopModeElem((cLoopModeElem *)v5, &data);
        v3 = v2;
    }
    else
    {
        v3 = 0;
    }
    cDList<cLoopModeElem_1>::Prepend(thisa, v3);
}

//----- (0089F5C0) --------------------------------------------------------
void __thiscall cLoopModeElem::cLoopModeElem(cLoopModeElem *this, sModeData *data)
{
    cLoopModeElem *v2; // ST04_4@1

    v2 = this;
    cDListNode<cLoopModeElem_1>::cDListNode<cLoopModeElem_1>(&this->baseclass_0);
    sModeData::sModeData(&v2->modedata, data);
}

//----- (0089F5F0) --------------------------------------------------------
void __thiscall cDListNode<cLoopModeElem_1>::cDListNode<cLoopModeElem_1>(cDListNode<cLoopModeElem, 1> *this)
{
    cDListNodeBase::cDListNodeBase(&this->baseclass_0);
}

//----- (0089F610) --------------------------------------------------------
sModeData *__thiscall cLoopModeStack::Pop(cLoopModeStack *this, sModeData *result)
{
    sLoopFrameInfo v2; // ST04_16@2
    sModeData *v3; // eax@2
    sModeData *v4; // eax@2
    cDList<cLoopModeElem, 1> *thisa; // [sp+0h] [bp-4Ch]@1
    __int64 v6; // [sp+8h] [bp-44h]@0
    __int64 v7; // [sp+10h] [bp-3Ch]@0
    char v8; // [sp+18h] [bp-34h]@2
    sModeData outval; // [sp+30h] [bp-1Ch]@3
    cLoopModeElem *first; // [sp+48h] [bp-4h]@1

    thisa = (cDList<cLoopModeElem, 1> *)this;
    first = cDList<cLoopModeElem_1>::GetFirst(&this->baseclass_0);
    if(first)
    {
        sModeData::sModeData(&outval, &first->modedata);
        cDList<cLoopModeElem_1>::Remove(thisa, first);
        operator delete(first);
        sModeData::sModeData(result, &outval);
        v4 = result;
    }
    else
    {
        *(_QWORD *)&v2.fMinorMode = v6;
        *(_QWORD *)&v2.nTicks = v7;
        sModeData::sModeData((sModeData *)&v8, 0, v2, 0x80u);
        sModeData::sModeData(result, v3);
        v4 = result;
    }
    return v4;
}

//----- (0089F6B0) --------------------------------------------------------
int __thiscall cIPtr<IGameShell>::operator__(cIPtr<IGameShell> *this, IGameShell *p)
{
    return cIPtrBase::operator__(&this->baseclass_0, p);
}

//----- (0089F6D0) --------------------------------------------------------
void __thiscall cDList<cLoopModeElem_1>::Prepend(cDList<cLoopModeElem, 1> *this, cLoopModeElem *Node)
{
    cDListBase::Prepend(&this->baseclass_0, &Node->baseclass_0.baseclass_0);
}

//----- (0089F6F0) --------------------------------------------------------
cLoopModeElem *__thiscall cDList<cLoopModeElem_1>::Remove(cDList<cLoopModeElem, 1> *this, cLoopModeElem *Node)
{
    return (cLoopModeElem *)cDListBase::Remove(&this->baseclass_0, &Node->baseclass_0.baseclass_0);
}

//----- (0089F710) --------------------------------------------------------
cLoopModeElem *__thiscall cDList<cLoopModeElem_1>::GetFirst(cDList<cLoopModeElem, 1> *this)
{
    return (cLoopModeElem *)cDListBase::GetFirst(&this->baseclass_0);
}

//----- (0089F730) --------------------------------------------------------
ILoopMode *__stdcall _LoopModeCreate(sLoopModeDesc *pDescription)
{
    ILoopMode *v1; // eax@2
    ILoopMode *v3; // [sp+0h] [bp-8h]@2
    void *this; // [sp+4h] [bp-4h]@1

    this = j__new(0x34u, "x:\\prj\\tech\\libsrc\\darkloop\\loopmode.cpp", 22);
    if(this)
    {
        cLoopMode::cLoopMode((cLoopMode *)this, pDescription);
        v3 = v1;
    }
    else
    {
        v3 = 0;
    }
    return v3;
}

//----- (0089F771) --------------------------------------------------------
int __stdcall cLoopMode::QueryInterface(cLoopMode *this, _GUID *id, void **ppI)
{
    int result; // eax@5

    if(id != &IID_ILoopMode
        && id != &IID_IUnknown
        && memcmp(id, &IID_ILoopMode, 0x10u)
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

//----- (0089F7DE) --------------------------------------------------------
unsigned int __stdcall cLoopMode::AddRef(cLoopMode *this)
{
    return cLoopMode::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (0089F7F0) --------------------------------------------------------
unsigned int __stdcall cLoopMode::Release(cLoopMode *this)
{
    unsigned int result; // eax@2

    if(cLoopMode::cRefCount::Release(&this->__m_ulRefs))
    {
        result = cLoopMode::cRefCount::operator unsigned_long(&this->__m_ulRefs);
    }
    else
    {
        cLoopMode::OnFinalRelease(this);
        result = 0;
    }
    return result;
}

//----- (0089F81D) --------------------------------------------------------
void __thiscall cLoopMode::cLoopMode(cLoopMode *this, sLoopModeDesc *pDescription)
{
    cLoopMode *thisa; // [sp+8h] [bp-8h]@1

    thisa = this;
    ILoopMode::ILoopMode(&this->baseclass_0);
    cLoopMode::cRefCount::cRefCount(&thisa->__m_ulRefs);
    thisa->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cLoopMode::_vftable_;
    if(!pDescription->ppClientIDs)
        _CriticalMsg("Empty loop modes are not supported", "x:\\prj\\tech\\libsrc\\darkloop\\loopmode.cpp", 0x26u);
    memcpy(&thisa->m_desc, pDescription, sizeof(thisa->m_desc));
    thisa->m_desc.ppClientIDs = (_GUID **)j__new(
        4 * thisa->m_desc.nClients,
        "x:\\prj\\tech\\libsrc\\darkloop\\loopmode.cpp",
        41);
    memcpy(thisa->m_desc.ppClientIDs, pDescription->ppClientIDs, 4 * pDescription->nClients);
}
// 9A6B44: using guessed type int (__stdcall *cLoopMode___vftable_)(int this, int id, int ppI);

//----- (0089F8C6) --------------------------------------------------------
void __thiscall cLoopMode::_cLoopMode(cLoopMode *this)
{
    this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cLoopMode::_vftable_;
    operator delete(this->m_desc.ppClientIDs);
}
// 9A6B44: using guessed type int (__stdcall *cLoopMode___vftable_)(int this, int id, int ppI);

//----- (0089F8F1) --------------------------------------------------------
sLoopModeName *__stdcall cLoopMode::GetName(cLoopMode *this)
{
    return &this->m_desc.name;
}

//----- (0089F8FE) --------------------------------------------------------
int __stdcall cLoopMode::CreatePartialDispatch(cLoopMode *this, sLoopModeInitParm *list, unsigned int msgs, ILoopDispatch **result)
{
    ILoopDispatch *v4; // eax@2
    ILoopDispatch *v6; // [sp+0h] [bp-8h]@2
    void *v7; // [sp+4h] [bp-4h]@1

    v7 = j__new(0x2DCu, "x:\\prj\\tech\\libsrc\\darkloop\\loopmode.cpp", 71);
    if(v7)
    {
        cLoopDispatch::cLoopDispatch((cLoopDispatch *)v7, &this->baseclass_0, list, msgs);
        v6 = v4;
    }
    else
    {
        v6 = 0;
    }
    *result = v6;
    return *result != 0 ? 0 : -2147467259;
}

//----- (0089F962) --------------------------------------------------------
int __stdcall cLoopMode::CreateDispatch(cLoopMode *this, sLoopModeInitParm *list, ILoopDispatch **result)
{
    return ((int(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[1].Release)(
        this,
        list,
        -1,
        result);
}

//----- (0089F97F) --------------------------------------------------------
sLoopModeDesc *__stdcall cLoopMode::Describe(cLoopMode *this)
{
    return &this->m_desc;
}

//----- (0089F990) --------------------------------------------------------
unsigned int __thiscall cLoopMode::cRefCount::AddRef(cLoopMode::cRefCount *this)
{
    ++this->ul;
    return this->ul;
}

//----- (0089F9B0) --------------------------------------------------------
unsigned int __thiscall cLoopMode::cRefCount::Release(cLoopMode::cRefCount *this)
{
    --this->ul;
    return this->ul;
}

//----- (0089F9D0) --------------------------------------------------------
unsigned int __thiscall cLoopMode::cRefCount::operator unsigned_long(cLoopMode::cRefCount *this)
{
    return this->ul;
}

//----- (0089F9E0) --------------------------------------------------------
void __thiscall cLoopMode::OnFinalRelease(cLoopMode *this)
{
    if(this)
        ((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[2].AddRef)(this, 1);
}

//----- (0089FA20) --------------------------------------------------------
void __thiscall cLoopMode::cRefCount::cRefCount(cLoopMode::cRefCount *this)
{
    this->ul = 1;
}

//----- (0089FA40) --------------------------------------------------------
void *__thiscall cLoopMode::_vector_deleting_destructor_(cLoopMode *this, unsigned int __flags)
{
    void *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    cLoopMode::_cLoopMode(this);
    if(__flags & 1)
        operator delete(thisa);
    return thisa;
}

//----- (0089FA70) --------------------------------------------------------
void __thiscall ILoopMode::ILoopMode(ILoopMode *this)
{
    ILoopMode *v1; // ST00_4@1

    v1 = this;
    IUnknown::IUnknown(&this->baseclass_0);
    v1->baseclass_0.vfptr = (IUnknownVtbl *)ILoopMode::_vftable_;
}
// 9A6B64: using guessed type int (*ILoopMode___vftable_[7])();

//----- (0089FA90) --------------------------------------------------------
int __stdcall cLoopDispatch::QueryInterface(cLoopDispatch *this, _GUID *id, void **ppI)
{
    int result; // eax@5

    if(id != &IID_ILoopDispatch
        && id != &IID_IUnknown
        && memcmp(id, &IID_ILoopDispatch, 0x10u)
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

//----- (0089FAFD) --------------------------------------------------------
unsigned int __stdcall cLoopDispatch::AddRef(cLoopDispatch *this)
{
    return cLoopDispatch::cRefCount::AddRef(&this->__m_ulRefs);
}

//----- (0089FB0F) --------------------------------------------------------
unsigned int __stdcall cLoopDispatch::Release(cLoopDispatch *this)
{
    unsigned int result; // eax@2

    if(cLoopDispatch::cRefCount::Release(&this->__m_ulRefs))
    {
        result = cLoopDispatch::cRefCount::operator unsigned_long(&this->__m_ulRefs);
    }
    else
    {
        cLoopDispatch::OnFinalRelease(this);
        result = 0;
    }
    return result;
}

//----- (0089FB3C) --------------------------------------------------------
void __thiscall cLoopDispatch::cLoopDispatch(cLoopDispatch *this, ILoopMode *loop, sLoopModeInitParm *parmList, unsigned int msgs)
{
    unsigned int v4; // eax@1
    IUnknown *v5; // eax@1
    ILoopManager *v6; // ST14_4@2
    IUnknown *v7; // ST10_4@5
    cLoopDispatch *thisa; // [sp+8h] [bp-10Ch]@1
    ILoopMode *pBaseMode; // [sp+Ch] [bp-108h]@2
    ConstraintTable constraints; // [sp+10h] [bp-104h]@1
    cAutoIPtr<ILoopManager> pLoopManager; // [sp+110h] [bp-4h]@1

    thisa = this;
    ILoopDispatch::ILoopDispatch(&this->baseclass_0);
    cLoopDispatch::cRefCount::cRefCount(&thisa->__m_ulRefs);
    v4 = msgs;
    LOBYTE(v4) = msgs | 3;
    thisa->m_msgs = v4;
    cLoopQueue::cLoopQueue(&thisa->m_Queue);
    _vector_constructor_iterator_(
        thisa->m_DispatchLists,
        8u,
        32,
        (void(__thiscall *)(void *))cPriIntArray<ILoopClient>::cPriIntArray<ILoopClient>);
    thisa->m_pLoopMode = loop;
    cClientInfoList::cClientInfoList(&thisa->m_aClientInfo);
    thisa->m_fDiagnostics = 0;
    thisa->m_diagnosticSet = 0;
    thisa->m_ProfileSet = 0;
    thisa->m_pProfileClientId = 0;
    cAverageTimer::cAverageTimer(&thisa->m_AverageFrameTimer);
    cSimpleTimer::cSimpleTimer(&thisa->m_TotalModeTime);
    cLoopDispatch::cInitParmTable::cInitParmTable(&thisa->m_Parms, parmList);
    thisa->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cLoopDispatch::_vftable_;
    ConstraintTable::ConstraintTable(&constraints);
    cLoopDispatch::AddClientsFromMode(thisa, loop, &constraints);
    v5 = _AppGetAggregated(&IID_ILoopManager);
    cAutoIPtr<ILoopManager>::cAutoIPtr<ILoopManager>(&pLoopManager, (ILoopManager *)v5);
    if(cIPtr<ILoopManager>::operator__(&pLoopManager.baseclass_0, 0))
    {
        v6 = cIPtr<ILoopManager>::operator_>(&pLoopManager.baseclass_0);
        pBaseMode = (ILoopMode *)((int(__stdcall *)(ILoopManager *))v6->baseclass_0.vfptr[4].QueryInterface)(v6);
        cLoopDispatch::AddClientsFromMode(thisa, pBaseMode, &constraints);
        if(pBaseMode)
            pBaseMode->baseclass_0.vfptr->Release((IUnknown *)pBaseMode);
    }
    cLoopDispatch::SortClients(thisa, &constraints);
    if(cIPtrBase::operator IUnknown__(&pLoopManager.baseclass_0.baseclass_0))
    {
        v7 = cIPtrBase::operator IUnknown__(&pLoopManager.baseclass_0.baseclass_0);
        v7->vfptr->Release(v7);
    }
    cAutoIPtr<ILoopManager>::operator_(&pLoopManager, 0);
    cLoopDispatch::SendSimpleMessage(thisa, 1);
    cAutoIPtr<ILoopManager>::_cAutoIPtr<ILoopManager>(&pLoopManager);
    ConstraintTable::_ConstraintTable(&constraints);
}
// 9A6B80: using guessed type int (__stdcall *cLoopDispatch___vftable_)(int this, int id, int ppI);

//----- (0089FD5B) --------------------------------------------------------
void __thiscall cLoopDispatch::SortClients(cLoopDispatch *this, ConstraintTable *constraints)
{
    cDynArray<sAbsoluteConstraint> *v2; // eax@3
    unsigned int v3; // ST04_4@3
    cDynArray<sAbsoluteConstraint> *v4; // eax@3
    sAbsoluteConstraint *v5; // ST00_4@3
    cLoopDispatch *thisa; // [sp+0h] [bp-8h]@1
    int i; // [sp+4h] [bp-4h]@1

    thisa = this;
    for(i = 0; i < 32; ++i)
    {
        v2 = ConstraintTable::operator__(constraints, i);
        v3 = cDABase<sAbsoluteConstraint_4_cDARawSrvFns<sAbsoluteConstraint>>::Size((cDABase<sAbsoluteConstraint, 4, cDARawSrvFns<sAbsoluteConstraint>> *)v2);
        v4 = ConstraintTable::operator__(constraints, i);
        v5 = cDABase<sAbsoluteConstraint_4_cDARawSrvFns<sAbsoluteConstraint>>::AsPointer((cDABase<sAbsoluteConstraint, 4, cDARawSrvFns<sAbsoluteConstraint>> *)v4);
        cPriGuidSetBase::Sort(&thisa->m_DispatchLists[i].baseclass_0.baseclass_0, v5, v3);
    }
}

//----- (0089FDBE) --------------------------------------------------------
void __thiscall cLoopDispatch::AddClientsFromMode(cLoopDispatch *this, ILoopMode *pLoop, ConstraintTable *constraints)
{
    IUnknown *v3; // eax@2
    int v4; // eax@9
    _GUID **v5; // eax@10
    _GUID *v6; // ST04_4@17
    ILoopManager *v7; // eax@17
    _GUID *v8; // ST0C_4@18
    ILoopManager *v9; // ST10_4@18
    sClientInfo *v10; // eax@25
    tLoopClientData__ *v11; // [sp+8h] [bp-C8h]@15
    cLoopDispatch *thisa; // [sp+Ch] [bp-C4h]@1
    char v13; // [sp+10h] [bp-C0h]@25
    int msg; // [sp+8Ch] [bp-44h]@26
    int i; // [sp+90h] [bp-40h]@26
    ILoopMode *mode; // [sp+94h] [bp-3Ch]@18
    sLoopModeInitParm *pInitParms; // [sp+98h] [bp-38h]@14
    sClientInfo *info; // [sp+9Ch] [bp-34h]@25
    char next_client; // [sp+A0h] [bp-30h]@8
    int pClientDesc; // [sp+A4h] [bp-2Ch]@25
    _GUID *pID; // [sp+A8h] [bp-28h]@7
    ILoopClient *pClient; // [sp+ACh] [bp-24h]@14
    int infoidx; // [sp+B0h] [bp-20h]@25
    int idx; // [sp+B4h] [bp-1Ch]@8
    char *ppLimit; // [sp+B8h] [bp-18h]@4
    cAutoIPtr<ILoopManager> pLoopManager; // [sp+BCh] [bp-14h]@2
    int fFirstWarning; // [sp+C0h] [bp-10h]@4
    cLoopDispatch::cInitParmTable *initParmTable; // [sp+C4h] [bp-Ch]@4
    int desc; // [sp+C8h] [bp-8h]@4
    char *ppIDs; // [sp+CCh] [bp-4h]@4

    thisa = this;
    if(pLoop)
    {
        v3 = _AppGetAggregated(&IID_ILoopManager);
        cAutoIPtr<ILoopManager>::cAutoIPtr<ILoopManager>(&pLoopManager, (ILoopManager *)v3);
        if(cIPtrBase::operator_(&pLoopManager.baseclass_0.baseclass_0))
            _CriticalMsg(
            "Failed to locate ILoopManager implementation",
            "x:\\prj\\tech\\libsrc\\darkloop\\loopdisp.cpp",
            0xB3u);
        fFirstWarning = 1;
        desc = ((int(__stdcall *)(ILoopMode *))pLoop->baseclass_0.vfptr[2].QueryInterface)(pLoop);
        ppIDs = *(char **)(desc + 36);
        ppLimit = &ppIDs[4 * *(_DWORD *)(desc + 40)];
        initParmTable = &thisa->m_Parms;
        while(ppIDs < ppLimit)
        {
            pID = *(_GUID **)ppIDs;
            if(!operator__(pID, &GUID_NULL))
            {
                next_client = 0;
                for(idx = 0;; ++idx)
                {
                    v4 = cClientInfoList::Size(&thisa->m_aClientInfo);
                    if(idx >= v4)
                        break;
                    v5 = (_GUID **)cClientInfoList::operator__(&thisa->m_aClientInfo, idx);
                    if(operator__(pID, *v5))
                    {
                        next_client = 1;
                        break;
                    }
                }
                if(!next_client)
                {
                    pInitParms = cLoopDispatch::cInitParmTable::Search(initParmTable, pID);
                    pClient = 0;
                    if(pInitParms)
                        v11 = pInitParms->data;
                    else
                        v11 = 0;
                    v6 = pID;
                    v7 = cIPtr<ILoopManager>::operator_>(&pLoopManager.baseclass_0);
                    ((void(__stdcall *)(ILoopManager *, _GUID *, tLoopClientData__ *, ILoopClient **))v7->baseclass_0.vfptr[2].AddRef)(
                        v7,
                        v6,
                        v11,
                        &pClient);
                    if(pClient)
                    {
                        pClientDesc = pClient->baseclass_0.vfptr[1].AddRef((IUnknown *)pClient);
                        sClientInfo::sClientInfo((sClientInfo *)&v13);
                        infoidx = cClientInfoList::Append(&thisa->m_aClientInfo, v10);
                        sClientInfo::_sClientInfo((sClientInfo *)&v13);
                        info = cClientInfoList::operator__(&thisa->m_aClientInfo, infoidx);
                        cTimerBase::SetName(&info->timer.baseclass_0, (const char *)(pClientDesc + 4));
                        info->priIntInfo.baseclass_0.pID = pID;
                        info->priIntInfo.pInterface = pClient;
                        info->priIntInfo.baseclass_0.priority = *(_DWORD *)(pClientDesc + 44);
                        cAnsiStr::operator_(&info->priIntInfo.nameStr, (const char *)(pClientDesc + 4));
                        info->priIntInfo.pData = cClientInfoList::operator__(&thisa->m_aClientInfo, infoidx);
                        info->interests = *(_DWORD *)(pClientDesc + 48);
                        if(thisa->m_msgs & info->interests)
                        {
                            msg = 1;
                            i = 0;
                            while(msg)
                            {
                                if(thisa->m_msgs & msg & info->interests)
                                    cPriGuidSet<sPriIntInfo<ILoopClient>>::Append(
                                    &thisa->m_DispatchLists[i].baseclass_0,
                                    &info->priIntInfo);
                                ++i;
                                msg *= 2;
                            }
                        }
                        TableAddClientConstraints(constraints, (sLoopClientDesc *)pClientDesc);
                    }
                    else
                    {
                        v8 = pID;
                        v9 = cIPtr<ILoopManager>::operator_>(&pLoopManager.baseclass_0);
                        mode = (ILoopMode *)((int(__stdcall *)(ILoopManager *, _GUID *))v9->baseclass_0.vfptr[3].QueryInterface)(
                            v9,
                            v8);
                        if(mode)
                        {
                            cLoopDispatch::AddClientsFromMode(thisa, mode, constraints);
                            if(mode)
                                mode->baseclass_0.vfptr->Release((IUnknown *)mode);
                            mode = 0;
                        }
                        else
                        {
                            if(fFirstWarning)
                            {
                                DbgReportWarning("Loop mode \"%s\" did not find all expected clients\n");
                                fFirstWarning = 0;
                            }
                        }
                    }
                }
            }
            ppIDs += 4;
        }
        cAutoIPtr<ILoopManager>::_cAutoIPtr<ILoopManager>(&pLoopManager);
    }
}

//----- (008A0121) --------------------------------------------------------
void __cdecl TableAddClientConstraints(ConstraintTable *table, sLoopClientDesc *desc)
{
    cDynArray<sAbsoluteConstraint> *v2; // eax@10
    sAbsoluteConstraint absoluteConstraint; // [sp+0h] [bp-14h]@7
    int i; // [sp+8h] [bp-Ch]@7
    int currentMessage; // [sp+Ch] [bp-8h]@7
    sLoopClientDesc *pRel; // [sp+10h] [bp-4h]@1

    for(pRel = desc + 1; pRel->pID; pRel = (sLoopClientDesc *)((char *)pRel + 12))
    {
        if(pRel->pID != (_GUID *)1 && pRel->pID != (_GUID *)2)
            _CriticalMsg("Bad constraint", "x:\\prj\\tech\\libsrc\\darkloop\\loopdisp.cpp", 0x93u);
        MakeAbsolute((sRelativeConstraint *)pRel, desc->pID, &absoluteConstraint);
        currentMessage = 1;
        i = 0;
        while(currentMessage)
        {
            if(currentMessage & *(_DWORD *)&pRel->szName[4])
            {
                v2 = ConstraintTable::operator__(table, i);
                cDABase<sAbsoluteConstraint_4_cDARawSrvFns<sAbsoluteConstraint>>::Append(
                    (cDABase<sAbsoluteConstraint, 4, cDARawSrvFns<sAbsoluteConstraint>> *)v2,
                    &absoluteConstraint);
            }
            ++i;
            currentMessage *= 2;
        }
    }
}

//----- (008A01DD) --------------------------------------------------------
void __thiscall cLoopDispatch::_cLoopDispatch(cLoopDispatch *this)
{
    sClientInfo *v1; // eax@4
    cLoopDispatch *thisa; // [sp+4h] [bp-8h]@1
    int i; // [sp+8h] [bp-4h]@1

    thisa = this;
    this->baseclass_0.baseclass_0.vfptr = (IUnknownVtbl *)&cLoopDispatch::_vftable_;
    cLoopDispatch::SendMessage(this, 2, 0, 2);
    for(i = 0; i < cClientInfoList::Size(&thisa->m_aClientInfo); ++i)
    {
        if(cClientInfoList::operator__(&thisa->m_aClientInfo, i)->priIntInfo.pInterface)
        {
            v1 = cClientInfoList::operator__(&thisa->m_aClientInfo, i);
            v1->priIntInfo.pInterface->baseclass_0.vfptr->Release((IUnknown *)v1->priIntInfo.pInterface);
        }
        cClientInfoList::operator__(&thisa->m_aClientInfo, i)->priIntInfo.pInterface = 0;
    }
    cLoopDispatch::cInitParmTable::_cInitParmTable(&thisa->m_Parms);
    cSimpleTimer::_cSimpleTimer(&thisa->m_TotalModeTime);
    cAverageTimer::_cAverageTimer(&thisa->m_AverageFrameTimer);
    cClientInfoList::_cClientInfoList(&thisa->m_aClientInfo);
    _vector_destructor_iterator_(
        thisa->m_DispatchLists,
        8u,
        32,
        (void(__thiscall *)(void *))cPriIntArray<ILoopClient>::_cPriIntArray<ILoopClient>);
}
// 9A6B80: using guessed type int (__stdcall *cLoopDispatch___vftable_)(int this, int id, int ppI);

//----- (008A02CE) --------------------------------------------------------
int __cdecl LoopProfileSend(ILoopClient *pClient, int message, tLoopMessageData__ *hData)
{
    return ((int(__stdcall *)(_DWORD, _DWORD, _DWORD))pClient->baseclass_0.vfptr[1].Release)(pClient, message, hData);
}

//----- (008A02E7) --------------------------------------------------------
void __stdcall cLoopDispatch::ClearTimers(cLoopDispatch *this)
{
    sClientInfo *v1; // eax@3
    int i; // [sp+0h] [bp-4h]@1

    cSimpleTimer::Clear(&this->m_TotalModeTime);
    cAverageTimer::Clear(&this->m_AverageFrameTimer);
    for(i = 0; i < cClientInfoList::Size(&this->m_aClientInfo); ++i)
    {
        v1 = cClientInfoList::operator__(&this->m_aClientInfo, i);
        cAverageTimer::Clear(&v1->timer);
    }
}

//----- (008A0350) --------------------------------------------------------
void __stdcall cLoopDispatch::DumpTimerInfo(cLoopDispatch *this)
{
    int v1; // eax@3
    sClientInfo *v2; // eax@4
    double v3; // ST64_8@6
    double v4; // ST3C_8@6
    double v5; // ST34_8@6
    double v6; // ST54_8@6
    double v7; // ST2C_8@6
    double v8; // ST1C_8@6
    double v9; // ST14_8@6
    int v10; // ST0C_4@6
    const char *v11; // eax@8
    int v12; // eax@10
    unsigned int v13; // eax@13
    cAverageTimer **v14; // eax@14
    cAverageTimer **v15; // eax@15
    cAverageTimer **v16; // eax@15
    cTimerBase **v17; // eax@15
    const char *v18; // eax@15
    const char *v19; // eax@18
    int v20; // eax@22
    sClientInfo *v21; // eax@23
    cAverageTimer *item; // [sp+58h] [bp-40h]@11
    long double clientAvg; // [sp+5Ch] [bp-3Ch]@14
    long double sumAvg; // [sp+64h] [bp-34h]@12
    cDynArray<cAverageTimer *> timers; // [sp+6Ch] [bp-2Ch]@9
    long double clientPctOfFrame; // [sp+74h] [bp-24h]@14
    long double frameAvg; // [sp+7Ch] [bp-1Ch]@12
    cAnsiStr msg; // [sp+84h] [bp-14h]@1
    int i; // [sp+90h] [bp-8h]@2
    int was_active; // [sp+94h] [bp-4h]@1

    cAnsiStr::cAnsiStr(&msg);
    was_active = cTimerBase::IsActive(&this->m_AverageFrameTimer.baseclass_0);
    if(was_active)
    {
        cAverageTimer::Stop(&this->m_AverageFrameTimer);
        for(i = 0;; ++i)
        {
            v1 = cClientInfoList::Size(&this->m_aClientInfo);
            if(i >= v1)
                break;
            v2 = cClientInfoList::operator__(&this->m_aClientInfo, i);
            cAverageTimer::Stop(&v2->timer);
        }
    }
    if(cAverageTimer::GetIters(&this->m_AverageFrameTimer) < 0xA)
    {
        cAnsiStr::FmtStr(
            &msg,
            "+----------------------------------------------------------------------------+\n[ Insufficient samples to calculate frame timings ]\n");
    }
    else
    {
        v3 = cSimpleTimer::GetResult(&this->m_TotalModeTime) - 2500.0;
        v4 = 1000.0 / (v3 / (double)cAverageTimer::GetIters(&this->m_AverageFrameTimer));
        v5 = 1000.0 / cAverageTimer::GetResult(&this->m_AverageFrameTimer);
        v6 = cSimpleTimer::GetResult(&this->m_TotalModeTime) - 2500.0;
        v7 = v6 - (double)cAverageTimer::GetTotalTime(&this->m_AverageFrameTimer);
        cAverageTimer::GetResult(&this->m_AverageFrameTimer);
        v8 = cSimpleTimer::GetResult(&this->m_TotalModeTime) - 2500.0;
        v9 = (double)cAverageTimer::GetTotalTime(&this->m_AverageFrameTimer);
        cAverageTimer::GetIters(&this->m_AverageFrameTimer);
        v10 = ((int(__stdcall *)(ILoopMode *))this->m_pLoopMode->baseclass_0.vfptr[1].QueryInterface)(this->m_pLoopMode)
            + 4;
        cAnsiStr::FmtStr(
            &msg,
            0x500u,
            "+----------------------------------------------------------------------------+\n|                       FRAME TIMINGS: %-16s                      |\n+----------------------------------------------------------------------------+\n\nFrames sampled:     %12d frames\n \nIn-loop time:       %12.0f ms    Total mode time:    %12.0f ms\nIn-loop frame avg:  %12.2f ms    Total out-of-loop:  %12.0f ms\nIn-loop framerate:  %12.2f fps   Mode framerate:     %12.2f fps\n \n");
    }
    v11 = cAnsiStr::operator char_const__(&msg);
    mprint(v11);
    if(cAverageTimer::GetIters(&this->m_AverageFrameTimer) >= 0xA)
    {
        mprintf(" Loop Client                Average Time     %% of Frame  Max Time  Min Time\n ----------------------------------------------------------------------------\n");
        cDynArray<cAverageTimer__>::cDynArray<cAverageTimer__>(&timers);
        for(i = 0;; ++i)
        {
            v12 = cClientInfoList::Size(&this->m_aClientInfo);
            if(i >= v12)
                break;
            item = &cClientInfoList::operator__(&this->m_aClientInfo, i)->timer;
            cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::Append(&timers.baseclass_0.baseclass_0, &item);
            cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::Sort(&timers.baseclass_0.baseclass_0, TimerSortFunc);
        }
        frameAvg = cAverageTimer::GetResult(&this->m_AverageFrameTimer);
        sumAvg = 0.0;
        for(i = 0;; ++i)
        {
            v13 = cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::Size(&timers.baseclass_0.baseclass_0);
            if(i >= v13)
                break;
            v14 = cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::operator__(&timers.baseclass_0.baseclass_0, i);
            clientAvg = cAverageTimer::GetResult(*v14);
            clientPctOfFrame = clientAvg / frameAvg * 100.0;
            if(clientAvg > 1.0)
            {
                sumAvg = sumAvg + clientAvg;
                v15 = cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::operator__(&timers.baseclass_0.baseclass_0, i);
                cAverageTimer::GetMinTime(*v15);
                v16 = cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::operator__(&timers.baseclass_0.baseclass_0, i);
                cAverageTimer::GetMaxTime(*v16);
                v17 = (cTimerBase **)cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::operator__(
                    &timers.baseclass_0.baseclass_0,
                    i);
                cTimerBase::GetName(*v17);
                cAnsiStr::FmtStr(&msg, " %-25s %#12.4f %#12.2f%% %#10lu %#10lu\n");
                v18 = cAnsiStr::operator char_const__(&msg);
                mprint(v18);
            }
        }
        clientAvg = frameAvg - sumAvg;
        if(clientAvg > 0.0)
        {
            cAnsiStr::FmtStr(&msg, " %-25s %#12.4f %#12.2f%%\n");
            v19 = cAnsiStr::operator char_const__(&msg);
            mprint(v19);
        }
        cDynArray<cAverageTimer__>::_cDynArray<cAverageTimer__>(&timers);
    }
    mprintf("+----------------------------------------------------------------------------+\n");
    if(was_active)
    {
        cAverageTimer::Start(&this->m_AverageFrameTimer);
        for(i = 0;; ++i)
        {
            v20 = cClientInfoList::Size(&this->m_aClientInfo);
            if(i >= v20)
                break;
            v21 = cClientInfoList::operator__(&this->m_aClientInfo, i);
            cAverageTimer::Start(&v21->timer);
        }
    }
    cAnsiStr::_cAnsiStr(&msg);
}

//----- (008A076F) --------------------------------------------------------
int __cdecl TimerSortFunc(cAverageTimer *const *pLeft, cAverageTimer *const *pRight)
{
    double v2; // ST00_8@1
    int v3; // eax@2
    double result; // [sp+8h] [bp-8h]@1

    v2 = cAverageTimer::GetResult(*pRight);
    result = v2 - cAverageTimer::GetResult(*pLeft);
    if(result <= 0.0)
    {
        if(result >= 0.0)
            v3 = 0;
        else
            v3 = -1;
    }
    else
    {
        v3 = 1;
    }
    return v3;
}

//----- (008A07C4) --------------------------------------------------------
int __stdcall cLoopDispatch::SendMessage(cLoopDispatch *this, int message, tLoopMessageData__ *hData, int flags)
{
    sPriIntInfo<ILoopClient> **v4; // eax@26
    sClientInfo *v5; // eax@51
    sClientInfo *v6; // eax@56
    int v7; // eax@60
    int v8; // [sp+0h] [bp-50h]@24
    int v9; // [sp+4h] [bp-4Ch]@15
    int v10; // [sp+8h] [bp-48h]@10
    int v11; // [sp+Ch] [bp-44h]@4
    const char *pszClient; // [sp+10h] [bp-40h]@26
    int clientResult; // [sp+14h] [bp-3Ch]@31
    unsigned int fFrameHeapchk; // [sp+1Ch] [bp-34h]@6
    unsigned int fLoopTime; // [sp+20h] [bp-30h]@6
    unsigned int fClientHeapchk; // [sp+24h] [bp-2Ch]@6
    int fPassedSkipTime; // [sp+28h] [bp-28h]@0
    unsigned int iLast; // [sp+2Ch] [bp-24h]@21
    int i; // [sp+30h] [bp-20h]@21
    int ia; // [sp+30h] [bp-20h]@49
    int ib; // [sp+30h] [bp-20h]@54
    cAverageTimer *pTimer; // [sp+38h] [bp-18h]@0
    ILoopClient *pClient; // [sp+3Ch] [bp-14h]@26
    int fLoopTimeThisMsg; // [sp+44h] [bp-Ch]@17
    int result; // [sp+48h] [bp-8h]@2
    cPriGuidSetBase *targetList; // [sp+4Ch] [bp-4h]@21

    if(this->m_msgs & message)
    {
        result = 0;
        v11 = this->m_fDiagnostics & 1 && message & this->m_diagnosticSet;
        fLoopTime = this->m_fDiagnostics & 2;
        fFrameHeapchk = this->m_fDiagnostics & 8;
        fClientHeapchk = this->m_fDiagnostics & 0x10;
        if(message & 0x4001)
            cSimpleTimer::Start(&this->m_TotalModeTime);
        if(cTimerBase::IsActive(&this->m_TotalModeTime.baseclass_0))
        {
            cSimpleTimer::Stop(&this->m_TotalModeTime);
            v10 = cSimpleTimer::GetResult(&this->m_TotalModeTime) > 2500.0;
            fPassedSkipTime = v10;
            cSimpleTimer::Start(&this->m_TotalModeTime);
            v9 = v10 && fLoopTime && message & 0x3C0;
            fLoopTimeThisMsg = v9;
        }
        else
        {
            fLoopTimeThisMsg = 0;
        }
        if(fLoopTimeThisMsg)
            cAverageTimer::Start(&this->m_AverageFrameTimer);
        targetList = (cPriGuidSetBase *)&this->m_DispatchLists[MessageToIndex(message)];
        iLast = cPriGuidSetBase::Size(targetList) - 1;
        for(i = 0; i <= (signed int)iLast; ++i)
        {
            if(flags & 1)
                v8 = i;
            else
                v8 = iLast - i;
            pClient = (*cPriGuidSet<sPriIntInfo<ILoopClient>>::operator__(
                (cPriGuidSet<sPriIntInfo<ILoopClient> > *)targetList,
                v8))->pInterface;
            v4 = cPriGuidSet<sPriIntInfo<ILoopClient>>::operator__((cPriGuidSet<sPriIntInfo<ILoopClient> > *)targetList, v8);
            pszClient = cAnsiStr::operator char_const__(&(*v4)->nameStr);
            if(v11)
                LoopTrack(message, pszClient);
            if(fLoopTimeThisMsg)
            {
                pTimer = (cAverageTimer *)((char *)(*cPriGuidSet<sPriIntInfo<ILoopClient>>::operator__(
                    (cPriGuidSet<sPriIntInfo<ILoopClient> > *)targetList,
                    v8))->pData
                    + 32);
                cAverageTimer::Start(pTimer);
            }
            if(this->m_ProfileSet & message)
                clientResult = LoopProfileSend(pClient, message, hData);
            else
                clientResult = ((int(__stdcall *)(ILoopClient *, int, tLoopMessageData__ *))pClient->baseclass_0.vfptr[1].Release)(
                pClient,
                message,
                hData);
            if(fLoopTimeThisMsg)
                cAverageTimer::Stop(pTimer);
            if(fClientHeapchk)
                j___heapchk();
            if(clientResult == 1)
            {
                result = -2147467259;
                break;
            }
        }
        if(fFrameHeapchk)
            j___heapchk();
        if(message & 0x2002)
            cSimpleTimer::Stop(&this->m_TotalModeTime);
        if(fLoopTime)
        {
            if(fLoopTimeThisMsg)
                cAverageTimer::Stop(&this->m_AverageFrameTimer);
            if(fPassedSkipTime && message & 0x200)
            {
                cAverageTimer::Mark(&this->m_AverageFrameTimer);
                for(ia = 0; ia < cClientInfoList::Size(&this->m_aClientInfo); ++ia)
                {
                    v5 = cClientInfoList::operator__(&this->m_aClientInfo, ia);
                    cAverageTimer::Mark(&v5->timer);
                }
            }
            if(message & 0x2002)
            {
                if(cTimerBase::IsActive(&this->m_AverageFrameTimer.baseclass_0))
                {
                    cAverageTimer::Stop(&this->m_AverageFrameTimer);
                    for(ib = 0; ib < cClientInfoList::Size(&this->m_aClientInfo); ++ib)
                    {
                        v6 = cClientInfoList::operator__(&this->m_aClientInfo, ib);
                        cAverageTimer::Stop(&v6->timer);
                    }
                }
                this->baseclass_0.baseclass_0.vfptr[4].Release((IUnknown *)this);
                this->baseclass_0.baseclass_0.vfptr[4].AddRef((IUnknown *)this);
            }
        }
        if(v11)
            LoopTrackClear();
        v7 = result;
    }
    else
    {
        if(message && !(this->m_msgs & message))
            DbgReportWarning("Message 0x%02X not supported by this dispatch chain\n");
        v7 = 1;
    }
    return v7;
}

//----- (008A0BBE) --------------------------------------------------------
int __cdecl MessageToIndex(unsigned int message)
{
    int i; // [sp+0h] [bp-8h]@1
    signed int currentMessage; // [sp+4h] [bp-4h]@1

    currentMessage = 1;
    i = 0;
    while(currentMessage && !(message & currentMessage))
    {
        ++i;
        currentMessage *= 2;
    }
    return i;
}

//----- (008A0C00) --------------------------------------------------------
void __cdecl LoopTrack(unsigned int message, const char *pszClient)
{
    int y; // [sp+0h] [bp-8h]@3
    int x; // [sp+4h] [bp-4h]@3

    if(!fSplitMono)
    {
        mono_split(1, 2);
        mono_setwin(2);
        fSplitMono = 1;
    }
    mono_getxy(&x, &y);
    mono_setwin(1);
    mono_setxy(0, 0);
    LoopGetMessageName(message);
    mprintf("%20s");
    mono_setxy(21, 0);
    mprintf("--> %-20s          ");
    mono_setwin(2);
    mono_setxy(x, y);
}

//----- (008A0CA7) --------------------------------------------------------
char __cdecl LoopTrackClear()
{
    mono_setwin(1);
    mono_clear();
    return mono_setwin(2);
}

//----- (008A0CC5) --------------------------------------------------------
int __stdcall cLoopDispatch::SendSimpleMessage(cLoopDispatch *this, int message)
{
    return ((int(__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[1].QueryInterface)(
        this,
        message,
        0,
        1);
}

//----- (008A0CE0) --------------------------------------------------------
int __stdcall cLoopDispatch::PostMessage(cLoopDispatch *this, int message, tLoopMessageData__ *hData, int flags)
{
    sLoopQueueMessage queueMessage; // [sp+0h] [bp-10h]@1

    queueMessage.message = message;
    queueMessage.hData = hData;
    queueMessage.flags = flags;
    cLoopQueue::Append(&this->m_Queue, &queueMessage);
    return 0;
}

//----- (008A0D0F) --------------------------------------------------------
int __stdcall cLoopDispatch::PostSimpleMessage(cLoopDispatch *this, int message)
{
    sLoopQueueMessage queueMessage; // [sp+0h] [bp-10h]@1

    queueMessage.message = message;
    queueMessage.hData = 0;
    queueMessage.flags = 0;
    cLoopQueue::Append(&this->m_Queue, &queueMessage);
    return 0;
}

//----- (008A0D40) --------------------------------------------------------
int __stdcall cLoopDispatch::ProcessQueue(cLoopDispatch *this)
{
    int retVal; // [sp+0h] [bp-14h]@1
    sLoopQueueMessage queueMessage; // [sp+4h] [bp-10h]@2

    retVal = 1;
    do
    {
        if(!cLoopQueue::GetMessage(&this->m_Queue, &queueMessage))
            break;
        retVal = ((int(__stdcall *)(cLoopDispatch *, int, tLoopMessageData__ *, int))this->baseclass_0.baseclass_0.vfptr[1].QueryInterface)(
            this,
            queueMessage.message,
            queueMessage.hData,
            queueMessage.flags);
    } while(!retVal);
    return retVal;
}

//----- (008A0D8E) --------------------------------------------------------
sLoopModeName *__stdcall cLoopDispatch::Describe(cLoopDispatch *this, sLoopModeInitParm **list)
{
    int v2; // ecx@0
    sLoopModeName *name; // [sp+0h] [bp-4h]@1

    name = (sLoopModeName *)((int(__stdcall *)(ILoopMode *, int))this->m_pLoopMode->baseclass_0.vfptr[1].QueryInterface)(
        this->m_pLoopMode,
        v2);
    if(list)
        *list = cLoopDispatch::cInitParmTable::List(&this->m_Parms);
    return name;
}

//----- (008A0DCF) --------------------------------------------------------
void __stdcall cLoopDispatch::SetDiagnostics(cLoopDispatch *this, unsigned int fDiagnostics, unsigned int messages)
{
    this->m_fDiagnostics = fDiagnostics;
    this->m_diagnosticSet = messages;
}

//----- (008A0DEE) --------------------------------------------------------
void __stdcall cLoopDispatch::GetDiagnostics(cLoopDispatch *this, unsigned int *pfDiagnostics, unsigned int *pMessages)
{
    *pfDiagnostics = this->m_fDiagnostics;
    *pMessages = this->m_diagnosticSet;
}

//----- (008A0E11) --------------------------------------------------------
void __stdcall cLoopDispatch::SetProfile(cLoopDispatch *this, unsigned int messages, _GUID *pClientId)
{
    this->m_ProfileSet = messages;
    this->m_pProfileClientId = pClientId;
}

//----- (008A0E30) --------------------------------------------------------
void __stdcall cLoopDispatch::GetProfile(cLoopDispatch *this, unsigned int *pMessages, _GUID **ppClientId)
{
    *pMessages = this->m_ProfileSet;
    *ppClientId = this->m_pProfileClientId;
}

//----- (008A0E53) --------------------------------------------------------
int __thiscall cLoopDispatch::DispatchNormalFrame(cLoopDispatch *this, ILoopClient *pClient, tLoopMessageData__ *hData)
{
    return ((int(__stdcall *)(_DWORD, _DWORD, _DWORD))pClient->baseclass_0.vfptr[1].Release)(pClient, 128, hData) != 1;
}

//----- (008A0E80) --------------------------------------------------------
unsigned int __thiscall cLoopDispatch::cRefCount::AddRef(cLoopDispatch::cRefCount *this)
{
    ++this->ul;
    return this->ul;
}

//----- (008A0EA0) --------------------------------------------------------
unsigned int __thiscall cLoopDispatch::cRefCount::Release(cLoopDispatch::cRefCount *this)
{
    --this->ul;
    return this->ul;
}

//----- (008A0EC0) --------------------------------------------------------
unsigned int __thiscall cLoopDispatch::cRefCount::operator unsigned_long(cLoopDispatch::cRefCount *this)
{
    return this->ul;
}

//----- (008A0ED0) --------------------------------------------------------
void __thiscall cLoopDispatch::OnFinalRelease(cLoopDispatch *this)
{
    if(this)
        ((void(__thiscall *)(_DWORD, _DWORD))this->baseclass_0.baseclass_0.vfptr[5].QueryInterface)(this, 1);
}

//----- (008A0F10) --------------------------------------------------------
void __thiscall cLoopQueue::cLoopQueue(cLoopQueue *this)
{
    this->m_nRemovePoint = 0;
    this->m_nInsertPoint = 0;
}

//----- (008A0F40) --------------------------------------------------------
void __thiscall cSimpleTimer::cSimpleTimer(cSimpleTimer *this)
{
    cSimpleTimer *v1; // ST00_4@1

    v1 = this;
    cTimerBase::cTimerBase(&this->baseclass_0);
    v1->m_TotalTime = 0;
}

//----- (008A0F60) --------------------------------------------------------
void __thiscall cTimerBase::cTimerBase(cTimerBase *this)
{
    this->m_flags = 0;
    this->m_szName[0] = 0;
}

//----- (008A0F80) --------------------------------------------------------
void __thiscall cAverageTimer::cAverageTimer(cAverageTimer *this)
{
    cAverageTimer *v1; // ST00_4@1

    v1 = this;
    cTimerBase::cTimerBase(&this->baseclass_0);
    v1->m_StartTime = 0;
    v1->m_TotalTime = 0;
    v1->m_Iterations = 0;
    v1->m_Depth = 0;
    v1->m_MinTime = -1;
    v1->m_MaxTime = 0;
}

//----- (008A0FE0) --------------------------------------------------------
void __thiscall cLoopDispatch::cRefCount::cRefCount(cLoopDispatch::cRefCount *this)
{
    this->ul = 1;
}

//----- (008A1000) --------------------------------------------------------
void __thiscall cLoopDispatch::cInitParmTable::cInitParmTable(cLoopDispatch::cInitParmTable *this, sLoopModeInitParm *list)
{
    this->m_list = cLoopDispatch::cInitParmTable::copy_parm(this, list);
}

//----- (008A1030) --------------------------------------------------------
sLoopModeInitParm *__thiscall cLoopDispatch::cInitParmTable::copy_parm(cLoopDispatch::cInitParmTable *this, sLoopModeInitParm *list)
{
    sLoopModeInitParm *result; // eax@2
    void *v3; // ST18_4@6
    int n; // [sp+8h] [bp-8h]@3

    if(list)
    {
        for(n = 0; list[n].pID; ++n)
            ;
        v3 = operator new(8 * n + 8);
        memcpy(v3, list, 8 * n + 8);
        result = (sLoopModeInitParm *)v3;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (008A10B0) --------------------------------------------------------
void *__thiscall cLoopDispatch::_scalar_deleting_destructor_(cLoopDispatch *this, unsigned int __flags)
{
    void *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    cLoopDispatch::_cLoopDispatch(this);
    if(__flags & 1)
        operator delete(thisa);
    return thisa;
}

//----- (008A10E0) --------------------------------------------------------
void __thiscall ILoopDispatch::ILoopDispatch(ILoopDispatch *this)
{
    ILoopDispatch *v1; // ST00_4@1

    v1 = this;
    IUnknown::IUnknown(&this->baseclass_0);
    v1->baseclass_0.vfptr = (IUnknownVtbl *)ILoopDispatch::_vftable_;
}
// 9A6BC0: using guessed type int (*ILoopDispatch___vftable_[15])();

//----- (008A1100) --------------------------------------------------------
void __thiscall cClientInfoList::cClientInfoList(cClientInfoList *this)
{
    cDynArray<sClientInfo__>::cDynArray<sClientInfo__>(&this->list);
}

//----- (008A1120) --------------------------------------------------------
void __thiscall ConstraintTable::ConstraintTable(ConstraintTable *this)
{
    _vector_constructor_iterator_(
        this,
        8u,
        32,
        (void(__thiscall *)(void *))cDynArray<sAbsoluteConstraint>::cDynArray<sAbsoluteConstraint>);
}

//----- (008A1140) --------------------------------------------------------
void __thiscall ConstraintTable::_ConstraintTable(ConstraintTable *this)
{
    _vector_destructor_iterator_(
        this,
        8u,
        32,
        (void(__thiscall *)(void *))cDynArray<sAbsoluteConstraint>::_cDynArray<sAbsoluteConstraint>);
}

//----- (008A1160) --------------------------------------------------------
cDynArray<sAbsoluteConstraint> *__thiscall ConstraintTable::operator__(ConstraintTable *this, int idx)
{
    return &this->table[idx];
}

//----- (008A1180) --------------------------------------------------------
void __thiscall cTimerBase::SetName(cTimerBase *this, const char *p)
{
    cTimerBase *v2; // ST0C_4@1

    v2 = this;
    strncpy(this->m_szName, p, 0x3Fu);
    v2->m_szName[63] = 0;
}

//----- (008A11B0) --------------------------------------------------------
int __thiscall cClientInfoList::Append(cClientInfoList *this, sClientInfo *info)
{
    sClientInfo *v2; // eax@2
    sClientInfo *v4; // [sp+0h] [bp-10h]@2
    cDABase<sClientInfo *, 4, cDARawSrvFns<sClientInfo *> > *thisa; // [sp+4h] [bp-Ch]@1
    void *v6; // [sp+8h] [bp-8h]@1
    sClientInfo *item; // [sp+Ch] [bp-4h]@4

    thisa = (cDABase<sClientInfo *, 4, cDARawSrvFns<sClientInfo *> > *)this;
    v6 = operator new(0x7Cu);
    if(v6)
    {
        sClientInfo::sClientInfo((sClientInfo *)v6, info);
        v4 = v2;
    }
    else
    {
        v4 = 0;
    }
    item = v4;
    return cDABase<sClientInfo___4_cDARawSrvFns<sClientInfo__>>::Append(thisa, &item);
}

//----- (008A1200) --------------------------------------------------------
sClientInfo *__thiscall cClientInfoList::operator__(cClientInfoList *this, int idx)
{
    return *cDABase<sClientInfo___4_cDARawSrvFns<sClientInfo__>>::operator__(&this->list.baseclass_0.baseclass_0, idx);
}

//----- (008A1220) --------------------------------------------------------
int __thiscall cClientInfoList::Size(cClientInfoList *this)
{
    return cDABase<sClientInfo___4_cDARawSrvFns<sClientInfo__>>::Size(&this->list.baseclass_0.baseclass_0);
}

//----- (008A1240) --------------------------------------------------------
void __thiscall sClientInfo::sClientInfo(sClientInfo *this, sClientInfo *__that)
{
    sClientInfo *v2; // ST0C_4@1

    v2 = this;
    sPriIntInfo<ILoopClient>::sPriIntInfo<ILoopClient>(&this->priIntInfo, &__that->priIntInfo);
    v2->interests = __that->interests;
    memcpy(&v2->timer, &__that->timer, sizeof(v2->timer));
}

//----- (008A1280) --------------------------------------------------------
void __thiscall sPriIntInfo<ILoopClient>::sPriIntInfo<ILoopClient>(sPriIntInfo<ILoopClient> *this, sPriIntInfo<ILoopClient> *__that)
{
    sPriIntInfo<ILoopClient> *v2; // ST04_4@1
    int v3; // edx@1

    v2 = this;
    v3 = __that->baseclass_0.priority;
    this->baseclass_0.pID = __that->baseclass_0.pID;
    this->baseclass_0.priority = v3;
    this->pInterface = __that->pInterface;
    cAnsiStr::cAnsiStr(&this->nameStr, &__that->nameStr);
    v2->pData = __that->pData;
}

//----- (008A12D0) --------------------------------------------------------
void __thiscall sClientInfo::_sClientInfo(sClientInfo *this)
{
    sPriIntInfo<ILoopClient> *v1; // ST00_4@1

    v1 = (sPriIntInfo<ILoopClient> *)this;
    cAverageTimer::_cAverageTimer(&this->timer);
    sPriIntInfo<ILoopClient>::_sPriIntInfo<ILoopClient>(v1);
}

//----- (008A12F0) --------------------------------------------------------
void __thiscall cAverageTimer::_cAverageTimer(cAverageTimer *this)
{
    cAverageTimer *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    if(cTimerBase::IsActive(&this->baseclass_0))
        cAverageTimer::Stop(thisa);
    cAverageTimer::OutputResult(thisa);
}

//----- (008A1320) --------------------------------------------------------
int __thiscall cTimerBase::IsActive(cTimerBase *this)
{
    return this->m_flags & 1;
}

//----- (008A1340) --------------------------------------------------------
void __thiscall cAverageTimer::OutputResult(cAverageTimer *this)
{
    cAverageTimer *thisa; // [sp+28h] [bp-4h]@1

    thisa = this;
    if(this->m_Iterations)
    {
        if(!cTimerBase::IsActive(&this->baseclass_0))
            AverageTimerOutputResult(
            thisa->baseclass_0.m_szName,
            (double)thisa->m_TotalTime / (double)thisa->m_Iterations,
            thisa->m_MaxTime,
            thisa->m_MinTime,
            thisa->m_TotalTime,
            thisa->m_Iterations);
    }
}

//----- (008A13C0) --------------------------------------------------------
void __thiscall cAverageTimer::Stop(cAverageTimer *this)
{
    cAverageTimer *thisa; // [sp+0h] [bp-8h]@1
    unsigned int delta; // [sp+4h] [bp-4h]@2

    thisa = this;
    --this->m_Depth;
    if(!this->m_Depth)
    {
        delta = timeGetTime() - this->m_StartTime;
        thisa->m_TotalTime += delta;
        if(delta > thisa->m_MaxTime)
            thisa->m_MaxTime = delta;
        if(delta < thisa->m_MinTime)
            thisa->m_MinTime = delta;
        thisa->baseclass_0.m_flags &= 0xFFFFFFFEu;
    }
}

//----- (008A1440) --------------------------------------------------------
void __thiscall sPriIntInfo<ILoopClient>::_sPriIntInfo<ILoopClient>(sPriIntInfo<ILoopClient> *this)
{
    cAnsiStr::_cAnsiStr(&this->nameStr);
}

//----- (008A1460) --------------------------------------------------------
sLoopModeInitParm *__thiscall cLoopDispatch::cInitParmTable::Search(cLoopDispatch::cInitParmTable *this, _GUID *pID)
{
    sLoopModeInitParm *result; // eax@2
    _GUID **p; // [sp+4h] [bp-4h]@1

    p = (_GUID **)this->m_list;
    if(this->m_list)
    {
        while(*p && operator__(*p, pID))
            p += 2;
        if(*p)
            result = (sLoopModeInitParm *)p;
        else
            result = 0;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (008A14C0) --------------------------------------------------------
void __thiscall sClientInfo::sClientInfo(sClientInfo *this)
{
    sClientInfo *v1; // ST00_4@1

    v1 = this;
    sPriIntInfo<ILoopClient>::sPriIntInfo<ILoopClient>(&this->priIntInfo);
    cAverageTimer::cAverageTimer(&v1->timer);
}

//----- (008A14F0) --------------------------------------------------------
void __thiscall cSimpleTimer::_cSimpleTimer(cSimpleTimer *this)
{
    cSimpleTimer *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    if(cTimerBase::IsActive(&this->baseclass_0))
    {
        cSimpleTimer::Stop(thisa);
        cSimpleTimer::OutputResult(thisa);
    }
}

//----- (008A1520) --------------------------------------------------------
void __thiscall cSimpleTimer::OutputResult(cSimpleTimer *this)
{
    cSimpleTimer *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    if(this->m_TotalTime && !cTimerBase::IsActive(&this->baseclass_0))
        SimpleTimerOutputResult(thisa->baseclass_0.m_szName, thisa->m_TotalTime);
    mprintf("Total time for %s: %lu ms\n");
}

//----- (008A1570) --------------------------------------------------------
void __thiscall cSimpleTimer::Stop(cSimpleTimer *this)
{
    cSimpleTimer *v1; // ST00_4@1
    int v2; // eax@1

    v1 = this;
    v1->m_TotalTime += timeGetTime() - v1->m_StartTime;
    v2 = v1->baseclass_0.m_flags;
    LOBYTE(v2) = v2 & 0xFE;
    v1->baseclass_0.m_flags = v2;
}

//----- (008A15B0) --------------------------------------------------------
void __thiscall cClientInfoList::_cClientInfoList(cClientInfoList *this)
{
    cDABase<sClientInfo *, 4, cDARawSrvFns<sClientInfo *> > *thisa; // [sp+4h] [bp-10h]@1
    sClientInfo *v2; // [sp+Ch] [bp-8h]@3
    int i; // [sp+10h] [bp-4h]@1

    thisa = (cDABase<sClientInfo *, 4, cDARawSrvFns<sClientInfo *> > *)this;
    for(i = 0; i < cClientInfoList::Size((cClientInfoList *)thisa); ++i)
    {
        v2 = *cDABase<sClientInfo___4_cDARawSrvFns<sClientInfo__>>::operator__(thisa, i);
        if(v2)
            sClientInfo::_scalar_deleting_destructor_(v2, 1u);
    }
    cDynArray<sClientInfo__>::_cDynArray<sClientInfo__>((cDynArray<sClientInfo *> *)thisa);
}

//----- (008A1620) --------------------------------------------------------
void __thiscall cDynArray<sClientInfo__>::_cDynArray<sClientInfo__>(cDynArray<sClientInfo *> *this)
{
    cDynArray_<sClientInfo___4>::_cDynArray_<sClientInfo___4>(&this->baseclass_0);
}

//----- (008A1640) --------------------------------------------------------
void *__thiscall sClientInfo::_scalar_deleting_destructor_(sClientInfo *this, unsigned int __flags)
{
    void *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    sClientInfo::_sClientInfo(this);
    if(__flags & 1)
        operator delete(thisa);
    return thisa;
}

//----- (008A1670) --------------------------------------------------------
void __thiscall cDynArray_<sClientInfo___4>::_cDynArray_<sClientInfo___4>(cDynArray_<sClientInfo *, 4> *this)
{
    cDABase<sClientInfo___4_cDARawSrvFns<sClientInfo__>>::_cDABase<sClientInfo___4_cDARawSrvFns<sClientInfo__>>(&this->baseclass_0);
}

//----- (008A1690) --------------------------------------------------------
void __thiscall cLoopDispatch::cInitParmTable::_cInitParmTable(cLoopDispatch::cInitParmTable *this)
{
    operator delete(this->m_list);
}

//----- (008A16C0) --------------------------------------------------------
void __thiscall cPriIntArray<ILoopClient>::_cPriIntArray<ILoopClient>(cPriIntArray<ILoopClient> *this)
{
    cPriGuidSet<sPriIntInfo<ILoopClient>>::_cPriGuidSet<sPriIntInfo<ILoopClient>>(&this->baseclass_0);
}

//----- (008A16E0) --------------------------------------------------------
void __thiscall cPriGuidSet<sPriIntInfo<ILoopClient>>::_cPriGuidSet<sPriIntInfo<ILoopClient>>(cPriGuidSet<sPriIntInfo<ILoopClient> > *this)
{
    cPriGuidSetBase::_cPriGuidSetBase(&this->baseclass_0);
}

//----- (008A1700) --------------------------------------------------------
void __thiscall cSimpleTimer::Clear(cSimpleTimer *this)
{
    this->baseclass_0.m_flags &= 0xFFFFFFFEu;
    this->m_TotalTime = 0;
}

//----- (008A1730) --------------------------------------------------------
void __thiscall cAverageTimer::Clear(cAverageTimer *this)
{
    this->baseclass_0.m_flags = 0;
    this->m_Iterations = 0;
    this->m_TotalTime = 0;
    this->m_MinTime = -1;
    this->m_MaxTime = 0;
}

//----- (008A1770) --------------------------------------------------------
const char *__thiscall cTimerBase::GetName(cTimerBase *this)
{
    return (const char *)this;
}

//----- (008A1780) --------------------------------------------------------
long double __thiscall cSimpleTimer::GetResult(cSimpleTimer *this)
{
    long double result; // st7@3
    cSimpleTimer *thisa; // [sp+8h] [bp-4h]@1

    thisa = this;
    if(!this->m_TotalTime || cTimerBase::IsActive(&this->baseclass_0))
        result = -1.0;
    else
        result = (double)thisa->m_TotalTime;
    return result;
}

//----- (008A17C0) --------------------------------------------------------
unsigned int __thiscall cAverageTimer::GetIters(cAverageTimer *this)
{
    return this->m_Iterations;
}

//----- (008A17E0) --------------------------------------------------------
unsigned int __thiscall cAverageTimer::GetTotalTime(cAverageTimer *this)
{
    return this->m_TotalTime;
}

//----- (008A1800) --------------------------------------------------------
unsigned int __thiscall cAverageTimer::GetMinTime(cAverageTimer *this)
{
    return this->m_MinTime;
}

//----- (008A1820) --------------------------------------------------------
unsigned int __thiscall cAverageTimer::GetMaxTime(cAverageTimer *this)
{
    return this->m_MaxTime;
}

//----- (008A1840) --------------------------------------------------------
long double __thiscall cAverageTimer::GetResult(cAverageTimer *this)
{
    long double result; // st7@3
    cAverageTimer *thisa; // [sp+10h] [bp-4h]@1

    thisa = this;
    if(!this->m_Iterations || cTimerBase::IsActive(&this->baseclass_0))
        result = -1.0;
    else
        result = (double)thisa->m_TotalTime / (double)thisa->m_Iterations;
    return result;
}

//----- (008A18A0) --------------------------------------------------------
void __thiscall cAverageTimer::Start(cAverageTimer *this)
{
    ++this->m_Depth;
    if(this->m_Depth == 1)
    {
        this->baseclass_0.m_flags |= 1u;
        this->m_StartTime = timeGetTime();
    }
}

//----- (008A18E0) --------------------------------------------------------
void __thiscall cDynArray<cAverageTimer__>::_cDynArray<cAverageTimer__>(cDynArray<cAverageTimer *> *this)
{
    cDynArray_<cAverageTimer___4>::_cDynArray_<cAverageTimer___4>(&this->baseclass_0);
}

//----- (008A1900) --------------------------------------------------------
void __thiscall cDynArray_<cAverageTimer___4>::_cDynArray_<cAverageTimer___4>(cDynArray_<cAverageTimer *, 4> *this)
{
    cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::_cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>(&this->baseclass_0);
}

//----- (008A1920) --------------------------------------------------------
void __thiscall cSimpleTimer::Start(cSimpleTimer *this)
{
    this->baseclass_0.m_flags |= 1u;
    this->m_StartTime = timeGetTime();
}

//----- (008A1950) --------------------------------------------------------
void __thiscall cAverageTimer::Mark(cAverageTimer *this)
{
    ++this->m_Iterations;
}

//----- (008A1970) --------------------------------------------------------
void __thiscall cLoopQueue::Append(cLoopQueue *this, sLoopQueueMessage *message)
{
    char *v2; // eax@2

    if(this->m_nInsertPoint >= 0x10)
    {
        cLoopQueue::PackAppend(this, message);
    }
    else
    {
        v2 = (char *)&this->m_Messages[this->m_nInsertPoint];
        *(_DWORD *)v2 = message->message;
        *((_DWORD *)v2 + 1) = message->hData;
        *((_DWORD *)v2 + 2) = message->flags;
        *((_DWORD *)v2 + 3) = message->alignmentPadTo16Bytes;
        ++this->m_nInsertPoint;
    }
}

//----- (008A19D0) --------------------------------------------------------
int __thiscall cLoopQueue::GetMessage(cLoopQueue *this, sLoopQueueMessage *pMessage)
{
    char *v2; // eax@2
    int result; // eax@2

    if(this->m_nRemovePoint == this->m_nInsertPoint)
    {
        result = 0;
    }
    else
    {
        v2 = (char *)&this->m_Messages[this->m_nRemovePoint];
        pMessage->message = *(_DWORD *)v2;
        pMessage->hData = (tLoopMessageData__ *)*((_DWORD *)v2 + 1);
        pMessage->flags = *((_DWORD *)v2 + 2);
        pMessage->alignmentPadTo16Bytes = *((_DWORD *)v2 + 3);
        ++this->m_nRemovePoint;
        result = 1;
    }
    return result;
}

//----- (008A1A30) --------------------------------------------------------
sLoopModeInitParm *__thiscall cLoopDispatch::cInitParmTable::List(cLoopDispatch::cInitParmTable *this)
{
    return this->m_list;
}

//----- (008A1A40) --------------------------------------------------------
void __thiscall sPriIntInfo<ILoopClient>::sPriIntInfo<ILoopClient>(sPriIntInfo<ILoopClient> *this)
{
    sPriIntInfo<ILoopClient> *v1; // ST00_4@1

    v1 = this;
    sPriGuidSetEntry::sPriGuidSetEntry(&this->baseclass_0);
    v1->pInterface = 0;
    cAnsiStr::cAnsiStr(&v1->nameStr);
    v1->pData = 0;
}

//----- (008A1A80) --------------------------------------------------------
void __thiscall sPriGuidSetEntry::sPriGuidSetEntry(sPriGuidSetEntry *this)
{
    this->pID = 0;
    this->priority = 16384;
}

//----- (008A1AB0) --------------------------------------------------------
void __thiscall cDynArray<sClientInfo__>::cDynArray<sClientInfo__>(cDynArray<sClientInfo *> *this)
{
    cDynArray_<sClientInfo___4>::cDynArray_<sClientInfo___4>(&this->baseclass_0);
}

//----- (008A1AD0) --------------------------------------------------------
int __thiscall cIPtr<ILoopManager>::operator__(cIPtr<ILoopManager> *this, ILoopManager *p)
{
    return cIPtrBase::operator__(&this->baseclass_0, p);
}

//----- (008A1AF0) --------------------------------------------------------
void __thiscall cDynArray<cAverageTimer__>::cDynArray<cAverageTimer__>(cDynArray<cAverageTimer *> *this)
{
    cDynArray_<cAverageTimer___4>::cDynArray_<cAverageTimer___4>(&this->baseclass_0);
}

//----- (008A1B10) --------------------------------------------------------
void __thiscall cDynArray_<sClientInfo___4>::cDynArray_<sClientInfo___4>(cDynArray_<sClientInfo *, 4> *this)
{
    cDABase<sClientInfo___4_cDARawSrvFns<sClientInfo__>>::cDABase<sClientInfo___4_cDARawSrvFns<sClientInfo__>>(&this->baseclass_0);
}

//----- (008A1B30) --------------------------------------------------------
void __thiscall cDynArray_<cAverageTimer___4>::cDynArray_<cAverageTimer___4>(cDynArray_<cAverageTimer *, 4> *this)
{
    cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>(&this->baseclass_0);
}

//----- (008A1B50) --------------------------------------------------------
void __thiscall cDABase<sClientInfo___4_cDARawSrvFns<sClientInfo__>>::cDABase<sClientInfo___4_cDARawSrvFns<sClientInfo__>>(cDABase<sClientInfo *, 4, cDARawSrvFns<sClientInfo *> > *this)
{
    this->m_pItems = 0;
    this->m_nItems = 0;
    cDABaseSrvFns::TrackCreate(4u);
}

//----- (008A1B80) --------------------------------------------------------
void __thiscall cDABase<sClientInfo___4_cDARawSrvFns<sClientInfo__>>::_cDABase<sClientInfo___4_cDARawSrvFns<sClientInfo__>>(cDABase<sClientInfo *, 4, cDARawSrvFns<sClientInfo *> > *this)
{
    cDABase<sClientInfo *, 4, cDARawSrvFns<sClientInfo *> > *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    cDABaseSrvFns::TrackDestroy();
    if(thisa->m_pItems)
    {
        cDARawSrvFns<sClientInfo__>::PreSetSize(thisa->m_pItems, thisa->m_nItems, 0);
        cDABaseSrvFns::DoResize((void **)&thisa->m_pItems, 4u, 0);
    }
}

//----- (008A1BC0) --------------------------------------------------------
sClientInfo **__thiscall cDABase<sClientInfo___4_cDARawSrvFns<sClientInfo__>>::operator__(cDABase<sClientInfo *, 4, cDARawSrvFns<sClientInfo *> > *this, int index)
{
    const char *v2; // eax@2
    cDABase<sClientInfo *, 4, cDARawSrvFns<sClientInfo *> > *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    if(index >= this->m_nItems)
    {
        v2 = _LogFmt("Index %d out of range");
        _CriticalMsg(v2, "x:\\prj\\tech\\h\\dynarray.h", 0x17Bu);
    }
    return &thisa->m_pItems[index];
}

//----- (008A1C10) --------------------------------------------------------
unsigned int __thiscall cDABase<sClientInfo___4_cDARawSrvFns<sClientInfo__>>::Append(cDABase<sClientInfo *, 4, cDARawSrvFns<sClientInfo *> > *this, sClientInfo *const *item)
{
    cDABase<sClientInfo *, 4, cDARawSrvFns<sClientInfo *> > *v2; // ST08_4@1
    unsigned int v3; // ST0C_4@1

    v2 = this;
    cDABase<sClientInfo___4_cDARawSrvFns<sClientInfo__>>::Resize(this, this->m_nItems + 1);
    v3 = v2->m_nItems++;
    cDARawSrvFns<sClientInfo__>::ConstructItem(&v2->m_pItems[v3], item);
    return cDABase<sClientInfo___4_cDARawSrvFns<sClientInfo__>>::Size(v2) - 1;
}

//----- (008A1C70) --------------------------------------------------------
unsigned int __thiscall cDABase<sClientInfo___4_cDARawSrvFns<sClientInfo__>>::Size(cDABase<sClientInfo *, 4, cDARawSrvFns<sClientInfo *> > *this)
{
    return this->m_nItems;
}

//----- (008A1C90) --------------------------------------------------------
sPriIntInfo<ILoopClient> **__thiscall cPriGuidSet<sPriIntInfo<ILoopClient>>::operator__(cPriGuidSet<sPriIntInfo<ILoopClient> > *this, int i)
{
    return (sPriIntInfo<ILoopClient> **)cDABase<sPriGuidSetEntry___4_cDARawSrvFns<sPriGuidSetEntry__>>::operator__(
        (cDABase<sPriGuidSetEntry *, 4, cDARawSrvFns<sPriGuidSetEntry *> > *)this,
        i);
}

//----- (008A1CB0) --------------------------------------------------------
unsigned int __thiscall cPriGuidSet<sPriIntInfo<ILoopClient>>::Append(cPriGuidSet<sPriIntInfo<ILoopClient> > *this, sPriIntInfo<ILoopClient> *pToAdd)
{
    return cPriGuidSetBase::Append(&this->baseclass_0, &pToAdd->baseclass_0);
}

//----- (008A1CD0) --------------------------------------------------------
void __thiscall cPriIntArray<ILoopClient>::cPriIntArray<ILoopClient>(cPriIntArray<ILoopClient> *this)
{
    cPriGuidSet<sPriIntInfo<ILoopClient>>::cPriGuidSet<sPriIntInfo<ILoopClient>>(&this->baseclass_0);
}

//----- (008A1CF0) --------------------------------------------------------
void __thiscall cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>(cDABase<cAverageTimer *, 4, cDARawSrvFns<cAverageTimer *> > *this)
{
    this->m_pItems = 0;
    this->m_nItems = 0;
    cDABaseSrvFns::TrackCreate(4u);
}

//----- (008A1D20) --------------------------------------------------------
void __thiscall cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::_cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>(cDABase<cAverageTimer *, 4, cDARawSrvFns<cAverageTimer *> > *this)
{
    cDABase<cAverageTimer *, 4, cDARawSrvFns<cAverageTimer *> > *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    cDABaseSrvFns::TrackDestroy();
    if(thisa->m_pItems)
    {
        cDARawSrvFns<cAverageTimer__>::PreSetSize(thisa->m_pItems, thisa->m_nItems, 0);
        cDABaseSrvFns::DoResize((void **)&thisa->m_pItems, 4u, 0);
    }
}

//----- (008A1D60) --------------------------------------------------------
cAverageTimer **__thiscall cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::operator__(cDABase<cAverageTimer *, 4, cDARawSrvFns<cAverageTimer *> > *this, int index)
{
    const char *v2; // eax@2
    cDABase<cAverageTimer *, 4, cDARawSrvFns<cAverageTimer *> > *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    if(index >= this->m_nItems)
    {
        v2 = _LogFmt("Index %d out of range");
        _CriticalMsg(v2, "x:\\prj\\tech\\h\\dynarray.h", 0x17Bu);
    }
    return &thisa->m_pItems[index];
}

//----- (008A1DB0) --------------------------------------------------------
unsigned int __thiscall cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::Append(cDABase<cAverageTimer *, 4, cDARawSrvFns<cAverageTimer *> > *this, cAverageTimer *const *item)
{
    cDABase<cAverageTimer *, 4, cDARawSrvFns<cAverageTimer *> > *v2; // ST08_4@1
    unsigned int v3; // ST0C_4@1

    v2 = this;
    cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::Resize(this, this->m_nItems + 1);
    v3 = v2->m_nItems++;
    cDARawSrvFns<cAverageTimer__>::ConstructItem(&v2->m_pItems[v3], item);
    return cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::Size(v2) - 1;
}

//----- (008A1E10) --------------------------------------------------------
unsigned int __thiscall cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::Size(cDABase<cAverageTimer *, 4, cDARawSrvFns<cAverageTimer *> > *this)
{
    return this->m_nItems;
}

//----- (008A1E30) --------------------------------------------------------
void __thiscall cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::Sort(cDABase<cAverageTimer *, 4, cDARawSrvFns<cAverageTimer *> > *this, int(__cdecl *pfnCompare)(cAverageTimer *const *, cAverageTimer *const *))
{
    if(this->m_pItems)
        qsort(this->m_pItems, this->m_nItems, 4u, (int(__cdecl *)(const void *, const void *))pfnCompare);
}

//----- (008A1E60) --------------------------------------------------------
void __thiscall cPriGuidSet<sPriIntInfo<ILoopClient>>::cPriGuidSet<sPriIntInfo<ILoopClient>>(cPriGuidSet<sPriIntInfo<ILoopClient> > *this)
{
    cPriGuidSetBase::cPriGuidSetBase(&this->baseclass_0);
}

//----- (008A1E80) --------------------------------------------------------
void __cdecl cDARawSrvFns<sClientInfo__>::PreSetSize(sClientInfo **__formal, unsigned int a2, unsigned int a3)
{
    ;
}

//----- (008A1E90) --------------------------------------------------------
void __cdecl cDARawSrvFns<sClientInfo__>::ConstructItem(sClientInfo **pItem, sClientInfo *const *pFrom)
{
    memcpy(pItem, pFrom, 4u);
}

//----- (008A1EB0) --------------------------------------------------------
void __cdecl cDARawSrvFns<cAverageTimer__>::PreSetSize(cAverageTimer **__formal, unsigned int a2, unsigned int a3)
{
    ;
}

//----- (008A1EC0) --------------------------------------------------------
void __cdecl cDARawSrvFns<cAverageTimer__>::ConstructItem(cAverageTimer **pItem, cAverageTimer *const *pFrom)
{
    memcpy(pItem, pFrom, 4u);
}

//----- (008A1EE0) --------------------------------------------------------
sPriGuidSetEntry **__thiscall cDABase<sPriGuidSetEntry___4_cDARawSrvFns<sPriGuidSetEntry__>>::operator__(cDABase<sPriGuidSetEntry *, 4, cDARawSrvFns<sPriGuidSetEntry *> > *this, int index)
{
    const char *v2; // eax@2
    cDABase<sPriGuidSetEntry *, 4, cDARawSrvFns<sPriGuidSetEntry *> > *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    if(index >= this->m_nItems)
    {
        v2 = _LogFmt("Index %d out of range");
        _CriticalMsg(v2, "x:\\prj\\tech\\h\\dynarray.h", 0x17Bu);
    }
    return &thisa->m_pItems[index];
}

//----- (008A1F30) --------------------------------------------------------
int __thiscall cDABase<sClientInfo___4_cDARawSrvFns<sClientInfo__>>::Resize(cDABase<sClientInfo *, 4, cDARawSrvFns<sClientInfo *> > *this, unsigned int newSlotCount)
{
    int result; // eax@2
    unsigned int evenSlots; // [sp+8h] [bp-4h]@1

    evenSlots = (newSlotCount + 3) & 0xFFFFFFFC;
    if(((this->m_nItems + 3) & 0xFFFFFFFC) == evenSlots)
        result = 1;
    else
        result = cDABaseSrvFns::DoResize((void **)&this->m_pItems, 4u, evenSlots);
    return result;
}

//----- (008A1F80) --------------------------------------------------------
int __thiscall cDABase<cAverageTimer___4_cDARawSrvFns<cAverageTimer__>>::Resize(cDABase<cAverageTimer *, 4, cDARawSrvFns<cAverageTimer *> > *this, unsigned int newSlotCount)
{
    int result; // eax@2
    unsigned int evenSlots; // [sp+8h] [bp-4h]@1

    evenSlots = (newSlotCount + 3) & 0xFFFFFFFC;
    if(((this->m_nItems + 3) & 0xFFFFFFFC) == evenSlots)
        result = 1;
    else
        result = cDABaseSrvFns::DoResize((void **)&this->m_pItems, 4u, evenSlots);
    return result;
}

//----- (008A1FD0) --------------------------------------------------------
void __thiscall cLoopQueue::PackAppend(cLoopQueue *this, sLoopQueueMessage *message)
{
    int v2; // ecx@2
    const char *v3; // eax@3
    cLoopQueue *thisa; // [sp+0h] [bp-4h]@1

    thisa = this;
    if(this->m_nRemovePoint)
    {
        memmove(
            this->m_Messages,
            &this->m_Messages[this->m_nRemovePoint],
            16 * (this->m_nInsertPoint - this->m_nRemovePoint));
        thisa->m_nInsertPoint -= thisa->m_nRemovePoint;
        thisa->m_nRemovePoint = 0;
        v2 = (int)&thisa->m_Messages[thisa->m_nInsertPoint];
        *(_DWORD *)v2 = message->message;
        *(_DWORD *)(v2 + 4) = message->hData;
        *(_DWORD *)(v2 + 8) = message->flags;
        *(_DWORD *)(v2 + 12) = message->alignmentPadTo16Bytes;
        ++thisa->m_nInsertPoint;
    }
    else
    {
        v3 = _LogFmt("Loop queue overflow (size is %d)");
        _CriticalMsg(v3, "x:\\prj\\tech\\libsrc\\darkloop\\loopque.cpp", 0x18u);
    }
}
