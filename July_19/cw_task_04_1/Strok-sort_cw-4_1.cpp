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

void SortArray(int *pArray, int nSize);
void OutputArray(char *ppArray, int *pArray, int nSize);

int main()
{
	const int MAX_COUNT = 10;
	char * ppWords[MAX_COUNT];
	int nLengthArray[MAX_COUNT];

	char sString[200], *pContext;
	int nCount = 0;

	cin.getline(sString, 200); // "A simple several words";
	int nLength = strlen(sString);

	char * pToken = strtok_s(sString, " .,:;", &pContext);

	while (pToken != NULL && nCount < MAX_COUNT)
	{
		nLengthArray[nCount] = strlen(pToken);
		ppWords[nCount++] = pToken;
		cout << pToken << endl;
		pToken = strtok_s(NULL, " .,:;", &pContext);
	}
	cout << endl;

	//for (int i = 0; i < nCount; ++i)
	//	cout << ppWords[i] << ' ' << nLengthArray[i] << endl;
	//cout << endl << endl;

	OutputArray(*ppWords, nLengthArray, nCount);
	SortArray(nLengthArray, nCount);
	OutputArray(*ppWords, nLengthArray, nCount);

	//for (int i = 0; i < nCount; ++i)
	//	cout << ppWords[i] << ' ' << nLengthArray[i] << endl;
	//cout << endl << endl;

	for (int i = 0; i < nLength; ++i)
		cout << sString[i];
	cout << endl << endl;

	return 0;
}


void SortArray(int *pArray, int nSize)
{
	int nTemp;
	//char *cTemp;
	for (int i = 0; i < nSize - 1; ++i)
		for (int j = 0; j < nSize - 1; ++j)
			if (pArray[j] > pArray[j + 1])
			{
				nTemp = pArray[j + 1];
				//cTemp = ppWords[j + 1];
				pArray[j + 1] = pArray[j];
				//ppWords[j + 1] = ppWords[j];
				pArray[j] = nTemp;
				//ppWords[j] = cTemp;
			}
}

void OutputArray(char *ppArray, int *pArray, int nSize)
{
	for (int i = 0; i < nSize; ++i)
		cout << ppArray[i] << ' ' << pArray[i] << endl;
	cout << endl << endl;
}