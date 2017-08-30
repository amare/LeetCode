/*
 Author:            cuckoo
 Date:              2017/08/06 20:51:32
 Update:            
 Problem:           Remove K Digits
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/remove-k-digits/description/

 */

#include <string>
using std::string;

class Solution {
public:
    string removeKdigits(string num, int k) {
        return RemoveKdigitsFirst(num, k);
    }
    
    string RemoveKdigitsFirst(string &num, int k)
    {
        int n = num.size();
        if(k > n)
            return "";
        
        string result;
        for(auto c : num)
        {
            while(k > 0 && !result.empty() && result.back() > c)            // still need to remove redundant digits
            {
                result.pop_back();                                          // make sure digits in result are in ascending order
                --k;                                                        // remove one char
            }
            result.push_back(c);
        }
        
        // make sure remove k digits in total
        while(!result.empty() && k-- > 0)
            result.pop_back();
        
        // remove leading zero
        auto pos = result.find_first_not_of('0');
        result = pos != string::npos ? result.substr(pos) : "0";
        
        return result;
    }
};
