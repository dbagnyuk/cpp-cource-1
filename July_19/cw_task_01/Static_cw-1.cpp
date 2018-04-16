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

void Func();

int main()
{
	for (int i = 0; i < 10; ++i)
		Func();
		cout << endl;
	return 0;
}

void Func()
{
	int a(0);
	static int nStat = 0;
	cout << ++a << ' ' << ++nStat << endl;
}