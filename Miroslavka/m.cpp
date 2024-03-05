#include <iostream>
#include <string>
#include <cctype>
#include <windows.h>

using namespace std;

// Перечисление для представления состояний автомата
enum State {
    S0, S1, S2, S3, S4, S5, S6
};

void lexicalAnalyzer(const string& input) {
    State currentState = S0;
    string token;

    for (char ch : input) {
        switch (currentState) {
            case S0:
                if (isdigit(ch)) {
                    currentState = S4;
                    token += ch;
                } else if (isalpha(ch)) {
                    currentState = S6;
                    token += ch;
                } else if (isspace(ch)) {
                    currentState = S0;
                } else {
                    currentState = S1;
                    token += ch;
                }
                break;
            case S1:
                cout << "token: " << token << endl;
                token = ""; // Сбрасываем текущий токен
                currentState = S0; // Возвращаемся к начальному состоянию
                break;
            case S2:
                if (ch == ':' || ch == '=' || ch == ';' || ch == '#' || ch == '&' || ch == '!') {
                    currentState = S0;
                    token += ch;
                    cout << "opetator: " << token << endl;
                    token.clear();
                } else {
                    currentState = S1; // Неверный символ после ':'
                }
                break;
            case S3:
                if (isalpha(ch) || isdigit(ch)) {
                    currentState = S3;
                    token += ch;
                } else {
                    currentState = S0;
                    cout << "Identifier: " << token << endl;
                    token.clear();
                }
                break;
            case S4:
                if (isdigit(ch)) {
                    currentState = S4;
                    token += ch;
                } else {
                    currentState = S0;
                    cout << "Integer constant: " << token << endl;
                    token.clear();
                }
                break;
            case S5:
                if (isdigit(ch)) {
                    currentState = S5;
                    token += ch;
                } else {
                    currentState = S0;
                    cout << "Number: " << token << endl;
                    token.clear();
                }
                break;
            case S6:
                if (isalpha(ch) || isdigit(ch)) {
                    currentState = S6;
                    token += ch;
                } else {
                    currentState = S0;
                    cout << "Identifier: " << token << endl;
                    token.clear();
                }
                break;
        }
    }

    cout << "token: " << token << endl;
}

int main() {
    SetConsoleCP(65001);	
    SetConsoleOutputCP(65001);

    cout << "Enter the line to analyze: ";
    string input;
    getline(cin, input); // Читаем строку с клавиатуры
    lexicalAnalyzer(input);
    return 0;
}