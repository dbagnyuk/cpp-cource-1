// enter the file name
// Read the array from file

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <io.h>

using namespace std;

enum FileErrorCode { OK, NO_FILE, NO_PERMISSIONS };

int * FileRead(const char * Name, int * pErr, int * Size);
void OutputArray(int * OutputArray, int * Size);
int main()
{

	char sFileName[260];
	cin.getline(sFileName, 260);
	int iErrCode, nArrSize;

	int * pArray = FileRead(sFileName, &iErrCode, &nArrSize);

	if (pArray == 0)
		cout << "Error code: " << iErrCode << endl;

	OutputArray(pArray, &nArrSize);

	delete[] pArray;

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

    return 0;
}

int * FileRead(const char * Name, int * pErr, int * Size)
{
	FILE * file_read; // create the file stream
	errno_t err = fopen_s(&file_read, Name, "rb");

	int * pResArr = 0; // if error then return 0

	if (file_read == NULL)
	{
		*pErr = NO_FILE;
		return pResArr;
	}

	int iID = _fileno(file_read);
	int nBytes = _filelength(iID);
	int nDataSize = nBytes / sizeof(int);
	pResArr = new int[nDataSize];
	fread(pResArr, sizeof(int), nDataSize, file_read);
	fclose(file_read);

	*pErr = OK; // OK
	*Size = nDataSize;
	return pResArr;
}

void OutputArray(int * OutputArray, int * Size)
{
	for (int i = 0; i < *Size; ++i)
		cout << setw(3) << OutputArray[i];
	cout << endl;
}
