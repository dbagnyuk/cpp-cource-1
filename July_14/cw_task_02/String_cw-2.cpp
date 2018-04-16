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
	cout << sSymbol << endl << endl;

	char sString[5] = "Test";

	cout << sString << endl << endl;

	sString[4] = 's';

	for (int i = 0; sString[i] != 0; ++i)
		cout << sString[i];

	cout << endl << endl;

	//for (int i = 0; i < 25000; ++i)
	//	cout << sString[i];
	//cout << endl << endl;

	return 0;
}

