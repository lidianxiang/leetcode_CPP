/*

给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

示例 1:
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。

示例 2:
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{   // 动态规划（需要根据正负性来判断）
public:
    int maxProduct(vector<int>& nums){
        vector<int> maxF(nums), minF(nums);
        for(int i=1; i<nums.size(); i++){
            maxF[i] = max(maxF[i-1] * nums[i], max(nums[i], minF[i-1] * nums[i]));
            minF[i] = min(minF[i-1] * nums[i], min(nums[i], maxF[i-1] * nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};


class Solution2{    // 动态规划 + 滚动数组优化空间复杂度
public:
    int maxProduct(vector<int>& nums){
        int maxF = nums[0], minF = nums[0], ans = nums[0];

        for(int i=1; i<nums.size(); i++){
            int mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
            ans = max(maxF, ans);
        }
        return ans;
    }
};