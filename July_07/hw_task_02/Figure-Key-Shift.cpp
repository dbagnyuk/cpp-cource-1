// use the figure from the previous home tasks
// uder use the arrows for moving the figure by X and Y.

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>

using namespace std;

void Figure(int nSize, char cChar, char cSpace, int nX, int nY);

int main()
{
	// Default values
	int nSizeDefault = 5;
	char cCharDefault = '*';
	char cSpaceDefault = ' ';
	int nXscan, nXdefault = 10, nYscan, nYdefault = 35;
	int KeyChoice = 5, KeyStart = 5;

	do
	{
		system("cls");
		cout << "For moving Figure use the 'Arrows'" << endl << "For default position use 'Space'" << endl << "For the end of the program use 'Escape'" << endl << endl << "For beginning press 'Enter'";
		KeyStart = _getch();
	} while (KeyStart != 13);

	if (KeyStart == 13) // enter key
		Figure(nSizeDefault, cCharDefault, cSpaceDefault, nXdefault, nYdefault);

	nXscan = nXdefault;
	nYscan = nYdefault;
	while (KeyChoice != 27) // Escape
	{
		KeyChoice = _getch();
		switch (KeyChoice)
		{
			case 72: // arrow up
			{
				--nXscan;
				if (nXscan >= 0 && nXscan <= 17)
				{
					Figure(nSizeDefault, cCharDefault, cSpaceDefault, nXscan, nYscan);
				}
				else
				{
					nXscan = 0;
					Figure(nSizeDefault, cCharDefault, cSpaceDefault, nXscan, nYscan);
				}
			} break;
			case 77: // arrow right
			{
				++nYscan;
				if (nYscan >= 0 && nYscan <= 72)
				{
					Figure(nSizeDefault, cCharDefault, cSpaceDefault, nXscan, nYscan);
				}
				else
				{
					nYscan = 72;
					Figure(nSizeDefault, cCharDefault, cSpaceDefault, nXscan, nYscan);
				}
			} break;
			case 80: // arrow down
			{
				++nXscan;
				if (nXscan >= 0 && nXscan <= 17)
				{
					Figure(nSizeDefault, cCharDefault, cSpaceDefault, nXscan, nYscan);
				}
				else
				{
					nXscan = 17;
					Figure(nSizeDefault, cCharDefault, cSpaceDefault, nXscan, nYscan);
				}
			} break;
			case 75: // arrow left
			{
				--nYscan;
				if (nYscan >= 0 && nYscan <= 72)
				{
					Figure(nSizeDefault, cCharDefault, cSpaceDefault, nXscan, nYscan);
				}
				else
				{
					nYscan = 0;
					Figure(nSizeDefault, cCharDefault, cSpaceDefault, nXscan, nYscan);
				}
			} break;
			case 32: // space
			{
				nXscan = nXdefault;
				nYscan = nYdefault;
				Figure(nSizeDefault, cCharDefault, cSpaceDefault, nXdefault, nYdefault);
			} break;
		}
	}

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

	system("cls");

	for (int i = 0; i < nX; ++i)
		cout << endl;

	for (int i = 0; i < nSide; ++i)
	{
		for (int i = 0; i < nY; ++i)
			cout << cSpace;

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
