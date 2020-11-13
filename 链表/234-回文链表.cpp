/*

请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true

*/


#include <iostream>
using namespace std;
#include <vector>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};


class Solution{
public:
    bool isPalindrome(ListNode* head){
        /*
            先将链表的值转到数组容器中，然后使用双指针来判断是否为回文
        */
        vector<int> vals;
        while(head != nullptr){  
            vals.emplace_back(head->val);  // 使用vector容器来存储链表的值
            head = head->next;
        }

        for(int i=0, j=(int)vals.size()-1; i<j; ++i, --j){  // 双指针
            if(vals[i] != vals[j]){
                return false;
            }
        }
        return true;
    }
}; 