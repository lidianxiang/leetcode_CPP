/*

给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 3
进阶：
如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？

*/

#include<iostream>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0), left(NULL), right(NULL) {}
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right):val(x), left(left), right(right) {}
};


class Solution{    // 中序遍历（二叉搜索树的中序遍历结果是升序序列）
private:
    vector<int> vec;
    void dfs(TreeNode *root, int k)
    {
        if (!root)
            return;
        dfs(root->left, k);
        vec.push_back(root->val);
        dfs(root->right, k);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        dfs(root, k);
        return vec[k - 1];
    }
};


class Solution2{   // dfs中序遍历，直接count中序遍历过的元素，到k个的时候退出
private:
    int count = 0;
    int res = -1;
    void dfs(TreeNode *root, int k)
    {
        if (!root)
        {
            return;
        }
        dfs(root->left, k);
        count++;
        if (count == k)
        {
            res = root->val;
            return;
        }
        dfs(root->right, k);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        dfs(root, k);
        return res;
    }
};


class Solution3{    // 递归+二分查找
private:
    int getNumOfNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        return getNumOfNodes(root->left) + getNumOfNodes(root->right) + 1;
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        if (!root)
            return -1;

        int numOfLeftNodes = getNumOfNodes(root->left);
        int numOfRightNodes = getNumOfNodes(root->right);
        if (numOfLeftNodes == k - 1)
        {
            return root->val;
        }
        else if (numOfLeftNodes >= k)
        {
            return kthSmallest(root->left, k);
        }
        else
        {
            return kthSmallest(root->right, k - numOfLeftNodes - 1);
        }
    }
};