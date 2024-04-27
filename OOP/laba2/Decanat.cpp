#include "Decanat.h"

void Decanat::PrintStudents() {
    for (auto student : students) {
        student.Print();
    }
}

void Decanat::PrintStudents(string group) {
    for (auto student : students) {
        if (student.group == group)
            student.Print();
    }
}

void Decanat::PrintStudents(int cours) {
    for (auto student : students) {
        if (student.cours == cours)
            student.Print();
    }
}

void Decanat::PrintAVGGradeOfGroups() {
    map<string, double> groupsGrades;
    map<string, size_t> groupsStudentsAmount;
    for (auto student : students) {
        for (auto grade : student.grades) {
            groupsGrades[student.group] += grade.second;
            groupsStudentsAmount[student.group]++;
        }
    }
    for (auto group : groupsGrades) {
        cout << "Group: " << group.first << " Average grade: " << group.second/groupsStudentsAmount[group.first] << endl;
    }
}

void Decanat::AddStudent(Student student) {
    students.push_back(student);
    studentsAmount++;
}

void Decanat::LoadStudentsFromFile(string fileName) {
    ifstream file(fileName, ios::binary|ios::in);
    Student student;
    while(!file.eof()) {
        file.read((char*)&student, sizeof(Student));
        AddStudent(student);
    }
}

void Decanat::SaveStudentsToFile(string fileName) {
    ofstream file(fileName, ios::binary|ios::out);
    for (auto student : students) {
        file.write((char*)&student, sizeof(student));
    }
}