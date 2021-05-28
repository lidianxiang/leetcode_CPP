/*

把字符串 s 看作是“abcdefghijklmnopqrstuvwxyz”的无限环绕字符串，所以 s 看起来是这样的："...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....". 

现在我们有了另一个字符串 p 。你需要的是找出 s 中有多少个唯一的 p 的非空子串，尤其是当你的输入是字符串 p ，你需要输出字符串 s 中 p 的不同的非空子串的数目。 

注意: p 仅由小写的英文字母组成，p 的大小可能超过 10000。

示例 1:
输入: "a"
输出: 1
解释: 字符串 S 中只有一个"a"子字符。
 

示例 2:
输入: "cac"
输出: 2
解释: 字符串 S 中的字符串“cac”只有两个子串“a”、“c”。.
 

示例 3:
输入: "zab"
输出: 6
解释: 在字符串 S 中有六个子串“z”、“a”、“b”、“za”、“ab”、“zab”。.

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{
public:
    // 判断字符串是否连续
    bool isContinous(char prev, char curr){
        if (prev == 'z')
            return curr == 'a';
        return prev + 1 == curr;
    }

    int findSubstringInWraproundString(string p) {
        vector<int> dp(26, 0);
        int N = p.size();
        int k = 0;
        for(int i=0; i<N; i++){
            if (i > 0 && isContinous(p[i-1], p[i])){
                ++k;
            }else{
                k = 1;
            }
            // 记录以每个字符结尾字串的最长长度
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
        // 累加每个子串
        return accumulate(dp.begin(), dp.end(), 0);
    }
};