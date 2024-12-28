#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <utility>


std::string parse_input(std::ifstream &s);

std::pair<int,int> parse_rules(std::string line);
std::string parse_update(std::string line);
int checkUpdateAndAdd(std::vector<std::pair<int,int>> &rules, std::string line);