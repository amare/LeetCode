/*
 Author:            cuckoo
 Date:              2017/05/03 22:20:18
 Update:            
 Problem:           Count Primes
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/count-primes/#/description

 */

#include <algorithm>        // for count()

#include <vector>
using std::vector;

class Solution {
public:
    int countPrimes(int n) {
        return countPrimesSecond(n);
    }
    
    /* wrong - example {49(7 * 7)}
    int countPrimesFirst(int n)
    {
        if(n <= 1) return 0;
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 2;
        if(n == 5) return 3;
        
        int num = 5, count = 3;
        while(++num <= n)
            if(num % 2 != 0 && num % 3 != 0 && num % 5 != 0)
                ++count;
        
        return count;
    }
    */
    
    int countPrimesSecond(int n)
    {
        if(n <= 1) return 0;
        
        vector<bool> is_prime(n, true);
        is_prime[0] = is_prime[1] = false;
        
        for(int i = 0; i * i < n; ++i)
        {
            if(is_prime[i])
            {
                for(int j = i * i; j < n; j += i)
                    is_prime[j] = false;
            }
        }
        
        return count(is_prime.begin(), is_prime.end(), true);
    }
};
