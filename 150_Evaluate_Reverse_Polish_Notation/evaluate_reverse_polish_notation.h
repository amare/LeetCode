/*
 Author:            cuckoo
 Date:              2017/06/08 11:09:31
 Update:            
 Problem:           Evaluate Reverse Polish Notation
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/evaluate-reverse-polish-notation/#/description

 */

#include <stack>
using std::stack;

#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        return evalRPNFirst(tokens);
    }
    
    int evalRPNFirst(vector<string>& tokens)
    {
        if(tokens.empty())
            return 0;
        
        stack<int> s;
        int number1 = 0, number2 = 0;
        for(int i = 0; i < tokens.size(); ++i)
        {
            if(tokens[i] == "+")
            {
                number2 = s.top();
                s.pop();
                number1 = s.top();
                s.pop();
                s.push(number1 + number2);
            }
            else if(tokens[i] == "-")
            {
                number2 = s.top();
                s.pop();
                number1 = s.top();
                s.pop();
                s.push(number1 - number2);
            }
            else if(tokens[i] == "*")
            {
                number2 = s.top();
                s.pop();
                number1 = s.top();
                s.pop();
                s.push(number1 * number2);
            }
            else if(tokens[i] == "/")
            {
                number2 = s.top();      // number2 must not be 0
                s.pop();
                number1 = s.top();
                s.pop();
                s.push(number1 / number2);
            }
            else
            {
                s.push(std::stoi(tokens[i]));
            }
        }
        
        return s.top();
    }
};
