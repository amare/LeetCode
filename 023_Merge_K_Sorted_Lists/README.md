
###__解决思路__:

 - 初始化最终有序链表result
 - 遍历链表数组，调用[合并两个有序链表](../021_Merge_Two_Sorted_Lists/merge_two_sorted_lists.h)的方法，依次传入result和新链表
 - 生成最终结果result


####时间复杂度

假设链表数组中每个链表有N个元素，共有K个链表

|iteration|current size|new list size|Average|
|:---|:---:|:---:|:---:|
|1|0|N|N/2|
|2|N|N|2N/2|
|3|2N|N|3N/2|

$N/2 + 2N/2 + ... + KN/2  =  \frac{N}{2}\sum_{i=1}^K i  =  \frac{NK(K+1)}{4} $


======

[更快的方法](https://discuss.leetcode.com/topic/6882/sharing-my-straightforward-c-solution-without-data-structure-other-than-vector/3)

[优先队列](https://discuss.leetcode.com/topic/7160/brief-c-solution-with-priority_queue/2)

[堆](https://discuss.leetcode.com/topic/7160/brief-c-solution-with-priority_queue/5)

[分治](https://discuss.leetcode.com/topic/29088/c-solution-using-merge-sort)


