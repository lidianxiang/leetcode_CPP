/*

给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。

进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？

示例 1：
输入：root = [1,3,null,null,2]
输出：[3,1,null,null,2]
解释：3 不能是 1 左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。

示例 2：
输入：root = [3,1,4,null,null,2]
输出：[2,1,4,null,null,3]
解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。

*/


#include<iostream>
using namespace std;
#include<vector>


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(NULL), right(NULL) {}
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution
{
private:
    int x = -1, y = -1;
    // 中序遍历，将树中值放入数组中
    void inorder(TreeNode *root, vector<int> &nums)
    {
        if (root == nullptr)
            return;

        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    // 寻找出那两个异常数值
    void findTwoSwappedNums(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] > nums[i + 1])
            {
                y = nums[i + 1];   // 第一个异常点用y记录下来，当时后面如果还有异常点，需要更新y值
                if (x == -1)  // 当发现第一个异常点时，即用x记录下来，后面就不需要改变得啦
                    x = nums[i];
                else
                    break;
            }
        }
    }
    // 重新恢复二叉搜索树
    void recover(TreeNode *root)
    {
        if (root == nullptr)
            return;

        if (root->val == x)  
            root->val = y;
        else if (root->val == y)
            root->val = x;
        recover(root->left);
        recover(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        vector<int> nums{};
        inorder(root, nums);
        findTwoSwappedNums(nums);
        recover(root);
    }
};


class Solution2{
private:
    // 维护三个指针，x和y记录下两个错误的值，pred指针用于记录当前节点的前驱节点
    TreeNode *x = nullptr, *y = nullptr, *pred = nullptr;
    void inorder(TreeNode *node)  // 中序遍历
    {
        if (node == nullptr)
            return;

        inorder(node->left);
        // 当前驱节点不为空且当前节点值小于前驱节点值
        if (pred != nullptr && node->val < pred->val)
        {
            y = node; // y用于记录当前节点，如果后面还存在当前节点值小于前驱节点值的情况，需要更新y
            if (x == nullptr)
                x = pred; // x用于记录前驱节点，且不用改变了
            else
                return;
        }
        pred = node;  // 更新前驱节点
        inorder(node->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        inorder(root);
        int temp = x->val;
        x->val = y->val;
        y->val = temp;
    }
};