#include "LRAnalyzer.h"

bool LRAnalyzer::Analyze(string str) {
    ClearStacks();
    FillInputStack(str);

    workingStack.push(make_pair('$', 1));

    while (workingStack.top().second != 0) {
        cout<<"State: "<< workingStack.top().second << " IS top: " << inputStack.top() << endl;
        if (rules.find(make_pair(workingStack.top().second, inputStack.top())) != rules.end()) {
            auto rule = rules[make_pair(workingStack.top().second, inputStack.top())]; 
            for (int i = 0; i < rule.second; i++) {
                workingStack.pop();
            }
            inputStack.push(rule.first);
        } else if (shifts.find(make_pair(workingStack.top().second, inputStack.top())) != shifts.end()) {
            unsigned short state = shifts[make_pair(workingStack.top().second, inputStack.top())];
            outputStack.push(inputStack.top());
            workingStack.push(make_pair(inputStack.top(), state));
            inputStack.pop();
        } else {
            return false;
        }
    }
    return true;
}

void LRAnalyzer::FillInputStack(string str) {
    inputStack.push('$');
    for (int i = str.size() - 1; i >= 0; i--) {
        inputStack.push(str[i]);
    }
}

void LRAnalyzer::SetRules() {
    //rule 1
    rules.emplace(make_pair(2, '$'), make_pair('S', 1));
    //rule 2
    rules.emplace(make_pair(5, '$'), make_pair('B', 3));
    //rule 3
    rules.emplace(make_pair(3, '$'), make_pair('B', 1));
    //rule 4
    rules.emplace(make_pair(8, ';'), make_pair('O', 3));
    rules.emplace(make_pair(8, ':'), make_pair('O', 3));
    rules.emplace(make_pair(8, '$'), make_pair('O', 3));
    //rule 5
    rules.emplace(make_pair(14, ';'), make_pair('O', 6));
    rules.emplace(make_pair(14, ':'), make_pair('O', 6));
    rules.emplace(make_pair(14, '$'), make_pair('O', 6));
    //rule 6
    rules.emplace(make_pair(17, ';'), make_pair('E', 3));
    rules.emplace(make_pair(17, ':'), make_pair('E', 3));
    rules.emplace(make_pair(17, '$'), make_pair('E', 3));
    rules.emplace(make_pair(17, ')'), make_pair('E', 3));
    //rule 7
    rules.emplace(make_pair(15, ';'), make_pair('E', 1));
    rules.emplace(make_pair(15, ':'), make_pair('E', 1));
    rules.emplace(make_pair(15, '$'), make_pair('E', 1));
    rules.emplace(make_pair(15, ')'), make_pair('E', 1));
    //rule 8
    rules.emplace(make_pair(20, ';'), make_pair('F', 3));
    rules.emplace(make_pair(20, ':'), make_pair('F', 3));
    rules.emplace(make_pair(20, '$'), make_pair('F', 3));
    rules.emplace(make_pair(20, ')'), make_pair('F', 3));
    rules.emplace(make_pair(20, '#'), make_pair('F', 3));
    //rule 9
    rules.emplace(make_pair(18, ';'), make_pair('F', 1));
    rules.emplace(make_pair(18, ':'), make_pair('F', 1));
    rules.emplace(make_pair(18, '$'), make_pair('F', 1));
    rules.emplace(make_pair(18, ')'), make_pair('F', 1));
    rules.emplace(make_pair(18, '#'), make_pair('F', 1));
    //rule 10
    rules.emplace(make_pair(21, ';'), make_pair('P', 1));
    rules.emplace(make_pair(21, ':'), make_pair('P', 1));
    rules.emplace(make_pair(21, '$'), make_pair('P', 1));
    rules.emplace(make_pair(21, ')'), make_pair('P', 1));
    rules.emplace(make_pair(21, '#'), make_pair('P', 1));
    rules.emplace(make_pair(21, '&'), make_pair('P', 1));
    //rule 11
    rules.emplace(make_pair(22, ';'), make_pair('P', 1));
    rules.emplace(make_pair(22, ':'), make_pair('P', 1));
    rules.emplace(make_pair(22, '$'), make_pair('P', 1));
    rules.emplace(make_pair(22, ')'), make_pair('P', 1));
    rules.emplace(make_pair(22, '#'), make_pair('P', 1));
    rules.emplace(make_pair(22, '&'), make_pair('P', 1));
    //rule 12
    rules.emplace(make_pair(25, ';'), make_pair('P', 3));
    rules.emplace(make_pair(25, ':'), make_pair('P', 3));
    rules.emplace(make_pair(25, '$'), make_pair('P', 3));
    rules.emplace(make_pair(25, ')'), make_pair('P', 3));
    rules.emplace(make_pair(25, '#'), make_pair('P', 3));
    rules.emplace(make_pair(25, '&'), make_pair('P', 3));
}

