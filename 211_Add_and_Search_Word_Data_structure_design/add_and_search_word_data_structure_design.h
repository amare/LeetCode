/*
 Author:            cuckoo
 Date:              2017/04/18 20:42:57
 Update:            
 Problem:           Add and Search Word - Data structure design
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/add-and-search-word-data-structure-design/#/description

 */

#include <cstddef>      // for NULL
#include <cctype>       // for islower()
#include <cstring>      // for memset()

#include <string>
using std::string;

struct TrieNode
{
    TrieNode *next[26];
    bool is_word;
    
    TrieNode(bool b = false)
    {
        std::memset(next, 0, sizeof(next));
        is_word = b;
    }
};
class WordDictionary
{
public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root_ = new TrieNode();
    }
    
    ~WordDictionary()
    {
        clear(root_);
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        TrieNode *current = root_;
        for(auto ch : word)
        {
            if(!std::islower(ch)) return;
            if(current->next[ch - 'a'] == NULL)
                current->next[ch - 'a'] = new TrieNode();
            current = current->next[ch - 'a'];
        }
        current->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return !word.empty() && backtracking(word, 0, root_);
    }
    
private:
    TrieNode *root_;
    void clear(TrieNode *root)
    {
        for(int i = 0; i < 26; ++i)
            if(root->next[i] != NULL)
                clear(root->next[i]);
        delete root;
    }
    bool backtracking(const string &word, int start, TrieNode *last)
    {
        if(start == word.size())
            return last->is_word == true ? true : false;
        
        if(word[start] == '.')
        {
            for(int i = 0; i < 26; ++i)
                if(last->next[i] != NULL && backtracking(word, start + 1, last->next[i]))
                    return true;
            return false;
        }
        if(std::islower(word[start]) && last->next[word[start] - 'a'] != NULL)
             return backtracking(word, start + 1, last->next[word[start] - 'a']);
       
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
