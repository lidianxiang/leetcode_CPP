/*

给你一个 m x n 的矩阵 matrix 和一个整数 k ，找出并返回矩阵内部矩形区域的不超过 k 的最大数值和。

题目数据保证总会存在一个数值和不超过 k 的矩形区域。

示例 1：
输入：matrix = [[1,0,1],[0,-2,3]], k = 2
输出：2
解释：蓝色边框圈出来的矩形区域 [[0, 1], [-2, 3]] 的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。

示例 2：
输入：matrix = [[2,2,-1]], k = 3
输出：3

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{    // 有序集合：枚举矩形的上下边界，并计算边界内的每列元素和
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k){
        int ans = INT_MIN;
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0; i<m; i++){    // 枚举上边界
            vector<int> sum(n);
            for(int j=i; j<m; j++){   // 枚举下边界
                for(int c=0; c<n; c++){   
                    sum[c] += matrix[j][c];   // 更新每列的元素和
                }
                set<int> sumSet{0};
                int s = 0;
                for(int v: sum){
                    s += v;
                    auto lb = sumSet.lower_bound(s - k);
                    if (lb != sumSet.end()){
                        ans = max(ans, s - *lb);
                    }
                    sumSet.insert(s);
                }
            }
        }
        return ans;
    }
};