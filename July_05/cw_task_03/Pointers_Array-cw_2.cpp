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
	const int nSize = 10;
	int iArray[nSize] = { 10,20,30,40,50,60,70,80,90,95};

	cout << iArray << endl;

	for (int i = 0; i < nSize; ++i)
	{
		cout << i << ' ' << iArray[i] << ' ' << *(iArray + i) << ' ' << &iArray[i] << ' ' << iArray + i << endl;
	}
	return 0;
}

