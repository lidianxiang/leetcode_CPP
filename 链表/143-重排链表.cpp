/*

给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

*/

#include <iostream>
using namespace std;
#include <vector>
#include <stdio.h>


struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};


class Solution{
public:
    void reorderList(ListNode* head){
        /*
            线性表：利用线性表存储该链表，然后利用线性表的下标访问特点直接指定元素顺序
        */
        if (head == nullptr){
            return;
        }
        vector<ListNode *> vec;
        ListNode* node = head;
        while(node){
            vec.emplace_back(node);
            node = node->next;
        }
        int i=0, j=vec.size()-1;
        while(i<j){
            vec[i]->next = vec[j];
            i++;
            if(i == j){
                break;
            }
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next = nullptr;
    }
};


class Solution2{
public:
    /*
        寻找链表中点 + 链表逆序 + 合并链表
    */
    void reorderList(ListNode* head)
    {
        if (head == nullptr)
            return;

        ListNode *mid = middleNode(head);
        ListNode *l1 = head;
        ListNode *l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }

    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    void mergeList(ListNode *l1, ListNode *l2)
    {
        ListNode *l1_tmp;
        ListNode *l2_tmp;
        while (l1 != nullptr && l2 != nullptr)
        {
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
    }
};