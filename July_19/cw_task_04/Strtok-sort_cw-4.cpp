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

	for (int i = 0; i < nCount; ++i)
		cout << ppWords[i] << ' ' << nLengthArray[i] << endl;
	cout << endl << endl;

	int nTemp;
	char *cTemp;
	for (int i = 0; i < nCount - 1; ++i)
		for (int j = 0; j < nCount - 1; ++j)
			if (nLengthArray[j] > nLengthArray[j + 1])
			{
				nTemp = nLengthArray[j + 1];
				nLengthArray[j + 1] = nLengthArray[j];
				nLengthArray[j] = nTemp;

				cTemp = ppWords[j + 1];
				ppWords[j + 1] = ppWords[j];
				ppWords[j] = cTemp;
			}

	for (int i = 0; i < nCount; ++i)
		cout << ppWords[i] << ' ' << nLengthArray[i] << endl;
	cout << endl << endl;


	for (int i = 0; i < nLength; ++i)
		cout << sString[i];
	cout << endl << endl;

	return 0;
}
