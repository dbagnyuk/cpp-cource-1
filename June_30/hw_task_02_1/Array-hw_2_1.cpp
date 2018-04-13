// create Array with 20 random numbers.fill it by the rand() % 21.
// output numbers and count of it.

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

void FillArraybyRandomNumbers(int * InputArray, int Size);
void OutputArray(int * OutputArray, int Size);
void CoutTextAboutArray(int Size);

int main()
{
	srand((unsigned int)time(0));

	const int iArray1Size = 20; // constant for aray size
	int iArray1[iArray1Size]; // Array size 20
	int nCnt = 0, a;

	FillArraybyRandomNumbers(iArray1, iArray1Size); // Filling and cout Array1 by the random numbers
	CoutTextAboutArray(iArray1Size);
	OutputArray(iArray1, iArray1Size);

	// Finding and write into new Array3 each number and hit count from 1st Array
	for (int i = 0; i < iArray1Size; ++i)
	{
		if (iArray1[i] != -1)
		{
			cout << iArray1[i] << " = ";
			nCnt = 1;
			a = iArray1[i];
			iArray1[i] = -1;

			for (int j = i + 1; j < iArray1Size; ++j)
			{
				if (iArray1[j] == a)
				{
					++nCnt;
					iArray1[j] = -1;
				}
			}
			cout << nCnt << endl;
		}
	}

	cout << endl;
	return 0;
}

void FillArraybyRandomNumbers(int * InputArray, int Size)
{
	for (int i = 0; i < Size; ++i)
		InputArray[i] = rand() % 21;
}
void OutputArray(int * OutputArray, int Size)
{
	for (int i = 0; i < Size; ++i)
		cout << setw(3) << OutputArray[i];
	cout << endl << endl;
}
void CoutTextAboutArray(int Size)
{
	cout << Size << " numbers Array: ";
}
