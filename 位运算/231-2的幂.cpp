/*

给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:

输入: 1
输出: true
解释: 20 = 1
示例 2:

输入: 16
输出: true
解释: 24 = 16
示例 3:

输入: 218
输出: false

*/

#include<iostream>
using namespace std;


class Solution{
public:
    bool isPowerOfTwo(int n){
        if (n == 0)
            return false;
        long x = n;
        return (x &(x-1)) == 0;
    }
};


class Solution2{  // x &(-x)会保留最右边的1，并将其他位设置为0
public:
    bool isPowerOfTwo(int n){
        if (n == 0)
            return false;
        long x = n;
        return (x &(-x)) == x;
    }
};