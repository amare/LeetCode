/*
 Author:            cuckoo
 Date:              2017/03/16 09:32:56
 Update:
 Problem:           Search in Rotated Sorted Array
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/search-in-rotated-sorted-array

 */

#include <vector>
using std::vector;

#include <algorithm>    // for lower_bound()

#include <limits>
using std::numeric_limits;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search_3(nums, target);
    }

    int binary_search(vector<int> &nums, int low, int high, int target)
    {
        while(low <= high)
        {
            int mid = (high + low) / 2;
            if(target == nums[mid]) return mid;
            if(target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }

    int search_1(vector<int>& nums, int target)
    {
        int index = -1;
        int size = nums.size();
        if(0 == size) return -1;
        if(size >= 1 && target == nums[0]) return 0;

        int i = 1;
        while(i < size && nums[i-1] < nums[i])
        {
            if(target == nums[i]) return i;
            ++i;
        }

        // now i is the pivot, then binary search
        index = binary_search(nums, i, size - 1, target);


        return index;
    }

    int search_2(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] == target) return mid;

            if(nums[low] <= nums[mid])
            {
                if(target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if(target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }

    int search_3(vector<int>& nums, int target)
    {
        auto skip_left = [&](int x){ return x < nums[0] ? x : numeric_limits<int>::min(); };
        auto skip_right = [&](int x){ return x < nums[0] ? numeric_limits<int>::max() : x; };
        auto adjust = [&](int x){ return target < nums[0] ? skip_left(x) : skip_right(x); };
        auto result = lower_bound(nums.begin(), nums.end(), target, [&](int x, int y){ return adjust(x) < adjust(y); });

        return result != nums.end() && *result == target ? result - nums.begin() : -1;
    }
};
