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
void OutputHeadOfCollumnsByString(ColumnName * pHeadAr, int nSize);
void InitStudents(Students * pStAr, int nSize);
void OutputStudents(Students * pStAr, int nSize);
void OutputOneStudents(Students * pStAr, int nNumber);
void OutputStudentCollumnForEdit(Students * pStAr, int nNumber, int ColNum);
void EditStudentCollumn(Students * pStAr, int nNumber, int ColNum);
void OutpuHeadForEdit(ColumnName * pHeadAr, int ColNum);
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
	int StudentNumber, CollumnNumber;

	InitHeadOfCollumns(pHeadOfCollumns, CollumnsCount);
	InitStudents(pStudentsArray, StudentsCount);

	char cFileName[] = "students.course";
	int a;
	do
	{
		cout << "What do you want to do: " << endl;
		cout << "O - output generated table, " << endl;
		cout << "R - read from file if exists, " << endl;
		cout << "W - write generated table into the file : ";

		a = _getch();
		system("cls");
	} while (a != 111 && a != 114 && a != 119);

	switch (a)
	{
	case 111: // output the table
	{
		OutputHeadOfCollumns(pHeadOfCollumns, CollumnsCount);
		OutputStudents(pStudentsArray, StudentsCount);
	}break;
	case 114: // read the file
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
			int b;
			do
			{
				cout << "File already exists! For rewrite press Y, for uppend press U, for exit press N: ";
				b = _getch();
				system("cls");
			} while (b != 121 && b != 117 && b != 110);
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
	int c;
	do
	{
		cout << endl << "For edit the student please press E, for quit press Q: ";
		c = _getch();
		system("cls");
	} while (c != 101 && c != 113);

	switch (c)
	{
	case 101: // Edit the student
	{

		OutputHeadOfCollumns(pHeadOfCollumns, CollumnsCount);
		OutputStudents(pStudentsArray, StudentsCount);

		cout << "Enter the student number between 1 and " << StudentsCount << ": ";
		int d;
		int StNumSize = 100;
		int StNumInd = 0;
		char * sStNum = new char[StNumSize];
		do
		{
			d = _getch();
			if (isalnum(d))
			{
				cout << (char)d;
				sStNum[StNumInd++] = (char)d;
			}
			else if (d == 8 && StNumInd > 0)
			{
				cout << "\b \b";
				sStNum[(StNumInd--) - 1] /= 10;
			}
			StudentNumber = atoi(sStNum);
			if (1 < StudentNumber && StudentNumber > StudentsCount)
			{
				cout << "\b \b";
				sStNum[(StNumInd--) - 1] /= 10;
			}
		} while (d != 13);
		delete[] sStNum;

		system("cls");
		cout << "The student wich you choice to edit: " << endl;
		OutputHeadOfCollumns(pHeadOfCollumns, CollumnsCount);
		OutputOneStudents(pStudentsArray, StudentNumber - 1);

		cout << "Choice by press the number of what you will change: " << endl;
		OutputHeadOfCollumnsByString(pHeadOfCollumns, CollumnsCount);
		int e;
		do
		{
			e = _getch();
		} while (e != 50 && e != 51 && e != 52 && e != 53);

		CollumnNumber = (int)e - 48;
		//cout << CollumnNumber << endl;

		OutpuHeadForEdit(pHeadOfCollumns, CollumnNumber - 1);
		OutputStudentCollumnForEdit(pStudentsArray, StudentNumber - 1, CollumnNumber);

		cout << "Enter the new value: ";
		EditStudentCollumn(pStudentsArray, StudentNumber - 1, CollumnNumber);

		system("cls");
		cout << "New student's information was updated:" << endl;
		OutputHeadOfCollumns(pHeadOfCollumns, CollumnsCount);
		OutputOneStudents(pStudentsArray, StudentNumber - 1);

	} break;
	case 113: // Quit
	{
		break;
	} break;
	}

	cout << endl;

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
	cout << endl;
}

