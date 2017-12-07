// MathAlgorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	//cout << Gcd(12, 9) << endl;

//	InsertSort();
	char buf[16] = "test charbuf";
	MyString str1;
	str1 = "test copy structfunction";
	MyString str2 = str1;
	MyString str3(str2);
	MyString str4(buf);

	cout << str1 <<endl;
    return 0;
}

