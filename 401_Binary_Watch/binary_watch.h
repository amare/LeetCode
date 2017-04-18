/*
 Author:            cuckoo
 Date:              2017/04/17 22:52:50
 Update:            
 Problem:           Binary Watch
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/binary-watch/#/description

 */

#include <cstdio>       // for sprintf

#include <vector>
using std::vector;

#include <string>
using std::string;
using std::to_string;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        return readBinaryWatch1(num);
    }
    
    void BacktrackingHours(vector<int> &hours, int hour, int index, int count, vector<int> &hours_bits, int start)
    {
        if(index == count)
        {
            if(hour <= 11)
                hours.push_back(hour);
            return;
        }
        for(int i = start; i <= 3; ++i)
        {
            hour += hours_bits[i];
            BacktrackingHours(hours, hour, index + 1, count, hours_bits, i + 1);
            hour -= hours_bits[i];
        }
        
    }
    
    void BacktrackingMinutes(vector<int> &minutes, int minute, int index, int count, vector<int> &minutes_bits, int start)
    {
        if(index == count)
        {
            if(minute <= 59)
                minutes.push_back(minute);
            return;
        }
        for(int i = start; i <= 5; ++i)
        {
            minute += minutes_bits[i];
            BacktrackingMinutes(minutes, minute, index + 1, count, minutes_bits, i + 1);
            minute -= minutes_bits[i];
        }
        
    }
    vector<string> readBinaryWatch1(int num)
    {
        if(num < 0 || num > 9) return {};
        vector<int> hours_bits = {1, 2, 4, 8}, minutes_bits = {1, 2, 4, 8, 16, 32};
        vector<int> hours, minutes;
        vector<string> result;
        for(int i = 0; i <= 3 && i <= num; ++i)
        {
            int j = num - i;
            if(j >= 6) continue;
            
            BacktrackingHours(hours, 0, 0, i, hours_bits, 0);
            BacktrackingMinutes(minutes, 0, 0, j, minutes_bits, 0);
            
            char formated_minute[2];
            for(auto hour : hours)
                for(auto minute : minutes)
                {
                    std::sprintf(formated_minute, "%02d", minute);
                    result.push_back(to_string(hour) + ":" + string(formated_minute));
                }
                   
            hours.clear();
            minutes.clear();
        }
        
        return result;
    }
};
