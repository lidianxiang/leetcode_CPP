/*

给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。

每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。

示例 1:

输入: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

输出: 4
解释: 最大值出现在树的第 3 层，宽度为 4 (5,3,null,9)。
示例 2:

输入: 

          1
         /  
        3    
       / \       
      5   3     

输出: 2
解释: 最大值出现在树的第 3 层，宽度为 2 (5,3)。
示例 3:

输入: 

          1
         / \
        3   2 
       /        
      5      

输出: 2
解释: 最大值出现在树的第 2 层，宽度为 2 (3,2)。
示例 4:

输入: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
输出: 8
解释: 最大值出现在树的第 4 层，宽度为 8 (6,null,null,null,null,null,null,7)。

*/


#include<iostream>
using namespace std;
#include<queue>
#include<list>


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};


class Solution{   // 层次遍历
public:
    int widthBinaryTree(TreeNode* root){
        if (root == nullptr){
            return 0;
        }

        int res = 1;
        list<int> idxList = {1};
        queue<TreeNode*> q{{root}};
        while(!q.empty()){
            auto delta = idxList.front() - 1;
            for(int k=q.size(); k>0; k--){
                auto index = idxList.front(); idxList.pop_front();
                index -= delta;
                auto cur = q.front(); q.pop();
                if (cur->left){
                    q.push(cur->left);
                    idxList.push_back(index*2);
                }
                if (cur->right){
                    q.push(cur->right);
                    idxList.push_back(index*2+1);
                }
            }
            res = max(res, idxList.back() - idxList.front() + 1);
        }
        return res;
    }
};