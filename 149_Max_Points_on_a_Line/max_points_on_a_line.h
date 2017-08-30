/*
 Author:            cuckoo
 Date:              2017/08/30 20:27:12
 Update:            
 Problem:           Max Points on a Line
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/max-points-on-a-line/description/

 */

#include <map>
using std::map;

#include <vector>
using std::vector;

#include <algorithm>            // for std::max()
#include <utility>              // for std::make_pair()

// Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        return MaxPointsFirst(points);
    }
    
    int MaxPointsFirst(vector<Point> &points)
    {
        int result = 0;
        for(int i = 0; i < points.size(); ++i)
        {
            int same_point = 1, vertical = 0;
            map<std::pair<int, int>, int> slopes_counts;
            
            for(int j = i + 1; j < points.size(); ++j)
            {
                if(points[i].x == points[j].x && points[i].y == points[j].y)        // same point
                    ++same_point;
                else if(points[i].x == points[j].x)                                 // slope is a infinite number
                    ++vertical;
                else
                {
                    int a = points[j].x - points[i].x, b = points[j].y - points[i].y;
                    int gcd = Gcd(a, b);
                    ++slopes_counts[std::make_pair(a / gcd, b / gcd)];
                }
            }
            
            int max_count = 0;
            for(auto iter = slopes_counts.begin(); iter != slopes_counts.end(); ++iter)
                max_count = std::max(max_count, iter->second);
            
            result = std::max(result, std::max(vertical, max_count) + same_point);
        }
        
        return result;
    }
    
    // 求最大公约数 - 辗转相除法
    int Gcd(int a, int b)
    {
        if(b == 0)
            return a;
        return Gcd(b, a % b);
    }
};
