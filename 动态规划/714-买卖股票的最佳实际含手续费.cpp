/*

给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

示例 1:

输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
输出: 8
解释: 能够达到的最大利润:  
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{    // 动态规划
public:
    int maxProfit(vector<int>& prices, int fee){
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for(int i=1; i<n; i++){
            // dp[i][0]表示第i天手里没有股票的情况下的收益，它有两种情况
            // 一是第i-1天本来就没交易，二是第i-1天交易了，所以要加上第i天卖出股票的收益，并减去手续费
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
            // dp[i][1]表示第i天交易时手里有股票的情况下的收益，他有两种情况
            // 一是第i-1天本来就持有股票，而是第i-1天手里没有股票，但是第i天买进了股票，所以收益要减去当天的买进价
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};