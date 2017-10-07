#ifndef __LOOPQUE_H
#define __LOOPQUE_H


struct sLoopQueueMessage
{
	int message;
	tLoopMessageData__ *hData;
	int flags;
	int alignmentPadTo16Bytes;
};


class cLoopQueue
{
public:
	cLoopQueue();
	~cLoopQueue();
	void Append(sLoopQueueMessage *message);
	int GetMessage(sLoopQueueMessage *pMessage);
	void PackAppend(sLoopQueueMessage *message);
    
    struct
    {
        unsigned int m_nRemovePoint;
        unsigned int m_nInsertPoint;
        sLoopQueueMessage m_Messages[16];
    };

private:

};



#endif	//__LOOPQUE_H

