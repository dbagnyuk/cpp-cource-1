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
	const int MAX_COUNT = 5;
	char * ppWords[MAX_COUNT];

	char sString[200], *pContext;
	int nCount = 0;

	cin.getline(sString, 200); // "A simple several words";
	int nLength = strlen(sString);

	char * pToken = strtok_s(sString, " .,:", &pContext);

	while (pToken != NULL && nCount < MAX_COUNT)
	{
		ppWords[nCount++] = pToken;
		cout << pToken << ' ' << nCount << endl;
		pToken = strtok_s(NULL, " .,:", &pContext);
	}
	cout << endl;

	for (int i = nCount - 1; i >= 0; --i)
		cout << ppWords[i] << ' ';
	cout << endl << endl;

	for (int i = 0; i < nLength; ++i)
		cout << sString[i];
	cout << endl << endl;

	return 0;
}
