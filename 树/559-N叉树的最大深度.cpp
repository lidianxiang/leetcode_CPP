/*

给定一个 N 叉树，找到其最大深度。

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

例如，给定一个 3叉树 :

        1
      / |  |
    3   2   4
  /  |
 5   6

我们应返回其最大深度，3。

*/

#include<iostream>
using namespace std;
#include<vector>
#include<stack>
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
    int maxDepth(Node* root){
        if (!root)
            return 0;
        int m = 0;
        for (Node* it:root->children){
            m = max(m, maxDepth(it));
        }
        return m+1;
    }
};


class Solution2{
public:
    int maxDepth(Node* root){
        /*
            DFS迭代
        */
        if (!root)
            return 0;

        stack<pair<Node *, int>> stack;
        stack.push(pair<Node *, int>(root, 1));
        int max_depth = 0;
        while (!stack.empty())
        {
            Node *node = stack.top().first;
            int depth = stack.top().second;
            stack.pop();
            for (Node *it : node->children)
            {
                stack.push(pair<Node *, int>(it, depth + 1));
            }
            max_depth = max(depth, max_depth);
        }
        return max_depth;
    }
};


class Solution3{
public:
    int maxDepth(Node* root){
        /*
            BFS迭代
        */
        if (!root)
            return 0;

        queue<Node *> queue;
        queue.push(root);
        int max_depth = 0;
        while (!queue.empty())
        {
            max_depth++;
            for (int size = queue.size(); size; size--)
            {
                Node *curr = queue.front();
                queue.pop();
                for (Node *it : curr->children){
                    queue.push(it);
                }
            }
        }
        return max_depth;
    }
};