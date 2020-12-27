/*

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{
public:
    string longestCommonPrefix(vector<string> strs){
        // 如果strs不为空，取strs的第一个字符串为比较对象
        string res = strs.empty() ? "": strs[0];
        // 遍历数组
        for (string s: strs){
            while(s.find(res) != 0){
                res = res.substr(0, res.length() - 1);
            }
        }
        return res;
    }
};