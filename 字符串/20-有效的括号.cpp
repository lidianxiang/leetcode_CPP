/*

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true

*/


#include<iostream>
using namespace std;
#include<stack>
#include<unordered_map>


class Solution{   // 栈
public:
    bool isValid(string s){
        int n = s.size();
        if (n % 2 == 1)
        {
            return false;
        }
        // 映射
        unordered_map<char, char> pairs = {
            {'}', '{'},
            {']', '['},
            {')', '('}};

        stack<char> stk;
        // 遍历
        for (char ch : s)
        {
            if (pairs.count(ch))
            {   
                // 当栈为空，或者栈的最上面的字符与字符在字典中的映射不对应的话，返回false
                if (stk.empty() || stk.top() != pairs[ch])
                {
                    return false;
                }
                stk.pop();  // 否则弹出栈中的字符
            }
            else
            {
                stk.push(ch); // 否则将字符压入栈中
            }
        }
        return stk.empty();  // 判断栈里是否为空
    }
};