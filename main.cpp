#include <assert.h>
#include <iostream>

bool IsLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		if (year < 400) return true;
		else if (year % 400 == 0) return true;
	return false;
}

double LaterInYear(int d1, int d2, int m1, int m2)
{
	double date = 0;
	if (m1 > m2)
		date = d1 + m1 / static_cast<double>(100);
	else if (m1 < m2)
		date = d2 + m2 / static_cast<double>(100);
	else if(d1 > d2)
		date = d1 + m1 / static_cast<double>(100);
	else date = d2 + m2 / static_cast<double>(100);
	return date;
}

int DaysInYear(int year) { if (IsLeapYear(year)) return 366; return 365; }

int SecondInHour(int hour) { return hour * 3600; }

bool IsYearOfApocalypse(int year) { return (year == 1992 || year == 2005 || year == 2011); }

int DaysInYearRange(int year1, int year2)
{
	int sum = 0;
	for (int i = year1; i <= year2; i++)
	{
		if (IsLeapYear(i))
			sum += 366;
		else sum += 365;
	}
	return sum;
}

int main()
{
	//Task 1

	assert(IsLeapYear(4) == 1);

	//Task 2

	assert(LaterInYear(23, 24, 5, 6) == 24.06);

	//Task 3

	assert(DaysInYear(4) == 366);

	//Task 4

	assert(DaysInYearRange(4, 5) == 731);

	//Task 5

	assert(IsYearOfApocalypse(2005) == 1);
}