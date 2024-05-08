#ifndef LRANALYZER
#define LRANALYZER

#include "../lr6/SysAnalyzer.h"

#include <map>
#include <iostream>
#include <stack>

using namespace std;

class LRAnalyzer {
    map<pair<unsigned short, char>, pair<char, size_t>> rules;
    map<pair<unsigned short, char>, unsigned short> shifts;
    stack<char> inputStack;
    stack<char> outputStack;
    stack<pair<char, unsigned short>> workingStack;

    void SetRules();
    void SetShifts();
    void ClearStacks();
    void FillInputStack(string);

    public:
    LRAnalyzer();
    bool Analyze(string);
};

#endif