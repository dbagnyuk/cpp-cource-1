#include <iostream>

using namespace std;

void Figure0 (int nSize, char cChar, char cSpace);
void Figure1 (int nSize, char cChar, char cSpace);
void Figure2 (int nSize, char cChar, char cSpace);
void Figure3 (int nSize, char cChar, char cSpace);
void Figure4 (int nSize, char cChar, char cSpace);
void Figure5 (int nSize, char cChar, char cSpace);
void Figure6 (int nSize, char cChar, char cSpace);
void Figure7 (int nSize, char cChar, char cSpace);
void Figure8 (int nSize, char cChar, char cSpace);
void Figure9 (int nSize, char cChar, char cSpace);

int main()
{
    // Default values
    int nSizeDefault = 3;
    char cCharDefault = '*';
    char cSpaceDefault = ' ';


    // List all Figures whith default values
    cout << "0" << endl;
    Figure0(nSizeDefault, cCharDefault, cSpaceDefault);
    cout << endl;
    cout << "1" << endl;
    Figure1(nSizeDefault, cCharDefault, cSpaceDefault);
    cout << endl;
    cout << "2" << endl;
    Figure2(nSizeDefault, cCharDefault, cSpaceDefault);
    cout << endl;
    cout << "3" << endl;
    Figure3(nSizeDefault, cCharDefault, cSpaceDefault);
    cout << endl;
    cout << "4" << endl;
    Figure4(nSizeDefault, cCharDefault, cSpaceDefault);
    cout << endl;
    cout << "5" << endl;
    Figure5(nSizeDefault, cCharDefault, cSpaceDefault);
    cout << endl;
    cout << "6" << endl;
    Figure6(nSizeDefault, cCharDefault, cSpaceDefault);
    cout << endl;
    cout << "7" << endl;
    Figure7(nSizeDefault, cCharDefault, cSpaceDefault);
    cout << endl;
    cout << "8" << endl;
    Figure8(nSizeDefault, cCharDefault, cSpaceDefault);
    cout << endl;
    cout << "9" << endl;
    Figure9(nSizeDefault, cCharDefault, cSpaceDefault);
    cout << endl;

    while (true)
    {
        // Init Users values
        int nFigureNum;
        int nSizeUser;
        char cCharUser;
        char cSpaceUser = ' ';
        char nConfirm;

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
        if (0 == nFigureNum)
            Figure0 (nSizeUser, cCharUser, cSpaceUser);
        else if (1 == nFigureNum)
            Figure1 (nSizeUser, cCharUser, cSpaceUser);
        else if (2 == nFigureNum)
            Figure2 (nSizeUser, cCharUser, cSpaceUser);
        else if (3 == nFigureNum)
            Figure3 (nSizeUser, cCharUser, cSpaceUser);
        else if (4 == nFigureNum)
            Figure4 (nSizeUser, cCharUser, cSpaceUser);
        else if (5 == nFigureNum)
            Figure5 (nSizeUser, cCharUser, cSpaceUser);
        else if (6 == nFigureNum)
            Figure6 (nSizeUser, cCharUser, cSpaceUser);
        else if (7 == nFigureNum)
            Figure7 (nSizeUser, cCharUser, cSpaceUser);
        else if (8 == nFigureNum)
            Figure8 (nSizeUser, cCharUser, cSpaceUser);
        else if (9 == nFigureNum)
            Figure9 (nSizeUser, cCharUser, cSpaceUser);

        cout << endl;

        // chek new enter confirmation
        do
        {
            cout << "For choice enother Figure enter 'y', for exit 'n': ";
            cin >> nConfirm;
        } while (nConfirm != 'n' && nConfirm != 'N' && nConfirm != 'y' && nConfirm != 'Y');
        if (nConfirm == 'n' || nConfirm == 'N')
            break;
    }
    return 0;
}

// Function of Figures

//***
//***
//***
void Figure0 (int nSize, char cChar, char cSpace)
{
    for (int i = 0; i < nSize; ++i)
    {
        cout << cSpace;
        for (int j = 0; j < nSize; ++j)
            cout << cChar;
        cout << endl;
    }
}

//*
//**
//***
void Figure1 (int nSize, char cChar, char cSpace)
{
    int nStars = 1;
    for (int i = 0; i < nSize; ++i)
    {
        cout << cSpace;
        for (int j = 0; j < nStars; ++j)
            cout << cChar;
        ++nStars;
        cout << endl;
    }
}

