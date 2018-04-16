// User input the string
// count the numbers of words in string

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <string.h>

using namespace std;

int main()
{
	int nCountWords = 1;
	int nCountCharacters = 0;
	int nStringSize = 100;
	char * sString = new char[nStringSize];
	int * nCntChar = new int[nCountWords];
	char ** sWords = new char *[nCountWords];

	cout << "Please enter the sentence and press Enter: ";

	cin.getline(sString, nStringSize + 1);
	sString[strlen(sString) + 1] = '\0';
	nStringSize = strlen(sString);

	cout << sString << endl << nStringSize << endl;

	int i = 0, j = 0, k = 0;
	sWords[j] = new char[nCountCharacters];
	while (sString[i] != '\0')
	{
		if (isalpha(sString[i]))
		{
			++nCountCharacters;
			nCntChar[j] = nCountCharacters;
			sWords[j][k] = sString[i];
			++k;
		}
		else if (isspace(sString[i]))
		{
			sWords[j][k] = '\0';
			++nCountWords;
			nCountCharacters = 0;
			k = 0;
			++j;
			sWords[j] = new char[nCountCharacters];
		}
		++i;
	}

	cout << nCountWords << endl;

	for (int i = 0; i < nCountWords; ++i)
		cout << nCntChar[i] << ' ';
	cout << endl;

	for (int i = 0; i < nCountWords; ++i)
	{
		for (int j = 0; j < nCntChar[i]; ++j)
			cout << (char)sWords[i][j];
		cout << endl;
	}

	//for (int i = 0; i < nStringSize; ++i)
	//	cout << (char)sString[i];

	cout << endl;
	for (int i = 0; i < nCountWords; ++i)
		delete[] sWords[i];
	delete[] sWords;
	delete[] sString;
	delete[] nCntChar;

	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}
