/*
 Author:            cuckoo
 Date:              2017/03/17 11:12:09
 Update:
 Problem:           Count and Say
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/count-and-say

 */

#include <string>
using std::string;
using std::to_string;

class Solution {
public:
    string countAndSay(int n) {
        return countAndSay_1(n);
    }

    string countAndSay_1(int n)
    {
        if(n <= 0) return string("1");
        string result = "1";
        while(--n)
        {
            string temp;
            for(int i = 0; i < result.size(); ++i)
            {
                int count = 1;
                while(i + 1 < result.size() && result[i + 1] == result[i])
                {
                    ++count;
                    ++i;
                }
                temp += to_string(count) + result[i];
            }
            result = temp;
        }

        return result;
    }
};
