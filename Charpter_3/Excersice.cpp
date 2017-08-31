#include "stdafx.h"
#include "Excersice.h"
#include "../Src/LinkList.h"
#include "../Src/TwoWayLinkList.h"
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

	Node<int>* p1 = twowaylinklist.GetNode(3);
	Node<int>* p2 = twowaylinklist.GetNode(4);
	twowaylinklist.SwapNeighbour(p1, p2);
	twowaylinklist.PrintList();
	cout << "Excersice_3  end------------" << endl;
}