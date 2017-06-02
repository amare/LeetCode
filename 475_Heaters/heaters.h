/*
 Author:            cuckoo
 Date:              2017/06/02 22:03:52
 Update:            
 Problem:           Heaters
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/heaters/#/description

 */

#include <vector>
using std::vector;

#include <algorithm>        // for lower_bound(), max(), min()

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        return FindRadiusFirst(houses, heaters);
    }
   
    int FindRadiusFirst(vector<int>& houses, vector<int>& heaters)
    {
        // check if the input is valid
        if(heaters.empty())
            return INT_MAX;
        
        int result = 0;
        // sort
        std::sort(heaters.begin(), heaters.end());
        for(auto house : houses)
        {
            auto index = std::lower_bound(heaters.begin(), heaters.end(), house);
            
            int left = index == heaters.begin() ? INT_MAX : house - *(index - 1);
            int right = index == heaters.end() ? INT_MAX : *(index) - house;
                
            result = std::max(result, std::min(left, right));
        }
        
        return result;
    }
};
