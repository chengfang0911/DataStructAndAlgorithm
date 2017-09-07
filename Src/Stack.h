// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once    


#include <stdio.h>
#include <tchar.h>
#include <wtypes.h>
#include <memory>

using namespace std;

enum StackType{LIST,ARRAY};

template<class T>
class StackNode
{
public:
	StackNode()
	{
		pNext = NULL;
	}
	T data;
	StackNode *pNext;
};

template<class T>
class CStack
{
public:
	CStack()
	{
		m_pHead = NULL;
	}
	~CStack() {}

	void InitStack(StackType ntype)
	{
		if (LIST == ntype)
		{
			m_pHead = new StackNode<T>;
		}
	}

	BOOL IsEmpty()
	{
		return m_pHead->pNext == NULL;
	}

	void DisposStack(){}

	void MakeEmpty()
	{
		while (!IsEmpty())
		{
			Pop();
		}
	}

	void Push(T data)
	{
		StackNode<T> *tmpData = new StackNode<T>();
		tmpData->data = data;

		tmpData->pNext = m_pHead->pNext;
		m_pHead = tmpData;
	}

	T Top()
	{
		StackNode<T>* pfirst = m_pHead->pNext;
		if (pfirst != NULL)
		{
			return pfirst->data;
		}
	}

	T Pop()
	{
		StackNode<T>* pfirst = m_pHead->pNext;
		T tmpData;
		StackNode<T>* tNode;
		if (pfirst != NULL)
		{
			tmpData = pfirst->data;
			tNode = pfirst;
			m_pHead->pNext = pfirst->pNext;
			delete tNode;
		}
		return tmpData;
	}
private:
	StackNode<T> *m_pHead;
};


// TODO: reference additional headers your program requires here
