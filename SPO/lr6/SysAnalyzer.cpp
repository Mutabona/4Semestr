#include "SysAnalyzer.h"

bool SysAnalyzer::Analyze(string str) {
    ClearStacks();
    FillInputStack(str);

    workingStack.push(make_pair('$', '0'));

    while ((inputStack.top() != '$') || (workingStack.top().first != '$')) {
        if(!CheckRelation()) return false;
    }

    return true;
}

bool SysAnalyzer::CheckRelation() {
    cout<< "Check Relation ";
    //working stack top
    char wst = workingStack.top().first;
    //input stack top
    char ist = inputStack.top();
    
    cout << wst << ' ' << ist;

    if (relationMatrix.find(make_pair(wst, ist)) != relationMatrix.end() ) {
        char relevance = relationMatrix[make_pair(wst, ist)];
        cout << ' '<< relevance <<endl;
        if (relevance == '<') {
            outputStack.push(ist);
            workingStack.push(make_pair(ist, relevance));
            inputStack.pop();
        }
        else if (relevance == '=') {
            outputStack.push(ist);
            workingStack.push(make_pair(ist, relevance));
            inputStack.pop();
        }
        else if (relevance == '>') {
            UseRule();
        }
    }
    else {
        return false;
    }

    return true;
}

void SysAnalyzer::UseRule() {
    string str = "";
    while (workingStack.top().second != '<') {
        str = workingStack.top().first + str;
        workingStack.pop();
    }
    str = workingStack.top().first + str;
    workingStack.pop();

    cout<< "STR: "<<str<< " ";

    if (rules.find(str) != rules.end()) {
        inputStack.push(rules[str]);
        cout << " To " << rules[str] << endl;
    }
}

void SysAnalyzer::SetRules() {
    rules.emplace("B", 'S');
    rules.emplace("X", 'B');
    rules.emplace("X;B", 'B');
    rules.emplace("O", 'X');
    rules.emplace("IAE", 'O');
    rules.emplace("TI?O:O", 'O');
    rules.emplace("F", 'E');
    rules.emplace("F#E", 'E');
    rules.emplace("P", 'F');
    rules.emplace("P&F", 'F');
    rules.emplace("I", 'P');
    rules.emplace("C", 'P');
    rules.emplace("(E)", 'P');
}

void SysAnalyzer::FillInputStack(string str) {
    inputStack.push('$');
    for (int i = str.size() - 1; i >= 0; i--) {
        inputStack.push(str[i]);
    }
}

SysAnalyzer::SysAnalyzer() {
    SetRelationMatrix();
    SetRules();
}

