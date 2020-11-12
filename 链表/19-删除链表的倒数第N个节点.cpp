/*

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.

*/

#include <iostream>
using namespace std;
#include <stdio.h>


struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr;) {}
    ListNode(int x):val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(next){}
};


class Solution{
public:
    // 求出链表的长度
    int getLength(ListNode *head)  
    {
        int length = 0;
        while (head)
        {
            ++length;
            head = head->next;
        }
        return length;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 添加一个哑节点，next指针指向head
        ListNode *dummy = new ListNode(0, head);
        int length = getLength(head);
        ListNode *cur = dummy;
        for (int i = 1; i < length - n + 1; ++i)
        {
            cur = cur->next;  // 移动至要删除的节点的前继节点
        }
        cur->next = cur->next->next;  // 删除节点
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};


class Solution2{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        /*
            快慢指针法：
                1、若初始时first指针和second指针均指向head节点，当first指针先对链表遍历，遍历次数为n，
                   则此时first与second间隔了n-1个节点，即first比second超前了n个节点。
                2、同时使first与second对链表进行遍历，当first遍历到链表末尾，则second刚好指向倒数第N个节点
                3、若first初始为head节点，second初始为dummy节点，dummy节点的next指针指向head，则first遍历完时，second刚好指向要删除节点的前继节点
        */
        ListNode *dummy = new ListNode(0, head);
        ListNode *first = head;
        ListNode *second = dummy;
        for (int i = 0; i < n; ++i)
        {
            first = first->next;
        }
        while (first)
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};