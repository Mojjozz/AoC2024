#include "MullItOver.h"

int main() {
	namespace fs = std::filesystem;
	fs::path projectRoot = fs::current_path().parent_path().parent_path();
	fs::current_path(projectRoot);
	std::ifstream file("day3/resources/Example.txt");

    if (!file) {
        std::cerr << "Error while reading file";
        return 1;
    }

    std::string line;
    std::getline(file, line);

    findValidMultiplications(line);

}