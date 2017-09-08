#include "stdafx.h"
#include "Excersice.h"
#include "../Src/LinkList.h"
#include "../Src/TwoWayLinkList.h"
#include "../Src/Stack.h"
#include <iostream>

using namespace std;


void Excersice_1()
{
	cout << "Excersice_1  begin------------" << endl;
	CLinkList<int> linklist;
	linklist.InitList();
	for (int i = 0;i<10 ;i++)
	{
		linklist.push_back(i);
	}
	linklist.PrintList();


	cout << linklist.GetSize() << endl;
	linklist.DeleteList();
	cout << linklist.GetSize() << endl;

	cout << "Excersice_1  end------------" << endl;
}

void Excersice_2()
{
	cout << endl <<"Excersice_2  begin------------" << endl;
	CLinkList<int> linklist1;
	linklist1.InitList();
	
	linklist1.push_back(1);
	linklist1.push_back(3);
	linklist1.push_back(4);
	linklist1.push_back(5);
	linklist1.push_back(6);
	

	CLinkList<int> linklist2;
	linklist2.InitList();
	for (int i = 10; i < 30; i++)
	{
		linklist2.push_back(i);
	}

	int nlistsize = linklist1.GetSize();
	for (int i = 0; i < nlistsize; i++)
	{
		int ndata = linklist1.GetNodeValue(i);
		linklist2.PrintList(ndata);
	}

	cout << "Excersice_2  end------------" << endl;
}

void Excersice_3()
{
	cout << endl << "Excersice_3  begin------------" << endl;
	CLinkList<int> linklist;
	linklist.InitList();
	for (int i = 0; i < 10; i++)
	{
		linklist.push_back(i);
	}
	linklist.PrintList();

	Node<int>* p1 = linklist.GetNode(3);
	Node<int>* p2 = linklist.GetNode(4);
	linklist.SwapNeighbour(p1, p2);
	linklist.PrintList();
	cout << endl;
	CTwoWayLinkList <int> twowaylinklist;
	twowaylinklist.InitList();
	for (int i = 0; i < 10; i++)
	{
		twowaylinklist.push_back(i);
	}
	twowaylinklist.PrintList();
	twowaylinklist.ReversePrintList();
	TwoWayNode<int>* twp1 = twowaylinklist.GetNode(3);
	TwoWayNode<int>* twp2 = twowaylinklist.GetNode(4);
	twowaylinklist.SwapNeighbour(twp1, twp2);
	twowaylinklist.PrintList();
	twowaylinklist.ReversePrintList();
	twp1 = twowaylinklist.GetNode(3);
	twp2 = twowaylinklist.GetNode(4);
	cout << twp1->data << endl;
	cout << twp1->pBefore->data << endl;
	cout << twp2->pBefore->data << endl;
	cout << "Excersice_3  end------------" << endl;
}

void LinkAndLink(CLinkList<int>* linklist1, CLinkList<int>* linklist2)
{
	Node<int>* pTmpNode = linklist1->First();
	if (pTmpNode == NULL)
	{
		return;
	}
	cout << "print link1 ¡É link2 :";
	while (pTmpNode != NULL)
	{
		int nData = pTmpNode->data;
		if (linklist2->GetNode(nData))
		{
			cout << nData << "  ";
		}
		pTmpNode = pTmpNode->pNext;
	}
	cout << endl;

}
void LinkOrLink(CLinkList<int>* linklist1, CLinkList<int>* linklist2)
{
	cout << "print link1 ¡È link2 : ";
	linklist2->PrintList();

	Node<int>* pTmpNode = linklist1->First();
	if (pTmpNode == NULL)
	{
		return;
	}
	while (pTmpNode != NULL)
	{
		int nData = pTmpNode->data;
		if (!linklist2->GetNode(nData))
		{
			cout<< "  " << nData ;
		}
		pTmpNode = pTmpNode->pNext;
	}
	cout << endl;
}

void Excersice_4()
{
	cout << "Excersice_4  begin------------" << endl;
	CLinkList<int> linklist1;
	linklist1.InitList();
	for (int i = 0; i < 10; i++)
	{
		linklist1.push_back(i);
	}

	CLinkList<int> linklist2;
	linklist2.InitList();
	for (int i = 5; i < 15; i++)
	{
		linklist2.push_back(i);
	}
	LinkAndLink(&linklist1,&linklist2);
	LinkOrLink(&linklist1, &linklist2);
	cout <<endl<< "Excersice_4  end------------" << endl;
}
void Excersice_18()
{
	CLinkStack<int> stack;
	stack.InitStack();
	stack.IsEmpty();
	for (int i = 0; i < 10; i++)
	{
		stack.Push(i);
	}
	for (int i = 0;i<10;i++)	 
	{
		cout << stack.Pop() << endl;
	}

}
