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
    const int iArray3Size = iArray2Size;
    int iArray1[iArray1Size]; // Array size 10
    int iArray2[iArray2Size]; // Array size 20
    int iArray3[iArray3Size]; // Array for results

    // Filling and cout Array 1 by the random numbers
    for (int i = 0; i < iArray1Size; ++i)
        iArray1[i] = rand () % 21;
    cout << "10 numbers Array: ";
    for (int i = 0; i < iArray1Size; ++i)
        cout << setw(3) << iArray1[i];
    cout << endl;

    // Filling and cout Array 1 by the random numbers
    for (int j = 0; j < iArray2Size; ++j)
        iArray2[j] = rand () % 21;
    cout << "20 numbers Array: ";
    for (int j = 0; j < iArray2Size; ++j)
        cout << setw(3) << iArray2[j];
    cout << endl;

    // Filling Array 3 (result) by 0
    for (int k = 0; k < iArray3Size; ++k)
        iArray3[k] = false;

    // Finding and write into new Array3 each number from 1st Array into 2nd Array
    for (int i = 0; i < iArray1Size; ++i)
        for (int j = 0; j < iArray2Size; ++j)
            if (iArray1[i] == iArray2[j])
            {
                int nExist = 0;
                for (int k = 0; k < iArray3Size; ++k)
                    if (iArray1[i] == iArray3[k])
                        ++nExist;
                if (0 == nExist)
                        iArray3[j] = iArray1[i];
            }

    cout << "Result Array:     ";
    for (int k = 0; k < iArray3Size; ++k)
        if (iArray3[k] == false)
            cout << setw(3) << " ";
        else
            cout << setw(3) << iArray3[k];
    cout << endl << endl;

    return 0;
}
