/*

给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

*/

#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<algorithm>


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x): val(x), left(NULL), right(NULL) {}
};


class Solution{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root){
        /*
            广度优先搜索：这题和102题很相似，不同在于这题需要在最后进行一个倒序操作
        */
        auto levelOrder = vector<vector<int>>();
        if (!root)
        {
            return levelOrder;
        }

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            auto level = vector<int>();
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            levelOrder.push_back(level);
        }

        reverse(levelOrder.begin(), levelOrder.end());
        return levelOrder;
    }
};