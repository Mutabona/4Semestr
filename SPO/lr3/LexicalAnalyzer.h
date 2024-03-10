#ifndef LEXICAL_ANALYZER
#define LEXICAL_ANALYZER

#include <cctype>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <string>
#include <list>

class LexicalAnalyzer {
    private:
      std::vector<std::string> divideIntoSubStrings(std::string str);

      std::list<std::string> lexems;
      std::map<std::string, std::string> keywords;
      std::map<std::string, std::string> operators;
      
      int validateString(std::string str);
      int validateConstant(std::string str, int start);
      int validateIdentifier(std::string str, int start);
      int validateOperator(std::string str, int start);
      
      void setKeywords();
      void setOperators();
      
    public:
      LexicalAnalyzer();
      std::string analyze(std::string str);
};

#endif