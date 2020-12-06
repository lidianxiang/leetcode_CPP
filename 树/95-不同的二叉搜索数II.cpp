/*

给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

示例：

输入：3
输出：
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]

解释：
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

#include<iostream>
using namespace std;
#include<vector>


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution{      // 递归法
public:
    vector<TreeNode*> generateTrees(int start, int end){
        if (start > end){
            return {nullptr};
        }
        
        vector<TreeNode*> allTrees;
        for (int i=start; i <= end; i++){
            // 获得所有可行的左子树集合
            vector<TreeNode*> leftTrees = generateTrees(start, i-1);
            // 获得所有可行的右子树集合
            vector<TreeNode*> rightTrees = generateTrees(i+1, end);
            // 从左子树集合中选出一颗左子树，从右子树集合中选出一颗右子树，拼接到根节点上
            for(auto& left: leftTrees){
                for(auto& right:rightTrees){
                    TreeNode* currTree = new TreeNode(i);
                    currTree->left = left;
                    currTree->right = right;
                    allTrees.emplace_back(currTree);
                }
            }
        }
        return allTrees;
    }

    vector<TreeNode*> generateTrees(int n){
        if (!n){  // 当n不存在的情况
            return {};
        }
        return generateTrees(1, n);
    }
};