/*
 Author:            cuckoo
 Date:              2017/05/09 20:27:39
 Update:            
 Problem:           Intersection of Two Arrays II
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/intersection-of-two-arrays-ii/#/description

 */

#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_multiset;

#include <algorithm>            // for sort()

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        return intersectSecond(nums1, nums2);
    }
    
    vector<int> intersectFirst(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_multiset<int> hash(nums1.begin(), nums1.end());
        
        vector<int> result;
        int n2 = nums2.size();
        for(int i = 0; i < n2; ++i)
        {
            auto iter = hash.find(nums2[i]);
            if(iter != hash.end())
            {
                result.push_back(nums2[i]);
                hash.erase(iter);
            }
        }
        
        return result;
    }
    
    // sort + binary search
    int UpperBound(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while(low < high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }
        
        return low;
    }
    vector<int> intersectSecond(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> result;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        while(i < n1)
        {
            int index = UpperBound(nums2, nums1[i]);
            int count2 = 0;
            while(index < n2 && nums2[index] == nums1[i])
            {
                ++count2;
                ++index;
            }
            
            int count1 = 0;
            while(j < n1 && nums1[j] == nums1[i])
            {
                ++count1;
                ++j;
            }
            
            result.insert(result.end(), std::min(count1, count2), nums1[i]);
            i = j;
        }
        
        return result;
    }
};
