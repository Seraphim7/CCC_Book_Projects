#pragma once

#include <cstring>

using namespace std;

class overloadingEqualsOperator
{
public:
	void operator= (overloadingEqualsOperator&);
	void setter(char[]);
	char* getter();
private:
	char m_CharArray[20] = "";
};

void overloadingEqualsOperator::operator= (overloadingEqualsOperator& rhs)
{
	strcpy(m_CharArray, rhs.m_CharArray);
}

void overloadingEqualsOperator::setter(char charArray[])
{
	strcpy(m_CharArray, charArray);
}

char* overloadingEqualsOperator::getter()
{
	char* charArrayPtr = &m_CharArray[0];

	return charArrayPtr;
}