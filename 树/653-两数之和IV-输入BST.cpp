/*

给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

案例 1:
输入: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

输出: True
 

案例 2:
输入: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

输出: False

*/

#include<iostream>
using namespace std;
#include<vector>


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(NULL), right(NULL) {}
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};


class Solution{   // 中序遍历+双指针
public:
    vector<int> vec;
    void inorder(TreeNode *root, vector<int> &vec)
    {
        if (!root)
            return;
        if (root->left)
            inorder(root->left, vec);
        vec.push_back(root->val);
        if (root->right)
            inorder(root->right, vec);
    }

    bool findTarget(TreeNode *root, int k)
    {
        inorder(root, vec);
        int left = 0, right = vec.size() - 1;
        while (left < right)
        {
            if (vec[left] + vec[right] == k)
                return true;
            else if (vec[left] + vec[right] < k)
                ++left;
            else
                --right;
        }
        return false;
    }
};