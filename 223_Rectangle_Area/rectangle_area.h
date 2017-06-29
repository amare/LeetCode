/*
 Author:            cuckoo
 Date:              2017/06/28 16:41:52
 Update:            
 Problem:           Rectangle Area
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/rectangle-area/#/description

 */

#include <algorithm>
using std::max;
using std::min;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return computeAreaFirst(A, B, C, D, E, F, G, H);
    }
    
    int computeAreaFirst(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        return ComputeAreaAux(A, B, C, D) + ComputeAreaAux(E, F, G, H) - ComputeAreaAux(max(A, E), max(B, F), min(C, G), min(D, H));
    }
    
    int ComputeAreaAux(int left, int bottom, int right, int top)
    {
        if(left >= right || bottom >= top)
            return 0;
        return (right - left) * (top - bottom);
    }
};
