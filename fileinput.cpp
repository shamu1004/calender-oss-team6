#define _CRT_SECURE_NO_WARNINGS
#include "HWclass.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <string>



using namespace std;

int main(void) {


    int inputsize = 0;
    ofstream file_obj;
    file_obj.open("Input.txt", ios::app | ios::binary);
    while (1) {
        string input;

        cout << "<< month (input \'q\' to terminate): ";
        cin >> input;

        if (input.compare("q") == 0) {
            cout << ">> Terminate input." << endl;
            break;
        }
        int month = stoi(input);

        cout << "<< date : ";
        int date;
        cin >> date;


        string name = "";
        cout << "<< HomeWork Name: ";
        cin >> name;

        int difficulty = 1;
        cout << "<< Difficulty: ";
        cin >> difficulty;


        HW homework(date, month, name, difficulty);


        file_obj.write((char*)&homework, sizeof(homework));




        cout << ">> Successfully added to list!" << endl;
        inputsize++;
    }
    file_obj.close();


    cout << ">> " << inputsize
        << " students info was successfully saved to the " << "input.txt" << endl;

    ifstream ifile_obj;
    ifile_obj.open("Input.txt", ios::in | ios::binary);
    HW readhomework;
    do {

        ifile_obj.read((char*)&readhomework, sizeof(readhomework));
        cout << readhomework.returnmonth() << "월" << endl;
        cout << readhomework.returndate() << "일" << endl;
        cout << "과제 : " << readhomework.returnHWname() << endl;
        cout << "난이도 : " << readhomework.returndifficulty() << endl;
        cout << "------------------" << endl;
        ifile_obj.peek();
    } while (!ifile_obj.eof());
    ifile_obj.close();


    return 0;
}