
    Author:            cuckoo
    Date:              2017/03/18 12:58:47
    Update:
    Problem:           Trapping Rain Water
    Difficulty:        Hard
    Source:            https://leetcode.com/problems/trapping-rain-water

__Solution Step__:
 - 分块计算
    - 可以看到需要 高-低-高 的形状，设左高坐标为left，低坐标为bottom，右高坐标为right
    - 去掉重复元素，确定left
    - 找到最低点并确认能否构成 高-低-高 形状
    - 寻找right，其中包括，不低于height[left] 以及 低于height[left] 两种情况
    - 分别对以上两种情况进行处理，并更新left和用于遍历的索引i

 > 糟糕的思路和想法

 - 同[Container With Most Water](https://leetcode.com/problems/container-with-most-water)
 两个指针，计算中间的蓄水量（注意需要填补，以免重复计算）

======
 - [bin sum](https://discuss.leetcode.com/topic/5125/sharing-my-simple-c-code-o-n-time-o-1-space)

 >left和right最终会相遇在最高点

 - [water level](https://discuss.leetcode.com/topic/43842/a-simple-c-solution)

 > maybe it's the most clever method
 - [scan from left to right and right to left](https://discuss.leetcode.com/topic/4136/a-different-o-n-approach-easy-to-understand-and-simple-code)
 - [inspired by Candy](https://discuss.leetcode.com/topic/5643/a-two-pass-o-n-solution-inspired-by-one-solution-of-candy)
 - [stack solution inspired by Largest Rectangle in Histogram](https://discuss.leetcode.com/topic/4939/a-stack-based-solution-for-reference-inspired-by-histogram)
