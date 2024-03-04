#include <iostream>
#include <string>
#include <cctype>
#include <windows.h>

enum State {
    S0, S1, S2, S3, S4, S5, S6
};

void lexicalAnalyzer(const std::string& input) {
    State currentState = S0;
    std::string token;

    for (int i = 0; i < input.size()+1; i++) {
        switch (currentState) {
            case S0:
                if (isalpha(input[i])) {
                    currentState = S1;
                    token += input[i];
                    break;
                } else if (isspace(input[i])) {
                    token.clear();
                    break;
                } else if (input[i] == '=' || input[i] == '*' || input[i] == '+' || input[i] == '-' || input[i] == '/') {
                    token.clear();
                    std::cout<<"Ariphmetic operator: "<< input[i] << std::endl;
                    break;
                } else if (input[i] == '?') {
                    token.clear();
                    std::cout<<"Logic operator: "<< input[i] << std::endl;
                    break;
                } else if (input[i] == ':') {
                    token.clear();
                    std::cout<<"Logic operator: "<< input[i] << std::endl;
                    break;
                }
            case S1:
                if (token[0] == 'i' && input[i] == 'f' && isspace(input[i+1])) {
                    i++;
                    currentState = S0;
                    std::cout<<"Operator: if"<<std::endl;
                    token.clear();
                    break;
                } else if (isdigit(input[i]) || isalpha(input[i])) {
                    token += input[i];
                    break;
                } else {
                    std::cout<<"Identifier: "<<token<<std::endl;
                    token.clear();
                    currentState = S0;
                    break;
                }
        }
    }
}

int main() {
    SetConsoleCP(65001);	
    SetConsoleOutputCP(65001);

    std::cout << "Cтрока для анализа: ";
    std::string input;
    getline(std::cin, input); // Читаем строку с клавиатуры
    lexicalAnalyzer(input);
    return 0;
}