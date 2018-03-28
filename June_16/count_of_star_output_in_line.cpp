#include <iostream>

using namespace std;

int main()
{
    cout << "Enter " << endl;
    int nSize;
    cin >> nSize;

    cout << endl;

    for (int i = 0; i < nSize; ++i)
    {
        for (int j = 0; j < nSize; ++j)
            cout << "*";

        cout << endl;
    }
    cout << endl;

    return 0;
}
