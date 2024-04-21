#include "LexicalAnalyzer.h"

LexicalAnalyzer::LexicalAnalyzer() {
    setKeywords();
    setOperators();
}

void LexicalAnalyzer::setKeywords() {
    //term
    keywords.emplace("if", "T");
}

void LexicalAnalyzer::setOperators() {
    //term
    operators.emplace("?", "?");
    operators.emplace(":", ":");
    //divide
    operators.emplace("#", "#");
    operators.emplace("&", "&");
    //assigment
    operators.emplace(":=", "A");
    operators.emplace("=", "A");
    //end
    operators.emplace(";", ";");
    //ariphmetic
    // operators.emplace("+", "O");
    // operators.emplace("-", "O");
    // operators.emplace("*", "O");
    // operators.emplace("/", "O");
    //relation
    // operators.emplace("<", "R");
    // operators.emplace("<=", "R");
    // operators.emplace(">", "R");
    // operators.emplace(">=", "R");
    //brackets
    operators.emplace("(", "(");
    operators.emplace(")", ")");
}

std::string LexicalAnalyzer::analyze(std::string _str) {
    head = 0;
    lexems.clear();
    std::string final;
    validateString(_str);
    for (auto str : lexems) {
        final += str;
    }
    return final;
}

int LexicalAnalyzer::validateString(std::string str) {
    while(head != str.size()) {
        if (isspace(str[head])) {
            head++;
            continue;
        }
        else if (isdigit(str[head])) {
            if(validateConstant(str)) return -1;
        }
        else if (isalpha(str[head])) {
            if (validateIdentifier(str)) return -1;
        }
        else {
            if (validateOperator(str)) return -1;
        }
    }
    
    return 0;
}

int LexicalAnalyzer::validateConstant(std::string str) {
    std::string token;
    for (; head < str.size() && isdigit(str[head]); head++) {
        token += str[head];
    }
    if (token.size() > 0) {
        lexems.push_back("C");
        //std::cout << "Constant: " << token << " lexem: C" << std::endl;
    }
    
    return 0;
}

int LexicalAnalyzer::validateIdentifier(std::string str) {
    std::string token;
    for (; head < str.size() && isalnum(str[head]); head++) {
        token += str[head];
    }
    if (token.size() > 0) {
        if (keywords.find(token) != keywords.end()) {
            lexems.push_back(keywords[token]);
            //std::cout << "Keyword: " << token << " lexem: " << keywords[token] << std::endl;
        }
        else {
            lexems.push_back("I");
            //std::cout << "Identifier: " << token << " lexem: I" << std::endl;
        }
    }
    return 0;
}

int LexicalAnalyzer::validateOperator(std::string str) {
    std::string token;
    for (; head < str.size(); head++) {
        if (str[head] == '(' || str[head] == ')') {
            if (token.size() > 0) {
                if (operators.find(token) != operators.end()) {
                    //std::cout << "Operator: " << token << " lexem: " << operators[token] << std::endl;
                    lexems.push_back(operators[token]);
                    token.clear();
                }
                else {
                    std::cout << "No operator matches: " << token << std::endl;
                    return -1;
                }
            }
            token+=str[head];
            //std::cout << "Operator: " << token << " lexem: " << operators[token] << std::endl;
            lexems.push_back(operators[token]);
            head++;
            return 0;
        }
        else if (isalnum(str[head]) || isspace(str[head])) break;
        else token+=str[head];
    }
    if (operators.find(token) != operators.end()) {
        //std::cout << "Operator: " << token << " lexem: " << operators[token] << std::endl;
        lexems.push_back(operators[token]);
        return 0;
    }
    else {
        std::cout << "No operator matches: " << token << std::endl;
        return -1;
    }
}