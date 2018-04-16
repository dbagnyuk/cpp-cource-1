// Cource project
// Students

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <io.h>

#define NAME_SIZE 15
#define SURNAME_SIZE 15
#define RATING_COUNT 5
#define COLLUMN_SIZE 19

using namespace std;


struct ColumnName
{
	char CollumnName[COLLUMN_SIZE];
	//	char Col1Name[COLLUMN_SIZE];
	//	char Col2Name[COLLUMN_SIZE];
	//	char ColAge[COLLUMN_SIZE];
	//	char ColRating[COLLUMN_SIZE];
	//	char ColGrade[COLLUMN_SIZE];
};

struct Students
{
	int Student_Number;
	char First_Name[NAME_SIZE];
	char Second_Name[SURNAME_SIZE];
	int Student_Age;
	int Student_Ratings[RATING_COUNT];
	int Student_Grade;
};

void InitHeadOfCollumns(ColumnName * pHeadAr, int nSize);
void OutputHeadOfCollumns(ColumnName * pHeadAr, int nSize);
void InitStudents(Students * pStAr, int nSize);
void OutputStudents(Students * pStAr, int nSize);
void WriteHeadIntoFile(ColumnName * pHeadAr, int nSize, char * Name);
void AppendHeadIntoFile(ColumnName * pHeadAr, int nSize, char * Name);
void WriteStudentsIntoFile(Students * pStAr, int nSize, char * Name);
void AppendStudentsIntoFile(Students * pStAr, int nSize, char * Name);

int main()
{
	int StudentsCount = 10;
	Students * pStudentsArray = new Students[StudentsCount];

	int CollumnsCount = 6;
	ColumnName * pHeadOfCollumns = new ColumnName[CollumnsCount];

	InitHeadOfCollumns(pHeadOfCollumns, CollumnsCount);
	InitStudents(pStudentsArray, StudentsCount);
	OutputHeadOfCollumns(pHeadOfCollumns, CollumnsCount);
	OutputStudents(pStudentsArray, StudentsCount);




	char cFileName[] = "students.course";

	cout << endl << "What do you want to do. R - read, W - write: ";

	int a = _getch();
	system("cls");
	switch (a)
	{
	case 114: //read the file
	{
		FILE * if_open; // create the file stream
		errno_t err = fopen_s(&if_open, cFileName, "rb"); // open the file for write

		if (if_open == NULL)
		{
			cout << "File not exists." << endl;
			break;
		}
		else
		{
			fclose(if_open);

			FILE * file_read; // create the file stream
			errno_t err = fopen_s(&file_read, cFileName, "rb"); // open the file for write
			int iFileID = _fileno(file_read); // file id
			int nLength = _filelength(iFileID); // file size in bytes
			int nFileSize = nLength / sizeof(char);
			char * pReadpArray = new char[nFileSize];
			fread(pReadpArray, sizeof(char), nFileSize, file_read);

			for (int i = 0; i < nFileSize; ++i)
				cout << pReadpArray[i];

			delete[] pReadpArray;
			fclose(file_read);
		}
	} break;
	case 119: // write into the file
	{
		FILE * if_exist; // create the file stream
		errno_t err = fopen_s(&if_exist, cFileName, "rb"); // open the file for write

		if (if_exist != NULL)
		{
			cout << "File already exists! For rewrite press Y, for uppend press U, for exit press N";
			int b = _getch();
			system("cls");
			if (b == 121) // y
			{
				fclose(if_exist);
				WriteHeadIntoFile(pHeadOfCollumns, CollumnsCount, cFileName);
				AppendStudentsIntoFile(pStudentsArray, StudentsCount, cFileName);
			}
			else if (b == 117) // u
			{
				fclose(if_exist);
				FILE * file_read; // create the file stream
				errno_t err = fopen_s(&file_read, cFileName, "rb"); // open the file for write
				int iFileID = _fileno(file_read); // file id
				int nLength = _filelength(iFileID); // file size in bytes
				int nFileSize = nLength / sizeof(int);
				fclose(file_read);

				if (nFileSize == 0) // see if in file exists any information, if not we write the head else we don't
				{
					AppendHeadIntoFile(pHeadOfCollumns, CollumnsCount, cFileName);
					AppendStudentsIntoFile(pStudentsArray, StudentsCount, cFileName);
				}
				else
				{
					AppendStudentsIntoFile(pStudentsArray, StudentsCount, cFileName);
				}
			}
			else if (b == 110) // n
			{
				fclose(if_exist);
				break;
			}
		}
		else
		{
			//fclose(if_exist);
			WriteHeadIntoFile(pHeadOfCollumns, CollumnsCount, cFileName);
			AppendStudentsIntoFile(pStudentsArray, StudentsCount, cFileName);
		}
	} break;
	}



	delete[] pStudentsArray;
	delete[] pHeadOfCollumns;

	// checking memory free
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory OK!" << endl;

	return 0;
}

