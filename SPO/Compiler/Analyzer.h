#include "../lr3/LexicalAnalyzer.h"
#include "../lr4/SyntaxisAnalyzer.h"
#include "../lr5/LLAnalyzer.h"

class Analyzer {
    private:
    SyntaxisAnalyzer syntaxisAnalyzer;
    LexicalAnalyzer lexicalAnalyzer;
    LLAnalyzer LLAnalyzer;

    public:
    int Analyze(std::string str);
};