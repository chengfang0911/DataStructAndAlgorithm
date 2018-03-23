// stdafx.cpp : source file that includes just the standard includes
// MathAlgorithm.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <string.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <errno.h>  
#include <time.h>

using namespace std;
#define LEFTCHILD(i) ((i) * 2) + 1 
// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
int *g_Arr;
int *g_tempArr;
int g_Size;

unsigned int Gcd(unsigned int num1, unsigned num2)
{
	unsigned int Rem;
	while (num2 > 0)
	{
		Rem = num1 % num2;
		num1 = num2;
		num2 = Rem;
	}
	return num1;
}

void InitData(int nsize = 10)
{
	g_Size = nsize;
	g_Arr = new int[nsize];
	g_tempArr = new int[nsize];
#ifndef _DEBUG 
	srand(time(NULL));
#endif
	for (int i = 0; i < g_Size; i++)
	{
		g_Arr[i] = rand() % 100;
	}
}

void printdata()
{
	cout << endl<< "---------" << endl;
	for (int i = 0;i < g_Size; i++)
	{
		cout << g_Arr[i] << "     ";
	}
}

void DeleteData()
{
	if (g_Arr)
	{
		delete[]g_Arr;
		g_Arr = NULL;
	}
}

void InsertSort()
{
	InitData();
	printdata();
	int i, j;
	int ntemp;
	for (i = 1; i < g_Size; i++ )
	{
		ntemp = g_Arr[i];
		for (j = i; j > 0 && g_Arr[j - 1] > ntemp; j--)
			g_Arr[j] = g_Arr[j - 1];
		g_Arr[j] = ntemp;
	}

	printdata();
	DeleteData();
}

void ShellSort()
{
	InitData();
	printdata();
	int nIncrement,i,j;
	int ntemp;
	for (nIncrement = g_Size / 2;nIncrement > 0;nIncrement /= 2)
	{
		for (i = nIncrement;i < g_Size; i++)
		{
			ntemp = g_Arr[i];
			for (j = i;j - nIncrement >= 0;j-=nIncrement)
			{
				if (g_Arr[j - nIncrement] > ntemp)
				{
					g_Arr[j] = g_Arr[j - nIncrement];
				}
				else
					break;
			}
			g_Arr[j] = ntemp;
		}
	}

	printdata();
	DeleteData();
}

void Swap(int &num1, int &num2)
{
	num1 = num1 ^ num2;
	num2 = num1 ^ num2;
	num1 = num1 ^ num2;
}

void PercDown(int nIndex, int nSum)
{
	int nChild;
	int nTemp;
	int i;
	nTemp = g_Arr[nIndex];
	for (i = nIndex;LEFTCHILD(i) < nSum; i = nChild)
	{
		nChild = LEFTCHILD(i);
		if (LEFTCHILD(i) + 1 < nSum && g_Arr[LEFTCHILD(i) + 1] > g_Arr[LEFTCHILD(i)])//区最大的孩子
		{
			nChild++;
		}
		if (nTemp < g_Arr[nChild] )
		{
			g_Arr[i] = g_Arr[nChild];
		}
		else
		{
			break;
		}
	}
	g_Arr[i] = nTemp;
}

void HeapSort()
{
	InitData();
	printdata();
	for (int i = g_Size / 2;i >= 0;i--)
	{
		PercDown(i,g_Size);
	}
	printdata();
	for (int i = g_Size -1;i > 0;i--)
	{
		Swap(g_Arr[0], g_Arr[i]);
		PercDown(0,i);
	}
	printdata();
}

void Merge(int *pArray , int *ptempArray ,int left,int mid,int right)
{
	int leftend = mid - 1;
	int i = left;
	int tmp = left;
	int j = mid;
	while (i < leftend && j < right)
	{
		if (pArray[i] <= pArray[j])
			ptempArray[tmp++] = pArray[i++];
		else
			ptempArray[tmp++] = pArray[j++];
	}
	while (i <= leftend)
	{
		ptempArray[tmp++] = pArray[i++];
	}
	while(j <= right)
		ptempArray[tmp++] = pArray[j++];

	for (int z = 0; z < right-left + 1; z++, right--)
		pArray[right] = ptempArray[right];
}


void MSort(int *pArray, int *ptempArray, int left ,int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MSort(pArray, ptempArray, left, mid);
		MSort(pArray, ptempArray, mid + 1, right);
		Merge(pArray, ptempArray, left, mid + 1, right);
	}
}

void MergeSort()
{
	InitData(20);
	printdata();

	MSort(g_Arr, g_tempArr, 0, g_Size - 1);

	printdata();
}

MyString::MyString()
	: m_buf(NULL),m_length(0)
{
	
}
MyString::MyString(const MyString &str)
{
	m_length = str.m_length;
	m_buf = new char[m_length + 1];
	memset(m_buf, 0, m_length + 1);
	strcpy_s(m_buf, m_length + 1, str.m_buf);
}
MyString::MyString(const char *buf)
{
	m_length = strlen(buf);
	m_buf = new char[m_length + 1];
	memset(m_buf, 0, m_length + 1);
	strcpy_s(m_buf, m_length + 1, buf);
}
MyString& MyString::operator = (const MyString &str)
{
	m_length = str.m_length;
	m_buf = new char[m_length + 1];
	memset(m_buf, 0, m_length + 1);
	strcpy_s(m_buf, m_length + 1, str.m_buf);
	return *this;
}
MyString::~MyString()
{
	if (m_length)
	{
		delete[]m_buf;
	}
}

ostream &operator<<(ostream& out, const MyString &str)
{
	out << str.m_buf;
	return out;
}

