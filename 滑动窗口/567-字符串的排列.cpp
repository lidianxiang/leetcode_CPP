/*

给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的 子串 。

示例 1：
输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").

示例 2：
输入: s1= "ab" s2 = "eidboaoo"
输出: False

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution {    // 滑动窗口
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m)
            return false;
        
        vector<int> cnt1(26), cnt2(26);
        for(int i=0; i<n; i++){
            ++cnt1[s1[i] - 'a'];
            ++cnt2[s2[i] - 'a'];
        }

        if (cnt1 == cnt2)
            return true;

        for (int i=n; i<m; i++){
            ++cnt2[s2[i] - 'a'];
            --cnt2[s2[i-n] - 'a'];
            if (cnt1 == cnt2)
                return true;
        }
        return false;
    }
};