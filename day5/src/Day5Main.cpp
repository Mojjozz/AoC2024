#include "PrintQueue.h"
#include <regex>


int main() {
	namespace fs = std::filesystem;
	fs::path projectRoot = fs::current_path().parent_path().parent_path();
	fs::current_path(projectRoot);
	std::ifstream file("day5/resources/realinput.txt");

    if (!file) {
        std::cerr << "Error while reading file";
        return 1;
    }

    std::string input = parse_input(file);

    std::vector<std::pair<int,int>> rules;
    std::vector<std::string> lines;
    std::stringstream ss(input);
    std::string line;


    std::smatch match;

    while(std::getline(ss, line)) {
        std::pair<int, int> p = parse_rules(line);
        if (p != std::pair<int,int>(0,0)){
            rules.push_back(parse_rules(line));
        }
        std::string l = parse_update(line);
        if (l != ""){
            lines.push_back(parse_update(line));
        }
    }

    int totalNumber = 0;
    for(auto line: lines){
        totalNumber += checkUpdateAndAdd(rules, line);
    }
    std::cout << "totalNumber: " << totalNumber << std::endl;
    return 0;
}
