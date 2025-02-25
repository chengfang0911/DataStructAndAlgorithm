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
constexpr int STACKSIZE = 48;

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

	virtual ~CStack() {}

	virtual void InitStack() = 0;

	virtual BOOL IsEmpty() = 0;

	virtual void DisposStack() = 0;

	virtual void MakeEmpty() = 0;

	virtual void Push(T data) = 0;

	virtual T Top() = 0;

	virtual T Pop() = 0;

};


template<class T>
class CLinkStack : public CStack<T>
{
public:
	CLinkStack()
	{
		m_pHead = NULL;
	}
	virtual ~CLinkStack() {}

	
	virtual void InitStack()
	{	
		m_pHead = new StackNode<T>;
	}

	virtual BOOL IsEmpty()
	{
		return m_pHead->pNext == NULL;
	}

	virtual void DisposStack() {}

	virtual void MakeEmpty()
	{
		while (!IsEmpty())
		{
			Pop();
		}
	}

	virtual void Push(T data)
	{
		StackNode<T> *tmpData = new StackNode<T>();
		tmpData->data = data;

		tmpData->pNext = m_pHead->pNext;
		m_pHead->pNext = tmpData;
	}

	virtual T Top()
	{
		StackNode<T>* pfirst = m_pHead->pNext;
		if (pfirst != NULL)
		{
			return pfirst->data;
		}
	}

	virtual T Pop()
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


template<class T>
class CArrayStack : public CStack<T>
{
public:
	CArrayStack()
	{
		m_pData = NULL;
		m_nIndex = 0;
	}
	~CArrayStack() {}


	virtual void InitStack()
	{
		m_pData = new T[STACKSIZE];
		memset(m_pData, -1, sizeof(T) * STACKSIZE);
		m_nIndex = 0;
	}

	virtual BOOL IsEmpty()
	{
		return m_nIndex == 0;
	}

	virtual void DisposStack() {}

	virtual void MakeEmpty()
	{
		if (m_pData)
		{
			delete[]m_pData;
			m_nIndex = 0;
		}
	}

	virtual void Push(T data)
	{
		m_pData[m_nIndex++] = data;
	}

	virtual T Top()
	{
		if (!IsEmpty())
		{
			return m_pData[m_nIndex - 1];
		}
	}

	virtual T Pop()
	{
		if (!IsEmpty())
		{
			return m_pData[--m_nIndex];
		}
	}
private:
	T* m_pData;
	StackType m_type;
	int m_nIndex;
};


// TODO: reference additional headers your program requires here
