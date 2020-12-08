/*

给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

*/


#include<iostream>
using namespace std;
#include<vector>
#include<queue>


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution{    // DFS递归法
public:
    vector<vector<int>> res;
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        addVector(root, 0);
        return res;
    }

    void addVector(TreeNode *root, int level)
    {
        if (!root) // 特殊情况
            return;
        if (res.size() == level) // 扩容
            res.resize(level + 1);

        if (level % 2 == 0)
            res[level].push_back(root->val);
        else
            res[level].insert(res[level].begin(), root->val);

        addVector(root->left, level + 1);
        addVector(root->right, level + 1);
    }
};


class Solution2{    // BFS迭代
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return {};

        queue<TreeNode *> q;
        q.push(root);

        int level = 0;
        while (!q.empty())
        {
            vector<int> temp;
            int count = q.size();
            while (count--)
            {
                TreeNode *node = q.front();
                q.pop();
                if (level % 2 == 0)
                    temp.push_back(node->val);
                else
                    temp.insert(temp.begin(), node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            level++;
            res.push_back(temp);
        }
        return res;
    }
};