void OutputHeadOfCollumnsByString(ColumnName * pHeadAr, int nSize)
{
	for (int i = 1; i < nSize - 1; ++i)
		cout << i + 1 << " - " << pHeadAr[i].CollumnName << endl;
	cout << endl;
}

void OutpuHeadForEdit(ColumnName * pHeadAr, int ColNum)
{
	cout << "Current collumn <" << pHeadAr[ColNum].CollumnName << "> is: ";
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

void OutputOneStudents(Students * pStAr, int nNumber)
{
	cout << setw(COLLUMN_SIZE) << pStAr[nNumber].Student_Number;
	cout << setw(COLLUMN_SIZE) << pStAr[nNumber].First_Name;
	cout << setw(COLLUMN_SIZE) << pStAr[nNumber].Second_Name;
	cout << setw(COLLUMN_SIZE) << pStAr[nNumber].Student_Age;
	int iRatSize = 2, iRatSizeMinus;
	iRatSizeMinus = COLLUMN_SIZE - (iRatSize * RATING_COUNT);
	cout << setw(iRatSizeMinus) << "";
	for (int j = 0; j < RATING_COUNT; ++j)
		cout << setw(iRatSize) << pStAr[nNumber].Student_Ratings[j];
	cout << setw(COLLUMN_SIZE) << pStAr[nNumber].Student_Grade << endl;
	cout << endl;
}

void OutputStudentCollumnForEdit(Students * pStAr, int nNumber, int ColNum)
{
	switch (ColNum)
	{
	case 1:
	{
		cout << pStAr[nNumber].Student_Number;
	} break;
	case 2:
	{
		cout << pStAr[nNumber].First_Name;
	} break;
	case 3:
	{
		cout << pStAr[nNumber].Second_Name;
	} break;
	case 4:
	{
		cout << pStAr[nNumber].Student_Age;
	} break;
	case 5:
	{
		for (int j = 0; j < RATING_COUNT; ++j)
			cout << setw(2) << pStAr[nNumber].Student_Ratings[j];
	} break;
	case 6:
	{
		cout << pStAr[nNumber].Student_Grade;
	} break;
	}
	cout << endl;
}

void EditStudentCollumn(Students * pStAr, int nNumber, int ColNum)
{
	switch (ColNum)
	{
	case 1:
	{
		cout << pStAr[nNumber].Student_Number;
	} break;
	case 2:
	{
		int iCurrInd = 0;
		char * pArray = new char[NAME_SIZE + 1];
		char a;
		do
		{
			a = _getch();
			if (isalpha(a))
			{
				pArray[iCurrInd++] = a;
				cout << (char)a;
			}
			else if (a == 8 && iCurrInd > 0)
			{
				cout << "\b \b";
				pArray[(iCurrInd--) - 1] /= 10;
			}
			if (1 < iCurrInd && iCurrInd >= NAME_SIZE)
			{
				cout << "\b \b";
				pArray[(iCurrInd--) - 1] /= 10;
			}
		} while (a != 13 && a != 27);

		if (a == 13 && pArray > 0)
		{
			for (int i = 0; i < NAME_SIZE; ++i)
				pStAr[nNumber].First_Name[i] = 0;
			memcpy(pStAr[nNumber].First_Name, pArray, sizeof(char) * iCurrInd);

			if (pStAr[nNumber].First_Name[0] >= 'a' && pStAr[nNumber].First_Name[0] <= 'z')
				pStAr[nNumber].First_Name[0] -= 32;
			for (int i = 1; i < SURNAME_SIZE; ++i)
			{
				if (pStAr[nNumber].First_Name[i] >= 'A' && pStAr[nNumber].First_Name[i] <= 'Z')
					pStAr[nNumber].First_Name[i] += 32;
			}
		}

		delete[] pArray;
	} break;
	case 3:
	{
		int iCurrInd = 0;
		char * pArray = new char[SURNAME_SIZE + 1];
		char a;
		do
		{
			a = _getch();
			if (isalpha(a))
			{
				pArray[iCurrInd++] = a;
				cout << (char)a;
			}
			else if (a == 8 && iCurrInd > 0)
			{
				cout << "\b \b";
				pArray[(iCurrInd--) - 1] /= 10;
			}
			if (1 < iCurrInd && iCurrInd >= SURNAME_SIZE)
			{
				cout << "\b \b";
				pArray[(iCurrInd--) - 1] /= 10;
			}
		} while (a != 13 && a != 27);

		if (a == 13 && pArray > 0)
		{
			for (int i = 0; i < SURNAME_SIZE; ++i)
				pStAr[nNumber].Second_Name[i] = 0;
			memcpy(pStAr[nNumber].Second_Name, pArray, sizeof(char) * iCurrInd);

			if (pStAr[nNumber].Second_Name[0] >= 'a' && pStAr[nNumber].Second_Name[0] <= 'z')
				pStAr[nNumber].Second_Name[0] -= 32;
			for (int i = 1; i < SURNAME_SIZE; ++i)
			{
				if (pStAr[nNumber].Second_Name[i] >= 'A' && pStAr[nNumber].Second_Name[i] <= 'Z')
					pStAr[nNumber].Second_Name[i] += 32;
			}
		}

		delete[] pArray;
	} break;
	case 4:
	{
		int iCurrInd = 0, iDigitsCnt = 3, NewAge;
		char * pArray = new char[iDigitsCnt];
		char a;
		do
		{
			a = _getch();
			if (isalnum(a))
			{
				pArray[iCurrInd++] = a;
				cout << (char)a;
			}
			else if (a == 8 && iCurrInd > 0)
			{
				cout << "\b \b";
				pArray[(iCurrInd--) - 1] /= 10;
			}
			if (1 < iCurrInd && iCurrInd >= iDigitsCnt)
			{
				cout << "\b \b";
				pArray[(iCurrInd--) - 1] /= 10;
			}
		} while (a != 13 && a != 27);

		pArray[iCurrInd] = '\0';
		NewAge = atoi(pArray);
		if (a == 13 && NewAge > 0)
			pStAr[nNumber].Student_Age = NewAge;

		delete[] pArray;
	} break;
	case 5:
	{
		for (int j = 0; j < RATING_COUNT; ++j)
		{
			cout << "Enter the <" << j + 1 << "> student rating: ";
			int iCurrInd = 0, iDigitsCnt = 2, NewRating;
			char * pArray = new char[iDigitsCnt];
			char a;
			do
			{
				a = _getch();
				if (isalnum(a))
				{
					pArray[iCurrInd++] = a;
					cout << (char)a;
				}
				else if (a == 8 && iCurrInd > 0)
				{
					cout << "\b \b";
					pArray[(iCurrInd--) - 1] /= 10;
				}
				if (1 < iCurrInd && iCurrInd >= iDigitsCnt)
				{
					cout << "\b \b";
					pArray[(iCurrInd--) - 1] /= 10;
				}
			} while (a != 13 && a != 27);

			pArray[iCurrInd] = '\0';
			NewRating = atoi(pArray);
			if (a == 13 && NewRating > 0)
				pStAr[nNumber].Student_Ratings[j] = NewRating;
			cout << endl;

			delete[] pArray;
		}

		cout << "(!) Also the student's grade was recalculated" << endl;
		// recalculate the students grade
		int iGrade = 0;
		for (int j = 0; j < RATING_COUNT; ++j)
		{
			iGrade += pStAr[nNumber].Student_Ratings[j];
		}
		pStAr[nNumber].Student_Grade = iGrade;
	} break;
	case 6:
	{
		cout << pStAr[nNumber].Student_Grade;
	} break;
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
