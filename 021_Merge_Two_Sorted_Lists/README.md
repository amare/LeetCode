
__解决思路__:
 - 构造一个新的头节点
 - 初始化尾节点指向头节点
 - 用两个指针分别遍历两个链表，选择较小值节点链接到为尾节点，并更新尾节点
 - 继续遍历，直到有一个链表为空
 - 将不空的链表链接到尾节点

======
 [更简洁的迭代版本](https://discuss.leetcode.com/topic/12946/my-10-line-clean-c-code)

 [递归版本](https://discuss.leetcode.com/topic/2513/a-recursive-solution)

 [更简洁的递归版本](https://discuss.leetcode.com/topic/18709/3-lines-c-12ms-and-c-4ms)
