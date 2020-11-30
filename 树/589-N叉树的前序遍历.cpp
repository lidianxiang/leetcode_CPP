/*

给定一个 N 叉树，返回其节点值的前序遍历。

例如，给定一个 3叉树 :

         1
      /  |  \
     3   2  4
   /  |
  5   6

返回其前序遍历: [1,3,5,6,2,4]。

*/

#include<iostream>
using namespace std;
#include<vector>
#include<stack>


class Node{
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val){
        val = _val;
    }

    Node(int _val, vector<Node*> _children){
        val = _val;
        children = _children;
    }
};


class Solution{
public:
    vector<int> res;
    vector<int> preorder(Node* root){
        /*
            递归法
        */
        if (!root)
            return res;
        res.push_back(root->val);
        for (Node* i:root->children){
            preorder(i);
        }
        return res;
    }
};


class Solution2{
public:
    vector<int> preorder(Node* root){
        /*
            迭代法
        */
        vector<int> res;
        if (!root)
            return res;

        stack<Node *> stk;
        stk.push(root);
        while (!stk.empty())
        {
            Node *node = stk.top();
            stk.pop();
            res.push_back(node->val);
            for (int i = node->children.size() - 1; i >= 0; --i) 
            {
                stk.push(node->children[i]);
            }
        }
        return res;
    }
};