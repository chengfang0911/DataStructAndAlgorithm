// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#include <iostream>
#include <stdio.h>
#include <tchar.h>

using namespace std;

unsigned int Gcd(unsigned int M, unsigned N);

void InsertSort();

class MyString
{
public:
	MyString();
	MyString(const MyString &str);
	MyString(const char *buf);
	MyString& operator = (const MyString &str);
	friend ostream & operator<<(ostream& out, const MyString &str);

	~MyString();
	char *GetBuf() = delete;
private:
	char *m_buf;
	unsigned int m_length;
};

// TODO: reference additional headers your program requires here
