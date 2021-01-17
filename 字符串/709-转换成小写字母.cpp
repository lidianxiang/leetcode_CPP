/*

实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。

示例 1：

输入: "Hello"
输出: "hello"
示例 2：

输入: "here"
输出: "here"
示例 3：

输入: "LOVELY"
输出: "lovely"

*/


#include<iostream>
using namespace std;


class Solution{
public:
    string toLowerCase(string str){
        int change_num = 'a' - 'A';   // 计算出在ASCII中小写字母与大写字母的差值
        string res = "";

        for(auto& ch: str){
            if (ch >= 'A' && ch <= 'Z'){
                res += (ch + change_num);
            }else{
                res += ch;
            }
        }
        return res;
    }
};


class Solution2{    // 位运算
public:
    string toLowerCase(string str){
        /* 位运算（解题区的思路
        大写变小写、小写变大写 : 字符 ^= 32;
        大写变小写、小写变小写 : 字符 |= 32;  
        小写变大写、大写变大写 : 字符 &= -33;
        eg：
        65(A)->二进制表示为100 0001
        32的二进制表示为 010 0000 
        100 0001|010 0000=110 0001->97(a)
        */
        for(auto& s:str){
            s |= 32;
        }
        return str;
    }
};