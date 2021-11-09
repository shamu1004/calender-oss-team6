#define _CRT_SECURE_NO_WARNINGS
#include "HWclass.h"
#include <iostream>
#include <string>
#include <list>
#include <string>




using namespace std;

int main(void) {
    list<HW> homeworklist;
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
        

        homeworklist.push_back(homework);
        cout << ">> Successfully added to list!" << endl;
    }

    string filepath = "./Homeworklist.dat";
    FILE* fp;
    fp = fopen(filepath.c_str(), "a");
    if (fp == nullptr) {
        perror("open() error!");
        return 1;
    }

    list<HW>::iterator iter;
    for (iter = homeworklist.begin(); iter != homeworklist.end(); ++iter) {
        fwrite(&(*iter), sizeof(HW), 1, fp);
    };
    fclose(fp);
    cout << ">> " << homeworklist.size()
        << " students info was successfully saved to the " << filepath << endl;


    fp = fopen(filepath.c_str(), "r");
    list<HW>::iterator newiter;
    fread(&(*newiter), sizeof(HW), 1, fp);
    for (newiter = homeworklist.begin(); newiter != homeworklist.end(); ++newiter) {
        HW newHW;
        newHW = *newiter;
        cout << newHW.returnmonth() << "월" << endl;
        cout << newHW.returndate() << "일" << endl;
        cout << "과제 : " << newHW.returnHWname() << endl;
        cout << "난이도 : " << newHW.returndifficulty() << endl;
        cout << "------------------" << endl;
    }
    
    if (fp == nullptr) {
        perror("open() error!");
        return 1;
    }

    return 0;
}
