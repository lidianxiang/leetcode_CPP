/*

实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1

*/

#include <iostream>
using namespace std;
#include<vector>

class Solution     // KMP算法：当出现字符串不匹配时，可以记录一部分之前已经匹配的文本内容，利用这些信息避免从头再去做匹配
{
public:
    void getNext(int *next, const string &s)   // 获取next数组：记录模式串与文本串不匹配时，模式串应该从哪里开始重新匹配
    {
        int j = 0;
        next[0] = 0;  // 初始化next
        for (int i = 1; i < s.size(); i++)   // 遍历模式串
        {
            while (j > 0 && s[i] != s[j])  // 当前后缀不相同的情况
            {
                j = next[j - 1];   // 回溯
            }
            if (s[i] == s[j])  // 当前后缀相同的情况
            {
                j++;   // 前进一位
            }
            next[i] = j; // 将j（前缀的长度）赋给next[i]
        }
    }

    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)  // 当模式串为空，直接返回0
        {
            return 0;
        }
        int next[needle.size()];  // 提前定义next数组的容量
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++)  // 遍历字符串
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])  //当两者相同时，j指针向后移动一位
            {
                j++;
            }
            if (j == needle.size())
            {
                return (i - needle.size() + 1);
            }
        }
        return -1;   // 如果最终不匹配，返回-1
    }
};

class Solution2{    // 另外一种KMP写法
public:
    vector<int> getNext(string str){
        int len = str.size();
        vector<int> next;
        next.push_back(-1);
        int j = 0, k = -1;
        while (j < len - 1){
            if (k == -1 || str[j] == str[k])
            {
                j++;
                k++;
                next.push_back(k);
            }
            else
            {
                k = next[k];
            }
        }
        return next;
    }

    int strStr(string haystack, string needle){
        if (needle.empty()){
            return 0;
        }

        int i = 0;
        int j = 0;
        int len1 = haystack.size();
        int len2 = needle.size();
        vector<int> next;
        next = getNext(needle);
        while (i < len1 && j < len2){
            if ((j == -1) || (haystack[i] == needle[j])){
                i++;
                j++;
            }
            else{
                j = next[j];
            }
        }
        if (j == len2){
            return i - j;
        }
        return -1;
    }
};