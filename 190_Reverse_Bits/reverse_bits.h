/*
 Author:            cuckoo
 Date:              2017/05/22 22:19:38
 Update:            
 Problem:           Reverse Bits
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/reverse-bits/#/description

 */

#include <cstdint>      // for unit32_t

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        return ReverseBitsFirst(n);
    }
    
    uint32_t ReverseBitsFirst(uint32_t n)
    {
        uint32_t result = 0;
        
        for(int i = 0; i < 32; ++i)
        {
            if((n >> i) & 1 == 1)
                result |= 1 << (31 - i);
        }
        
        return result;
    }
};
