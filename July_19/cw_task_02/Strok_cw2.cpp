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
	char sString[200], *pContext;
	int nCount = 0;
	cin.getline(sString, 200); // "A simple several words";
	int nLength = strlen(sString);

	char * pToken = strtok_s(sString, " .,:", &pContext);

	while (pToken != NULL)
	{
		cout << pToken << ' ' << ++nCount << endl;
		pToken = strtok_s(NULL, " .,:", &pContext);
	}

	for (int i = 0; i < nLength; ++i)
		cout << sString[i];
	cout << endl;
	return 0;
}
