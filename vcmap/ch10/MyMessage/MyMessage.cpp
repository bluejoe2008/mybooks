// MessageMock.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "conio.h"
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define MSG_KEY		0x1224
#define MSG_CHAR	0x1225
#define MSG_QUIT	0x0001
#define MSG_CLOSE	0x0002

//定义消息
struct _MSG
{
	int Message;
	int Parameter;
};

//消息队列
CList<_MSG> _MsgQueue;

//消息处理函数
typedef void (*MessageProc)(int Message, int Parameter);
MessageProc _MessageHandler;

//发送消息
void _PostMessage(int Message, int Parameter)
{
	_MSG NewMsg;
	NewMsg.Message = Message;
	NewMsg.Parameter = Parameter;

	_MsgQueue.AddTail(NewMsg);
}

//读取消息队列中的新消息
bool _GetMessage(_MSG * pMsg)
{
	while(_MsgQueue.IsEmpty());

	_MSG LastMsg = _MsgQueue.RemoveHead();
	*pMsg = LastMsg;

	if(pMsg->Message == MSG_QUIT)
		return false;		

	return true;
}

//转换消息
void _TranslateMessage(_MSG * pMsg)
{
	//x键为系统键
	if(pMsg->Message == MSG_KEY && pMsg->Parameter == 'x')
	{
		pMsg->Message = MSG_CLOSE;
		return;
	}

	//将键盘消息转换成字符消息
	if(pMsg->Message == MSG_KEY)
	{
		pMsg->Message = MSG_CHAR;
	}
}

//分发消息
void _DispatchMessage(_MSG * pMsg)
{
	(*_MessageHandler)(pMsg->Message, pMsg->Parameter);
}

//消息大循环，负责读取消息-->分发消息
void MessageLoop(MessageProc handler)
{
	_MessageHandler = handler;

	_MSG msg;
	while(_GetMessage(&msg))
	{
		_TranslateMessage(&msg);
		_DispatchMessage(&msg);
	}
}

//对MSG_CHAR的响应
void OnChar(int charInput)
{
	if(charInput == 'q')
		_PostMessage(MSG_QUIT, 0);

	cout << "you typed " << (char)charInput << endl;
}

//对MSG_CLOSE的响应
void OnClose(int charInput)
{
	_PostMessage(MSG_QUIT, 0);
}

void MyMessageProc(int Message, int Parameter)
{
	switch(Message)
	{
		case MSG_CHAR:
			OnChar(Parameter);
			break;

		case MSG_CLOSE:
			OnClose(Parameter);
			break;
	}
}

//消息发生器
UINT GatherMessages(LPVOID pParam)
{
	while(*((bool *)pParam))
	{
		if(_kbhit())
		{
			int ch = _getch();
			_PostMessage(MSG_KEY, ch);
		}
	}

	return 0;
}

int main(void)
{
	bool flag = true;

	//打开消息发生器
	AfxBeginThread(GatherMessages, &flag);
	//开始消息处理循环
	MessageLoop(MyMessageProc);

	flag = false;

	AfxEndThread(0);
	return 0;
}