#include <iostream>

using namespace std;

int main()
{
    cout << "Enter two numbers and operator between" << endl;
    cout << "Like this: 2 + 3" << endl;

    double d1, d2, dResult;
    char cOperator;


    cin >> d1 >> cOperator >> d2;

    if ('+' == cOperator)
        dResult = d1 + d2;

    else if ('-' == cOperator)
        dResult = d1 - d2;

    else if ('*' == cOperator)
        dResult = d1 * d2;

    else dResult = d1 / d2;

    cout << "Result: " << d1 << cOperator << d2 << "=" << dResult << endl;

    return 0;
}
