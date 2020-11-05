/*

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]

*/

#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <stack>


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};


class Solution{
public:
    vector<int> reversePrint(ListNode* head){
        /*
            reverse反转法
        */
        vector<int> res;
        while(head != NULL){
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


class Solution2{
public:
    vector<int> reversePrint(ListNode* head){
        vector<int> res;
        stack<int> s;
        while(head != NULL){  // 入栈
            s.push(head->val);
            head = head->next;
        }

        while(!s.empty()){  // 出栈
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};


class Solution3{
public:
    vector<int> reversePrint(ListNode* head){
        /*
            递归法
        */
        vector<int> res;
        if (head == nullptr){
            return res;
        }
        res = reversePrint(head->next);
        res.push_back(head->val);
        return res;
    }
};


class Solution4{
public:
    vector<int> reversePrint(ListNode* head){
        /*
            改变链表的结构
        */
        vector<int> res;
        ListNode *pre = nullptr;
        ListNode *next = head;
        ListNode *cur = head;
        while (cur)
        {
            next = cur->next; //保存当前结点的下一个节点
            cur->next = pre;  //当前结点指向前一个节点，反向改变指针
            pre = cur;        //更新前一个节点
            cur = next;       //更新当前结点
        }
        while (pre)
        { // 上一个while循环结束后，pre指向新的链表头
            res.push_back(pre->val);
            pre = pre->next;
        }
        return res;
    }
};