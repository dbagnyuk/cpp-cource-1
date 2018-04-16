// String_cw-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>

using namespace std;

int main()
{
	char sSymbol = 'a';
	cout << sSymbol << endl;

	char sString[20] = { 'T','e','s','t' };

	cout << sString << endl;

	for (int i = 0; sString[i] != 0; ++i)
		cout << sString[i];

	cout << endl << endl;
    return 0;
}

