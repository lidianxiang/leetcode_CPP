/*

给定一个二叉树，原地将它展开为一个单链表。

 

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

*/

#include<iostream>
using namespace std;
#include<vector>


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    void preorderTraversal(TreeNode *root, vector<TreeNode *> &vec)
    {
        if (root)
        {
            vec.push_back(root);
            preorderTraversal(root->left, vec);
            preorderTraversal(root->right, vec);
        }
    }

    void flatten(TreeNode *root)
    {
        vector<TreeNode *> vec;
        preorderTraversal(root, vec);
        int size = vec.size();
        for (int i = 1; i < size; ++i)
        {
            TreeNode *prev = vec.at(i - 1), *curr = vec.at(i);
            prev->left = nullptr;
            prev->right = curr;
        }
    }
};


class Solution2{  // 迭代实现前序遍历
public:
    void flatten(TreeNode *root)
    {
        auto vec = vector<TreeNode *>();
        auto stk = stack<TreeNode *>();
        TreeNode *node = root;
        while (node || !stk.empty())
        {
            while (node)
            {
                vec.push_back(node);
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        int size = vec.size();
        for (int i = 1; i < size; i++)
        {
            auto prev = vec.at(i - 1), curr = vec.at(i);
            prev->left = nullptr;
            prev->right = curr;
        }
    }
};