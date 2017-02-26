
/*
 Author:            cuckoo
 Date:              2017/02/26 13:40:33
 Update:
 Problem:           Reverse Integer
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/reverse-integer/
 Note:
 Reverse digits of an integer.

 The input is assumed to be a 32-bit signed integer.
 Your function should return 0 when the reversed integer overflows.

 Example1:
 Input: 123
 Output: 321

 Example2:
 Input: -123
 Output: -321

 Solution: 1. transfer the int type into string type and handle the string
           2. mathematical method

 */

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::reverse;

#include <string>
using std::string;

#include <sstream>
using std::stringstream;
using std::ostringstream;

#include <climits>      // for INT_MAX, INT_MIN


int reverse_1(int x)
{
    // transfer int to string
    stringstream ss;
    ss << x;
    string str = ss.str();

    if(*(str.end() - 1) == '0')     // if the integer's last digit is 0
    {
        str = str.substr(0, str.size() - 1);
    }

    if(str.substr(0, 1) == string("-"))    // negative
    {
        string str2 = str.substr(1);
        std::reverse(str2.begin(), str2.end());
        str = string("-") + str2;
    }
    else
    {
        std::reverse(str.begin(), str.end());
    }

    // if the reversed integer overflows
    if(str.size() == 11 && str > string("-2147483648"))
    {
        return 0;
    }
    if(str.size() == 10 && str > string("2147483647"))
    {
        return 0;
    }

    // transfer string to int
    int ret = 0;
    ss = stringstream(str);
    ss >> ret;

    return ret;
}

// @Kenigma https://discuss.leetcode.com/topic/6005/shortest-code-possible-in-c
int reverse_2(int x)
{
    long long ans = 0;
    while(x)
    {
        ans = ans * 10 + x % 10;
        x /= 10;
    }

    return (ans > INT_MAX || ans < INT_MIN) ? 0 : ans;
}

int reverse_3(int x)
{
    int ans = 0;
    while(x)
    {
        int temp = ans * 10 + x % 10;
        if(temp / 10 != ans)
            return 0;
        ans = temp;
        x /= 10;
    }

    return ans;
}

int reverse(int x)
{
    return reverse_3(x);
}

int main()
{
    int test = -1463847413;
    int res = reverse(test);
    cout << res << endl;

    return 0;
}
