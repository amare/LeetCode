/*
 Author:            cuckoo
 Date:              2017/04/18 11:07:21
 Update:            
 Problem:           Implement Trie (Prefix Tree)
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/implement-trie-prefix-tree/#/description

 */

#include <cstddef>          // for NULL

#include <cstring>          // for memset

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

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int size = word.size();
        TrieNode *current = root;
        for(int i = 0; i < size; ++i)
        {
            if(current->next[word[i] - 'a'] == NULL)
                current->next[word[i] - 'a'] = new TrieNode();
            current = current->next[word[i] - 'a'];
        }
        current->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *result = find(word);
        return result != NULL && result->is_word == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != NULL;
    }

private:
    TrieNode *root;
    TrieNode * find(const string &word)
    {
        TrieNode *current = root;
        int size = word.size();
        for(int i = 0; i < size && current != NULL; ++i)
        {
            current = current->next[word[i] - 'a'];
        }
        
        return current;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
