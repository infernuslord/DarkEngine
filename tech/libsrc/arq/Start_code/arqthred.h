#ifndef ARQTHRED_H
#define ARQTHRED_H



class cARQFulfillerThread
{
public:
	~cARQFulfillerThread();
	unsigned int ThreadProc();
	cARQFulfillerThread(cARQRequestQueue *requestQueue);
	void* _vector_deleting_destructor_(unsigned int __flags);
	void _cARQFulfillerThread();
	void SetPrioirities(int light, int normal);




private:

};





#endif

