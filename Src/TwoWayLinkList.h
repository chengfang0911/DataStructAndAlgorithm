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
		pBefore = NULL;
	}
	T data;
	Node *pNext;
	Node *pBefore;
};

template<class T>
class CTwoWayLinkList
{
public:
	CTwoWayLinkList()
	{
		m_pEnd = m_pBegin = NULL;
		m_nSize = 0;
	}
	
	~CTwoWayLinkList()
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
	Node<T>* GetNode(T value)
	{
		Node<T> *ptmpNode = m_pBegin;
		while ((ptmpNode != NULL) && (ptmpNode->data != value))
		{
			ptmpNode = ptmpNode->pNext;
		}
		return ptmpNode;
	}

	T GetNodeValue(int nIndex)
	{
		int n = 0;
		Node<T> *ptmpNode = m_pBegin->pNext;
		while (ptmpNode != NULL)
		{
			if (n++ == nIndex)
			{
				return ptmpNode->data;
			}
			ptmpNode = ptmpNode->pNext;
		}
		return m_pBegin->data;
	}

	Node<T>* FindPrevious(T value)
	{
		return NULL;
	}
	Node<T>* FindPrevious(Node<T>* pNode)
	{
		Node<T>* pTmp = m_pBegin;
		while ((pTmp->pNext != NULL) && (pTmp->pNext != pNode))
		{
			pTmp = pTmp->pNext;
		}
		return pTmp;
	}
	void Delete(T value)
	{}
	void DeleteList()
	{
		Node<T> *pNode = NULL;
		Node<T> *pTmp = NULL;
		pNode = m_pBegin->pNext;
		m_pBegin->pNext = NULL;
		while (pNode != NULL)
		{
			pTmp = pNode->pNext;
			delete pNode;
			pNode = pTmp;
		}
	}
	Node<T>* Header()
	{
		return m_pBegin;
	}
	Node<T>* First()
	{
		return m_pBegin->pNext;
	}
	Node<T>* Advance(Node<T>* p)
	{
		return NULL;
	}

	Node<T>* InsertData(Node<T> *pNode, T value)
	{
		Node<T> *pTmp = m_pBegin;
		while ((pTmp = pTmp->pNext) && pTmp == pNode)
		{

		}
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

		m_nSize++;
		return TRUE;
	}
	void PrintList()
	{
		cout << "begin print list---------------" << endl;
		Node<T> *pTmp = m_pBegin->pNext;
		while (pTmp != NULL)
		{
			cout <<" "<< pTmp->data;
			pTmp = pTmp->pNext;
		}
		cout <<endl<< "end print list---------------" << endl;
	}
	void PrintList(int nindex)
	{
		int n = 1;
		Node<T> *pTmp = m_pBegin;
		while (pTmp != NULL && (pTmp = pTmp->pNext))
		{
			if (n++ == nindex)
			{
				cout << nindex <<" index value is : "<< pTmp->data << endl;
			}
		}
	}
	int GetSize()
	{
		return m_nSize;
	}
	void SwapNeighbour(Node<T>* pBefore,Node<T>* pBack)
	{
		Node<T>* pTmp = pBack->pNext;
		Node<T>* pPrevious = FindPrevious(pBefore);
		//pBefore->pNext = pBack->pNext;
		//pBack->pNext = pBefore;
		//pPrevious->pNext = pBack;

		pPrevious->pNext = pBack;
		pBack->pNext = pBefore;
		pBefore->pNext = pTmp;
	}

private:
	Node<T> *m_pBegin;
	Node<T> *m_pEnd;
	int m_nSize;
};


// TODO: reference additional headers your program requires here
