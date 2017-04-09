
    Author:            cuckoo
    Date:              2017/04/08 10:22:53
    Update:            
    Problem:           House Robber II
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/house-robber-ii/#/description

__Solution Step__:

 - two pass
 - one from `first` to `last - 1` - (not rob the last house)
 - another from `first + 1` to 'last' - (not rob the last house)
 - return max of one result and another result
