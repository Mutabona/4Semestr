#ifndef SYSANALYZER
#define SYSANALYZER

#include <iostream>
#include <map>
#include <stack>
#include <windows.h>
#include <vector>

using namespace std;

class SysAnalyzer {
    stack<char> inputStack;
    stack<char> outputStack;
    stack<pair<char, char>> workingStack;
    map<pair<char, char>, char> relationMatrix;
    map<string, char> rules;

    void FillInputStack(string);
    void SetRelationMatrix();
    void ClearStacks();
    void SetRules();
    bool CheckRelation();
    void UseRule();
    void PrintOutputStack();

    public:
    SysAnalyzer();
    bool Analyze(string);
};

#endif