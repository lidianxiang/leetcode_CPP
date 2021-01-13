/*

给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

示例:

输入: s = "abcdefg", k = 2
输出: "bacdfeg"

*/


#include<iostream>
using namespace std;
#include<algorithm>

class Solution{
public:
    string reverseStr(string s, int k){
        int len = s.length();
        for(int start=0; start<len; start += 2*k){   // 每2k个字符为一段
            int i = start;
            int j = min(start+k-1, len-1);  // 判断剩余字符不足k的情况
            while(i<j){
                swap(s[i++], s[j--]);     // 反转区间内的字符
            }
        }
        return s;
    }
};