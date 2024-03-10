#include "LexicalAnalyzer.h"
#include <iostream>
#include <string>
#include <windows.h>


int main() {
    std::cout << "String to analyze: ";
    std::string input;
    getline(std::cin, input);
    
    LexicalAnalyzer lexicalAnalyzer;
    std::cout << lexicalAnalyzer.analyze(input) << std::endl;
    return 0;
}