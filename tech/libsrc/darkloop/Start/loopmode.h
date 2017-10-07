#ifndef __LOOPMODE_H
#define __LOOPMODE_H

class cLoopMode
{
public:
	cLoopMode(sLoopModeDesc *pDescription);
	~cLoopMode();
	sLoopModeName* GetName();
	int __stdcall cLoopMode::CreatePartialDispatch(sLoopModeInitParm *list, unsigned int msgs, ILoopDispatch **result);

    struct cRefCount
    {
        unsigned int ul;
    };

    struct
    {
        //XXX
        //fix me
        //ILoopMode baseclass_0;
        cLoopMode::cRefCount __m_ulRefs;
        sLoopModeDesc m_desc;
    };

private:

};



#endif	//__LOOPMODE_H

