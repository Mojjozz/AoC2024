#include "RedNosedReports.h"

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

        for(int i = 1; i < level.size(); i++) {
            int curr = level.at(i - 1);
            int next = level.at(i);
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
          localCopy.erase(localCopy.begin() + i);
          if(processReport(localCopy)==0){
              return 0;
          }
          localCopy.insert(localCopy.begin() + i, holder);
        }
        return -1;
}
