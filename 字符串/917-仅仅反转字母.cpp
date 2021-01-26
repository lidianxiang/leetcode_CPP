/*

给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

示例 1：

输入："ab-cd"
输出："dc-ba"
示例 2：

输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"
示例 3：

输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"

*/

#include<iostream>
using namespace std;


class Solution{     // 双指针
public:
    string reverseOnlyLetters(string S){
        int left = 0, right = S.size();
        while(left < right){
            if (isalpha(S[left]) && isalpha(S[right])){
                swap(S[left], S[right]);
                ++left;
                --right;
            }
            else if(!isalpha(S[left])){
                ++left;
            }
            else if (!isalpha(S[right])){
                --right;
            }
        }
        return S;
    }
};