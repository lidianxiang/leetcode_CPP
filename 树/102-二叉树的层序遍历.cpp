/*

给你一个二叉树，请你返回其按层序遍历得到的节点值。（即逐层地，从左到右访问所有节点）。

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

*/

#include<iostream>
using namespace std;
#include<queue>
#include<vector>


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode *root){
        /*
            广度优先搜索
        */
        vector<vector<int>> res;
        if (root == NULL)
        {
            return res;
        }

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int currentLevelSize = q.size();
            res.push_back(vector<int>());
            for (int i = 0; i < currentLevelSize; i++)
            {
                auto node = q.front();
                q.pop();
                res.back().push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return res;
    }
};