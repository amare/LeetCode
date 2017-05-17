
    Author:            cuckoo
    Date:              2017/05/16 22:32:12
    Update:            
    Problem:           Word Ladder
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/word-ladder/#/description

#### Solution Step
 - backtracking(DFS) - TLE

#### Discuss
 - [BFS](https://discuss.leetcode.com/topic/16983/easy-76ms-c-solution-using-bfs)
 - [Two-end](https://discuss.leetcode.com/topic/10372/share-my-two-end-bfs-in-c-80ms) - From one end, we have to generate O(m^len) branches. Yet from both ends, we are only supposed to generate O(2m^(len/2)) braches. So we are sqrt(m^len)/2 times faster.
