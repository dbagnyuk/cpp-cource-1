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
    for (int i = 0; i < nSize; ++i)
    {
        for (int j = 0; j < nStars1; ++j)
            cout << "*";
        ++nStars1;

        cout << endl;
    }
    for (int i = 0; i < nSize; ++i)
    {
        for (int j = 0; j < nStars2-1; ++j)
            cout << "*";
        --nStars2;

        cout << endl;
    }

    cout << endl;

    return 0;
}
