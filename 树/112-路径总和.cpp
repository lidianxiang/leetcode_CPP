/*

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

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
    bool hasPathSum(TreeNode* root, int sum){
        /*
            BFS: 队列
        */
        if (root == NULL)
            return false;
        queue<TreeNode *> queue_node;
        queue<int> queue_val;
        queue_node.push(root);
        queue_val.push(root->val);
        while (!queue_node.empty())
        {
            TreeNode *now = queue_node.front();
            int val = queue_val.front();
            queue_node.pop();
            queue_val.pop();

            if (now->left == NULL && now->right == NULL)
            {
                if (val == sum)
                {
                    return true;
                }
            }
            if (now->left != NULL)
            {
                queue_node.push(now->left);
                queue_val.push(val + now->left->val);
            }
            if (now->right != NULL)
            {
                queue_node.push(now->right);
                queue_val.push(val + now->right->val);
            }
        }
        return false;
    }
};


class Solution{
public:
    bool hasPathSum(TreeNode* root, int sum){
        /*
            DFS: 递归法
        */
        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr)
            return sum == root->val;
            
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};