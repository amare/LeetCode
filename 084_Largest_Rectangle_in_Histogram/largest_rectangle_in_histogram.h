/*
 Author:            cuckoo
 Date:              2017/03/29 21:41:01
 Update:            
 Problem:           Largest Rectangle in Histogram
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/largest-rectangle-in-histogram/#/description

 */

#include <stack>
using std::stack;

#include <vector>
using std::vector;

#include <algorithm>    // for max()

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return largestRectangleArea_1(heights);
    }
    
    int largestRectangleArea_1(vector<int>& heights)
    {
        heights.push_back(0);
        
        int result = 0;
        int size = heights.size();
        stack<int> s;
        for(int right_index = 0; right_index < size; ++right_index)
        {
            while(!s.empty() && heights[right_index] < heights[s.top()])
            {
                int top = s.top();
                s.pop();
                int left_index = s.empty() ? -1 : s.top();
                result = std::max(result, heights[top] * (right_index - left_index - 1));
            }
            s.push(right_index);
        }
        
        return result;
    }
};
