
    Author:            cuckoo
    Date:              2017/03/28 20:43:54
    Update:            
    Problem:           Subsets
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/subsets/#/description

__Solution Step__:
 - 初始化result为[[]]
 - 遍历数组集合，插入当前值到旧结果A的每个子集合中，获得新结果B
 - 更新结果C为新结果B与旧结果A的并集
 - 继续遍历数组集合，直到其为空

======
 - [bit manipulation](https://discuss.leetcode.com/topic/2764/my-solution-using-bit-manipulation/7)
 - [backtracking](https://discuss.leetcode.com/topic/46159/a-general-approach-to-backtracking-questions-in-java-subsets-permutations-combination-sum-palindrome-partitioning)
