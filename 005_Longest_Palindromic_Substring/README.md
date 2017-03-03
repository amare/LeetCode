
方案1：
 - 遍历字符串s，依次取出第i个元素
 - 判断区间[i, j]的子字符串是否是回文字符串，j取值范围[i+1, n]。其中，n为字符串s的长度，j从n开始取值，依次递减，直到i+1

方案2：
 - 遍历字符串s，找到 AA 或 ABA 模式的子字符串，存区间下标(i, j)到数组Array中
 - 遍历数组Array，取出下标，在字符串s中将区间分别向两边扩展，寻找更长回文字符串
 - 更好的思路见[Approach #4](https://leetcode.com/articles/longest-palindromic-substring/#approach-4-expand-around-center-accepted)

方案3：动态规划，转化为填表的过程。详见[Approach #3](https://leetcode.com/articles/longest-palindromic-substring/#approach-3-dynamic-programming-accepted)

方案4：[Manacher's Algorithm](http://articles.leetcode.com/longest-palindromic-substring-part-ii)

方案5：[Longest Common Substring](https://leetcode.com/articles/longest-palindromic-substring/#approach-1-longest-common-substring-accepted)

其他：[LeetCode Editorial Solution](https://leetcode.com/articles/longest-palindromic-substring)
