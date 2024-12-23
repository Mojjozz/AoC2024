#include "MullItOver.h"
#include <regex>

long findValidMultiplications(std::string line) {
    std::regex regexp("mul\\(([0-9]+),([0-9]+)\\)");
    std::smatch m;
    long total = 0L;
    while(std::regex_search(line, m, regexp)) {
        int num1 = std::stoi(m[1]);
        int num2 = std::stoi(m[2]);
        total += num1*num2;
        line = m.suffix();
    }
    return total;
}


long findValidMultiplicationsFeature(std::string line, bool &enabled) {
    std::smatch m;
    long total = 0L;
    std::regex regexp("mul\\(([0-9]+),([0-9]+)\\)|(do\\(\\)|don't\\(\\))");
    while(std::regex_search(line, m, regexp)) {
        if(m[0] == "do()"){
            enabled = true;
        } else if(m[0] == "don't()") {
            enabled = false;
        } else if (enabled) {
            int num1 = std::stoi(m[1]);
            int num2 = std::stoi(m[2]);
            total += num1*num2;
        }
        line = m.suffix();
    }
    return total;
}