/*
 Author:            cuckoo
 Date:              2017/04/22 13:27:06
 Update:            
 Problem:           Arithmetic Slices
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/arithmetic-slices/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        return numberOfArithmeticSlicesFirst(A);
    }
    
    int numberOfArithmeticSlicesFirst(vector<int>& A)
    {
        int n = A.size();
        if(n < 3) return 0;
        // dp[i] means the number of arithmetic slices in current sequence ending with A[i]
        vector<int> dp(n, 0);
        for(int i = 2; i < n; ++i)
        {
            dp[i] = dp[i-1];
            for(int k = i; k >= 2; --k)
            {
                if(A[k-2] - A[k-1] != A[k-1] - A[k])
                    break;
                ++dp[i];
            }
        }
         
        return dp[n-1];
    }
};
