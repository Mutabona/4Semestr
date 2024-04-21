#ifndef LLANALYZER
#define LLANALYZER

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <windows.h>

using namespace std;

class LLAnalyzer {
    map<pair<char, char>, int> table;
    map<int, pair<string, string>> rules;

    int head;

    stack<char> workingStack;
    stack<char> outputStack;

    void SetTable();
    void SetRules();
    void DropStacks();
    
    bool ProcessInputSymbol(char s);
    void UseRule(int ruleNumber);
    void Shift();

    void PrintOutputStack();

    public:
    LLAnalyzer();
    bool Analyze(string _input);
};

#endif