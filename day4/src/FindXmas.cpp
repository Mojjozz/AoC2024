#include "FindXmas.h"

std::vector<std::pair<int, int>> directions = {{0,1},   {0,-1}, {1,0},  {-1,0},
                                               {-1,-1}, {-1,1}, {1,-1}, {1,1}};
std::string parse_input(std::ifstream &s) {
    return { std::istreambuf_iterator<char>(s), {} };
}

