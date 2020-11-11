/*

给出一个以头节点 head 作为第一个节点的链表。链表中的节点分别编号为：node_1, node_2, node_3, ... 。

每个节点都可能有下一个更大值（next larger value）：对于 node_i，如果其 next_larger(node_i) 是 node_j.val，那么就有 j > i 且  node_j.val > node_i.val，而 j 是可能的选项中最小的那个。如果不存在这样的 j，那么下一个更大值为 0 。

返回整数答案数组 answer，其中 answer[i] = next_larger(node_{i+1}) 。

示例 1：
输入：[2,1,5]
输出：[5,5,0]

示例 2：
输入：[2,7,4,3,5]
输出：[7,0,5,5,0]

示例 3：
输入：[1,7,5,1,9,2,5,1]
输出：[7,9,9,9,0,5,0,0]

*/

#include <iostream>
using namespace std;
#include <stdio.h>
#include <vector>
#include <stack>


struct ListNode{
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(NULL){}
};


class Solution{
public:
    vector<int> nextLargerNodes(ListNode *head){
        /*
            思路： 使用栈来存储链表信息
        */
        int count = 0;  // 计数
        vector<int> result;  // 结果
        stack<pair<int, int>> tmp;  // first为链表的val值，second为链表的下标
        while (head)
        {
            result.push_back(0);  // 初始化为0
            // 当stack不为空，且链表中的值大于stack中的值
            while (!tmp.empty() && head->val > tmp.top().first)
            {
                // result保存链表的值
                result[tmp.top().second] = head->val;
                // stack中弹出值
                tmp.pop();
            }
            // 如果stack为空，又或者链表此时的值小于stack中的值
            tmp.push(make_pair(head->val, count++));
            head = head->next;
        }
        return result;
    }
};

class Solution2{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        stack<int> nodes;
        stack<int> stk;
        int length = 0;
        // 第一遍遍历链表， 用栈nodes来存储链表的数值与长度
        while (head)
        {
            nodes.push(head->val);
            head = head->next;
            length++;
        }
        vector<int> result(length);  // 保存结果
        while (!nodes.empty())
        {
            int node = nodes.top();  
            nodes.pop(); // 弹出首个nodes中的值
            while (!stk.empty() && node >= stk.top())  // 当stk不为空且nodes中的node值大于stk中的值时
            {
                stk.pop();  // 弹出此时stk中的值
            }
            // 从大到小保存至result中
            result[--length] = stk.empty() ? 0 : stk.top();
            stk.push(node);
        }
        return result;
    }
};
