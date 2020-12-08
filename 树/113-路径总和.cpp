/*

给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

*/

#include<iostream>
using namespace std;
#include<vector>


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution{     // dfs递归法
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(TreeNode *root, int sum){
        if (!root)
            return;
        path.push_back(root->val);
        sum -= root->val;
        if (!root->left && !root->right && sum == 0)
        {
            res.push_back(path);
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum){
        dfs(root, sum);
        return res;
    }
};