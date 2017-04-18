/*
 Author:            cuckoo
 Date:              2017/04/16 12:58:25
 Update:            
 Problem:           Restore IP Addresses
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/restore-ip-addresses/#/description

 */

#include <cstdlib>      // for aoti()

#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        return restoreIpAddresses1(s);
    }
    
    bool isValid(string &s)
    {
        if(s.size() > 1 && s[0] == '0')     // avoid leading 0
            return false;
        int num = std::atoi(s.c_str());
        return (num >= 0 && num <= 255);
    }
    void backtracking(vector<string> &ips, string &ip, string &s, int start, int index)
    {
        if(index == 4)
        {
            if(start == s.size())
                ips.push_back(ip.substr(0, ip.size() - 1));
            return;
        }
        for(int i = 1; i <= 3 && start + i <= s.size(); ++i)
        {
            string temp = s.substr(start, i);
            if(isValid(temp))
            {
                string old_ip = ip;
                ip += temp;
                ip.push_back('.');
                backtracking(ips, ip, s, start + i, index + 1);
                ip.pop_back();
                ip = std::move(old_ip);
            }
        }
    }
    vector<string> restoreIpAddresses1(string &s)
    {
        int size = s.size();
        if(size < 4 || size > 12)
            return {};
            
        vector<string> ips;
        string ip;
        backtracking(ips, ip, s, 0, 0);
        
        return ips;
    }
};
