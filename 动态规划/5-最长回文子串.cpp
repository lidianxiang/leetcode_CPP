/*

给你一个字符串 s，找到 s 中最长的回文子串。

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
示例 3：

输入：s = "a"
输出："a"
示例 4：

输入：s = "ac"
输出："a"

*/

#include<iostream>
using namespace std;
#include<vector>	
#include <utility>


class Solution{    // 暴力求解
public:
    bool isPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;
        for (; left < right; left++, right--)
        {
            if (s[left] != s[right])
            {
                return false;
            }
        }
        return true;
    }

    string longestPalindrome(string s)
    {
        string res = "";
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            int maxLength = size - i;
            for (int tmpSize = 1; tmpSize <= maxLength; tmpSize++)
            {
                string tmp = s.substr(i, tmpSize);
                if (isPalindrome(tmp) && tmp.size() > res.size())
                {
                    res = tmp;
                }
            }
        }
        return res;
    }
};


class Solution2{    // 动态规划
public:
    string longestPalindrome(string s){
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for(int l=0; l<n; ++l){
            for(int i=0; i+l<n; ++i){
                int j=i+l;
                if(l == 0){
                    dp[i][j] = 1;
                }else if (l == 1){
                    dp[i][j] = (s[i] == s[j]);
                }else {
                    dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                }
                if (dp[i][j] && l+1 > ans.size()){
                    ans = s.substr(i, l+1);
                }
            }
        }
        return ans;
    }
};


class Solution {    // 中心扩展法
private:
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }
public:
    
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};