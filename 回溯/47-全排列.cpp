/*

给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

示例 1：

输入：nums = [1,1,2]
输出：
[   [1,1,2],
    [1,2,1],
    [2,1,1]]

示例 2：
输入：nums = [1,2,3]
输出：[  [1,2,3],
        [1,3,2],
        [2,1,3],
        [2,3,1],
        [3,1,2],
        [3,2,1]]

*/


#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


class Solution {
    // vector<int> visit;
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm, vector<int>& visit){
        // 当索引值到达最后，则将排列数组perm添加值最后的答案ans中
        if (idx == nums.size()){
            ans.emplace_back(perm);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            // 去除重复项
            // visit表示已访问的元素
            if (visit[i] || (i > 0 && nums[i] == nums[i-1] && !visit[i-1])){
                continue;
            }
            perm.emplace_back(nums[i]);
            visit[i] = 1;
            backtrack(nums, ans, idx+1, perm, visit);
            // 下面两步是撤销操作
            visit[i] = 0;
            perm.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        vector<int> visit;
        visit.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, 0, perm, visit);
        return ans;
    }
};