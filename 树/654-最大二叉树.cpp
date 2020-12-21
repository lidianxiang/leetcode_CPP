/*

给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。
通过给定的数组构建最大二叉树，并且输出这个树的根节点。

示例 ：

输入：[3,2,1,6,0,5]
输出：返回下面这棵树的根节点：

       6
    /     \
   3       5
    \     / 
     2   0   
       \
        1

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
};


class Solution{
private:
    TreeNode *traversal(vector<int> &nums, int left, int right)
    {
        if (left >= right){   // 递归终止条件
            return nullptr;
        }

        int maxValueIndex = left;
        // 遍历数组找到数组中的最大值
        for (int i = left + 1; i < right; i++)
        {
            if (nums[i] > nums[maxValueIndex])
            {
                maxValueIndex = i;
            }
        }
        // 将最大值作为根节点
        TreeNode *root = new TreeNode(nums[maxValueIndex]);
        // 递归左子树，范围左闭右开
        root->left = traversal(nums, left, maxValueIndex);
        // 递归右子树，范围左闭右开
        root->right = traversal(nums, maxValueIndex + 1, right);
        return root;
    }

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return traversal(nums, 0, nums.size());
    }
};