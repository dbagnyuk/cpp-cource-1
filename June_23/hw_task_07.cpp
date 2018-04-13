// Array-hw3-3_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

void FillArraybyRandomNumbers(int * InputArray, int Size);
void FillArraybyFalse(int * InputArray, int Size);
void OutputArray(int * OutputArray, int Size);

int main()
{
	srand((unsigned int)time(0));

	const int iArray1Size = 10; // constant for aray size
	const int iArray2Size = iArray1Size * 2;
	const int iArray3Size = iArray2Size;
	int iArray1[iArray1Size]; // Array size 10
	int iArray2[iArray2Size]; // Array size 20
	int iArray3[iArray3Size]; // Array for results, size 20

	// Filling and cout Array 1 by the random numbers
	FillArraybyRandomNumbers(iArray1, iArray1Size);
	cout << "10 numbers Array: ";
	OutputArray(iArray1, iArray1Size);

	// Filling and cout Array 1 by the random numbers
	FillArraybyRandomNumbers(iArray2, iArray2Size);
	cout << "20 numbers Array: ";
	OutputArray(iArray2, iArray2Size);

	// Filling Array 3 (result) by 0
	FillArraybyFalse(iArray3, iArray3Size);

	// Finding and write into new Array3 each number from 1st Array into 2nd Array
	for (int i = 0; i < iArray1Size; ++i)
		for (int j = 0; j < iArray2Size; ++j)
			if (iArray1[i] == iArray2[j])
			{
				bool bExist = true;
				for (int k = 0; k < iArray3Size; ++k)
					if (iArray1[i] == iArray3[k])
					{
						bExist = false;
						break;
					}
				if (bExist)
					iArray3[j] = iArray1[i];
			}

	cout << "Result Array:     ";
	for (int k = 0; k < iArray3Size; ++k)
		if (iArray3[k] == false)
			cout << setw(3) << " ";
		else
			cout << setw(3) << iArray3[k];
	cout << endl << endl;

	return 0;
}

void FillArraybyRandomNumbers(int * InputArray, int Size)
{
	for (int i = 0; i < Size; ++i)
		InputArray[i] = rand() % 21;
}
void FillArraybyFalse(int * InputArray, int Size)
{
	for (int k = 0; k < Size; ++k)
		InputArray[k] = false;
}
void OutputArray(int * OutputArray, int Size)
{
	for (int i = 0; i < Size; ++i)
		cout << setw(3) << OutputArray[i];
	cout << endl;
}
