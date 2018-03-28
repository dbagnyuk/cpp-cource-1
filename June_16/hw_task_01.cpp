#include <iostream>

using namespace std;

int main()
{
    cout << "Enter side size of the figure: ";
    int nSize;
    cin >> nSize;

    cout << endl;

    int nStars1 = 1;
    int nStars2 = nSize;
    int nSpaces = 3;
    for (int i = 0; i < nSize; ++i)
    {
        for (int j = 0; j < nStars1; ++j)
            cout << "*";
        ++nStars1;

        for (int j = 0; j < nSpaces; ++j)
            cout << " ";

        for (int j = 0; j < nStars2; ++j)
            cout << "*";
        --nStars2;

        for (int j = 0; j < nSpaces; ++j)
            cout << " ";

        for (int j = 0; j < 3; ++j)
            cout << "*";

        cout << endl;
    }
    cout << endl;

    return 0;
}
