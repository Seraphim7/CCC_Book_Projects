#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "cStrings and the = operator.h"

using namespace std;

int main()
{
	char* myArrayPtr;
	char myArray[10];
	overloadingEqualsOperator obj1;
	overloadingEqualsOperator obj2;

	cout << "Enter in 10 characters: ";
	cin.get(myArray, 10);

	obj1.setter(myArray);

	obj2 = obj1;

	myArrayPtr = obj2.getter();

	for (size_t i = 0; i < 10; i++)
	{
		cout << *(myArrayPtr + i);
	}
	return 0;
}