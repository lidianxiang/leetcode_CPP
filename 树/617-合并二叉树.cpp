/*

给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

示例 1:

输入: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
输出: 
合并后的树:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7

*/

#include<iostream>
using namespace std;
#include<queue>


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution{   // DFS递归法
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (!t1)
            return t2;
        if (!t2)
            return t1;

        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};


class Solution2{
public:
    TreeNode* mergeTrees(TreeNode *t1, TreeNode *t2){
        if (t1 == nullptr)
            return t2;
        if (t2 == nullptr)
            return t1;

        auto merge = new TreeNode(t1->val + t2->val);
        queue<TreeNode *> q;
        queue<TreeNode *> queue1;
        queue<TreeNode *> queue2;
        q.push(merge);
        queue1.push(t1);
        queue2.push(t2);
        while (!queue1.empty() && !queue2.empty())
        {
            auto node = q.front(), node1 = queue1.front(), node2 = queue2.front();
            q.pop();
            queue1.pop();
            queue2.pop();
            auto left1 = node1->left, left2 = node2->left, right1 = node1->right, right2 = node2->right;
            if (left1 != nullptr || left2 != nullptr)
            {
                if (left1 != nullptr && left2 != nullptr)
                {
                    auto left = new TreeNode(left1->val + left2->val);
                    node->left = left;
                    q.push(left);
                    queue1.push(left1);
                    queue2.push(left2);
                }
                else if (left1 != nullptr)
                {
                    node->left = left1;
                }
                else if (left2 != nullptr)
                {
                    node->left = left2;
                }
            }
            if (right1 != nullptr || right2 != nullptr)
            {
                if (right1 != nullptr && right2 != nullptr)
                {
                    auto right = new TreeNode(right1->val + right2->val);
                    node->right = right;
                    q.push(right);
                    queue1.push(right1);
                    queue2.push(right2);
                }
                else if (right1 != nullptr)
                {
                    node->right = right1;
                }
                else if (right2 != nullptr)
                {
                    node->right = right2;
                }
            }
        }
        return merge;
    }
};