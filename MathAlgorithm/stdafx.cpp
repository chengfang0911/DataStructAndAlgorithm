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
using namespace std;

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
int *g_Arr;
constexpr int g_Size = 10;

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

void InitData()
{
	g_Arr = new int[10];
	unique_ptr<int> uqptrArr;
	unique_ptr<int> uqptrArr1(g_Arr);
	uqptrArr = move(uqptrArr1);
	//uqptrArr.reset(g_Arr);
	for (int i = 0; i < 10; i++)
	{
		g_Arr[i] = rand() % 100;
	}
}

void printdata()
{
	cout << "---------" << endl;
	for (int i=0;i<g_Size;i++)
	{
		cout << g_Arr[i] << endl;
	}
}

void DeleteData()
{

}



void InsertSort()
{
	InitData();
	printdata();
	int j = -1;;
	for (int i=1;i<10;i++)
	{
		int ntemp = g_Arr[i];
		for (j=i;j>0 && g_Arr[j-1]>ntemp;j--)
			g_Arr[j] = g_Arr[j-1];
		g_Arr[j] = ntemp;
	}
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