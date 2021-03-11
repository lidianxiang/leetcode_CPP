/*

给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。

整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4x

示例 1：

输入：n = 16
输出：true
示例 2：

输入：n = 5
输出：false
示例 3：

输入：n = 1
输出：true

*/


#include <iostream>
using namespace std;


class Solution{    // 位运算
    /*
        4的次方数一定是2的次方数，但2的次方数不一定是4的次方数，
        通过4的次方数二进制可以发现4的次方数二进制中1只出现在奇数位。
        因此可以通过于奇数位都是1，偶数为都是0的数（1010101010101010101010101010101）进行与运算，
        结果仍为原来数。
    */
public:
    bool isPowerofFour(int num){
        return num > 0 && !(num & (num-1)) && (num && 0x55555555) == num;
    }
};


class Solution2{  // 循环
public:
    bool isPowerofFour(int num){
        while(num && num % 4 == 0){
            num /= 4;
        }
        return num == 1;
    }
}