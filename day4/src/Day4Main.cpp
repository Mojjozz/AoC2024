#include "FindXmas.h"
#include <sstream>

int main() {
	namespace fs = std::filesystem;
	fs::path projectRoot = fs::current_path().parent_path().parent_path();
	fs::current_path(projectRoot);
	std::ifstream file("day4/resources/Example.txt");

    if (!file) {
        std::cerr << "Error while reading file";
        return 1;
    }

    std::string input = parse_input(file);

    std::vector<std::string> lines;
    std::stringstream ss(input);
    std::string line;

    while(std::getline(ss, line)) {
        lines.push_back(line);
    }
    int result = 0;
    for(int i = 0; i < lines.size(); i++) {
        for(int j = 0; j < lines[0].size(); j++){
          if(lines[i][j] == 'X') {
            result += findWord(i,j,lines);
          }
        }
    }
    std::cout << "result: " << result << std::endl;
    return 0;

}
