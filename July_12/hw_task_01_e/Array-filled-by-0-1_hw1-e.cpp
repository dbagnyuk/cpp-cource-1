// Create dynamic n-size array and fill it 0 and 1 like bellow
// 0 0 1
// 0 1 1
// 0 0 1

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

	int nSize;
	do
	{
		system("cls");
		cout << "Enter size (number between 3 and 25) of the array: ";
		cin >> nSize;
	} while (nSize < 3 || nSize > 25);

	//int nSize = 10; // default size for array
	int ** ppArray = new int *[nSize]; // initialyze array of poinerts

	system("cls");

	// create numbers of arrays and write pointer into the array
	for (int i = 0; i < nSize; ++i)
		ppArray[i] = new int[nSize];

	// filling arrays by the 0
	for (int i = 0; i < nSize; ++i)
		for (int j = 0; j < nSize; ++j)
			ppArray[i][j] = 0;

	// filling the right top corner by the 1
	int k = (nSize / 2);
	for (int i = 0; i < nSize; ++i)
	{
		if (i >= k)
		{
			for (int j = k - ((nSize + 1) % 2); j < nSize - k + ((nSize + 1) % 2); ++j)
				ppArray[j][i] = 1;
			--k;
		}
	}

	// output the array
	for (int i = 0; i < nSize; ++i)
	{
		for (int j = 0; j < nSize; ++j)
			cout << setw(2) << ppArray[i][j];
		cout << endl;
	}
	cout << endl;

	// free memory
	for (int i = 0; i < nSize; ++i)
		delete[] ppArray[i];
	delete[] ppArray;

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}
