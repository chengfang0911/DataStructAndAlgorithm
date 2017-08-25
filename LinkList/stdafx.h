// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <wtypes.h>
#include <memory>

using namespace std;

template<typename T>
class Node
{
public:
	Node()
	{
		pNext = NULL;
	}
	~Node()
	{
		if (pNext != NULL)
		{
			delete pNext;
		}
		
	}
	T data;
	Node *pNext;
};

template<typename T>
class CLinkList
{
public:
	CLinkList()
	{}
	~CLinkList()
	{

	}

	void InitList();
	BOOL IsFree();
	BOOL IsLast();
	Node<T>* FindNode(T value);
	Node<T>* InsertData(Node<T> *pNode,T value);
private:
	shared_ptr <Node<T>> m_pBegin;
	shared_ptr <Node<T>> m_pEnd;
};


// TODO: reference additional headers your program requires here
