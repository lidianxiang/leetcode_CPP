/*

给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

示例 1：
输入：head = [4,2,1,3]
输出：[1,2,3,4]

示例 2：
输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]

示例 3：

输入：head = []
输出：[]

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
    ListNode* sortList(ListNode *head){
        /*
            思路：
                1、 使用快慢指针法求出链表的中点
                2、 归并法进行两路归并，使用时间复杂度为 O(nlogn)
        */
        if (head == NULL || head->next == NULL){
            return head;
        }
        ListNode *pmid;        // 链表中点的前继节点
        ListNode *slow = head; // 链表中点
        ListNode *fast = head;
        // 快慢指针找中点
        while (fast && fast->next)
        {
            pmid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pmid->next = NULL; // 将链表断成两个
        return twoWayMerge(sortList(head), sortList(slow));
    }

    // 递归法归并链表排序
    ListNode *twoWayMerge(ListNode *l1, ListNode *l2){
        ListNode header(-1);
        ListNode *p = &header;
        while (l1 && l2){
            if (l1->val < l2->val){
                p->next = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 == NULL ? l2 : l1;
        return header.next;
    }
};