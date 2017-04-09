/*
 Author:            cuckoo
 Date:              2017/04/08 14:15:24
 Update:            
 Problem:           Ugly Number
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/ugly-number/#/description

 */

#include <cmath>        // for pow()

class Solution {
public:
    bool isUgly(int num) {
        return isUgly_2(num);
    }
    
    // Brute Force
    bool isUgly_1(int num)
    {
        if(num <= 0) return false;

        // num range from 0 to 2147483247(pow(2,31) - 1)
        for(int i = 0; i < 31; ++i)
            for(int j = 0; j < 20; ++j)
                for(int k = 0; k < 14; ++k)
                    if(std::pow(2, i) * std::pow(3, j) * std::pow(5, k) == num) 
                        return true;
        /*               
        cout << static_cast<int>(pow(3,20)) << endl;
        cout << static_cast<int>(pow(5,14)) << endl;
        */
        
        return false;
    }
    
    bool isUgly_2(int num)
    {
        if(num <= 0) return false;
        
        while((num & 1) == 0) num >>= 1;
        while(num % 3 == 0) num /= 3;
        while(num % 5 == 0) num /= 5;
        
        return num == 1;
    }
};
