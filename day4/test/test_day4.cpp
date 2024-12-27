#include "FindXmas.h"
#include <gtest/gtest.h>
#include <sstream>


TEST(FindXmasSuite, FindWordTest) {
  //given
  std::vector<std::string> input;
  std::string data = "MMMSSSASSSSAMXMASSSAAMMXX";
  input.push_back(data);
  //when
  int result = findWord(0, 13, input);
  //then
  ASSERT_EQ(2, result);
}



TEST(FindXmasSuite, FindMasTest) {
  //given
  std::string input = "MMAMAS\nSSAASS\nSSASMM";
  std::stringstream ss(input);
  std::string line;
  std::vector<std::string> lines;
  while(std::getline(ss, line)) {
      lines.push_back(line);
  }
  //when
  int res = findMas(1,2,lines);
  ASSERT_EQ(1,res);
}
