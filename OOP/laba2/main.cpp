#include <iostream>
#include "Decanat.h"

using namespace std;

int main() {
    string str; 
    Decanat decanat;
    int number;
    int choice = 0;
    do {
        cout << "Load from file - 1" << endl;
        cout << "Save to file - 2" << endl;
        cout << "Print all students - 3" << endl;
        cout << "Print students by group - 4" << endl;
        cout << "Print students by cours - 5" << endl;
        cout << "Print average groups grade - 6" << endl;
        cout << "Quit - 0" << endl;

        cin >> choice;
        switch (choice) {
            case 1:
                cout<<"File: ";
                cin>>str;
                decanat.LoadStudentsFromFile(str);
                break;
            case 2:
                cout<<"File: ";
                cin>>str;
                decanat.SaveStudentsToFile(str);
                break;
            case 3:
                decanat.PrintStudents();
                break;
            case 4:
                cout<<"Group: ";
                cin>>str;
                decanat.PrintStudents(str);
                break;
            case 5:
                cout<<"Cours: ";
                cin>>number;
                decanat.PrintStudents(number);
                break;
            case 6:
                decanat.PrintAVGGradeOfGroups();
                break;
        }

    } while (choice);
}