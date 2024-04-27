#ifndef DECANAT
#define DECANAT

#include <Student.h>
#include <deque>
#include <map>
#include <fstream>

using namespace std;

class Decanat {
    deque<Student> students;
    size_t studentsAmount = 0;
    
    public:

    void AddStudent(Student student);

    void LoadStudentsFromFile(string fileName);
    void SaveStudentsToFile(string fileName);

    void PrintStudents();
    void PrintStudents(int cours);
    void PrintStudents(string group);
    void PrintAVGGradeOfGroups();
};

#endif