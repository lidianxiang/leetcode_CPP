/*

给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。

下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 。

示例 1：
输入：matrix = [[2,1,3],[6,5,4],[7,8,9]]
输出：13
解释：下面是两条和最小的下降路径，用加粗标注：
[[2,1,3],      [[2,1,3],
 [6,5,4],       [6,5,4],
 [7,8,9]]       [7,8,9]]

示例 2：
输入：matrix = [[-19,57],[-40,-5]]
输出：-59
解释：下面是一条和最小的下降路径，用加粗标注：
[[-19,57],
 [-40,-5]]

示例 3：
输入：matrix = [[-48]]
输出：-48

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{    // 动态规划
public:
    int minFallingPathSum(vector<vector<int>>& matrix){
        int n = matrix.size();
        // 行倒着排，dp方程好写一点，从倒数第二行开始往上面计算
        for(int r=n-2; r>=0; --r){
            // 列正常顺着排
            for(int c=0; c<n; ++c){
                int best = matrix[r][c];
                if (c>0){
                    best = min(best, matrix[r+1][c-1]);
                }
                if (c+1<n){
                    best = min(best, matrix[r+1][c+1]);
                }
                // 直接在原数组上想加，减少额外的内存
                matrix[r][c] += best;
            }
        }
        
        int ans = INT_MAX;
        // 由于是从下往上计算的，所以最后相加的结果是在第一行上
        // 所以只需要比较第一行的值，最小值即最后结果
        for(int x: matrix[0]){
            ans = min(ans, x);
        }
        return ans;
    }
};