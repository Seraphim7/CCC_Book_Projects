#include <iostream>
#include <cstring>

using namespace std;

const int rows = 13;
const int seatsInRow = 6;
const int classCharacters = 9;

void Input(char[], char&);
void Row(char[], int&);
void Seat(char&, int&);

int main()
{
	char seatsArray[rows][seatsInRow];
	char seatingClass[classCharacters];
	char seatLetter;
	int rowNumber;
	int seatNumber;
	int anotherIteration = 0;

	// Initialization
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < seatsInRow; j++)
		{
			seatsArray[i][j] = '*';
		}
	}

	// Looping until all of the seats are taken
	for (int i = 1; i < (rows * seatsInRow) + anotherIteration; i++)
	{
		Input(seatingClass, seatLetter);
		Row(seatingClass, rowNumber);
		Seat(seatLetter, seatNumber);

		// Set the occupied seat to 'X'
		seatsArray[rowNumber - 1][seatNumber - 1] = 'X';

		// Output
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < seatsInRow; j++)
			{
				cout << seatsArray[i][j];
			}
			cout << endl;
		}

		cout << endl;
		cin.ignore(100, '\n');
	}
}

// Input
void Input(char seatingClass[], char& seatLetter)
{
	cout << "Hello, Welcome to the airplane seat picker!" << endl;
	cout << "First, we will ask you whether your ticket is first, buisness, or economy: ";
	cin.get(seatingClass, classCharacters);

	cout << "Now, pick a seat (A through F): ";
	cin >> seatLetter;
	cin.ignore(100, '\n');
}

// Finding the rows available based on the type of class of ticket
void Row(char seatingClass[], int& rowNumber)
{
	int firstClass[] = { 1, 2 };
	int buisnessClass[] = { 3, 4, 5, 6, 7 };
	int economyClass[] = { 8, 9, 10, 11, 12, 13 };

	cout << "Which row do you want?: ";

	if (strcmp(seatingClass, "first") == 0)
	{
		for (int i = 0; i < 2; i++)
		{
			cout << firstClass[i] << " ";
		}
	}
	else if (strcmp(seatingClass, "buisness") == 0)
	{
		for (int i = 0; i < 5; i++)
		{
			cout << buisnessClass[i] << " ";
		}
	}
	else
	{
		for (int i = 0; i < 6; i++)
		{
			cout << economyClass[i] << " ";
		}
	}
	cout << ": ";
	cin >> rowNumber;
}

// Seat letters to numbers
void Seat(char& seatLetter, int& seatNumber)
{
	switch (seatLetter)
	{
	case 'A':
		seatNumber = 1;
		break;
	case 'B':
		seatNumber = 2;
		break;
	case 'C':
		seatNumber = 3;
		break;
	case 'D':
		seatNumber = 4;
		break;
	case 'E':
		seatNumber = 5;
		break;
	default:
		seatNumber = 6;
		break;
	}
}