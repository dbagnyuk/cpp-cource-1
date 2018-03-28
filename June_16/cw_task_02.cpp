#include <iostream>
using namespace std;

int main()
{
    cout << "Enter " << endl;
    int nSize;
    cin >> nSize;

    cout << endl;

    int nStars = 1;
    for (int i = 0; i < nSize; ++i)
    {
        for (int j = 0; j < nStars; ++j)
            cout << "*";

        ++nStars;
        cout << endl;
    }
    cout << endl;

    return 0;
}
