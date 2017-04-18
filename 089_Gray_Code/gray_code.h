/*
 Author:            cuckoo
 Date:              2017/04/14 10:58:55
 Update:            
 Problem:           Gray Code
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/gray-code/#/description

 */

#include <vector>
using std::vector;

#include <bitset>
using std::bitset;

class Solution {
public:
    vector<int> grayCode(int n) {
        return grayCode_2(n);
    }
    
    /* wrong
    int MyStringToNonNegativeInt(string &s)
    {
        long result = 0, size = s.size();
        int index = s.find_first_not_of(' ');
        if(index == -1) return 0;
        while(index < size && isdigit(s[index]))
        {
            result = result * 2 + (s[index++] - '0');
            if(result >= INT_MAX) return INT_MAX;
        }
        
        return result;
    }
    
    void backtracking(vector<int> &result, string &s, int index, int n)
    {
        if(index > n)
        {
            result.push_back(MyStringToNonNegativeInt(s));
            return;
        }
        s.push_back('0');
        backtracking(result, s, index + 1, n);
        s.pop_back();
        s.push_back('1');
        backtracking(result, s, index + 1, n);
        s.pop_back();
    }
    vector<int> grayCode_1(int n)
    {
        if(n < 0) return {};
        vector<int> result;
        string s;
        backtracking(result, s, 1, n);
        
        return result;
    }
    */
    
    void backtracking(vector<int> &result, bitset<32> &bits, int index)
    {
        if(index == 0)
        {
            result.push_back(bits.to_ulong());
            return;
        }
        backtracking(result, bits, index - 1);
        bits.flip(index - 1);
        backtracking(result, bits, index - 1);
    }
    vector<int> grayCode_2(int n)
    {
        if(n < 0) return {};
        
        vector<int> result;
        bitset<32> bits;
        backtracking(result, bits, n);
        
        return result;
    }
};
