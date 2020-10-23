/*

给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]

*/


#include<iostream>
using namespace std;
#include<vector>

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    /*
        动态规划：
        更新过程为：从倒数第二个元素开始往前更新 它等于原来这个位置的数 + 前一个位置的数
            行[i] = 行[i] + 行[i-1]
    */
    {
        vector<int> kRows(rowIndex + 1);  // 第K行的vector大小为rowIndex+1
        for (int i = 0; i <= rowIndex; i++)  // 利用前一行求后一行，第K行要循环K遍
        {
            kRows[i] = 1;    // 行末尾为1
            for (int j = i; j > 1; j--)  
            {
                kRows[j - 1] = kRows[j - 2] + kRows[j - 1];
            }
        }
        return kRows;
    }
};