// Pointers-cw_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{

	int a = 5, b(7);
	int * pA = &a;

	cout << a << ' ' << &a << ' ' << b << ' ' << &b << ' ' << pA << ' ' << endl;

	*pA += 10;
	pA = &b;
	*pA += 10;

	cout << a << ' ' << &a << ' ' << b << ' ' << &b << ' ' << pA << ' ' << endl;

    return 0;
}