void LRAnalyzer::SetShifts() {
    shifts.emplace(make_pair(1, 'S'), 0);
    shifts.emplace(make_pair(1, 'B'), 2);
    shifts.emplace(make_pair(1, 'O'), 3);
    shifts.emplace(make_pair(1, 'T'), 9);
    shifts.emplace(make_pair(1, 'I'), 6);

    shifts.emplace(make_pair(3, ';'), 4);

    shifts.emplace(make_pair(4, 'B'), 5);
    shifts.emplace(make_pair(4, 'O'), 3);
    shifts.emplace(make_pair(4, 'T'), 9);
    shifts.emplace(make_pair(4, 'I'), 6);

    shifts.emplace(make_pair(6, 'A'), 7);

    shifts.emplace(make_pair(7, 'E'), 8);
    shifts.emplace(make_pair(7, 'F'), 15);
    shifts.emplace(make_pair(7, 'P'), 18);
    shifts.emplace(make_pair(7, 'I'), 21);
    shifts.emplace(make_pair(7, 'C'), 22);
    shifts.emplace(make_pair(7, '('), 23);

    shifts.emplace(make_pair(9, 'I'), 10);

    shifts.emplace(make_pair(10, '?'), 11);

    shifts.emplace(make_pair(11, 'O'), 12);
    shifts.emplace(make_pair(11, 'T'), 9);
    shifts.emplace(make_pair(11, 'I'), 6);

    shifts.emplace(make_pair(12, ':'), 13);

    shifts.emplace(make_pair(13, 'O'), 14);
    shifts.emplace(make_pair(13, 'T'), 9);
    shifts.emplace(make_pair(13, 'I'), 6);

    shifts.emplace(make_pair(15, '#'), 16);

    shifts.emplace(make_pair(16, 'F'), 15);
    shifts.emplace(make_pair(16, 'P'), 18);
    shifts.emplace(make_pair(16, 'I'), 21);
    shifts.emplace(make_pair(16, 'C'), 22);
    shifts.emplace(make_pair(16, '('), 23);
    shifts.emplace(make_pair(16, 'E'), 17);

    shifts.emplace(make_pair(18, '&'), 19);

    shifts.emplace(make_pair(19, 'F'), 20);
    shifts.emplace(make_pair(19, 'P'), 18);
    shifts.emplace(make_pair(19, 'I'), 21);
    shifts.emplace(make_pair(19, 'C'), 22);
    shifts.emplace(make_pair(19, '('), 23);

    shifts.emplace(make_pair(23, 'F'), 15);
    shifts.emplace(make_pair(23, 'P'), 18);
    shifts.emplace(make_pair(23, 'I'), 21);
    shifts.emplace(make_pair(23, 'C'), 22);
    shifts.emplace(make_pair(23, '('), 23);
    shifts.emplace(make_pair(23, 'E'), 24);

    shifts.emplace(make_pair(24, ')'), 25);
}

LRAnalyzer::LRAnalyzer() {
    SetRules();
    SetShifts();
}

void LRAnalyzer::ClearStacks() {
    while (!inputStack.empty()) inputStack.pop();
    while (!outputStack.empty()) outputStack.pop();
    while (!workingStack.empty()) workingStack.pop();
}