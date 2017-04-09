/*
 Author:            cuckoo
 Date:              2017/04/08 16:03:23
 Update:            
 Problem:           Ugly Number II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/ugly-number-ii/#/description

 */

#include <queue>
using std::priority_queue;

#include <vector>
using std::vector;

#include <cmath>        // for min()

class Solution {
public:
    int nthUglyNumber(int n) {
        return nthUglyNumber_2(n);
    }
    
    // priority_queue
    int nthUglyNumber_1(int n)
    {
        if(n <= 0) return 0;
        
        priority_queue<long, vector<long>, std::greater<long>> q;
        q.push(1l);
        
        for(int i = 1; i < n; ++i)
        {
            long temp = q.top();        // attention long type
            while(!q.empty() && q.top() == temp) q.pop();
            
            q.push(temp * 2);
            q.push(temp * 3);
            q.push(temp * 5);
        }
        
        return q.top();
    }
    
    // Dynamic Programming
    int nthUglyNumber_2(int n)
    {
        if(n <= 0) return 0;
        
        vector<int> ugly(n);
        ugly[0] = 1;
        
        int index2 = 0, index3 = 0, index5 = 0;
        int next_multiple_of_2 = 2, next_multiple_of_3 = 3, next_multiple_of_5 = 5;
        for(int i = 1; i < n; ++i)
        {
            int next_ugly_no = std::min(next_multiple_of_2, std::min(next_multiple_of_3, next_multiple_of_5));
            ugly[i] = next_ugly_no;
            if(next_ugly_no == next_multiple_of_2)
                next_multiple_of_2 = ugly[++index2] * 2;
            if(next_ugly_no == next_multiple_of_3)
                next_multiple_of_3 = ugly[++index3] * 3;
            if(next_ugly_no == next_multiple_of_5)
                next_multiple_of_5 = ugly[++index5] * 5;
        }
        
        return ugly[n-1];
    }
};
