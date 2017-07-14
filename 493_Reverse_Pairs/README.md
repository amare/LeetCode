
    Author:            cuckoo
    Date:              2017/07/12 16:48:51
    Update:            
    Problem:           Reverse Pairs
    Difficulty:        Hard
    Source:            https://leetcode.com/problems/reverse-pairs/#/description

#### Solution Step


#### Editorial Solution
 - [Four Approaches](https://leetcode.com/articles/reverse-pairs/#approach-4-modified-merge-sort-accepted)
    - `Modified Merge Sort`
        - Time Complexity: O(nlog(n))
            - T(n) = 2 * T(n/2) + O(n) => T(n) = n + nlog(n)
        - Space Complexity: O(n). Additional space for storing copy arrays
    - `Binary Search Tree`
        - Time Complexity: O(n^2)
            - The best case complexity for BST is O(log(n)) for search as well as insertion, wherein, the tree formed is complete binary tree
            - Whereas, in case like [1,2,3,4,5,6,7,8,...], insertion as well as search for an element becomes O(n) in time, since, the tree is skewed in only one direction, and hence, is no better than the array
            - So, in worst case, for searching and insertion over n items, the complexity is O(n*n)
        - Space Complexity: O(n) extra space for storing the BST in Node struct.
    - `Binary Indexed Tree`
        - Time Complexity: O(nlog(n))
            - In query and update operations, we see that the loop iterates at most the number of bits in index which can be at most n. Hence, the complexity of both the operations is O(log(n))(Number of bits in n is log(n))
            - The in-built operation lower_bound is binary search, hence O(log(n))
            - We perform the operations for n elements, hence the total complexity is O(nlog(n))
        - Space Complexity: O(n). Additional space for bit array and copy array
