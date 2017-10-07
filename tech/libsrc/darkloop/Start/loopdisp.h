#ifndef __LOOPDISP_H
#define __LOOPDISP_H


struct ConstraintTable
{
    cDynArray<sAbsoluteConstraint> table[32];
};



class cLoopDispatch
{
public:
    cLoopDispatch(ILoopMode *loop, sLoopModeInitParm *parmList, unsigned int msgs);
    ~cLoopDispatch();

private:

};





#endif	//__LOOPDISP_H



