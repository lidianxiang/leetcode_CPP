/*

输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。

示例：

给定一个链表: 1->2->3->4->5, 和 k = 2.

返回链表 4->5.

*/


#include <iostream>
using namespace std;


struct ListNode{
    int val;
    ListNode *next;
};


class Solution{
public:
    ListNode* getKthFromEnd(ListNode* head, int k){
        /*
        快慢指针：
            1、定义两个指针，快指针fast，慢指针slow
            2、让fast先向前移动k个位置，然后low和fast再一起向前移动
            3、当fast达到链表尾部，返回slow
        */
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL){
            fast = fast->next;
            if (k == 0){
                slow = slow->next;
            }
            else{
                k--;
            }
        }
        return slow;
    }
};