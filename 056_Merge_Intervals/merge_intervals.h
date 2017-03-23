/*
 Author:            cuckoo
 Date:              2017/03/23 11:14:46
 Update:
 Problem:           Merge Intervals
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/merge-intervals

 */

#include <vector>
using std::vector;

#include <algorithm>    // for sort(), max()

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        return merge_1(intervals);
    }

    vector<Interval> merge_1(vector<Interval>& intervals)
    {
        if(intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b)
            {return a.start < b.start;});   // if a.start <= b.start, there is a Runtime Error
                                            // because of the strict weak order principle
        vector<Interval> result(1, intervals[0]);
        for(int i = 1; i < intervals.size(); ++i)
        {
           Interval &last = result.back();  // ^attention: &
           if(last.end >= intervals[i].start)
               last.end = std::max(intervals[i].end, last.end);  // which is larger end?
           else
               result.push_back(intervals[i]);
        }

        return result;
    }
};
