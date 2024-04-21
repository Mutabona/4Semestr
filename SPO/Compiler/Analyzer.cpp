#include "Analyzer.h"

int Analyzer::Analyze(std::string str) {
    std::string lexems = lexicalAnalyzer.analyze(str);
    std::cout<< lexems << std::endl;
    bool belongToLanguage = LLAnalyzer.Analyze(lexems);
    if (belongToLanguage) {
        std::cout<< "The string belongs to the language\n" << std::endl;
        return 0;
    }
    else {
        std::cout<< "The string does not belong to the language\n" << std::endl;
        return -1;
    }
}