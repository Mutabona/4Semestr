#include "student.h"

void Student::Print() {
    cout << FIO << " Group: "<< group << " Cours: " << cours << endl;
    for (auto grade : grades) {
        cout << "Subject: " << grade.first << " Grade: " << grade.second << endl;
    }
}

// Student::Student(string _FIO, string _group, unsigned short _cours, map<string, unsigned short> _grades) {
//     FIO = _FIO;
//     group = _group;
//     cours = _cours;
//     grades = _grades;
// }