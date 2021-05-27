/*

给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例：
输入：nums: [1, 1, 1, 1, 1], S: 3
输出：5
解释：

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{    // 回溯
public:
    int count = 0;
    int findTargetSumWays(vector<int>& nums, int target){
        calculate(nums, 0, 0, target);
        return count;
    }

    void calculate(vector<int>& nums, int i, int sum, int S){
        // 结束条件
        if (i == nums.size()){
            if (sum == S){
                count++;
            }
        }else{
            // 两种方式的计算
            calculate(nums, i+1, sum+nums[i], S);
            calculate(nums, i+1, sum-nums[i], S);
        }
    }
};


class Solution2{   
        /*
        动态规划：01背包问题
            把整个集合看成两个子集，Q表示整个集合，P表示正数子集，N表示负数子集，T表示目标和
                S(P) - S(N) = T
            那么我们在等式两边同时加上S(P)和S(N)，则
                S(P) + S(N) + S(P) - S(N) = T + S(P) + S(N)
            化简后得到
                2 * S(P) = S(Q) + T
            也就是正数集合的两倍 == 目标和 + 序列总和
        */
public:
    int findTargetSumWays(vector<int>& nums, int target){
        long sum = 0;
        for(const int& num: nums)
            sum += num;
        if ((sum + target) % 2 == 1 || target > sum)
            return 0;
        target = (target + sum) / 2;
        int *dp = new int[target+1];
        memset(dp, 0, (target+1)*sizeof(int));
        dp[0] = 1;
        for(const int& num: nums){
            for(int j=target; j>=num; j--){
                dp[j] += dp[j-num];
            }
        }
        int ans = dp[target];
        delete[] dp;
        return ans;
    }
};