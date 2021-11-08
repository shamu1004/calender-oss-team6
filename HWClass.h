#pragma once
#include <iostream>
#include <string>
using namespace std;
class HW {
private:
	int date;
	int month;
	string hwname;
	int difficulty;
public:
	HW() {
		date = 0;
		month = 0;
		hwname = "";
		difficulty = 0;
	}
	HW(const HW &homework);
	int returndate() { return date; }
	int returnmonth() { return month; }
	string returnHWname() { return hwname; }
	int returndifficulty() { return difficulty; }
	void setdate(const int source);
	void setmonth(const int source);
	void setHWname(const string source);
	void setDifficulty(const int difficulty);
};
void HW::setdate(const int source) {
	this->date = source;
}
HW::HW(const HW& homework) {
	this->date = homework.date;
	this->month = homework.month;
	this->hwname = homework.hwname;
	this->difficulty = homework.difficulty;
}
void HW::setmonth(const int source) {
	this->month = source;
}
void HW::setHWname(const string source) {
	this->hwname = source;
}

void HW::setDifficulty(const int source) {
	this->difficulty = source;
}
