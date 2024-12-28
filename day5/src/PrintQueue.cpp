#include "PrintQueue.h"
#include <regex>
#include <map>


const std::regex pattern_rules("([0-9]{2})\\|([0-9]{2})");
const std::regex pattern_update("[0-9]+,.+");

std::string parse_input(std::ifstream &s) {
    return { std::istreambuf_iterator<char>(s), {} };
}

std::pair<int,int> parse_rules(std::string line) {
    std::smatch match;
    std::regex_search(line, match, pattern_rules);
    if(match[0] == ""){
        return std::pair<int, int>(0,0);
    }
    std::pair<int, int> p = {std::stoi(match[1]), std::stoi(match[2])};
    return p;
    
}


std::string parse_update(std::string line) {
    if(std::regex_match(line, pattern_update)){
        return line;
    }
    return "";
}


int checkUpdateAndAdd(std::vector<std::pair<int, int>> &rules, std::string line) {
    std::stringstream ss(line);
    std::map<int,int> ruleMap;
    int num;
    std::vector<int> numbersForUpdate;
    while(ss >> num) {
        numbersForUpdate.push_back(num);
        if(ss.peek() == ',') {
            ss.ignore();
        }
    }
    for(int i = 1; i < numbersForUpdate.size(); i++) {
        int before = numbersForUpdate[i-1];
        int current = numbersForUpdate[i];
        for(const auto& rule : rules) {
            if(rule.second == current){
                ruleMap[rule.first] = rule.second;
            }
        }
        if(ruleMap.find(before) != ruleMap.end()) {
            continue;
        } else {
            return 0;
        }
    }

    return numbersForUpdate[numbersForUpdate.size()/2];
}