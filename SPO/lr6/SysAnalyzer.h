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

    void SetRelationMatrix();
    void ClearStacks();
    virtual void SetRules();
    bool CheckRelation();
    void UseRule();

    protected:
    virtual void FillInputStack(string);

    public:
    SysAnalyzer();
    virtual bool Analyze(string);
    void PrintOutputStack();
};

#endif