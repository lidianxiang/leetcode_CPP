/*

给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:
输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

*/

#include<iostream>
using namespace std;
#include<stdio.h>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};


class Solution{
public:
    ListNode* partition(ListNode *head, int x){
        /*
            双指针法：使用两个指针before和after来追踪链表，将小于x的节点使用before连接，
                    大于等于x的节点使用after连接，最后将before和after进行连接。
        
        */
        if (!head || !head->next)
            return head;

        ListNode *before_head = new ListNode(-1);
        ListNode *before = before_head;
        ListNode *after_head = new ListNode(-1);
        ListNode *after = after_head;

        while (head)
        {
            if (head->val < x)
            {
                before->next = head;
                before = before->next;
            }
            else
            {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        after->next = nullptr;
        before->next = after_head->next;
        return before_head->next;
    }
};