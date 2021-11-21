#include <string>
#include <iostream>
using namespace std;

int dayNumber(int day, int month, int year)
{

	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
					4, 6, 2, 4 };
	year -= month < 3;
	return (year + year / 4 - year / 100 +
		year / 400 + t[month - 1] + day) % 7;
}

int numberOfDays(int monthNumber, int year)
{
	// Janunary
	if (monthNumber == 0)
		return (31);

	// February 
	if (monthNumber == 1)
	{
		// If the year is leap then February has 
		// 29 days 
		if (year % 400 == 0 ||
			(year % 4 == 0 && year % 100 != 0))
			return (29);
		else
			return (28);
	}

	// March 
	if (monthNumber == 2)
		return (31);

	// April 
	if (monthNumber == 3)
		return (30);

	// May 
	if (monthNumber == 4)
		return (31);

	// June 
	if (monthNumber == 5)
		return (30);

	// July 
	if (monthNumber == 6)
		return (31);

	// August 
	if (monthNumber == 7)
		return (31);

	// September 
	if (monthNumber == 8)
		return (30);

	// October 
	if (monthNumber == 9)
		return (31);

	// November 
	if (monthNumber == 10)
		return (30);

	// December 
	if (monthNumber == 11)
		return (31);
}

// Function to print the calendar of the given year 
void printCalendar(int year)
{
	cout<<"\n		         Calendar - "<<year<<"\n";
	int days;
	int current = dayNumber(1, 1, year);
	for (int i = 0; i < 12; i++)
	{
		days = numberOfDays(i, year);
		cout<<"\n ---------------------------- "<<i+1<<"월 -----------------------------\n\n";
		cout<<"	Sun	Mon	Tue	Wed	Thu	Fri	Sat\n";

		int k;
		for (k = 0; k < current; k++)
			cout<<"	 ";

		for (int j = 1; j <= days; j++)
		{
			cout<<"	"<<j;

			if (++k > 6)
			{
				k = 0;
				cout<<"\n";
			}
		}

		if (k)
			cout<<"\n";

		current = k;
	}

	return;
}

int main()
{	
	int year = 0;
	cout<<"이번년도를 입력하시오: ";
	cin>>year;
	printCalendar(year);

	return (0);
}
