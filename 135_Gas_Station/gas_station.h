/*
 Author:            cuckoo
 Date:              2017/06/07 20:35:33
 Update:            
 Problem:           Gas Station
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/gas-station/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        return canCompleteCircuitSecond(gas, cost);
    }
    
    int canCompleteCircuitFirst(vector<int>& gas, vector<int>& cost)
    {
        // check input
        
        //
        int n = gas.size();
        for(int start_index = 0; start_index < n; ++start_index)
        {
            int current_index = start_index;
            // 从当前站到达下一站后所剩余的气量
            int left = gas[current_index] - cost[current_index];
            
            for(int i = 1; i < n && left >= 0; ++i)
            {
                current_index = (start_index + i) % n;
                left = left + gas[current_index] - cost[current_index];
            }
            if(left >= 0 && ((current_index + 1) % n) == start_index)
                return start_index;
        }
        
        return -1;
    }
    
    int canCompleteCircuitSecond(vector<int>& gas, vector<int>& cost)
    {
         /*
         * If start from i, stop before station x -> no station k from i + 1 to x - 1 can reach x.
         * Bcoz if so, i can reach k and k can reach x, then i reaches x. Contradiction.
         * Thus i can jump directly to x instead of i + 1, bringing complexity from O(n^2) to O(n).
         */
        int n = gas.size();
        int i = 0, j = 0;
        // start from station i
        for(; i < n; i += j)
        {
            int gas_left = 0;
            // forward j stations
            for(j = 1; j <= n; ++j)
            {
                int k = (i + j - 1) % n;
                gas_left += gas[k] - cost[k];
                if(gas_left < 0)
                    break;
            }
            if(j > n)
                return i;
        }
        
        return -1;
    }
};
