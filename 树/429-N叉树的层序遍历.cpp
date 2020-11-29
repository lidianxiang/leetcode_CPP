/*

给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。

例如，给定一个 3叉树 :

         1
      /  |  \
    3    2   4
  /  \
 5    6

返回其层序遍历:

[
     [1],
     [3,2,4],
     [5,6]
]

*/


#include<iostream>
using namespace std;
#include<queue>

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


class Solution{
public:
    vector<vector<int>> levelOrder(Node* root){
        queue<Node *> que;
        if (root != NULL)
            que.push(root);
        vector<vector<int>> res;
        while (!que.empty())
        {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++)
            {
                Node *node = que.front();
                que.pop();
                vec.push_back(node->val);
                for (int i = 0; i < node->children.size(); i++)
                {
                    if (node->children[i])
                        que.push(node->children[i]);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};