#include <iostream>

using namespace std;

int searchingForSmallestIndex(int[], int);
const int sizeOfArray = 5;

int main()
{
	int intArray[sizeOfArray];

	cout << "Enter the contents of your array..." << endl;
	for (int i = 0; i < sizeOfArray; i++)
	{
		cout << ": ";
		cin >> intArray[i];
	}
	int smallestNumber = searchingForSmallestIndex(intArray, sizeOfArray);
	cout << smallestNumber << " is the smallest number in the array!";

	return 0;
}

int searchingForSmallestIndex(int intArray[], int sizeOfArray)
{
	int smallestNumber;
	smallestNumber = intArray[0];
	for (int i = 0; i < sizeOfArray; i++)
	{
		if (smallestNumber > intArray[i])
		{
			smallestNumber = intArray[i];
		}
	}
	return smallestNumber;
}