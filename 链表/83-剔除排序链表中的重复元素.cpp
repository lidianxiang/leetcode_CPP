/*

给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3

*/

#include <stdio.h>


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};


class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        /*
            双指针
        */
        if (head == NULL || head->next == NULL){
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while(slow->next != NULL){
            if (fast->val == slow->val){   // 当快指针的值与慢指针的值相等的情况
                if (fast->next == NULL){   // 当快指针的next指针指向null的情况（快指针走到了最后一个结点）
                    slow->next == NULL;
                }
                else{
                    slow->next = fast->next;   // slow指针删除掉重复的元素
                    fast = fast->next;
                }
            }
            else{  // 当快指针的值与慢指针的值不相等的情况
                fast = fast->next;
                slow = slow->next;
            }
        }
        return head;
    }
};


class Solution{
public:
    ListNode* deleteDuplicate(ListNode* head){
        /*
            单指针法
        */
        if(!head || !head->next)
            return head;

        ListNode* p = head;
        while(p->next != NULL && p != NULL){
            if (p->val == p->next->val){
                p->next = p->next->next;
            }
            else{
                p = p->next;
            }
        }
        return head;
    }
};


class Solution{
public:
    ListNode* deleteDuplicate(ListNode* head){
        /*
            递归法
        */

        if (!head || !head->next)
            return head;

        head->next = deleteDuplicate(head->next);
        if (head->val == head->next->val)
            head = head->next;
        return head;
    }
};