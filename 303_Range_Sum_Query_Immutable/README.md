
    Author:            cuckoo
    Date:              2017/04/09 13:03:32
    Update:            
    Problem:           Range Sum Query - Immutable
    Difficulty:        Easy
    Source:            https://leetcode.com/problems/range-sum-query-immutable/#/description

__Solution Step__:
 - [clever solution](https://discuss.leetcode.com/topic/36450/recommend-for-beginners-clean-c-implementation-with-detailed-explanation)


======
 - [other](https://discuss.leetcode.com/topic/29206/5-lines-c-4-lines-python)
```
    class NumArray {
    public:
        NumArray(vector<int> &nums) {
            accu.push_back(0);
            for (int num : nums)
                accu.push_back(accu.back() + num);
        }
    
        int sumRange(int i, int j) {
            return accu[j + 1] - accu[i];
        }
    private:
        vector<int> accu;
};
```
