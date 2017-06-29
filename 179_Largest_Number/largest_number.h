/*
 Author:            cuckoo
 Date:              2017/06/09 19:51:01
 Update:            
 Problem:           Largest Number
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/largest-number/#/description

 */

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <cstring>          // for strcmp

#include <algorithm>            // for sort()

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        return largestNumberSecond(nums);
    }
    
    struct CompareFunction
    {
        bool operator()(int a, int b)
        {
            string s1 = std::to_string(a), s2 = std::to_string(b);
            return std::strcmp((s1 + s2).c_str(), (s2 + s1).c_str()) < 0;
        }
    };
    string largestNumberFirst(vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums), CompareFunction());
        
        string result;
        for(auto iter = nums.rbegin(); iter != nums.rend(); ++iter)
            result += std::to_string(*iter);
            
        return (!result.empty() && result[0] == '0') ? "0" : result;
    }
    
    string largestNumberSecond(vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums), [](int a, int b){
            return std::to_string(a) + std::to_string(b) > std::to_string(b) + std::to_string(a);
        });
        
        string result;
        for(auto num : nums)
            result += std::to_string(num);
            
        return (!result.empty() && result[0] == '0') ? "0" : result;
    }
};
