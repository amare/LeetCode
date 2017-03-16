
    Author:            cuckoo
    Date:              2017/03/16 09:32:56
    Update:
    Problem:           Search in Rotated Sorted Array
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/search-in-rotated-sorted-array

__解决思路__:

 - 寻找pivot
 - 如果target没在[0, pivot]范围中，则二分搜索(pivot, size)范围内的数字

======
[Revised Binary Search](https://discuss.leetcode.com/topic/7711/revised-binary-search)

Notice that there is always a half of the array sorted, so we only need to see whether
the target is in the sorted part or rotated part.

[Binary Search 2](https://discuss.leetcode.com/topic/3538/concise-o-log-n-binary-search-solution)

 - 二分搜索寻找最小值，即pivot
 - 利用pivot找到真正的中间值，进行二分搜索

[Clever idea](https://discuss.leetcode.com/topic/28367/c-4-lines-4ms/4)
