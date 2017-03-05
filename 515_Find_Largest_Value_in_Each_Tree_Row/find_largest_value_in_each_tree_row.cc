#include "find_largest_value_in_each_tree_row.h"
#include <sstream>
using std::istringstream;
using std::ostringstream;
#include <string>
using std::string;
using std::cin;

 int myAtoi_2(string &s)
{
    if(s.empty()) return 0;
    int sign = 1, size = s.size();
    long result = 0;
    int i = s.find_first_not_of(' ');
    if(i == -1)
        return 0;
    if(s.at(i) == '+' || s.at(i) == '-')
        sign = (s.at(i++) == '+') ? 1 : -1;
    while(i < size && s.at(i) >= '0' && s.at(i) <= '9')
    {
        result = result * 10 + (s.at(i++) - '0');
        if(result * sign >= INT_MAX) return INT_MAX;
        if(result * sign <= INT_MIN) return INT_MIN;
    }
    return result * sign;
}

TreeNode *CreateTree()
{
    cout << "Please input a sequence of node separated by whitespace and ended in \"quit\"\
            e.g, 1 3 2 5 3 null 9 quit" << endl;
    string str;
    TreeNode * root;
    if(cin >> str && str != "null" && str != "quit")
    {
        root = new TreeNode(myAtoi_2(str));
    }
    else
    {
        return NULL;
    }

    vector<string> values;
    while(cin >> str && str != "quit")
    {
        values.push_back(str);
    }

    queue<TreeNode *> nodes;
    nodes.push(root);

    int i = 0;      // index of values
    int size = values.size();
    TreeNode * cur = NULL;

    while(!nodes.empty())
    {
        cur = nodes.front();
        TreeNode *left_child, *right_child;

        if(i < size && values.at(i) != "null")
        {
            left_child = new TreeNode(myAtoi_2(values.at(i)));
            cur->left = left_child;
            nodes.push(left_child);
        }
        ++i;
        if(i < size && values.at(i) != "null")
        {
            right_child = new TreeNode(myAtoi_2(values.at(i)));
            cur->right = right_child;
            nodes.push(right_child);
        }
        ++i;
        nodes.pop();
    }

    return root;
}

/*
int DeleteTree_1(TreeNode *root)
{
    if(root == NULL)
        return -1;

    queue<TreeNode *> tree;
    TreeNode *cur = NULL;
    tree.push(root);

    while(!tree.empty())
    {
        cur = tree.front();
        if(cur->left)
            tree.push(cur->left);
        if(cur->right)
            tree.push(cur->right);
        tree.pop();
        delete cur;
    }

    return 1;
}
*/

void DeleteTree_2(TreeNode * &root)
{
    if(root == NULL)
        return;
    if(root->left)
        DeleteTree_2(root->left);
    if(root->right)
        DeleteTree_2(root->right);
    delete root;
    root = NULL;
}

int CheckTree(TreeNode *root)
{
    if(root == NULL)
        return -1;

    queue<TreeNode *> tree;
    TreeNode *cur = NULL;
    tree.push(root);

    cout << "***** BEGIN: what the tree is look like *****" << endl;
    while(!tree.empty())
    {
        cur = tree.front();
        cout << cur->val << "  ";
        if(cur->left)
        {
            tree.push(cur->left);
            cout << "left: " << cur->left->val << '\t';
        }
        else
        {
            cout << "left: null" << '\t';
        }
        if(cur->right)
        {
            tree.push(cur->right);
            cout << "right: " << cur->right->val << '\t';
        }
        else
        {
            cout << "right: null" << '\t';
        }
        cout << endl;
        tree.pop();
    }
    cout << "***** END: what the tree is look like *****" << endl;

    return 1;
}

int main()
{
    TreeNode *root = CreateTree();
    CheckTree(root);
    /*
    TreeNode *six = new TreeNode(9);
    TreeNode *five = new TreeNode(3);
    TreeNode *four = new TreeNode(5);
    TreeNode *two = new TreeNode(3);
    two->left = four;
    two->right = five;
    TreeNode *three = new TreeNode(2);
    three->right = six;
    TreeNode *one = new TreeNode(1);
    one->left = two;
    one->right = three;
*/
    Solution s;
    vector<int> out = s.largestValues(root);
    for(auto i : out)
        cout << i << ' ';
    cout << endl;
    DeleteTree_2(root);

/*
    delete six;
    delete five;
    delete four;
    delete three;
    delete two;
    delete one;
*/
    return 0;
}
