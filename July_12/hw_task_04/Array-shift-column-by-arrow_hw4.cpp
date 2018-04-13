// Create dynamic n-size array and fill it random numbers
// by the press the arrows shifting the collumns or rows in the same direction

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>

using namespace std;

void Array(int ** ppArray, int Size);
void ArrayFillingRandom(int ** ppArray, int Size);

int main()
{
	srand((unsigned int)time(0));

	int nSize;
	do
	{
		system("cls");
		cout << "Enter size (number between 3 and 25) of the array: ";
		cin >> nSize;
	} while (nSize < 3 || nSize > 25);

	//int nSize = 10; // default size for array
	int ** ppArray = new int *[nSize]; // initialyze array of poinerts
	int * pArrayTemp = new int[nSize]; // pointer to array for sum by collumns
	int KeyChoice = 5;
	bool bArrayOut = false;

	// create numbers of arrays and write pointer into the array
	for (int i = 0; i < nSize; ++i)
		ppArray[i] = new int[nSize];

	// filling arrays by the randon numbers
	ArrayFillingRandom(ppArray, nSize);
	// output array first time
	Array(ppArray, nSize);

	while (KeyChoice != 27) // Do until Escape pressed
	{
		bArrayOut = false;
		KeyChoice = _getch();
		switch (KeyChoice)
		{
			case 77: // arrow right
			{
				// write last column to temp array
				for (int i = 0; i < nSize; ++i)
				{
					int j = nSize - 1;
					pArrayTemp[i] = ppArray[i][j]; // copy last collumn to temp array
					for (int k = nSize - 1; k >= 0; --k)
						ppArray[i][k] = ppArray[i][k - 1];
					ppArray[i][0] = pArrayTemp[i];
				}
				bArrayOut = true;
			} break;
			case 75: // arrow left
			{
				// write first column to temp array
				for (int i = 0; i < nSize; ++i)
				{
					int j = 0;
					pArrayTemp[i] = ppArray[i][j]; // copy first column to temp array
					for (int k = 1; k < nSize; ++k)
						ppArray[i][k - 1] = ppArray[i][k];
					ppArray[i][nSize - 1] = pArrayTemp[i];
				}
				bArrayOut = true;
			} break;
			case 72: // arrow up
			{
				// write first row to temp array
				for (int k = 0; k < nSize; ++k)
					pArrayTemp[k] = ppArray[0][k]; // copy first row to temp array
				for (int i = 0; i < nSize; ++i)
					for (int j = 0; j < nSize; ++j)
					{
						if (i + 1 < nSize)
							ppArray[i][j] = ppArray[i + 1][j];
						else
							ppArray[nSize -1][j] = pArrayTemp[j];
					}
				bArrayOut = true;
			} break;
			case 80: // arrow down
			{
				// write last row to temp array
				for (int k = 0; k < nSize; ++k)
					pArrayTemp[k] = ppArray[nSize - 1][k]; // copy last row to temp array
				for (int i = nSize - 1; i >= 0; --i)
					for (int j = 0; j < nSize; ++j)
					{
						if (i - 1 >= 0)
							ppArray[i][j] = ppArray[i - 1][j];
						else
							ppArray[0][j] = pArrayTemp[j];
					}
				bArrayOut = true;
			} break;
		}
		if (bArrayOut)
			Array(ppArray, nSize);
	}
	cout << endl << endl;

	//Array(ppArray, nSize);
	//cout << endl;
	//for (int j = 0; j < nSize; ++j)
	//	cout << setw(3) << pArrayTemp[j];
	//cout << endl;

	// free memory
	for (int i = 0; i < nSize; ++i)
		delete[] ppArray[i];
	delete[] ppArray;
	delete[] pArrayTemp;

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}

void Array(int ** ppArray, int Size)
{
	system("cls");
	// output the big array and next of it arra with row sum
	for (int i = 0; i < Size; ++i)
	{
		for (int j = 0; j < Size; ++j)
			cout << setw(3) << ppArray[i][j];
		cout << setw(3) << endl;
	}
}

void ArrayFillingRandom(int ** ppArray, int Size)
{
	for (int i = 0; i < Size; ++i)
		for (int j = 0; j < Size; ++j)
			ppArray[i][j] = rand() % 10;
}