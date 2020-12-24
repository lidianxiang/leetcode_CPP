/*

序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

示例: 

你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"

*/

#include<iostream>
using namespace std;
#include<queue>


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(NULL), right(NULL) {}
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)  // BFS
    {
        string res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto *cur = q.front();
                q.pop();
                if (cur == nullptr)
                {
                    res += "nullptr,";
                }
                else
                {
                    string str_val = to_string(cur->val) + ",";
                    res += str_val;
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        stringstream s(data);
        string str_node;
        queue<TreeNode *> q;
        //getline(s, str_node, ",");
        getline(s, str_node, ',');
        TreeNode *root;
        if (str_node == "nullptr")
        {
            return nullptr;
        }
        else
        {
            int inte_node = stoi(str_node);
            root = new TreeNode(inte_node);
            q.push(root);
        }
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                TreeNode *cur = q.front();
                q.pop();
                if (cur != nullptr)
                {
                    string str_left, str_right;
                    if (getline(s, str_left, ',') && str_left != "nullptr")
                    {
                        TreeNode *l = new TreeNode(stoi(str_left));
                        q.push(l);
                        cur->left = l;
                    }
                    if (getline(s, str_right, ',') && str_right != "nullptr")
                    {
                        TreeNode *r = new TreeNode(stoi(str_right));
                        q.push(r);
                        cur->right = r;
                    }
                }
            }
        }
        return root;
    }
};