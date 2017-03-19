
    Author:            cuckoo
    Date:              2017/03/18 17:33:25
    Update:
    Problem:           Wildcard Matching
    Difficulty:        Hard
    Source:            https://leetcode.com/problems/wildcard-matching

__Solution Step__:
 - recursion (Time Limit Exceeded)
 - Dynamic Promgramming (可以通过去除字符间重复的'*'进行优化)
```
    f[i][j] if s[0..i-1] matches p[0..j-1]
    if p[j-1] != '*'
        f[i][j] = (s[i-1] == p[j-1] || p[j-1] == '?') && f[i-1][j-1]
    if p[j-1] == '*'
        f[i][j] is true if any of the following is true
        1) '*' matches the empty sequence: f[i][j-1]
        2) '*' matches any sequence of characters: f[i-1][j]
        '?' matches any single character
```

======
 - [Backtracking](https://discuss.leetcode.com/topic/57070/c-code-9ms-beats-100-persons)
 - [Recursion without TLE](https://discuss.leetcode.com/topic/40848/c-recursive-solution-16-ms)
 - [DP Optimized version](https://discuss.leetcode.com/topic/17901/accepted-c-dp-solution-with-a-trick)
![DynamicProgrammingOptimized](../res/DynamicProgrammingOptimized.png)
======
 - [Recursion2 without TLE](https://discuss.leetcode.com/topic/21577/my-three-c-solutions-iterative-16ms-dp-180ms-modified-recursion-88ms)
 - [KMP](https://discuss.leetcode.com/topic/9390/c-o-n-m-solution-using-kmp)