void SysAnalyzer::SetRelationMatrix() {
    relationMatrix.emplace(make_pair('S', '$'), '>');

    relationMatrix.emplace(make_pair('B', '$'), '>');

    relationMatrix.emplace(make_pair('X', ';'), '=');
    relationMatrix.emplace(make_pair('X', '$'), '>');

    relationMatrix.emplace(make_pair('O', ':'), '=');
    relationMatrix.emplace(make_pair('O', ';'), '>');
    relationMatrix.emplace(make_pair('O', '$'), '>');

    relationMatrix.emplace(make_pair('T', 'I'), '=');

    relationMatrix.emplace(make_pair('I', '?'), '=');
    relationMatrix.emplace(make_pair('I', 'A'), '=');
    relationMatrix.emplace(make_pair('I', ':'), '>');
    relationMatrix.emplace(make_pair('I', '#'), '>');
    relationMatrix.emplace(make_pair('I', '&'), '>');
    relationMatrix.emplace(make_pair('I', ')'), '>');
    relationMatrix.emplace(make_pair('I', ';'), '>');
    relationMatrix.emplace(make_pair('I', '$'), '>');

    relationMatrix.emplace(make_pair('E', ':'), '>');
    relationMatrix.emplace(make_pair('E', ')'), '=');
    relationMatrix.emplace(make_pair('E', ':'), '>');
    relationMatrix.emplace(make_pair('E', ';'), '>');
    relationMatrix.emplace(make_pair('E', '$'), '>');

    relationMatrix.emplace(make_pair('F', ':'), '>');
    relationMatrix.emplace(make_pair('F', '#'), '=');
    relationMatrix.emplace(make_pair('F', ')'), '>');
    relationMatrix.emplace(make_pair('F', ';'), '>');
    relationMatrix.emplace(make_pair('F', '$'), '>');

    relationMatrix.emplace(make_pair('P', ':'), '>');
    relationMatrix.emplace(make_pair('P', '#'), '>');
    relationMatrix.emplace(make_pair('P', ')'), '>');
    relationMatrix.emplace(make_pair('P', ';'), '>');
    relationMatrix.emplace(make_pair('P', '$'), '>');
    relationMatrix.emplace(make_pair('P', '&'), '=');

    relationMatrix.emplace(make_pair('A', 'I'), '<');
    relationMatrix.emplace(make_pair('A', 'E'), '=');
    relationMatrix.emplace(make_pair('A', 'F'), '<');
    relationMatrix.emplace(make_pair('A', 'P'), '<');
    relationMatrix.emplace(make_pair('A', 'C'), '<');
    relationMatrix.emplace(make_pair('A', '('), '<');

    relationMatrix.emplace(make_pair('C', ':'), '>');
    relationMatrix.emplace(make_pair('C', '#'), '>');
    relationMatrix.emplace(make_pair('C', ')'), '>');
    relationMatrix.emplace(make_pair('C', ';'), '>');
    relationMatrix.emplace(make_pair('C', '$'), '>');
    relationMatrix.emplace(make_pair('C', '&'), '>');

    relationMatrix.emplace(make_pair('?', 'O'), '=');
    relationMatrix.emplace(make_pair('?', 'T'), '<');
    relationMatrix.emplace(make_pair('?', 'I'), '<');

    relationMatrix.emplace(make_pair(':', 'O'), '=');
    relationMatrix.emplace(make_pair(':', 'T'), '<');
    relationMatrix.emplace(make_pair(':', 'I'), '<');

    relationMatrix.emplace(make_pair('#', 'E'), '=');
    relationMatrix.emplace(make_pair('#', 'I'), '<');
    relationMatrix.emplace(make_pair('#', 'F'), '<');
    relationMatrix.emplace(make_pair('#', 'P'), '<');
    relationMatrix.emplace(make_pair('#', 'C'), '<');
    relationMatrix.emplace(make_pair('#', '('), '<');

    relationMatrix.emplace(make_pair('&', 'I'), '<');
    relationMatrix.emplace(make_pair('&', 'F'), '=');
    relationMatrix.emplace(make_pair('&', 'P'), '<');
    relationMatrix.emplace(make_pair('&', 'C'), '<');
    relationMatrix.emplace(make_pair('&', '('), '<');

    relationMatrix.emplace(make_pair('(', 'E'), '=');
    relationMatrix.emplace(make_pair('(', 'I'), '<');
    relationMatrix.emplace(make_pair('(', 'F'), '<');
    relationMatrix.emplace(make_pair('(', 'P'), '<');
    relationMatrix.emplace(make_pair('(', 'C'), '<');
    relationMatrix.emplace(make_pair('(', '('), '<');

    relationMatrix.emplace(make_pair(')', ':'), '>');
    relationMatrix.emplace(make_pair(')', '#'), '>');
    relationMatrix.emplace(make_pair(')', ')'), '>');
    relationMatrix.emplace(make_pair(')', ';'), '>');
    relationMatrix.emplace(make_pair(')', '$'), '>');
    relationMatrix.emplace(make_pair(')', '&'), '>');

    relationMatrix.emplace(make_pair(';', 'B'), '=');
    relationMatrix.emplace(make_pair(';', 'O'), '<');
    relationMatrix.emplace(make_pair(';', 'T'), '<');
    relationMatrix.emplace(make_pair(';', 'I'), '<');
    relationMatrix.emplace(make_pair(';', 'X'), '<');

    relationMatrix.emplace(make_pair('$', 'S'), '<');
    relationMatrix.emplace(make_pair('$', 'B'), '<');
    relationMatrix.emplace(make_pair('$', 'O'), '<');
    relationMatrix.emplace(make_pair('$', 'T'), '<');
    relationMatrix.emplace(make_pair('$', 'I'), '<');
    relationMatrix.emplace(make_pair('$', 'X'), '<');
}

void SysAnalyzer::ClearStacks() {
    while (!inputStack.empty()) inputStack.pop();
    while (!outputStack.empty()) outputStack.pop();
    while (!workingStack.empty()) workingStack.pop();
}

void SysAnalyzer::PrintOutputStack() {
    cout<<"\nOutput stack: ";
    while (!outputStack.empty()) {
        cout<<outputStack.top();
        outputStack.pop();
    }
    cout<<'\n';
}