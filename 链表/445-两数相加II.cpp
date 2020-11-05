/*

给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 8 -> 0 -> 7

*/

#include <iostream>
using namespace std;
#include <stack>
#include <stdio.h>


struct ListNode{
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(NULL) {}
};


class Solution{
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2){
        /*
            栈：本题的难点在于链表中数位的顺序与我们做加法的顺序是相反的，为了逆序处理所有的数位，
               可以使用栈，把所有数字压入栈中，在依次取出相加。且计算过程中需要注意进位的情况。
        */
        stack<int> s1, s2;  // 使用两个栈将l1和l2链表的值存储下来
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;  // 进位标志
        ListNode *ans = nullptr;
        while (!s1.empty() or !s2.empty() or carry != 0)
        {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty())
                s1.pop();  // 逐步弹出s1栈中的值
            if (!s2.empty())
                s2.pop(); // 逐步弹出s2栈中的值
            int cur = a + b + carry;  // 弹出的两栈之值与进位之值相加
            carry = cur / 10;
            cur %= 10;
            auto curnode = new ListNode(cur);
            curnode->next = ans;
            ans = curnode;
        }
        return ans;
    }
};