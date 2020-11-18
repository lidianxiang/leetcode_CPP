/*

给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

示例：
给你这个链表：1->2->3->4->5
当 k = 2 时，应当返回: 2->1->4->3->5
当 k = 3 时，应当返回: 3->2->1->4->5

*/

#include<iostream>
using namespace std;
#include<stdio.h>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};


class Solution{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(-1); // 哑节点
        dummy->next = head;

        ListNode *pre = dummy; // 待翻转链表的前驱
        ListNode *end = dummy; // 待翻转链表的末尾

        while (end->next != nullptr)
        {
            for (int i = 0; i < k && end != nullptr; ++i)
                end = end->next; // end前进k步
            if (end == nullptr)
                break;
            ListNode *start = pre->next; // 待翻转链表部分的头节点
            ListNode *next = end->next;  // 未翻转链表部分的头节点
            end->next = nullptr;         // 断开待翻转与未翻转部分
            pre->next = reverse(start);  // 翻转，并将已翻转与翻转后的头节点相连
            start->next = next;          // 将翻转后的尾节点与为翻转部分相连
            pre = start;                 // pre指针跳k步
            end = pre;                   // end指针同时跳k步
        }
        return dummy->next;
    }

    // 反转链表代码
    ListNode *reverse(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
};