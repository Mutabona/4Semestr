#include "../lr3/LexicalAnalyzer.h"
#include "../lr4/SyntaxisAnalyzer.h"

class Analyzer {
    private:
    SyntaxisAnalyzer syntaxisAnalyzer;
    LexicalAnalyzer lexicalAnalyzer;

    public:
    int Analyze(std::string str);
};

int Analyzer::Analyze(std::string str) {
    syntaxisAnalyzer.analyze(lexicalAnalyzer.analyze(str));
}