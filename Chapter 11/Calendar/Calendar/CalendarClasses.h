#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace dateTypeClass
{
	class dateType
	{
	public:
		void setDate(int&, int&, int&);
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		bool isLeapYear();
		int daysInMonth();
		int returnDaysPassed();
		int returnDaysRemaining(int&);
		void printDate() const;
		void calculateNewDate(int&, int&, int&, int&);
		explicit dateType(int month = 1, int day = 1, int year = 1900);
	private:
		int dMonth;
		int dDay;
		int dYear;
		int monthDays = 1;
	};

	void dateType::setDate(int& month, int& day, int& year)
	{
		while (month > 12 || month < 1)
		{
			cout << "This month is not valid!: ";
			cin >> month;
		}

		if (month % 2 == 0 && month != 2)
		{
			while (day > 30 || day < 1)
			{
				dDay = day;
			}
		}
		else if (month % 2 == 1)
		{
			while (day > 31 || day < 1)
			{
				dDay = day;
			}
		}
		else
		{
			while (day > 28 || day < 1)
			{
				dDay = day;
			}
		}

		dMonth = month;
		dYear = year;
	}

	int dateType::getDay() const
	{
		return dDay;
	}

	int dateType::getMonth() const
	{
		return dMonth;
	}

	int dateType::getYear() const
	{
		return dYear;
	}

	bool dateType::isLeapYear()
	{
		if (dYear % 4 == 0)
		{
			return true;
		}
		return false;
	}

	int dateType::daysInMonth()
	{
		if (dMonth % 2 == 0 && dMonth != 2)
		{
			monthDays = 30;
		}
		else if (dMonth % 2 == 1)
		{
			monthDays = 31;
		}
		else if (dMonth == 2 && dYear % 4 == 0)
		{
			monthDays = 29;
		}
		else
		{
			monthDays = 28;
		}
		return monthDays;
	}

	int dateType::returnDaysPassed()
	{
		int daysPassed = 0;

		if (dMonth == 1)
		{
			daysPassed = dDay - 1;
		}
		else
		{
			for (int i = 1; i <= dMonth; i++)
			{
				if (i == dMonth)
				{
					daysPassed = daysPassed + dDay;
				}
				else if (i == 1)
				{
					daysPassed = 31 - 1;
				}
				else if (i % 2 == 0 && i != 2)
				{
					daysPassed = daysPassed + 30;
				}
				else if (i % 2 == 1)
				{
					daysPassed = daysPassed + 31;
				}
				else
				{
					if (!isLeapYear())
					{
						daysPassed = daysPassed + 28;
					}
					else
					{
						daysPassed = daysPassed + 29;
					}
				}
			}
		}
		return daysPassed;
	}

	int dateType::returnDaysRemaining(int& daysPassed)
	{
		return (365 - daysPassed);
	}

	void dateType::printDate() const
	{
		cout << dMonth << "-" << dDay << "-" << dYear << endl;
	}

	void dateType::calculateNewDate(int& addedDays, int& newDateDays, int& newDateMonths, int& newDateYears)
	{
		int daysInMonth;
		newDateMonths = dMonth;
		newDateYears = dYear;
		newDateDays = 0;

		for (int i = 1; i <= addedDays; i++)
		{
			switch (dMonth)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				daysInMonth = 31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				daysInMonth = 30;
				break;
			case 2:
				if (isLeapYear())
				{
					daysInMonth = 29;
				}
				else
				{
					daysInMonth = 28;
				}
				break;
			default:
				break;
			}

			if (addedDays + dDay > daysInMonth && dDay == daysInMonth)
			{
				newDateMonths++;
				newDateDays = 1;
			}
			else
			{
				newDateDays = dDay + 1;
			}

			if (dDay == 31 && (newDateMonths == 13))
			{
				newDateYears++;
				newDateMonths = 1;
				newDateDays = 1;
				dMonth = 1;
			}

			if (dDay == daysInMonth)
			{
				dDay = 0;
				dMonth++;
			}
			dDay++;
		}
	}

	dateType::dateType(int month, int day, int year)
	{
		while (month > 12 || month < 1)
		{
			cout << "This month is not valid. Enter a new month: ";
			cin >> month;
		}

		if (month != 2)
		{
			if ((month % 2 == 1 && month > 8 && month < 12) || (month % 2 == 0 && month < 8))
			{
				while (day > 30 || day < 1)
				{
					cout << "This day is not valid given this month. Enter a new day: ";
					cin >> day;
				}
			}
			else if ((month % 2 == 1 && month < 8) || (month % 2 == 0 && month > 8))
			{
				while (day > 31 || day < 1)
				{
					cout << "This day is not valid given this month. Enter a new day: ";
					cin >> day;
				}
			}
		}
		else
		{
			if (!isLeapYear())
			{
				while (day > 28 || day < 1)
				{
					cout << "This day is not valid given February and the year " << year << ". Enter a new day: ";
					cin >> day;
				}
			}
			else
			{
				while (day > 29 || day < 1)
				{
					cout << "This day is not valid given February and the year " << year << ". Enter a new day: ";
					cin >> day;
				}
			}
		}

		dDay = day;
		dMonth = month;
		dYear = year;
	}
}

