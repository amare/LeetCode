#include "trapping_rain_water.h"

int main()
{
    Solution s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    // {1,1,0,2,1,7,5,3,6,2,9,8,2,1,3,2,1,2};
    s.trap(height);

    return 0;
}
