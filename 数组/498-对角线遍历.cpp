/*

给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

示例:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

输出:  [1,2,4,7,5,3,6,8,9]

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix){
        vector<int> nums;
        int m = matrix.size();
        if (m == 0){
            return nums;
        }
        int n = matrix[0].size();
        if (n == 0){
            return nums;
        }
        // 标志位，true表示从东北方向转向西南方向扫描
        bool bXFlag = true;
        for(int i=0; i<m+n; i++){
            int pm = bXFlag ? m : n;
            int pn = bXFlag ? n : m;

            int x = (i < pm) ? i : pm - 1;
            int y = i - x;

            while(x >= 0 && y < pn){
                nums.push_back(bXFlag ? matrix[x][y] : matrix[y][x]);
                x--;
                y++;
            }
            // 反转扫描方向
            bXFlag = !bXFlag;
        }
        return nums;
    }
};