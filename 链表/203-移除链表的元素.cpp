/*

删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5

*/
#include <stdio.h>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
        /*
            哨兵节点：此处的作用是伪头
        */
        ListNode *sentinel = new ListNode(0);  // 哨兵结点
        sentinel->next = head;  // 指向头结点
        // 初始化两个指针prev和curr，指向当前结点和前继结点
        ListNode *prev = sentinel, *curr = head, *toDelete = nullptr;
        while (curr != nullptr)
        {
            if (curr->val == val)  // 当当前结点的值等于要移除的数组时
            {
                prev->next = curr->next;  // 前继结点的next指针指向当前结点的next指针
                toDelete = curr;  // 要删除的结点赋值给toDelete
            }
            else
            {
                prev = curr; // 若当前结点的值不等于val时，前继结点向前移动一位
            }

            curr = curr->next;  // 不论什么情况，当前结点都向前移动一位

            // 删除要删除的结点
            if (toDelete != nullptr)
            {
                delete toDelete;
                toDelete = nullptr;
            }
        }
        // 删除完指定结点后的ret，指向哨兵结点的next指针
        ListNode *ret = sentinel->next;
        // 哨兵结点的使命已完成，删除掉哨兵结点
        delete sentinel;
        return ret;
    }
};