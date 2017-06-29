/*
 Author:            cuckoo
 Date:              2017/06/14 10:25:15
 Update:            
 Problem:           Bitwise AND of Numbers Range
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/bitwise-and-of-numbers-range/#/description

 */

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return rangeBitwiseAndSecond(m, n);
    }
    
    // TLE
    int rangeBitwiseAndFirst(int m, int n)
    {
        m = static_cast<unsigned int>(m);
        n = static_cast<unsigned int>(n);
    
        int result = 0;
        for(int i = 0; i < 32; ++i)
        {
            if(m >> i & 1 != 0)
            {
                unsigned int j = m + 1;
                while(j <= n)
                {
                    if((j >> i & 1) == 0)       // 注意运算符的优先级
                        break;
                    ++j;                        // if j == 2147483647, 会溢出
                }
                if(j > n)
                    result |= 1 << i;
            }
        }
            
        return result;
    }
    
    // 只要 m != n, 则区间[m, n]至少有一个偶数和奇数, 最后一位的与运算结果为0
    // 于是问题转化为：find the common prefix of m and n 's binary code
    int rangeBitwiseAndSecond(int m, int n)
    {
        int step = 0;
        while(m != n)
        {
            m >>= 1;
            n >>= 1;
            ++step;
        }
        
        return m << step;
    }
};
