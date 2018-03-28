#include <iostream>

using namespace std;

int main()
{
    int nSize;
    do
    {
    cout << "Enter side size (number between 3 and 99) of the figure: ";
    cin >> nSize;
    } while (nSize < 3 || nSize > 99);

    cout<<endl;

    int nNumber = nSize;
    int nSide = nSize + 2;
    for (int i = 0; i < nSide; ++i)
    {
        if (i == 0 || i == nSide - 1)
        {
            for (int j = 0; j < nSide; ++j)
                cout << "*";
        }
        else if (i == (nSize / 2) + 1)
        {
            cout << "*";
                if (nSize > 9)
                {
                    //cout << nDigit << endl;
                    for (int j = 0; j < (nSize / 2); ++j)
                        cout << " ";
                    cout << nNumber;
                    for (int j = (nSize / 2) + 2; j < nSize; ++j)
                        cout << " ";
                }
                else
                {
                    for (int j = 0; j < (nSize / 2); ++j)
                        cout << " ";
                    cout << nNumber;
                    for (int j = (nSize / 2) + 1; j < nSize; ++j)
                        cout << " ";
                }
            cout << "*";
        }
        else
        {
            cout << "*";
            for (int j = 0; j < nSize; ++j)
                cout << " ";
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
