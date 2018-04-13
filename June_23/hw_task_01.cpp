#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{

    srand ((unsigned int) time(0));

    int iArray[20];

    for (int i = 0; i < 20; ++i)
        iArray[i] = rand () % 21;

    for (int i = 0; i < 20; ++i)
        cout << iArray[i] << ' ';

    cout << endl;

    int iMin = iArray[0];
    int iMinPosition = 0;
    for (int i = 1; i < 20; ++i)
        if (iMin > iArray[i])
        {
            iMin = iArray[i];
            iMinPosition = i;
        }
    int iMax = iArray[0];
    int iMaxPosition = 0;
    for (int i = 1; i < 20; ++i)
        if (iMax < iArray[i])
        {
            iMax = iArray[i];
            iMaxPosition = i;
        }

    cout <<"Min: " << iMin << "; "<< "Max: "<< iMax << endl;

    if (iMinPosition < iMaxPosition)
    {
        for (int i = iMinPosition; i <= iMaxPosition; ++i)
            cout << iArray[i] << ' ';
    }
    else
    {
        for (int i = iMaxPosition; i <= iMinPosition; ++i)
            cout << iArray[i] << ' ';
    }

    cout << endl;

    return 0;
}
