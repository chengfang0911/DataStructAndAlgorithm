// Charpter_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	CTree<int> tree;
	tree.InsertTreeData(5);
	tree.InsertTreeData(3);
	tree.InsertTreeData(2);
	tree.InsertTreeData(1);
	tree.InsertTreeData(4);
	tree.InsertTreeData(7);
	tree.InsertTreeData(6);
	tree.InsertTreeData(8);
	tree.InsertTreeData(9);
	tree.InsertTreeData(10);

	cout << "Tree Max is: " << tree.FindMax()->data<< endl;
	cout << "Tree min is: " << tree.FindMin()->data << endl;
	cout << "----------depth----------" << endl;
	tree.Depth();
	cout << "----------width----------" << endl;
	tree.Width();

	//CHeap<int> heap;
	//heap.Init();
	//heap.Insert(1);
	//heap.Insert(3);
	//heap.Insert(5);
	//heap.Insert(7);
	//heap.Insert(9);
	//heap.Insert(2);
	//heap.Insert(4);
	//heap.Insert(6);
 //   return 0;
}

