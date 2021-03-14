/*

不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。

示例 1:

输入: a = 1, b = 2
输出: 3
示例 2:

输入: a = -2, b = 3
输出: 1

*/


#include<iostream>
using namespace std;


class Solution{
public:
    int getSum(int a, int b){
        while(b){
            auto carry = ((unsigned int) (a & b) << 1);   // 获取进位结果
            a = a ^ b;   // 异或操作，获取加法下的结果 
            b = carry;
        }
        return a;
    }
};