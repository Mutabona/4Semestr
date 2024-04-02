#include "SyntaxisAnalyzer.h"

bool SyntaxisAnalyzer::analyze(std::string str) {
    head = 0;
    if (validateBlock(str)) {
        return false;
    }
    return true;
}

int SyntaxisAnalyzer::validateBlock(std::string str) {
    std::cout<< "Block" << std::endl;
    if(validateOperator(str)) {
        std::cout<< "No block " << std::endl;
        return -1;
    }
    if (str[head] == ';') {
        head++;
        if(validateBlock(str)) return -1;
    } 
    else if (head == str.size()) {
        return 0;
    } 
    else {
        return -1;
    }
    return 0;
}

int SyntaxisAnalyzer::validateOperator(std::string str) {
    std::cout<< "Operator " << "head -> " << str[head] << std::endl;
    if (str[head] == 'I') {
        head++;
        if(validateOperatorARO(str)) return -1;
    }
    else if (str[head] == 'T') {
        head++;
        if(validateOperatorIf(str)) return -1;
    }
    else {
        return -1;
    }
    return 0;
}

int SyntaxisAnalyzer::validateOperatorARO(std::string str) {
    std::cout<< "Operator AR " << "head -> " << str[head] << std::endl;
    if (str[head] == 'A' || str[head] == 'O' || str[head] == 'R') {
        head++;
        if (validateExpression(str)) {
            return -1;
        }
    }
    else {
        std::cout<< "No operator AR " << std::endl;
        return -1;
    }
    return 0;
}

int SyntaxisAnalyzer::validateOperatorIf(std::string str) {
    std::cout<< "Operator IF " << "head -> " << str[head] << std::endl;
    if (str[head] == 'I') {
        head++;
    } 
    else {
        std::cout<< "No Term 1 " << std::endl;
        return -1;
    }

    if (str[head] == '?') {
        head++;
        if (validateOperator(str)) return -1;
    }
    else {
        std::cout<< "No Term 2 " << std::endl;
        return -1;
    }

    if (str[head] == ':') {
        head++;
        if (validateOperator(str)) return -1;
    }
    else {
        std::cout<< "No Term 3 " << std::endl;
        return -1;
    }
    return 0;
}

int SyntaxisAnalyzer::validateExpression(std::string str) {
    std::cout<< "Expression " << "head -> " << str[head] << std::endl;
    if (validateFactor(str)) {
        std::cout<< "No expression " << std::endl;
        return -1;
    }
    if (str[head] == 'E') {
        head++;
        if (validateExpression(str)) return -1;
    }
    return 0;
}

int SyntaxisAnalyzer::validateFactor(std::string str) {
    std::cout<< "Factor " << "head -> " << str[head] << std::endl;
    if (validatePrimary(str)) {
        std::cout<< "No factor " << std::endl;
        return -1;
    }
    if (str[head] == 'F') {
        head++;
        if (validateFactor(str)) return -1;
    }
    return 0;
}

int SyntaxisAnalyzer::validatePrimary(std::string str) {
    std::cout<< "Primary " << "head -> " << str[head] << std::endl;
    if (str[head] == 'I' || str[head] == 'C') {
        head++;
        return 0;
    }
    else if (str[head] == '(') {
        head++;
        if (validateExpression(str)) return -1;
        if (str[head] == ')') {
            head++;
            return 0;
        }
    }
    else {
        std::cout<< "No primary " << std::endl;
        return -1;
    }
    return 0;
}