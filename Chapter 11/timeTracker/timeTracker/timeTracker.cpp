#include <iostream>
#include <string>
#include "timeTrackerMethods.h"

using namespace std;

int main()
{
	int hours;
	int minutes;
	int seconds;
	string timeZone;

	cout << "Hours: ";
	cin >> hours;
	cin.ignore(100, '\n');
	cout << "Minutes: ";
	cin >> minutes;
	cin.ignore(100, '\n');
	cout << "Seconds: ";
	cin >> seconds;
	cin.ignore(100, '\n');
	cout << "What is your time zone: ";
	getline(cin, timeZone);

	extClockType clock(hours, minutes, seconds);
	extClockType clock2(hours, minutes, seconds);
	clock.printTime();
	clock.incrementHours();
	clock.incrementMinutes();
	clock.printTime();
	clock.incrementSeconds();
	clock.printTime();
	clock.setTimeZone(timeZone);
	timeZone = clock.getTimeZone();

	bool isEqual = clock2.equalTime(clock);

	cout << isEqual << endl;

	cout << timeZone;
}