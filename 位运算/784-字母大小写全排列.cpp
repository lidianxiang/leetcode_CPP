/*

给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。

示例：
输入：S = "a1b2"
输出：["a1b2", "a1B2", "A1b2", "A1B2"]

输入：S = "3z4"
输出：["3z4", "3Z4"]

输入：S = "12345"
输出：["12345"]

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{   // 回溯 + 位运算
public:
    vector<string> letterCasePermutation(string S){
        vector<string> ans;
        dfs(S, 0, ans);
        return ans;
    }


    void dfs(string& S, int index, vector<string>& ans){
        if (index == S.length()){
            ans.push_back(S);
            return;
        }
        // 未修改当前字符
        dfs(S, index+1, ans);
        // 修改当前字符
        if (isalpha(S[index])){
            S[index] = S[index] ^ 32;  // 大写变小写， 小写变大写
            dfs(S, index+1, ans);
        }
    }
};