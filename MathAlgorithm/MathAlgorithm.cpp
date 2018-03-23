// MathAlgorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

constexpr int nSize = 10;

template <typename T>
class Singleton
{
public:
	static T* s_Instance;
     static T* Instance()
     {
		 if (s_Instance == NULL)
		 {
			 s_Instance = new Singleton<T>();
		 }
         return s_Instance;
     }

 protected:
     Singleton(void) {}
     ~Singleton(void) {}

 private:
     Singleton(const Singleton& rhs) {}
     Singleton& operator = (const Singleton& rhs) {}
};

int main()
{
	//cout << Gcd(12, 9) << endl;

//	InsertSort();
//	ShellSort();
	//HeadSort();
	//char buf[16] = "test charbuf";
	//MyString str1;
	//str1 = "test copy structfunction";
	//MyString str2 = str1;
	//MyString str3(str2);
	//MyString str4(buf);

	//cout << str1 <<endl;
	//HeapSort();
	//MergeSort();
    return 0;
}

