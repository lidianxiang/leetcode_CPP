/*

给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]

*/

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


class Solution {      // 回溯
public:

    void dfs(vector<int>& candidates,  vector<vector<int>>& res, vector<int>& path, int start, int target){
        if (target == 0){  // 当条件满足时
            res.push_back(path);
            return;
        }
        // 遍历数组
        for(int i=start; i<candidates.size() && target - candidates[i] >= 0; i++){
            if (i > start && candidates[i] == candidates[i-1])  // 跳过重复的元素
                continue;
            path.push_back(candidates[i]);
            dfs(candidates,res, path, i+1, target-candidates[i]);
            path.pop_back();  // 回溯
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end()); // 排序，使得重复的元素相邻
        dfs(candidates, res, path,0, target);
        return res;
    }
};