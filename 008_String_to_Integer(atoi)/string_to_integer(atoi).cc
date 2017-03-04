#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "string_to_integer(atoi).h"

TEST_CASE("String to Integer(atoi)", "[myAtoi]")
{
    Solution s;
    REQUIRE( s.myAtoi("") == 0);
    REQUIRE( s.myAtoi("     ") == 0);
    REQUIRE( s.myAtoi("  a10.89") == 0 );
    REQUIRE( s.myAtoi("  +-10") == 0 );
    REQUIRE( s.myAtoi("+00010a23") == 10 );
    REQUIRE( s.myAtoi("-00010.23") == -10 );
    REQUIRE( s.myAtoi("-2147483649") == -2147483648 );
    REQUIRE( s.myAtoi("+2147483648") == 2147483647 );
    REQUIRE( s.myAtoi("-12147483648") == -2147483648 );

}
