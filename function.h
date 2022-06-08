#include <iostream>
#include <fstream>
#include <string>

#ifndef KURSOVYA_FUNCTION_H
#define KURSOVYA_FUNCTION_H

#endif //KURSOVYA_FUNCTION_H

void search(Student **db, int ns) {
    cout << "Enter full name of students " << endl;
    string name, surname, patronymic;
    cin >> name >> surname >> patronymic;
    for (int i = 0; i < ns; i++) {
        if ((db[i]->name == name) && (db[i]->surname == surname) && (db[i]->patronymic == patronymic)) {
            cout << "Full name: " << db[i]->name << " " << db[i]->surname << " " << db[i]->patronymic
                 << " date of birth: " << db[i]->birth << endl;
            cout << " credits:" << endl;
            for (string & credit : db[i]->credits) {
                if (credit == "not_a_credit")
                    cout << "not_a_credit" << endl;
                else
                    cout << "delivery date:" << credit << endl;
            }
            cout << "exams:" << endl;
            for (int j = 0; j < 5; j++) {
                cout << "mark: " << db[i]->exams[0][j];
                cout << ", delivery date: " << db[i]->exams[1][j] << endl;
            }
        }
    }
}

void remove(Student **db, int ns) {
    cout << "Enter the number of student which you want to remove " << endl;
    int nr;
    cin >> nr;
    if (nr > ns ) {
        cout << " You enter incorrect number of student" << endl;
        return;
    }
    free(db[nr - 1]);
    for (int i = nr - 1; i < ns - 1; ++i) {
        db[i] = db[i + 1];
    }
    ns--;
}

void change(Student **db, int ns) {
    cout << "Enter the number of student whose information you want to change" << endl;
    int nr;
    cin >> nr;
    if (nr > ns ) {
        cout << " You enter incorrect number of student" << endl;

    }
    bool l;
    while (true) {
        cout << "Enter down what you want to change" << endl;
        string st, rem, newdate;
        int numb, newmark;
        cin >> st;
        if (st == "name") {
            cout << "Enter new name" << endl;
            cin >> rem;
            db[nr]->name = rem;

        } else if (st == "surname") {
            cout << "Enter new surname" << endl;
            cin >> rem;
            db[nr]->surname = rem;
        } else if (st == "patronymic") {
            cout << "Enter new patronymic" << endl;
            cin >> rem;
            db[nr]->patronymic = rem;
        } else if (st == "mark of exam") {
            cout << "Enter number of exam and new mark" << endl;
            cin >> numb >> newmark;
            if (numb > 4 ) {
                cout << " You enter incorrect number of exam " << endl;
                break;
            }
            db[nr]->exams[0][numb] = rem;
        } else if (st == "date of exam") {
            cout << "Enter number of exam and new date" << endl;
            if (numb > 4 ) {
                cout << " You enter incorrect number of exam " << endl;
                break;
            }
            cin >> numb >> newdate;
            db[nr]->exams[1][numb] = newdate;
        } else if (st == "date for credit") {
            cout << "Enter number of credit and new date, if you want change status "
                 << "credit just write date of pass/not a credit" << endl;
            if (numb > 9 ) {
                cout << " You enter incorrect number of exam " << endl;
                break;
            }
            cin >> numb >> newdate;
            db[nr]->credits[numb] = newdate;
        }
        cout << "if you want to exit enter 0" << endl
             << "if you want to continue enter 1" << endl;
        cin >> l;
        if (!l) {
            break;
        }
    }
}

