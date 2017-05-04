/*
 Author:            cuckoo
 Date:              2017/05/03 21:10:40
 Update:            
 Problem:           Happy Number
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/happy-number/#/description

 */

#include <unordered_set>
using std::unordered_set;

class Solution {
public:
    bool isHappy(int n) {
        return isHappyFirst(n);
    }
    
    bool isHappyFirst(int n)
    {
        if(n < 0) return false;
        
        unordered_set<int> hash;
        while(true)
        {
            if(hash.find(n) != hash.end())
                return false;
            hash.insert(n);
            
            int next = 0;
            while(n != 0)
            {
                next += (n % 10) * (n % 10);
                n /= 10;
            }
            if(next == 1)
                return true;
            n = next;
        }
    }
};
