/*

给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。

示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：
输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：
输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。

*/

#include <iostream>
using namespace std;
#include <unordered_set>
#include <stdio.h>

struct ListNode{
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(NULL) {}
};


class Solution{
public:
    ListNode *deleteCycle(ListNode *head){
        /*
            哈希表：遍历链表中的每个节点，并将其记录下来；一旦遇到了此前遍历过的节点，就可以判定链表中存在环。
        */
        unordered_set<ListNode *> visited;
        while(head != nullptr){
            if(visited.count(head)){
                return head;
            }
            visited.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};


class Solution2{
public:
    ListNode * delelteCycle(ListNode *head){
        /*
            快慢指针：1、两个指针fast和slow，起始与链表头部，slow每次移动一步，fast每次移动两步，如果链表有环，fast与slow指针会在环中相遇
                    2、fast与slow相遇的结点命名为ptr，ptr继续每次移动一步，slow指针再从相遇的结点出继续移动，当ptr和slow指针相遇的结点，即所得答案。
        */
        ListNode *slow = head; 
        ListNode *fast = head;
        while(fast != nullptr){
            slow = slow->next;
            // 因为fast指针会走两步，所以要提前判断一下fast->next指针是否存在
            if(fast->next == nullptr){
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow){
                ListNode * ptr = head;
                while(ptr != slow){
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};