/*

找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        backtrack(k, n, 1, {}, res);
        return res;
    }

    void backtrack(int k, int sum, int start, vector<int> cur, vector<vector<int>>& res){
        if (k == 0){
            if (sum == 0){
                res.push_back(cur);
            }
            return;
        }

        for(int i=start; i<=9; i++){
            cur.push_back(i);
            backtrack(k-1, sum-i, i+1, cur, res);
            cur.pop_back();
        }
    }
};