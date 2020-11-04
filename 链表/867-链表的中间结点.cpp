/*

给定一个头结点为 head 的非空单链表，返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。

示例 1：

输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
示例 2：

输入：[1,2,3,4,5,6]
输出：此列表中的结点 4 (序列化形式：[4,5,6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。

*/

#include <stdio.h>
#include <vector>


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};


class Solution{
public:
    ListNode* middleNode(ListNode* head){
        /*
            数组法：把链表的值保存至数组中
        */
        vector<ListNode*> A = {head};
        while(A.back()->next != NULL){
            A.push_back(A.back()->next);
        }
        return A[A.size() / 2];
    }
};


class Solution2{
public:
    ListNode* middleNode(ListNode* head){
        /*
            单指针法：遍历数组求的数组的长度，然后再次遍历数组至长度的二分之一处即可
        */
        int n = 0;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            ++n;
            cur = cur->next;
        }

        int k = 0;
        cur = head;
        while (k < n / 2)
        {
            ++k;
            cur = cur->next;
        }
        return cur;
    }
};


class Solution3{
public:
    ListNode* middleNode(ListNode* head){
        /*
            快慢指针法
        */
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};