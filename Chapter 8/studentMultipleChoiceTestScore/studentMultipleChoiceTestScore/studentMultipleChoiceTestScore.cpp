#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

const int NUM_OF_ANSWERS = 20;
const int IDSize = 31;

int main()
{
	ifstream DataFile;
	char studentRecord[IDSize];
	char* studentRecordPtr = &studentRecord[0];
	char realAnswers[NUM_OF_ANSWERS + 1];
	char* realAnswersPtr = &realAnswers[0];
	int numberOfStudents;
	char studentAnswers[IDSize - 9];
	char* studentAnswersPtr = &studentAnswers[0];
	char studentID[8];
	char* studentIDPtr = &studentID[0];

	cout << "How many students are in your history class?: ";
	cin >> numberOfStudents;

	DataFile.open("text.txt");

	if (DataFile.is_open())
	{
		cout << "File opened!" << endl;
		for (int i = 0; i <= numberOfStudents; i++)
		{
			if (i == 0)
			{
				DataFile.get(realAnswersPtr, 21);
			}
			else
			{
				DataFile.ignore();
				DataFile.get(studentRecordPtr, 31);
				strncpy(studentIDPtr, studentRecordPtr, 8);
				DataFile.ignore();
				strncpy(studentAnswersPtr, studentRecordPtr + 9, 21);
				DataFile.ignore();
			}
		}
		
		
		DataFile.close();
	}
	else
	{
		cout << "fail" << endl;
	}

	for (int i = 0; i < NUM_OF_ANSWERS + 1; i++)
	{
		cout << *(realAnswersPtr + i);
	}

	cout << endl;

	for (int i = 0; i < 8; i++)
	{
		cout << *(studentIDPtr + i);
	}

	cout << " ";

	for (int i = 0; i < NUM_OF_ANSWERS + 1; i++)
	{
		cout << *(studentAnswersPtr + i);
	}
}