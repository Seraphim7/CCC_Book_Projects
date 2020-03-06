#pragma once

#include <string>

class MyClass
{
public:
	MyClass();
	MyClass(int);
	~MyClass();
	int getter();
	void operator= (MyClass&);

private:
	int number;
	char character;
	std::string letters;
};

MyClass::MyClass(int num)
{
	number = num;
}

MyClass::~MyClass()
{
}

int MyClass::getter()
{
	return number;
}
void MyClass::operator= (MyClass& lhs)
{
	lhs.number = number;
}

MyClass::MyClass()
{

}