#include <iostream>

using namespace std;

int main()
{
    double d1, d2, dResult;
    char cOperator;
    char nConfirm;

    while (true)
    {
        // input data block
        cout << "Enter two numbers and operator between" << endl;
        cout << "Like this: 2 + 3 " << endl;
        cin >> d1 >> cOperator >> d2;

        // logic block
        int iErrCode = 0;
        // 0 - OK
        // 1 - Zero division
        // 2 - Wrong operation sign
        if ('+' == cOperator)
            dResult = d1 + d2;
        else if ('-' == cOperator)
            dResult = d1 - d2;
        else if ('*' == cOperator)
            dResult = d1 * d2;
        else if ('/' == cOperator)
            {
            if (d2 == 0)
                iErrCode = 1;
            else
                dResult = d1 / d2;
            }
        else
            iErrCode = 2;

        // output data block
        if (iErrCode == 0)
            cout << "Result: " << d1 << cOperator << d2 << "=" << dResult << endl;
        else if (iErrCode == 1)
            cout << "Err: Zero division" << endl;
        else
            cout << "Err: Wrong operation sign" << endl;
        cout << endl;

        // chek new enter confirmation
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
