/*

反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

*/
#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode (int x): val(x), next(NULL){}
};


class Solution{
public:
    ListNode* reverseList(ListNode* head){
        /*
        双指针法：
            1、定义两个指针： pre 和 cur ；pre 在前 cur 在后。
            2、每次让 prepre 的 next 指向 cur ，实现一次局部反转
            3、局部反转完成之后，pre 和 cur 同时往前移动一个位置
            4、循环上述过程，直至 pre 到达链表尾部

        */
        ListNode *cur = NULL, *pre = head;
        while (pre != NULL)
        {
            ListNode *t = pre->next;
            pre->next = cur; // 让pre的next指针指向pre的前一个节点
            cur = pre; // cur指针向前移动
            pre = t;  // pre指针向前移动
        }
        return cur;
    }
};