/*

给定一个字符串 s，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。

重复出现的子串要计算它们出现的次数。

示例 1 :

输入: "00110011"
输出: 6
解释: 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。

请注意，一些重复出现的子串要计算它们出现的次数。

另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。
示例 2 :

输入: "10101"
输出: 4
解释: 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。

*/


#include<iostream>
using namespace std;
#include<vector>

class Solution     // 按子符分组
{
public:
    int countBinarySubstrings(string s)
    {
        // vector<int> counts;  // 将字符串按0和1连续进行统计分组
        // int n = s.size(), ptr = 0;
        // while (ptr < n)  // 遍历字符串
        // {
        //     char c = s[ptr];
        //     int count = 0;
        //     while (ptr < n && s[ptr] == c)
        //     {
        //         ++ptr;
        //         ++count;  // 统计连续相同字符的数量
        //     }
        //     counts.push_back(count);
        // }

        // int ans = 0;
        // for (int i = 1; i < counts.size(); i++)
        // {
        //     ans += min(counts[i], counts[i - 1]);  // 比较，取较小的值
        // }
        // return ans;

        // 精简代码
        int ptr = 0, n = s.size(), last = 0, ans = 0;
        while (ptr < n)
        {
            char c = s[ptr];
            int count = 0;
            while (ptr < n && s[ptr] == c)
            {
                ++ptr;
                ++count;
            }
            ans += min(count, last);
            last = count;
        }
        return ans;
    }
};