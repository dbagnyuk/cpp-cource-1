#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{

    srand ((unsigned int) time(0));

    int iArray[20];

    for (int i = 0; i < 20; ++i)
        iArray[i] = rand () % 20;

    for (int i = 0; i < 20; ++i)
        cout << iArray[i] << ' ';
    cout << endl;

    int nCountEven = 0;
    for (int i = 0; i < 20; ++i)
        {
            if (iArray[i] % 2 == 0)
                nCountEven++;
        }

    int nCountOdd = 0;
    for (int i = 0; i < 20; ++i)
        {
            if (iArray[i] % 2 != 0)
                nCountOdd++;
        }

    cout <<"Count Even numbers: " << nCountEven << "; "<< "Count Odd numbers: "<< nCountOdd << endl;

    if (nCountEven > nCountOdd)
        cout << "Count of Even numbers more than count of Odd numbers.";
    else if (nCountEven < nCountOdd)
        cout << "Count of Odd numbers more than count of Even number.";
    else
        cout << "Count of Even and Odd numbers is equal.";

    cout << endl << endl;

    return 0;
}

