/*

给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。


示例 1：
输入：s = "aa" p = "a"
输出：false
解释："a" 无法匹配 "aa" 整个字符串。

示例 2:
输入：s = "aa" p = "a*"
输出：true
解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。

示例 3：
输入：s = "ab" p = ".*"
输出：true
解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。

示例 4：
输入：s = "aab" p = "c*a*b"
输出：true
解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。

示例 5：
输入：s = "mississippi" p = "mis*is*p*."
输出：false

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution {
public:
    bool isMatch(string s, string p) {
        int sSize = s.size();
        int pSize = p.size();
        // 当p为空的情况
        if (p.empty())
            return s.empty();

        vector<bool> tmpVec(pSize+1, false);
        vector<vector<bool>> dp(sSize+1, tmpVec);
        // 下面这段代码都是初始化的过程
        dp[0][0] = true;
        if (sSize != 0 && (p[0] == s[0] || p[0] == '.'))
            dp[1][1] = true;
        if (p[0] == '*')
            dp[0][1] = true;
        for(int i=1; i<pSize; i++){
            if (p[i] == '*' && dp[0][i-1] == true)
                dp[0][i+1] = true;
        }


        for(int i=0; i<sSize; i++){
            for(int j=1; j<pSize; j++){
                // 当两个字符串的当前字符相当或字符串p的当前字符为点号（匹配任意字符）时
                if (p[j] == '.' || p[j] == s[i])
                    dp[i+1][j+1] = dp[i][j];
                // 当字符串p的当前字符为星号
                if (p[j] == '*'){
                    // 看字符串p的前面两位，如果匹配就true，否则为false
                    if (p[j-1] != s[i] && p[j-1] != '.')
                        dp[i+1][j+1] = dp[i+1][j-1];
                    else
                        dp[i+1][j+1] = (dp[i][j+1] || dp[i+1][j-1]);
                }
            }
        }
        return dp[sSize][pSize];
    }
};