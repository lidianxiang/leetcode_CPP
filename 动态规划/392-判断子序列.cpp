/*

给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

进阶：

如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

致谢：

特别感谢 @pbrother 添加此问题并且创建所有测试用例。

示例 1：

输入：s = "abc", t = "ahbgdc"
输出：true
示例 2：

输入：s = "axc", t = "ahbgdc"
输出：false

*/

#include<iostream>
using namespace std;


class Solution{   // 双指针
public:
    bool isSubsequence(string s, string t){
        int n = s.length(), m = t.length();
        int i = 0, j = 0;
        while(i < n && j < m){
            if (s[i] == t[j]){
                i++;
            }
            j++;
        }
        return i == n;
    }
};


class Solution2{    // 动态规划
public:
    bool isSubsequence(string s, string t){
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
        for(int i=0; i<=s.size(); i++){
            for(int j=0; j<=t.size(); j++){
                if (s[i-1] == t[j-1])  // 当在t中找到了一个字符在s中也出现了
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        if (dp[s.size()][t.size()] == s.size())
            return true;
        return false;
    }
};