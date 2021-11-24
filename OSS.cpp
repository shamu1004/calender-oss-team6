#define _CRT_SECURE_NO_WARNINGS
#include "HWClass.h"
#include "Calendar.h"
#include <iostream>

using namespace std;

int main(void) {
	int inputsize = 0;

	ofstream file_obj;
	file_obj.open("Input.txt", ios::app | ios::binary);

	while (1) {
		string input;

		cout << "캘린더를 보시려면 q, 과제를 입력하시려면 해당 과제의 월을 입력해주세요 : ";
		cin >> input;

		if (input.compare("q") == 0) {
			cout << ">> 캘린더를 확인합니다." << endl;
			break;
		}
		int month = stoi(input);

		cout << "<< 일을 입력하세요 : ";
		int date;
		cin >> date;

		string name = "";
		cout << "<< 과제명을 입력하세요(띄어쓰기 없이 입력하세요) : ";
		cin >> name;

		int difficulty = 1;
		cout << "<< 난이도를 입력하세요 : ";
		cin >> difficulty;

		HW homework(date, month, name, difficulty);

		file_obj.write((char*)&homework, sizeof(homework));

		cout << ">> 성공적으로 추가되었습니다. " << endl;
		inputsize++;
	}
	file_obj.close();

	cout << ">> " << inputsize
		<< " students info was successfully saved to the " << "input.txt" << endl;

	ifstream ifile_obj;
	ifile_obj.open("Input.txt", ios::in | ios::binary);
	HW readhomework;

	//입력받은 HW배열이라고 가정 10개로 일단 고정..
	HW arr[10];

	//과제 갯수가 총 몇 개인줄 세주는 변수
	int num = 0;

	//input에 있는 달력 정보 읽어오는 기능
	do {
		ifile_obj.read((char*)&readhomework, sizeof(readhomework));
		arr[num] = readhomework;
		num++;
		ifile_obj.peek();
	} while (!ifile_obj.eof());

	ifile_obj.close();
	
	//얘는 365로 바꾼 배열
	int arr365[10];

	//다시 월/일/난이도로 돌린 HW 타입 배열 -> 일단 길이 10이라고 가정
	HW arr2[10];

	for (int i = 0; i < num; i++) {
		arr365[i] = calculateCalendar(arr[i].returnmonth(), arr[i].returndate()); // arr365에 정보 입력

		int dm[2]; // recalculateCalendar에서 월/일 공유하는 배열

		recalculateCalendar(arr365[i], dm); // arr365 -> arr2로 다시 되돌려주는 과정
		arr2[i].setHWname(arr[i].returnHWname());
		arr2[i].setmonth(dm[0]);
		arr2[i].setdate(dm[1]);
		arr2[i].setDifficulty(arr[i].returndifficulty());
	}

	printCalendar(2021, arr365);
	
	while (1) {
		int select;
		cout << "1번 : 요일 별 과제 확인 / 2번 : 종료\n";
		cout << "원하는 작업을 입력하세요 : ";
		cin >> select;

		if (select == 1) {
			int month, date, exist;
			cout << "월을 입력하세요.\n";
			cin >> month;
			cout << "일을 입력하세요.\n";
			cin >> date;
			cout << '\n';

			
			int tmpint = 0;
			for (int m = 0; m < 10; m++) {

				if (calculateCalendar(month, date) == arr365[m]) {
					cout << "|--------------------------|\n";
					cout << "과제 이름 : " << arr2[m].returnHWname() << '\n';
					cout << arr2[m].returnmonth() << " 월 " << arr2[m].returndate() << " 일\n";
					cout << "난이도 : " << arr2[m].returndifficulty() << '\n';
					cout << "|--------------------------|\n\n";
					tmpint++;
					
				}
				
			}
			if (tmpint == 0)
				cout << "해당 날짜에 저장된 과제가 없습니다." << '\n';

			
		}
		else if (select == 2)
			break;
		else
			cout << "잘못된 번호를 입력하셨습니다. 다시 입력하세요\n" << '\n';
	}
	return 0;
}