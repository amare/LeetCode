
    Author:            cuckoo
    Date:              2017/04/22 13:27:06
    Update:            
    Problem:           Arithmetic Slices
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/arithmetic-slices/#/description

#### Solution Step
 - `dp[i]` means the number of arithmetic slices in current sequence ending with A[i]
```
sequence: {1 2 3 5 7}


        i
        ↓
    1 2 3           dp[2] = dp[1] + 1
        ↑                           ↑
        k                        (1,2,3)

          i
          ↓
    1 2 3 5         dp[3] = dp[2]
          ↑
          k

            i
            ↓
    1 2 3 5 7       dp[4] = dp[3] + 1
            ↑                       ↑
            k                    (3,5,7)
```

#### Discuss
 - [O(n), More Concise](https://discuss.leetcode.com/topic/62992/3ms-c-standard-dp-solution-with-very-detailed-explanation) - `dp[i]` means the number of arithmetic which all ends with A[i]

