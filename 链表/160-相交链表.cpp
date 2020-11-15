/*

编写一个程序，找到两个单链表相交的起始节点。

示例 1：
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

*/

#include <stdio.h>
#include <unordered_set>
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};


class Solution{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
        /*
            双指针法：
                    1、A的指针遍历完A，接着从headB开始遍历
                    2、B的指针遍历完B，接着从headA开始遍历
                    两个指针都都最多走 m + n。
        */
        if (headA == nullptr || headB == nullptr){
            return nullptr;
        }

        ListNode* cur_a = headA;
        ListNode* cur_b = headB;

        while(cur_a != cur_b){
            cur_a = (cur_a? cur_a->next: headB);
            cur_b = (cur_b? cur_b->next: headA);
        }
        return cur_a;
    }
};


class Solution{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
        /*
            哈希表法：使用一个hashset遍历链表，hashset中存放其所有指针，遍历另一个链表，去hashset中去寻找相同的指针。
        */
        std::unordered_set<ListNode* > set;  // 使用hashset来保存A链表的所有指针
        ListNode* cur_a = headA;
        ListNode* cur_b = headB;

        while(cur_a){
            set.insert(cur_a);
            cur_a = cur_a->next;
        }

        while(cur_b){
            if (set.find(cur_b) != set.end()){  // 找到了
                return cur_b;
            }
            cur_b = cur_b->next;
        }
        return nullptr;   // 没有找到，返回空
    }
};