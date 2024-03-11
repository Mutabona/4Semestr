#include <iostream>
#include <map>
#include <vector>
#include <vector>
#include <sstream>
#include <algorithm>

class SyntaxisAnalyzer {
    private:
        int validateIfOperator(std::string);
        int validateFactor(std::string);
        int validateOperator(std::string);
        int validateOperatorAR(std::string);
        int validateExpression(std::string);
        int validateBlock(std::string);

        std::vector<std::string> divideIntoOperators(std::string str);
    public:
        SyntaxisAnalyzer() {}
        bool analyze(std::string str);
};

bool SyntaxisAnalyzer::analyze(std::string str) {
    std::vector<std::string> operators = divideIntoOperators(str);

    for (auto oper : operators) {
        validateOperator(oper);
    }
}

int SyntaxisAnalyzer::validateOperator(std::string str) {
    if (str[0] == 'I') {
        validateOperatorAR(str);
    }
    else if (str[0] == 'T') {
        validateIfOperator(str);
    }
    else {
        return -1;
    }
}

int SyntaxisAnalyzer::validateOperatorAR(std::string str) {
    if (str[0] == 'I' && str[1] == 'O') {
        validateExpression(str);
    }
    else {
        return -1;
    }
}



std::vector<std::string> SyntaxisAnalyzer::divideIntoOperators(std::string str) {
    std::vector<std::string> subStrings;
    std::istringstream iss(str);
    std::string token;
    while(std::getline(iss, token, ';')) {
        subStrings.push_back(token);
    }
    return subStrings;
}