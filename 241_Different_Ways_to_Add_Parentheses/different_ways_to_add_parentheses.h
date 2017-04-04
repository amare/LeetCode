/*
 Author:            cuckoo
 Date:              2017/04/04 20:02:19
 Update:            
 Problem:           Different Ways to Add Parentheses
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/different-ways-to-add-parentheses/#/description

 */

#include <cstdlib>      // for atoi()

#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        return diffWaysToCompute_1(input);
    }
    
    vector<int> diffWaysToCompute_1(string input)
    {
        int size = input.size();
        if(0 == size) return {};
        /* handle with wrong input */
        vector<int> result;
        for(int i = 0; i < size; ++i)
        {
            char current = input[i];
            if(current == '+' || current == '-' || current == '*')
            {
                vector<int> left_operands = diffWaysToCompute_1(input.substr(0, i));
                vector<int> right_operands = diffWaysToCompute_1(input.substr(i+1));
                for(auto left : left_operands)
                    for(auto right : right_operands)
                        switch(current)
                        {
                            case '+':
                                result.push_back(left + right); break;
                            case '-':
                                result.push_back(left - right); break;
                            case '*':
                                result.push_back(left * right); break;
                            default:
                                /* handle with exception*/
                                break;
                        }
            }
        }
        if(result.empty())
            result.push_back(std::atoi(input.c_str()));
        
        return result;
    }
};
