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
	const int MAX_COUNT = 20;
	char * ppWords[MAX_COUNT];
	int nLengthArray[MAX_COUNT];

	char sString[200], *pContext;
	int nCount = 0;

	cout << "Please enter the string: ";
	cin.getline(sString, 200); // "A simple several words";
	int nLength = strlen(sString);

	char * pToken = strtok_s(sString, " .,:", &pContext);

	while (pToken != NULL && nCount < MAX_COUNT)
	{
		nLengthArray[nCount] = strlen(pToken);
		ppWords[nCount++] = pToken;
		pToken = strtok_s(NULL, " .,:", &pContext);
	}

	cout << "The count fo words in string are: " << nCount << endl << endl;

	delete[] * ppWords;
	delete[] pToken;

	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}
