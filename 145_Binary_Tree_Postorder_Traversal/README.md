
    Author:            cuckoo
    Date:              2017/05/07 11:23:31
    Update:            
    Problem:           Binary Tree Postorder Traversal
    Difficulty:        Hard
    Source:            https://leetcode.com/problems/binary-tree-postorder-traversal/#/description

#### Solution Step
 - Recursion
 - Stack
 - Morris

#### Discuss
 - [Using Pre-order Traversal](https://discuss.leetcode.com/topic/2919/my-accepted-code-with-explaination-does-anyone-have-a-better-idea) - pre-order traversal is `root-left-right`, and post order is `left-right-root`. modify the code for pre-order to make it `root-right-left`, and then reverse the output so that we can get `left-right-root` .
 - [Real Post-order Traversal without reversing Pre-order](https://discuss.leetcode.com/topic/30632/preorder-inorder-and-postorder-iteratively-summarization/20)
 - [Real Post-order Traversal without reversing Pre-order2](https://discuss.leetcode.com/topic/12801/a-real-postorder-traversal-without-reverse-or-insert-4ms)
 - [Using a List without Reverse](https://discuss.leetcode.com/topic/2919/my-accepted-code-with-explaination-does-anyone-have-a-better-idea/59)
 - [Morris Traversal](https://discuss.leetcode.com/topic/14473/0-ms-clear-c-solutions-iterative-recursive-morris-traversal-3-different-solutions/)

#### Summary
 - [Method One](https://discuss.leetcode.com/topic/2919/my-accepted-code-with-explaination-does-anyone-have-a-better-idea/51)
 - [Method Two](https://discuss.leetcode.com/topic/44387/preorder-inorder-postorder-iterative-solution-by-c)
 - [Method Three](https://discuss.leetcode.com/topic/2919/my-accepted-code-with-explaination-does-anyone-have-a-better-idea/61)
