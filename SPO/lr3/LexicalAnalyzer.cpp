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
    operators.emplace("#", "E");
    operators.emplace("&", "F");
    //assigment
    operators.emplace(":=", "A");
    operators.emplace("=", "A");
    //end
    operators.emplace(";", ";");
    //ariphmetic
    operators.emplace("+", "O");
    operators.emplace("-", "O");
    operators.emplace("*", "O");
    operators.emplace("/", "O");
    //relation
    operators.emplace("<", "R");
    operators.emplace("<=", "R");
    operators.emplace(">", "R");
    operators.emplace(">=", "R");
    //brackets
    operators.emplace("(", "(");
    operators.emplace(")", ")");
}

std::vector<std::string> LexicalAnalyzer::divideIntoSubStrings(std::string str) {
    std::vector<std::string> subStrings;
    std::istringstream iss(str);
    std::string token;
    while(std::getline(iss, token, ' ')) {
        subStrings.push_back(token);
    }
    return subStrings;
}

std::string LexicalAnalyzer::analyze(std::string str) {
    lexems.clear();
    std::vector<std::string> subStrings = divideIntoSubStrings(str);
    std::string final;
    for (auto str : subStrings) {
        validateString(str);
    }
    for (auto str : lexems) {
        final += str;
    }
    return final;
}

int LexicalAnalyzer::validateString(std::string str) {
    if (isdigit(str[0])) {
        if(validateConstant(str, 0) == -1) {
            return -1;
        }
        return 0;
    }
    
    if (keywords.find(str) != keywords.end()) {
        lexems.push_back(keywords[str]);
        //std::cout << "Keyword: " << str <<" lexem: " << keywords[str] << std::endl;
        return 0;
    }
    
    if (validateIdentifier(str, 0) == -1) {
        return -1;
    }
    return 0;
}

int LexicalAnalyzer::validateConstant(std::string str, int start) {
    std::string token;
    for (int i = start; i < str.size(); i++) {
        if (!isdigit(str[i])) {
            int j;
            if ((j = validateOperator(str, i)) != -1) {

                if (token.size() > 0) {
                    auto position = lexems.end();
                    position--;
                    lexems.insert(position, "C");
                    //std::cout << "Constant: " << token << " lexem: C" << std::endl;
                    token = "";
                }
                
                i=j-1;
                if (isalpha(str[j])) {
                    if(validateConstant(str, j) == -1) {
                        return -1;
                    }
                    return 0;
                }
                continue;
            }
            else {
                if (isalpha(str[i])) {
                    std::cout << "Identifier can't start with the number: " << str << std::endl;
                }
                else {
                    std::cout << "Unexpected symbol: " << str[i] << " in: " << str << std::endl;
                }
                lexems.push_back(" error ");
                return -1;
            }
        }
        token += str[i];
    }
    if (token.size() > 0) {
        lexems.push_back("C");
        //std::cout << "Constant: " << token << " lexem: C" << std::endl;
    }
    
    return 0;
}

int LexicalAnalyzer::validateIdentifier(std::string str, int start) {
    std::string token;
    for (int i = start; i < str.size(); i++) {
        if (!isalpha(str[i]) && !isdigit(str[i])) {
            int j;
            if ((j = validateOperator(str, i)) != -1) {
                
                if (token.size() > 0) {
                    auto position = lexems.end();
                    position--;
                    lexems.insert(position, "I");
                    //std::cout << "Identifier: " << token << " lexem: I" << std::endl;
                    token = "";
                }
                
                i=j-1;
                if (isdigit(str[j])) {
                    if(validateConstant(str, j) == -1) {
                        return -1;
                    }
                    return 0;
                }
                continue;
            }
            else {
                std::cout << "Unexpected symbol: " << str[i] << " in: " << str << std::endl;
                lexems.push_back(" error ");
                return -1;
            }
        }
        token += str[i];
    }
    if (token.size() > 0) {
        lexems.push_back("I");
        //std::cout << "Identifier: " << token << " lexem: I" << std::endl;
    }
    return 0;
}

int LexicalAnalyzer::validateOperator(std::string str, int start) {
    std::string token;
    int i = start;
    for (; i < str.size(); i++) {
        if (isdigit(str[i]) || isalpha(str[i])) break;
        else token+=str[i];
    }
    if (operators.find(token) != operators.end()) {
        //std::cout << "Operator: " << token << " lexem: " << operators[token] << std::endl;
        lexems.push_back(operators[token]);
        return i;
    }
    else {
        return -1;
    }
}