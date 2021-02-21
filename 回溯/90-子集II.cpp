/*

给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/


#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


class Solution {    // 回溯
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(vector<int>& nums, int startIndex){
        res.push_back(path);
        for(int i=startIndex; i<nums.size(); i++){
            if (i>startIndex && nums[i] == nums[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            backtrack(nums, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return res;
    }
};