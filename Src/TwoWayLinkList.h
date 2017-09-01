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
class TwoWayNode
{
public:
	TwoWayNode()
	{
		pNext = NULL;
		pBefore = NULL;
	}
	T data;
	TwoWayNode *pNext;
	TwoWayNode *pBefore;
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
		m_pEnd = m_pBegin = new TwoWayNode<T>();
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
	TwoWayNode<T>* GetNode(T value)
	{
		TwoWayNode<T> *ptmpTwoWayNode = m_pBegin;
		while ((ptmpTwoWayNode != NULL) && (ptmpTwoWayNode->data != value))
		{
			ptmpTwoWayNode = ptmpTwoWayNode->pNext;
		}
		return ptmpTwoWayNode;
	}

	T GetNodeValue(int nIndex)
	{
		int n = 0;
		TwoWayNode<T> *ptmpTwoWayNode = m_pBegin->pNext;
		while (ptmpTwoWayNode != NULL)
		{
			if (n++ == nIndex)
			{
				return ptmpTwoWayNode->data;
			}
			ptmpTwoWayNode = ptmpTwoWayNode->pNext;
		}
		return m_pBegin->data;
	}

	TwoWayNode<T>* FindPrevious(T value)
	{
		/*TwoWayNode<T>* pTmp = m_pBegin;
		while ((pTmp->pNext != NULL) && (pTmp->pNext != pTwoWayNode))
		{
			pTmp = pTmp->pNext;
		}
		return pTwoWayNode->pBefore;*/
		return NULL;
	}
	TwoWayNode<T>* FindPrevious(TwoWayNode<T>* pTwoWayNode)
	{
		return pTwoWayNode->pBefore;
	}
	void Delete(T value)
	{}
	void DeleteList()
	{
		TwoWayNode<T> *pTwoWayNode = NULL;
		TwoWayNode<T> *pTmp = NULL;
		pTwoWayNode = m_pBegin->pNext;
		m_pBegin->pNext = NULL;
		while (pTwoWayNode != NULL)
		{
			pTmp = pTwoWayNode->pNext;
			delete pTwoWayNode;
			pTwoWayNode = pTmp;
		}
	}
	TwoWayNode<T>* Header()
	{
		return m_pBegin;
	}
	TwoWayNode<T>* First()
	{
		return m_pBegin->pNext;
	}
	TwoWayNode<T>* Advance(TwoWayNode<T>* p)
	{
		return NULL;
	}

	TwoWayNode<T>* InsertData(TwoWayNode<T> *pTwoWayNode, T value)
	{
		TwoWayNode<T> *pTmp = m_pBegin;
		while ((pTmp = pTmp->pNext) && pTmp == pTwoWayNode)
		{

		}
		return NULL;
	}
	BOOL push_back(T value)
	{
		TwoWayNode<T> *pTwoWayNode = new TwoWayNode<T>();
		if (NULL == pTwoWayNode)
		{
			return FALSE;
		}
		pTwoWayNode->data = value;
		pTwoWayNode->pNext = NULL;
		pTwoWayNode->pBefore = m_pEnd;


		m_pEnd->pNext = pTwoWayNode;
		m_pEnd = pTwoWayNode;

		m_nSize++;
		return TRUE;
	}
	void PrintList()
	{
		cout << "begin print twowaylist---------------" << endl;
		TwoWayNode<T> *pTmp = m_pBegin->pNext;
		while (pTmp != NULL)
		{
			cout <<" "<< pTmp->data;
			pTmp = pTmp->pNext;
		}
		cout <<endl<< "end print twowaylist---------------" << endl;
	}
	void PrintList(int nindex)
	{
		int n = 1;
		TwoWayNode<T> *pTmp = m_pBegin;
		while (pTmp != NULL && (pTmp = pTmp->pNext))
		{
			if (n++ == nindex)
			{
				cout << nindex <<" index value is : "<< pTmp->data << endl;
			}
		}
	}
	void ReversePrintList()
	{
		TwoWayNode<T> *pTmp = m_pEnd;
		cout << "begin print twowaylist---------------" << endl;
		while (pTmp != NULL)
		{
			cout << " " << pTmp->data;
			pTmp = pTmp->pBefore;
		}
		cout << endl << "end print twowaylist---------------" << endl;
	}
	int GetSize()
	{
		return m_nSize;
	}
	void SwapNeighbour(TwoWayNode<T>* pBefore,TwoWayNode<T>* pBack)
	{
		TwoWayNode<T>* pTmp = pBack->pNext;
		TwoWayNode<T>* pPrevious = FindPrevious(pBefore);

		pPrevious->pNext = pBack;
		pBack->pNext = pBefore;
		pBefore->pNext = pTmp;

		pBack->pBefore = pPrevious;
		pBefore->pBefore = pBack;
		pTmp->pBefore = pBefore;
	}

private:
	TwoWayNode<T> *m_pBegin;
	TwoWayNode<T> *m_pEnd;
	int m_nSize;
};


// TODO: reference additional headers your program requires here
