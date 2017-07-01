/*
 Author:            cuckoo
 Date:              2017/06/30 10:30:37
 Update:            
 Problem:           Sliding Window Median
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/sliding-window-median/#/description

 */

#include <vector>
using std::vector;

#include <set>
using std::multiset;

#include <iterator>     // for next(), prev()

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        return medianSlidingWindowFirst(nums, k);
    }
    
    vector<double> medianSlidingWindowFirst(vector<int>& nums, int k)
    {
        if(k > nums.size())
            return {};
        
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = std::next(window.begin(), k / 2);
        
        vector<double> medians;
        medians.push_back((static_cast<double>(*mid) + *std::prev(mid, 1 - k % 2)) / 2);
        
        for(int i = k; i < nums.size(); ++i)
        {
            //insert element
            window.insert(nums[i]);
            if(nums[i] < *mid)
                mid--;
            
            // erase element
            // 关联容器的迭代器只会在删除其指向元素时才会失效
            if(nums[i-k] <= *mid)
                mid++;
            window.erase(window.lower_bound(nums[i-k]));
            
            medians.push_back((static_cast<double>(*mid) + *std::prev(mid, 1 - k % 2)) / 2);
        }
        
        return medians;
    }
};
