#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

int main()
{
    srand ((unsigned int) time(0));

    const int iArray1Size = 10; // constant for aray size
    const int iArray2Size = 20;
    const int iArray3Size = 50;
    int iArray1[iArray1Size]; // Array size 10
    int iArray2[iArray2Size]; // Array size 20
    int iArray3[iArray3Size]; // Array for results
    int nCountEquals = 0;

    // Filling and cout Array 1 by the random numbers
    for (int i = 0; i < iArray1Size; ++i)
        iArray1[i] = rand () % 21;
    cout << "10 numbers Array: ";
    for (int i = 0; i < iArray1Size; ++i)
        cout << setw(3) << iArray1[i];
    cout << endl;

    // Filling and cout Array 1 by the random numbers
    for (int i = 0; i < iArray2Size; ++i)
        iArray2[i] = rand () % 21;
    cout << "20 numbers Array: ";
    for (int i = 0; i < iArray2Size; ++i)
        cout << setw(3) << iArray2[i];
    cout << endl;

    // Filling Array 3 (result) by 0
    for (int i = 0; i < iArray3Size; ++i)
        iArray3[i] = 0;

    // Finding and write into new Array3 each number from 1st Array in 2nd Array
    for (int i = 0; i < iArray1Size; ++i)
        for (int j = 0; j < iArray2Size; ++j)
            if (iArray1[i] == iArray2[j])
            {
                iArray3[nCountEquals] = iArray2[j];
                ++nCountEquals;
            }

    cout << "Result Array:     ";
    for (int i = 0; i < nCountEquals; ++i)
        cout << setw(3) << iArray3[i];
    cout << endl << endl;

    return 0;
}
