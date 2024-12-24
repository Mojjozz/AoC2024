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

    long total_puzzle1 = 0;
    long total_puzzle2 = 0;
    bool enabled=true;
    while(std::getline(file, line)) {
        long result = findValidMultiplications(line);
        total_puzzle1 += result;
        long result2 = findValidMultiplicationsFeature(line, enabled);
        total_puzzle2 += result2;
    }
    std::cout << "total part 1: " << total_puzzle1 << std::endl;
    std::cout << "total part 2: " << total_puzzle2 << std::endl;
}



// might be the right answer: 88802350