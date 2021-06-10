/*

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

示例 1：
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 

示例 2：
输入：height = [4,2,0,3,2,5]
输出：9

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{     // 暴力求解
public:
    int trap(vector<int>& height){
        int size = height.size();
        int ans = 0;
        for(int i=1; i<size; i++){
            int max_left = 0, max_right = 0;
            // 从当前元素从左到右扫描更新
            for(int j=i; j>=0; j--){
                max_left = max(max_left, height[j]);
            }
            // 从当前元素从右到左扫描元素
            for(int j=i; j<size; j++){
                max_right = max(max_right, height[j]);
            }
            // 以左右最大值中的较小值为标准，与当前柱子的高度相减，得到雨水量，并累加结果
            ans += min(max_left, max_right) - height[i];
        }
        return ans;
    }
};


class Solution2{
public:
    int trap(vector<int> height){
        int size = height.size();
        if (size < 3)
            return 0;
        // 初始化两个数组
        vector<int> max_left(size), max_right(size);

        int ans = 0;
        // 从左到右遍历，求最大值，并完成初始化
        max_left[0] = height[0];
        for(int i=1; i<size; i++){
            max_left[i] = max(height[i], max_left[i-1]);
        }
        // 从右到左遍历，求最大值，并完成初始化
        max_right[size-1] = height[size-1];
        for(int i=size-2; i>=0; i--){
            max_right[i] = max(height[i], max_right[i+1]);
        }
        // 将从左到右的最大值数组与从右到左的最大值数组进行逐一比较
        for(int i=1; i<size-1; i++){
            ans += min(max_left[i], max_right[i]) - height[i];
        }
        return ans;
    }
};


class Solution3{    // 单调栈
public:
    int trap(vector<int>& height){
        int ans = 0, current = 0;
        // 初始化一个栈，用于存储索引值
        stack<int> st;
        while(current < height.size()){
            // 当栈不为空且当前元素大于栈顶元素
            while(!st.empty() && height[current] > height[st.top()]){
                int top = st.top();
                // 弹出栈顶元素
                st.pop();
                // 当栈为空跳出循环
                if (st.empty())
                    break;
                // 求出两者之间的距离
                int distance = current - st.top() - 1;
                // 求高度
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                // 累加雨水量
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
};


class Solution4{   // 双指针，一次遍历
public:
    int trap(vector<int>& height){
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while(left < right){
            if (height[left] < height[right]){
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else{
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;   
    }
};