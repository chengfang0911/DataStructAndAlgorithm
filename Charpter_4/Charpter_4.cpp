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

	cout << "Tree Max is: " << tree.FindMax() << endl;
	cout << "Tree min is: " << tree.FindMin() << endl;

    return 0;
}

