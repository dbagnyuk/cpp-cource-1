// Struct_cw-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <io.h>

using namespace std;

struct Comp
{
	int nProcFreq;
	char sProcName[20];
	int nMemory;
	char sHardName[20];
};

int main()
{

	int a;
	Comp cmp;

	cin >> cmp.nProcFreq;

	Comp cmp2 = { 3300, "Itanium", 16, "WD" };

	cout << cmp2.sProcName << endl;


	int nSize = 5;
	Comp * pCmpArr = new Comp[nSize];

	for (int i = 0; i < nSize; ++i)
	{
		cin >> pCmpArr[i].nProcFreq;
		cin >> pCmpArr[i].sProcName;
		cin >> pCmpArr[i].nMemory;
		cin >> pCmpArr[i].sProcName;
	}


	delete[] pCmpArr;

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

    return 0;
}

