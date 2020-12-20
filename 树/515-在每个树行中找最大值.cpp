/*

您需要在二叉树的每一行中找到最大的值。

示例：

输入: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

输出: [1, 3, 9]

*/


#include<iostream>
using namespace std;
#include<queue>


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(NULL), right(NULL) {}
    TreeNode(int x): val(x), left(NULL) ,right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};


class Solution{      // 层次遍历
public:
    vector<int> largestValues(TreeNode* root){
        queue<TreeNode *> q;
        if (root != nullptr)
        {
            q.push(root);
        }
        vector<int> res;
        while (!q.empty())
        {
            int size = q.size();
            int maxValue = INT_MIN;
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();
                maxValue = max(maxValue, node->val);
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            res.push_back(maxValue);
        }
        return res;
    }
};