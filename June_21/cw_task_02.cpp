#include <iostream>

using namespace std;

int main()
{
    double d1, d2, dResult;
    char cOperator;
    char nConfirm;

    while (true)
    {
        cout << "Enter two numbers and operator between" << endl;
        cout << "Like this: 2 + 3" << endl;
        cin >> d1 >> cOperator >> d2;
        if ('+' == cOperator)
            dResult = d1 + d2;
        else if ('-' == cOperator)
            dResult = d1 - d2;
        else if ('*' == cOperator)
            dResult = d1 * d2;
        else
            dResult = d1 / d2;

        cout << "Result: " << d1 << cOperator << d2 << "=" << dResult << endl;

        do
        {
            cout << "For continue enter 'y', for exit 'n': ";
            cin >> nConfirm;
        } while (nConfirm != 'n' && nConfirm != 'N' && nConfirm != 'y' && nConfirm != 'Y');
        if (nConfirm == 'n' || nConfirm == 'N')
            break;
    }

    return 0;
}
