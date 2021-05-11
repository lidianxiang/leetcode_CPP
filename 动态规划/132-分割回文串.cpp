/*

给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。

返回符合要求的 最少分割次数 。

示例 1：
输入：s = "aab"
输出：1
解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

示例 2：
输入：s = "a"
输出：0

示例 3：
输入：s = "ab"
输出：1

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{     // 动态规划
public:
    int minCut(string s){
        int n = s.size();
        vector<vector<int> > g(n, vector<int>(n, true));
        // 提前计算出是否为回文串
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                g[i][j] = (s[i] == s[j]) && g[i+1][j-1];
            }
        }

        vector<int> f(n, INT_MAX);
        for(int i=0; i<n; i++){
            // 当这个字符串本身就是回文串时，则不需要任何的切割的，所以为0
            if (g[0][i]){
                f[i] = 0;
            }else{
                for(int j=0; j<i; j++){
                    // 当需要进行切割时
                    if (g[j+1][i]){
                        f[i] = min(f[i], f[j]+1);
                    }
                }
            }
        }
        return f[n-1];
    }
};