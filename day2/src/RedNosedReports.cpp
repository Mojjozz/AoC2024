#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

int processReport(std::vector<int>& level);
int processReportDampener(std::vector<int>& level);
int main() {
    std::ifstream file("/Users/morganjohansson/Documents/AoC2024/day2/resources/Example.txt");

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
}

int processReport(std::vector<int>& level) {
        
        int num1 = level.at(0);
        int num2 = level.at(1);
        bool ascending;
        if(num1 < num2){
            ascending=true;
        }else if(num1 > num2) {
            ascending=false;
        }else{
            return -1;
        }

        for(int i = 1; i < levels.size(); i++) {
            int curr = levels.at(i - 1);
            int next = levels.at(i);
            int diff = std::abs(curr - next);
            if(diff < 1 || diff > 3) {
                return -1;
            }
            if(ascending && next < curr) {
                return -1;
            } else if (!ascending && next > curr) {
                return -1;
            }        
        }
        return 0;
}

int processReportDampener(std::vector<int>& level) {
        std::vector<int> localCopy = level;
        for(int i = 0; i < level.size(); i++){
          int holder = level.at(i);
          localCopy.erase(i);
          if(processReport(localCopy==0){
              return 0;
          }
          localCopy.insert(i,i);
        }
        return -1;
}
