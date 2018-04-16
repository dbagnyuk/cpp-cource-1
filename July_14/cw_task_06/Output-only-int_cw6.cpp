// Output-only-int_cw6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int a = 12;
	while (a != 27)
	{
		a = _getch();
		if (a >= '0' && a <= '9')
			cout << (char)a;
	}
	cout << endl;

    return 0;
}

