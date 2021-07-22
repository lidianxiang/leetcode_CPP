/*

给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

整数除法仅保留整数部分。

示例 1：
输入：s = "3+2*2"
输出：7

示例 2：
输入：s = " 3/2 "
输出：1

示例 3：
输入：s = " 3+5 / 2 "
输出：5

*/

#include<iostream>
using namespace std;
#include<vector>


class Solution {   // 栈
public:
    int calculate(string s) {
        vector<int> stk;
        char preSign = '+';
        int num = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            // 当前数为数字时
            if (isdigit(s[i])){
                num = num * 10 + int(s[i] - '0');
            }
            // 当前数不为数字也不为空格时
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1 ){
                switch (preSign){
                    // 加号压入栈
                    case '+':
                        stk.push_back(num);
                        break;
                    // 减号将相反数压入栈
                    case '-':
                        stk.push_back(-num);
                        break;
                    // 乘号与栈顶元素相结合
                    case '*':
                        stk.back() *= num;
                        break;
                    // 除号与栈顶元素相结合
                    default:
                        stk.back() /= num;
                }
                // 更新preSign
                preSign = s[i];
                // num重新置为0
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};