void output(Student **db, int ns){
    for (int i = 0; i < ns; ++i) {
        cout << i+1  << " Full name: " << db[i]->name << " " << db[i]->surname << " " << db[i]->patronymic
             << " date of birth: " << db[i]->birth << endl;
    }
    for (int i = 0; i < ns; ++i) {
        cout << "index of student: " << i+1 << endl << "exams: " << endl;
        for (int j = 0; j < 5; ++j) {
            cout  << "sub: " << j + 1  <<" mark: "<< db[i]->exams[0][j] << " date:" << db[i]->exams[1][j] << endl;
        }
    }
    for (int i = 0; i < ns; ++i) {
        cout << "index of student: " << i+1 << endl << "credits: " << endl;
        for (int j = 0; j < 10; ++j) {
            if(db[i]->credits[j] == "not a credit")
                cout << "sub: " << j << ' ' << "not a credit" << endl;
            else
                cout << "sub: " << j << ' '<< "date: " << db[i]->credits[j] << endl;
        }
    }
}

Student** createDB() {
    cout << "You are in the menu for creating a database of students" << endl
         << "Enter the number of students" << endl;
    int ns;
    cin >> ns;
    Student * *db;
    db = (Student **) malloc(ns * sizeof(Student *));
    Student a;
    for (int i = 0; i < ns; ++i) {
        db[i] = &a;
    }
    if (db == nullptr) cout << "error, memory not allocated" << endl;
    cout << "Enter the student's full name and date of birth, each new student from a new line" << endl;
    for (int i = 0; i < ns + 1; i++) {
        string n, sn, p, d;
        cin >> n >> sn >> p >> d;
        db[i] = new Student(n, sn, p, d);
    }
    for (int i = 0; i < 11; i++) {
        cout << "Enter credits for subjects and delivery date" << endl;
        string cr, date;
        cin >> cr;
        if (cr == "credit pass") {
            cin >> date;
        } else {
            date = "Contact the training department for the date of your transfer";
        }
        db[i]->credits[i] = date;
    }
    for (int i = 0; i < 6; i++) {
        cout << "Enter exam for subjects and delivery date" << endl;
        string date;
        string mark;
        cin >> mark;
        if (mark == "3" || mark == "4" || mark == "5") {
            cin >> date;
            cout << "Enter date of pass" << endl;
            cin >> date;
            db[i]->exams[i][0] = mark;
            db[i]->exams[i][0] = date;
        } else {
            date = "Contact the training department for the date of your transfer";
            db[i]->exams[i][0] = "2";
            db[i]->exams[i][0] = "Contact the training department for the date of your transfer";
        }
    }
    return db;
}

Student** createDB(int ns) {
    string filename;
    Student * *db;
    db = (Student**) malloc(ns * sizeof(Student *));
    cout << "Enter name of file" << endl;
    cin >> filename;
    ifstream file;
    file.open(filename);
    string k, st;
    if (!file.is_open()) {
        cout << "the file was not opened, file name is incorrect " << endl;
    }
    for (int i = 0; i < ns; i++) {
        string n, sn, p;
        getline(file, n, ',');
        getline(file, sn, ',');
        getline(file, p, ',');
        getline(file, k, ',');
        db[i] = new Student(n, sn, p, k);
    }
    for (int i = 0; i < ns; i++) {
        for (int j = 0; j < 5; ++j) {
            string a, a1;
            getline(file, a, ',');
            db[i]->exams[1][j] = a;
            getline(file, a1, ',');
            db[i]->exams[0][j] = a1;
        }
    }

    for (int i = 0; i < ns; i++) {
        for (int j = 0; j < 10; ++j) {
            getline(file, k, ',');
            db[i]->credits[j] = k;
        }
    }
    return db;
}

bool bigger(const string& first, const string& second) {
    vector<string> arr1 = {first, second};
    vector<string> arr2 = {first, second};
    sort(arr2.begin(), arr2.end());
    return arr1.at(0) == arr2.at(0);
}

void sort_by_surname(Student** db, int ns) {
    for (int i = 0; i < ns - 1; i++)
        for (int j = 0; j < ns - i - 1; j++)
            if (bigger(db[j + 1]->surname, db[j]->surname))
                swap(db[j], db[j + 1]);
    cout << "done" << endl;
}