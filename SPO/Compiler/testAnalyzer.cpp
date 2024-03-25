#include <iostream>
#include <fstream>
#include <string>
#include "Analyzer.h"

int main() {
    Analyzer analyzer;
    std::ifstream file("testStrings.txt");
    std::string str;
    while(getline(file, str)) { 
        std::cout << str << std::endl;
        analyzer.Analyze(str);
        str.clear();
    }
    file.close();
    return 0;
}