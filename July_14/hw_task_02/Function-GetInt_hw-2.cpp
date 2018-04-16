// Create the function which must control user's input
// user can't input alphabetical but only numeric character

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>

using namespace std;

bool GettingIntegerRightRange(int nFrom, int nTo, int nResult);
bool GettingIntegerLeftRange(int nFrom, int nTo, int nResult);

int main()
{

	int a = 5;
	int nSize = 100;
	char * sString = new char [nSize];
	int nFrom, nTo;
	int iResultValue;

	cout << "Enter the two numbers:" << endl;
	cout << "First number: "; cin >> nFrom;
	cout << "Second number: "; cin >> nTo;

	if (nTo < nFrom)
		swap(nTo, nFrom);

	cout << "Please enter the number and press Enter: ";
	nSize = 0;
	do
	{
		label:
		a = _getch();
		if (a >= '0' && a <= '9')
		{
			cout << (char)a;
			sString[nSize++] = (char)a;
		}
		else if (a == 8 && nSize > 0)
		{
			cout << "\b \b";
			sString[(nSize--) - 1] /= 10;
		}
		iResultValue = atoi(sString);
		if (!GettingIntegerRightRange(nFrom, nTo, iResultValue))
		{
			cout << endl << "Number is not in the range!" << endl;
			for (int i = 0; i < nSize; ++i)
				sString[i] = NULL;
			nSize = 0;
			cout << "Please enter the new number: ";
		}
	} while (a != 13);

	if (!GettingIntegerLeftRange(nFrom, nTo, iResultValue))
	{
		cout << endl << "Number is not in the range!" << endl;
		for (int i = 0; i < nSize; ++i)
			sString[i] = NULL;
		nSize = 0;
		cout << "Please enter the new number: ";
		goto label;
	}

	//cout << endl << "Number from char array: ";
	//for (int i = 0; i < nSize; ++i)
	//	cout << sString[i];
	//cout << endl;

	//iResultValue = atoi(sString);
	//cout << "Number convertet into integer is: " << iResultValue << endl;

	cout << endl;
	delete[] sString;

	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}

bool GettingIntegerRightRange(int nFrom, int nTo, int nResult)
{
	if (nResult <= nTo)
		return true;
	else
	{
		return false;
	}
}

bool GettingIntegerLeftRange(int nFrom, int nTo, int nResult)
{
	if (nResult >= nFrom)
		return true;
	else
	{
		return false;
	}
}