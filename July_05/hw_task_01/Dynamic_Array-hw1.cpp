// Random Array on 20 numbers
// Find even numbers
// write finded even in dynamic array

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
	int iArray2Size = iArray1Size;
	int * pArray1 = new int[iArray1Size]; // Array size 20
	int * pArray2 = new int[iArray2Size];
	int * pArray2Begin = pArray2;

	// Filling and cout Array 1 by the random numbers
	FillArraybyRandomNumbers(pArray1, iArray1Size);
	cout << "The Input Random Array " << iArray1Size << " numbers Array: " << endl;
	OutputArray(pArray1, iArray1Size);

	//cout << pArray2 << " " << pArray2Begin << " " << *pArray2 << " " << *pArray2Begin << " " << endl << endl;

	iArray2Size = 0;
	for (int i = 0; i < iArray1Size; ++i)
	{
		if (pArray1[i] % 2 == 0 && pArray1[i] != 0)
			pArray2[iArray2Size++] = pArray1[i];
	}

	cout << "The Output Array on " << iArray2Size << " numbers:" << endl;
	OutputArray(pArray2Begin, iArray2Size);

	delete [] pArray1;
	delete [] pArray2;

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
