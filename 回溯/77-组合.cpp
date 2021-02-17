/*

给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{   // 递归回溯
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k){
        // 剪枝操作
        // temp的长度加上区间[cur, n]的长度小于k， 不可能构造出长度为k的temp数组
        if (temp.size() + (n - cur + 1) < k){
            return;
        }
        // 记录合法的答案
        if (temp.size() == k){
            ans.push_back(temp);
            return;
        }
        // 考虑选择当前的位置
        temp.push_back(cur);
        dfs(cur+1, n, k);
        temp.pop_back();
        // 考虑不选择当前的位置
        dfs(cur+1, n, k);
    }

    vector<vector<int>> combine(int n, int k){
        dfs(1, n, k);
        return ans;
    }
};