#ifndef ARQQUEUE_H
#define ARQQUEUE_H


class cARQRequestQueue
{
public:
	~cARQRequestQueue();
	cARQRequestQueue(unsigned int queueID);
	//int AddRequest(cARQRequest *pRequest, cARQRequestQueue::eAddFlags flags);
	//int RemoveRequest(cARQRequest *pRequest);
	//cARQRequest * GetRequest();
	unsigned int GetMax();
	void *GetAvailabilitySignalHandle();
	unsigned int GetCount();
	void WaitPut();
	void ReleasePut();




private:

};





#endif

