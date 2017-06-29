
    Author:            cuckoo
    Date:              2017/06/24 11:01:04
    Update:            
    Problem:           Count Complete Tree Nodes
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/count-complete-tree-nodes/#/description

#### Solution Step
 - I.遍历二叉树，累加
 - II.二分的思想：
    - a.其他层的节点数目加上最后一层的节点数目
    - b.如何得到最后一层的节点数目？
        - (1)分别计算当前根节点左子树和右子树的层数LN,RN(一直向左孩子方向遍历下去)
        - (2)如果 LN == RN，说明根节点左子树最后一层是满的，以当前根节点的右孩子为新的根节点，计算最后一层的数目，两者相加
        - (3)否则，说明根节点右子树最后一层是空的，以当前根节点的左孩子为新的根节点，计算最后一层的数目

#### Discuss
 - [More Simple, Easy Understand](https://discuss.leetcode.com/topic/15515/easy-short-c-recursive-solution)
