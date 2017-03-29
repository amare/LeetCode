
    Author:            cuckoo
    Date:              2017/03/29 10:17:03
    Update:            
    Problem:           Merge Sorted Array
    Difficulty:        Easy
    Source:            https://leetcode.com/problems/merge-sorted-array/#/description

__Solution Step__:
 - three pointer: `tail` - the end of the new array whose length is (m + n)  
                  `index1` - the end of array1 which is not in the right position in new array  
                  `index2` - the end of array2 which is not in the right position in new array
 - loop until all elments of one of two array are in right position
 - if array2 is longer than array1, just copy the rest of array2 to new array


======
 - [more concise](https://discuss.leetcode.com/topic/16946/4ms-c-solution-with-single-loop)
