/*

给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1:
输入: 
           1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

输出: true

示例 2:
输入: 
           1          1
          /           \
         2             2

        [1,2],     [1,null,2]

输出: false

示例 3:
输入: 
           1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

输出: false

*/

#include<iostream>
using namespace std;
#include<queue>


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q){
        /*
            DFS（深度优先搜索）
        */
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if (p == nullptr || q == nullptr)
        {
            return false;
        }
        else if (p->val != q->val)
        {
            return false;
        }
        else
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};



class Solution2{
public:
    bool isSameTree(TreeNode *p, TreeNode *q){
        /*
            BFS(广度优先搜索)：队列
        */
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if (p == nullptr || q == nullptr)
        {
            return false;
        }
        queue<TreeNode *> queue1, queue2;
        queue1.push(p);
        queue2.push(q);
        while (!queue1.empty() && !queue2.empty())
        {
            auto node1 = queue1.front();
            queue1.pop();
            auto node2 = queue2.front();
            queue2.pop();
            if (node1->val != node2->val)
            {
                return false;
            }
            auto left1 = node1->left, right1 = node1->right, left2 = node2->left, right2 = node2->right;
            if ((left1 == nullptr) ^ (left2 == nullptr))
            {
                return false;
            }
            if ((right1 == nullptr) ^ (right2 == nullptr))
            {
                return false;
            }
            if (left1 != nullptr)
            {
                queue1.push(left1);
            }
            if (right1 != nullptr)
            {
                queue1.push(right1);
            }
            if (left2 != nullptr)
            {
                queue2.push(left2);
            }
            if (right2 != nullptr)
            {
                queue2.push(right2);
            }
        }
        return queue1.empty() && queue2.empty();
  
    }
};