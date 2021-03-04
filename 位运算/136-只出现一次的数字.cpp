/*

给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4

*/

#include<iostream>
using namespace std;


class Solution{    // 位运算
    /*

        1、任何数和0做异或运算，结果仍是原来的数本身
        2、任何数和其自身做异或运算，结果等于0
        3、异或运算满足交换律和结合律

    */
public:
    int singleNumber(vector<int>& nums){
        int res = 0;
        for(auto num:nums){
            res ^= num;
        }
        return res;
    }
};