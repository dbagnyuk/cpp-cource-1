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
	const int iArray2SizeX = iArray1Size;
	const int iArray2SizeY = 2;
	int iArray1[iArray1Size]; // Array size 20
	int iArray2[iArray2SizeX][iArray2SizeY]; // Array size 2x20
	int nNum, nCnt, nCntEx, kX = 0;

	FillArraybyRandomNumbers(iArray1, iArray1Size); // Filling and cout Array1 by the random numbers
	CoutTextAboutArray(iArray1Size);
	OutputArray(iArray1, iArray1Size);

	//for (int j = 0; j < iArray2SizeX; ++j)
	//	for (int k = 0; k < iArray2SizeY; ++k)
	//		iArray2[j][k] = false;

	// Finding and write into new Array3 each number and hit count from 1st Array
	for (int i = 0; i < iArray1Size - 1; ++i)
	{
		nNum = iArray1[i];
		nCnt = 1;
		nCntEx = 0;

		for (int k = 0; k < iArray2SizeX; ++k)
			if (iArray2[k][0] == nNum)
				nCntEx++;

		if (nCntEx != 0)
			continue;

		for (int j = i + 1; j < iArray1Size; ++j)
		{
			if (nNum == iArray1[j])
				nCnt++;
		}

		iArray2[kX][0] = nNum;
		iArray2[kX][1] = nCnt;
		kX++;
	}

	cout << "Number:" << " " << "Count:" << endl;
	for (int j = 0; j < kX; ++j)
	{
		for (int k = 0; k < iArray2SizeY; ++k)
			cout << setw(7) << iArray2[j][k];
		cout << endl;
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
