// $Header: x:/prj/tech/libsrc/sdesc/RCS/sdestool.h 1.5 1998/01/02 14:43:33 mahk Exp $

#ifndef __SDESTOOL_H
#define __SDESTOOL_H

//XXX Chaos
#include <lg.h>
#include <comtools.h>


#include <sdestype.h>

////////////////////////////////////////////////////////////
// Struct Desc Tools
//
// For use by editor DLLs
//
F_DECLARE_INTERFACE(IStructDescTools); 

#undef INTERFACE
#define INTERFACE IStructDescTools

DECLARE_INTERFACE_(IStructDescTools,IUnknown)
{
   DECLARE_UNKNOWN_PURE();

   //
   // Lookup a field by name
   //
   STDMETHOD_(const sFieldDesc*, GetFieldNamed)(THIS_ const sStructDesc* desc, const char* field) PURE; 

   //
   // Parse and unparse a field
   //
   STDMETHOD(ParseField)(THIS_ const sFieldDesc* fdesc, const char* string, void* struc) PURE;
   STDMETHOD(UnparseField)(THIS_ const sFieldDesc* fdesc, const void* struc, char* string, int buflen) PURE; 

   // 
   // Parse & Unparse a "simple" structure (e.g. a one-field structure)
   //
   STDMETHOD_(BOOL,IsSimple)(THIS_ const sStructDesc* desc) PURE;
   STDMETHOD_(BOOL,ParseSimple)(THIS_ const sStructDesc* desc, const char* string, void *struc) PURE;
   STDMETHOD_(BOOL,UnparseSimple)(THIS_ const sStructDesc* desc, const void* struc, char* buf, int len) PURE;
   

   //
   // Parse & unparse the "full" representation of a structure
   //

   STDMETHOD_(BOOL,ParseFull)(THIS_ const sStructDesc* sdesc, const char* string, void* struc) PURE; 
   STDMETHOD_(BOOL,UnparseFull)(THIS_ const sStructDesc* sdesc, const void* struc, char* out, int buflen) PURE; 

   //
   // Dump a struct to the mono 
   //
   STDMETHOD(Dump)(THIS_ const sStructDesc* sdesc, const void* struc) PURE; 

   //
   // Set and Get an integral field
   // 
   STDMETHOD(SetIntegral)(THIS_ const sFieldDesc* fdesc, long value, void* struc) PURE;
   STDMETHOD(GetIntegral)(THIS_ const sFieldDesc* fdesc, const void* struc, long* value) PURE;

   //
   // Lookup an sdesc in the registry.  NULL if none exists
   //
   STDMETHOD_(const sStructDesc*, Lookup)(THIS_ const char* name) PURE; 
   STDMETHOD(Register)(THIS_ const sStructDesc* desc) PURE; 
   STDMETHOD(ClearRegistry)(THIS) PURE; 


   
};






class cSdescTools
{
public:

    class cOuterPointer
    {
    public:
        struct
        {
            IUnknown *m_pOuterUnknown;
        };

        cOuterPointer();
        ~cOuterPointer();

        void Init(IUnknown *p);

        IUnknown *operator->();

    private:

    };

    struct IAggregateMemberControl
    {
        IUnknown *baseclass_0;
    };

    class cComplexAggregateControl
    {
    public:

        class cRefCount
        {
        public:
            struct
            {
                unsigned int ul;
            };

            cRefCount();
            ~cRefCount();

            unsigned int AddRef();
            unsigned int Release();
            operator unsigned long();

        private:

        };





        struct
        {
            IAggregateMemberControl baseclass_0;
            cSdescTools::cComplexAggregateControl::cRefCount __m_ulRefs;
            cSdescTools *m_pAggregateMember;
        };

        cComplexAggregateControl();
        ~cComplexAggregateControl();

        int Connect();
        int PostConnect();
        int Init();
        int End();
        int Disconnect();
        int QueryInterface(_GUID *id, void **ppI);
        unsigned int AddRef();
        unsigned int Release();
        void OnFinalRelease();
        void InitControl(cSdescTools *p);

    private:

    };




    struct
    {
        //IStructDescTools baseclass_0;
        cOuterPointer __m_pOuterUnknown;
        cComplexAggregateControl __m_AggregateControl;
        //cHashTable<char const *, sStructDesc const *, cHashFunctions> mRegistry;
    };


    /*
    struct cHashTable<char const *, sStructDesc const *, cHashFunctions>
    {
        cHashTable<char const *, sStructDesc const *, cHashFunctions>Vtbl *vfptr;
        $54FB11C877EFB07B528F62C41235A710 ___u1;
        int sizelog2;
        int fullness;
        int tombstones;
        char *statvec;
        cHashTable<char const *, sStructDesc const *, cHashFunctions>::Elem *vec;
    };

    struct cHashTable<char const *, sStructDesc const *, cHashFunctions>Vtbl
    {
        void *(__thiscall *__vecDelDtor)(cHashTable<char const *, sStructDesc const *, cHashFunctions> *this, unsigned int);
    };

    struct cHashTable<char const *, sStructDesc const *, cHashFunctions>::Elem
    {
        const char *key;
        sStructDesc *value;
    };

    struct IAsyncReadFulfiller
    {
        IUnknown baseclass_0;
    };
    */



    cSdescTools(IUnknown *pOuter);
    ~cSdescTools();

    int QueryInterface(_GUID *id, void **ppI);
    unsigned int AddRef();
    unsigned int Release();
    sFieldDesc *GetFieldNamed(sStructDesc *desc, const char *field);
    int ParseField(sFieldDesc *fdesc, const char *string, void *struc);
    int UnparseField(sFieldDesc *fdesc, const void *struc, char *string, int len);
    int SetIntegral(sFieldDesc *fdesc, int value, void *struc);
    int GetIntegral(sFieldDesc *fdesc, const void *struc, int *value);
    int IsSimple(sStructDesc *desc);
    int ParseSimple(sStructDesc *desc, const char *string, void *struc);
    int UnparseSimple(sStructDesc *desc, const void *struc, char *out, int len);
    int Dump(sStructDesc *sdesc, const void *struc);
    int ParseFull(sStructDesc *sdesc, const char *string, void *struc);
    int UnparseFull( sStructDesc *sdesc, const void *struc, char *out, int buflen);
    sStructDesc *Lookup(const char *name);
    int Register(sStructDesc *desc);
    int ClearRegistry();
    void SdescToolsCreate();
    int Connect();
    static int PostConnect();
    int Init();
    int End();
    int Disconnect();
    void OnFinalRelease();
    void *_scalar_deleting_destructor_(unsigned int __flags);


private:

};



EXTERN void SdescToolsCreate(void);

EXTERN int StructFieldToString(const void *struc, sStructDesc *desc, sFieldDesc *field, char *dest);

#endif // __SDESTOOL_H
