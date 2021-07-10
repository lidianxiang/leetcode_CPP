/*

给你 二维 平面上两个 由直线构成的 矩形，请你计算并返回两个矩形覆盖的总面积。

每个矩形由其 左下 顶点和 右上 顶点坐标表示：

第一个矩形由其左下顶点 (ax1, ay1) 和右上顶点 (ax2, ay2) 定义。
第二个矩形由其左下顶点 (bx1, by1) 和右上顶点 (bx2, by2) 定义。
 

示例 1：
输入：ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
输出：45

示例 2：
输入：ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
输出：16

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // 特殊情况：当两个矩形不存在重合的情况，直接加上两个矩形的面积即可
        if (bx1 >= ax2 || bx2 <= ax1 || by1 >= ay2 || by2 <= ay1){
            return (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1);
        }
        // 寻找重合的面积的x坐标
        int a = min(ay2, by2);
        int b = max(ay1, by1);
        int x = abs(a-b);
        // 寻找重合面积的y坐标
        int c = min(ax2, bx2);
        int d = max(ax1, bx1);
        int y = abs(c-d);
        // 两个面积想加，并减去重合的面积
        return (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1) - x * y;
    }
};