
    Author:            cuckoo
    Date:              2017/03/17 20:35:53
    Update:            2017/07/20 18:15:16
    Problem:           Missing Number
    Difficulty:        Easy
    Source:            https://leetcode.com/problems/missing-number

__Solution Step__:
 - First
     - 构造一个标志位数组，其大小为待查找数组元素个数加1，全部初始化为false
     - 遍历待查找数组，对于每个数字，置标志位为true
     - 遍历标志位数组，找到值为false的索引，即缺失数字
 - Third - [From LintCode](http://www.jiuzhang.com/solution/find-the-missing-number/)

======
 - [xor](https://discuss.leetcode.com/topic/22313/c-solution-using-bit-manipulation) - 异或满足交换律和结合律，且自身异或为0。算法中参与异或运算的有
(0, 1, ..., size - 1), (size) 以及 待查找数组中的所有元素

 - [XOR More Concise](https://discuss.leetcode.com/topic/22366/simple-c-codes)
 - [more](https://discuss.leetcode.com/topic/22305/1-lines-ruby-python-java-c)
