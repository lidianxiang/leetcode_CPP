/*

给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:
每个数组中的元素不会超过 100
数组的大小不会超过 200

示例 1:
输入: [1, 5, 11, 5]
输出: true
解释: 数组可以分割成 [1, 5, 5] 和 [11].

示例 2:
输入: [1, 2, 3, 5]
输出: false
解释: 数组不能分割成两个元素和相等的子集.

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{  // 动态规划
public:
    bool canPartition(vector<int>& nums){
        int n = nums.size();
        // 当nums的个数小于2，则返回false
        if (n < 2)
            return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        // 当nums所有元素的总和为奇数，则返回false
        if (sum & 1){
            return false;
        }
        // 对半分，target
        int target = sum / 2;
        // 当nums中的最大值大于sum的一半，则返回false
        if (maxNum > target){
            return false;
        }

        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        // 初始化操作
        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for(int i=1; i<n; i++){
            int num = nums[i];
            for(int j=1; j<=target; j++){
                // 当j的值大于当前值，则有两种情况，前面不取当前值，后面取当前值
                if (j >= num){
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-num];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n-1][target];
    }
};


class Solution2{    // 动态规划 + 空间优化（dp由二维转为一维）
public:
    int canPartition(vector<int>& nums){
        int n = nums.size();
        if (n < 2){
            return false;
        }

        int sum = 0, maxNum = 0;
        for(auto& num: nums){
            sum += num;
            maxNum = max(num, maxNum);
        }

        if (sum & 1){
            return false;
        }
        int target = sum / 2;
        if (maxNum > target){
            return false;
        }
        vector<int> dp(target+1, 0);
        dp[0] = true;
        for(int i=0; i<n; i++){
            int num = nums[i];
            for(int j=target; j>= num; j--){
                dp[j] |= dp[j-num];
            }
        }
        return dp[target];
    }
};