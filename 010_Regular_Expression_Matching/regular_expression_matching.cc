
#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "regular_expression_matching.h"

TEST_CASE("Regular Expression Matching", "[isMatch]")
{
    Solution s;
    REQUIRE( s.isMatch("aa", "a") == false);
    REQUIRE( s.isMatch("aa", "aa") == true);
    REQUIRE( s.isMatch("aaa", "aa") == false);
    REQUIRE( s.isMatch("aa", "a*") == true );
    REQUIRE( s.isMatch("aa", ".*") == true);
    REQUIRE( s.isMatch("ab", ".*") == true);
    REQUIRE( s.isMatch("aab", "c*a*b") == true);
    REQUIRE( s.isMatch("", "a*") == true);
    REQUIRE( s.isMatch("abcdeb", "a.*b") == true);
    REQUIRE( s.isMatch("bcdeb", "a.*b") == false);
}

/*
#include "regular_expression_matching.h"

int main()
{
    Solution s;
    cout << s.isMatch("aa", "a") << endl;

    return 0;
}
*/
