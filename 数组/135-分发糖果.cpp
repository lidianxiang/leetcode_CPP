/*

老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1：
输入：[1,0,2]
输出：5
解释：你可以分别给这三个孩子分发 2、1、2 颗糖果。

示例 2：
输入：[1,2,2]
输出：4
解释：你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution {   // 两次遍历（左遍历+右遍历）
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n);
        for(int i=0; i<n; i++){
            if (i>0 && ratings[i] > ratings[i-1]){
                left[i] = left[i-1]+1;
            }else{
                left[i] = 1;
            }
        }

        int right = 0, ret = 0;
        for(int i=n-1; i>=0; i--){
            if (i<n-1 && ratings[i] > ratings[i+1]){
                right++;
            }else{
                right = 1;
            }
            ret += max(left[i], right);
        }
        return ret;
    }
};


class Solution2{   // 常数空间遍历: 只记录当前递减序列的长度dec，最近的递增序列的长度inc和前一个同学的糖果数pre
public:
    int candy(vector<int>& ratings){
        int n = ratings.size();
        int ret = 1;
        int inc = 1, dec = 0, pre = 1;
        for(int i=1; i<n; i++){
            if (ratings[i] >= ratings[i-1]){
                dec = 0; 
                pre = ratings[i] == ratings[i-1] ? 1: pre+1;
                ret += pre;
                inc = pre;
            }else{
                dec++;
                if (dec == inc){
                    dec++;
                }
                ret += dec;
                pre = 1;
            }
        }
        return ret;
    }
};