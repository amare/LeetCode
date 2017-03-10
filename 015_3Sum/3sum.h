/*
 Author:            cuckoo
 Date:              2017/03/10 22:38:34
 Update:
 Problem:           3Sum
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/3sum

 */

#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;

#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        return threeSum_2(nums);
    }

    vector<vector<int>> threeSum_1(vector<int>& nums) {
        vector<vector<int>> ans;
        // divide into two parts, the elements in first part are less or equal than zero, second larger than zero
        vector<int> first, second;
        unordered_set<int> hash_first, hash_second;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] <= 0)
            {
                 first.push_back(nums[i]);
                 hash_first.insert(nums[i]);
            }
            else
            {
                 second.push_back(nums[i]);
                 hash_second.insert(nums[i]);
            }
        }

        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        // scan first part, and find another number in second part
        int target = 0;
        for(int i = 0; i < first.size(); ++i)
        {
            for(int j = i + 1; j < first.size(); ++j)
            {
                target = -(first[i] + first[j]);
                if(hash_second.find(target) != hash_second.end())
                {
                    vector<int> temp = {first[i], first[j], target};
                    ans.push_back(temp);
                }
                while(j + 1 < first.size() && first[j] == first[j+1]) ++j;
            }
            while(i + 1 < first.size() && first[i] == first[i+1]) ++i;
        }
        // scan second part, and find another number in first part
        int target2 = 0;
        for(int i = 0; i < second.size(); ++i)
        {
            for(int j = i + 1; j < second.size(); ++j)
            {
                target2 = -(second[i] + second[j]);
                if(hash_first.find(target2) != hash_first.end())
                {
                    vector<int> temp = {second[i], second[j], target2};
                    ans.push_back(temp);
                }
                while(j + 1 < second.size() && second[j] == second[j+1]) ++j;
            }
            while(i + 1 < second.size() && second[i] == second[i+1]) ++i;
        }

        // handle with [0,0,...,0]
        int k = 0;
        for(auto i : first)
        {
            if(i == 0)
                ++k;
            if(k >= 3)
            {
                vector<int> temp = {0, 0, 0};
                ans.push_back(temp);
                break;
            }
        }

        return ans;
    }

    vector<vector<int>> threeSum_2(vector<int>& nums)
    {
        vector<vector<int>> ans;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size; ++i)
        {
            int target = -nums[i];
            int head = i + 1;
            int tail = size - 1;

            int sum = 0;
            while(head < tail)
            {
                sum = nums[head] + nums[tail];
                if(sum < target)
                    ++head;
                else if(sum > target)
                    --tail;
                else
                {
                    vector<int> triplet = {nums[i], nums[head], nums[tail]};
                    ans.push_back(triplet);
                    // Processing duplicates of Number 2. Rolling the head pointer to the next different number forwards
                    while(head < tail && nums[head] == triplet[1]) ++head;
                    // Processing duplicates of Number 3. Rolling the tail pointer to the next differet number backwards
                    while(head < tail && nums[tail] == triplet[2]) --tail;
                }
            }
            // Processing duplicates of Number 1
            while(i + 1 < size && nums[i+1] == nums[i]) ++i;
        }

        return ans;
    }
};
