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
    int nHight = (nSize * 2) - 1;
    for (int i = 0; i < nHight; ++i)
    {
        for (int j = 0; j < nSpaces; ++j)
            cout << " ";

        for (int j = 0; j < nStars; ++j)
            cout << "*";

        if (i < nHight / 2)
        {
            --nSpaces;
            nStars += 2;
        }
        else
        {
            ++nSpaces;
            nStars -= 2;
        }

        cout << endl;
    }
    cout << endl;

    return 0;
}