namespace extDateTypeClass
{
	class extDateType : public dateTypeClass::dateType
	{
	public:
		extDateType(int month, int day, int year) : dateType(month, day, year){}
		void setNameOfMonth(string&);
		void printDateWithoutDashes();
	private:
		string dMonthName;
	};

	void extDateType::setNameOfMonth(string& monthName)
	{
		dMonthName = monthName;
	}

	void extDateType::printDateWithoutDashes()
	{
		cout << dMonthName << " " << extDateType::getYear() << endl;
	}
}

namespace dayTypeClass
{
	class dayType
	{
	public:
		dayType(string&);
		void printDay() const;
		string getDay() const;
		string getNextDay();
		void calculateAddedDays(int);
		string returnAddedDaysTotal() const;
		dayType(){};
	private:
		int dDayOfWeekNum;
		string dDayOfWeek;
		string dDayOfWeekPlus1;
		string dDayOfWeekPlusAddedDays;
		enum daysOfWeek
		{
			Sunday = 1,
			Monday,
			Tuesday,
			Wednsday,
			Thursday,
			Friday,
			Saturday
		} weekDays = static_cast<daysOfWeek>(1);
	};

	dayType::dayType(string& day)
	{
		if (day == "sun" || day == "Sun")
		{
			dDayOfWeek = "Sunday";
			dDayOfWeekNum = 1;
		}
		else if (day == "mon" || day == "Mon")
		{
			dDayOfWeek = "Monday";
			dDayOfWeekNum = 2;
		}
		else if (day == "tues" || day == "Tues")
		{
			dDayOfWeek = "Tuesday";
			dDayOfWeekNum = 3;
		}
		else if (day == "wed" || day == "Wed")
		{
			dDayOfWeek = "Wednsday";
			dDayOfWeekNum = 4;
		}
		else if (day == "thurs" || day == "Thurs")
		{
			dDayOfWeek = "Thursday";
			dDayOfWeekNum = 5;
		}
		else if (day == "fri" || day == "Fri")
		{
			dDayOfWeek = "Friday";
			dDayOfWeekNum = 6;
		}
		else if (day == "sat" || day == "Sat")
		{
			dDayOfWeek = "Saturday";
			dDayOfWeekNum = 7;
		}
	}

	void dayType::printDay() const
	{
		cout << dDayOfWeek << endl;
	}
	string dayType::getDay() const
	{
		return dDayOfWeek;
	}
	string dayType::getNextDay()
	{
		weekDays = static_cast<daysOfWeek>(dDayOfWeekNum);
		weekDays = static_cast<daysOfWeek>(weekDays + 1);

		if (weekDays == 8)
		{
			weekDays = static_cast<daysOfWeek>(1);
		}

		switch (weekDays)
		{
		case Sunday:
			dDayOfWeekPlus1 = "Sunday";
			break;
		case Monday:
			dDayOfWeekPlus1 = "Monday";
			break;
		case Tuesday:
			dDayOfWeekPlus1 = "Tuesday";
			break;
		case Wednsday:
			dDayOfWeekPlus1 = "Wednsday";
			break;
		case Thursday:
			dDayOfWeekPlus1 = "Thursday";
			break;
		case Friday:
			dDayOfWeekPlus1 = "Friday";
			break;
		case Saturday:
			dDayOfWeekPlus1 = "Saturday";
			break;
		default:
			break;
		}
		return dDayOfWeekPlus1;
	}

	void dayType::calculateAddedDays(int addedDays)
	{
		for (int i = 1; i <= addedDays; i++)
		{
			if (weekDays == 8)
			{
				weekDays = static_cast<daysOfWeek>(1);
			}

			switch (weekDays)
			{
			case Sunday:
				dDayOfWeekPlusAddedDays = "Sunday";
				break;
			case Monday:
				dDayOfWeekPlusAddedDays = "Monday";
				break;
			case Tuesday:
				dDayOfWeekPlusAddedDays = "Tuesday";
				break;
			case Wednsday:
				dDayOfWeekPlusAddedDays = "Wednsday";
				break;
			case Thursday:
				dDayOfWeekPlusAddedDays = "Thursday";
				break;
			case Friday:
				dDayOfWeekPlusAddedDays = "Friday";
				break;
			case Saturday:
				dDayOfWeekPlusAddedDays = "Saturday";
				break;
			default:
				break;
			}
			weekDays = static_cast<daysOfWeek>(weekDays + 1);
		}
	}

	string dayType::returnAddedDaysTotal() const
	{
		return dDayOfWeekPlusAddedDays;
	}
}

namespace calendarTypeClass
{
	class calendarType : public extDateTypeClass::extDateType, public dayTypeClass::dayType
	{
	public:
		using extDateType::extDateType;
		using dayType::dayType;
		void PrintHeader();
		void FirstDayOfMonth();
	private:
		int dLastDayInMonth;
		string dFirstDayOfMonth;
	};

	void calendarType::PrintHeader()
	{
		extDateType::printDateWithoutDashes();
		cout << endl;
		cout << "Sun\tMon\tTue\tWed\tThur\tFri\tSat";
	}

	void calendarType::FirstDayOfMonth()
	{
		
	}
}