#include <iostream>

using namespace std;

//enum

int main()
{
    int sideDefault = 3;
    //int cntFigures = 5;
    int cntFigSpace = 5;
    //int lenString = (3 * 5) + (5 * 5);
    char cDefault = '*';
    char cSpace = ' ';

    cout<<endl;

    int nStarsFig2 = 1;
    int nSpaces2 = cntFigSpace + sideDefault - nStarsFig2;
    int nStarsFig3 = sideDefault;
    int nSpaces3 = cntFigSpace - sideDefault + nStarsFig3;
    int nStarsFig4 = sideDefault;
    int nSpacesFig4 = 0;
    int nSpaces4 = cntFigSpace;
    int nStars1Fig5 = 1;
    int nStars2Fig5 = sideDefault;
    int nSpacesFig5 = 3;

    for (int i = 0; i < sideDefault; ++i)
    {
        // Figure 1
        for (int j = 0; j < sideDefault; ++j)
            cout << cDefault;
        for (int j = 0; j < cntFigSpace; ++j)
            cout << cSpace;

        // Figure 2
        for (int j = 0; j < nStarsFig2; ++j)
            cout << cDefault;
        ++nStarsFig2;
        for (int j = 0; j < nSpaces2; ++j)
            cout << cSpace;
        --nSpaces2;

        // Figure 3
        for (int j = 0; j < nStarsFig3; ++j)
            cout << cDefault;
        --nStarsFig3;
        for (int j = 0; j < nSpaces3; ++j)
            cout << cSpace;
        ++nSpaces3;

        // Figure 4
        for (int j = 0; j < nSpacesFig4; ++j)
            cout << cSpace;
        ++nSpacesFig4;
        for (int j = 0; j < nStarsFig4; ++j)
            cout << cDefault;
        --nStarsFig4;
        for (int j = 0; j < nSpaces4; ++j)
            cout << cSpace;

        // Figure 5
        for (int j = 0; j < nStars1Fig5; ++j)
            cout << cDefault;
        ++nStars1Fig5;
        for (int j = 0; j < nSpacesFig5; ++j)
            cout << cSpace;
        for (int j = 0; j < nStars2Fig5; ++j)
            cout << cDefault;
        --nStars2Fig5;
        for (int j = 0; j < nSpacesFig5; ++j)
            cout << cSpace;
        for (int j = 0; j < 3; ++j)
            cout << cDefault;

        cout<<endl;
    }
    cout<<endl;


    int nFigure;
    int nSize;
    char cChar;

    // Query for User enter and check them
    do
    {
    cout << "Choice the Figure (number between 0 and 9): ";
    cin >> nFigure;
    } while (nFigure < 0 || nFigure > 9);
    do
    {
    cout << "Enter side size (number between 3 and 99) of the figure: ";
    cin >> nSize;
    } while (nSize < 3 || nSize > 99);
    cout << "Enter char for the figure: ";
    cin >> cChar;

    cout << endl;

    switch (nFigure)
    {
        //***
        //***
        //***
        case 0:
        {
            for (int i = 0; i < nSize; ++i)
            {
                cout << cSpace;
                for (int j = 0; j < nSize; ++j)
                    cout << cChar;
                cout << endl;
            }
        }
        break;
        //*
        //**
        //***
        case 1:
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
        break;
        //***
        //**
        //*
        case 2:
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
        break;
        //***
        // **
        //  *
        case 3:
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
        break;
        //*   ***   ***
        //**   **   ***
        //***   *   ***
        case 4:
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
        break;
        //*
        //**
        //***
        //**
        //*
        case 5:
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
                for (int j = 0; j < nStars2-1; ++j)
                    cout << cChar;
                --nStars2;
                cout<<endl;
            }
        }
        break;
        //  *
        // ***
        //*****
        case 6:
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
                    for (int j = 0; j < nStars-1; ++j)
                        cout << cChar;
                    ++nStars;
                }
                cout<<endl;
            }
        }
        break;
        //  *
        // ***
        //*****
        // ***
        //  *
        case 7:
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
        break;
        //*****
        //*   *
        //*   *
        //*   *
        //*****
        case 8:
        {
            int nSide = nSize + 2;
            for (int i = 0; i < nSide; ++i)
            {
                cout << cSpace;
                if (i == 0 || i == nSide-1)
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
        break;
        //*****
        //*   *
        //* 3 *
        //*   *
        //*****
        case 9:
        {
            int nNumber = nSize;
            int nSide = nSize + 2;
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
        break;
    }
    cout << endl;
    return 0;
}
