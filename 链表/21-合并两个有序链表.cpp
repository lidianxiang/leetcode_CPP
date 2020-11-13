/*

将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

*/


#include <iostream>
using namespace std;
#include<stdio.h>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};


class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode dummy = ListNode(-1);  // 设置一个哑节点
        ListNode *pre = &dummy;  // 哑节点的指针

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)  // 比较l1和l2的大小
            {
                pre->next = l1;  // 哑节点指向较小的值
                l1 = l1->next;  // l1链表的指针向后移动
            }
            else
            {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        pre->next = l1 == nullptr ? l2 : l1;

        return dummy.next;
    }
};


class Solution2{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        /*
            递归法
        */
        if (l1 == nullptr){  // 当l1不存在的特殊情况
            return l2;
        }else if (l2 == nullptr){ // 当l2不存在的特殊情况
            return l1;
        }else if (l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};


class Solution3{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        /*
            迭代法
        */
        ListNode *preHead = new ListNode(-1);  // 设置一个哑节点

        ListNode *prev = preHead;  // 设置一个指针，初始时也指向哑节点
        while (l1 != nullptr && l2 != nullptr)  // 遍历两个链表
        {
            if (l1->val < l2->val)  // 判断当前两个链表的头节点的大小
            {
                prev->next = l1;  // prev指向较小的那个值
                l1 = l1->next;  // l1链表的头节点向后移动一位
            }
            else
            {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;  // prev指针同时向后移动一位
        }
        prev->next = l1 == nullptr ? l2 : l1;   // 当l1和l2中一个合并完后，prev直接指向另一个不为空的链表即可，因为是有序链表
        return preHead->next;
    }
};