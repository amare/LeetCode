/*
 Author:            cuckoo
 Date:              2017/07/17 15:44:20
 Update:            
 Problem:           Top K Frequent Elements
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/top-k-frequent-elements/#/description

 */

#include <vector>
using std::vector;

#include <queue>
using std::priority_queue;

#include <unordered_map>
using std::unordered_map;

#include <map>
using std::multimap;

#include <utility>
using std::pair;

#include <functional>           // std::greater

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        return TopKFrequentThird(nums, k);
    }
    
    vector<int> TopKFrequentFirst(vector<int>& nums, int k)
    {
        unordered_map<int, int> counts;
        for(auto num : nums)
            ++counts[num];
        
        multimap<int, int, std::greater<int>> frequency;
        for(auto &p : counts)
            frequency.insert(std::make_pair(p.second, p.first));

        vector<int> result;
        int i = 0;
        for(auto &p : frequency)
        {
            result.push_back(p.second);
            if(++i >= k)
                break;
        }
            
        /*
        vector<int> final_result;
        std::copy(result.begin(), result.begin() + k, std::back_inserter(final_result));
        */
        
        return result;
    }
    
    // Using Min Heap - O(nlogk)
    vector<int> TopKFrequentSecond(vector<int>& nums, int k)
    {
        unordered_map<int, int> counts;
        for(auto num : nums)
            ++counts[num];
        
        priority_queue<pair<int, int>, vector<pair<int, int> >, std::greater<pair<int, int> > > min_heap;
        for(auto &p : counts)
        {
            min_heap.push(std::make_pair(p.second, p.first));
            if(min_heap.size() > k)
                min_heap.pop();
        }
        
        vector<int> result;
        while(!min_heap.empty())
        {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        return result;
    }    
        
    // Bucket Sort - O(n)
    vector<int> TopKFrequentThird(vector<int>& nums, int k)
    {
        unordered_map<int, int> counts;
        for(auto num : nums)
            ++counts[num];
        
        vector<vector<int> > buckets(nums.size() + 1);
        for(auto &p : counts)
            buckets[p.second].push_back(p.first);
        
        vector<int> result;
        for(int i = buckets.size() - 1; i >= 0; --i)
        {
            for(auto num : buckets[i])
            {
                result.push_back(num);
                if(result.size() == k)
                    return result;
            }
        }
        
        return result;
    }
};
