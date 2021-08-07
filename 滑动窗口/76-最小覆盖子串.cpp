/*

给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

示例 1：
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"

示例 2：
输入：s = "a", t = "a"
输出："a"

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution {    // 滑动窗口
public:
    string minWindow(string s, string t) {
        vector<int> map(128);
        // need表示还差多少个字符即可覆盖字符串t
        int left = 0, right = 0, need = t.size(), minStart = 0, minLen = INT_MAX;
        for(char ch: t){
            ++map[ch];   // 统计t中出现的字符的次数
        }

        while(right < s.size()){
            if (map[s[right]] > 0)   // 窗口右移，每包含一个t中的字符，need-1
                --need;
            --map[s[right]];
            ++right;
            while(need == 0){    // 完全覆盖子串时
                if (right - left < minLen){   // 此时字符被包含在[left, right)中
                    minStart = left;
                    minLen = right - left;
                }
                if (++map[s[left]] > 0)    // 窗口左移
                    ++need;
                ++left;   
            }
        }
        if (minLen != INT_MAX)
            return s.substr(minStart, minLen);
        return "";
    }
};