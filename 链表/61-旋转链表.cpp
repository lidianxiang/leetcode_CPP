/*

给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL

*/

#include <iostream>
using namespace std;
#include <stdio.h>


struct ListNode{
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(NULL){}
};


class Solution{
public:
    ListNode* rotateRight(ListNode* head, int k){
        /*
            双指针法：
                1、先让快指针走 k 个位置，然后两个指针一起走完整个链表。
                2、两个指针之间的区域就是需要改变的地方
                    即，first->next 指向 head，完成旋转（当然还没完事）；
                    head 指向 second->next，头结点指向确认；
                    second->next 指向空节点，尾结点指向确认；

        */
        if (!head) return NULL;

        int n = 0; 
        for(auto p=head; p; p=p->next) n++;  // 求出链表的长度

        k = k % n;  // k对n求余，防止重复走多遍
        auto first = head, second = head;
        while(k--){  // first指针先移动k步
            first = first->next;
        }

        while(first->next){  // 第二次，first和second同时移动，直至first走到尾部
            first = first->next;
            second = second->next;
        }

        first->next = head;
        head = second->next;
        second->next = NULL;
        return head;

    }
};


class Solution2{
public:
    ListNode* rotateRight(ListNode* head, int k){
        /*
            1、先将链表闭合成环
            2、找到相应的位置，断开这个环，确定新的链表的头和尾
        */
        if (!head || !head->next || k==0)
            return head; // 特殊情况先行判断

        ListNode *pos = head;
        int n = 1;  // 求出链表的长度
        while(pos && pos->next){
            pos = pos->next;
            n++;
        }

        int move = k % n;  // 实际要移动的步数
        if (move == 0) return head;

        ListNode *tail = head;
        for(int i=0; i<n - move -1; i++){
            tail = tail->next;  // 转换后的新链表的尾部
        }
        ListNode *newHead = tail->next; // 新链表的头
        tail->next = nullptr; // 尾部指向空指针，断开环形链表
        pos->next = head;  // 原来的链表的尾部是原来的链表的头进行连接
        return newHead;
    }
};