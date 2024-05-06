#include "../lr3/LexicalAnalyzer.h"
#include "../lr4/SyntaxisAnalyzer.h"
#include "../lr5/LLAnalyzer.h"
#include "../lr6/SysAnalyzer.h"

class Analyzer {
    private:
    SyntaxisAnalyzer syntaxisAnalyzer;
    LexicalAnalyzer lexicalAnalyzer;
    LLAnalyzer LLAnalyzer;
    SysAnalyzer sysAnalyzer;

    public:
    int Analyze(std::string str);
};