/*

请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

示例 1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

*/


#include<iostream> 
using namespace std;
#include<vector>


class Solution{    // 滑动窗口
public:
    int lengthOfLongestSubstring(stirng s){
        // map统计字符在当前子串出现的次数，字符的ascii码值小于128
        int map[128] = {0}, len = 0, start = 0;
        for(int i=0; i<s.size(); i++){
            ++map[s[i]];
            while(map[s[i]] == 2){  // 出现重复
                --map[s[start++]];  // 不断滑动右移的同时恢复map中的状态，当map[s[i]] == 1时，确定新的start
            }
            len = max(len, i - start + 1);
        }
        return len;
    }
};


class Solution2{   // 滑动窗口  
public:
    int lengthOfLongestSubstring(strign s){
        vector<int> map(128, -1);  // map记录字符在当前子串上次出现的位置
        int len = 0, start = 0;
        for(int i=0; i<s.size(); i++){
            if (map[s[i]] >= start){
                start = map[s[i]] + 1;
            }
            map[s[i]] = i;
            len = max(len, i - start + 1);
        }
        return len;
    }
};