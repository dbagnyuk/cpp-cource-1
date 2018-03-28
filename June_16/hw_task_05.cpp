#include <iostream>

using namespace std;

int main()
{
    cout << "Enter side size of the figure: ";
    int nSize;
    cin >> nSize;

    cout << endl;

    int nSide = nSize + 2;
    for (int i = 0; i < nSide; ++i)
    {
        if (i == 0 || i == nSide - 1)
        {
            for (int j = 0; j < nSide; ++j)
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
