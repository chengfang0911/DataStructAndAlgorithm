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
class TreeNode
{
public:
	TreeNode()
	{
		pLeft = NULL;
		pRight = NULL;
	}
	TreeNode(T Tdata)
	{
		data = Tdata;
		pLeft = NULL;
		pRight = NULL;
	}
	T data;
	TreeNode *pLeft;
	TreeNode *pRight;
};


template<class T>
class CTree
{
public:
	CTree()
	{
		m_pRoot = NULL;
	}
	~CTree() {}
	void MakeEmtpy()
	{
		MakeEmtpy(m_pRoot);
	}

	TreeNode<T> *Find(T data)
	{
		Find(data, m_pRoot);
	}
	TreeNode<T> *InsertTreeData(T data)
	{
		return InsertTreeData(data, m_pRoot);
	}
	TreeNode<T> *FindMin()
	{
		if (NULL == m_pRoot)
		{
			return NULL;
		}
		if (m_pRoot->pLeft == NULL)
		{
			return m_pRoot;
		}
		return FindMin(m_pRoot->pLeft);
	}
	TreeNode<T> *FindMax() 
	{
		if (NULL == m_pRoot)
		{
			return NULL;
		}
		if (m_pRoot->pRight == NULL)
		{
			return m_pRoot;
		}
		return FindMin(m_pRoot->pRight);
	}

	void Delete(T data) {}
	T Retrieve(TreeNode<T> *pPos) {}

private:
	TreeNode<T> *m_pRoot;

	TreeNode<T> *Find(T data, TreeNode<T> *pNode = NULL)
	{
		if (NULL == pNode)
		{
			return NULL;
		}
		if (data == pNode->data)
			return m_pRoot;
		else if (data < pNode->data)
			return Find(data, pNode->pLeft);
		else
			return Find(data, pNode->pRight);
	}
	TreeNode<T> *InsertTreeData(T data, TreeNode<T> *pNode)
	{
		if (pNode == NULL)
		{
			pNode = new TreeNode<T>(data);
			return pNode;
		}
		if (data == pNode->data)
		{
			return pNode;
		}
		else if (data < pNode->data)
		{
			pNode->pLeft = InsertTreeData(data, pNode->pLeft);
		}
		else if (data > pNode->data)
		{
			pNode->pRight = InsertTreeData(data, pNode->pRight);
		}
		return pNode;
	}
	void MakeEmtpy(TreeNode<T> *pNode)
	{
		if (pNode != NULL)
		{
			MakeEmtpy(pNode->pLeft);
			MakeEmtpy(pNode->pRight);
			delete pNode;
		}
	}
	TreeNode<T> *FindMin(TreeNode<T> *pNode)
	{
		if (NULL == pNode->pLeft)
		{
			return pNode;
		}
		else
		{
			return FindMin(pNode->pLeft);
		}
	}
	TreeNode<T> *FindMax(TreeNode<T> *pNode)
	{
		if (NULL == pNode->pRight)
		{
			return pNode;
		}
		else
		{
			return FindMin(pNode->pRight);
		}
	}
};


// TODO: reference additional headers your program requires here
