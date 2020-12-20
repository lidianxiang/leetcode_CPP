/*

给定一个二叉树，根节点为第1层，深度为 1。在其第 d 层追加一行值为 v 的节点。

添加规则：给定一个深度值 d （正整数），针对深度为 d-1 层的每一非空节点 N，为 N 创建两个值为 v 的左子树和右子树。

将 N 原先的左子树，连接为新节点 v 的左子树；将 N 原先的右子树，连接为新节点 v 的右子树。

如果 d 的值为 1，深度 d - 1 不存在，则创建一个新的根节点 v，原先的整棵树将作为 v 的左子树。

示例 1:

输入: 
二叉树如下所示:
       4
     /   \
    2     6
   / \   / 
  3   1 5   

v = 1

d = 2

输出: 
       4
      / \
     1   1
    /     \
   2       6
  / \     / 
 3   1   5   

示例 2:

输入: 
二叉树如下所示:
      4
     /   
    2    
   / \   
  3   1    

v = 1

d = 3

输出: 
      4
     /   
    2
   / \    
  1   1
 /     \  
3       1

*/

#include<iostream>
using namespace std;
#include<queue>


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(NULL), right(NULL){}
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution{
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d){
        if (d == 1)    // 如果d为1时，则创建一个新的根节点，原来的root为其左节点
        {
            return new TreeNode(v, root, nullptr);
        }

        queue<TreeNode *> q;
        q.push(root);
        // 当前层数为d-1时，停止遍历
        while (--d != 1){
            for (int i = 0, size = q.size(); i < size; ++i){
                TreeNode *node = q.front();
                q.pop();
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
            }
        }
        // 队列中剩下的节点即为节点N
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            // 先创建一个节点P，其左节点为当前节点的左节点
            // 然后将当前节点的左节点设置为P
            node->left = new TreeNode(v, node->left, nullptr);
            node->right = new TreeNode(v, nullptr, node->right);
        }
        return root;
    }
};