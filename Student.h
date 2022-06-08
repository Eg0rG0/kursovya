
#ifndef KURSOVYA_STUDENT_H
#define KURSOVYA_STUDENT_H
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Student {
    string name, surname, patronymic, birth;
    string credits[10];
    string exams[2][5];
    Student() {
        this->name = "0";
        this->surname = "0";
        this->patronymic = "0";
        this->birth = "0";
    }

    Student(const Student &a){
        this->name = a.name;
        this->surname = a.surname;
        this->patronymic = a.patronymic;
        this->birth = a.birth;
        for (int i = 0; i < credits->length(); i++) {
            this->credits[i] = credits[i];
        }
        for (int i = 0; i < 5; i++) {
            this->exams[i][0] = exams[i][0];
            this->exams[i][i] = exams[i][1];
        }

    }
    Student(string name, string surname, string patronymic, string birth) {
        this->name = name;
        this->surname = surname;
        this->patronymic = patronymic;
        this->birth = birth;
    }
};

#endif //KURSOVYA_STUDENT_H
