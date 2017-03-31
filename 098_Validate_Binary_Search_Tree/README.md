
    Author:            cuckoo
    Date:              2017/03/31 11:09:19
    Update:            
    Problem:           Validate Binary Search Tree
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/validate-binary-search-tree/#/description

__Solution Step__:
 - 1. make sure the left-child's key is less than root's key and the right-child's key is greater than root's key
 - 2. make sure that the `most-right-child` of a left-subtree has the key `less` than the root's key
 - 3. make sure that the `most-left-child` of a right-subtree has the key `greater` than the root's key

======
 - [Morris Trversal](https://discuss.leetcode.com/topic/17357/morris-traversal-o-1-space-no-recursion-o-n-time-with-explanation-java)  

    >`Inorder Traversal` to see if the value is monotonically increased  
    >use `Morris Traversal` to gain O(1) space, No recursion and O(n) time  

    >main idea: the key part of tree traversal is how to go back to parent,
               one way is to use recursion and store parent in function stack,
               another way is to use explicit stack to store parent,
               morris traversal modify the original tree and 
               let the right child of the predecessor of the root to point back to itself
               in order to go back to the root and then restore the pointer(set it to null again)
               the overall time complexity is still O(n), since the tree is traversed
               no more than twice(there is not overlap between the path of finding predecessor)  


 - [inorder traversal recursion](https://discuss.leetcode.com/topic/4659/c-in-order-traversal-and-please-do-not-rely-on-buggy-int_max-int_min-solutions-any-more)

 >using previous node
 - [recursion version](https://discuss.leetcode.com/topic/18573/c-simple-recursive-solution)  

 >using root node to be max_node in left-subtree traversal or min_node in right-subtree traversal
