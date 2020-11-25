/*

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

示例 1:
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6 
解释: 节点 2 和节点 8 的最近公共祖先是 6。

示例 2:
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。

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
    vector<TreeNode *> getPath(TreeNode *root, TreeNode *target)
    {
        vector<TreeNode *> path;
        TreeNode *node = root;
        while (node != target)
        {
            path.push_back(node);
            if (target->val < node->val)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        path.push_back(node);
        return path;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path_p = getPath(root, p);
        vector<TreeNode *> path_q = getPath(root, q);
        TreeNode *ancestor;
        for (int i = 0; i < path_p.size() && i < path_q.size(); ++i)
        {
            if (path_p[i] == path_q[i])
            {
                ancestor = path_p[i];
            }
            else
            {
                break;
            }
        }
        return ancestor;
    }
};


class Solution2{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        /*
        1、从根节点开始遍历
        2、如果当前节点值大于p和q的值，那么说明p和q应该在当前节点的左子树上，因此当前节点移动到左子树上
        3、如果当前节点值小于p和q的值，那么说明p和q应该在当前节点的右子树上，因此当前节点移动到右子树上
        4、如果当前节点不满足上述2个条件，那么说明当前节点就是分岔点
        */
        TreeNode* ancestor = root;
        while(true){
            if (p->val < ancestor->val && q->val < ancestor->val){
                ancestor = ancestor->left;
            }
            else if (p->val > ancestor->val && q->val > ancestor->val){
                ancestor = ancestor->right;
            }
            else{
                break;
            }
        }
        return ancestor;
    }
};