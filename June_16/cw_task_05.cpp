#include <iostream>
using namespace std;

int main()
{
    int first, second;
    cout << "Enter the first number"<<endl;
    cin >> first;
    cout << "Enter the second number"<<endl;
    cin >> second;


    if (first > second)
    {
        int tmp = second;
        second = first;
        first = tmp;
    }

    cout << endl;
    cout << "Numbers: ";

    int c = 0;
    for (int i=first; i<=second; i++)
    {
        if (i%2 == 0)
        {
            c++;
            cout << i << " ";
        }
    }

    cout << endl << "Count of numbers: " << c << endl;

    return 0;
}
