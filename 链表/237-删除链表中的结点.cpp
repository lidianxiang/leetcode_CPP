/*

请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点。传入函数的唯一参数为 要被删除的节点 。

现有一个链表 -- head = [4,5,1,9]，它可以表示为:

示例 1：

输入：head = [4,5,1,9], node = 5
输出：[4,1,9]
解释：给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
示例 2：

输入：head = [4,5,1,9], node = 1
输出：[4,5,9]
解释：给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.

*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution{
public:
    void deleteNode(ListNode* node){
        
        *node = *(node->next);
        // node->val = node->next->val;
        // node->next = node->next->next;
    }
};

class Solution2{
public:
    bool isPalindrome(ListNode *head){
        /*
        
        快慢指针：
                1、找到前半部分链表的尾节点。
                2、反转后半部分链表。
                3、判断是否回文。
                4、恢复链表。
                5、返回结果。
        
        */
        if (head == nullptr){  // 特殊情况，当链表为空时
            return true;
        }
        // 找到前半部分链表的尾节点并反转后半部分链表
        ListNode *firstHalfEnd = endOfFirstHalf(head);
        ListNode *secondHalfStart = reverseList(firstHalfEnd->next);
        // 判断是否回文
        ListNode *p1 = head;
        ListNode *p2 = secondHalfStart;
        bool result = true;
        while (result && p2 != nullptr)
        {
            if (p1->val != p2->val)
            {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        // 还原链表并返回结果
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
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

    ListNode *endOfFirstHalf(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};