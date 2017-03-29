
    Author:            cuckoo
    Date:              2017/03/29 08:45:35
    Update:            
    Problem:           Word Search
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/word-search/#/description

__Solution Step__:
 - `accessed[row][col]` check if board[row][col] is accessed
 - if not accessed, and row and col are valid, and word[index] match board[row][col]
 - turn `backward` | `forward` | `upward` | `downward` respectively
 - until the last character in word is matched
