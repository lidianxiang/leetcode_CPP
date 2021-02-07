/*

数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：

输入：n = 1
输出：["()"]

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{   // 回溯
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;  // 创建数组保存最后结果
        int lc = 0, rc = 0;  // lc和rc分别表示左括号和右括号的个数
        dfs(res, "", n, lc, rc);
        return res;
    }

    void dfs(vector<string>& res, string path, int n, int lc, int rc){
        if (rc > lc || lc > n || rc > n)  // 递归结束条件
            return;
        if (lc == rc && lc == n){   // 当左右括号数等于n时，满足条件，将结果push_back到res中
            res.push_back(path);
            return;
        }
        // 递归调用
        dfs(res, path+"(" ,n, lc+1, rc);
        dfs(res, path+")", n, lc, rc+1);
    }
};