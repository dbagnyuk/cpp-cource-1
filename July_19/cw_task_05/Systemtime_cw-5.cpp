#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <string.h>
#include <Windows.h>

using namespace std;

int main()
{

	SYSTEMTIME st1, st2, st3;

	GetLocalTime(&st1);
	//sort1();
	GetLocalTime(&st2);
	//sort2();
	GetLocalTime(&st3);

	int nDiff = st2.wMilliseconds - st1.wMilliseconds;

	int nTime = st1.wMilliseconds + st2.wSecond * 100 + st1.wMinute * 60 * 1000 + st1.wHour * 60 * 60 * 100;

	cout << st1.wMilliseconds << endl;

	cout << nDiff << ' ' << nTime << endl;

	return 0;
}
