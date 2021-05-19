/*

给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:
输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。

示例 2:
输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{    // 动态规划
public:
    int findNumberOfLIS(vector<int>& nums){
        int n = nums.size();
        // 特判
        if (n < 1){
            return n;
        }

        vector<int> dp(n, 1);
        vector<int> count(n, 1);

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if (nums[j] < nums[i]){
                    // 第一次找到
                    if (dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    // 再次找到
                    }else if (dp[j] + 1 == dp[i]){
                        count[i] += count[j];
                    }
                }
            }
        }
        // 返回dp中的最大值，即最长递增子序列的长度
        int max = *max_element(dp.begin(), dp.end());
        int res = 0;
        for(int i=0; i<n; i++){
            if (dp[i] == max){
                res += count[i];
            }
        }
        return res;
    }
};