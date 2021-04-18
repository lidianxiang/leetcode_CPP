/*

给定一个三角形 triangle ，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

示例 1：
输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
输出：11
解释：如下面简图所示：
   2
  3 4
 6 5 7
4 1 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

示例 2：
输入：triangle = [[-10]]
输出：-10

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{
public:
    int minmumTotal(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<vector<int>> f(n, vector<int>(n));
        f[0][0] = triangle[0][0];
        for(int i=1; i<n; i++){
            f[i][0] = f[i-1][0] + triangle[i][0];
            for(int j=1; j<i; j++){
                f[i][j] = min(f[i-1][j-1], f[i-1][j]) + triangle[i][j];
            }
            f[i][i] = f[i-1][i-1] + triangle[i][i];
        }
        return *min_element(f[n-1].begin(), f[n-1].end());
    }
};


class Solution2{    //动态规划 + 空间优化
public:
    int minmumTotal(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<vector<int>> f(2, vector<int>(n));
        f[0][0] = triangle[0][0];
        for(int i=1; i<n; i++){
            int curr = i % 2;
            int prev = 1 - curr;
            f[curr][0] = f[prev][0] + triangle[i][0];
            for(int j=1; j<i; j++){
                f[curr][j] = min(f[prev][j-1], f[prev][j]) + triangle[i][j];
            }
            f[curr][i] = f[prev][i-1] + triangle[i][i];
        }
        return *min_element(f[(n-1)%2].begin(), f[(n-1)%2].end());
    }
};
