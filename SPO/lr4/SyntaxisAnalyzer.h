#ifndef SYNTAXIS_ANALYZER
#define SYNTAXIS_ANALYZER

#include <iostream>
#include <map>
#include <vector>
#include <vector>
#include <sstream>
#include <algorithm>

class SyntaxisAnalyzer {
    private:
        int head = 0;

        int validateOperatorIf(std::string);
        int validateFactor(std::string);
        int validateOperator(std::string);
        int validateOperatorAR(std::string);
        int validateExpression(std::string);
        int validateBlock(std::string);
        int validatePrimary(std::string);
    public:
        SyntaxisAnalyzer() {}
        bool analyze(std::string str);
};

#endif