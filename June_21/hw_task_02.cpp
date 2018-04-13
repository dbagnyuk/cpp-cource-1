#include <iostream>

using namespace std;

void Figure0 (int nSize, char cChar);
void Figure1 (int nSize, char cChar);
void Figure2 (int nSize, char cChar);
void Figure3 (int nSize, char cChar);
void Figure4 (int nSize, char cChar);
void Figure5 (int nSize, char cChar);
void Figure6 (int nSize, char cChar);
void Figure7 (int nSize, char cChar);
void Figure8 (int nSize, char cChar);
void Figure9 (int nSize, char cChar);

int main()
{
    // Default values
    int nSizeDefault = 3;
    char cCharDefault = '*';

    // List all Figures whith default values
    cout << "0" << endl;
    Figure0(nSizeDefault, cCharDefault);
    cout << endl;
    cout << "1" << endl;
    Figure1(nSizeDefault, cCharDefault);
    cout << endl;
    cout << "2" << endl;
    Figure2(nSizeDefault, cCharDefault);
    cout << endl;
    cout << "3" << endl;
    Figure3(nSizeDefault, cCharDefault);
    cout << endl;
    cout << "4" << endl;
    Figure4(nSizeDefault, cCharDefault);
    cout << endl;
    cout << "5" << endl;
    Figure5(nSizeDefault, cCharDefault);
    cout << endl;
    cout << "6" << endl;
    Figure6(nSizeDefault, cCharDefault);
    cout << endl;
    cout << "7" << endl;
    Figure7(nSizeDefault, cCharDefault);
    cout << endl;
    cout << "8" << endl;
    Figure8(nSizeDefault, cCharDefault);
    cout << endl;
    cout << "9" << endl;
    Figure9(nSizeDefault, cCharDefault);
    cout << endl;

    // Init Users values
    int nFigureNum;
    int nSizeUser;
    char cCharUser;

    // Query for User enter and check them
    do
    {
    cout << "Choice the Figure (number between 0 and 9): ";
    cin >> nFigureNum;
    } while (nFigureNum < 0 || nFigureNum > 9);
    do
    {
    cout << "Enter side size (number between 3 and 99) of the figure: ";
    cin >> nSizeUser;
    } while (nSizeUser < 3 || nSizeUser > 99);
    cout << "Enter char for the figure: ";
    cin >> cCharUser;

    cout << endl;


    // list the Figure that User choise
    if (nFigureNum == 0)
    Figure0 (nSizeUser, cCharUser);

    else if (nFigureNum == 1)
    Figure1 (nSizeUser, cCharUser);

    else if (nFigureNum == 2)
    Figure2 (nSizeUser, cCharUser);

    else if (nFigureNum == 3)
    Figure3 (nSizeUser, cCharUser);

    else if (nFigureNum == 4)
    Figure4 (nSizeUser, cCharUser);

    else if (nFigureNum == 5)
    Figure5 (nSizeUser, cCharUser);

    else if (nFigureNum == 6)
    Figure6 (nSizeUser, cCharUser);

    else if (nFigureNum == 7)
    Figure7 (nSizeUser, cCharUser);

    else if (nFigureNum == 8)
    Figure8 (nSizeUser, cCharUser);

    else if (nFigureNum == 9)
    Figure9 (nSizeUser, cCharUser);

    cout << endl;
    return 0;
}

// Function of Figures

//***
//***
//***
void Figure0 (int nSize, char cChar)
{
    for (int i = 0; i < nSize; ++i)
    {
        cout << " ";
        for (int j = 0; j < nSize; ++j)
            cout << cChar;
        cout << endl;
    }
    return;
}

//*
//**
//***
void Figure1 (int nSize, char cChar)
{
    int nStars = 1;
    for (int i = 0; i < nSize; ++i)
    {
        cout << " ";
        for (int j = 0; j < nStars; ++j)
            cout << cChar;
        ++nStars;
        cout << endl;
    }
    return;
}

//***
//**
//*
void Figure2 (int nSize, char cChar)
{
    int nStars = nSize;
    for (int i = 0; i < nSize; ++i)
    {
        cout << " ";
        for (int j = 0; j < nStars; ++j)
            cout << cChar;
        --nStars;
        cout<<endl;
    }
    return;
}

