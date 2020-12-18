/*

给你一个二叉树的根结点，请你找出出现次数最多的子树元素和。一个结点的「子树元素和」定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。

你需要返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。

示例 1：
输入:

  5
 /  \
2   -3
返回 [2, -3, 4]，所有的值均只出现一次，以任意顺序返回所有值。

示例 2：
输入：

  5
 /  \
2   -5
返回 [2]，只有 2 出现两次，-5 只出现 1 次。

*/


#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution{    // 后序遍历递归
public:
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        unordered_map<int, int> sumFreq;  // 哈希表，key为子树和，value为key的出现次数
        int maxFreq = 0;
        dfs(root, sumFreq, maxFreq);  // 后序遍历
        vector<int> res;
        for (const auto &kv : sumFreq)
        {
            if (kv.second == maxFreq)
            {
                res.push_back(kv.first);
            }
        }
        return res;
    }

    // 后序遍历
    int dfs(TreeNode *root, unordered_map<int, int> &sumFreq, int &maxFreq)
    {
        if (root == nullptr)
            return 0;

        int sumLeft = dfs(root->left, sumFreq, maxFreq);
        int sumRight = dfs(root->right, sumFreq, maxFreq);
        auto sum = sumLeft + sumRight + root->val;
        sumFreq[sum]++;
        maxFreq = max(maxFreq, sumFreq[sum]);
        return sum;
    }
};