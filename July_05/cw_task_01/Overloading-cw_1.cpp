// Overloading-cw_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <math.h>

using namespace std;

void Rect(int nSizeIn);
void Rect(int nSizeIn, char cBorderIn);
void Rect(char cBorderIn, int nSizeIn);


void main()
{
	int nSize = 5;
	char cBarder = '$';

	Rect(nSize);
	Rect(nSize, cBarder);
	Rect(cBarder, nSize);

}

void Rect(int nSize)
{
	cout << "void Rect(int nSize)" << endl;
}

void Rect(int nSize, char cBorderIn)
{
	cout << "void Rect(int nSize, char cBorderIn)" << endl;
}

void Rect(char cBorderIn, int nSize)
{
	cout << "void Rect(char cBorderIn, int nSize)" << endl;
}
