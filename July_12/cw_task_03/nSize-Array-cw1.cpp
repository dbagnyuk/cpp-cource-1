// nSize-Array-cw1.cpp : Defines the entry point for the console application.
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
	srand((unsigned int)time(0));

	int nSize = 10;
	int ** ppArray = new int * [nSize];

	for (int i = 0; i < nSize; ++i)
		ppArray[i] = new int[nSize];

	for (int i = 0; i < nSize; ++i)
		for (int j = 0; j < nSize; ++j)
			ppArray[i][j] = rand() % 10;

	for (int i = 0; i < nSize; ++i)
	{
		for (int j = 0; j < nSize; ++j)
			cout << ppArray[i][j] << ' ';
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < nSize; ++i)
		delete[] ppArray[i];
	delete[] ppArray;

	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;
	
	return 0;
}
