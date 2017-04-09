
    Author:            cuckoo
    Date:              2017/04/08 09:36:04
    Update:            
    Problem:           House Robber
    Difficulty:        Easy
    Source:            https://leetcode.com/problems/house-robber/#/description

__Solution Step__:

 - dp[i] represent the total money whether current house is robbed or not
 - dp[i] = max(dp[i-2] + house[i], dp[i-1])
                       ↑              ↑
                      rob          not rob

======
 - [Constant Space](https://discuss.leetcode.com/topic/11110/c-1ms-o-1-space-very-simple-solution)
