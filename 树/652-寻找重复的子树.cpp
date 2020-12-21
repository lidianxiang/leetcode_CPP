/*

给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

两棵树重复是指它们具有相同的结构以及相同的结点值。

示例 1：

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
下面是两个重复的子树：

      2
     /
    4
和

    4

*/


#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(NULL), right(NULL) {}
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)   // 递归法
    {
        vector<TreeNode *> res;
        unordered_map<string, int> mp;
        dfs(root, res, mp);
        return res;
    }

    string dfs(TreeNode *root, vector<TreeNode *> &res, unordered_map<string, int> &mp)
    {
        if (root == 0)
            return "";

        string str = to_string(root->val) + "," + dfs(root->left, res, mp) + "," + dfs(root->right, res, mp);
        // mp的value默认从0开始计算，所以等于value等于1时，即代表有重复的子树了
        if (mp[str] == 1)
        {
            res.push_back(root);
        }
        mp[str]++;
        return str;
    }
};