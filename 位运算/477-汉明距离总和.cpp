/*

两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。

计算一个数组中，任意两个数之间汉明距离的总和。

示例:

输入: 4, 14, 2

输出: 6

解释: 在二进制表示中，4表示为0100，14表示为1110，2表示为0010。（这样表示是为了体现后四位之间关系）
所以答案为：
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{     // 位运算
public:
    int totalHammingDistance(vector<int> nums){
        if (nums.empty())
            return 0;
        
        int ans = 0, n = nums.size();
        vector<int> cnt(32, 0);

        for(auto num: nums){
            int i=0;
            while(num > 0){
                cnt[i] += (num & 0x1);   // 按位统计，与二进制1相比取&计算
                num >>= 1;  // 右移一位
                i++;
            }
        }

        for(auto&& k : cnt){
            ans += k * (n-k);   // 循环统计
        }
        return ans;
    }
};