void InitHeadOfCollumns(ColumnName * pHeadAr, int nSize)
{
	static char * pCollumnsNames[] = { "Number","First Name","Second Name","Age","Rating","Grade" };
	int sNamesCount = sizeof(pCollumnsNames) / sizeof(char *);
	int nLen, nMinLen;

	for (int i = 0; i < nSize; ++i)
	{
		//iInd = rand() % sNamesCount;
		nLen = strlen(pCollumnsNames[i]) + 1;

		if (nLen < COLLUMN_SIZE)
			nMinLen = nLen;
		else
			nMinLen = COLLUMN_SIZE;

		memcpy(pHeadAr[i].CollumnName, pCollumnsNames[i], nMinLen);
		pHeadAr[i].CollumnName[nMinLen - 1] = 0;
	}
}

void OutputHeadOfCollumns(ColumnName * pHeadAr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
		cout << setw(COLLUMN_SIZE) << pHeadAr[i].CollumnName;
	cout << endl << endl;
}

void InitStudents(Students * pStAr, int nSize)
{
	// first name of students
	static char * sNames[] = { "Bill","Jim","Bob","Mery" };
	int iInd1, sNamesCount = sizeof(sNames) / sizeof(char *);
	int nLen1, nMinLen1;

	// second name of students
	static char * sSurNames[] = { "Billovich","Jimmich","Bobovsky","Meryan" };
	int iInd2, sSurNamesCount = sizeof(sSurNames) / sizeof(char *);
	int nLen2, nMinLen2;

	for (int i = 0; i < nSize; ++i)
	{
		//filling number of student by direct
		pStAr[i].Student_Number = i + 1;

		// filling the first name of student
		iInd1 = rand() % sNamesCount;
		nLen1 = strlen(sNames[iInd1]) + 1;

		if (nLen1 < NAME_SIZE)
			nMinLen1 = nLen1;
		else
			nMinLen1 = NAME_SIZE;

		memcpy(pStAr[i].First_Name, sNames[iInd1], nMinLen1);
		pStAr[i].First_Name[nMinLen1 - 1] = 0;

		// filling the second name of student
		iInd2 = rand() % sSurNamesCount;
		nLen2 = strlen(sSurNames[iInd2]) + 1;

		if (nLen2 < NAME_SIZE)
			nMinLen2 = nLen2;
		else
			nMinLen2 = NAME_SIZE;

		memcpy(pStAr[i].Second_Name, sSurNames[iInd2], nMinLen2);
		pStAr[i].Second_Name[nMinLen2 - 1] = 0;

		// filling the age of students
		int iAge;
		iAge = rand() % 10 + 17;
		pStAr[i].Student_Age = iAge;

		// filling the count of rating numbers
		int iRange;
		for (int j = 0; j < RATING_COUNT; ++j)
		{
			iRange = rand() % 5;
			pStAr[i].Student_Ratings[j] = iRange;
		}

		// filling the students grade
		int iGrade = 0;
		for (int j = 0; j < RATING_COUNT; ++j)
		{
			iGrade += pStAr[i].Student_Ratings[j];
		}
		pStAr[i].Student_Grade = iGrade;
	}
}

void OutputStudents(Students * pStAr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
	{
		cout << setw(COLLUMN_SIZE) << pStAr[i].Student_Number;
		cout << setw(COLLUMN_SIZE) << pStAr[i].First_Name;
		cout << setw(COLLUMN_SIZE) << pStAr[i].Second_Name;
		cout << setw(COLLUMN_SIZE) << pStAr[i].Student_Age;
		int iRatSize = 2, iRatSizeMinus;
		iRatSizeMinus = COLLUMN_SIZE - (iRatSize * RATING_COUNT);
		cout << setw(iRatSizeMinus) << "";
		for (int j = 0; j < RATING_COUNT; ++j)
			cout << setw(iRatSize) << pStAr[i].Student_Ratings[j];
		cout << setw(COLLUMN_SIZE) << pStAr[i].Student_Grade << endl;
	}
	cout << endl;
}

void WriteHeadIntoFile(ColumnName * pHeadAr, int nSize, char * Name)
{
	FILE * file_write; // create the file stream
	errno_t err = fopen_s(&file_write, Name, "wb"); // open the file for write
	// write into the file
	fwrite(pHeadAr, sizeof(ColumnName), nSize, file_write);
	fclose(file_write);
}

void AppendHeadIntoFile(ColumnName * pHeadAr, int nSize, char * Name)
{
	FILE * file_write; // create the file stream
	errno_t err = fopen_s(&file_write, Name, "ab"); // open the file for write
	// write into the file
	fwrite(pHeadAr, sizeof(ColumnName), nSize, file_write);
	fclose(file_write);
}

void WriteStudentsIntoFile(Students * pStAr, int nSize, char * Name)
{
	FILE * file_write; // create the file stream
	errno_t err = fopen_s(&file_write, Name, "wb"); // open the file for write
													// write into the file
	fwrite(pStAr, sizeof(Students), nSize, file_write);
	fclose(file_write);
}

void AppendStudentsIntoFile(Students * pStAr, int nSize, char * Name)
{
	FILE * file_write; // create the file stream
	errno_t err = fopen_s(&file_write, Name, "ab"); // open the file for write
													// write into the file
	fwrite(pStAr, sizeof(Students), nSize, file_write);
	fclose(file_write);
}
