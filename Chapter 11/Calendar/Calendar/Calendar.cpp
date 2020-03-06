#include <iostream>
#include <string>
#include "CalendarClasses.h"

using namespace std;

using calendarTypeClass::calendarType;

void Month(dateTypeClass::dateType&, string&);

int main()
{
	int month;
	int day;
	int year;
	int addedDays;
	int daysInMonth;
	int daysPassedInYear;
	int daysRemainingInYear;
	int newDateDays;
	int newDateMonths;
	int newDateYears;
	string monthName;
	string dayOfWeek;
	
	cout << "Enter the month as a number: ";
	cin >> month;

	cout << "Enter the day: ";
	cin >> day;

	cout << "Enter the year: ";
	cin >> year;

	calendarType dateObj(month, day, year);

	Month(dateObj, monthName);
	dateObj.setNameOfMonth(monthName);

	dateObj.printDate();
	dateObj.printDateWithoutDashes();

	daysInMonth = dateObj.daysInMonth();
	daysPassedInYear = dateObj.returnDaysPassed();
	daysRemainingInYear = dateObj.returnDaysRemaining(daysPassedInYear);

	cout << "There are " << daysInMonth << " in the month of " << monthName << " given the year " << year << endl;

	if (daysPassedInYear == 1)
	{
		cout << daysPassedInYear << " day has passed since the beginning of the year " << year << endl;
	}
	else
	{
		cout << daysPassedInYear << " days have passed since the beginning of the year " << year << endl;
	}

	if (daysRemainingInYear == 1)
	{
		cout << daysRemainingInYear << " day is remaining in the year " << year << endl;
	}
	else
	{
		cout << daysRemainingInYear << " days are remaining in the year " << year << endl;
	}

	cout << "How many days do you want to add to this date " << dateObj.getMonth() << "-" << dateObj.extDateType::getDay() << "-" << dateObj.getYear() << ": ";
	cin >> addedDays;

	dateObj.calculateNewDate(addedDays, newDateDays, newDateMonths, newDateYears);
	cout << newDateMonths << "-" << newDateDays << "-" << newDateYears << endl;

	cout << "Favorite day: ";
	cin >> dayOfWeek;

	dateObj.dayType::dayType(dayOfWeek);

	dayOfWeek = dateObj.dayType::getDay();
	cout << "Today is " << dayOfWeek << endl;

	dayOfWeek = dateObj.getNextDay();
	cout << "The next day is " << dayOfWeek << endl;

	cout << "How many days do you want to add to today?: ";
	cin >> addedDays;

	dateObj.calculateAddedDays(addedDays);
	cout << "Today + " << addedDays << " = " << dateObj.returnAddedDaysTotal() << endl;

	dateObj.PrintHeader();
	return 0;
}

void Month(dateTypeClass::dateType& dateObj, string& monthName)
{
	switch (dateObj.getMonth())
	{
	case 1:
		monthName = "January";
		break;
	case 2:
		monthName = "February";
		break;
	case 3:
		monthName = "March";
		break;
	case 4:
		monthName = "April";
		break;
	case 5:
		monthName = "May";
		break;
	case 6:
		monthName = "June";
		break;
	case 7:
		monthName = "July";
		break;
	case 8:
		monthName = "Auguest";
		break;
	case 9:
		monthName = "September";
		break;
	case 10:
		monthName = "October";
		break;
	case 11:
		monthName = "November";
		break;
	case 12:
		monthName = "December";
		break;
	default:
		break;
	}
}