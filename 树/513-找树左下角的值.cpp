/*

给定一个二叉树，在树的最后一行找到最左边的值。

示例 1:

输入:

    2
   / \
  1   3

输出:
1

示例 2:

输入:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

输出:
7

*/


#include<iostream>
using namespace std;
#include<queue>


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(NULL), right(NULL) {}
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};


class Solution{   //递归法
public:
    int maxLen = INT_MIN;
    int maxLeftValue;
    void dfs(TreeNode *root, int leftLen)
    {
        if (root->left == nullptr && root->right == nullptr)  // 递归终止条件
        {
            if (leftLen > maxLen)
            {
                maxLen = leftLen;  // 更新最大深度
                maxLeftValue = root->val;
            }
            return;
        }
        if (root->left)
        {
            dfs(root->left, leftLen + 1);
        }
        if (root->right)
        {
            dfs(root->right, leftLen + 1);
        }
    }

    int findBottomLeftValue(TreeNode *root)
    {
        dfs(root, 0);
        return maxLeftValue;
    }
};


class Solution2{      // 层次遍历
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (root != nullptr)
        {
            q.push(root);
        }
        int result = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (i == 0)
                    result = node->val;
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
        }
        return result;
    }
};