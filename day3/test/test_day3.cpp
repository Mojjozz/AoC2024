#include "MullItOver.h"
#include <gtest/gtest.h>

TEST(MullItOverTest, ClearStringFromGarbageAndMultiply) {
   //given
   std::string line = "xmul(2,2)not_appmul(1,5]normul[1,5]but_thismul(6,2)mul( 1, 1)from";

   //when
   long result = findValidMultiplications(line);

   //then
   ASSERT_EQ(16, result);

}


TEST(MullItOverTest, SearchStringAndEnadbleDisableMul) {
   //given
   std::string line = "from()why()?mul(603,692)({select()}] )]-(mul(387,685)who()mul(28,717)who()";
   
   //when
   long result = findValidMultiplicationsFeature(line);

   //then
   ASSERT_EQ(48, result);
}