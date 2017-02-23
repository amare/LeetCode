/*
 Author:            cuckoo
 Date:              2017/02/23 14:31:33
 Update:
 Problem:           Two Sum
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/two-sum
 Note:
 Given an array of integers, return indices of the two numbers such that they add up to a
 specific target.
 You may assume that each input would have exactly one solution, and you may not use the
 same element twice.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2

 Solution:  1. Iterate.     O(n*n)
            2. Sort first.  O(nlgn)
            3. Hash table.  O(n)
 */

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include<algorithm>
using std::sort;
using std::find_if;

#include <functional>
using std::bind2nd;
using std::binary_function;

#include <utility>
using std::pair;
using std::make_pair;

#include <unordered_map>
using std::unordered_map;

vector<int> twoSum_1(vector<int> &nums, int target)
{
    for(auto iter = nums.begin(); iter != nums.end() - 1; ++iter)
    {
        for(auto iter2 = iter + 1; iter2 != nums.end(); ++iter2)
        {
            if(*iter + *iter2 == target)
                return vector<int>({static_cast<int>(iter - nums.begin()),
                    static_cast<int>(iter2 - nums.begin())});
        }
    }
}

struct CompareLess
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first < b.first;
    }
};

struct CompareGreater : public binary_function<pair<int, int>, int, bool>
{
    bool operator()(const pair<int, int> &a, const int &b) const
    {
        return a.first > b;
    }
};

vector<int> twoSum_2(vector<int> &nums, int target)
{
    vector<pair<int, int>> numbers(nums.size());
    for(int i = 0; i < nums.size(); ++i)
    {
        numbers[i] = make_pair(nums[i], i);
    }
    sort(numbers.begin(), numbers.end(), CompareLess());
    /*
        auto new_end = find_if(numbers.begin(), numbers.end(), bind2nd(CompareGreater(), target));

        ^wrong
        @gps: The sum maybe less than the addend and the summand
              {-3, 3}, target = 0
     */

    auto head = numbers.begin();
    auto tail = numbers.end() - 1;
    while( head != tail)
    {
        int sum = (*head).first + (*tail).first;
        if(sum == target)
            return vector<int>({(*head).second, (*tail).second});
        else if(sum > target)
            --tail;
        else
            ++head;
    }
}

vector<int> twoSum_3(vector<int> &nums, int target)
{
    unordered_map<int, int> hash;
    for(int i = 0; i < nums.size(); ++i)
    {
        int other = target - nums[i];
        if(hash.find(other) != hash.end())
            return vector<int>({hash[other], i});
        else
            hash.insert({nums[i], i});
    }
}

int main()
{
    vector<int> Testcase = {-3, 4, 3, 90};
    int target = 0;
    vector<int> result;
    result = twoSum_3(Testcase, target);
    for(auto i : result)
        cout << i << " ";
    cout << endl;

    return 0;
}
