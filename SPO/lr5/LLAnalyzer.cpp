#include <iostream>
#include <vector>
#include <map>

using namespace std;

class LLAnalyzer {
    map<int, pair<string, string>> table;
    map<int, pair<string, vector<string>>> rules;

    void SetTable();
    void SetRules();
};

void LLAnalyzer::SetTable() {
    table.emplace(1, make_pair("S", "I"));
    table.emplace(1, make_pair("B", "T"));
    table.emplace(1, make_pair("B", "I"));
    table.emplace(1, make_pair("O", "T"));
    table.emplace(1, make_pair("O", "I"));
    table.emplace(1, make_pair("?", "I"));
    table.emplace(1, make_pair("?", "T"));
}

void LLAnalyzer::SetRules() {
    rules.emplace(1, make_pair("S", "B"));

    rules.emplace(2, make_pair("B", ("O", "X")));

    rules.emplace(3, make_pair("X", (";", "B")));
    rules.emplace(4, make_pair("X", "0"));

    rules.emplace(5, make_pair("O", ("I", "A", "E")));
    rules.emplace(6, make_pair("O", ("T", "I", "?", "O", ":", "O")));

    rules.emplace(7, make_pair("E", ("F", "Y")));

    rules.emplace(8, make_pair("Y", ("#", "E")));
    rules.emplace(9, make_pair("Y", "0"));

    rules.emplace(6, make_pair("F", ("P", "Z")));

    rules.emplace(6, make_pair("Z", ("&", "F")));
    rules.emplace(2, make_pair("Z", "0"));

    rules.emplace(7, make_pair("P", "I"));
    rules.emplace(8, make_pair("P", "C"));
    rules.emplace(9, make_pair("P", ("(", "E", ")")));

}