#include "RedNosedReports.h"

int main() {

	namespace fs = std::filesystem;
	fs::path projectRoot = fs::current_path().parent_path().parent_path();
	fs::current_path(projectRoot);
	std::ifstream file("day2/resources/Example.txt");

    if (!file) {
        std::cerr << "Error while reading file";
        return 1;
    }

    std::string line;
    int safeLevels = 0;
    int safeLevelsDampener = 0;
    while(std::getline(file, line)) {
        std::stringstream ss(line);
        int number;
        std::vector<int> level;
        while(ss >> number) {
            level.push_back(number);
        }

        if(processReport(level) == 0){
            safeLevels++;
            safeLevelsDampener++;
        }else {
          if(processReportDampener(level) == 0){
            safeLevelsDampener++;
          }
        }
        
    }
    std::cout << "Safe reports: " << safeLevels << std::endl;
    std::cout << "Safe Dampened reports: " << safeLevelsDampener << std::endl;
}