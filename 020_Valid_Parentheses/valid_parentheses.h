/*
 Author:            cuckoo
 Date:              2017/03/11 17:27:51
 Update:
 Problem:           Valid Parentheses
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/valid-parentheses

 */

#include <stack>
using std::stack;

#include <string>
using std::string;

class Solution {
public:
    bool isValid(string s) {
        return isValid_1(s);
    }

    bool isValid_1(string &s)
    {
        stack<char> left_parentheses;
        int size = s.size();
        for(int i = 0; i < size; ++i)
        {
            switch(s[i])
            {
                case ')':
                    // stack.top() is undefined if the stack is empty.
                    if(!left_parentheses.empty() && '(' == left_parentheses.top())
                        left_parentheses.pop();
                    else
                        return false;
                    break;
                case '}':
                    if(!left_parentheses.empty() && '{' == left_parentheses.top())
                        left_parentheses.pop();
                    else
                        return false;
                    break;
                case ']':
                    if(!left_parentheses.empty() && '[' == left_parentheses.top())
                        left_parentheses.pop();
                    else
                        return false;
                    break;
                case '(':
                case '{':
                case '[':
                    left_parentheses.push(s[i]);
                    break;
                default:
                    return false;
            }
        }
        /* garbage code
        if(left_parentheses.empty())
            return true;
        else
            return false;
        */
        return left_parentheses.empty();
    }

    bool isValid_2(string s)
    {
        stack<char> paren;
        for (char& c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[': paren.push(c); break;
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
                default: ; // pass
            }
        }
        return paren.empty() ;
    }
};
