/*

我们有两个长度相等且不为空的整型数组 A 和 B 。

我们可以交换 A[i] 和 B[i] 的元素。注意这两个元素在各自的序列中应该处于相同的位置。

在交换过一些元素之后，数组 A 和 B 都应该是严格递增的（数组严格递增的条件仅为A[0] < A[1] < A[2] < ... < A[A.length - 1]）。

给定数组 A 和 B ，请返回使得两个数组均保持严格递增状态的最小交换次数。假设给定的输入总是有效的。

示例:
输入: A = [1,3,5,4], B = [1,2,3,7]
输出: 1
解释: 
交换 A[3] 和 B[3] 后，两个数组如下:
A = [1, 3, 5, 7] ， B = [1, 2, 3, 4]
两个数组均为严格递增的。

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{     // 动态规划
public:
    int minSwap(vector<int>& A, vector<int>& B){
        // n1表示数组A和B满足前i-1个元素分别严格递增，并且A[i-1]和B[i-1]未被交换的最小交换次数
        // s1表示A[i-1]和B[i-1]被交换的最小交换次数
        int n1 = 0, s1 = 1;
        for(int i=1; i<A.size(); i++){
            int n2 = INT_MAX, s2 = INT_MAX;
            if (A[i-1] < A[i] && B[i-1] < B[i]){
                n2 = min(n2, n1);
                s2 = min(s2, s1+1);
            }
            if (A[i-1] < B[i] && B[i-1] < A[i]){
                n2 = min(n2, s1);
                s2 = min(s2, n2+1);
            }
            n1 = n2;
            s1 = s2;
        }
        return min(n1, s1);
    }
};