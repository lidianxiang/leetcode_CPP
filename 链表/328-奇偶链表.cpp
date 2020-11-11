/*

给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:

输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
示例 2:

输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL

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
    ListNode* oddEvenList(ListNode *head){
        /*
            双指针法：奇节点放在一个链表中，偶节点放在另一个链表中，然后将偶链表放在奇链表的后面
        */
        if (head == nullptr)
            return nullptr;
        ListNode *odd = head, *even = head->next, *evenHead = even;
        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;  // 奇指针跳着指向下下一个节点
            odd = odd->next;         // 奇指针向后移动
            even->next = odd->next;  // 偶指针跳到下下一个节点
            even = even->next;       // 偶指针向后移动
        }
        odd->next = evenHead;        // 奇指针末尾连接偶指针
        return head;
    }
};