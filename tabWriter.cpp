#include <iostream>
#include <ctime>
#include "windows.h"
#include <fstream>


const int row = 6, column = 11;
const int stringNum = 6, outLength = 20;

void randomNotesGen(int[row][column], std::ofstream &outFile);

int main()
{
	srand(time(0));
	std::ofstream outFile;
	int dMinor[row][column] = { 0,1,3,5,6,8,10,12,13,15,17,
							 1,3,5,6,8,10,11,13,15,17,18,
							 0,2,3,5,7,9,10,12,14,15,17,
							 0,2,3,5,7,8,10,12,14,15,17,
							 0,1,3,5,7,8,10,12,13,15,17,
							 0,1,3,5,6,8,10,12,13,15,17 };
	int dMajor[row][column] = { 0,2,3,5,7,9,10,12,14,15,17,
							 0,2,3,5,7,8,10,12,14,15,17,
							 0,2,4,6,7,9,11,12,14,16,18,
							 0,2,4,5,7,9,11,12,14,16,17,
							 0,2,4,5,7,9,10,12,14,16,17,
							 0,2,3,5,7,9,10,12,14,15,17 };
	outFile.open("tabOut.txt", std::ofstream::out | std::ofstream::app);
	char choice;
	bool exit = false;
	//Main Menu
	do
	{
		choice = NULL;
		system("cls");
		printf("Choose A Scale: \n 1. D Minor\n 2. D Major\n 3. Coming Soon\n\n Press 'q' to quit...\n");
		std::cin >> choice;
		switch (choice)
		{
		case '1':
			outFile << "D Minor: \n";
			system("cls");
			printf("D Minor: \n");
			randomNotesGen(dMinor, outFile);
			system("pause");
			break;
		case '2':
			outFile << "D Major: \n";
			system("cls");
			printf("D Major: \n");
			randomNotesGen(dMajor, outFile);
			system("pause");
			break;
		case 'q':
			exit = true;
			break;
		default:
			break;
		}
	} while (!exit);
	outFile.close();
}

void randomNotesGen(int dMinor[row][column], std::ofstream &outFile)
{
	char output[stringNum][outLength];
	int startingCol, startingRow;
	int newNoteRow, newNoteCol;
	for (int r = 0; r < 6; r++)
	{
		for (int c = 0; c < 20; c++)
		{
			output[r][c] = '-';
		}
	}
	startingCol = ((rand() % 11));
	startingRow = ((rand() % 6));
	output[startingRow][0] = dMinor[startingRow][startingCol] + 48;
	for (int i = 1; i < 20; i++)
	{
		newNoteRow = ((rand() % 3) - 1);
		switch (newNoteRow)
		{
			case -1:
				if (startingRow == 0)
				{
					newNoteRow = rand() % 2;
				}
				break;
			case 1:
				if (startingRow == 5)
				{
					newNoteRow = (rand() % 2) - 1;
				}
				break;
			default:
				break;

		}
		startingRow += newNoteRow;
		newNoteCol = ((rand() % 3) - 1);
		switch (newNoteCol)
		{
			case -1:
				if (startingCol == 0)
				{
					newNoteCol = rand() % 2;
				}
				break;
			case 1:
				if (startingCol == 10)
				{
					newNoteCol = (rand() % 2) - 1;
				}
				break;
			default:
				break;

		}
		startingCol += newNoteCol;

		output[startingRow][i] = dMinor[startingRow][startingCol] + 48;
	}
	for (int r = 0; r < 6; r++)
	{
		for (int c = 0; c < 20; c++)
		{
			switch (output[r][c])
			{
			case 10: printf("10 ");
				outFile << "10 ";
				break;
			case 11: printf("11 ");
				outFile << "11 ";
				break;
			case 58: printf("10 ");
				outFile << "10 ";
				break;
			case 59: printf("11 ");
				outFile << "11 ";
				break;
			case 60: printf("12 ");
				outFile << "12 ";
				break;
			case 61: printf("13 ");
				outFile << "13 ";
				break;
			case 62: printf("14 ");
				outFile << "14 ";
				break;
			case 63: printf("15 ");
				outFile << "15 ";
				break;
			case 64: printf("16 ");
				outFile << "16 ";
				break;
			case 65: printf("17 ");
				outFile << "17 ";
				break;
			case 66: printf("18 ");
				outFile << "18 ";
				break;
			default:
				printf("%c  ", output[r][c]);
				outFile << output[r][c] << "  ";
				break;

			}
		}
		printf("\n");
		outFile << std::endl;
	}
	outFile << std::endl;
}