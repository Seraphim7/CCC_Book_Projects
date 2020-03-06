#pragma once

#include <string>

using namespace std;

class clockType
{
public:
	void setTime(int hours, int minutes, int seconds);
	void getTime(int& hours, int& minutes, int& seconds) const;
	void printTime() const;
	void incrementSeconds();
	void incrementMinutes();
	void incrementHours();
	bool equalTime(const clockType& otherClock) const;
	clockType(int hours, int minutes, int seconds);
	clockType();
private:
	int hr;
	int min;
	int sec;
};

class extClockType : public clockType
{
public:
	using clockType::clockType;
	void setTimeZone(string);
	string getTimeZone() const;
private:
	string m_timeZone;
};