/*

给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。

注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。

示例 1：
输入：root = [4,2,7,1,3], val = 5
输出：[4,2,7,1,3,5]
解释：另一个满足题目要求可以通过的树是：

示例 2：
输入：root = [40,20,60,10,30,50,70], val = 25
输出：[40,20,60,10,30,50,70,null,null,25]

示例 3：
输入：root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
输出：[4,2,7,1,3,5]

*/


#include<iostream>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution{     // 模拟法
public:
    TreeNode* insertIntoBST(TreeNode* root, int val){
        if (root == nullptr){
            return new TreeNode(val);
        }

        TreeNode* pos = root;
        while(pos != nullptr){
            // 当插入值小于根节点的值
            if(val < pos->val){
                // 当当前节点没有左节点
                if (pos->left == nullptr){
                    pos->left = new TreeNode(val);  // 插入值即为左节点
                    break;
                }else{
                    pos = pos->left;  
                }
            }else{   // 当插入值小于根节点的值
                // 当当前节点没有左节点
                if (pos->right == nullptr){
                    pos->right = new TreeNode(val);  // 插入值即为右节点
                    break;
                }else{
                    pos = pos->right;
                }
            }
        }
        return root;
    }
};