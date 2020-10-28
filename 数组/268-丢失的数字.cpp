/*

给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。

进阶：

你能否实现线性时间复杂度、仅使用额外常数空间的算法解决此问题?
 
示例 1：

输入：nums = [3,0,1]
输出：2
解释：n = 3，因为有 3 个数字，所以所有的数字都在范围 [0,3] 内。2 是丢失的数字，因为它没有出现在 nums 中。
示例 2：

输入：nums = [0,1]
输出：2
解释：n = 2，因为有 2 个数字，所以所有的数字都在范围 [0,2] 内。2 是丢失的数字，因为它没有出现在 nums 中。
示例 3：

输入：nums = [9,6,4,2,3,5,7,0,1]
输出：8
解释：n = 9，因为有 9 个数字，所以所有的数字都在范围 [0,9] 内。8 是丢失的数字，因为它没有出现在 nums 中。
示例 4：

输入：nums = [0]
输出：1
解释：n = 1，因为有 1 个数字，所以所有的数字都在范围 [0,1] 内。1 是丢失的数字，因为它没有出现在 nums 中。

*/


#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


class Solution{
public:
    int missingNumber(vector<int>& nums){
        /*
            暴力方法，先排序后遍历数组
        */
        sort(nums.begin(), nums.end());
        int res = nums.size();
        for (int i=0; i<nums.size();i++){
            if (i != nums[i]){
                res = i;
                break;
            }
        }
        return res;
    }
};


class Solution2{
public:
    int missingNumber(vector<int>& nums){
        /*
            排序 + 二分查找
        */
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size(), mid;
        while (left < right){
            mid = (left + right) / 2;
            if (nums[mid] > mid) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};


class Solution3{
public:
    int missingNumber(vector<int>& nums){
        /*
            数学求和
        */
        int sum = 0, n = nums.size();
        for (int n: nums){
            sum += n;
        }
        return (n * (n + 1) / 2 - sum);
        
    }
};


class Solution{
public:
    int missingNumber(vector<int>& nums){
        /*
            异或：nums.size()的大小即为n,将0到n异或，并且同时异或nums[0]到nums[n-1],共2n+1个数，
                相同的数异或结果为0，0 ^ a = a,所以最后的结果是缺失的数字
        */
        int res = nums.size();
        for (int i=0; i<nums.size(); ++i){
            res = res ^ i ^ nums[i];  // a ^ b ^ b = a
        }
        return res;
    }
};