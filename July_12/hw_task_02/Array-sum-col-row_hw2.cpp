// Create dynamic n-size array and fill it random numbers
// sum te rows and collumns
// out the array and sum of each col and row

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int nSize;
	do
	{
		system("cls");
		cout << "Enter size (number between 3 and 12) of the array: ";
		cin >> nSize;
	} while (nSize < 3 || nSize > 12);

	//int nSize = 10; // default size for array
	int ** ppArray = new int *[nSize]; // initialyze array of poinerts
	int * pArraySumCol = new int[nSize]; // pointer to array for sum by collumns
	int * pArraySumRow = new int[nSize]; // pointer to array for sum by rows

	system("cls");

	// create numbers of arrays and write pointer into the array
	for (int i = 0; i < nSize; ++i)
		ppArray[i] = new int[nSize];

	// filling arrays by the randon numbers
	for (int i = 0; i < nSize; ++i)
		for (int j = 0; j < nSize; ++j)
			ppArray[i][j] = rand() % 10;

	// sum numbers in each rows and write it into array for sum
	for (int i = 0; i < nSize; ++i)
	{
		pArraySumRow[i] = 0;
		for (int j = 0; j < nSize; ++j)
			pArraySumRow[i] += ppArray[i][j];
	}

	// sum numbers in each collumn and write it into array for sum
	for (int i = 0; i < nSize; ++i)
	{
		pArraySumCol[i] = 0;
		for (int j = 0; j < nSize; ++j)
			pArraySumCol[i] += ppArray[j][i]; // for collumn sum we rotate the array and sum numbers like row sum at first
	}

	// output the big array and next of it arra with row sum
	for (int i = 0; i < nSize; ++i)
	{
		for (int j = 0; j < nSize; ++j)
			cout << setw(3) << ppArray[i][j];
		cout << setw(3) << "|";
		cout << setw(3) << pArraySumRow[i] << endl;
	}
	// output before big array the array with sum of rows
	for (int j = 0; j < nSize; ++j)
		cout << setw(3) << "---";
	cout << endl;
	for (int j = 0; j < nSize; ++j)
		cout << setw(3) << pArraySumCol[j];
	cout << endl << endl;

	// free memory
	for (int i = 0; i < nSize; ++i)
		delete[] ppArray[i];
	delete[] ppArray;
	delete[] pArraySumCol;
	delete[] pArraySumRow;

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}
