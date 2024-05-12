#include "Optimizator.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

vector<string> split(const string& str, const string& delim) 
{
    vector<string> tokens;
    size_t pos = 0;
    while (pos < str.length()) 
    {
        // Find the position of the next occurrence of the delimiter
        size_t next = str.find(delim, pos);
        if (next == string::npos) 
        {
            next = str.length();
        }
        // Extract the token from the string
        string token = str.substr(pos, next-pos);
        if (!token.empty())
        {
            tokens.push_back(token);
        }
        // Update the position to start searching from the next character
        pos = next + delim.length();
    }
    return tokens;
}

int main() {
    Optimizator optimizator;
    ifstream file("test.txt");
    vector<string> objCode;
    string str;
    while(getline(file, str)) { 
        objCode.push_back(str);
        str.clear();
    }
    file.close();
    vector<vector<string>> objectCode;
    for (auto str : objCode) {
        objectCode.push_back(split(str, " "));
    }
    vector<vector<string>> optimized = optimizator.Optimize(objectCode);
    for (auto triad : optimized) {
        cout << setiosflags(ios::left) << setw(2) << triad[0] <<" " << setw(2) << triad[1] <<" " << setw(2) << triad[2] <<" " << endl;
    }
    return 0;
}