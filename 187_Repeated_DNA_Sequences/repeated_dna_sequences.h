/*
 Author:            cuckoo
 Date:              2017/06/10 15:25:51
 Update:            
 Problem:           Repeated DNA Sequences
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/repeated-dna-sequences/#/description

 */

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <unordered_set>
using std::unordered_set;

#include <unordered_map>
using std::unordered_map;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        return findRepeatedDnaSequencesSecondOptimized(s);
    }
    
    vector<string> findRepeatedDnaSequencesFirst(string &s)
    {
        vector<string> result;
        
        unordered_map<string, int> hash;
        int n = s.size();
        // ^attention: (s.size() - 9)的类型为无符号类型size_type
        for(int i = 0; i < n - 9; ++i)
        {
            // 关于map的下标运算符[]:
            // 如果关键字不在map中, 会为它创建一个元素并插入到map中, 关联值进行值初始化
            ++hash[s.substr(i, 10)];    
        }
        
        for(auto &p : hash)
            if(p.second > 1)
                result.push_back(p.first);
        
        return result;
    }
    
    // not store the 10-letter substrings themselves any more, because it will consume too much memory
    vector<string> findRepeatedDnaSequencesSecond(string &s)
    {
        vector<string> result;
        // unordered_map<int, int> hash;
        
        unordered_set<int> words, double_words;
        // 重新编码, 每个字母对应2bit
        int map[26] = { -1 };   // 值初始化
        map['A' - 'A'] = 0;
        map['C' - 'A'] = 1;
        map['G' - 'A'] = 2;
        map['T' - 'A'] = 3;
        
        for(int i = 0; i < static_cast<int>(s.size()) - 9; ++i)
        {
            int val = 0;
            for(int j = i; j < i + 10; ++j)
            {
                val <<= 2;
                val |= map[s[j] - 'A'];
            }
            
            /* // using unordered_map
            if(++hash[val] == 2)
                result.push_back(s.substr(i, 10));
            */
            // using unordered_set
            if(!words.insert(val).second && double_words.insert(val).second)    // 
                result.push_back(s.substr(i, 10));
        }
        
        return result;
    }
    
    // Maintain a size 10 window
    vector<string> findRepeatedDnaSequencesSecondOptimized(string &s)
    {
        vector<string> result;
        unordered_map<int, int> hash;
        
        // unordered_set<int> words, double_words;
        // 重新编码, 每个字母对应2bit
        int map[26] = { -1 };   // 值初始化
        map['A' - 'A'] = 0;
        map['C' - 'A'] = 1;
        map['G' - 'A'] = 2;
        map['T' - 'A'] = 3;
        
        int val = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            val <<= 2;
            val |= map[s[i] - 'A'];
            val &= 0xFFFFF;
            if(i < 9)
                continue;
            // using unordered_map will be faster
            if(++hash[val] == 2)
                result.push_back(s.substr(i - 9, 10));
            /*
            // using unordered_set
            if(!words.insert(val).second && double_words.insert(val).second)    // 
                result.push_back(s.substr(i - 9, 10));
            */
        }
        
        return result;
    }
};
