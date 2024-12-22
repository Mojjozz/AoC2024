#include "MullItOver.h"
#include <regex>

void findValidMultiplications(std::string line) {
    std::cout << "line passed: " << line << std::endl;
    std::regex regexp("mul\\([0-9]+,[0-9+]\\)");
    std::smatch m;
    std::regex_search(line, m, regexp);
    for(int i = 0; i < m.size(); i++) {
        std::cout << m[i] << std::endl;
    }
}