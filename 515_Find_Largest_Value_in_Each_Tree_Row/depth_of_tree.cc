//
// Author:            cuckoo
// Date:              2017/03/04 18:13:33
// Update:            /*date*/
// Description:       Depth of Tree
// Note:              /*denote*/

//

#include <iostream>
using std::cout;
using std::endl;

#include <cmath>
using std::max;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

int DepthOfTree(TreeNode *root)
{
    TreeNode *cur = root;
    int left_depth = 0, right_depth = 0;
    if(cur->left)
    {
        left_depth = DepthOfTree(cur->left);
    }
    if(cur->right)
    {
        right_depth = DepthOfTree(cur->right);
    }
    return max(left_depth, right_depth) + 1;
}

int main()
{
    TreeNode *four = new TreeNode(0);
    TreeNode *two = new TreeNode(0);
    two->left = four;
    TreeNode *three = new TreeNode(0);
    TreeNode *one = new TreeNode(0);
    one->left = two;
    one->right = three;

    cout << DepthOfTree(one) << endl;

    return 0;
}
