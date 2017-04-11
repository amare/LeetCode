
    Author:            cuckoo
    Date:              2017/04/11 20:37:17
    Update:            
    Problem:           Integer Break
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/integer-break/#/description

#### Discuss
 - [Math](https://discuss.leetcode.com/topic/43055/why-factor-2-or-3-the-math-behind-this-problem)
 >If an optimal product contains a factor f >= 4, then you can replace it with factors 2 and f-2 without losing optimality, as 2*(f-2) = 2f-4 >= f. So you never need a factor greater than or equal to 4, meaning you only need factors 1, 2 and 3 (and 1 is of course wasteful and you'd only use it for n=2 and n=3, where it's needed). And 3*3 is simply better than 2*2*2, so you'd never use 2 more than twice.

 - [DP](https://discuss.leetcode.com/topic/47388/c-0ms-dp-solution-with-explanation-in-chinese)
