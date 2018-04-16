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

#define NAME_SIZE 20

using namespace std;

struct Students
{
	char Names[NAME_SIZE];
	int Rating;
};

void InitStudents(Students * pStAr, int nSize);
void OutputStudents(Students * pStAr, int nSize);

int main()
{
	int StudentsCount = 10;
	Students * pStudentsArray = new Students[StudentsCount];

	InitStudents(pStudentsArray, StudentsCount);
	OutputStudents(pStudentsArray, StudentsCount);

	delete[] pStudentsArray;

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}

void InitStudents(Students * pStAr, int nSize)
{
	static char * sNames[] = { "Bill","Jim","Bob","Mery" };
	int iInd, sNamesCount = sizeof(sNames) / sizeof(char *);
	int nLen, nMinLen;

	for (int i = 0; i < nSize; ++i)
	{
		iInd = rand() % sNamesCount;
		nLen = strlen(sNames[iInd]) + 1;

		if (nLen < NAME_SIZE)
			nMinLen = nLen;
		else
			nMinLen = NAME_SIZE;

		memcpy(pStAr[i].Names, sNames[iInd], nMinLen);
		pStAr[i].Names[nMinLen - 1] = 0;
	}
}

void OutputStudents(Students * pStAr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
		cout << setw(NAME_SIZE) << pStAr[i].Names << endl;
	cout << endl;
}