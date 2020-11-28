/*

给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

*/

#include<iostream>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution{
private:
    int ans;
    int depth(TreeNode* node){  // 递归
        if (node == NULL)  // 递归结束条件
            return 0;
        int L = depth(node->left);  // 左儿子为根的子树的深度
        int R = depth(node->right); // 右儿子为根的子树的深度
        ans = max(ans, L+R+1);      // 计算节点的深度并更新ans
        return max(L, R)+1;         // 返回该节点为根的子树的深度
    }
public:
    int diameterOfBinaryTree(TreeNode* root){
        ans = 1;
        depth(root);
        return ans-1;
    }
};