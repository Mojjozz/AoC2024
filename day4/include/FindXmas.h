#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>


std::string parse_input(std::ifstream &s);

int findWord(int r, int c, std::vector<std::string> input);

bool NW(char NW_char, char SE_char);
bool NE(char NE_char, char SW_char);

int findMas(int startCord_x, int startCord_y, std::vector<std::string> &input);
