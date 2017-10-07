//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include "sdestool.h"
#include "sdesbase.h"


cSdescTools::cSdescTools(IUnknown *pOuter)
{
}

cSdescTools::~cSdescTools()
{
}


int cSdescTools::QueryInterface(_GUID *id, void **ppI)
{


}

unsigned int cSdescTools::AddRef()
{

}

unsigned int cSdescTools::Release()
{

}

sFieldDesc *cSdescTools::GetFieldNamed(sStructDesc *desc, const char *field)
{

}

int cSdescTools::ParseField(sFieldDesc *fdesc, const char *string, void *struc)
{

}

int cSdescTools::UnparseField(sFieldDesc *fdesc, const void *struc, char *string, int len)
{
    int retval;
    void *buf;
    int size;

    size = 1024;
    if(fdesc->size > 0x400)
        size = fdesc->size;
    if(size < len)
        size = len;
    buf = j__new(size, "x:\\prj\\tech\\libsrc\\sdesc\\sdestool.cpp", 55);
    retval = 1;

    if(StructFieldToString(struc, (sStructDesc *)1, fdesc, (char *)buf))
    {
        strncpy(string, (const char *)buf, len);
        string[len - 1] = 0;
        retval = 0;
    }
    operator delete(buf);
    return retval;
}



int cSdescTools::SetIntegral(sFieldDesc *fdesc, int value, void *struc)
{

}

int cSdescTools::GetIntegral(sFieldDesc *fdesc, const void *struc, int *value)
{

}

int cSdescTools::IsSimple(sStructDesc *desc)
{

}

int cSdescTools::ParseSimple(sStructDesc *desc, const char *string, void *struc)
{

}

int cSdescTools::UnparseSimple(sStructDesc *desc, const void *struc, char *out, int len)
{

}

int cSdescTools::Dump(sStructDesc *sdesc, const void *struc)
{

}

int cSdescTools::ParseFull(sStructDesc *sdesc, const char *string, void *struc)
{

}

int cSdescTools::UnparseFull(sStructDesc *sdesc, const void *struc, char *out, int buflen)
{

}

sStructDesc *cSdescTools::Lookup(const char *name)
{

}

int cSdescTools::Register(sStructDesc *desc)
{
    sStructDesc *v3;
    char *key;

    key = (char *)desc;
    //if(cHashTable<char_const___sStructDesc_const___cHashFunctions>::HasKey(&this->mRegistry, (const char *const *)&key) && config_spew_on && CfgSpewTest("sdesctab"))
   // {
    //    CfgDoSpew("A struct desc has already been registered for %s\n");
   // }
    v3 = desc;
   // cHashTable<char_const___sStructDesc_const___cHashFunctions>::Set(&this->mRegistry, (const char *const *)&v3, &desc);
    return 0;
}


int cSdescTools::ClearRegistry()
{

}

void SdescToolsCreate()
{

}

int cSdescTools::Connect()
{

}

int cSdescTools::PostConnect()
{
    return 0;
}

int cSdescTools::Init()
{

}

int cSdescTools::End()
{

}

int cSdescTools::Disconnect()
{

}




void cSdescTools::OnFinalRelease()
{

}

void *cSdescTools::_scalar_deleting_destructor_(unsigned int __flags)
{

}



cSdescTools::cOuterPointer::cOuterPointer()
{

}

cSdescTools::cOuterPointer::~cOuterPointer()
{

}

void cSdescTools::cOuterPointer::Init(IUnknown *p)
{

}

IUnknown *cSdescTools::cOuterPointer::operator->()
{
    return this->m_pOuterUnknown;
}

cSdescTools::cComplexAggregateControl::cComplexAggregateControl()
{

}

cSdescTools::cComplexAggregateControl::~cComplexAggregateControl()
{

}


int cSdescTools::cComplexAggregateControl::Connect()
{

}

int cSdescTools::cComplexAggregateControl::PostConnect()
{
    int result;

    if(this->m_pAggregateMember)
        result = cSdescTools::PostConnect();
    else
        result = 0;
    return result;
}

int cSdescTools::cComplexAggregateControl::Init()
{

}

int cSdescTools::cComplexAggregateControl::End()
{

}

int cSdescTools::cComplexAggregateControl::Disconnect()
{

}

int cSdescTools::cComplexAggregateControl::QueryInterface(_GUID *id, void **ppI)
{

}


unsigned int cSdescTools::cComplexAggregateControl::AddRef()
{

}

unsigned int cSdescTools::cComplexAggregateControl::Release()
{

}

void cSdescTools::cComplexAggregateControl::OnFinalRelease()
{

}

void cSdescTools::cComplexAggregateControl::InitControl(cSdescTools *p)
{

}



