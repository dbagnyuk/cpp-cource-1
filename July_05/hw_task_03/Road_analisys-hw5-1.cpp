// create Array with 20 random numbers. fill it by the rand() % 21.
// in each row write the count of symbols equal the number in equal position
// if number <= 10 use "*"
// if number > 10 use "#"
// if number > 10 and closests 2 position (3 in sum) > 10 too use "$"

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <math.h>

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
								//const int iArray2Size = iArray1Size;
	int iArray1[iArray1Size]; // Array size 20
							  //int iArray2[iArray2Size]; // Array size 20
	int nBadCnt = 0;

	FillArraybyRandomNumbers(iArray1, iArray1Size); // Filling and cout Array1 by the random numbers
													//FillArraybyFalse(iArray2, iArray2Size); // Filling Array2 by the fault
	CoutTextAboutArray(iArray1Size);
	OutputArray(iArray1, iArray1Size);
	cout << endl << "Bar Chart of the road covering condition:" << endl << endl;

	for (int i = 0; i < iArray1Size; ++i)
	{
		if (iArray1[i] < 10)
		{
			cout << setw(4) << i + 1 << setw(4) << iArray1[i] << setw(4);
			for (int j = 0; j < iArray1[i]; ++j)
				cout << "*";
			cout << endl;
		}
		else if ((iArray1[i+1] >= 10 && iArray1[i + 2] >= 10) && (i + 1) < iArray1Size && (i + 2) < iArray1Size)
		{
			while (iArray1[i] >= 10)
			{
				cout << setw(4) << i + 1 << setw(4) << iArray1[i] << setw(4);
				for (int j = 0; j < iArray1[i]; ++j)
					cout << "$";
				cout << endl;
				++i;
			}
			--i;
		}
		else if (iArray1[i] >= 10)
		{
			cout << setw(4) << i + 1 << setw(4) << iArray1[i] << setw(4);
			for (int j = 0; j < iArray1[i]; ++j)
				cout << "#";
			cout << endl;
		}
	}
	cout << endl;

	cout << "Bad road covering condition percent: " << nBadCnt * 100 / iArray1Size << "%" << endl;
	cout << endl;
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