/*

给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

*/

#include<iostream>
using namespace std;
#include<queue>


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x): val(x), left(NULL), right(NULL) {}
};


class Solution{
public:
    bool check(TreeNode *p, TreeNode *q)
        /*
            递归法
        */
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
    
    bool isSymmetric(TreeNode *root)
    {
        return check(root, root);
    }
};


class Solution{
public:
    bool check(TreeNode *u, TreeNode *v)
        /*
            迭代法：将上面的递归法改为了迭代法
        */
    {
        queue<TreeNode *> q;
        q.push(u);
        q.push(v);
        while (!q.empty())
        {
            u = q.front();
            q.pop();
            v = q.front();
            q.pop();
            if (!u && !v)
                continue;
            if ((!u || !v) || (u->val != v->val))
                return false;

            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode *root)
    {
        return check(root, root);
    }
};