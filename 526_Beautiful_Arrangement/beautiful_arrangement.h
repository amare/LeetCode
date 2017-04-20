/*
 Author:            cuckoo
 Date:              2017/04/19 21:25:20
 Update:            
 Problem:           Beautiful Arrangement
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/beautiful-arrangement/#/description

 */

#include <cstring>      // for memset

#include <unordered_set>
using std::unordered_set;

class Solution {
public:
    int countArrangement(int N) {
        return countArrangement1(N);
    }
    
    void backtracking(int index, int n, int &result, unordered_set<int> &hash)
    {
        if(index >= n + 1)
        {
            ++result;
            return;
        }
        for(int i = 1; i <= n; ++i)
        {
            if(hash.find(i) == hash.end() && (index % i == 0 || i % index == 0))
            {
                hash.insert(i);
                backtracking(index + 1, n, result, hash);
                hash.erase(i);
            }
        }
    }
    int countArrangement1(int N)
    {
        int result = 0;
        unordered_set<int> hash;
        backtracking(1, N, result, hash);
        
        return result;
    }

    void backtracking2(int index, int n, int &result, bool is_visited[])
    {
        if(index == 0)
        {
            ++result;
            return;
        }
        for(int i = 1; i <= n; ++i)
        {
            if(!is_visited[i] && (index % i == 0 || i % index == 0))
            {
                is_visited[i] = true;
                backtracking2(index - 1, n, result, is_visited);
                is_visited[i] = false;
            }
        }
    }
    int countArrangement2(int N)
    {
        int result = 0;
        bool is_visited[N + 1];
        std::memset(is_visited, 0, sizeof(is_visited));
        
        backtracking2(N, N, result, is_visited);
        
        return result;
    }
};
