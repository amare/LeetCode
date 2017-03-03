#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "longest_palindromic_substring.h"

TEST_CASE("Longest Palindromic Substring", "[longestPalindrome]")
{
    Solution s;
    REQUIRE( s.longestPalindrome("a") == "a");
    REQUIRE( s.longestPalindrome("aa") == "aa" );
    REQUIRE( s.longestPalindrome("abaaba") == "abaaba" );
    REQUIRE( s.longestPalindrome("babadada") == "adada" );
}
