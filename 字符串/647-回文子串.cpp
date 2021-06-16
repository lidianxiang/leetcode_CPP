/*

给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

示例 1：
输入："abc"
输出：3
解释：三个回文子串: "a", "b", "c"

示例 2：
输入："aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"

*/


#include<iostream>
using namespace std;


class Solution{      // 中心扩散法
public:
    int countSubstring(string s){
        int n = s.size(), ans = 0;
        for(int i=0; i < 2*n-1; ++i){
            int left=i/2, right = i/2 + i%2;
            while(left>=0 && right<n && s[left] == s[right]){
                --left;
                ++right;
                ++ans;
            }
        }
        return ans;
    }
};