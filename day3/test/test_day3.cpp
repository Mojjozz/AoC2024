#include "MullItOver.h"
#include <gtest/gtest.h>

TEST(MullItOverTest, ClearStringFromGarbage) {
   //given
   std::string line = "xmul(2,2)not_appmul(1,5]normul[1,5]but_thismul(6,2)mul( 1, 1)from";

   // when
   long result = findValidMultiplications(line);

   //then
   ASSERT_EQ(16, result);

}