/*

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

*/

#include <iostream>
using namespace std;
#include <stdio.h>


struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution{
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2){
        /*
            模拟法：由于输入的两个链表都是逆序存储数字的位数，因此两个链表中同一位置的数字可以直接相加。
                   同时遍历两个链表，逐位计算他们的和，并与当前位置的进位相加。
        */
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2)
        {
            int n1 = l1 ? l1->val : 0;  // 计算l1链表当前值
            int n2 = l2 ? l2->val : 0;  // 计算l2链表当前值
            int sum = n1 + n2 + carry;  // 两者相加，再与carry进位相加，得到当前总和
            if (!head)  // 刚开始时
            {
                head = tail = new ListNode(sum % 10);  // head指针和tail指针同时指向sum对10求余的数
            }
            else
            {
                tail->next = new ListNode(sum % 10);  // tail的next指针指向sum对10求余的数
                tail = tail->next;  // tail指针向后移动
            }
            carry = sum / 10; // 进位值
            if (l1)
            {
                l1 = l1->next;  // l1链表向后移动一位
            }
            if (l2)
            {
                l2 = l2->next;  // l2链表向后移动一位
            }
        }
        if (carry > 0)  // 如果最后一位相加后，仍然存在进位
        {
            tail->next = new ListNode(carry);  // 在链表的最后new一个新的结点
        }
        return head;
    }
}