
方案一：两个索引，从后向前依次遍历，当匹配字符分别为普通字符，'.'或'*'时，根据具体情况进入不
同的分支。情况太复杂，难以穷举所有情况。

方案二：递归。详见[Discuss](https://discuss.leetcode.com/topic/6183/my-concise-recursive-and-dp-solutions-with-full-explanation-in-c)

方案三：动态规划。详见[Discuss](https://discuss.leetcode.com/topic/6183/my-concise-recursive-and-dp-solutions-with-full-explanation-in-c)

    f[i][j]: if s[0..i-1] matches p[0..j-1]
    if p[j - 1] != '*'
        f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
    if p[j - 1] == '*', denote p[j - 2] with x
        f[i][j] is true iff any of the following is true
        1) "x*" repeats 0 time and matches empty: f[i][j - 2]
        2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
        '.' matches any single character


