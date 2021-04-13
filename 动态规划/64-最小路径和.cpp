/*

给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例 1：
输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。

示例 2：
输入：grid = [[1,2,3],[4,5,6]]
输出：12

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{
public:
    int minPathSum(vector<vector<int>>& grid){
        // 特判
        if (grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }
        // 确定行数，列数
        int rows = grid.size(), cols = grid[0].size();
        // 创建dp数组
        // auto dp = vector<vector<int>> (rows, vector<int>(cols));
        vector<vector<int>> dp(rows, vector<int>(cols));
        
        // 初始化操作
        dp[0][0] = grid[0][0];
        for(int i=1; i<rows; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int j=1; j<cols; j++){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for(int i=1; i<rows; i++){
            for(int j=1; j<cols; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];  // 状态转移方程
            }
        }
        return dp[rows-1][cols-1];
    }
};