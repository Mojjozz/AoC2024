#include "FindXmas.h"

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

    for(int i = 0; i < lines.size(); i++) {
        for(int j = 0; j < lines[0].size(); j++){
            std::cout << "i:" << i << " j: " << j << " line[i][j]: " << lines[i][j] << std::endl;
        }
    }

    return 0;

}