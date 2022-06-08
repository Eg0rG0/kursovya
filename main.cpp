#include <iostream>
#include "Student.h"
#include <fstream>
#include <vector>
#include "function.h"

using namespace std;

int main() {
    cout << "Hello my dear user! You got into the database program" << endl
         << "Enter the number of students" << endl;
    bool a;
    int ns;
    cin >> ns;
    cout << "If you create database on console enter 1" << endl
         << "If you already have database enter 0" << endl;
    cin >> a;
    Student** db;
    if (a) {
        db = createDB();
    }
    else {
        db = createDB(ns);
    }
    int value;
    while (true) {

        cout << "If you want to sort database, enter 0" << endl
             << "If you want to search the student, enter 1" << endl
             << "If you want to remove the student, enter 2" << endl
             << "If you want to change information of student, enter 3" << endl
             << "If you want to display database on screen, enter 4" << endl
             << "if you want to exit from menu, enter 5" << endl;
        cin >> value;
        switch (value) {
            case 0:
                sort_by_surname(db, ns);
                break;
            case 1:
                search(db, ns);
                break;
            case 2:
                remove(db, ns);
                break;
            case 3:
                change(db, ns);
                break;
            case 4:
                output(db, ns);
                break;
            case 5:
                free(db);
                return 0;
        }
    }
    free(db);
    return 0;
}
