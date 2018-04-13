//

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	cout << "Enter array size: ";
	int nSize;
	cin >> nSize;

	int * pArray = new int[nSize];

	delete[] pArray;

	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}
