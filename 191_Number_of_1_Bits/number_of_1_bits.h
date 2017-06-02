/*
 Author:            cuckoo
 Date:              2017/05/18 22:23:39
 Update:            
 Problem:           Number of 1 Bits
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/number-of-1-bits/#/description

 */

#include <cinttypes>        // for uint32_t

#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return hammingWeightSecond(n);
    }
    
    int hammingWeightFirst(uint32_t n)
    {
        int result = 0;
        
        for(int i = 0; i < 32; ++i)
            if((n >> i) & 1 == 1)
                ++result;
        
        return result;   
    }
    
    // Loop and Flip
    int hammingWeightSecond(uint32_t n)
    {
        cout << "n: " << n << endl;
        int result = 0;
        int mask = 1;
        for(int i = 0; i < 32; ++i)
        {
            // when i == 31, mask == -2147483648 which represents by binary 
            //                        1000 0000 0000 0000 0000 0000 0000 0000
            cout << i << " " << mask << endl;
            if((n & mask) != 0)
                ++result;
            mask <<= 1;
        }
        
        cout << "result: " << result << endl;
        return result;
    }
    
    // n & (n - 1) : flips the least-significant 1-bit in n to 0
    int hammingWeightThird(uint32_t n)
    {
        int result = 0;
        while(n != 0)
        {
            ++result;
            n &= (n - 1);
        }
        
        return result;
    }
};
