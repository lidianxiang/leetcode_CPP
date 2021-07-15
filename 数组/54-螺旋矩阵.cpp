/*

给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution {    // 模拟法
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        // 若数组为空，直接返回
        if (matrix.empty()){
            return ans;
        }

        int upper = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        while(true){
            // 向右移动到最右边
            for(int i=left; i<=right; ++i){
                ans.push_back(matrix[upper][i]);
            }
            // 重新设定上边界，若上边界大于下边界，则遍历完成
            if (++upper > bottom){
                break;
            }

            // 向下
            for(int i=upper; i<=bottom; ++i){
                ans.push_back(matrix[i][right]);
            }
            // 重新设定右边界
            if (--right < left){
                break;
            }

            // 向左
            for(int i=right; i >= left; --i){
                ans.push_back(matrix[bottom][i]);
            }
            // 重新设定下边界
            if (--bottom < upper){
                break;
            }
            
            // 向上
            for(int i = bottom; i>=upper; --i){
                ans.push_back(matrix[i][left]);
            }
            // 重新设定左边界
            if (++left > right){
                break;
            }    
        }
        return ans;
    }
};