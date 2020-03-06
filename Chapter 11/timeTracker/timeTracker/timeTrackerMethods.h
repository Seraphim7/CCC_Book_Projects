#pragma once

#include <iostream>
#include <string>
#include "timeTrackerClasses.h"

using namespace std;

void clockType::setTime(int hours, int minutes, int seconds)
{
	hr = hours;
	min = minutes;
	sec = seconds;
}

void clockType::getTime(int& hours, int& minutes, int& seconds) const
{
	hours = hr;
	minutes = min;
	seconds = sec;
}

void clockType::printTime() const
{
	cout << "The time currently is: " << hr << ":" << min << ":" << sec << endl;
}

void clockType::incrementSeconds()
{
	if (sec == 59)
	{
		sec = 0;
		if (min == 59)
		{
			min = 0;
			if (hr == 23)
			{
				hr = 0;
			}
		}
	}
	else
	{
		sec++;
	}
}

void clockType::incrementMinutes()
{
	if (min == 59)
	{
		min = 0;
		if (hr == 23)
		{
			hr = 0;
		}
	}
	else
	{
		min++;
	}
}

void clockType::incrementHours()
{
	if (hr == 23)
	{
		hr = 0;
	}
	else
	{
		hr++;
	}
}

bool clockType::equalTime(const clockType& otherClock) const
{
	if (otherClock.hr == this->hr && otherClock.min == this->min && otherClock.sec == this->sec)
	{
		return true;
	}
	return false;
}

clockType::clockType(int hours, int minutes, int seconds)
{
	setTime(hours, minutes, seconds);
}

clockType::clockType(){}

void extClockType::setTimeZone(string timeZone)
{
	m_timeZone = timeZone;
}

string extClockType::getTimeZone() const
{
	return m_timeZone;
}