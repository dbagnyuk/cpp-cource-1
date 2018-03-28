#include <iostream>

using namespace std;

int main()
{
    cout << "Enter side size of the figure: ";
    int nSize;
    cin >> nSize;

    cout << endl;

    int nStarsUp = 1;
    int nSpacesUp = nSize;
    for (int i = 0; i < nSize; ++i)
    {
        for (int j = 0; j < nSpacesUp; ++j)
            cout << " ";
        --nSpacesUp;

        for (int j = 0; j < nStarsUp; ++j)
            cout << "*";

        if (nStarsUp == 1)
        {
            ++nStarsUp;
        }
        else
        {

            for (int j = 0; j < nStarsUp-1; ++j)
                cout << "*";
            ++nStarsUp;
        }

        cout << endl;
    }

    int nStarsDwn = nSize;
    int nSpacesDwn = 1;
    for (int i = 0; i < nSize; ++i)
    {
        for (int j = 0; j < nSpacesDwn+1; ++j)
            cout << " ";
        ++nSpacesDwn;

        for (int j = 0; j < nStarsDwn-1; ++j)
            cout << "*";

        for (int j = 0; j < nStarsDwn-2; ++j)
            cout << "*";
        --nStarsDwn;

        cout << endl;
    }
    cout << endl;

    return 0;
}
