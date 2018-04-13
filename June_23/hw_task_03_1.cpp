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
    int iArray1[iArray1Size];
    int iArray2[iArray2Size];

    // Filling and cout Array 1 by the random numbers
    for (int i = 0; i < iArray1Size; ++i)
        iArray1[i] = rand () % 21;
    for (int i = 0; i < iArray1Size; ++i)
        cout << setw(3) << iArray1[i];
    cout << endl;

    // Filling and cout Array 1 by the random numbers
    for (int i = 0; i < iArray2Size; ++i)
        iArray2[i] = rand () % 21;
    for (int i = 0; i < iArray2Size; ++i)
        cout << setw(3) << iArray2[i];
    cout << endl;


    // Finding and cout each number from 1st Array into 2nd Array
    for (int i = 0; i < iArray1Size; ++i)
        for (int j = 0; j < iArray2Size; ++j)
            if (iArray1[i] == iArray2[j])
                cout << setw(3) << iArray1[i];
    cout << endl << endl;

    return 0;
}
