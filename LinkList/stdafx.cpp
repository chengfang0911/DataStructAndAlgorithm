// stdafx.cpp : source file that includes just the standard includes
// LinkList.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file




template<typename T>
void CLinkList<T>::InitList()
{
	m_pBegin = make_shared<Node<T>>();
	m_pEnd = make_shared<Node<T.>();
}

template<typename T>
BOOL CLinkList<T>::IsFree()
{
	if (NULL == m_pBegin->pNext)
	{
		return TRUE;
	}

	return FALSE;
}

template<typename T>
BOOL CLinkList<T>::IsLast()
{
	if (NULL == m_pEnd->pNext)
	{
		return TRUE;
	}
	return FALSE;
}

template<typename T>
Node<T>* CLinkList<T>::InsertData(Node<T> *pNode, T value)
{

	return NULL;
}

template<typename T>
Node<T>* CLinkList<T>::FindNode(T value)
{
	Node *ptmpNode = m_pBegin;
	while (ptmpNode != NULL && pNode->data == value)
	{
		ptmpNode = ptmpNode->pNext;
		return ptmpNode;
	}
	return NULL;
}
