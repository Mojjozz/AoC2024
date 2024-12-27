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


bool NW(char NW_char, char SE_char) {
  if( NW_char == 'M' && SE_char  == 'S'){
    return true;
  } else if (NW_char == 'S' && SE_char == 'M') {
    return true;
  } else {
    return false;
  }
}

bool NE(char NE_char, char SW_char) {
  if (NE_char == 'M' && SW_char == 'S') {
    return true;
  } else if (NE_char == 'S' && SW_char == 'M') {
    return true;
  } else {
    return false;
  }
}


int findMas(int startCord_x, int startCord_y, std::vector<std::string> &input) {
  if(startCord_x-1 < 0 || startCord_x+1 > input.size() || startCord_y-1 < 0 || startCord_y > input[0].size()){
    return 0;
  }
  char NW_char=input[startCord_x-1][startCord_y-1];
  char SE_char=input[startCord_x+1][startCord_y+1];
  char NE_char=input[startCord_x+1][startCord_y-1];
  char SW_char=input[startCord_x-1][startCord_y+1];
  
  if (NW(NW_char, SE_char) && NE(NE_char, SW_char)) {
    return 1;
  }else {
    return 0;
  }
}

