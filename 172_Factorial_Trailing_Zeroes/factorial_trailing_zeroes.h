/*
 Author:            cuckoo
 Date:              2017/06/09 18:46:32
 Update:            
 Problem:           Factorial Trailing Zeroes
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/factorial-trailing-zeroes/#/description

 */

class Solution {
public:
    int trailingZeroes(int n) {
        return trailingZeroesFirst(n);
    }

    int trailingZeroesFirst(int n)
    {
        // 10的因子为2和5, 对于阶乘来说, 有足够多的因子2，故能提供多少因子5，阶乘结果末尾就有多少零
        // 统计是5的倍数的数个数, 即可以提供因子5的数
        // 统计是25的倍数的数个数, 即可以再提供一个因子5的数
        // 统计是125的倍数的数个数, 即可以再次提供一个因子5的数
        // ...
        // 例如, 125可以提供3个因子5, 故会统计3次
        int result = 0;
        while(n >= 5)
        {
            n /= 5;
            result += n;
        }
        
        return result;
    }
};
