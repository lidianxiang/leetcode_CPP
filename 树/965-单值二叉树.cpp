/*

如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。

只有给定的树是单值二叉树时，才返回 true；否则返回 false。

示例 1：
        1
      /   \
     1     1
    / \     \
   1   1      1

输入：[1,1,1,1,1,null,1]
输出：true

示例 2：
        2
      /   \
     2     2
    / \     
   5   2      

输入：[2,2,2,5,2]
输出：false

*/

#include<iostream>
using namespace std;
#include<vector>;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution{
public:
    bool isUnivalTree(TreeNode* root){
        /*
            递归法
        */
        bool left_correct = (root->left == nullptr || (root->val == root->left->val && isUnivalTree(root->left)));
        bool right_correct = (root->right == nullptr || (root->val == root->right->val && isUnivalTree(root->right)));
        return left_correct && right_correct;
    }
};