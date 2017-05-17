/*
 Author:            cuckoo
 Date:              2017/05/16 22:32:12
 Update:            
 Problem:           Word Ladder
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/word-ladder/#/description

 */

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <climits>          // for INT_MAX

#include <unordered_set>
using std::unordered_set;

#include <queue>
using std::queue;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return ladderLengthSecond(beginWord, endWord, wordList);
    }
    
    // TLE
    bool NextWord(string &word1, string &word2)
    {
        int size_1 = word1.size(), size_2 = word2.size();
        if(size_1 != size_2)
            return false;
         
        int count = 0;   
        for(int i = 0; i < size_1; ++i)
            if(word1[i] != word2[i])
                ++count;
        
        return count == 1 ? true : false;
    }
    void backtracking(string &current_word, string &last_word, vector<string> &word_lists, vector<bool> &used, int count, int &min_count)
    {
        if(current_word == last_word)
        {
            min_count = std::min(min_count, count);
            return;
        }
            
        for(int i = 0; i < word_lists.size(); ++i)
        {
            if(used[i] == false && NextWord(word_lists[i], current_word))
            {
                used[i] = true;
                backtracking(word_lists[i], last_word, word_lists, used, count + 1, min_count);
                used[i] = false;
            }    
        }
        
        return;
    }
    int ladderLengthFirst(string beginWord, string endWord, vector<string>& wordList)
    {
        vector<bool> used(wordList.size(), false);
        int min_count = INT_MAX;
        
        backtracking(beginWord, endWord, wordList, used, 1, min_count);
        
        return min_count == INT_MAX ? 0 : min_count;
    }
    
    // BFS
    void AddNextNode(string &current, unordered_set<string> &word_set, queue<string> &q)
    {
        word_set.erase(current);
        for(int i = 0; i < current.size(); ++i)
        {
            char c = current[i];
            for(int k = 0; k < 26; ++k)
            {
                current[i] = 'a' + k;
                if(word_set.find(current) != word_set.end())
                {
                    q.push(current);
                    word_set.erase(current);
                }
            }
            current[i] = c;
        }
    }
    int ladderLengthSecond(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        
        int result = 1;
        while(q.empty() == false)
        {
            int n = q.size();
            for(int i = 0; i < n; ++i)
            {
                string current = q.front();
                q.pop();
                if(current == endWord)
                    return result;
                AddNextNode(current, word_set, q);
            }
            ++result;
        }
        
        return 0;
    }
};
