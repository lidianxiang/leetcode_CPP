/*

反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

示例:
输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

*/

#include<iostream>
using namespace std;
#include<stdio.h>


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};


class Solution{
public:
    ListNode* reverseBetween(ListNode *head, int m, int n){
        /*
            双指针法
        */
        if (n == 1 || !head)  // 特殊情况判断
            return head;

        ListNode *prev = NULL, *curr = head;
        while (m > 1)   // 循环后，curr指针指向待反转的头节点，prev为其前继节点，如此时：prev为1，curr为2
        {
            prev = curr;  
            curr = curr->next;
            m--;
            n--;
        }
        ListNode *before = prev, *after = curr;  // 记录下此时的两个节点，因为后续要连接反转部分和反转前与反转后的链表
        while (n > 0)  // 反转部分链表节点
        {
            ListNode *nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
            n--;
        }
        if (before)  // 如果此时的before指针的值存在的情况下
        {
            before->next = prev;  // before指针的下一个节点应该为反转后的头节点，如此时的4
        }
        else
        {
            head = prev;
        }
        after->next = curr;  // after指针的next指向反转部分的第一个不反转的节点，如此时的5
        return head;
    }
};