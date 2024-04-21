#include "LLAnalyzer.h"

void LLAnalyzer::DropStacks() {
    while (!workingStack.empty()) workingStack.pop();
    while (!outputStack.empty()) outputStack.pop();
}

void LLAnalyzer::SetTable() {
    table.emplace(make_pair('S', 'I'), 1);
    table.emplace(make_pair('S', 'T'), 1);

    table.emplace(make_pair('B', 'T'), 2);
    table.emplace(make_pair('B', 'I'), 2);

    table.emplace(make_pair('O', 'I'), 5);
    table.emplace(make_pair('O', 'T'), 6);

    table.emplace(make_pair('T', 'T'), 16);

    table.emplace(make_pair('I', 'I'), 17);

    table.emplace(make_pair('?', '?'), 18);

    table.emplace(make_pair(':', ':'), 19);
    
    table.emplace(make_pair('A', 'A'), 20);

    table.emplace(make_pair('X', ';'), 3);
    table.emplace(make_pair('X', '$'), 4);

    table.emplace(make_pair(';', ';'), 21);

    table.emplace(make_pair('$', '$'), 22);

    table.emplace(make_pair('E', 'I'), 7);
    table.emplace(make_pair('E', 'C'), 7);
    table.emplace(make_pair('E', '('), 7);

    table.emplace(make_pair('F', 'I'), 10);
    table.emplace(make_pair('F', 'C'), 10);
    table.emplace(make_pair('F', '('), 10);

    table.emplace(make_pair('Y', '#'), 8);
    table.emplace(make_pair('Y', '$'), 9);
    table.emplace(make_pair('Y', ':'), 9);
    table.emplace(make_pair('Y', ';'), 9);
    table.emplace(make_pair('Y', ')'), 9);

    table.emplace(make_pair('#', '#'), 23);

    table.emplace(make_pair('P', 'I'), 13);
    table.emplace(make_pair('P', 'C'), 14);
    table.emplace(make_pair('P', '('), 15);

    table.emplace(make_pair('(', '('), 24);
    table.emplace(make_pair(')', ')'), 25);

    table.emplace(make_pair('Z', '&'), 11);
    table.emplace(make_pair('Z', '$'), 12);
    table.emplace(make_pair('Z', ':'), 12);
    table.emplace(make_pair('Z', ';'), 12);
    table.emplace(make_pair('Z', ')'), 12);
    table.emplace(make_pair('Z', '#'), 12);

    table.emplace(make_pair('C', 'C'), 26);

    table.emplace(make_pair('&', '&'), 27);
}

void LLAnalyzer::SetRules() {
    rules.emplace(1, make_pair("S", "B"));

    rules.emplace(2, make_pair("B", "OX"));

    rules.emplace(3, make_pair("X", ";B"));
    rules.emplace(4, make_pair("X", "lambda"));

    rules.emplace(5, make_pair("O", "IAE"));
    rules.emplace(6, make_pair("O", "TI?O:O"));

    rules.emplace(7, make_pair("E", "FY"));

    rules.emplace(8, make_pair("Y", "#E"));
    rules.emplace(9, make_pair("Y", "lambda"));

    rules.emplace(10, make_pair("F", "PZ"));

    rules.emplace(11, make_pair("Z", "&F"));
    rules.emplace(12, make_pair("Z", "lambda"));

    rules.emplace(13, make_pair("P", "I"));
    rules.emplace(14, make_pair("P", "C"));
    rules.emplace(15, make_pair("P", "(E)"));

    rules.emplace(16, make_pair("T", "0"));

    rules.emplace(17, make_pair("I", "0"));

    rules.emplace(18, make_pair("?", "0"));

    rules.emplace(19, make_pair(":", "0"));

    rules.emplace(20, make_pair("A", "0"));

    rules.emplace(21, make_pair(";", "0"));

    rules.emplace(22, make_pair("$", "0"));

    rules.emplace(23, make_pair("#", "0"));

    rules.emplace(24, make_pair("(", "0"));
    rules.emplace(25, make_pair(")", "0"));

    rules.emplace(26, make_pair("C", "0"));

    rules.emplace(27, make_pair("&", "0"));
}

LLAnalyzer::LLAnalyzer() {
    SetTable();
    SetRules();
}

bool LLAnalyzer::Analyze(string _input) {
    DropStacks();

    workingStack.push('$');
    workingStack.push('S');

    head = 0;
    
    _input += '$';

    while (head < _input.size()) {
        if (!ProcessInputSymbol(_input[head])) {
            cout<<"Symbol: "<<_input[head]<<endl;
            PrintOutputStack();
            return false;
        }
    }
    PrintOutputStack();
    return true;
}

bool LLAnalyzer::ProcessInputSymbol(char c) {
    int ruleNumber;
    if (table.find(make_pair(workingStack.top(), c)) != table.end()) {
        ruleNumber = table[make_pair(workingStack.top(), c)];
        if (rules[ruleNumber].second == "0") {
            cout<<"SHIFT WS TOP: "<< workingStack.top() << " C:" << c <<endl;
            Shift();
        }
        else if (rules[ruleNumber].second == "lambda") {
            cout<<"Lambda: "<<workingStack.top()<<endl;
            workingStack.pop();
        }
        else {
            cout<<"Use rule: "<<ruleNumber <<" WS TOP: "<<workingStack.top() << " C:" << c <<endl;
            UseRule(ruleNumber);
        } 
        return true;
    }
    else {
        return false;
    }
}

void LLAnalyzer::UseRule(int ruleNumber) {
    char c = workingStack.top();
    outputStack.push(c);
    workingStack.pop();
    for (int j = rules[ruleNumber].second.size()-1; j >= 0 ; j--) {
        //cout<<"Add: "<<rules[ruleNumber].second[j]<<endl;
        workingStack.push(rules[ruleNumber].second[j]);
    }
}

void LLAnalyzer::Shift() {
    char c = workingStack.top();
    workingStack.pop();
    outputStack.push(c);
    head++;
}

void LLAnalyzer::PrintOutputStack() {
    cout<<"\nOutput stack: ";
    while (!outputStack.empty()) {
        cout<<outputStack.top();
        outputStack.pop();
    }
    cout<<'\n';
}