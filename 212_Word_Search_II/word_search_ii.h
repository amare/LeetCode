/*
 Author:            cuckoo
 Date:              2017/07/08 12:43:11
 Update:            
 Problem:           Word Search II
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/word-search-ii/#/description

 */

#include <cstring>          // for memset()

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <unordered_set>
using std::unordered_set;



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

class Trie
{
public:    
    Trie()
    {
        root = new TrieNode();
    }
    
    ~Trie()
    {
        clear(root);
    }
    
    void Insert(string &word)
    {
        TrieNode *current = root;
        for(int i = 0; i < word.size(); ++i)
        {
            char c = word[i];
            if(current->next[c - 'a'] == NULL)
                current->next[c - 'a'] = new TrieNode();
            current = current->next[c - 'a'];
        }
        current->is_word = true;
    }
    
    bool Search(string &word)
    {
        TrieNode *result = Find(word);
        return result != NULL && result->is_word;
    }
    
    bool StartWithPrefix(string &prefix)
    {
        return Find(prefix) != NULL;
    }
    
 private:
    TrieNode *root;
    
    TrieNode * Find(string &word)
    {
        TrieNode *current = root;
        for(int i = 0; i < word.size() && current != NULL; ++i)
        {
            current = current->next[word[i] - 'a'];
        }
        return current;
    }
    
    void clear(TrieNode *root)
    {
        for(int i = 0; i < 26; ++i)
            if(root->next[i] != NULL)
                clear(root->next[i]);
        delete root;
    }
};

struct NewTrieNode
{
    NewTrieNode *next[26];
    string word;
    
    NewTrieNode()
    {
        memset(next, 0, sizeof(next));
        word = "";
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        return FindWordsSecond(board, words);
    }
    
    // TLE
    vector<string> FindWordsFirst(vector<vector<char>>& board, vector<string>& words)
    {
        // check input
        
        vector<string> result;
        
        unordered_set<string> hash;
        for(auto &word : words)
            hash.insert(word);
        
        int m = board.size(), n = board[0].size();
        
        for(auto iter = hash.begin(); iter != hash.end(); ++iter)
        {
            vector<vector<bool> > accessed(m, vector<bool>(n, false));
            string word = *iter;
            for(int i = 0; i < m; ++i)
            {
                bool flag = false;
                for(int j = 0; j < n; ++j)
                {
                    if(flag = Backtracking(board, i, j, word, 0, accessed))
                    {
                        result.push_back(word);
                        break;
                    }
                }
                if(flag)
                    break;
            }
        }
        
        return result;
    }
    
    bool Backtracking(vector<vector<char> > &board, int row, int col, string &word, int index, vector<vector<bool> > &accessed)
    {   
        if(index >= word.size())
            return true;
        
        int m = board.size(), n = board[0].size();
        if(row < 0 || row >= m|| col < 0 || col >= n || accessed[row][col] || board[row][col] != word[index])
            return false;
        
        accessed[row][col] = true; 
        if(Backtracking(board, row - 1, col, word, index + 1, accessed) || 
           Backtracking(board, row + 1, col, word, index + 1, accessed) ||
           Backtracking(board, row, col - 1, word, index + 1, accessed) ||
           Backtracking(board, row, col + 1, word, index + 1, accessed))
        {
            return true;
        }            
        accessed[row][col] = false;
        
        return false;
    }
    
    // Trie
    vector<string> FindWordsSecond(vector<vector<char>>& board, vector<string>& words)
    {
        // check input
        
        Trie trie;
        for(auto &word : words)
            trie.Insert(word);
        
        unordered_set<string> result;       // avoid duplicated element
        
        int m = board.size(), n = board[0].size();
        vector<vector<bool> > accessed(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                string s;
                BacktrackingTrie(board, i, j, s, trie, accessed, result);
            }
        }
        
        return vector<string>(result.begin(), result.end());
    }
    
    void BacktrackingTrie(vector<vector<char> > &board, int row, int col, string s, Trie &trie, vector<vector<bool> > &accessed, unordered_set<string> &result)
    {
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || accessed[row][col])
            return;
        
        s.push_back(board[row][col]);
        if(!trie.StartWithPrefix(s))
            return;
        
        if(trie.Search(s))
            result.insert(s);
        
        accessed[row][col] = true;
        BacktrackingTrie(board, row - 1, col, s, trie, accessed, result);
        BacktrackingTrie(board, row + 1, col, s, trie, accessed, result);
        BacktrackingTrie(board, row, col - 1, s, trie, accessed, result);
        BacktrackingTrie(board, row, col + 1, s, trie, accessed, result);
        accessed[row][col] = false;
    }

    // the best one
    vector<string> FindWordsThird(vector<vector<char>>& board, vector<string>& words)
    {
        vector<string> result;
        
        NewTrieNode *root = BulidTrie(words);
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                BacktrackingThird(board, i, j, root, result);
            }
        }
        
        return result;
    }
    
    void BacktrackingThird(vector<vector<char> > &board, int row, int col, NewTrieNode *node, vector<string> &result)
    {
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return;
        
        char c = board[row][col];
        if(c == '#' || node->next[c - 'a'] == NULL)
            return;
        
        node = node->next[c - 'a'];
        if(!(node->word).empty())
        {
            result.push_back(node->word);
            (node->word).clear();               // de-duplicate
        }
        
        board[row][col] = '#';                  // no need to use extra space accessed[m][n]
        BacktrackingThird(board, row - 1, col, node, result);
        BacktrackingThird(board, row + 1, col, node, result);
        BacktrackingThird(board, row, col - 1, node, result);
        BacktrackingThird(board, row, col + 1, node, result);
        board[row][col] = c;
    }
    
    NewTrieNode * BulidTrie(vector<string> &words)
    {
        NewTrieNode *root = new NewTrieNode();
        for(auto &word : words)
        {
            NewTrieNode *current = root;
            for(auto c : word)
            {
                if(current->next[c - 'a'] == NULL)
                    current->next[c - 'a'] = new NewTrieNode();
                current = current->next[c - 'a'];
            }
            current->word = word;
        }
        
        return root;
    }
};
