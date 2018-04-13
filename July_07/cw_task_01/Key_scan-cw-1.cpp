// Key_scan-cw-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int a = 5;
	while (a != 27) // Escape
	{
		a = _getch();
		cout << a << endl;
	}

    return 0;
}
