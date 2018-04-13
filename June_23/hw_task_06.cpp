// Array-hw2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{

	srand((unsigned int)time(0));

	const int iArraySize = 20;
	int iArray[iArraySize];

	for (int i = 0; i < iArraySize; ++i)
		iArray[i] = rand() % 20;

	for (int i = 0; i < iArraySize; ++i)
		cout << iArray[i] << ' ';
	cout << endl;

	int nCountEven = 0;
	for (int i = 0; i < iArraySize; ++i)
	{
		if (i % 2 == 0)
			nCountEven++;
	}

	int nCountOdd = 0;
	for (int i = 0; i < iArraySize; ++i)
	{
		if (i % 2 != 0)
			nCountOdd++;
	}

	cout << "Count Even numbers: " << nCountEven << "; " << "Count Odd numbers: " << nCountOdd << endl;

	if (nCountEven > nCountOdd)
		cout << "Count of Even numbers more than count of Odd numbers.";
	else if (nCountEven < nCountOdd)
		cout << "Count of Odd numbers more than count of Even number.";
	else
		cout << "Count of Even and Odd numbers is equal.";

	cout << endl << endl;

	return 0;
}
