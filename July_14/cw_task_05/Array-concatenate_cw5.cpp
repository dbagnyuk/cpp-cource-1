// concatinate two arrays into third array
//

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int nSize1 = 10, nSize2 = 20;
	int * pAr1 = new int[nSize1];
	int * pAr2 = new int[nSize2];
	int * pArRes = new int[nSize1 + nSize2];

	for (int i = 0; i < nSize1; ++i)
		pAr1[i] = rand() % 10;

	for (int i = 0; i < nSize2; ++i)
		pAr2[i] = rand() % 10;

	memcpy(pArRes, pAr1, sizeof(int) * nSize1);
	memcpy(pArRes + nSize1, pAr2, sizeof(int) * nSize2);

	for (int i = 0; i < nSize1; ++i)
		cout << pAr1[i] << ' ';
	cout << endl;

	for (int i = 0; i < nSize2; ++i)
		cout << pAr2[i] << ' ';
	cout << endl;

	for (int i = 0; i < nSize1 + nSize2; ++i)
		cout << pArRes[i] << ' ';
	cout << endl;

	cout << endl;

	// free memory
	delete[] pAr1;
	delete[] pAr2;
	delete[] pArRes;

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;



	return 0;
}
