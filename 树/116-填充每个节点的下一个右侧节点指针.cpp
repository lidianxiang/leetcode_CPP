/*

给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

进阶：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

示例：
         1                      1 -->NULL      
       /   \                  /   \
      2     3                2 --> 3 -->NULL
     / \   / \              / \   / \ 
    4  5  6  7             4->5-->6->7 -->NULL

输入：root = [1,2,3,4,5,6,7]
输出：[1,#,2,3,#,4,5,6,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。

*/

#include<iostream>
using namespace std;
#include<queue>

class Node{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() :val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val): val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next): val(_val), left(_left), right(_right), next(_next) {}
};


class Solution{    // 层次遍历
public:
    Node *connect(Node *root)
    {
        if (!root)
        {
            return root;
        }
        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; ++i)
            {
                Node *node = que.front();
                que.pop();

                if (i < size - 1)
                {
                    node->next = que.front();
                }
                if (node->left != nullptr)
                    que.push(node->left);
                if (node->right != nullptr)
                    que.push(node->right);
            }
        }
        return root;
    }
};


class Solution2{
public:
    Node* connect(Node* root){
        if (root == nullptr)
        {
            return root;
        }

        Node *leftmost = root;
        while (leftmost->left != nullptr)
        {
            Node *head = leftmost;
            while (head != nullptr)
            {
                // 当同为一层且同为一个父节点时
                head->left->next = head->right;
                if (head->next != nullptr)
                {
                    // 当同为一层不同父节点时
                    head->right->next = head->next->left;
                }
                // 节点移动
                head = head->next;
            }
            // 移动到下一层
            leftmost = leftmost->left;
        }
        return root;
    }
};