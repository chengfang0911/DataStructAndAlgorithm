// stdafx.cpp : source file that includes just the standard includes
// MathAlgorithm.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

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