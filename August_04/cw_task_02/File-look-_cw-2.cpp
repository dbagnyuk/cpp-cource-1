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
#include <windows.h>

using namespace std;

int main()
{
	WIN32_FIND_DATA wf;
	HANDLE hFile = FindFirstFile("C:\\*.*", &wf);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		cout << "Nothing" << endl;
		return 0;
	}

	BOOL bOK = TRUE;

	while (bOK)
	{
		if (wf.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			cout << "   ";
		else
			cout << "          ";
		cout << wf.cFileName << endl;

		bOK = FindNextFile(hFile, &wf);
	}

	cout << endl;
	return 0;
}
