/*

给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

示例 1：
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

示例 2：
输入：target = 4, nums = [1,4,4]
输出：1

示例 3：
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0

*/


#include<iostream>
using namespace std;
#include<vector>

class Solution{    // 滑动窗口
public:
    int minSubArrayLen(int target, vector<int>& nums){
        int n = nums.size();
        if (n == 0){
            return 0;
        }
        int ans = INT_MAX;
        // 双指针，初始值均为0
        int start = 0, end = 0;
        int sum = 0;
        while (end < n){
            sum += nums[end];
            // 当sum的值大于target目标值时
            while (sum >= target){
                // 更新ans
                ans = min(ans, end - start + 1);
                // sum减去nums[start]
                sum -= nums[start];
                // start右移
                start++;
            }
            // end不断右移
            end++;
        }
        return ans == INT_MAX ? 0: ans;
    }
};