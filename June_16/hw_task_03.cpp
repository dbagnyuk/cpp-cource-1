#include <iostream>

using namespace std;

int main()
{
    cout << "Enter side size of the figure: ";
    int nSize;
    cin >> nSize;

    cout << endl;

    int nStars = 1;
    int nSpaces = nSize;
    for (int i = 0; i < nSize; ++i)
    {
        for (int j = 0; j < nSpaces; ++j)
            cout << " ";
        --nSpaces;

        for (int j = 0; j < nStars; ++j)
            cout << "*";

        if (nStars == 1)
        {
            ++nStars;
        }
        else
        {

            for (int j = 0; j < nStars-1; ++j)
                cout << "*";
            ++nStars;
        }

        cout << endl;
    }
    cout << endl;

    return 0;
}
