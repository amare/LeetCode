/*
 Author:            cuckoo
 Date:              2017/05/10 22:19:05
 Update:            
 Problem:           Arranging Coins
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/arranging-coins/#/description

 */

#include <cmath>        // for sqrt()

class Solution {
public:
    int arrangeCoins(int n) {
        return arrangeCoinsThird(n);
    }
    
    int arrangeCoinsFirst(int n)
    {
        int k = 0;
        while(true)
        {
            if(k * (k + 1) <= 2 * n && 2 * n < (k + 1) * (k + 2))
                return k;
            ++k;
        }
    }
    
    // 1 + 2 + ... + k <= n
    int arrangeCoinsSecond(int n)
    {
        int low = 1, high = n;
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if(0.5* mid * mid + 0.5 * mid <= n)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return low - 1;
    }
    
    // (-b + sqrt(4 * a * c) / (2 * a)
    int arrangeCoinsThird(int n)
    {
        return static_cast<int>((std::sqrt(1 + 8.0 * n) - 1) / 2);
    }
};
