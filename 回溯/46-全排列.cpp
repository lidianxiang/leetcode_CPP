/*

给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/


#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


class Solution{    // 回溯 
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        if (first == len){
            res.push_back(output);
            return;
        }

        for(int i=first; i<len; i++){
            swap(output[i], output[first]);  // 动态维护数组
            backtrack(res, output, first+1, len);   // 继续递归填下一个数
            swap(output[i], output[first]);   // 撤销操作
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>  res;
        backtrack(res, nums, 0, nums.size());
        return res;
    }
};