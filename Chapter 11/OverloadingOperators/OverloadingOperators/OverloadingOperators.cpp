#include <iostream>
#include "OverloadingOperators.h"

using namespace std;

int main()
{
	MyClass newObject(2);
	MyClass newObject1(5);
	MyClass newObject2(7);

	cout << "newObject2: " << newObject2.getter() << endl;
	cout << "newObject: " << newObject.getter() << endl;
	cout << "neObject1: " << newObject1.getter() << endl;

	newObject2 = newObject; // left hand side

	cout << "Now newObject is: " << newObject2.getter() << endl;
	
	newObject = newObject1;

	cout << "Now newObject1 is: " << newObject1.getter() << endl;

	return 0;
}