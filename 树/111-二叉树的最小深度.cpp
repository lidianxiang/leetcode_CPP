/*

给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：2

示例 2：
输入：root = [2,null,3,null,4,null,5,null,6]
输出：5

*/

#include<iostream>
using namespace std;
#include<limits.h>
#include<queue>


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution{
public:
    int minDepth(TreeNode *root){
        /*
            DFS:递归法
        */
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        int depth = INT_MAX;
        if (root->left != nullptr)
        {
            depth = min(minDepth(root->left), depth);
        }
        if (root->right != nullptr)
        {
            depth = min(minDepth(root->right), depth);
        }
        return depth + 1;
    }
};


class Solution2{
public:
    int minDepth(TreeNode* root){
        /*
            BFS: queue队列
        */
        if (root == nullptr)
            return 0;

        queue<pair<TreeNode *, int>> Queue;
        Queue.emplace(root, 1);
        while (!Queue.empty())
        {
            TreeNode *node = Queue.front().first;
            int depth = Queue.front().second;
            Queue.pop();
            if (node->left == nullptr && node->right == nullptr)
            {
                return depth;
            }
            if (node->left != nullptr)
            {
                Queue.emplace(node->left, depth + 1);
            }
            if (node->right != nullptr)
            {
                Queue.emplace(node->right, depth + 1);
            }
        }
        return 0;
    }
};