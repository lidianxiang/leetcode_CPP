/*

给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。

示例 1：

输入：
    3
   / \
  9  20
    /  \
   15   7
输出：[3, 14.5, 11]
解释：
第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。

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

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    /*
        BFS迭代法
    */
    {
        vector<double> avg;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            double sum = 0;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                auto left = node->left, right = node->right;
                if (left != nullptr)
                {
                    q.push(left);
                }
                if (right != nullptr)
                {
                    q.push(right);
                }
            }
            avg.push_back(sum / size);
        }
        return avg;
    }
};