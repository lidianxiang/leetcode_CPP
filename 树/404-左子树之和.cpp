/*

计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

*/

#include<iostream>
using namespace std;
#include<queue>


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution{
public:
    bool isLeafNode(TreeNode *node)
    {
        // 判断是否是叶子节点
        return !node->left && !node->right;
    }

    int dfs(TreeNode *node)
    {
        int ans = 0;
        if (node->left)
        {
            ans += isLeafNode(node->left) ? node->left->val : dfs(node->left);
        }
        if (node->right && !isLeafNode(node->right))
        {
            ans += dfs(node->right);
        }
        return ans;
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        return root ? dfs(root) : 0;
    }
};


class Solution2  
/*
    BFS: queue队列

*/
{
public:
    bool isLeafNode(TreeNode *node)
    {
        // 判断是否是叶子节点
        return !node->left && !node->right;
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int ans = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
            {
                if (isLeafNode(node->left))
                {
                    ans += node->left->val;
                }
                else
                {
                    q.push(node->left);
                }
            }
            if (node->right)
            {
                if (!isLeafNode(node->right))
                {
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};