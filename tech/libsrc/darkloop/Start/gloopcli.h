#ifndef __GLOOPCLI_H
#define __GLOOPCLI_H


class cGenericLoopClient
{
public:
    cGenericLoopClient(int(__stdcall *pCallback)(void *, int, tLoopMessageData__ *), void *pContext, sLoopClientDesc *pClientDesc);
    ~cGenericLoopClient();

private:

};









#endif	//__GLOOPCLI_H