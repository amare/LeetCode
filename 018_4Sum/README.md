
    Author:            cuckoo
    Date:              2017/04/19 20:11:14
    Update:            
    Problem:           4Sum
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/4sum/#/description

#### Solution Step
 - [3Sum](https://leetcode.com/problems/3sum/#/description)

#### Discuss
 - [More Faster](https://discuss.leetcode.com/topic/28641/my-16ms-c-code)
```
    The key point is to add checking at the start of the loop.
    At loop 1:
        if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
        if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
    At loop 2:
        if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
        if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
    Then we skip this loop to avoid a waste of time.
```
 - [kSum](https://discuss.leetcode.com/topic/33182/java-backtracking-solution-for-k-sum-beat-94)
