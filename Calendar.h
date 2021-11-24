#pragma once
#include "HWClass.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <string>

static int isLeap = 0;
static int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// ------------------ 캘린더 함수 -----------------//
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
			(year % 4 == 0 && year % 100 != 0)) {
			isLeap = 1;
			return (29);
		}
		else {
			isLeap = 0;
			return (28);
		}
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

// 어차피 난이도는 여기에 표시해 줄 필요가 없어서 지워버림.(어차피 입력값에서 그대로 받아오니까)
int calculateCalendar(int month, int day) {
	//1월부터 12월
	int result = 0;
	if (day > 0) {
		for (int i = 0; i < month - 1; i++) {
			result += days[i];
		}
		result += day;
	}
	else if (day <= 0) {
		for (int i = 0; i < month - 2; i++) {
			result += days[i];
		}
		result += days[month-2] + day;
	}
	

	

	//윤년일 때는 하루 더해줌
	if (isLeap && month > 2) {
		result += 1;
	}

	return result;
}
// 뒤 배열은 어차피 main쪽이랑 공유됨. 배열 자체 리턴이 안되서 이런식으로 바꿈.
void recalculateCalendar(int date, int arr[]) { 

	int input = date;
	int month = 1;
	int day = 0;

	for (int i = 0; i < 12; i++) {
		if (input - days[i] > 0) {
			month++;
			input -= days[i];
		}
		else {
			day = input;
		}
	}

	arr[0] = month;
	arr[1] = day;
}


// Function to print the calendar of the given year 
void printCalendar(int year, int arr[],int arr2[])
{
	cout << "\n		         Calendar - " << year << "\n";

	int cdays; // 배열 days와 구분 위한 명칭 변경 days => cdays
	int current = dayNumber(1, 1, year);

	for (int i = 0; i < 12; i++)
	{
		cdays = numberOfDays(i, year);
		cout << "\n ---------------------------- " << i + 1 << "월 -----------------------------\n\n";
		cout << "	Sun	Mon	Tue	Wed	Thu	Fri	Sat\n";

		int k;
		for (k = 0; k < current; k++)
			cout << "\t";

		for (int j = 1; j <= cdays; j++) {
			// 일치 여부 확인용 boolean 변수
			bool cor = false;
			// i=월, j=일. i,j를 받아가서 숫자로 변환하고 그 숫자랑 가져온 배열에 들어있는 값 중 하나라도 일치한다면 뒤에 *표시 넣어주면 됨
			for (int m = 0; m < 10; m++) {
				if (calculateCalendar(i+1, j) == arr[m])
					cor = true;
			}
			bool cor2 = false;
			for (int m = 0; m < 10; m++) {
				if (calculateCalendar(i + 1, j) == arr2[m])
					cor2 = true;
			}

			// 일치시 *표시
			if (cor && cor2) {
				cout << '\t' << j << '*'<<'!';
				cor = false;
				cor2 = false;
			}
				
			else if(cor)
				cout << '\t' << j << '*';
			else if(cor2)
				cout << '\t' << j << '!';
			else
				cout << '\t' << j;

			
			

			if (++k > 6)
			{
				k = 0;
				cout << "\n";
			}
		}

		if (k)
			cout << "\n";

		current = k;
	}
	return;
}
// ------------------ 캘린더 함수 -----------------//
