/*
 Author:            cuckoo
 Date:              2017/03/20 15:38:29
 Update:
 Problem:           Permutations
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/Permutations

 */

#include <vector>
using std::vector;

#include <algorithm>    // for find(), swap(), next_permutation()
#include <utility>      // for move()

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return permute_5(nums);
    }

    void search(vector<int> &nums, vector<vector<int>> &result, int row, vector<int> &single)
    {
        if(row >= nums.size())
            result.push_back(single);
        else
        {
            for(int col = 0; col < nums.size(); ++col)
            {
                if(find(single.begin(), single.end(), nums[col]) == single.end()) // can not find it
                {
                    single.push_back(nums[col]);
                    search(nums, result, row + 1, single);
                    single.pop_back();
                }
            }
        }
    }

    vector<vector<int>> permute_1(vector<int>& nums)
    {
        vector<vector<int>> result(0);
        vector<int> single(0);
        search(nums, result, 0, single);

        return result;
    }

    // ===========
    // standard backtracking solution
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
    void permutation(vector<int> &nums, int begin, vector<vector<int>> &result)
    {
        if(begin >= nums.size())
        {
            // one permutation instance
            result.push_back(nums);
            return;
        }
        // every number chosen to be the begin one
        for(int i = begin; i < nums.size(); ++i)
        {
            std::swap(nums[begin], nums[i]);
            permutation(nums, begin + 1, result);
            std::swap(nums[begin], nums[i]);     // reset
        }
    }
    vector<vector<int>> permute_2(vector<int>& nums)
    {
        vector<vector<int>> result(0);
        permutation(nums, 0, result);

        return result;
    }

    // using next_permutation to iterate all the permutations
    vector<vector<int>> permute_3(vector<int>& nums)
    {
        vector<vector<int>> result(0);
        sort(nums.begin(), nums.end());
        do
        {
            result.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));

        return result;
    }

    // recursion dfs
    void dfs(vector<int> &nums, vector<vector<int>> &result)
    {
        if(nums.size() == 1)
        {
            result.push_back(nums);
            return;
        }
        // obtain the permutation result of nums which removes the first element
        vector<int> nums1(nums.begin() + 1, nums.end());
        dfs(nums1, result);

        // and insert the first element nums[0] into different position from the first to the last
        vector<vector<int>> result_tmp(0);
        for(int i = 0; i < result.size(); ++i)
        {
            vector<int> tmp = result[i];
            for(int j = 0; j <= result[i].size(); ++j)
            {
                tmp.insert(tmp.begin() + j, nums[0]);
                result_tmp.push_back(tmp);
                tmp = result[i];
            }
        }

        result = result_tmp;
    }

    vector<vector<int>> permute_4(vector<int>& nums)
    {
        vector<vector<int>> result;
        dfs(nums, result);

        return result;
    }

    // iterative version of the above solution
    vector<vector<int>> permute_5(vector<int>& nums)
    {
        vector<vector<int>> result(0);
        if(nums.empty()) return result;
        // seed
        result.push_back(vector<int>(1, nums[0]));

        for(int i = 1; i < nums.size(); ++i)
        {
            vector<vector<int>> result_tmp(0);
            for(auto &v : result)
            {
                for(int j = 0; j <= v.size(); ++j)
                {
                    vector<int> tmp = v;
                    tmp.insert(tmp.begin() + j, nums[i]);
                    result_tmp.push_back(std::move(tmp));
                }
            }
            result = result_tmp;
        }

        return result;
    }

};
