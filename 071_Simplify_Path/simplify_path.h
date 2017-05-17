/*
 Author:            cuckoo
 Date:              2017/05/11 11:06:51
 Update:            
 Problem:           Simplify Path
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/simplify-path/#/description

 */

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <sstream>
using std::istringstream;

class Solution {
public:
    string simplifyPath(string path) {
        return simplifyPathSecond(path);
    }
    
    /* wrong answer
    string simplifyPathFirst(string &path)
    {
        stack<char> s;
        
        int n = path.size();
        if(0 == n)
            return string();
        for(int i = 0; i < n; ++i)
        {
            if(path[i] == '.')
            {
                if(i + 1 < n && path[i + 1] == '.')
                {
                    if(s.empty() == false)
                        s.pop();        // pop '/'
                    while(s.empty() == false && s.top() != '/')
                        s.pop();
                }
                else
                {
                    // do nothing
                }
            }
            else if(path[i] == '/')
            {
                if(s.empty() == true || s.top() != '/')
                {
                    s.push(path[i]);  
                }
                else
                {
                   // do nothing 
                }
            }
            else
                s.push(path[i]);
        }
        
        if(s.empty() == false && s.top() == '/')
            s.pop();
        string result;
        while(s.empty() == false)
        {
            result += s.top();
            s.pop();
        }
        
        std::reverse(result.begin(), result.end());
    
        return result == string() ? string("/") : result;
    }
    */
    
    string simplifyPathSecond(string &path)
    {
        if(path.empty())
            return string();
        
        string result, filename;
        
        vector<string> s;
        istringstream iss(path);
        while(getline(iss, filename, '/'))
        {
            if(filename == "" || filename == ".")
                continue;
            if(filename == "..")
            {
                if(s.empty() == false)
                    s.pop_back();
                continue;
            }
            s.push_back(filename);
        }
        
        for(auto &word : s)
            result += "/" + word;
        
        return result.empty() ? "/" : result;
    }
};
