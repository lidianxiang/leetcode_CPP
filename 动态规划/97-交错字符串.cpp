/*

给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
提示：a + b 意味着字符串 a 和 b 连接。

示例 1：
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出：true

示例 2：
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出：false

示例 3：
输入：s1 = "", s2 = "", s3 = ""
输出：true

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{      // 动态规划
public:
    bool isInterleave(string s1, string s2, string s3){
        auto f = vector<vector<int>> (s1.size()+1, vector<int>(s2.size()+1, false));

        int n = s1.size(), m = s2.size(), t = s3.size();

        if (n+m != t){
            return false;
        }

        f[0][0] = true;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                int p = i+j-1;
                if (i>0){
                    f[i][j] |= (f[i-1][j] && s1[i-1] == s3[p]);
                }
                if (j>0){
                    f[i][j] |= (f[i][j-1] && s2[j-1] == s3[p]);
                }
            }
        }
        return f[n][m];
    }
};


class Solution2{     // 动态规划 + 滚动数组优化空间复杂度
public:
    bool isInterleave(string s1, string s2, string s3){
        auto f = vector<int> (s2.size()+1, false);

        int n = s1.size(), m = s2.size(), t = s3.size();

        if (n+m != t){
            return false;
        }

        f[0] = true;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                int p = i+j-1;
                if (i>0){
                    f[j] &= (s1[i-1] == s3[p]);
                }
                if (j>0){
                    f[j] |= (f[j-1] && s2[j-1] == s3[p]);
                }
            }
        }
        return f[m];
    }
};