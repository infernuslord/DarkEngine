//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include <aggmemb.h>

#include <dynarray.h>
#include <hashset.h>

#include <looptype.h>
#include <loopapi.h>

#include "loopque.h"


cLoopQueue::cLoopQueue()
{
	m_nRemovePoint = 0;
	m_nInsertPoint = 0;
}


void cLoopQueue::Append(sLoopQueueMessage *message)
{
	char *v2;

	if (m_nInsertPoint >= 0x10)
	{
		cLoopQueue::PackAppend(message);
	}
	else
	{
		v2 = (char *)&m_Messages[this->m_nInsertPoint];
		*v2 = message->message;
		*(v2 + 1) = (char)message->hData;
		*(v2 + 2) = message->flags;
		*(v2 + 3) = message->alignmentPadTo16Bytes;
		++this->m_nInsertPoint;
	}
}

int cLoopQueue::GetMessage(sLoopQueueMessage *pMessage)
{
	char *v2;
	int result;

	if (this->m_nRemovePoint == this->m_nInsertPoint)
	{
		result = 0;
	}
	else
	{
		v2 = (char *)&m_Messages[m_nRemovePoint];
		pMessage->message = *v2;
		pMessage->hData = (tLoopMessageData__ *)*(v2 + 1);
		pMessage->flags = *(v2 + 2);
		pMessage->alignmentPadTo16Bytes = *(v2 + 3);
		++this->m_nRemovePoint;
		result = 1;
	}
	return result;
}


void cLoopQueue::PackAppend(sLoopQueueMessage *message)
{
	int *v2;
	const char *v3;
	cLoopQueue *thisa;

	thisa = this;
	if (m_nRemovePoint)
	{
		memmove(m_Messages, &m_Messages[m_nRemovePoint], 16 * (m_nInsertPoint - m_nRemovePoint));
		thisa->m_nInsertPoint -= thisa->m_nRemovePoint;
		thisa->m_nRemovePoint = 0;
		*v2 = (int)&thisa->m_Messages[thisa->m_nInsertPoint];
		*v2 = message->message;
		*(v2 + 4) = (int)message->hData;
		*(v2 + 8) = message->flags;
		*(v2 + 12) = message->alignmentPadTo16Bytes;
		++thisa->m_nInsertPoint;
	}
	else
	{
		v3 = _LogFmt("Loop queue overflow (size is %d)");
		_CriticalMsg(v3, "x:\\prj\\tech\\libsrc\\darkloop\\loopque.cpp", 0x18u);
	}
}