//***
//**
//*
void Figure2 (int nSize, char cChar, char cSpace)
{
    int nStars = nSize;
    for (int i = 0; i < nSize; ++i)
    {
        cout << cSpace;
        for (int j = 0; j < nStars; ++j)
            cout << cChar;
        --nStars;
        cout<<endl;
    }
}

//***
// **
//  *
void Figure3 (int nSize, char cChar, char cSpace)
{
    int nStars = nSize;
    int nSpaces = 0;
    for (int i = 0; i < nSize; ++i)
    {
        cout << cSpace;
        for (int j = 0; j < nSpaces; ++j)
            cout << cSpace;
        ++nSpaces;

        for (int j = 0; j < nStars; ++j)
            cout << cChar;
        --nStars;
        cout << endl;
    }
}

//*   ***   ***
//**   **   ***
//***   *   ***
void Figure4 (int nSize, char cChar, char cSpace)
{
    int nStars1 = 1;
    int nStars2 = nSize;
    int nSpaces = 3;
    for (int i = 0; i < nSize; ++i)
    {
        cout << cSpace;
        for (int j = 0; j < nStars1; ++j)
            cout << cChar;
        ++nStars1;

        for (int j = 0; j < nSpaces; ++j)
            cout << cSpace;

        for (int j = 0; j < nStars2; ++j)
            cout << cChar;
        --nStars2;

        for (int j = 0; j < nSpaces; ++j)
            cout << cSpace;

        for (int j = 0; j < 3; ++j)
            cout << cChar;

        cout<<endl;
    }
}

//*
//**
//***
//**
//*
void Figure5 (int nSize, char cChar, char cSpace)
{
    int nStars1 = 1;
    int nStars2 = nSize;
    for (int i = 0; i < nSize; ++i)
    {
        cout << cSpace;
        for (int j = 0; j < nStars1; ++j)
            cout << cChar;
        ++nStars1;
        cout << endl;
    }
    for (int i = 0; i < nSize; ++i)
    {
        cout << cSpace;
        for (int j = 0; j < nStars2 - 1; ++j)
            cout << cChar;
        --nStars2;
        cout<<endl;
    }
}

//  *
// ***
//*****
void Figure6 (int nSize, char cChar, char cSpace)
{
    int nStars = 1;
    int nSpaces = nSize;
    for (int i = 0; i < nSize; ++i)
    {
        for (int j = 0; j < nSpaces; ++j)
            cout << cSpace;
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
}

//  *
// ***
//*****
// ***
//  *
void Figure7 (int nSize, char cChar, char cSpace)
{
    int nStars = 1;
    int nSpaces = nSize;
    int nHight = (nSize * 2) - 1;
    for (int i = 0; i < nHight; ++i)
    {
        for (int j = 0; j < nSpaces; ++j)
            cout << cSpace;

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
}

//*****
//*   *
//*   *
//*   *
//*****
void Figure8 (int nSize, char cChar, char cSpace)
{
    int nSide = nSize + 2;
    for (int i = 0; i < nSide; ++i)
    {
        cout << cSpace;
        if (i == 0 || i == nSide - 1)
        {
            for (int j = 0; j < nSide; ++j)
                cout << cChar;
        }
        else
        {
            cout << cChar;
            for (int j = 0; j < nSize; ++j)
                cout << cSpace;
            cout << cChar;
        }
        cout << endl;
    }
}

//*****
//*   *
//* 3 *
//*   *
//*****
void Figure9 (int nSize, char cChar, char cSpace)
{
    int nNumber = nSize;
    int nSide = nSize+2;
    for (int i = 0; i < nSide; ++i)
    {
        cout << cSpace;
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
                        cout << cSpace;
                    cout << nNumber;
                    for (int j = (nSize / 2) + 2; j < nSize; ++j)
                        cout << cSpace;
                }
                else
                {
                    for (int j = 0; j < (nSize / 2); ++j)
                        cout << cSpace;
                    cout<<nNumber;
                    for (int j = (nSize / 2) + 1; j < nSize; ++j)
                        cout << cSpace;
                }
            cout << cChar;
        }
        else
        {
            cout << cChar;
            for (int j = 0; j < nSize; ++j)
                cout << cSpace;
            cout << cChar;
        }
        cout << endl;
    }
}
