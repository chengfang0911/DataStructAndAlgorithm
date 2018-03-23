#pragma once    
#include <iostream>
#include <stdio.h>
#include <tchar.h>

using namespace std;
template<class T>
class CHeap
{
public:
	CHeap():m_data(NULL), m_nSize(0), m_nPos(-1)
	{};
	CHeap(const CHeap &hp) 
	{
	};
	//CHeap<T>& operator= CHeap(const CHeap &hp)
	//{
	//	return *this;
	//};
	//CHeap& operator= CHeap(const CHeap &hp)
	//{
		//m_data = new T[heap.m_nSize];
		//for (int i = 0;i<m_nSize£»i++)
		//{
		//	m_data[i] = 0;
		//}
	//};
	~CHeap() 
	{
		if (m_data)
		{
			delete[]m_data;
		}
	}
	void Init(int nSize = 32)
	{
		m_data = new T[nSize + 1];
		if (m_data)
		{
			m_nSize = nSize;
			m_nPos = 0;
			memset(m_data, 0, sizeof(T) * nSize);
			m_data[0] = 0;
		}
	}

	bool Insert(T val)
	{
		if (!m_data)
			Init();
		int i;
		for (i = ++m_nPos; val < m_data[GetFatherID(i)]; i /= 2)//if insert data < father
			m_data[i] = m_data[GetFatherID(i)];
		m_data[i] = val;
		return true;
	}
	T Get()
	{
		T data;
		return data;
	}
	T Delete()
	{
		cout << "delete min data:";
		T mindata = m_data[1];
		T lastadata = m_data[m_nPos--];
		int i = 0;
		int nchild;
		for (i = 1; i * 2 < m_nPos; i = nchild)
		{
			nchild = i * 2;
			if (m_data[nchild + 1] < m_data[nchild])//get min son
			{
				nchild++;
			}
			if (m_data[nchild] < lastadata)//if son < lastdata
			{
				m_data[i] = m_data[nchild];
			}
			else
			{
				break;
			}
		}
		m_data[i] = lastadata;
		return mindata;
	}
	void PrintData()
	{
		cout << endl << "---------------------------"<<endl;
		for (int i = 0;i<m_nPos;i++)
		{
			cout << m_data[i] << " ";
		}
		cout << "---------------------------" << endl;
	}
private:
	int GetFatherID(int nIndex)
	{
		return nIndex / 2;
	}
	int m_nSize;
	int m_nPos;
	T* m_data;
};