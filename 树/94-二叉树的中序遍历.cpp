/*

给定一个二叉树的根节点 root ，返回它的 中序 遍历。

 

示例 1：
        1
          \ 
           2
         /
        3
输入：root = [1,null,2,3]
输出：[1,3,2]

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
输出：[2,1]

示例 5：
        1
          \
           2

输入：root = [1,null,2]
输出：[1,2]

*/

#include<iostream>
using namespace std;
#include<vector>
#include<stack>


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
    void traversal(TreeNode* cur, vector<int>& vec){
        if (cur == NULL)
            return;
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }

    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        traversal(root, res);
        return res;
    }
};


class Solution2{     // 迭代法
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (!stk.empty() || cur != NULL)
        {
            if (cur != NULL)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = stk.top();
                stk.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};