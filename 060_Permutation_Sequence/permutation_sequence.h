/*
 Author:            cuckoo
 Date:              2017/04/06 20:09:34
 Update:            
 Problem:           Permutation Sequence
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/permutation-sequence/#/description

 */

#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    string getPermutation(int n, int k) {
        return getPermutation_1(n, k);
    }
    
    string getPermutation_1(int n, int k)
    {
        int count = 1;
        vector<int> factorial(n);
        factorial[0] = 1;
        for(int i = 1; i <= n; ++i)
        {
            count *= i;
            factorial[i] = count;
        }
        if(k > count)
            return string();
        
        string result;
        vector<char> nums = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for(int i = 1; i <= n; ++i)
        {
            int index = (k - 1) / factorial[n-i];
            result += nums[index];
            nums.erase(nums.begin() + index);
            k = k - index * factorial[n-i];
        }
        
        return result;
    }
};
