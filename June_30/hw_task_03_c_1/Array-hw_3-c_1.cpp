// create Array with 20 random numbers.fill it by the rand() % 21.
// request and read user's choice number.
// said is number exists or not in array and on which position in array

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	const int iArray1SizeX = 2; // constant for aray size rows
	const int iArray1SizeY = 20; // constant for aray size columns
	const int iArray2Size = iArray1SizeY;
	int iArray1[iArray1SizeX][iArray1SizeY]; // Array size 2x20
	int iArray2[iArray2Size]; // Array size 20

	int nNumber; int nNumExists = 0, nCntExists = 0, k = 0;

	for (int i = 0; i < iArray1SizeY; ++i)
	{
		iArray1[0][i] = i + 1;
		iArray1[1][i] = rand() % 21;
	}

	for (int j = 0; j < iArray2Size; ++j)
		iArray2[j] = false;

	cout << "Array with the random numbers and with indexes top of them:" << endl;
	for (int i = 0; i < iArray1SizeX; ++i)
	{
		for (int j = 0; j < iArray1SizeY; ++j)
			cout << setw(3) << iArray1[i][j];
		cout << endl;
	}
	cout << endl;

	cout << "Please enter the number which you whant to know exists in array or not: ";
	cin >> nNumber;

	// Finding number in array and say about it
	for (int i = 0; i < iArray1SizeY; ++i)
	{
		if (iArray1[1][i] == nNumber)
		{
			nNumExists++;
			nCntExists++;
			iArray2[k] = i + 1;
			k++;
		}
	}

	if (nNumExists)
	{
		cout << "Number '" << nNumber << "' exists in array '" << nCntExists << "' times." << endl;
		cout << "Indexes of position in array:";
		for (int i = 0; i < k; ++i)
			cout << setw(3) << iArray2[i];
	}
	else
		cout << "Number '" << nNumber << "' not exists in array.";

	cout << endl << endl;
	return 0;
}
