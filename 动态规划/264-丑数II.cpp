/*

编写一个程序，找出第 n 个丑数。

丑数就是质因数只包含 2, 3, 5 的正整数。

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{
public:
    int nthUglyNumber(int n){
        vector<int> dp(n);
        dp[0] = 1;
        int p_2, p_3, p_5;
        p_2 = p_3 = p_5 = 0;
        for(int i=1; i<n; i++){
            dp[i] = min(min(2*dp[p_2], 3*dp[p_3]), 5*dp[5]);
            if (dp[i] == 2 * dp[p_2])
                ++p_2;
            if (dp[i] == 3 * dp[p_3])
                ++p_3;
            if (dp[i] == 5 * dp[p_5])
                ++p_5;
        }
        return dp[p_5];
    }
};