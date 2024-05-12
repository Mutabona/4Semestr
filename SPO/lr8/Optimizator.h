#ifndef OPTIMIZATOR
#define OPTIMIZATOR

#include <iostream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

class Optimizator {
    map<string, int> signOfUse;
    vector<vector<string>> objectCode;

    void ProcessOperation(vector<string>);
    bool ProcessAssignment(vector<string>);

    void ReplaceVariable(string);

    void IncreaseSignOfUse(string);

    string GetReplacingVariable(string var);

    public:
    vector<vector<string>> Optimize(vector<vector<string>>);
};

#endif