/*

给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。

示例 1：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6

示例 2：
输入：lists = []
输出：[]

示例 3：
输入：lists = [[]]
输出：[]

*/

#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
#include<queue>


struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    struct cmp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists){
        /*
            优先队列：让每个链表的头部进入优先队列
        */
        priority_queue<ListNode *, vector<ListNode *>, cmp> pri_queue;
        for (auto elem : lists)
        {
            if (elem)
                pri_queue.push(elem);
        }

        ListNode dummy(-1);
        ListNode *p = &dummy;
        while (!pri_queue.empty())
        {
            ListNode *top = pri_queue.top();
            pri_queue.pop();
            p->next = top;
            p = top;
            if (top->next)
                pri_queue.push(top->next);
        }
        return dummy.next;
    }
};


class Solution2{
public:
    /*
        分治合并：
                1、K个链表两两配对，进行第一轮合并，结束后k个链表合并为k/2个链表
                2、k/2个链表依然两两配对，进行第二轮合并，结束后k/2个链表合并为k/4个链表
                3、重复上述过程，进行log(k)次合并
    */
    ListNode *merge(ListNode *p1, ListNode *p2)
    {
        if (!p1)
            return p2;
        if (!p2)
            return p1;
        if (p1->val < p2->val)
        {
            p1->next = merge(p1->next, p2);
            return p1;
        }
        else
        {
            p2->next = merge(p1, p2->next);
            return p2;
        }
    }

    ListNode *merge(vector<ListNode *> &lists, int start, int end)
    {
        if (start == end)
            return lists[start];
        int mid = (start + end) / 2;
        ListNode *l1 = merge(lists, start, mid);
        ListNode *l2 = merge(lists, mid + 1, end);
        return merge(l1, l2);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }
};