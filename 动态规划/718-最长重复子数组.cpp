/*

给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

示例：
输入：
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出：3
解释：
长度最长的公共子数组是 [3, 2, 1] 。

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{    // 动态规划
public:
    int findLength(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        int ans = 0;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                dp[i][j] = nums1[i] == nums2[j]? dp[i+1][j+1] + 1: 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};


class Solution2{     // 滑动窗口
public:
    // 求两个数组的最大重复子数组的长度，addA和addB用于调节数组A、B的的起始位置
    int maxLength(vector<int>& A, vector<int>& B, int addA, int addB, int len){
        int ret = 0, k = 0;
        for(int i=0; i < len; i++){
            if (A[addA + i] == B[addB + i]){
                k++;
            }else{
                k = 0;
            }
            ret = max(ret ,k);
        }
        return ret;
    }

    int findLength(vector<int>& A, vector<int>& B){
        int n = A.size(), m = B.size();
        int ret = 0;
        // B不动，A动
        for(int i=0; i<n; i++){
            int len = min(m, n-i);
            int maxLen = maxLength(A, B, i, 0, len);
            ret = max(ret, maxLen);
        }
        // A不动，B动
        for(int i=0; i<m; i++){
            int len = min(n, m-i);
            int maxLen = maxLength(A, B, 0, i, len);
            ret = max(ret, maxLen);
        }
        // 返回两者的最大值
        return ret;
    }
};