
    Author:            cuckoo
    Date:              2017/07/01 10:27:56
    Update:            
    Problem:           Find Median From Data Stream
    Difficulty:        Hard
    Source:            https://leetcode.com/problems/find-median-from-data-stream/#/description

#### Solution Step
 - 剑指Offer
    - 数据在容器中已排序，可以分割为两个部分，前半部分的数据均小于等于后半部分
    - 前半部分用最大堆实现，后半部分用最小堆实现，从而可以在O(1)时间内获取中位数
    - 插入时需保证数据平均分配到两个堆内，并且最大堆中的数据都要小于等于最小堆中的数据
 - [Sliding Window Median](https://leetcode.com/problems/sliding-window-median/#/description)
    - maintain a median pointer which points to (N/2)th element
    - multiset - implemented by Self-balancig Binary Search Tree

#### Editorial Solution
 - [Four Approaches](https://leetcode.com/articles/find-median-from-data-stream/)
