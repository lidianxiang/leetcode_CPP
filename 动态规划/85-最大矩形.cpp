/*

给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

示例 1：
输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：6
解释：最大矩形如上图所示。

示例 2：
输入：matrix = []
输出：0

示例 3：
输入：matrix = [["0"]]
输出：0

示例 4：
输入：matrix = [["1"]]
输出：1

示例 5：
输入：matrix = [["0","0"]]
输出：0

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{
public:
    int maximalRectangle(vector<vector<char>>& matrix){
        int m = matrix.size();
        if (m == 0){
            return 0;
        }

        int n = matrix[0].size();
        // left数组来记录一行中的连续1的个数
        vector<vector<int>> left(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1'){
                    left[i][j] = (j == 0? 0: left[i][j-1]) + 1;
                }
            }
        }
        // ret保存结果
        int ret = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (matrix[i][j] == '0'){
                    continue;
                }
                // width记录宽度
                int width = left[i][j];
                // area记录面积，初始化为width
                int area = width;
                // 从当前行往上算，统计最小width值
                for(int k=i-1; k>=0; k--){
                    width = min(width, left[k][j]);
                    // 更新面积值area
                    area = max(area, (i-k+1) * width);
                }
                ret = max(ret, area);
            }
        }
        return ret;
    }
};


class Solution2{     // 单调栈
public:
    int maximalRectangle(vector<vector<char>>& matrix){
        int m = matrix.size();
        if (m == 0)
            return 0;
        
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1'){
                    left[i][j] = (j == 0 ? 0: left[i][j-1]) + 1;
                }
            }
        }

        int ret = 0;
        for(int j=0; j<n; j++){
            vector<int> up(m,0), down(m, 0);

            stack<int> stk;
            for(int i=0; i<m; i++){
                while(!stk.empty() && left[stk.top()][j] >= left[i][j]){
                    stk.pop();
                }
                up[i] = stk.empty() ? -1: stk.top();
                stk.push(i);
            }
            stk = stack<int>();
            for(int i=m-1; i>=0; i--){
                while(!stk.empty() && left[stk.top()][j] >= left[i][j]){
                    stk.pop();
                }
                down[i] = stk.empty()? m: stk.top();
                stk.push(i);
            }

            for(int i=0; i<m; i++){
                int height = down[i] - up[i] - 1;
                int area = height * left[i][j];
                ret = max(ret, area);
            }
        }
        return ret;
    }
};