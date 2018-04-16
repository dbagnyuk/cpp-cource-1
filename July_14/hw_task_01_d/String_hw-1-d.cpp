// User input the string
// Output words sorted by length

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <string.h>

using namespace std;

void SortArray(char **ppArray, int *pArray, int nSize);
void OutputArray(char **ppArray, int *pArray, int nSize);
void OutputString(char **ppArray, int nSize);

int main()
{
	const int MAX_COUNT = 10;
	char * ppWords[MAX_COUNT];
	int nLengthArray[MAX_COUNT];

	char sString[200], *pContext;
	int nCount = 0;

	cout << "Please enter the string: ";
	cin.getline(sString, 200); // "A simple several words";
	int nLength = strlen(sString);

	char * pToken = strtok_s(sString, " .,:;", &pContext);

	while (pToken != NULL && nCount < MAX_COUNT)
	{
		nLengthArray[nCount] = strlen(pToken);
		ppWords[nCount++] = pToken;
		pToken = strtok_s(NULL, " .,:;", &pContext);
	}

//	OutputArray(ppWords, nLengthArray, nCount);
	SortArray(ppWords, nLengthArray, nCount);
//	OutputArray(ppWords, nLengthArray, nCount);
	OutputString(ppWords, nCount);

	delete[] * ppWords;
	delete[] pToken;

	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}

void SortArray(char **ppArray, int *pArray, int nSize)
{
	int nTemp;
	char *cTemp;
	for (int i = 0; i < nSize - 1; ++i)
		for (int j = 0; j < nSize - 1; ++j)
			if (pArray[j] > pArray[j + 1])
			{
				nTemp = pArray[j + 1];
				pArray[j + 1] = pArray[j];
				pArray[j] = nTemp;

				cTemp = ppArray[j + 1];
				ppArray[j + 1] = ppArray[j];
				ppArray[j] = cTemp;
			}
}

void OutputArray(char **ppArray, int *pArray, int nSize)
{
	for (int i = 0; i < nSize; ++i)
		cout << ppArray[i] << ' ' << pArray[i] << endl;
	cout << endl << endl;
}

void OutputString(char **ppArray, int nSize)
{
	cout << "Output string: ";
	for (int i = 0; i < nSize; ++i)
		cout << ppArray[i] << ' ';
	cout << endl << endl;
}