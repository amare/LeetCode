
/*
 Author:            cuckoo
 Date:              2017/05/09 19:35:03
 Update:            
 Problem:           Intersection of Two Arrays
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/intersection-of-two-arrays/#/description

 */

#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;

#include <algorithm>        // for sort()

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        return intersectionFirst(nums1, nums2);
    }
    
    int FindTarget(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return -1;
    }
    vector<int> intersectionFirst(vector<int>& nums1, vector<int>& nums2)
    {
        int n2 = nums2.size(), n1 = nums1.size();
        if(0 == n1 || 0 == n2) return {};
        
        vector<int> result;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int last_index = 0, i = 1;
        do
        {
            if(FindTarget(nums1, nums2[last_index]) != -1)
            {
                result.push_back(nums2[last_index]);
            }
            while(i < n2 && nums2[i] == nums2[last_index]) ++i;
            last_index = i;
        }while(i < n2);

        return result;
    }

    // using two set
    vector<int> intersectionSecond(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> hash, intersection_set;
        
        int n1 = nums1.size(), n2 = nums2.size();
        for(int i = 0; i < n1; ++i)
            hash.insert(nums1[i]);
            
        for(int i = 0; i < n2; ++i)
            if(hash.find(nums2[i]) != hash.end())
                intersection_set.insert(nums2[i]);
                
        vector<int> result;
        for(auto num : intersection_set)
            result.push_back(num);
            
        return result;
    }
};
