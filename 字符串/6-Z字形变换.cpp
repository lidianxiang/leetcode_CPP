/*

将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);

示例 1：

输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"
示例 2：
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I
示例 3：

输入：s = "A", numRows = 1
输出："A"

*/

#include<iostream>
using namespace std;
#include<vector>


class Solution {   // 模拟法
public:
    string convert(string s, int numRows){
        if (numRows == 1){
            return s;
        }

        int sSize = s.size();
        int storeSize = min(sSize, numRows);
        string res;  // 临时保存每行字符
        vector<string> store(storeSize);  // 分行存储
        int loc = 0;  // 实时位置，范围在[0, numRows-1]
        bool change = false;  // 标志位，false为向下，true为向上
        for(int index=0; index < sSize; index++){
            store[loc].push_back(s[index]);
            if (loc == numRows -1 || loc == 0){
                change = !change;  // 每次到第一行或是最后一行时，变换标志位
            }
            loc += change ? 1: -1;
        }

        for(int index = 0; index < storeSize; index++){
            res += store[index];  // 将每行的结果拼接在一起
        }
        return res;
    }
};