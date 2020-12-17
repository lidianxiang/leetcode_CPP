/*

给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
说明： 要求算法时间复杂度为 O(h)，h 为树的高度。

示例:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。

一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

    5
   / \
  4   6
 /     \
2       7

另一个正确答案是 [5,2,6,null,4,null,7]。

    5
   / \
  2   6
   \   \
    4   7

*/

#include<iostream>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode(right)) : val(x), left(left), right(right) {}
};


class Solution{   // 递归法
public:
    TreeNode* deleteNode(TreeNode* root, int key){
        // 第一种情况：没有找到删除的节点，遍历到空节点直接返回了
        if (root == nullptr)
            return root;
        if (root->val == key)
        {
            // 第二种情况：左右孩子都为空，直接删除节点，返回NULL为根节点
            // 第三种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位，返回右孩子为根节点
            if (root->left == nullptr)
                return root->right;
            // 第四种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补空，返回左孩子为根节点
            else if (root->right == nullptr)
                return root->left;
            else
            {
                TreeNode *cur = root->right;  // 找到右子树
                while (cur->left != nullptr)
                {
                    cur = cur->left;  // 返回右子树中的最左子树
                }
                cur->left = root->left;  // 将要删除的节点的左子树移到右子树的最左节点上
                TreeNode *tmp = root;  // 定义一个临时指针指向要删除的节点
                root = root->right;  
                delete tmp;  // 删除这个节点
                return root;
            }
        }
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        return root;
    }
};