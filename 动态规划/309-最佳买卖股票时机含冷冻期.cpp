/*

给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。

示例:
输入: [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{   // 动态规划
public:
    int maxProfit(vector<int>& prices){
        if (prices.empty())
            return 0;

        int n = prices.size();
        // f[i][0]: 手上持有股票的最大收益
        // f[i][1]: 手上不持有股票，并且处于冷冻期的累计最大收益
        // f[i][2]: 手上不持有股票，并且不在冷冻期的累计最大收益
        vector<vector<int>> f(n, vector<int>(3));
        // 把买入股票当成是负收益
        f[0][0] = -prices[0];
        for(int i=1; i<n; i++){
            // 第i天为f[i][0]: 可以是在第i-1天就已经持有的情况，或是第i天买入的，那么第i-1天就不能持有股票并且不处于冷冻期中
            f[i][0] = max(f[i-1][0], f[i][2]-prices[i]);
            // 第i天为f[i][1]: 第i-1天时必须是持有一只股票，第i天卖掉了，所以要加上卖掉股票的正收益prices[i]
            f[i][1] = f[i-1][0] + prices[i];
            // 第i天为f[i][2]: 第i天结束后不持有任何股票且不处于冷冻期，那么当天没有进行任何操作
            // 即第i-1天不持有任何股票，如果处于冷冻期，对应的状态为f[i-1][1]
            // 如果不处于冷冻期，对应的状态为f[i-1][2]
            f[i][2] = max(f[i-1][1], f[i-1][2]);
        }
        return max(f[n-1][1], f[n-1][2]);
    }
};