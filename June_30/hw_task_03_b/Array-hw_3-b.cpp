// create Array with 20 random numbers.fill it by the rand() % 21.
// request and read user's choice number.
// said is number exists or not in array and how many tymes

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
	int nNumber, nNumExist = 0, nCntExists = 0;

	FillArraybyRandomNumbers(iArray1, iArray1Size); // Filling and cout Array1 by the random numbers
	CoutTextAboutArray(iArray1Size);
	OutputArray(iArray1, iArray1Size);

	cout << "Please enter the number which you whant to know exists in array or not: ";
	cin >> nNumber;

	// Finding number in array and say about it
	for (int i = 0; i < iArray1Size; ++i)
	{
		if (iArray1[i] == nNumber)
		{
			nNumExist++;
			nCntExists++;
		}
	}

	if (nNumExist > 0)
		cout << "Number " << nNumber << " exists in array " << nCntExists << " times.";
	else
		cout << "Number " << nNumber << " not exists in array.";

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
