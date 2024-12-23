#include "MullItOver.h"

int main() {
	namespace fs = std::filesystem;
	fs::path projectRoot = fs::current_path().parent_path().parent_path();
	fs::current_path(projectRoot);
	std::ifstream file("day3/resources/realinput.txt");

    if (!file) {
        std::cerr << "Error while reading file";
        return 1;
    }

    std::string line;

    long total;
    while(std::getline(file, line)) {
        long result = findValidMultiplications(line);
        total += result;
    }


    std::cout << "total: " << total << std::endl;
}