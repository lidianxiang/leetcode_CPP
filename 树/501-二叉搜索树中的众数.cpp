/*

给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树

例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2
返回[2].

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


class Solution{
public:
    vector<int> ans;
    int base, count, maxCount;

    void update(int x){
        if (x == base){
            ++count;  // 计数加一
        }else{
            count = 1;
            base = x;
        }

        if (count == maxCount){
            ans.push_back(base);
        }
        if (count > maxCount){
            maxCount = count;  // 更新众数的次数
            ans = vector<int> {base};  // 更新最大数
        }
    }

    void dfs(TreeNode* node){ // 中序遍历
        if (!node){
            return;
        }

        dfs(node->left);
        update(node->val);
        dfs(node->right);
    }

    vector<int> findMode(TreeNode* root){
        dfs(root);
        return ans;
    }
};