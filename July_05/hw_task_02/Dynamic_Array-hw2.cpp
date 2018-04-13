// 2x Random Array on 20 and 10 numbers
// Merge both arrays in third dynamic array

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <math.h>

using namespace std;

void FillArraybyRandomNumbers(int * InputArray, int Size);
void OutputArray(int * OutputArray, int Size);

int main()
{
	srand((unsigned int)time(0));

	int iArray1Size = 20; // constant for aray size
	int iArray2Size = 10;
	int iArray3MergeSize = iArray1Size + iArray2Size;
	int * pArray1 = new int[iArray1Size]; // Array size 20
	int * pArray2 = new int[iArray2Size];
	int * pArray3Merge = new int[iArray3MergeSize];
	int * pArray3MergeBegin = pArray3Merge;

	// Filling and cout Array 1st by the random numbers
	FillArraybyRandomNumbers(pArray1, iArray1Size);
	cout << "The Input Random Array " << iArray1Size << " numbers Array: " << endl;
	OutputArray(pArray1, iArray1Size);
	// Filling and cout Array 2nd by the random numbers
	FillArraybyRandomNumbers(pArray2, iArray2Size);
	cout << "The Input Random Array " << iArray2Size << " numbers Array: " << endl;
	OutputArray(pArray2, iArray2Size);

	iArray3MergeSize = 0;
	for (int i = 0; i < iArray1Size; ++i)
		pArray3Merge[iArray3MergeSize++] = pArray1[i];
	for (int j = 0; j < iArray2Size; ++j)
		pArray3Merge[iArray3MergeSize++] = pArray2[j];

	cout << "The Output Array on " << iArray2Size << " numbers:" << endl;
	OutputArray(pArray3MergeBegin, iArray3MergeSize);

	delete[] pArray1;
	delete[] pArray2;
	delete[] pArray3Merge;

	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

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
	cout << endl;
}
