// #define _GNU_SOURCE     //在<sys/features.h>中用于特性控制的一个功能测试宏
#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "roman_to_integer.h"

TEST_CASE("Roman to Integer", "[romanToInt]")
{
    Solution s;
    REQUIRE( s.romanToInt("MMMCMXCIX") == 3999 );
    REQUIRE( s.romanToInt("DCXXI") == 621 );
    REQUIRE( s.romanToInt("MDCLXVI") == 1666 );
    REQUIRE( s.romanToInt("CM") == 900 );
}
