// create Array with 20 random numbers.fill it by the rand() % 21.
// find all pair numbers sum of which must be equal 20.

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

void FillArraybyRandomNumbers(int * InputArray, int Size);
void FillArraybyFalse(int * InputArray, int Size);
void OutputArray(int * OutputArray, int Size);
void OutputResultArray(int * OutputResultArray, int Size);
void CoutTextAboutArray(int Size);

int main()
{
	srand((unsigned int)time(0));

	const int iArray1Size = 20; // constant for aray size
	const int iArray2Size = iArray1Size;
	int iArray1[iArray1Size]; // Array size 20
	int iArray2[iArray2Size]; // Array size 20
	
	FillArraybyRandomNumbers(iArray1, iArray1Size); // Filling and cout Array1 by the random numbers
	FillArraybyFalse(iArray2, iArray2Size); // Filling Array2 by the fault
	CoutTextAboutArray(iArray1Size);
	OutputArray(iArray1, iArray1Size);

	// Finding and write into new Array3 each number from 1st Array into 2nd Array
	for (int i = 0; i < iArray1Size - 1; ++i)
			if (20 == iArray1[i] + iArray1[i + 1])
			{
				iArray2[i] = iArray1[i];
				iArray2[i + 1] = iArray1[i + 1];
			}

	OutputResultArray(iArray2, iArray2Size);
	return 0;
}

void FillArraybyRandomNumbers(int * InputArray, int Size)
{
	for (int i = 0; i < Size; ++i)
		InputArray[i] = rand() % 21;
}
void FillArraybyFalse(int * InputArray, int Size)
{
	for (int j = 0; j < Size; ++j)
		InputArray[j] = false;
}
void OutputArray(int * OutputArray, int Size)
{
	for (int i = 0; i < Size; ++i)
		cout << setw(3) << OutputArray[i];
	cout << endl;
}
void CoutTextAboutArray(int Size)
{
	cout << Size << " numbers Array: ";
}
void OutputResultArray(int * OutputResultArray, int Size)
{
	cout << "Result Array:     ";
	for (int j = 0; j < Size; ++j)
		if (OutputResultArray[j] == false)
			cout << setw(3) << " ";
		else
			cout << setw(3) << OutputResultArray[j];
	cout << endl << endl;
}
