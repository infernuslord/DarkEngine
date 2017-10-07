#ifndef ARQ_H
#define ARQ_H

class cARQManager
{
public:
	cARQManager();
	~cARQManager();
	int QueryInterface(_GUID *id, void **ppI);
	unsigned int AddRef();
	unsigned int Release();
	int Init();
	int End();
	int __stdcall QueueRequest(sARQRequest *pClientRequest, IAsyncReadControl **ppControl);
	int __stdcall QueueStreamRequest(sARQStreamRequest *pClientRequest, IAsyncReadControl **ppControl);
	int __stdcall GetAsyncStreamer(sARQStreamerDesc *__formal, IAsyncStreamer **a3);
	int __stdcall Suspend();
	int __stdcall Resume();
	int __stdcall IsStreamerBlocking();
	int __stdcall FulfillAll();
	int __stdcall FulfillToPriority(int priority);
	int __stdcall KillAll();
	void BalanceThreadPriority();
	int Connect();
	int PostConnect();
	int Disconnect();
	void OnFinalRelease();
	void *_scalar_deleting_destructor_(unsigned int __flags);

    /*
    int __stdcall cComplexAggregateControl::Connect(cARQManager::cComplexAggregateControl *this);
    int __stdcall cComplexAggregateControl::PostConnect(cARQManager::cComplexAggregateControl *this);
    int __stdcall cComplexAggregateControl::Init(cARQManager::cComplexAggregateControl *this);
    int __stdcall cComplexAggregateControl::End(cARQManager::cComplexAggregateControl *this);
    int __stdcall cComplexAggregateControl::Disconnect(cARQManager::cComplexAggregateControl *this);
    int __stdcall cComplexAggregateControl::QueryInterface(cARQManager::cComplexAggregateControl *this, _GUID *id, void **ppI);
    unsigned int __stdcall cComplexAggregateControl::AddRef(cARQManager::cComplexAggregateControl *this);
    unsigned int __stdcall cComplexAggregateControl::Release(cARQManager::cComplexAggregateControl *this);
    void __thiscall cOuterPointer::cOuterPointer(cARQManager::cOuterPointer *this);
    void __thiscall cOuterPointer::Init(cARQManager::cOuterPointer *this, IUnknown *p);
    void __thiscall cComplexAggregateControl::cComplexAggregateControl(cARQManager::cComplexAggregateControl *this);
    void __thiscall cComplexAggregateControl::cRefCount::cRefCount(cARQManager::cComplexAggregateControl::cRefCount *this);
    void __thiscall cComplexAggregateControl::InitControl(cARQManager::cComplexAggregateControl *this, cARQManager *p);
    unsigned int __thiscall cComplexAggregateControl::cRefCount::AddRef(cARQManager::cComplexAggregateControl::cRefCount *this);
    unsigned int __thiscall cComplexAggregateControl::cRefCount::Release(cARQManager::cComplexAggregateControl::cRefCount *this);
    unsigned int __thiscall cComplexAggregateControl::cRefCount::operator unsigned_long(cARQManager::cComplexAggregateControl::cRefCount *this);
    void __thiscall cComplexAggregateControl::OnFinalRelease(cARQManager::cComplexAggregateControl *this);
    IUnknown *__thiscall cOuterPointer::operator_ > (cARQManager::cOuterPointer *this);
    */




private:

};






#endif

