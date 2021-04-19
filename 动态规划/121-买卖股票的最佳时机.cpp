/*

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。

注意：你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

*/


#include<iostream>
using namespace std;
#include<vector>

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    /*
        暴力求解，两层循环，但是会超出leetcode的时间限制
    */
    {
        int n = (int)prices.size(), ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                ans = max(ans, prices[j] - prices[i]);
            }
        }
        return ans;
    }
};


class Solution2
{
public:
    int maxProfit(vector<int>& prices)
    {
        int inf = 1e9;
        // minprice表示最低价格，maxprofit表示最高利润
        int minprice = inf, maxprofit = 0;
        for(int price: prices)
        {
            // 更新每日的最高利润
            maxprofit = max(maxprofit, price - minprice);
            // 更新每日的最低价格
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
};