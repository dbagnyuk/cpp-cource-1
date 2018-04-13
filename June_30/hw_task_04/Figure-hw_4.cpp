// use the figure from the previous home tasks
// request and read user's choice of bias numbers for X and Y.
// draw the figure with user's choice of offset.

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

void Figure(int nSize, char cChar, char cSpace, int nX, int nY);

int main()
{
	// Default values
	int nSizeDefault = 5;
	char cCharDefault = '*';
	char cSpaceDefault = ' ';
	int nXchoice, nYchoice;

	cout << "Please enter the bias for X-axis: ";
	cin >> nXchoice;
	cout << "Please enter the bias for Y-axis: ";
	cin >> nYchoice;
	system("cls");

	Figure(nSizeDefault, cCharDefault, cSpaceDefault, nXchoice, nYchoice);

	cout << endl;
	return 0;
}

//*****
//*   *
//* 3 *
//*   *
//*****
void Figure(int nSize, char cChar, char cSpace, int nX, int nY)
{
	int nNumber = nSize;
	int nSide = nSize + 2;

	for (int i = 0; i < nX; ++i)
		cout << endl;

	for (int i = 0; i < nSide; ++i)
	{
		for (int i = 0; i < nY; ++i)
			cout << cSpace;

		//cout << cSpace;
		if (i == 0 || i == nSide - 1)
		{
			for (int j = 0; j < nSide; ++j)
				cout << cChar;
		}
		else if (i == (nSize / 2) + 1)
		{
			cout << cChar;
			if (nSize > 9)
			{
				for (int j = 0; j < (nSize / 2); ++j)
					cout << cSpace;
				cout << nNumber;
				for (int j = (nSize / 2) + 2; j < nSize; ++j)
					cout << cSpace;
			}
			else
			{
				for (int j = 0; j < (nSize / 2); ++j)
					cout << cSpace;
				cout << nNumber;
				for (int j = (nSize / 2) + 1; j < nSize; ++j)
					cout << cSpace;
			}
			cout << cChar;
		}
		else
		{
			cout << cChar;
			for (int j = 0; j < nSize; ++j)
				cout << cSpace;
			cout << cChar;
		}
		cout << endl;
	}
}
