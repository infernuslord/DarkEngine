#ifndef ARQSTRRD_H
#define ARQSTRRD_H

class cAsyncStreamReader
{
public:
    cAsyncStreamReader(sARQStreamRequest *streamRequest);
	~cAsyncStreamReader();
	int QueryInterface(_GUID *id, void **ppI);
	unsigned int AddRef();
	unsigned int Release();
	int DoFulfill(sARQRequest *__formal, sARQResult *pResult);
	int DoKill(sARQRequest *__formal, int a3);
	//unsigned int cRefCount::AddRef(cAsyncStreamReader::cRefCount *this);
	//unsigned int cRefCount::Release(cAsyncStreamReader::cRefCount *this);
	//unsigned int cRefCount::operator unsigned_long(cAsyncStreamReader::cRefCount *this);
	void OnFinalRelease();
	//void cRefCount::cRefCount(cAsyncStreamReader::cRefCount *this);
	void *_scalar_deleting_destructor_(unsigned int __flags);

    struct cRefCount
    {
        unsigned int ul;
    };

    struct
    {
        //IAsyncReadFulfiller baseclass_0;
        cAsyncStreamReader::cRefCount __m_ulRefs;
        sARQStreamRequest m_StreamRequest;
    };



private:

};




#endif

