#include "FindXmas.h"
#include <gtest/gtest.h>



TEST(FindXmasSuite, FindWordTest) {
  //given
  std::vector<std::string> input;
  std::string data = "MMMSSSASSSSAMXMASSSAAMMXX";
  input.push_back(data);
  std::cout << input[0][0] << std::endl;
  //when
  int result = findWord(0, 13, input);
  //then
  ASSERT_EQ(2, result);
}

