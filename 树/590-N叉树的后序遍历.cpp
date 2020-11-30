/*

给定一个 N 叉树，返回其节点值的后序遍历。

例如，给定一个 3叉树 :

       1 
     / | \
    3  2  4
   / \
  5   6

返回其后序遍历: [5,6,3,2,4,1]

*/

#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<algorithm>


class Node{
public:
    int val;
    vector<Node*> children;

    Node(){}

    Node(int _val){
        val = _val;
    }

    Node(int _val, vector<Node*> _children){
        val = _val;
        children = _children;
    }
};


class Solution{   // 递归法
private:
    vector<int> res;
    void traversal(Node* root){
        if (root == NULL) 
            return;

        for(int i=0; i<root->children.size(); i++){
            traversal(root->children[i]);
        }
        res.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root){
        traversal(root);
        return res;
    }
};


class Solution2{    // stack迭代法
public:
    vector<int> postorder(Node* root){
        vector<int> res;
        if (root == NULL)
            return res;
        stack<Node *> stk;
        stk.push(root);
        while (!stk.empty())
        {
            Node *node = stk.top();
            stk.pop(); 
            res.push_back(node->val);
            for (int i = 0; i < node->children.size(); i++)
            {
                if (node->children[i] != NULL)
                {
                    stk.push(node->children[i]);
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};