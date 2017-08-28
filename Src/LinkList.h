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

template<class T>
class CLinkList
{
public:
	CLinkList()
	{}
	~CLinkList()
	{

	}

	void InitList();
	void MakeEmpty();
	BOOL IsEmpty();
	BOOL IsLast();
	Node<T>* Find(T value);
	Node<T>* FindPrevious(T value);
	void Delete(T value);
	void DeleteList();
	Node<T>* Header();
	Node<T>* First();
	Node<T>* Advance(Node<T>* p);

	Node<T>* InsertData(Node<T> *pNode,T value);
private:
	shared_ptr <Node<T>> m_pBegin;
	shared_ptr <Node<T>> m_pEnd;
};


// TODO: reference additional headers your program requires here
