/*
 Author:            cuckoo
 Date:              2017/05/04 19:37:54
 Update:            
 Problem:           Can I Win
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/can-i-win/#/description

 */

#include <unordered_map>
using std::unordered_map;

#include <vector>
using std::vector;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        return canIWinFirst(maxChoosableInteger, desiredTotal);
    }
    
    
    bool canIWinFirst(int max_choosable_integer, int desired_total)
    {
        int sum = (1 + max_choosable_integer) * max_choosable_integer / 2;
        if(sum < desired_total)
            return false;
            
        if(desired_total <= 0)
            return true;
        
        unordered_map<int, bool> dp;
        // used - the state of the game
        vector<bool> used(max_choosable_integer + 1, false);
        
        return backtracking(dp, desired_total, used);
    }
    
private:
    bool backtracking(unordered_map<int, bool> &dp, int desired_total, vector<bool> &used)
    {
        if(desired_total <= 0)
            return false;
        
        int key = format(used);
        if(dp.find(key) != dp.end())
            return dp[key];
        
        // try every unchosen number as the next step
        for(int i = 1; i < used.size(); ++i)
        {
            if(used[i] == false)
            {
                used[i] = true;
                // another player lose
                if(backtracking(dp, desired_total - i, used) == false)
                {
                    dp.insert({key, true});
                    used[i] = false;
                    return true;
                }
                
                used[i] = false;
            }
        }
        
        dp.insert({key, false});
        return false;
    }
    
    // transfer a sequence of bool values to a num
    int format(vector<bool> &used)
    {
        int num = 0;
        for(auto b : used)
        {
            num <<= 1;
            if(b)
                num |= b;
        }
        
        return num;
    }
};
