#include "stdafx.h"
#include "Excersice.h"
#include "../Src/LinkList.h"
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
	cout << "Excersice_1  end------------" << endl;

	cout << linklist.GetSize() << endl;
	linklist.DeleteList();
	cout << linklist.GetSize() << endl;
}

void Excersice_2()
{

}