//***
// **
//  *
void Figure3 (int nSize, char cChar)
{
    int nStars = nSize;
    int nSpaces = 0;
    for (int i = 0; i < nSize; ++i)
    {
        cout << " ";
        for (int j = 0; j < nSpaces; ++j)
            cout << " ";
        ++nSpaces;

        for (int j = 0; j < nStars; ++j)
            cout << cChar;
        --nStars;
        cout << endl;
    }
    return;
}

//*   ***   ***
//**   **   ***
//***   *   ***
void Figure4 (int nSize, char cChar)
{
    int nStars1 = 1;
    int nStars2 = nSize;
    int nSpaces = 3;
    for (int i = 0; i < nSize; ++i)
    {
        cout << " ";
        for (int j = 0; j < nStars1; ++j)
            cout << cChar;
        ++nStars1;

        for (int j = 0; j < nSpaces; ++j)
            cout << " ";

        for (int j = 0; j < nStars2; ++j)
            cout << cChar;
        --nStars2;

        for (int j = 0; j < nSpaces; ++j)
            cout << " ";

        for (int j = 0; j < 3; ++j)
            cout << cChar;

        cout<<endl;
    }
    return;
}

//*
//**
//***
//**
//*
void Figure5 (int nSize, char cChar)
{
    int nStars1 = 1;
    int nStars2 = nSize;
    for (int i = 0; i < nSize; ++i)
    {
        cout << " ";
        for (int j = 0; j < nStars1; ++j)
            cout << cChar;
        ++nStars1;
        cout << endl;
    }
    for (int i = 0; i < nSize; ++i)
    {
        cout << " ";
        for (int j = 0; j < nStars2 - 1; ++j)
            cout << cChar;
        --nStars2;
        cout<<endl;
    }
    return;
}

//  *
// ***
//*****
void Figure6 (int nSize, char cChar)
{
    int nStars = 1;
    int nSpaces = nSize;
    for (int i = 0; i < nSize; ++i)
    {
        for (int j = 0; j < nSpaces; ++j)
            cout << " ";
        --nSpaces;

        for (int j = 0; j < nStars; ++j)
            cout << cChar;

        if (nStars == 1)
        {
            ++nStars;
        }
        else
        {
            for (int j = 0; j < nStars - 1; ++j)
                cout << cChar;
            ++nStars;
        }
        cout<<endl;
    }
    return;
}

//  *
// ***
//*****
// ***
//  *
void Figure7 (int nSize, char cChar)
{
    int nStars = 1;
    int nSpaces = nSize;
    int nHight = (nSize * 2) - 1;
    for (int i = 0; i < nHight; ++i)
    {
        for (int j = 0; j < nSpaces; ++j)
            cout << " ";

        for (int j = 0; j < nStars; ++j)
            cout << cChar;

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
    return;
}

//*****
//*   *
//*   *
//*   *
//*****
void Figure8 (int nSize, char cChar)
{
    int nSide = nSize + 2;
    for (int i = 0; i < nSide; ++i)
    {
        cout << " ";
        if (i == 0 || i == nSide - 1)
        {
            for (int j = 0; j < nSide; ++j)
                cout << cChar;
        }
        else
        {
            cout << cChar;
            for (int j = 0; j < nSize; ++j)
                cout << " ";
            cout << cChar;
        }
        cout << endl;
    }
    return;
}

//*****
//*   *
//* 3 *
//*   *
//*****
void Figure9 (int nSize, char cChar)
{
    int nNumber = nSize;
    int nSide = nSize + 2;
    for (int i = 0; i < nSide; ++i)
    {
        cout << " ";
        if (i == 0 || i == nSide - 1)
        {
            for (int j = 0; j < nSide; ++j)
                cout << cChar;
        }
        else if (i == (nSize / 2) + 1)
        {
            cout << cChar;
                if (nSize > 9)
                {
                    for (int j = 0; j < (nSize / 2); ++j)
                        cout << " ";
                    cout << nNumber;
                    for (int j = (nSize / 2) + 2; j < nSize; ++j)
                        cout << " ";
                }
                else
                {
                    for (int j = 0; j < (nSize / 2); ++j)
                        cout << " ";
                    cout<<nNumber;
                    for (int j = (nSize / 2) + 1; j < nSize; ++j)
                        cout << " ";
                }
            cout << cChar;
        }
        else
        {
            cout << cChar;
            for (int j = 0; j < nSize; ++j)
                cout<<" ";
            cout << cChar;
        }
        cout << endl;
    }
    return;
}
