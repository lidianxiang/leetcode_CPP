/*

返回与给定的前序和后序遍历匹配的任何二叉树。

pre 和 post 遍历中的值是不同的正整数。

示例：

输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
输出：[1,2,3,4,5,6,7]

*/

#include<iostream>
using namespace std;
#include<vector>


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(NULL), right(NULL) {}
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode*right):val(x), left(left), right(right) {}
};


class Solution{
    /*
    递归法：

        后序遍历中，我们知道 
                左子树：[post_start,index], 右子树：[index+1, post_end-1]
        在前序遍历中，
                左子树起始位置为pre_start+1,左子树个数一共有(index - post_start)个，
        因此左子树：
                [pre_start+1, pre_start+1 + (index - post_start)]
        右子树起始位置为左子树终止位置+1，终止位置为pre_end，
        因此右子树：
                [ pre_start+1 + (index - post_start) + 1, pre_end]
    */

public:
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
    {
        return helper(pre, post, 0, pre.size() - 1, 0, post.size() - 1);
    }

    TreeNode *helper(vector<int> &pre, vector<int> &post, int pre_start, int pre_end, int post_start, int post_end)
    {
        if (pre_start > pre_end || post_start > post_end)
            return NULL;
        TreeNode *root = new TreeNode(pre[pre_start]);
        if (pre_start == pre_end)
            return root;

        int index = post_start;
        while (pre[pre_start + 1] != post[index])
        {
            index++;
        }
        root->left = helper(pre, post, pre_start + 1, pre_start + 1 + index - post_start, post_start, index);
        root->right = helper(pre, post, pre_start + 1 + 1 + index - post_start, pre_end, index + 1, post_end - 1);
        return root;
    }
};