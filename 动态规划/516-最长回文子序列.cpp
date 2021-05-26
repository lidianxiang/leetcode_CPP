/*

给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。 

示例 1:
输入:
"bbbab"
输出:  4
一个可能的最长回文子序列为 "bbbb"。

示例 2:
输入:
"cbbd"
输出:  2

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{
public:
    int longestPalindromeSubseq(string s){
        int n = s.size();
        // dp数组全部初始化为0
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // base case
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }
        // 反着遍历保证正确的状态转移方程
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                // 状态转移方程
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        // 返回整个s的最长回文子序列
        return dp[0][n-1];
    }
};