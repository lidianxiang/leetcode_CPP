/*

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
示例 4:

输入: s = ""
输出: 0

*/


#include<iostream>
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<string>


class Solution{
public:
    int lengthOfLongestSubstring(string s){
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为-1， 相当于在字符串左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        for (int i = 0; i < n; ++i){
            if (i != 0){
                occ.erase(s[i - 1]);
            }
            // 当没有出现重复字符时，记录下来
            while (rk + 1 < n && !occ.count(s[rk + 1])){
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};


class Solution2{   // 滑动窗口（双指针）
public:
    int lengthOfLongestSubstring(string s){
        // 双指针start和end
        int start(0), end(0), length(0), res(0);
        int size = s.size();
        while (end < size)
        {
            char tmp = s[end];
            for (int i = start; i < end; i++)
            {
                if (tmp == s[i])   // 当右指针的值出现在之前的数组中时
                {
                    start = i + 1;  // 左指针跳到出现的值的下一个位置
                    length = end - start;   // 更新最大长度
                    break;  
                }  
            }
            // 否则（右指针的值未出现在之前的数组中）
            ++end;  // 更新右指针
            ++length; // 更新最大长度
            res = max(res, length);  // 更新最后的结果
        }
        return res;
    }
};


class Solution3{    // 滑动窗口+hashmap优化
public:
    int lengthOfLongestSubstring(string s){
        int start(0), end(0), length(0), res(0);
        int size = s.size();
        unordered_map<char, int> hash;
        while (end < size)
        {
            char tmp = s[end];
            if (hash.find(tmp) != hash.end() && hash[tmp] >= start)
            {
                start = hash[tmp] + 1;
                length = end - start;
            }
            hash[tmp] = end;

            end++;
            length++;
            res = max(res, length);
        }
        return res;
    }
};