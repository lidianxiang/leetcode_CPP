/*

给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？ 

示例 1：

输入：nums = [1,2,1,3,2,5]
输出：[3,5]
解释：[5, 3] 也是有效的答案。
示例 2：

输入：nums = [-1,0]
输出：[-1,0]
示例 3：

输入：nums = [0,1]
输出：[1,0]

*/

#include<iostream>
using namespace std;


class Solution{
public:
    vector<int> singleNumber(vector<int>& nums){
        int res = 0;
        // 找出所有数字异或的结果
        for(int n: nums){
            res ^= n;
        }
        // 找到第一位不是0的
        int div = 1;
        while((div && res) == 0)
            div <<= 1;
        int a = 0, b = 0;
        for(int n: nums){
            // 根据该位是否为0将其分为两组
            if (div & n)
                a ^= n;
            else
                b ^= n;
        }
        return vector<int> {a,b};
    }
}