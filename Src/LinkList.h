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

template<class T>
class Node
{
public:
	Node()
	{
		pNext = NULL;
	}
	T data;
	Node *pNext;
};

template<class T>
class CLinkList
{
public:
	CLinkList()
	{
		m_pEnd = m_pBegin = NULL;
	}
	
	~CLinkList()
	{
		DeleteList();
	}
	

	void InitList()
	{
		m_pEnd = m_pBegin = new Node<T>();
	}
	void MakeEmpty(){}
	BOOL IsEmpty()
	{
		if (NULL == m_pBegin->pNext)
		{
			return TRUE;
		}

		return FALSE;
	}
	BOOL IsLast()
	{
		if (NULL == m_pEnd->pNext)
		{
			return TRUE;
		}
		return FALSE;
	}
	Node<T>* Find(T value)
	{
		Node *ptmpNode = m_pBegin;
		while (ptmpNode != NULL && pNode->data == value)
		{
			ptmpNode = ptmpNode->pNext;
			return ptmpNode;
		}
		return NULL;
	}
	Node<T>* FindPrevious(T value)
	{
		return NULL;
	}
	void Delete(T value)
	{}
	void DeleteList()
	{
		Node<T> *pNode = NULL;
		while ((pNode = m_pBegin) && (pNode != NULL))
		{
			m_pBegin = m_pBegin->pNext;
			delete pNode;
		}
	}
	Node<T>* Header()
	{
		return NULL;
	}
	Node<T>* First()
	{
		return NULL;
	}
	Node<T>* Advance(Node<T>* p)
	{
		return NULL;
	}

	Node<T>* InsertData(Node<T> *pNode, T value)
	{
		return NULL;
	}
	BOOL push_back(T value)
	{
		Node<T> *pNode = new Node<T>();
		if (NULL == pNode)
		{
			return FALSE;
		}
		pNode->data = value;
		pNode->pNext = NULL;

		m_pEnd->pNext = pNode;
		m_pEnd = pNode;
		return TRUE;
	}
	void PrintList()
	{
		cout << "begin print list---------------" << endl;
		Node<T> *pTmp = m_pBegin;
		while (pTmp != NULL && (pTmp = pTmp->pNext))
		{
			cout << pTmp->data << endl;
		}
		cout << "end print list---------------" << endl;
	}
	int GetSize()
	{
		int nSize = 0;
		Node<T> *pTmp = m_pBegin;
		while (pTmp != NULL && (pTmp = pTmp->pNext))
		{
			nSize++;
		}
		return nSize;
	}
private:
	Node<T> *m_pBegin;
	Node<T> *m_pEnd;
};


// TODO: reference additional headers your program requires here
