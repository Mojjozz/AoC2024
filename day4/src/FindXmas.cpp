#include "FindXmas.h"

std::vector<std::pair<int, int>> directions = {{0,1},   {0,-1}, {1,0},  {-1,0},
                                               {-1,-1}, {-1,1}, {1,-1}, {1,1}};

const std::string XMAS = "XMAS";

std::string parse_input(std::ifstream &s) {
    return { std::istreambuf_iterator<char>(s), {} };
}


int findWord(int r, int c, std::vector<std::string> input) {
  int acc = 0;
  for(std::pair<int, int> dir : directions) {
    int row_step = dir.first;
    int col_step = dir.second;
    int pos_x = r;
    int pos_y = c;
    for(int i = 0; i < XMAS.size(); i++){
      // pos_x or pos_y cannot be less than 0 or greater than the max number of rows/ cols
      if (pos_x < 0 || pos_y < 0 || pos_x > input.size()-1 || pos_y > input[0].size()-1) {
        break;
      }
      char letterToFind=XMAS[i];
      char currLetter=input[pos_x][pos_y];
      if (letterToFind == currLetter){
        if (currLetter == 'S'){
          acc++;
          break;
        }
        if (row_step != 0) {
          pos_x=pos_x + row_step;
        }
        if (col_step != 0) {
          pos_y=pos_y + col_step;
          
        }
      } else {
        break;
      }
    }
  }
  return acc;
}

