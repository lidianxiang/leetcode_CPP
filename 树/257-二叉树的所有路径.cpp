/*

给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

*/

#include<iostream>
using namespace std;
#include<vector>
#include<queue>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    void construct_paths(TreeNode *root, string path, vector<string> &paths)
    {
        if (root != nullptr)
        {
            path += to_string(root->val);
            if (root->left == nullptr && root->right == nullptr)
            {
                paths.push_back(path);
            }
            else
            {
                path += "->";
                construct_paths(root->left, path, paths);
                construct_paths(root->right, path, paths);
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    /*
        DFS：递归法（回溯）
    */
    {
        vector<string> paths;
        construct_paths(root, "", paths);
        return paths;
    }
};


class Solution2{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    /*
        BFS: 队列
    */
    {
        vector<string> paths;
        if (root == nullptr)
        {
            return paths;
        }

        queue<TreeNode *> node_queue;
        queue<string> path_queue;

        node_queue.push(root);
        path_queue.push(to_string(root->val));

        while (!node_queue.empty())
        {
            TreeNode *node = node_queue.front();
            string path = path_queue.front();
            node_queue.pop();
            path_queue.pop();

            if (node->left == nullptr && node->right == nullptr)
            {
                paths.push_back(path);
            }
            else
            {
                if (node->left != nullptr)
                {
                    node_queue.push(node->left);
                    path_queue.push(path + "->" + to_string(node->left->val));
                }
                if (node->right != nullptr)
                {
                    node_queue.push(node->right);
                    path_queue.push(path + "->" + to_string(node->right->val));
                }
            }
        }
        return paths;
    }
};