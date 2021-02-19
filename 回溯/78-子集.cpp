/*

给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, vector<int>& nums){
        // 满足条件
        if (cur == nums.size()){
            ans.push_back(temp);
            return;
        }
        // 考虑选择当前位置
        temp.push_back(nums[cur]);
        dfs(cur+1, nums);
        temp.pop_back();
        // 不考虑选择当前位置
        dfs(cur+1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};