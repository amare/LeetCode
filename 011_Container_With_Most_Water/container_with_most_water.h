/*
 Author:            cuckoo
 Date:              2017/03/09 21:27:24
 Update:
 Problem:           Container With Most Water
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/container-with-most-water

 */

#include <vector>
using std::vector;

#include <algorithm>
using std::max;
using std::min;

class Solution {
public:
    int maxArea(vector<int>& height) {
        return maxArea_3(height);
    }

    // Time Limit Exceeded
    int maxArea_1(vector<int> &height)
    {
        int size = height.size();
        int max_area = 0;
        int temp = 0;
        for(int i = 0; i < size; ++i)
        {
            for(int j = i + 1; j < size; ++j)
            {
                temp = (j - i) * min(height.at(i), height.at(j));
                if(max_area < temp)
                    max_area = temp;
            }
        }
        return max_area;
    }

    int maxArea_2(vector<int> &height)
    {
        int water = 0, temp_h = 0;
        int first = 0, last = height.size() - 1;
        while(first < last)
        {
            temp_h = min(height[first], height[last]);
            water = max(water, temp_h * (last - first));
            if(height[first] < height[last])
                ++first;
            else
                --last;
        }

        return water;
    }

    int maxArea_3(vector<int> &height)
    {
        int water = 0, temp_h = 0;
        int first = 0, last = height.size() - 1;
        while(first < last)
        {
            temp_h = min(height[first], height[last]);
            water = max(water, temp_h * (last - first));
            while(first < last && height[first] <= temp_h) ++first;
            while(first < last && height[last] <= temp_h) --last;
        }

        return water;
    }
};
