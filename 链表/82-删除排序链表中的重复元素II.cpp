/*

给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3

*/

#include <iostream>
using namespace std;
#include <stdio.h>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        /*
            双指针法
        */
        if (!head || !head->next)
            return head;
        ListNode *dummy = new ListNode(-1);  // 哑节点
        dummy->next = head;
        ListNode *prev = dummy;

        while (prev && prev->next)
        {
            ListNode *curr = prev->next;
            // 如果curr到最后一位了或者当前curr所指向的元素与后一位不重复
            if (!curr->next || curr->next->val != curr->val)
                prev = curr;  // prev指向向前移动一位
            else
            {
                // 当curr不是最后一位或者curr与后一位元素一样
                while (curr->next && curr->val == curr->next->val)
                    curr = curr->next;  // curr指针向前移动一位
                prev->next = curr->next;   // prev指针跳过当前结点
            }
        }
        return dummy->next;
    }
};


class Solution2{
public:
    ListNode* deleteDuplicates(ListNode* head){
        /*
            递归法
        */
        if (!head || !head->next)
            return head;
        if (head->next->val != head->val)
        {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        else
        {
            ListNode *curr = head;
            while (curr->next && curr->next->val == curr->val)
                curr = curr->next;
            return deleteDuplicates(curr->next);
        }
    }
};