/*
 Author:            cuckoo
 Date:              2017/07/15 18:57:59
 Update:            
 Problem:           Longest Valid Parentheses
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/longest-valid-parentheses/#/description

 */

#include <string>
using std::string;

#include <stack>
using std::stack;

#include <vector>
using std::vector;

class Solution {
public:
    int longestValidParentheses(string s) {
        return LongestValidParenthesesThird(s);
    }
    
    // Wrong
    int LongestValidParenthesesFirst(string &s)
    {
        int n = s.size();
        
        stack<char> left_parentheses;
        vector<int> dp(n + 1, 0);       // dp[i] represent the number of parentheses in the substring ending with s[i]
        
        int result = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(s[i-1] == '(')
            {
                left_parentheses.push('(');
                dp[i] = dp[i-1];
            }
            else
            {
                if(left_parentheses.empty())
                    dp[i] = 0;
                else
                {
                    left_parentheses.pop();
                    dp[i] = dp[i-1] + 1;
                }
            }
            result = std::max(result, dp[i]);
        }
        
        return result * 2;
    }
    
    // Dynamic Programming
    int LongestValidParenthesesSecond(string &s)
    {
        int n = s.size();
        vector<int> dp(n, 0);       // dp[i] represents the length of the longest valid substring ending at ith index
        
        int result = 0;
        for(int i = 1; i < n; ++i)
        {
            if(s[i] == ')')             // .........)
            {
                if(s[i-1] == '(')       // ........()
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                else if(i - dp[i-1] - 1 >= 0 && s[i - dp[i-1] - 1] == '(')      // ...((...))
                    dp[i] = dp[i-1] + (i - dp[i-1] - 2 >= 0 ? dp[i - dp[i-1] - 2] : 0) + 2;
                else                    // ...)(...))
                    dp[i] = 0;
            }
            else                        // .........(
                dp[i] = 0;
            
            result = std::max(result, dp[i]);
        }
        
        return result;
    }
    
    // Stack
    int LongestValidParenthesesThird(string &str)
    {
        int result = 0;
        
        stack<int> s;
        s.push(-1);
        for(int i = 0; i < str.size(); ++i)
        {
            if(str[i] == '(')
                s.push(i);
            else
            {
                s.pop();
                if(s.empty())           // there is not '(' to be matched, update the 前驱 of the start index of new valid substring
                    s.push(i);
                else
                    result = std::max(result, i - s.top());
            }
        }
        
        return result;
    }
};
