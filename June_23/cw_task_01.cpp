#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand ((unsigned int) time(0));

    int iArray[10];

    for (int i = 0; i < 10; ++i)
        iArray[i] = rand () % 21;

    for (int i = 0; i < 10; ++i)
        cout << iArray[i] << ' ';
    cout << endl;

    int nMin = iArray[0];
    for (int i = 1; i < 10; ++i)
        if (iArray[i] < nMin)
            nMin = iArray[i];
    cout << "Min: " << nMin << endl;

    cout << endl;
    return 0;
}
