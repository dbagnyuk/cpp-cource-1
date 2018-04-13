// create Array with 20 random numbers.fill it by the rand() % 21.
// request and read user's choice number.
// said is number exists or not in array and on which position in array

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

void FillArraybyRandomNumbers(int * InputArray, int Size);
void FillArraybyFalse(int * InputArray, int Size);
void OutputArray(int * OutputArray, int Size);
void CoutTextAboutArray(int Size);

int main()
{
	srand((unsigned int)time(0));

	const int iArray1Size = 20; // constant for aray size
	const int iArray2Size = iArray1Size;
	int iArray1[iArray1Size]; // Array size 20
	int iArray2[iArray2Size]; // Array size 20
	int nNumber; int nNumExists = 0;
	int j = 0;

	FillArraybyRandomNumbers(iArray1, iArray1Size); // Filling and cout Array1 by the random numbers
	FillArraybyFalse(iArray2, iArray2Size); // Filling Array2 by the fault
	CoutTextAboutArray(iArray1Size);
	OutputArray(iArray1, iArray1Size);

	cout << "Please enter the number which you whant to know exists in array or not: ";
	cin >> nNumber;

	// Finding number in array and say about it
	for (int i = 0; i < iArray1Size; ++i)
	{
		if (iArray1[i] == nNumber)
		{
			nNumExists++;
			iArray2[j] = i;
			j++;
		}
	}

	if (nNumExists)
	{
		cout << "Number " << nNumber << " exists in array.";
		cout << "Number stay in array on position: ";
		for (int i = 0; i < j; ++i)
			cout << setw(3) << iArray2[i] + 1;
	}
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
void FillArraybyFalse(int * InputArray, int Size)
{
	for (int j = 0; j < Size; ++j)
		InputArray[j] = false;
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
