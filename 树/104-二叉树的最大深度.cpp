/*

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

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
    int maxDepth(TreeNode *root){
            /*
                递归法
            */
        if (root == nullptr) 
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};


class Solution{
public:
    int maxDepth(TreeNode* root){
        /*
            广度优先搜索：每次将一层的节点全部放在队列中
        */
        if (root == nullptr)
            return 0;
        queue<TreeNode *> Queue;
        Queue.push(root);
        int ans = 0;
        while (!Queue.empty())
        {
            int size = Queue.size();
            while (size > 0)
            {
                TreeNode *node = Queue.front();
                Queue.pop();
                if (node->left)
                    Queue.push(node->left);
                if (node->right)
                    Queue.push(node->right);
                --size;
            }
            ++ans;
        }
        return ans;
    }
};