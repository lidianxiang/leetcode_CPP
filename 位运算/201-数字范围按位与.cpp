/*

给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

示例 1: 

输入: [5,7]
输出: 4
示例 2:

输入: [0,1]
输出: 0

*/


#include<iostream>
using namespace std;

class Solution{   
    /*
        位运算： 
            求出两个给定数字的二进制字符串的公共前缀

            将两个数字不断向右移动，知道数字相等，即数字被缩减为他们的公共前缀。
            然后通过将公共前缀向左移动，将零添加到公共前缀的右边以获得最终结果。
    */
public:
    int rangeBitwiseAnd(int m, int n){
        int shift = 0;
        while(m < n){
            m >>= 1;
            n >>= 1;
            ++shift;
        }
        return m << shift;
    }
};