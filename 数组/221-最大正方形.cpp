/*

在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

示例 1：
输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：4

示例 2：
输入：matrix = [["0","1"],["1","0"]]
输出：1

示例 3：
输入：matrix = [["0"]]
输出：0

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{   // 暴力求解
public:
    int maximalSquare(vector<vector<char>>& matrix){
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return 0;
        }

        int maxSide = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if (matrix[i][j] == '1'){
                    // 遇到一个 1 作为正方形的左上角
                    maxSide = max(maxSide, 1);
                    // 计算可能的最大正方形边长
                    int currentMaxSide = min(rows - i, columns - j);
                    for(int k=1; k<currentMaxSide; k++){
                        // 判断新增的一行一列是否均为 1 
                        bool flag = true;
                        if (matrix[i+k][j+k] == '0'){
                            break;
                        }
                        for(int m=0; m<k; m++){
                            if (matrix[i+k][j+m] == '0' || matrix[i+m][j+k] == '0'){
                                flag = false;
                                break;
                            }
                        }
                        if (flag){
                            // 更新最大边长
                            maxSide = max(maxSide, k+1);
                        }else{
                            break;
                        }
                    }
                }
            }
        }
        int maxSquare = maxSide * maxSide;
        return maxSquare;
    }
};



class Solution2{   // 动态规划，其中dp[i][j]表示的是正方形的右下角的元素
public:
    int maximalSquare(vector<vector<char>>& matrix){
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return 0;
        }

        int maxSide = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if (matrix[i][j] == '1'){
                    if (i == 0 || j == 0){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    }
                    int maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        int maxSquare = maxSide * maxSide;
        return maxSquare;
    }
};