/*

给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

示例 1

     1 
      \
       2
      /
     3

输入：root = [1,null,2,3]
输出：[1,2,3]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]

示例 4：

      1
     /
    2
输入：root = [1,2]
输出：[1,2]

示例 5：
      1
        \
         2

输入：root = [1,null,2]
输出：[1,2]

*/

#include<iostream>
using namespace std;
#include<stack>
#include<vector>


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(NULL), right(NULL) {}
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};


class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        /*
            迭代法
        */
        stack<TreeNode *> stk;
        vector<int> res;
        if (root == NULL)
            return res;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();
            res.push_back(node->val);
            if (node->right)
                stk.push(node->right);
            if (node->left)
                stk.push(node->left);
        }
        return res;
    }
};


class Solution2{      // 递归法
public:
    void traversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == NULL)
            return;
        vec.push_back(cur->val);    // 中
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};