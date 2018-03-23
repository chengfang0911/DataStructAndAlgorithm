// Charpter_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>

int main()
{
	//CTree<int> tree;
	//tree.InsertTreeData(5);
	//tree.InsertTreeData(3);
	//tree.InsertTreeData(2);
	//tree.InsertTreeData(1);
	//tree.InsertTreeData(4);
	//tree.InsertTreeData(7);
	//tree.InsertTreeData(6);
	//tree.InsertTreeData(8);
	//tree.InsertTreeData(9);
	//tree.InsertTreeData(10);

	//cout << "Tree Max is: " << tree.FindMax()->data<< endl;
	//cout << "Tree min is: " << tree.FindMin()->data << endl;
	//cout << "----------depth----------" << endl;
	//tree.Depth();
	//cout << "----------width----------" << endl;
	//tree.Width();
	CHeap<int> heap;
	heap.Init();
	//srand(time(NULL));
	for (int i=0;i>=0 && i<1;i++)
	{
		cout << i << "=+++" << endl;
	}
	for (int i = 0; i < 15; i++)
	{
		heap.Insert(rand() % 100);
	}
	heap.PrintData();
	for (int i=0;i<5;i++)
	{
		cout << heap.Delete();
		heap.PrintData();
	}

	return 0;
}

