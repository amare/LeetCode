/*
 Author:            cuckoo
 Date:              2017/04/21 21:15:55
 Update:            
 Problem:           Combination Sum IV
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/combination-sum-iv/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        return combinationSum4TwoUpdate(nums, target);
    }
    
    // Time Limit Exceeded
    void backtracking(vector<int> &nums, int remain, int &count)
    {
        if(remain < 0)  return;
        if(remain == 0)
        {
            ++count;
            return;
        }
        
        for(int i = 0; i < nums.size(); ++i)
            backtracking(nums, remain - nums[i], count);
        
    }
    int combinationSum4_1(vector<int>& nums, int target)
    {
        int count = 0;
        backtracking(nums, target, count);
        
        return count;
    }
    
    // recursive + memorization
    int BacktrackingTwo(vector<int> &nums, int target, vector<int> &dp)
    {
        if(dp[target] != -1)
            return dp[target];
        
        dp[target] = 0;
        for(int i = 0; i < nums.size(); ++i)
            if(target >= nums[i])
                dp[target] += BacktrackingTwo(nums, target - nums[i], dp);
        
        return dp[target];
    }
    int combinationSum4TwoUpdate(vector<int>& nums, int target)
    {
        int n = nums.size();
        if(0 == n) return 0;
        
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        
        return BacktrackingTwo(nums, target, dp);
    }
    
    /*wrong
    // Dynamic Programming
    int combinationSum4_2(vector<int>& nums, int target)
    {
        int n = nums.size();
        if(0 == n) return 0;
        
        // nums[i] is positive
        sort(nums.begin(), nums.end());
        
        vector<int> dp(target + 1, 0);
        for(int i = 0; i < n; ++i)
            dp[nums[i]] = 1;
        
        for(int k = nums[0] + 1; k <= target; ++k)
        {
            cout << "k: " << k << endl;
            for(int i = 0; i < n; ++i)
            {
                if(nums[i] < k)
                {
                    cout << nums[i] << " " << k - nums[i] << endl;
                    dp[k] += dp[nums[i]] * dp[k - nums[i]];   
                }
            }
            cout << "dp[" << k << "]: " << dp[k] << endl;
            cout << "===============" << endl;
        }
        
        return dp[target];
    }
    */
};
