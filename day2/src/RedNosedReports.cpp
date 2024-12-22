#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

int processReport(std::string);
int main() {
    std::ifstream file("D:\\AoC2024\\day2\\resources\\realinput.txt");

    if (!file) {
        std::cerr << "Error while reading file";
        return 1;
    }

    std::string line;
    int safeLevels = 0;
    while(std::getline(file, line)) {
        if(processReport(line) == 0){
            safeLevels++;
        }
    }
    std::cout << "Safe reports: " << safeLevels << std::endl;
}

int processReport(std::string line) {
        std::stringstream ss(line);
        int number;
        std::vector<int> levels;
        while(ss >> number) {
            levels.push_back(number);
        }
        int num1 = levels.at(0);
        int num2 = levels.at(1);
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
