/*

给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。

子数组 定义为原数组中的一个连续子序列。

请你返回 arr 中 所有奇数长度子数组的和 。
示例 1：

输入：arr = [1,4,2,5,3]
输出：58
解释：所有奇数长度子数组和它们的和为：
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
我们将所有值求和得到 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
示例 2：

输入：arr = [1,2]
输出：3
解释：总共只有 2 个长度为奇数的子数组，[1] 和 [2]。它们的和为 3 。
示例 3：

输入：arr = [10,11,12]
输出：66

*/
#include<iostream>
using namespace std;
#include<vector>

class Solution{
public:
    int sumOddLengthSubarrays(vector<int>& arr){
        /*
        主要用到动态规划和滑动窗口的思想
        首先先遍历一遍每个元素并相加，然后每次扩大两个窗口求子序列的和，
        由于子序列有重叠的问题，考虑直接在上一个子序列的基础上叠加新增的两个窗口的元素之和
        */
        int i, j, tmp;
        int sum = 0;
        for (i=0; i<arr.size(); i++){
            tmp = 0;
            tmp += arr[i];
            sum += tmp;
            for (j=2; i+j< arr.size(); j+=2){
                tmp += arr[i+j] + arr[i+j-1];
                sum += tmp;
            }
        }
        return sum;
    }
};