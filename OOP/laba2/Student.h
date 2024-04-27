#ifndef STUDENT
#define STUDENT

#include <iostream>
#include <map>

using namespace std;

class Student {
    public:
    string FIO;
    map<string, unsigned short> grades;
    string group;
    unsigned short cours;

    // Student(string _FIO, string _group, unsigned short _cours, map<string, unsigned short> _grades);
    void Print();
};

#endif