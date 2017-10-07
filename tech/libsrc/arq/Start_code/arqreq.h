#ifndef ARQREQ_H
#define ARQREQ_H

class cARQRequest
{
public:
    cARQRequest(sARQRequest *reqInfo);
	~cARQRequest();
	unsigned int AddRef();
	unsigned int Release();
	void _cARQRequest();
	int IsFulfilled();
	int Fulfill();
	int Kill(int fDiscard);
	int GetResult(sARQResult *pResult);
	int IsFinished();
	//unsigned int cRefCount::AddRef(cARQRequest::cRefCount *this);
	//unsigned int cRefCount::Release(cARQRequest::cRefCount *this);
	//unsigned int cRefCount::operator unsigned_long(cARQRequest::cRefCount *this);
	void OnFinalRelease();
	//void cRefCount::cRefCount(cARQRequest::cRefCount *this);
	void *_scalar_deleting_destructor_(unsigned int __flags);
	int GetQueueID();
	//void SetOwningQueue(cARQRequestQueue *pOwningQueue);
	int QueryInterface(_GUID *id, void **ppI);
	int GetPriority();

    struct cRefCount
    {
        unsigned int ul;
    };

    struct
    {
        //IAsyncReadControl baseclass_0;
        //cDListNode<cARQRequest, 1> baseclass_4;
        cARQRequest::cRefCount __m_ulRefs;
        sARQRequest m_ReqInfo;
        sARQResult m_Result;
        cThreadLock m_Lock;
        //cARQRequest::eState m_State;
        cARQRequestQueue *m_pOwningQueue;
    };


private:

};





#endif

