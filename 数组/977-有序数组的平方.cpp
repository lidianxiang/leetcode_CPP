/*

给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

示例 1：

输入：[-4,-1,0,3,10]
输出：[0,1,9,16,100]
示例 2：

输入：[-7,-3,2,3,11]
输出：[4,9,9,49,121]

*/

#include<iostream>
using namespace std;
#include<vector>


class Solution{
public:
    vector<int> sortedSquares(vector<int> &A){
        /*
            使用双指针
        */
        int len = A.size();
        // 定义两个指针a，b，分别指向两头，count指针用于计数，并从尾部开始计数
        int a = 0, b = len - 1, count = b;
        vector<int> ans(len);
        while(count >= 0){
            int left = A[a] * A[a], right = A[b] * A[b];
            // 当left的值大于right的值
            if (left > right){
                ans[count] = left;
                a++;
            }
            else{
                ans[count] = right;
                b--;
            }
            count--;
        }
        return ans;
    }
};