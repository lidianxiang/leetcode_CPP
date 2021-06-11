/*

给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

示例 1：
输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"

示例 2：
输入：s = ")()())"
输出：4
解释：最长有效括号子串是 "()()"

示例 3：
输入：s = ""
输出：0

*/


#include<iostream>
using namespace std;


class Solution{    // 栈
public:
    int longestValidParentheses(string s){
        int maxans = 0;
        stack<int> stk;
        stk.push(-1);
        for(int i=0; i<s.length(); i++){
            if (s[i] == '('){
                stk.push(i);
            }else{
                stk.pop();
                if (stk.empty()){
                    stk.push(i);
                }else{
                    maxans = max(maxans, i -stk.top());
                }
            }
        }
        return maxans;
    }
};


class Solution2{   // 动态规划
public:
    int longestValidParentheses(string s){
        int maxans = 0, n = s.length();
        vector<int> dp(n, 0);
        for(int i=1; i<n; i++){
            if (s[i] == ')'){
                if (s[i-1] == '('){
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                }else if (i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '('){
                    dp[i] = dp[i-1] + ((i - dp[i-1]) >= 2 ? dp[i - dp[i-1] - 2] : 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};