/*
 Author:            cuckoo
 Date:              2017/03/18 12:58:47
 Update:
 Problem:           Trapping Rain Water
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/trapping-rain-water

 */

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>

class Solution {
public:
    int trap(vector<int>& height) {
        return trap_1(height);
    }

    int trap_1(vector<int>& height)
    {
        int water = 0, size = height.size();
        if(size < 3) return 0;
        int left = 0, right = 0;

        for(int i = 0; i < size - 2;)
        {
            // 去掉重复元素，确定left
            while(i + 1 < size && height[i + 1] == height[i])
            {
                ++i;
                ++left;
            }
            // 找到最低点并确认能否构成 高-低-高 形状
            while(i + 1 < size && height[i + 1] < height[i]) ++i;
            if(i + 1 == size) return water;
            int bottom = i;
            if(height[bottom] == height[left])
            {
                ++i;
                ++left;
                continue;
            }

            // 寻找right
            int max_height = 0, max_index = 0;
            while(i + 1 < size && height[i + 1] < height[left])
            {
                if(height[i + 1] >= max_height)
                {
                    max_height = height[i + 1];
                    max_index = i + 1;
                }
                ++i;
            }

            right = i + 1;
            if(right == size)
            {
                // 没有比height[left]还要高的,选择left右侧最高的
                right = max_index;
                std::cout << "right == size" << std::endl;

                for(int j = left + 1; j < right; ++j)
                {
                    if(height[right] - height[j] > 0)
                        water += height[right] - height[j];
                }
                std::cout << "left: " << left << "\tright: " << right << "\twater: " << water << std::endl;

                left = right;
                i = right;
            }
            else
            {
                // 找到跟height[left]一样高，或更高的。
                for(int j = left + 1; j < right; ++j)
                {
                    if(height[left] - height[j] > 0)
                        water += height[left] - height[j];
                }
                std::cout << "left: " << left << "\tright: " << right << "\twater: " << water << std::endl;

                left = right;
                i = right;
            }
        }

        return water;
    }

    // two pointer
    int trap_2(vector<int>& height)
    {
        int water = 0;
        int first = 0, last = height.size() - 1;
        while(first < last)
        {
            int temp = 0;
            int min_height = std::min(height[first], height[last]);
            for(int i = first + 1; i < last; ++i)
            {
                temp = min_height - height[i];
                if(temp > 0)
                {
                    water += temp;
                    height[i] += temp;  // 填上相应高度，避免相同区域的重复累加
                }
            }
            height[first] <= height[last] ? ++first : --last;
        }

        return water;
    }

    int trap_3(vector<int>& height)
    {
        int water = 0;
        int left = 0, right = height.size() - 1;
        int max_left = 0, max_right = 0;
        while(left < right)
        {
            if(height[left] <= height[right])
            {
                if(height[left] >= max_left)
                    max_left = height[left];
                else
                    water += max_left - height[left];
                ++left;
            }
            else
            {
                if(height[right] >= max_right)
                    max_right = height[right];
                else
                    water += max_right - height[right];
                --right;
            }
        }

        return water;
    }

    // water level
    int trap_4(vector<int>& height)
    {
        int water = 0, level = 0;   // level used to record current water level
        int left = 0, right = height.size() - 1;
        while(left < right)
        {
            int lower = height[left] < height[right] ? height[left++] : height[right--];
            if(lower < level)
                water += level - lower;
            else
                level = lower;
        }

        return water;
    }
};
