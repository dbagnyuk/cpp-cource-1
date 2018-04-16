// User input the string
// Output the string in backward

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <string.h>

using namespace std;

void BackwardArray(char **ppArray, int *pArray, int nSize);
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
	BackwardArray(ppWords, nLengthArray, nCount);
//	OutputArray(ppWords, nLengthArray, nCount);
	OutputString(ppWords, nCount);

	cout << endl;

	delete[] * ppWords;
	delete[] pToken;

	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}

void BackwardArray(char **ppArray, int *pArray, int nSize)
{
	int nTemp;
	char *cTemp;
	for (int i = 0, j = 1; i < nSize - j; ++i, ++j)
			if (j > i)
			{
				nTemp = pArray[nSize - j];
				pArray[nSize - j] = pArray[i];
				pArray[i] = nTemp;

				cTemp = ppArray[nSize - j];
				ppArray[nSize - j] = ppArray[i];
				ppArray[i] = cTemp;
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