/*

给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]

*/


#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<algorithm>


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(NULL), right(NULL) {}
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};


class Solution{      // 递归法
public:
    void traversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == NULL)
            return;
        traversal(cur->left, vec);
        traversal(cur->right, vec);
        vec.push_back(cur->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};


class Solution2{      // 迭代法
public:
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode *> stk;
        if (root == NULL)
            return res;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();
            res.push_back(node->val);
            if (node->left)
                stk.push(node->left);
            if (node->right)
                stk.push(node->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};