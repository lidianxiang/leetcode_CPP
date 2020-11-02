/*

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]

示例 2：
输入：head = []
输出：[]

示例 3：
输入：head = [1]
输出：[1]

*/


struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution{
public:
    ListNode* swapPairs(ListNode* head){
        /*
            递归： 用 head 表示原始链表的头节点，新的链表的第二个节点，用 newHead 表示新的链表的头节点，
                  原始链表的第二个节点，则原始链表中的其余节点的头节点是 newHead.next。
                  令 head.next = swapPairs(newHead.next)，表示将其余节点进行两两交换，
                  交换后的新的头节点为 head 的下一个节点。然后令 newHead.next = head，
                  即完成了所有节点的交换。最后返回新的链表的头节点 newHead。

        */
        // 这个是递归的结束条件，建议放在最前面
        if (head == nullptr || head->next == nullptr) // 当链表不存在或是链表只有一个数的情况
        {
            return head;  // 不需要比较，直接返回
        }
        ListNode *newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};



class Solution2{
public:
    ListNode* swapPairs(ListNode* head){
        /*
            迭代法：https://leetcode-cn.com/problems/swap-nodes-in-pairs/solution/liang-liang-jiao-huan-lian-biao-zhong-de-jie-di-91/
        */
        ListNode *dummyHead = new ListNode(0);  // 创建一个哑节点
        dummyHead->next = head;  // 哑节点的next指针指向head节点
        ListNode *temp = dummyHead;  // 创建一个临时节点
        while (temp->next != nullptr && temp->next->next != nullptr)
        {
            // 获得temp节点的后面两个节点，初始关系是：temp -> node1 -> node2
            ListNode *node1 = temp->next;  
            ListNode *node2 = temp->next->next;  
            // 转换3个节点的关系，变化后为：temp -> node2 -> node1
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            // 将temp指向下一个node1节点
            temp = node1;
        }
        return dummyHead->next;
    }
};